# Copyright (c) 2017 HyungSeok Han and Sang Kil Cha at SoftSec, KAIST
#
# See the file LICENCE for copying permission.

import basic
import const
import sys
import os


class ApiHook(basic.Api):
    def __init__(self, api):
        self.__dict__ = api.__dict__.copy()
        self.arghooks= []
        for arg in self.args:
            self.arghooks.append(ArgHook(arg))

    def list_args(self, show_type):
        ret = ''
        for x in self.arghooks:
            if show_type :
                ret += '%s %s,'%(x.get('type'), x.get('name'))
            else:
                ret += '%s,'%x.get('name')
        return ret[:-1]

    def log(self):
        body = self.log_intro()
        body += self.log_input()
        body += self.call_ori()
        body += self.log_output()
        args = self.list_args(True)
        return '%s fake_%s(%s){\n%s}\n'%(self.rtype, self.name, args, body)

    def log_intro(self):
        intro = '\tFILE *fp = fopen(log_path,"a");\n'
        intro += '\tHANDLE fh = (HANDLE)_fileno(fp);\n'
        intro += '\tOVERLAPPED overlapped;\n'
        intro += '\tmemset(&overlapped, 0, sizeof(overlapped));\n'
        intro += '\tconst int lockSize = 10000;\n'
        intro += '\tLockFileEx(fh, LOCKFILE_EXCLUSIVE_LOCK, 0, lockSize, 0, &overlapped);\n'
        intro += '\t_wsetlocale(0, L"chs");\n'
        return intro

    def log_input(self):
        ret = ''
        for arghook in self.arghooks:
            if arghook.is_input():
                ret += arghook.log()
        ret = '''\tfprintf(fp,"IN ['%s',");\n''' % (self.name) + ret
        return ret + '''\tfprintf(fp,"]\\n");\n'''

    def call_ori(self):
        args = self.list_args(False)
        if self.is_void() :
            return  '\t%s(%s);\n'%(self.name, args)
        return '\t%s ret = %s(%s);\n'%(self.rtype,self.name, args)

    def log_output(self):
        ret = ArgHook(self.rval).log()
        for arghook in self.arghooks:
            if arghook.is_output():
                ret += arghook.log()
        ret = '''\tfprintf(fp,"OUT ['%s',");\n'''%(self.name) +ret
        ret += '''\tfprintf(fp,"]\\n");\n'''

        ret += '\tmemset(&overlapped, 0, sizeof(overlapped));\n'
        ret += '\tUnlockFileEx(fh, 0, lockSize, 0, &overlapped);\n'
        ret += '\tfclose(fp);\n'
        if not self.is_void():
            ret += '\treturn ret;\n'
        return ret

    def hook_entry(self):
        return self.name, 'fake_%s' % self.name

    def hook_orifun(self):
        return self.rtype, self.name, self.list_args(True), self.name


class ArgHook(basic.Arg):
    def __init__(self, arg):
        self.__dict__ = arg.__dict__.copy()

    def log(self):
        if self.type in const.WCHAR_TYPE:
            return self.wlog()
        else:
            return self.alog()

    def alog(self):
        if self.name == const.RVAL and self.type == 'VOID':
            return ''
        ret, add, add_arg = '', '', ''

        # if (self.is_input() and self.name != const.RVAL) and \
        #         (self.type in const.CHECK_ORIGINAL):
        #     ret += '''\tchar name_buf[0x100];\n'''
        #     ret += '''\tIORegistryEntryGetName(%s,name_buf);\n'''%self.name
        #     add += "'ori':'IOServiceGetMatchingService(0,IOServiceMatching(\\\"%s\\\"))',"
        #     add_arg += ',name_buf'

        log_name = self.get_log_name()
        fmt = self.get_fmt()

        ret += '\tif(%s) ' % (self.valid_ptr())
        ret += '''fprintf(fp,"{'name':'%s',''' % self.name
        ret += ''''value': %s,''' % fmt
        ret += ''''size' : 0x%%lx,'cnt':0x%%x,%s ''' % add
        ret += ''''data':[",%s, sizeof(%s),''' % (log_name, self.type)
        ret += '''%s%s);\n ''' % (self.get_opt('cnt'), add_arg)

        ret += '''\telse fprintf(fp,"{'name':'%s',''' % self.name
        ret += ''''value': %s, ''' % fmt
        ret += ''''size' : 0x%%lx,'cnt':'undefined',%s ''' % add
        ret += ''''data':[",%s,sizeof(%s)%s);\n''' % (log_name, self.type, add_arg)

        if self.is_ptr():
            ret += self.log_ptr()

        if self.is_input() and self.name != const.RVAL and \
                (self.type in const.CHECK_CF):
            ret += '''\tfprintf(fp,"],'ori':");\n'''
            ret += '''\tlog_CFTypeRef(fp,%s);\n'''%self.name
            ret += '''\tfprintf(fp,"},");\n'''

        else:
            ret += '''\tfprintf(fp,"]},");\n '''
        return ret

    def wlog(self):
        if self.name == const.RVAL and self.type == 'VOID':
            return ''
        ret, add, add_arg = '', '', ''

        # if (self.is_input() and self.name != const.RVAL) and \
        #         (self.type in const.CHECK_ORIGINAL):
        #     ret += '''\tchar name_buf[0x100];\n'''
        #     ret += '''\tIORegistryEntryGetName(%s,name_buf);\n'''%self.name
        #     add += "'ori':'IOServiceGetMatchingService(0,IOServiceMatching(\\\"%s\\\"))',"
        #     add_arg += ',name_buf'

        log_name = self.get_log_name()
        fmt = self.get_fmt()

        ret += '\tif(%s)\n' % (self.valid_ptr())
        ret += '''\t{\n\t\tfprintf(fp,"{'name':'%s',");\n''' % self.name
        ret += '''\t\tfwprintf(fp, L"'value': %s,", %s);\n''' % (fmt, log_name)
        ret += '''\t\tfprintf(fp, "'size' : 0x%%lx,'cnt':0x%%x,%s ''' % add
        ret += ''''data':[", sizeof(%s),''' % self.type
        ret += '''%s%s);\n ''' % (self.get_opt('cnt'), add_arg)

        ret += '''\t}else \n\t{\n\t\tfprintf(fp,"{'name':'%s',");\n''' % self.name
        ret += '''\t\tfwprintf(fp, L"'value': %s, ", %s);\n''' % (fmt, log_name)
        ret += '''\t\tfprintf(fp, "'size' : 0x%%lx,'cnt':'undefined',%s ''' % add
        ret += ''''data':[",sizeof(%s)%s);\n\t}\n''' % (self.type, add_arg)

        if self.is_ptr():
            ret += self.log_ptr()

        if self.is_input() and self.name != const.RVAL and \
                (self.type in const.CHECK_CF):
            ret += '''\tfprintf(fp,"],'ori':");\n'''
            ret += '''\tlog_CFTypeRef(fp,%s);\n'''%self.name
            ret += '''\tfprintf(fp,"},");\n'''

        else:
            ret += '''\tfprintf(fp,"]},");\n '''
        return ret

    def log_ptr(self):
        if "cnt" not in self.opt:
            return ""
        template = '''\tif(%s){\n\t\tfor(int i=0; i<%s;i++){\n%s\t\t}\n\t}\n'''
        name = self.name
        if 'void *' in self.type:
            name = '((uint8_t *) %s)' % name
        body = '''\t\t\tfprintf(fp,"%s,",%s[i]);\n''' % (self.get_fmt(True), name)
        if "," in self.get_opt('cnt'):
            tmp = self.get_opt('cnt').split(',')
            for_str = "%s < %s ? %s : %s" % (tmp[0], tmp[1], tmp[0], tmp[1])
        else:
            for_str = self.get_opt('cnt')
        return template % (self.valid_ptr(self.name), for_str, body)

    def get_log_name(self):
        name = self.name
        # if 'CFStringRef' == self.type:
        #    return 'CFStringGetCStringPtr(%s,kCFStringEncodingMacRoman)'%name
        return name

    def get_fmt(self, for_ptr=False):
        ty = self.type.replace('const', '').replace("CONST", '').strip()
        if "cnt" in self.opt:
            if for_ptr:
                return "0x%x"
            else:
                return '%p'
        if ty in const.TYPE_FMT:
            return const.TYPE_FMT[ty]
        if not for_ptr and self.is_ptr():
            return '%p'
        # return const.SIZE_FMT[self.get_opt('size')]
        return const.SIZE_FMT[const.TYPE_SIZE[self.type]]

    def valid_ptr(self, init='1'):
        ret = init
        cnt = str(self.get_opt('cnt'))
        if "," not in cnt:
            for idx in range(len(cnt)):
                if cnt[idx] != '*':
                    break
                ret = '%s && ' % cnt[idx+1:] + ret
        else:
            cnt = cnt.split(",")
            for idx in range(len(cnt[0])):
                if cnt[0][idx] != '*':
                    break
                ret = '%s && %s && ' % (cnt[0][idx+1:], cnt[1]) + ret
        return ret


class Hooker:
    def __init__(self):
        self.apis = basic.load_apis()

    def gen_hook(self, fn_hook):
        code = const.HEADER
        template = const.HOOK_MAIN_TEMPLATE
        attach = const.HOOK_ATTACH_TEMPLATE
        detach = const.HOOK_DETACH_TEMPLATE
        ori_proc = const.HOOK_ORI_PROC_TEMPLATE
        attach_table = ''
        detach_table = ''
        for name, api in self.apis.items():
            if name == "wvsprintfW":
                a = 3
            h = ApiHook(api)
            code += h.log()
            code += ori_proc % h.hook_orifun()
            code += "\n"
            attach_table += attach % h.hook_entry()
            detach_table += detach % h.hook_entry()

        code += template % (attach_table, detach_table)
        with open(fn_hook, 'w') as f:
            f.write(code)


def show_help():
    print(' ./gen-hook [name of hooking code]')


if __name__ == '__main__':
    # if len(sys.argv) != 2:
    #    show_help()
    #    sys.exit(0)

    hooker = Hooker()
    hooker.gen_hook("hook.c")

