class Extract:
    def __init__(self):
        self.keyword = "WINUSERAPI"
        self.api_list = list()
        self.type_dict = dict()

    def __add_type(self, type_name):
        if type_name not in self.type_dict:
            self.type_dict[type_name] = 1

    def do_extract(self, file_path):
        with open(file_path, "r") as f:
            data = f.readlines()
        found_fun_def = False
        ret_type = None
        fun_name = None
        fun_info = None
        arg_info = None
        for line in data:
            line = line.strip()
            if len(line) == 0 or line[0] == '#':
                continue
            if found_fun_def is False:
                if line == self.keyword:
                    found_fun_def = True
                    fun_info = list()
                    arg_info = list()
            else:
                if ret_type is None:
                    ret_type = line
                    self.__add_type(ret_type)
                    continue
                if line == "WINAPI":
                    continue
                if fun_name is None and '(' in line:
                    # 函数开始,获取函数名
                    fun_name = line.split('(')[0]
                    fun_info.append((ret_type, fun_name))
                    if line[-1] == ";":
                        fun_info.append(arg_info)
                        self.api_list.append(fun_info)
                        found_fun_def = False
                        ret_type = None
                        fun_name = None
                        fun_info = None
                        arg_info = None
                    continue
                if ',' in line or ';' in line:
                    is_end = False
                    if ';' in line:
                        # 函数声明结束
                        line = line.split(';')[0]
                        is_end = True
                    else:
                        line = line[:-1]
                    # 获取参数
                    if is_end:
                        line = line[:-1]
                    items = line.split(' ')
                    opt_info = None
                    if len(items) == 1:
                        fun_info.append(arg_info)
                        self.api_list.append(fun_info)
                        found_fun_def = False
                        ret_type = None
                        fun_name = None
                        fun_info = None
                        arg_info = None
                        continue
                    if fun_name == "SendInput":
                        a = 3
                    if len(items) == 2 or items[1][0:2] == "__":
                        # 函数声明中没有参数名称
                        arg_type = items[-1]
                        arg_name = "arg%d" % len(arg_info)
                        opt_info = items[0]
                    else:
                        # 函数声明中有参数名称
                        if ')' not in line:
                            tmp = line.find(' ')
                            opt_info = line[:tmp]
                            arg_str = line[tmp + 1:]
                        else:
                            tmp = line.rfind(')')
                            opt_info = line[:tmp+1]
                            arg_str = line[tmp + 2:]
                        if "/" in arg_str:
                            arg_str = arg_str.split("/")[0].strip()[:-1]
                        if "*" in arg_str:
                            tmp = arg_str.split("*")
                            arg_type = tmp[0].strip() + "*"
                            arg_name = tmp[1]
                        else:
                            tmp = arg_str.rfind(' ')
                            arg_type = arg_str[:tmp].strip()
                            arg_name = arg_str[tmp+1:]

                    if "const" in arg_type:
                        arg_type = arg_type.replace("const", "CONST")
                    if " FAR" in arg_type:
                        arg_type = arg_type.replace(" FAR", "")

                    self.__add_type(arg_type)
                    opt_dict = dict()
                    if "__inout" in opt_info:
                        arg_class = 3
                    elif "__out" in opt_info:
                        arg_class = 2
                    else:
                        arg_class = 1

                    if "ecount" in opt_info:
                        opt_dict["cnt"] = opt_info.split('(')[1][:-1]
                        if "result" in opt_dict["cnt"]:
                            opt_dict["cnt"] = opt_dict["cnt"].replace("return", "ret")

                    if arg_class == 2:
                        opt_dict["IO"] = "O"
                    elif arg_class == 3:
                        opt_dict["IO"] = "IO"
                    if len(arg_name) == 0:
                        arg_name = "arg%d" % len(arg_info)
                    arg_info.append((arg_type, arg_name, opt_dict))

                    if is_end:
                        fun_info.append(arg_info)
                        self.api_list.append(fun_info)
                        found_fun_def = False
                        ret_type = None
                        fun_name = None
                        fun_info = None
                        arg_info = None


if __name__ == "__main__":
    h_path = "/Users/apple/Desktop/WinUser.h"
    e = Extract()
    e.do_extract(h_path)
    o_path = "output.txt"
    with open(o_path, "w") as f:
        for api in e.api_list:
            f.write(str(api) + ',\n')
        """f.write("TYPE_SIZE = {\n")

        for type_name in e.type_dict.keys():
            f.write("\'%s\': " % type_name)
            ty = type_name
            if "CONST" in type_name:
                ty = type_name.replace("CONST", "").strip()
            if "*" in ty or ty[0] == "P" or ty[:2] == "LP" \
                    or ty[0] == "H" or "PROC" in ty:
                f.write("4,\n")
            else:
                f.write("0,\n")"""


