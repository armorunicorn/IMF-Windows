# Copyright (c) 2017 HyungSeok Han and Sang Kil Cha at SoftSec, KAIST
#
# See the file LICENCE for copying permission.

RVAL = 'ret'
DCNT = 1 #Defualt Cnt
DSIZE = 4 # Defualt Size
TYPE_FMT = {'LPWSTR': """'\\"%s\\"'""",
            'LPCWSTR': """'\\"%s\\"'""",
            'LPCSTR': """'\\"%s\\"'""",
            'LPSTR': """'\\"%s\\"'""",
            'CHAR': """'\\"%c\\"'""",
            'WCHAR': """'\\"%c\\"'""",
            }
WCHAR_TYPE = {
    "WCHAR": 1,
    "LPWSTR": 1,
    "LPCWSTR": 1,
}
SIZE_FMT = {1: '0x%hhx', 2: '0x%hx', 4: '0x%x', 8: '0x%llx'}
DEBUG = True
MULTI_NUM =4
DATA = 'DATA'
VALUE = 'VALUE'
TYPE_PTR = ['CFDictionaryRef', 'IONotificationPortRef',
            'io_name_t', 'CFStringRef', 'char *']
TYPE_SIZE = {
    'WINSTAENUMPROCW': 4,
    'LPCMENUITEMINFOA': 4,
    'HICON': 4,
    'HICON*': 4,
    'UINT32': 4,
    'HACCEL': 4,
    'WNDENUMPROC': 4,
    'DWORD': 4,
    'LPWNDCLASSEXW': 4,
    'CONST WNDCLASSEXA*': 4,
    'LPCMENUITEMINFOW': 4,
    'DISPLAYCONFIG_MODE_INFO*': 4,
    'HDESK': 4,
    'HCURSOR': 4,
    'CONST PAINTSTRUCT*': 4,
    'LRESULT': 4,
    'BYTE': 1,
    'TIMERPROC': 4,
    'LONG_PTR': 4,
    'CONST MSGBOXPARAMSW*': 4,
    'COLORREF*': 4,
    'long': 8,
    'CONST MENUTEMPLATEW*': 4,
    'BLENDFUNCTION*': 4,
    'CONST MSG*': 4,
    'LPDRAWTEXTPARAMS': 4,
    'LPARAM': 4,
    'DRAWSTATEPROC': 4,
    'LPINT': 4,
    'HWINSTA': 4,
    'PDWORD_PTR': 4,
    'PGUITHREADINFO': 4,
    'PICONINFOEXA': 4,
    'LPINPUT': 4,
    'LPWNDCLASSEXA': 4,
    'LPPAINTSTRUCT': 4,
    'PCHANGEFILTERSTRUCT': 4,
    'PDISPLAY_DEVICEW': 4,
    'LPPOINT': 4,
    'PRAWINPUT': 4,
    'LPCSTR': 4,
    'HHOOK': 4,
    'MONITORENUMPROC': 4,
    'HMODULE': 4,
    'CONST UPDATELAYEREDWINDOWINFO*': 4,
    'ULONG': 4,
    'PROPENUMPROCEXA': 4,
    'PALTTABINFO': 4,
    'PCURSORINFO': 4,
    'LPDWORD': 4,
    'PVOID': 4,
    'PTITLEBARINFO': 4,
    'LPSECURITY_ATTRIBUTES': 4,
    'HINSTANCE': 4,
    'PSECURITY_DESCRIPTOR': 4,
    'PMENUBARINFO': 4,
    'PRAWINPUT*': 4,
    'INT': 4,
    'HANDLE': 4,
    'LPCMENUINFO': 4,
    'PULONG': 4,
    'LPMSG': 4,
    'WNDPROC': 4,
    'va_list': 4,
    'PICONINFO': 4,
    'CONST WINDOWPLACEMENT*': 4,
    'CHAR': 1,
    'INT_PTR': 4,
    'WORD': 2,
    'RECT*': 4,
    'FARPROC': 4,
    'LPSTR': 4,
    'int': 4,
    'VOID': 1,
    'LPACCEL': 4,
    'CONST MSGBOXPARAMSA*': 4,
    'BYTE*': 4,
    'LPMENUITEMINFOA': 4,
    'CONST WNDCLASSEXW*': 4,
    'PICONINFOEXW': 4,
    'CONST WNDCLASSW*': 4,
    'CONST SIZE*': 4,
    'PDISPLAY_DEVICEA': 4,
    'PROPENUMPROCEXW': 4,
    'PCRAWINPUTDEVICE': 4,
    'CONST BYTE*': 4,
    'HKL *': 4,
    'CONST COLORREF*': 4,
    'HBRUSH': 4,
    'PLASTINPUTINFO': 4,
    'UINT': 4,
    'HBITMAP': 4,
    'PROPENUMPROCW': 4,
    'HDEVNOTIFY': 4,
    'CONST WNDCLASSA*': 4,
    'PGESTURECONFIG': 4,
    'PBSMINFO': 4,
    'SIZE*': 4,
    'CONST MENUTEMPLATEA*': 4,
    'CONST RECT*': 4,
    'HRAWINPUT': 4,
    'LPCRECT': 4,
    'PRAWINPUTDEVICELIST': 4,
    'DESKTOPENUMPROCW': 4,
    'LPCDLGTEMPLATEW': 4,
    'HDC': 4,
    'DISPLAYCONFIG_DEVICE_INFO_HEADER*': 4,
    'LPMENUINFO': 4,
    'HWINEVENTHOOK': 4,
    'CONST VOID*': 4,
    'LPCWSTR': 4,
    'UINT_PTR': 4,
    'POINT': 8,
    'DESKTOPENUMPROCA': 4,
    'LPWNDCLASSW': 4,
    'LPTPMPARAMS': 4,
    'WCHAR': 2,
    'DISPLAYCONFIG_PATH_INFO*': 4,
    'HMONITOR': 4,
    'PSCROLLBARINFO': 4,
    'PGESTUREINFO': 4,
    'WINDOWPLACEMENT*': 4,
    'SHORT': 2,
    'WINEVENTPROC': 4,
    'LPBYTE': 4,
    'ATOM': 2,
    'HKL': 4,
    'BOOL*': 4,
    'HGESTUREINFO': 4,
    'LPWSTR': 4,
    'HPOWERNOTIFY': 4,
    'HWND': 4,
    'CONST INT*': 4,
    'DLGPROC': 4,
    'PUINT': 4,
    'HDWP': 4,
    'DEVMODEW*': 4,
    'SENDASYNCPROC': 4,
    'LPWNDCLASSA': 4,
    'PWINDOWINFO': 4,
    'LPCSCROLLINFO': 4,
    'UINT*': 4,
    'HMENU': 4,
    'LPCGUID': 4,
    'PSECURITY_INFORMATION': 4,
    'CONST POINT*': 4,
    'PROPENUMPROCA': 4,
    'CONST HWND *': 4,
    'COLORREF': 4,
    'UINT32*': 4,
    'PRAWINPUTDEVICE': 4,
    'PFLASHWINFO': 4,
    'PBYTE': 4,
    'ACCESS_MASK': 4,
    'HTOUCHINPUT': 4,
    'WINSTAENUMPROCA': 4,
    'WPARAM': 4,
    'BOOL': 4,
    'PCOMBOBOXINFO': 4,
    'HRGN': 4,
    'LPVOID': 4,
    'ULONG_PTR': 4,
    'CONST HANDLE*': 4,
    'DEVMODEA*': 4,
    'LPTRACKMOUSEEVENT': 4,
    'LPWORD': 4,
    'GRAYSTRINGPROC': 4,
    'LPMONITORINFO': 4,
    'HOOKPROC': 4,
    'LPMOUSEMOVEPOINT': 4,
    'LPRECT': 4,
    'LONG': 4,
    'POINT*': 4,
    'LPSCROLLINFO': 4,
    'LPMENUITEMINFOW': 4,
    'DWORD*': 4,
    'LPCDLGTEMPLATEA': 4,
    'CONST HWND*': 4,
    'DISPLAYCONFIG_TOPOLOGY_ID*': 4,
    'HKL*': 4,
}
CHECK_ORIGINAL = ['io_service_t', 'io_registry_entry_t']
CHECK_CF = ['CFDictionaryRef', 'CFTypeRef']
STRING_TYPE = ['io_string_t', 'io_name_t', 'io_struct_inband_t']
HANDLES =  ['io_connect_t', 'mach_port_t', 'io_iterator_t', 'io_object_t',
            'io_registry_entry_t', 'io_service_t']
HOOK_ENTRY_TEMPLATE = '\t{ .replacement = (void*)%40s, .original = (void*)%35s},\n'
HOOK_TABLE_TEMPLATE = '''
typedef struct interposer {
    void* replacement;
      void* original;
} interpose_t;
__attribute__((used)) static const interpose_t interposers[]
  __attribute__((section("__DATA, __interpose"))) = {
    %s
  };
'''
HOOK_PROC_VAL_TEMPLATE = '''
typedef %s (WINAPI *%s_fun) (%s);
%s_fun p%s = %s;
HOOK_TRACE_INFO hHook%s = { 0 };
ULONG Hook%s_ACLEntries[1] = { 0 };
'''

HOOK_PREPARE_TEMPLATE = '\tp%s = (%s_fun)GetProcAddress(huser32, \"%s\");\n'
HOOK_ATTACH_TEMPLATE = '''
\tLhInstallHook(p%s, fake_%s, NULL, &hHook%s);
\tLhSetExclusiveACL(Hook%s_ACLEntries, 1, &&hHook%s);
'''
HEADER = '''
/*
Copyright (c) 2017 HyungSeok Han and Sang Kil Cha at SoftSec, KAIST

See the file LICENCE for copying permission.
*/
#include "stdafx.h"
#include <easyhook.h>
#include <Windows.h>

#ifndef LOG_PATH
#define LOG_PATH "D:\\\\log.txt"
#endif

HANDLE g_mutex;
const char* log_path = LOG_PATH;
'''

HOOK_MAIN_TEMPLATE = '''
void PrepareRealApiEntry()
{
    HMODULE huser32 = LoadLibrary(L"User32.dll");
%s
}

extern "C" void __declspec(dllexport) __stdcall NativeInjectionEntryPoint(REMOTE_ENTRY_INFO* inRemoteInfo);

void __stdcall NativeInjectionEntryPoint(REMOTE_ENTRY_INFO* inRemoteInfo)
{
    PrepareRealApiEntry();
%s
    RhWakeUpProcess();
}
'''
CODE_HEAD = '''
/*
Copyright (c) 2017 HyungSeok Han and Sang Kil Cha at SoftSec, KAIST

See the file LICENCE for copying permission.
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <IOKit/IOKitLib.h>
#include <fcntl.h>
#include <unistd.h>
#include <CoreFoundation/CoreFoundation.h>

#define MAYBE (get_rand32() % rate == 0)
unsigned int first = 1;
unsigned int set_seed = 0;
const char* log_file = NULL;
unsigned int seed = 0;
unsigned int bitlen = 8;
unsigned int rate = 1000;
unsigned int max_loop = 1000;
uint16_t get_rand(){
  short ret;
  if(first ==1){
    if(set_seed == 0){
      int fd;
      fd = open("/dev/urandom",0);
      read(fd,&seed,4);
      close(fd);
      FILE *fp = fopen(log_file,"a");
      fprintf(fp,"seed: %ld, rate: %ld, bitlen: %ld, max_loop: %ld\\n", seed, rate,
              bitlen, max_loop);
      fclose(fp);
      sync();
    }
    srand(seed);
    first = 0;
  }
  ret = (uint16_t)rand() & 0xffff;
  return ret;
}
uint32_t get_rand32(){
  uint32_t ret = (get_rand() << 16) | get_rand();
  return ret;
}
CFMutableDictionaryRef make_CFDic(){
  return CFDictionaryCreateMutable(NULL,0,&kCFTypeDictionaryKeyCallBacks,&kCFTypeDictionaryValueCallBacks);
}

CFMutableDictionaryRef set_CFDic(CFMutableDictionaryRef dic, CFTypeRef key, CFTypeRef val){
  CFDictionarySetValue(dic,key,val);
  return dic;
}
CFNumberRef make_CFNum(int value){
  int *ptr = malloc(sizeof(int));
  *ptr = value;
  return CFNumberCreate(NULL,kCFNumberIntType,ptr);
}

boolean_t mut_bool(boolean_t v){
  if( MAYBE ){
    if((get_rand() & 1) ==0) return false;
    return true;
  }
  return v;
}
uint8_t mut_byte(uint8_t v){
  uint8_t r ;
  if( MAYBE ){
    r= (uint16_t)get_rand() ;
    if(bitlen <8){
      return v ^ (r & ((1 << (8-bitlen))-1) ); 
    }else{
      return v ^ (r & 1) ;
    }
  }
  return v;
}

uint16_t mut_short(uint16_t v){
  uint16_t r ;
  if( MAYBE ){
    r= get_rand();
    if(bitlen <16){
      return v ^ (r & ((1 << (16-bitlen))-1) ); 
    }else{
      return v ^ (r & 1) ;
    }
  }
  return v;
}

uint32_t mut_int(uint32_t v){
  uint32_t r =0;
  if( MAYBE ){
    r = (r<<16) | (uint32_t) get_rand();
    r = (r<<16) | (uint32_t) get_rand();
    if(bitlen <32){
      return v ^ (r & ((1 << (32-bitlen))-1) ); 
    }else{
      return v ^ (r & 1) ;
    }

  }
  return v;
}

uint64_t mut_long(uint64_t v){
  uint64_t r = 0;
  if( MAYBE ){
    r = (r<<16) | (uint64_t) get_rand();
    r = (r<<16) | (uint64_t) get_rand();
    r = (r<<16) | (uint64_t) get_rand();
    r = (r<<16) | (uint64_t) get_rand();

    if(bitlen <64){
      return v ^ (r & (((uint64_t)1 << (64-bitlen))-1) ); 
    }else{
      return v ^ (r & 1) ;
    }
  }
  return v;
}

void* mut_ptr(void *v){
  if ( MAYBE ){
    if(sizeof(void *) ==4 ) return (void *)mut_int((uint32_t)v);
    else return (void *)mut_long((uint64_t)v);
  }
  return v;
}

void* mut_array(void *v, uint32_t len, uint32_t size){
  uint32_t i = 0;
  if(size == 1){
    for(i=0; i<len; i++){
      ((uint8_t *)v)[i] = mut_byte(((uint8_t *)v)[i]);
    }
  }else if(size == 2){
    for(i=0; i<len; i++){
      ((uint16_t *)v)[i] = mut_short(((uint16_t *)v)[i]);
    }
  }else if(size == 4){
    for(i=0; i<len; i++){
      ((uint32_t *)v)[i] = mut_int(((uint32_t *)v)[i]);
    }
  }else if(size == 8){
    for(i=0; i<len; i++){
      ((uint64_t *)v)[i] = mut_long(((uint64_t *)v)[i]);
    }
  }
  return v;
}
void help(){
    puts("./fuzz -f [log path] -s [seed] -b [bitlen] -r [rate] -l [# of max loops]");
    puts("\\t-f [log path] : required");
    puts("\\t-b [bitlen] : default = 8");
    puts("\\t-r [rate] : default = 1000");
    puts("\\t-l [# of max loops] : default = 1000");
    puts("\\t-s [seed] : default = random value");
    exit(0);
}

unsigned int parse_uint(char *data){
    char *ptr;
    unsigned int ret = strtoul(data, &ptr, 10);
    if(ret == 0){
        help();
    }
    return ret;
}

void parse_args(int argc, char **argv){
    int opt;
    while ((opt = getopt(argc, argv, "f:s:b:r:l:")) != -1){
        switch(opt){
            case 'f':
                log_file = optarg;
                break;
            case 's':
                seed = parse_uint(optarg);
                set_seed = 1;
                break;
            case 'b':
                bitlen = parse_uint(optarg);
                break;
            case 'r':
                rate = parse_uint(optarg);
                break;
            case 'l':
                max_loop = parse_uint(optarg);
                break;
            default :
                help();
        }

    }
    if(log_file == NULL && set_seed == 0){
        help();
    }
}
int main(int argc, char **argv){
  parse_args(argc, argv);
  unsigned int loop=0;
  while(loop<max_loop){

'''
CODE_TAIL = '''
    loop++;
  }
}
'''
API_DEFS = [
#[('int', 'wvsprintfA'), [('LPSTR', 'arg0', {'IO': 'O'}), ('LPCSTR', 'arg1', {}), ('va_list', 'arglist', {})]],
#[('int', 'wvsprintfW'), [('LPWSTR', 'arg0', {'IO': 'O'}), ('LPCWSTR', 'arg1', {}), ('va_list', 'arglist', {})]],
#[('int', 'wsprintfA'), [('LPSTR', 'arg0', {'IO': 'O'}), ('LPCSTR', 'arg1', {})]],
#[('int', 'wsprintfW'), [('LPWSTR', 'arg0', {'IO': 'O'}), ('LPCWSTR', 'arg1', {})]],
[('HKL', 'LoadKeyboardLayoutA'), [('LPCSTR', 'pwszKLID', {}), ('UINT', 'Flags', {})]],
[('HKL', 'LoadKeyboardLayoutW'), [('LPCWSTR', 'pwszKLID', {}), ('UINT', 'Flags', {})]],
[('HKL', 'ActivateKeyboardLayout'), [('HKL', 'hkl', {}), ('UINT', 'Flags', {})]],
[('int', 'ToUnicodeEx'), [('UINT', 'wVirtKey', {}), ('UINT', 'wScanCode', {}), ('CONST BYTE*', 'lpKeyState', {}), ('LPWSTR', 'pwszBuff', {'IO': 'O', 'cnt': 'cchBuff'}), ('int', 'cchBuff', {}), ('UINT', 'wFlags', {}), ('HKL', 'dwhkl', {})]],
[('BOOL', 'UnloadKeyboardLayout'), [('HKL', 'hkl', {})]],
[('BOOL', 'GetKeyboardLayoutNameA'), [('LPSTR', 'pwszKLID', {'IO': 'O', 'cnt': 'KL_NAMELENGTH'})]],
[('BOOL', 'GetKeyboardLayoutNameW'), [('LPWSTR', 'pwszKLID', {'IO': 'O', 'cnt': 'KL_NAMELENGTH'})]],
[('int', 'GetKeyboardLayoutList'), [('int', 'nBuff', {}), ('HKL*', 'lpList', {'IO': 'O', 'cnt': 'nBuff, ret'})]],
[('HKL', 'GetKeyboardLayout'), [('DWORD', 'idThread', {})]],
[('int', 'GetMouseMovePointsEx'), [('UINT', 'cbSize', {}), ('LPMOUSEMOVEPOINT', 'lppt', {}), ('LPMOUSEMOVEPOINT', 'lpptBuf', {'IO': 'O', 'cnt': 'nBufPoints'}), ('int', 'nBufPoints', {}), ('DWORD', 'resolution', {})]],
[('HDESK', 'CreateDesktopA'), [('LPCSTR', 'lpszDesktop', {}), ('LPCSTR', 'lpszDevice', {}), ('DEVMODEA*', ' pDevmode', {}), ('DWORD', 'dwFlags', {}), ('ACCESS_MASK', 'dwDesiredAccess', {}), ('LPSECURITY_ATTRIBUTES', 'lpsa', {})]],
[('HDESK', 'CreateDesktopW'), [('LPCWSTR', 'lpszDesktop', {}), ('LPCWSTR', 'lpszDevice', {}), ('DEVMODEW*', ' pDevmode', {}), ('DWORD', 'dwFlags', {}), ('ACCESS_MASK', 'dwDesiredAccess', {}), ('LPSECURITY_ATTRIBUTES', 'lpsa', {})]],
[('HDESK', 'CreateDesktopExA'), [('LPCSTR', 'lpszDesktop', {}), ('LPCSTR', 'lpszDevice', {}), ('DEVMODEA*', ' pDevmode', {}), ('DWORD', 'dwFlags', {}), ('ACCESS_MASK', 'dwDesiredAccess', {}), ('LPSECURITY_ATTRIBUTES', 'lpsa', {}), ('ULONG', 'ulHeapSize', {}), ('PVOID', 'pvoid', {})]],
[('HDESK', 'CreateDesktopExW'), [('LPCWSTR', 'lpszDesktop', {}), ('LPCWSTR', 'lpszDevice', {}), ('DEVMODEW*', ' pDevmode', {}), ('DWORD', 'dwFlags', {}), ('ACCESS_MASK', 'dwDesiredAccess', {}), ('LPSECURITY_ATTRIBUTES', 'lpsa', {}), ('ULONG', 'ulHeapSize', {}), ('PVOID', 'pvoid', {})]],
[('HDESK', 'OpenDesktopA'), [('LPCSTR', 'lpszDesktop', {}), ('DWORD', 'dwFlags', {}), ('BOOL', 'fInherit', {}), ('ACCESS_MASK', 'dwDesiredAccess', {})]],
[('HDESK', 'OpenDesktopW'), [('LPCWSTR', 'lpszDesktop', {}), ('DWORD', 'dwFlags', {}), ('BOOL', 'fInherit', {}), ('ACCESS_MASK', 'dwDesiredAccess', {})]],
[('HDESK', 'OpenInputDesktop'), [('DWORD', 'dwFlags', {}), ('BOOL', 'fInherit', {}), ('ACCESS_MASK', 'dwDesiredAccess', {})]],
[('BOOL', 'EnumDesktopsA'), [('HWINSTA', 'hwinsta', {}), ('DESKTOPENUMPROCA', 'lpEnumFunc', {}), ('LPARAM', 'lParam', {})]],
[('BOOL', 'EnumDesktopsW'), [('HWINSTA', 'hwinsta', {}), ('DESKTOPENUMPROCW', 'lpEnumFunc', {}), ('LPARAM', 'lParam', {})]],
[('BOOL', 'EnumDesktopWindows'), [('HDESK', 'hDesktop', {}), ('WNDENUMPROC', 'lpfn', {}), ('LPARAM', 'lParam', {})]],
[('BOOL', 'SwitchDesktop'), [('HDESK', 'hDesktop', {})]],
[('BOOL', 'SetThreadDesktop'), [('HDESK', 'hDesktop', {})]],
[('BOOL', 'CloseDesktop'), [('HDESK', 'hDesktop', {})]],
[('HDESK', 'GetThreadDesktop'), [('DWORD', 'dwThreadId', {})]],
[('HWINSTA', 'CreateWindowStationA'), [('LPCSTR', 'lpwinsta', {}), ('DWORD', 'dwFlags', {}), ('ACCESS_MASK', 'dwDesiredAccess', {}), ('LPSECURITY_ATTRIBUTES', 'lpsa', {})]],
[('HWINSTA', 'CreateWindowStationW'), [('LPCWSTR', 'lpwinsta', {}), ('DWORD', 'dwFlags', {}), ('ACCESS_MASK', 'dwDesiredAccess', {}), ('LPSECURITY_ATTRIBUTES', 'lpsa', {})]],
[('HWINSTA', 'OpenWindowStationA'), [('LPCSTR', 'lpszWinSta', {}), ('BOOL', 'fInherit', {}), ('ACCESS_MASK', 'dwDesiredAccess', {})]],
[('HWINSTA', 'OpenWindowStationW'), [('LPCWSTR', 'lpszWinSta', {}), ('BOOL', 'fInherit', {}), ('ACCESS_MASK', 'dwDesiredAccess', {})]],
[('BOOL', 'EnumWindowStationsA'), [('WINSTAENUMPROCA', 'lpEnumFunc', {}), ('LPARAM', 'lParam', {})]],
[('BOOL', 'EnumWindowStationsW'), [('WINSTAENUMPROCW', 'lpEnumFunc', {}), ('LPARAM', 'lParam', {})]],
[('BOOL', 'CloseWindowStation'), [('HWINSTA', 'hWinSta', {})]],
[('BOOL', 'SetProcessWindowStation'), [('HWINSTA', 'hWinSta', {})]],
[('HWINSTA', 'GetProcessWindowStation'), []],
[('BOOL', 'SetUserObjectSecurity'), [('HANDLE', 'hObj', {}), ('PSECURITY_INFORMATION', 'pSIRequested', {}), ('PSECURITY_DESCRIPTOR', 'pSID', {})]],
[('BOOL', 'GetUserObjectSecurity'), [('HANDLE', 'hObj', {}), ('PSECURITY_INFORMATION', 'pSIRequested', {}), ('PSECURITY_DESCRIPTOR', 'pSID', {'IO': 'O'}), ('DWORD', 'nLength', {}), ('LPDWORD', 'lpnLengthNeeded', {'IO': 'O'})]],
[('BOOL', 'GetUserObjectInformationA'), [('HANDLE', 'hObj', {}), ('int', 'nIndex', {}), ('PVOID', 'pvInfo', {'IO': 'O'}), ('DWORD', 'nLength', {}), ('LPDWORD', 'lpnLengthNeeded', {'IO': 'O'})]],
[('BOOL', 'GetUserObjectInformationW'), [('HANDLE', 'hObj', {}), ('int', 'nIndex', {}), ('PVOID', 'pvInfo', {'IO': 'O'}), ('DWORD', 'nLength', {}), ('LPDWORD', 'lpnLengthNeeded', {'IO': 'O'})]],
[('BOOL', 'SetUserObjectInformationA'), [('HANDLE', 'hObj', {}), ('int', 'nIndex', {}), ('PVOID', 'pvInfo', {}), ('DWORD', 'nLength', {})]],
[('BOOL', 'SetUserObjectInformationW'), [('HANDLE', 'hObj', {}), ('int', 'nIndex', {}), ('PVOID', 'pvInfo', {}), ('DWORD', 'nLength', {})]],
[('BOOL', 'IsHungAppWindow'), [('HWND', 'hwnd', {})]],
[('VOID', 'DisableProcessWindowsGhosting'), []],
[('UINT', 'RegisterWindowMessageA'), [('LPCSTR', 'lpString', {})]],
[('UINT', 'RegisterWindowMessageW'), [('LPCWSTR', 'lpString', {})]],
[('BOOL', 'TrackMouseEvent'), [('LPTRACKMOUSEEVENT', 'lpEventTrack', {'IO': 'IO'})]],
[('BOOL', 'DrawEdge'), [('HDC', 'hdc', {}), ('LPRECT', 'qrc', {'IO': 'IO'}), ('UINT', 'edge', {}), ('UINT', 'grfFlags', {})]],
[('BOOL', 'DrawFrameControl'), [('HDC', 'arg0', {}), ('LPRECT', 'arg1', {'IO': 'IO'}), ('UINT', 'arg2', {}), ('UINT', 'arg3', {})]],
[('BOOL', 'DrawCaption'), [('HWND', 'hwnd', {}), ('HDC', 'hdc', {}), ('CONST RECT*', ' lprect', {}), ('UINT', 'flags', {})]],
[('BOOL', 'DrawAnimatedRects'), [('HWND', 'hwnd', {}), ('int', 'idAni', {}), ('CONST RECT*', 'lprcFrom', {}), ('CONST RECT*', 'lprcTo', {})]],
[('BOOL', 'GetMessageA'), [('LPMSG', 'lpMsg', {'IO': 'O'}), ('HWND', 'hWnd', {}), ('UINT', 'wMsgFilterMin', {}), ('UINT', 'wMsgFilterMax', {})]],
[('BOOL', 'GetMessageW'), [('LPMSG', 'lpMsg', {'IO': 'O'}), ('HWND', 'hWnd', {}), ('UINT', 'wMsgFilterMin', {}), ('UINT', 'wMsgFilterMax', {})]],
[('BOOL', 'TranslateMessage'), [('CONST MSG*', 'lpMsg', {})]],
[('LRESULT', 'DispatchMessageA'), [('CONST MSG*', 'lpMsg', {})]],
[('LRESULT', 'DispatchMessageW'), [('CONST MSG*', 'lpMsg', {})]],
[('BOOL', 'SetMessageQueue'), [('int', 'cMessagesMax', {})]],
[('BOOL', 'PeekMessageA'), [('LPMSG', 'lpMsg', {'IO': 'O'}), ('HWND', 'hWnd', {}), ('UINT', 'wMsgFilterMin', {}), ('UINT', 'wMsgFilterMax', {}), ('UINT', 'wRemoveMsg', {})]],
[('BOOL', 'PeekMessageW'), [('LPMSG', 'lpMsg', {'IO': 'O'}), ('HWND', 'hWnd', {}), ('UINT', 'wMsgFilterMin', {}), ('UINT', 'wMsgFilterMax', {}), ('UINT', 'wRemoveMsg', {})]],
[('BOOL', 'RegisterHotKey'), [('HWND', 'hWnd', {}), ('int', 'id', {}), ('UINT', 'fsModifiers', {}), ('UINT', 'vk', {})]],
[('BOOL', 'UnregisterHotKey'), [('HWND', 'hWnd', {}), ('int', 'id', {})]],
[('BOOL', 'ExitWindowsEx'), [('UINT', 'uFlags', {}), ('DWORD', 'dwReason', {})]],
[('BOOL', 'SwapMouseButton'), [('BOOL', 'fSwap', {})]],
[('DWORD', 'GetMessagePos'), []],
[('LONG', 'GetMessageTime'), []],
[('LPARAM', 'GetMessageExtraInfo'), []],
[('BOOL', 'IsWow64Message'), []],
[('LPARAM', 'SetMessageExtraInfo'), [('LPARAM', 'lParam', {})]],
[('LRESULT', 'SendMessageA'), [('HWND', 'hWnd', {}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('LRESULT', 'SendMessageW'), [('HWND', 'hWnd', {}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('LRESULT', 'SendMessageTimeoutA'), [('HWND', 'hWnd', {}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {}), ('UINT', 'fuFlags', {}), ('UINT', 'uTimeout', {}), ('PDWORD_PTR', 'lpdwResult', {'IO': 'O'})]],
[('LRESULT', 'SendMessageTimeoutW'), [('HWND', 'hWnd', {}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {}), ('UINT', 'fuFlags', {}), ('UINT', 'uTimeout', {}), ('PDWORD_PTR', 'lpdwResult', {'IO': 'O'})]],
[('BOOL', 'SendNotifyMessageA'), [('HWND', 'hWnd', {}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('BOOL', 'SendNotifyMessageW'), [('HWND', 'hWnd', {}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('BOOL', 'SendMessageCallbackA'), [('HWND', 'hWnd', {}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {}), ('SENDASYNCPROC', 'lpResultCallBack', {}), ('ULONG_PTR', 'dwData', {})]],
[('BOOL', 'SendMessageCallbackW'), [('HWND', 'hWnd', {}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {}), ('SENDASYNCPROC', 'lpResultCallBack', {}), ('ULONG_PTR', 'dwData', {})]],
[('long', 'BroadcastSystemMessageExA'), [('DWORD', 'flags', {}), ('LPDWORD', 'lpInfo', {'IO': 'IO'}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {}), ('PBSMINFO', 'pbsmInfo', {'IO': 'O'})]],
[('long', 'BroadcastSystemMessageExW'), [('DWORD', 'flags', {}), ('LPDWORD', 'lpInfo', {'IO': 'IO'}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {}), ('PBSMINFO', 'pbsmInfo', {'IO': 'O'})]],
[('long', 'BroadcastSystemMessageA'), [('DWORD', 'flags', {}), ('LPDWORD', 'lpInfo', {'IO': 'IO'}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('long', 'BroadcastSystemMessageW'), [('DWORD', 'flags', {}), ('LPDWORD', 'lpInfo', {'IO': 'IO'}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('long', 'BroadcastSystemMessage'), [('DWORD', 'flags', {}), ('LPDWORD', 'lpInfo', {'IO': 'IO'}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('HDEVNOTIFY', 'RegisterDeviceNotificationA'), [('HANDLE', 'hRecipient', {}), ('LPVOID', 'NotificationFilter', {}), ('DWORD', 'Flags', {})]],
[('HDEVNOTIFY', 'RegisterDeviceNotificationW'), [('HANDLE', 'hRecipient', {}), ('LPVOID', 'NotificationFilter', {}), ('DWORD', 'Flags', {})]],
[('BOOL', 'UnregisterDeviceNotification'), [('HDEVNOTIFY', 'handle', {})]],
[('HPOWERNOTIFY', 'RegisterPowerSettingNotification'), [('HANDLE', 'hRecipient', {}), ('LPCGUID', 'PowerSettingGuid', {}), ('DWORD', 'Flags', {})]],
[('BOOL', 'UnregisterPowerSettingNotification'), [('HPOWERNOTIFY', 'Handle', {})]],
[('BOOL', 'PostMessageA'), [('HWND', 'hWnd', {}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('BOOL', 'PostMessageW'), [('HWND', 'hWnd', {}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('BOOL', 'PostThreadMessageA'), [('DWORD', 'idThread', {}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('BOOL', 'PostThreadMessageW'), [('DWORD', 'idThread', {}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('BOOL', 'AttachThreadInput'), [('DWORD', 'idAttach', {}), ('DWORD', 'idAttachTo', {}), ('BOOL', 'fAttach', {})]],
[('BOOL', 'ReplyMessage'), [('LRESULT', 'lResult', {})]],
[('BOOL', 'WaitMessage'), []],
[('DWORD', 'WaitForInputIdle'), [('HANDLE', 'hProcess', {}), ('DWORD', 'dwMilliseconds', {})]],
[('LRESULT', 'DefWindowProcA'), [('HWND', 'hWnd', {}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('LRESULT', 'DefWindowProcW'), [('HWND', 'hWnd', {}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('VOID', 'PostQuitMessage'), [('int', 'nExitCode', {})]],
[('LRESULT', 'CallWindowProcA'), [('WNDPROC', 'lpPrevWndFunc', {}), ('HWND', 'hWnd', {}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('LRESULT', 'CallWindowProcW'), [('WNDPROC', 'lpPrevWndFunc', {}), ('HWND', 'hWnd', {}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('BOOL', 'InSendMessage'), []],
[('DWORD', 'InSendMessageEx'), [('LPVOID', 'lpReserved', {})]],
[('UINT', 'GetDoubleClickTime'), []],
[('BOOL', 'SetDoubleClickTime'), [('UINT', 'arg0', {})]],
[('ATOM', 'RegisterClassA'), [('CONST WNDCLASSA*', 'lpWndClass', {})]],
[('ATOM', 'RegisterClassW'), [('CONST WNDCLASSW*', 'lpWndClass', {})]],
[('BOOL', 'UnregisterClassA'), [('LPCSTR', 'lpClassName', {}), ('HINSTANCE', 'hInstance', {})]],
[('BOOL', 'UnregisterClassW'), [('LPCWSTR', 'lpClassName', {}), ('HINSTANCE', 'hInstance', {})]],
[('BOOL', 'GetClassInfoA'), [('HINSTANCE', 'hInstance', {}), ('LPCSTR', 'lpClassName', {}), ('LPWNDCLASSA', 'lpWndClass', {'IO': 'O'})]],
[('BOOL', 'GetClassInfoW'), [('HINSTANCE', 'hInstance', {}), ('LPCWSTR', 'lpClassName', {}), ('LPWNDCLASSW', 'lpWndClass', {'IO': 'O'})]],
[('ATOM', 'RegisterClassExA'), [('CONST WNDCLASSEXA*', 'arg0', {})]],
[('ATOM', 'RegisterClassExW'), [('CONST WNDCLASSEXW*', 'arg0', {})]],
[('BOOL', 'GetClassInfoExA'), [('HINSTANCE', 'hInstance', {}), ('LPCSTR', 'lpszClass', {}), ('LPWNDCLASSEXA', 'lpwcx', {'IO': 'O'})]],
[('BOOL', 'GetClassInfoExW'), [('HINSTANCE', 'hInstance', {}), ('LPCWSTR', 'lpszClass', {}), ('LPWNDCLASSEXW', 'lpwcx', {'IO': 'O'})]],
[('HWND', 'CreateWindowExA'), [('DWORD', 'dwExStyle', {}), ('LPCSTR', 'lpClassName', {}), ('LPCSTR', 'lpWindowName', {}), ('DWORD', 'dwStyle', {}), ('int', 'X', {}), ('int', 'Y', {}), ('int', 'nWidth', {}), ('int', 'nHeight', {}), ('HWND', 'hWndParent', {}), ('HMENU', 'hMenu', {}), ('HINSTANCE', 'hInstance', {}), ('LPVOID', 'lpParam', {})]],
[('HWND', 'CreateWindowExW'), [('DWORD', 'dwExStyle', {}), ('LPCWSTR', 'lpClassName', {}), ('LPCWSTR', 'lpWindowName', {}), ('DWORD', 'dwStyle', {}), ('int', 'X', {}), ('int', 'Y', {}), ('int', 'nWidth', {}), ('int', 'nHeight', {}), ('HWND', 'hWndParent', {}), ('HMENU', 'hMenu', {}), ('HINSTANCE', 'hInstance', {}), ('LPVOID', 'lpParam', {})]],
[('BOOL', 'IsWindow'), [('HWND', 'hWnd', {})]],
[('BOOL', 'IsMenu'), [('HMENU', 'hMenu', {})]],
[('BOOL', 'IsChild'), [('HWND', 'hWndParent', {}), ('HWND', 'hWnd', {})]],
[('BOOL', 'DestroyWindow'), [('HWND', 'hWnd', {})]],
[('BOOL', 'ShowWindow'), [('HWND', 'hWnd', {}), ('int', 'nCmdShow', {})]],
[('BOOL', 'AnimateWindow'), [('HWND', 'hWnd', {}), ('DWORD', 'dwTime', {}), ('DWORD', 'dwFlags', {})]],
[('BOOL', 'UpdateLayeredWindow'), [('HWND', 'hWnd', {}), ('HDC', 'hdcDst', {}), ('POINT*', ' pptDst', {}), ('SIZE*', ' psize', {}), ('HDC', 'hdcSrc', {}), ('POINT*', ' pptSrc', {}), ('COLORREF', 'crKey', {}), ('BLENDFUNCTION*', ' pblend', {}), ('DWORD', 'dwFlags', {})]],
[('BOOL', 'UpdateLayeredWindowIndirect'), [('HWND', 'hWnd', {}), ('CONST UPDATELAYEREDWINDOWINFO*', ' pULWInfo', {})]],
[('BOOL', 'GetLayeredWindowAttributes'), [('HWND', 'hwnd', {}), ('COLORREF*', ' pcrKey', {'IO': 'O'}), ('BYTE*', ' pbAlpha', {'IO': 'O'}), ('DWORD*', ' pdwFlags', {'IO': 'O'})]],
[('BOOL', 'PrintWindow'), [('HWND', 'hwnd', {}), ('HDC', 'hdcBlt', {}), ('UINT', 'nFlags', {})]],
[('BOOL', 'SetLayeredWindowAttributes'), [('HWND', 'hwnd', {}), ('COLORREF', 'crKey', {}), ('BYTE', 'bAlpha', {}), ('DWORD', 'dwFlags', {})]],
[('BOOL', 'ShowWindowAsync'), [('HWND', 'hWnd', {}), ('int', 'nCmdShow', {})]],
[('BOOL', 'FlashWindow'), [('HWND', 'hWnd', {}), ('BOOL', 'bInvert', {})]],
[('BOOL', 'FlashWindowEx'), [('PFLASHWINFO', 'pfwi', {})]],
[('BOOL', 'ShowOwnedPopups'), [('HWND', 'hWnd', {}), ('BOOL', 'fShow', {})]],
[('BOOL', 'OpenIcon'), [('HWND', 'hWnd', {})]],
[('BOOL', 'CloseWindow'), [('HWND', 'hWnd', {})]],
[('BOOL', 'MoveWindow'), [('HWND', 'hWnd', {}), ('int', 'X', {}), ('int', 'Y', {}), ('int', 'nWidth', {}), ('int', 'nHeight', {}), ('BOOL', 'bRepaint', {})]],
[('BOOL', 'SetWindowPos'), [('HWND', 'hWnd', {}), ('HWND', 'hWndInsertAfter', {}), ('int', 'X', {}), ('int', 'Y', {}), ('int', 'cx', {}), ('int', 'cy', {}), ('UINT', 'uFlags', {})]],
[('BOOL', 'GetWindowPlacement'), [('HWND', 'hWnd', {}), ('WINDOWPLACEMENT*', 'lpwndpl', {'IO': 'IO'})]],
[('BOOL', 'SetWindowPlacement'), [('HWND', 'hWnd', {}), ('CONST WINDOWPLACEMENT*', 'lpwndpl', {})]],
[('BOOL', 'GetWindowDisplayAffinity'), [('HWND', 'hWnd', {}), ('DWORD*', ' pdwAffinity', {'IO': 'O'})]],
[('BOOL', 'SetWindowDisplayAffinity'), [('HWND', 'hWnd', {}), ('DWORD', 'dwAffinity', {})]],
[('HDWP', 'BeginDeferWindowPos'), [('int', 'nNumWindows', {})]],
[('HDWP', 'DeferWindowPos'), [('HDWP', 'hWinPosInfo', {}), ('HWND', 'hWnd', {}), ('HWND', 'hWndInsertAfter', {}), ('int', 'x', {}), ('int', 'y', {}), ('int', 'cx', {}), ('int', 'cy', {}), ('UINT', 'uFlags', {})]],
[('BOOL', 'EndDeferWindowPos'), [('HDWP', 'hWinPosInfo', {})]],
[('BOOL', 'IsWindowVisible'), [('HWND', 'hWnd', {})]],
[('BOOL', 'IsIconic'), [('HWND', 'hWnd', {})]],
[('BOOL', 'AnyPopup'), []],
[('BOOL', 'BringWindowToTop'), [('HWND', 'hWnd', {})]],
[('BOOL', 'IsZoomed'), [('HWND', 'hWnd', {})]],
[('HWND', 'CreateDialogParamA'), [('HINSTANCE', 'hInstance', {}), ('LPCSTR', 'lpTemplateName', {}), ('HWND', 'hWndParent', {}), ('DLGPROC', 'lpDialogFunc', {}), ('LPARAM', 'dwInitParam', {})]],
[('HWND', 'CreateDialogParamW'), [('HINSTANCE', 'hInstance', {}), ('LPCWSTR', 'lpTemplateName', {}), ('HWND', 'hWndParent', {}), ('DLGPROC', 'lpDialogFunc', {}), ('LPARAM', 'dwInitParam', {})]],
[('HWND', 'CreateDialogIndirectParamA'), [('HINSTANCE', 'hInstance', {}), ('LPCDLGTEMPLATEA', 'lpTemplate', {}), ('HWND', 'hWndParent', {}), ('DLGPROC', 'lpDialogFunc', {}), ('LPARAM', 'dwInitParam', {})]],
[('HWND', 'CreateDialogIndirectParamW'), [('HINSTANCE', 'hInstance', {}), ('LPCDLGTEMPLATEW', 'lpTemplate', {}), ('HWND', 'hWndParent', {}), ('DLGPROC', 'lpDialogFunc', {}), ('LPARAM', 'dwInitParam', {})]],
[('INT_PTR', 'DialogBoxParamA'), [('HINSTANCE', 'hInstance', {}), ('LPCSTR', 'lpTemplateName', {}), ('HWND', 'hWndParent', {}), ('DLGPROC', 'lpDialogFunc', {}), ('LPARAM', 'dwInitParam', {})]],
[('INT_PTR', 'DialogBoxParamW'), [('HINSTANCE', 'hInstance', {}), ('LPCWSTR', 'lpTemplateName', {}), ('HWND', 'hWndParent', {}), ('DLGPROC', 'lpDialogFunc', {}), ('LPARAM', 'dwInitParam', {})]],
[('INT_PTR', 'DialogBoxIndirectParamA'), [('HINSTANCE', 'hInstance', {}), ('LPCDLGTEMPLATEA', 'hDialogTemplate', {}), ('HWND', 'hWndParent', {}), ('DLGPROC', 'lpDialogFunc', {}), ('LPARAM', 'dwInitParam', {})]],
[('INT_PTR', 'DialogBoxIndirectParamW'), [('HINSTANCE', 'hInstance', {}), ('LPCDLGTEMPLATEW', 'hDialogTemplate', {}), ('HWND', 'hWndParent', {}), ('DLGPROC', 'lpDialogFunc', {}), ('LPARAM', 'dwInitParam', {})]],
[('BOOL', 'EndDialog'), [('HWND', 'hDlg', {}), ('INT_PTR', 'nResult', {})]],
[('HWND', 'GetDlgItem'), [('HWND', 'hDlg', {}), ('int', 'nIDDlgItem', {})]],
[('BOOL', 'SetDlgItemInt'), [('HWND', 'hDlg', {}), ('int', 'nIDDlgItem', {}), ('UINT', 'uValue', {}), ('BOOL', 'bSigned', {})]],
[('UINT', 'GetDlgItemInt'), [('HWND', 'hDlg', {}), ('int', 'nIDDlgItem', {}), ('BOOL*', 'lpTranslated', {'IO': 'O'}), ('BOOL', 'bSigned', {})]],
[('BOOL', 'SetDlgItemTextA'), [('HWND', 'hDlg', {}), ('int', 'nIDDlgItem', {}), ('LPCSTR', 'lpString', {})]],
[('BOOL', 'SetDlgItemTextW'), [('HWND', 'hDlg', {}), ('int', 'nIDDlgItem', {}), ('LPCWSTR', 'lpString', {})]],
[('UINT', 'GetDlgItemTextA'), [('HWND', 'hDlg', {}), ('int', 'nIDDlgItem', {}), ('LPSTR', 'lpString', {'IO': 'O', 'cnt': 'cchMax'}), ('int', 'cchMax', {})]],
[('UINT', 'GetDlgItemTextW'), [('HWND', 'hDlg', {}), ('int', 'nIDDlgItem', {}), ('LPWSTR', 'lpString', {'IO': 'O', 'cnt': 'cchMax'}), ('int', 'cchMax', {})]],
[('BOOL', 'CheckDlgButton'), [('HWND', 'hDlg', {}), ('int', 'nIDButton', {}), ('UINT', 'uCheck', {})]],
[('BOOL', 'CheckRadioButton'), [('HWND', 'hDlg', {}), ('int', 'nIDFirstButton', {}), ('int', 'nIDLastButton', {}), ('int', 'nIDCheckButton', {})]],
[('UINT', 'IsDlgButtonChecked'), [('HWND', 'hDlg', {}), ('int', 'nIDButton', {})]],
[('LRESULT', 'SendDlgItemMessageA'), [('HWND', 'hDlg', {}), ('int', 'nIDDlgItem', {}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('LRESULT', 'SendDlgItemMessageW'), [('HWND', 'hDlg', {}), ('int', 'nIDDlgItem', {}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('HWND', 'GetNextDlgGroupItem'), [('HWND', 'hDlg', {}), ('HWND', 'hCtl', {}), ('BOOL', 'bPrevious', {})]],
[('HWND', 'GetNextDlgTabItem'), [('HWND', 'hDlg', {}), ('HWND', 'hCtl', {}), ('BOOL', 'bPrevious', {})]],
[('int', 'GetDlgCtrlID'), [('HWND', 'hWnd', {})]],
[('long', 'GetDialogBaseUnits'), []],
[('LRESULT', 'DefDlgProcA'), [('HWND', 'hDlg', {}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('LRESULT', 'DefDlgProcW'), [('HWND', 'hDlg', {}), ('UINT', 'Msg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('BOOL', 'CallMsgFilterA'), [('LPMSG', 'lpMsg', {}), ('int', 'nCode', {})]],
[('BOOL', 'CallMsgFilterW'), [('LPMSG', 'lpMsg', {}), ('int', 'nCode', {})]],
[('BOOL', 'OpenClipboard'), [('HWND', 'hWndNewOwner', {})]],
[('BOOL', 'CloseClipboard'), []],
[('DWORD', 'GetClipboardSequenceNumber'), []],
[('HWND', 'GetClipboardOwner'), []],
[('HWND', 'SetClipboardViewer'), [('HWND', 'hWndNewViewer', {})]],
[('HWND', 'GetClipboardViewer'), []],
[('BOOL', 'ChangeClipboardChain'), [('HWND', 'hWndRemove', {}), ('HWND', 'hWndNewNext', {})]],
[('HANDLE', 'SetClipboardData'), [('UINT', 'uFormat', {}), ('HANDLE', 'hMem', {})]],
[('HANDLE', 'GetClipboardData'), [('UINT', 'uFormat', {})]],
[('UINT', 'RegisterClipboardFormatA'), [('LPCSTR', 'lpszFormat', {})]],
[('UINT', 'RegisterClipboardFormatW'), [('LPCWSTR', 'lpszFormat', {})]],
[('int', 'CountClipboardFormats'), []],
[('UINT', 'EnumClipboardFormats'), [('UINT', 'format', {})]],
[('int', 'GetClipboardFormatNameA'), [('UINT', 'format', {}), ('LPSTR', 'lpszFormatName', {'IO': 'O', 'cnt': 'cchMaxCount'}), ('int', 'cchMaxCount', {})]],
[('int', 'GetClipboardFormatNameW'), [('UINT', 'format', {}), ('LPWSTR', 'lpszFormatName', {'IO': 'O', 'cnt': 'cchMaxCount'}), ('int', 'cchMaxCount', {})]],
[('BOOL', 'EmptyClipboard'), []],
[('BOOL', 'IsClipboardFormatAvailable'), [('UINT', 'format', {})]],
[('int', 'GetPriorityClipboardFormat'), [('UINT*', 'paFormatPriorityList', {'cnt': 'cFormats'}), ('int', 'cFormats', {})]],
[('HWND', 'GetOpenClipboardWindow'), []],
[('BOOL', 'AddClipboardFormatListener'), [('HWND', 'hwnd', {})]],
[('BOOL', 'RemoveClipboardFormatListener'), [('HWND', 'hwnd', {})]],
[('BOOL', 'GetUpdatedClipboardFormats'), [('PUINT', 'lpuiFormats', {'IO': 'O', 'cnt': 'cFormats'}), ('UINT', 'cFormats', {}), ('PUINT', 'pcFormatsOut', {'IO': 'O'})]],
[('BOOL', 'CharToOemA'), [('LPCSTR', 'pSrc', {}), ('LPSTR', 'pDst', {'IO': 'O'})]],
[('BOOL', 'CharToOemW'), [('LPCWSTR', 'pSrc', {}), ('LPSTR', 'pDst', {'IO': 'O'})]],
[('BOOL', 'OemToCharA'), [('LPCSTR', 'pSrc', {}), ('LPSTR', 'pDst', {'IO': 'O'})]],
[('BOOL', 'OemToCharW'), [('LPCSTR', 'pSrc', {}), ('LPWSTR', 'pDst', {'IO': 'O'})]],
[('BOOL', 'CharToOemBuffA'), [('LPCSTR', 'lpszSrc', {}), ('LPSTR', 'lpszDst', {'IO': 'O', 'cnt': 'cchDstLength'}), ('DWORD', 'cchDstLength', {})]],
[('BOOL', 'CharToOemBuffW'), [('LPCWSTR', 'lpszSrc', {}), ('LPSTR', 'lpszDst', {'IO': 'O', 'cnt': 'cchDstLength'}), ('DWORD', 'cchDstLength', {})]],
[('BOOL', 'OemToCharBuffA'), [('LPCSTR', 'lpszSrc', {}), ('LPSTR', 'lpszDst', {'IO': 'O', 'cnt': 'cchDstLength'}), ('DWORD', 'cchDstLength', {})]],
[('BOOL', 'OemToCharBuffW'), [('LPCSTR', 'lpszSrc', {}), ('LPWSTR', 'lpszDst', {'IO': 'O', 'cnt': 'cchDstLength'}), ('DWORD', 'cchDstLength', {})]],
[('LPSTR', 'CharUpperA'), [('LPSTR', 'lpsz', {'IO': 'IO'})]],
[('LPWSTR', 'CharUpperW'), [('LPWSTR', 'lpsz', {'IO': 'IO'})]],
[('DWORD', 'CharUpperBuffA'), [('LPSTR', 'lpsz', {'IO': 'IO', 'cnt': 'cchLength'}), ('DWORD', 'cchLength', {})]],
[('DWORD', 'CharUpperBuffW'), [('LPWSTR', 'lpsz', {'IO': 'IO', 'cnt': 'cchLength'}), ('DWORD', 'cchLength', {})]],
[('LPSTR', 'CharLowerA'), [('LPSTR', 'lpsz', {'IO': 'IO'})]],
[('LPWSTR', 'CharLowerW'), [('LPWSTR', 'lpsz', {'IO': 'IO'})]],
[('DWORD', 'CharLowerBuffA'), [('LPSTR', 'lpsz', {'IO': 'IO', 'cnt': 'cchLength'}), ('DWORD', 'cchLength', {})]],
[('DWORD', 'CharLowerBuffW'), [('LPWSTR', 'lpsz', {'IO': 'IO', 'cnt': 'cchLength'}), ('DWORD', 'cchLength', {})]],
[('LPSTR', 'CharNextA'), [('LPCSTR', 'lpsz', {})]],
[('LPWSTR', 'CharNextW'), [('LPCWSTR', 'lpsz', {})]],
[('LPSTR', 'CharPrevA'), [('LPCSTR', 'lpszStart', {}), ('LPCSTR', 'lpszCurrent', {})]],
[('LPWSTR', 'CharPrevW'), [('LPCWSTR', 'lpszStart', {}), ('LPCWSTR', 'lpszCurrent', {})]],
[('LPSTR', 'CharNextExA'), [('WORD', 'CodePage', {}), ('LPCSTR', 'lpCurrentChar', {}), ('DWORD', 'dwFlags', {})]],
[('LPSTR', 'CharPrevExA'), [('WORD', 'CodePage', {}), ('LPCSTR', 'lpStart', {}), ('LPCSTR', 'lpCurrentChar', {}), ('DWORD', 'dwFlags', {})]],
[('BOOL', 'IsCharAlphaA'), [('CHAR', 'ch', {})]],
[('BOOL', 'IsCharAlphaW'), [('WCHAR', 'ch', {})]],
[('BOOL', 'IsCharAlphaNumericA'), [('CHAR', 'ch', {})]],
[('BOOL', 'IsCharAlphaNumericW'), [('WCHAR', 'ch', {})]],
[('BOOL', 'IsCharUpperA'), [('CHAR', 'ch', {})]],
[('BOOL', 'IsCharUpperW'), [('WCHAR', 'ch', {})]],
[('BOOL', 'IsCharLowerA'), [('CHAR', 'ch', {})]],
[('BOOL', 'IsCharLowerW'), [('WCHAR', 'ch', {})]],
[('HWND', 'SetFocus'), [('HWND', 'hWnd', {})]],
[('HWND', 'GetActiveWindow'), []],
[('HWND', 'GetFocus'), []],
[('UINT', 'GetKBCodePage'), []],
[('SHORT', 'GetKeyState'), [('int', 'nVirtKey', {})]],
[('SHORT', 'GetAsyncKeyState'), [('int', 'vKey', {})]],
[('BOOL', 'GetKeyboardState'), [('PBYTE', 'lpKeyState', {'IO': 'O', 'cnt': '256'})]],
[('BOOL', 'SetKeyboardState'), [('LPBYTE', 'lpKeyState', {'cnt': '256'})]],
[('int', 'GetKeyNameTextA'), [('LONG', 'lParam', {}), ('LPSTR', 'lpString', {'IO': 'O', 'cnt': 'cchSize'}), ('int', 'cchSize', {})]],
[('int', 'GetKeyNameTextW'), [('LONG', 'lParam', {}), ('LPWSTR', 'lpString', {'IO': 'O', 'cnt': 'cchSize'}), ('int', 'cchSize', {})]],
[('int', 'GetKeyboardType'), [('int', 'nTypeFlag', {})]],
[('int', 'ToAscii'), [('UINT', 'uVirtKey', {}), ('UINT', 'uScanCode', {}), ('CONST BYTE*', 'lpKeyState', {'cnt': '256'}), ('LPWORD', 'lpChar', {'IO': 'O'}), ('UINT', 'uFlags', {})]],
[('int', 'ToAsciiEx'), [('UINT', 'uVirtKey', {}), ('UINT', 'uScanCode', {}), ('CONST BYTE*', 'lpKeyState', {'cnt': '256'}), ('LPWORD', 'lpChar', {'IO': 'O'}), ('UINT', 'uFlags', {}), ('HKL', 'dwhkl', {})]],
[('int', 'ToUnicode'), [('UINT', 'wVirtKey', {}), ('UINT', 'wScanCode', {}), ('CONST BYTE*', 'lpKeyState', {}), ('LPWSTR', 'pwszBuff', {'IO': 'O', 'cnt': 'cchBuff'}), ('int', 'cchBuff', {}), ('UINT', 'wFlags', {})]],
[('DWORD', 'OemKeyScan'), [('WORD', 'wOemChar', {})]],
[('SHORT', 'VkKeyScanA'), [('CHAR', 'ch', {})]],
[('SHORT', 'VkKeyScanW'), [('WCHAR', 'ch', {})]],
[('SHORT', 'VkKeyScanExA'), [('CHAR', 'ch', {}), ('HKL', 'dwhkl', {})]],
[('SHORT', 'VkKeyScanExW'), [('WCHAR', 'ch', {}), ('HKL', 'dwhkl', {})]],
[('VOID', 'keybd_event'), [('BYTE', 'bVk', {}), ('BYTE', 'bScan', {}), ('DWORD', 'dwFlags', {}), ('ULONG_PTR', 'dwExtraInfo', {})]],
[('VOID', 'mouse_event'), [('DWORD', 'dwFlags', {}), ('DWORD', 'dx', {}), ('DWORD', 'dy', {}), ('DWORD', 'dwData', {}), ('ULONG_PTR', 'dwExtraInfo', {})]],
[('UINT', 'SendInput'), [('UINT', 'cInputs', {}), ('LPINPUT', 'pInputs', {'cnt': 'cInputs'}), ('int', 'cbSize', {})]],
[('BOOL', 'GetTouchInputInfo'), [('HTOUCHINPUT', 'hTouchInput', {}), ('UINT', 'cInputs', {}), ('PTOUCHINPUT', 'pInputs', {'IO': 'O', 'cnt': 'cInputs'}), ('int', 'cbSize', {})]],
[('BOOL', 'CloseTouchInputHandle'), [('HTOUCHINPUT', 'hTouchInput', {})]],
[('BOOL', 'RegisterTouchWindow'), [('HWND', 'hwnd', {}), ('ULONG', 'ulFlags', {})]],
[('BOOL', 'UnregisterTouchWindow'), [('HWND', 'hwnd', {})]],
[('BOOL', 'IsTouchWindow'), [('HWND', 'hwnd', {}), ('PULONG', 'pulFlags', {'IO': 'O'})]],
[('BOOL', 'GetLastInputInfo'), [('PLASTINPUTINFO', 'plii', {'IO': 'O'})]],
[('UINT', 'MapVirtualKeyA'), [('UINT', 'uCode', {}), ('UINT', 'uMapType', {})]],
[('UINT', 'MapVirtualKeyW'), [('UINT', 'uCode', {}), ('UINT', 'uMapType', {})]],
[('UINT', 'MapVirtualKeyExA'), [('UINT', 'uCode', {}), ('UINT', 'uMapType', {}), ('HKL', 'dwhkl', {})]],
[('UINT', 'MapVirtualKeyExW'), [('UINT', 'uCode', {}), ('UINT', 'uMapType', {}), ('HKL', 'dwhkl', {})]],
[('BOOL', 'GetInputState'), []],
[('DWORD', 'GetQueueStatus'), [('UINT', 'flags', {})]],
[('HWND', 'GetCapture'), []],
[('HWND', 'SetCapture'), [('HWND', 'hWnd', {})]],
[('BOOL', 'ReleaseCapture'), []],
[('DWORD', 'MsgWaitForMultipleObjects'), [('DWORD', 'nCount', {}), ('CONST HANDLE*', 'pHandles', {'cnt': 'nCount'}), ('BOOL', 'fWaitAll', {}), ('DWORD', 'dwMilliseconds', {}), ('DWORD', 'dwWakeMask', {})]],
[('DWORD', 'MsgWaitForMultipleObjectsEx'), [('DWORD', 'nCount', {}), ('CONST HANDLE*', 'pHandles', {'cnt': 'nCount'}), ('DWORD', 'dwMilliseconds', {}), ('DWORD', 'dwWakeMask', {}), ('DWORD', 'dwFlags', {})]],
[('UINT_PTR', 'SetTimer'), [('HWND', 'hWnd', {}), ('UINT_PTR', 'nIDEvent', {}), ('UINT', 'uElapse', {}), ('TIMERPROC', 'lpTimerFunc', {})]],
[('BOOL', 'KillTimer'), [('HWND', 'hWnd', {}), ('UINT_PTR', 'uIDEvent', {})]],
[('BOOL', 'IsWindowUnicode'), [('HWND', 'hWnd', {})]],
[('BOOL', 'EnableWindow'), [('HWND', 'hWnd', {}), ('BOOL', 'bEnable', {})]],
[('BOOL', 'IsWindowEnabled'), [('HWND', 'hWnd', {})]],
[('HACCEL', 'LoadAcceleratorsA'), [('HINSTANCE', 'hInstance', {}), ('LPCSTR', 'lpTableName', {})]],
[('HACCEL', 'LoadAcceleratorsW'), [('HINSTANCE', 'hInstance', {}), ('LPCWSTR', 'lpTableName', {})]],
[('HACCEL', 'CreateAcceleratorTableA'), [('LPACCEL', 'paccel', {'cnt': 'cAccel'}), ('int', 'cAccel', {})]],
[('HACCEL', 'CreateAcceleratorTableW'), [('LPACCEL', 'paccel', {'cnt': 'cAccel'}), ('int', 'cAccel', {})]],
[('BOOL', 'DestroyAcceleratorTable'), [('HACCEL', 'hAccel', {})]],
[('int', 'CopyAcceleratorTableA'), [('HACCEL', 'hAccelSrc', {}), ('LPACCEL', 'lpAccelDst', {'IO': 'O', 'cnt': 'cAccelEntries, ret'}), ('int', 'cAccelEntries', {})]],
[('int', 'CopyAcceleratorTableW'), [('HACCEL', 'hAccelSrc', {}), ('LPACCEL', 'lpAccelDst', {'IO': 'O', 'cnt': 'cAccelEntries, ret'}), ('int', 'cAccelEntries', {})]],
[('int', 'TranslateAcceleratorA'), [('HWND', 'hWnd', {}), ('HACCEL', 'hAccTable', {}), ('LPMSG', 'lpMsg', {})]],
[('int', 'TranslateAcceleratorW'), [('HWND', 'hWnd', {}), ('HACCEL', 'hAccTable', {}), ('LPMSG', 'lpMsg', {})]],
[('int', 'GetSystemMetrics'), [('int', 'nIndex', {})]],
[('HMENU', 'LoadMenuA'), [('HINSTANCE', 'hInstance', {}), ('LPCSTR', 'lpMenuName', {})]],
[('HMENU', 'LoadMenuW'), [('HINSTANCE', 'hInstance', {}), ('LPCWSTR', 'lpMenuName', {})]],
[('HMENU', 'LoadMenuIndirectA'), [('CONST MENUTEMPLATEA*', 'lpMenuTemplate', {})]],
[('HMENU', 'LoadMenuIndirectW'), [('CONST MENUTEMPLATEW*', 'lpMenuTemplate', {})]],
[('HMENU', 'GetMenu'), [('HWND', 'hWnd', {})]],
[('BOOL', 'SetMenu'), [('HWND', 'hWnd', {}), ('HMENU', 'hMenu', {})]],
[('BOOL', 'ChangeMenuA'), [('HMENU', 'hMenu', {}), ('UINT', 'cmd', {}), ('LPCSTR', 'lpszNewItem', {}), ('UINT', 'cmdInsert', {}), ('UINT', 'flags', {})]],
[('BOOL', 'ChangeMenuW'), [('HMENU', 'hMenu', {}), ('UINT', 'cmd', {}), ('LPCWSTR', 'lpszNewItem', {}), ('UINT', 'cmdInsert', {}), ('UINT', 'flags', {})]],
[('BOOL', 'HiliteMenuItem'), [('HWND', 'hWnd', {}), ('HMENU', 'hMenu', {}), ('UINT', 'uIDHiliteItem', {}), ('UINT', 'uHilite', {})]],
[('int', 'GetMenuStringA'), [('HMENU', 'hMenu', {}), ('UINT', 'uIDItem', {}), ('LPSTR', 'lpString', {'IO': 'O', 'cnt': 'cchMax'}), ('int', 'cchMax', {}), ('UINT', 'flags', {})]],
[('int', 'GetMenuStringW'), [('HMENU', 'hMenu', {}), ('UINT', 'uIDItem', {}), ('LPWSTR', 'lpString', {'IO': 'O', 'cnt': 'cchMax'}), ('int', 'cchMax', {}), ('UINT', 'flags', {})]],
[('UINT', 'GetMenuState'), [('HMENU', 'hMenu', {}), ('UINT', 'uId', {}), ('UINT', 'uFlags', {})]],
[('BOOL', 'DrawMenuBar'), [('HWND', 'hWnd', {})]],
[('HMENU', 'GetSystemMenu'), [('HWND', 'hWnd', {}), ('BOOL', 'bRevert', {})]],
[('HMENU', 'CreateMenu'), []],
[('HMENU', 'CreatePopupMenu'), []],
[('BOOL', 'DestroyMenu'), [('HMENU', 'hMenu', {})]],
[('DWORD', 'CheckMenuItem'), [('HMENU', 'hMenu', {}), ('UINT', 'uIDCheckItem', {}), ('UINT', 'uCheck', {})]],
[('BOOL', 'EnableMenuItem'), [('HMENU', 'hMenu', {}), ('UINT', 'uIDEnableItem', {}), ('UINT', 'uEnable', {})]],
[('HMENU', 'GetSubMenu'), [('HMENU', 'hMenu', {}), ('int', 'nPos', {})]],
[('UINT', 'GetMenuItemID'), [('HMENU', 'hMenu', {}), ('int', 'nPos', {})]],
[('int', 'GetMenuItemCount'), [('HMENU', 'hMenu', {})]],
[('BOOL', 'InsertMenuA'), [('HMENU', 'hMenu', {}), ('UINT', 'uPosition', {}), ('UINT', 'uFlags', {}), ('UINT_PTR', 'uIDNewItem', {}), ('LPCSTR', 'lpNewItem', {})]],
[('BOOL', 'InsertMenuW'), [('HMENU', 'hMenu', {}), ('UINT', 'uPosition', {}), ('UINT', 'uFlags', {}), ('UINT_PTR', 'uIDNewItem', {}), ('LPCWSTR', 'lpNewItem', {})]],
[('BOOL', 'AppendMenuA'), [('HMENU', 'hMenu', {}), ('UINT', 'uFlags', {}), ('UINT_PTR', 'uIDNewItem', {}), ('LPCSTR', 'lpNewItem', {})]],
[('BOOL', 'AppendMenuW'), [('HMENU', 'hMenu', {}), ('UINT', 'uFlags', {}), ('UINT_PTR', 'uIDNewItem', {}), ('LPCWSTR', 'lpNewItem', {})]],
[('BOOL', 'ModifyMenuA'), [('HMENU', 'hMnu', {}), ('UINT', 'uPosition', {}), ('UINT', 'uFlags', {}), ('UINT_PTR', 'uIDNewItem', {}), ('LPCSTR', 'lpNewItem', {})]],
[('BOOL', 'ModifyMenuW'), [('HMENU', 'hMnu', {}), ('UINT', 'uPosition', {}), ('UINT', 'uFlags', {}), ('UINT_PTR', 'uIDNewItem', {}), ('LPCWSTR', 'lpNewItem', {})]],
[('BOOL', 'RemoveMenu'), [('HMENU', 'hMenu', {}), ('UINT', 'uPosition', {}), ('UINT', 'uFlags', {})]],
[('BOOL', 'DeleteMenu'), [('HMENU', 'hMenu', {}), ('UINT', 'uPosition', {}), ('UINT', 'uFlags', {})]],
[('BOOL', 'SetMenuItemBitmaps'), [('HMENU', 'hMenu', {}), ('UINT', 'uPosition', {}), ('UINT', 'uFlags', {}), ('HBITMAP', 'hBitmapUnchecked', {}), ('HBITMAP', 'hBitmapChecked', {})]],
[('LONG', 'GetMenuCheckMarkDimensions'), []],
[('BOOL', 'TrackPopupMenu'), [('HMENU', 'hMenu', {}), ('UINT', 'uFlags', {}), ('int', 'x', {}), ('int', 'y', {}), ('int', 'nReserved', {}), ('HWND', 'hWnd', {}), ('CONST RECT*', 'prcRect', {})]],
[('BOOL', 'TrackPopupMenuEx'), [('HMENU', 'arg0', {}), ('UINT', 'arg1', {}), ('int', 'arg2', {}), ('int', 'arg3', {}), ('HWND', 'arg4', {}), ('LPTPMPARAMS', 'arg5', {})]],
[('BOOL', 'CalculatePopupWindowPosition'), [('CONST POINT*', 'anchorPoint', {}), ('CONST SIZE*', 'windowSize', {}), ('UINT', 'flags', {}), ('RECT*', 'excludeRect', {}), ('RECT*', 'popupWindowPosition', {'IO': 'O'})]],
[('BOOL', 'GetMenuInfo'), [('HMENU', 'arg0', {}), ('LPMENUINFO', 'arg1', {'IO': 'IO'})]],
[('BOOL', 'SetMenuInfo'), [('HMENU', 'arg0', {}), ('LPCMENUINFO', 'arg1', {})]],
[('BOOL', 'EndMenu'), []],
[('BOOL', 'InsertMenuItemA'), [('HMENU', 'hmenu', {}), ('UINT', 'item', {}), ('BOOL', 'fByPosition', {}), ('LPCMENUITEMINFOA', 'lpmi', {})]],
[('BOOL', 'InsertMenuItemW'), [('HMENU', 'hmenu', {}), ('UINT', 'item', {}), ('BOOL', 'fByPosition', {}), ('LPCMENUITEMINFOW', 'lpmi', {})]],
[('BOOL', 'GetMenuItemInfoA'), [('HMENU', 'hmenu', {}), ('UINT', 'item', {}), ('BOOL', 'fByPosition', {}), ('LPMENUITEMINFOA', 'lpmii', {'IO': 'IO'})]],
[('BOOL', 'GetMenuItemInfoW'), [('HMENU', 'hmenu', {}), ('UINT', 'item', {}), ('BOOL', 'fByPosition', {}), ('LPMENUITEMINFOW', 'lpmii', {'IO': 'IO'})]],
[('BOOL', 'SetMenuItemInfoA'), [('HMENU', 'hmenu', {}), ('UINT', 'item', {}), ('BOOL', 'fByPositon', {}), ('LPCMENUITEMINFOA', 'lpmii', {})]],
[('BOOL', 'SetMenuItemInfoW'), [('HMENU', 'hmenu', {}), ('UINT', 'item', {}), ('BOOL', 'fByPositon', {}), ('LPCMENUITEMINFOW', 'lpmii', {})]],
[('UINT', 'GetMenuDefaultItem'), [('HMENU', 'hMenu', {}), ('UINT', 'fByPos', {}), ('UINT', 'gmdiFlags', {})]],
[('BOOL', 'SetMenuDefaultItem'), [('HMENU', 'hMenu', {}), ('UINT', 'uItem', {}), ('UINT', 'fByPos', {})]],
[('BOOL', 'GetMenuItemRect'), [('HWND', 'hWnd', {}), ('HMENU', 'hMenu', {}), ('UINT', 'uItem', {}), ('LPRECT', 'lprcItem', {'IO': 'O'})]],
[('int', 'MenuItemFromPoint'), [('HWND', 'hWnd', {}), ('HMENU', 'hMenu', {}), ('POINT', 'ptScreen', {})]],
[('DWORD', 'DragObject'), [('HWND', 'hwndParent', {}), ('HWND', 'hwndFrom', {}), ('UINT', 'fmt', {}), ('ULONG_PTR', 'data', {}), ('HCURSOR', 'hcur', {})]],
[('BOOL', 'DragDetect'), [('HWND', 'hwnd', {}), ('POINT', 'pt', {})]],
[('BOOL', 'DrawIcon'), [('HDC', 'hDC', {}), ('int', 'X', {}), ('int', 'Y', {}), ('HICON', 'hIcon', {})]],
[('int', 'DrawTextA'), [('HDC', 'hdc', {}), ('LPCSTR', 'lpchText', {'IO': 'IO', 'cnt': 'cchText'}), ('int', 'cchText', {}), ('LPRECT', 'lprc', {'IO': 'IO'}), ('UINT', 'format', {})]],
[('int', 'DrawTextW'), [('HDC', 'hdc', {}), ('LPCWSTR', 'lpchText', {'IO': 'IO', 'cnt': 'cchText'}), ('int', 'cchText', {}), ('LPRECT', 'lprc', {'IO': 'IO'}), ('UINT', 'format', {})]],
[('int', 'DrawTextExA'), [('HDC', 'hdc', {}), ('LPSTR', 'lpchText', {'IO': 'IO', 'cnt': 'cchText'}), ('int', 'cchText', {}), ('LPRECT', 'lprc', {'IO': 'IO'}), ('UINT', 'format', {}), ('LPDRAWTEXTPARAMS', 'lpdtp', {})]],
[('int', 'DrawTextExW'), [('HDC', 'hdc', {}), ('LPWSTR', 'lpchText', {'IO': 'IO', 'cnt': 'cchText'}), ('int', 'cchText', {}), ('LPRECT', 'lprc', {'IO': 'IO'}), ('UINT', 'format', {}), ('LPDRAWTEXTPARAMS', 'lpdtp', {})]],
[('BOOL', 'GrayStringA'), [('HDC', 'hDC', {}), ('HBRUSH', 'hBrush', {}), ('GRAYSTRINGPROC', 'lpOutputFunc', {}), ('LPARAM', 'lpData', {}), ('int', 'nCount', {}), ('int', 'X', {}), ('int', 'Y', {}), ('int', 'nWidth', {}), ('int', 'nHeight', {})]],
[('BOOL', 'GrayStringW'), [('HDC', 'hDC', {}), ('HBRUSH', 'hBrush', {}), ('GRAYSTRINGPROC', 'lpOutputFunc', {}), ('LPARAM', 'lpData', {}), ('int', 'nCount', {}), ('int', 'X', {}), ('int', 'Y', {}), ('int', 'nWidth', {}), ('int', 'nHeight', {})]],
[('BOOL', 'DrawStateA'), [('HDC', 'hdc', {}), ('HBRUSH', 'hbrFore', {}), ('DRAWSTATEPROC', 'qfnCallBack', {}), ('LPARAM', 'lData', {}), ('WPARAM', 'wData', {}), ('int', 'x', {}), ('int', 'y', {}), ('int', 'cx', {}), ('int', 'cy', {}), ('UINT', 'uFlags', {})]],
[('BOOL', 'DrawStateW'), [('HDC', 'hdc', {}), ('HBRUSH', 'hbrFore', {}), ('DRAWSTATEPROC', 'qfnCallBack', {}), ('LPARAM', 'lData', {}), ('WPARAM', 'wData', {}), ('int', 'x', {}), ('int', 'y', {}), ('int', 'cx', {}), ('int', 'cy', {}), ('UINT', 'uFlags', {})]],
[('LONG', 'TabbedTextOutA'), [('HDC', 'hdc', {}), ('int', 'x', {}), ('int', 'y', {}), ('LPCSTR', 'lpString', {'cnt': 'chCount'}), ('int', 'chCount', {}), ('int', 'nTabPositions', {}), ('CONST INT*', 'lpnTabStopPositions', {'cnt': 'nTabPositions'}), ('int', 'nTabOrigin', {})]],
[('LONG', 'TabbedTextOutW'), [('HDC', 'hdc', {}), ('int', 'x', {}), ('int', 'y', {}), ('LPCWSTR', 'lpString', {'cnt': 'chCount'}), ('int', 'chCount', {}), ('int', 'nTabPositions', {}), ('CONST INT*', 'lpnTabStopPositions', {'cnt': 'nTabPositions'}), ('int', 'nTabOrigin', {})]],
[('DWORD', 'GetTabbedTextExtentA'), [('HDC', 'hdc', {}), ('LPCSTR', 'lpString', {'cnt': 'chCount'}), ('int', 'chCount', {}), ('int', 'nTabPositions', {}), ('CONST INT*', 'lpnTabStopPositions', {'cnt': 'nTabPositions'})]],
[('DWORD', 'GetTabbedTextExtentW'), [('HDC', 'hdc', {}), ('LPCWSTR', 'lpString', {'cnt': 'chCount'}), ('int', 'chCount', {}), ('int', 'nTabPositions', {}), ('CONST INT*', 'lpnTabStopPositions', {'cnt': 'nTabPositions'})]],
[('BOOL', 'UpdateWindow'), [('HWND', 'hWnd', {})]],
[('HWND', 'SetActiveWindow'), [('HWND', 'hWnd', {})]],
[('HWND', 'GetForegroundWindow'), []],
[('BOOL', 'PaintDesktop'), [('HDC', 'hdc', {})]],
[('VOID', 'SwitchToThisWindow'), [('HWND', 'hwnd', {}), ('BOOL', 'fUnknown', {})]],
[('BOOL', 'SetForegroundWindow'), [('HWND', 'hWnd', {})]],
[('BOOL', 'AllowSetForegroundWindow'), [('DWORD', 'dwProcessId', {})]],
[('BOOL', 'LockSetForegroundWindow'), [('UINT', 'uLockCode', {})]],
[('HWND', 'WindowFromDC'), [('HDC', 'hDC', {})]],
[('HDC', 'GetDC'), [('HWND', 'hWnd', {})]],
[('HDC', 'GetDCEx'), [('HWND', 'hWnd', {}), ('HRGN', 'hrgnClip', {}), ('DWORD', 'flags', {})]],
[('HDC', 'GetWindowDC'), [('HWND', 'hWnd', {})]],
[('int', 'ReleaseDC'), [('HWND', 'hWnd', {}), ('HDC', 'hDC', {})]],
[('HDC', 'BeginPaint'), [('HWND', 'hWnd', {}), ('LPPAINTSTRUCT', 'lpPaint', {'IO': 'O'})]],
[('BOOL', 'EndPaint'), [('HWND', 'hWnd', {}), ('CONST PAINTSTRUCT*', 'lpPaint', {})]],
[('BOOL', 'GetUpdateRect'), [('HWND', 'hWnd', {}), ('LPRECT', 'lpRect', {'IO': 'O'}), ('BOOL', 'bErase', {})]],
[('int', 'GetUpdateRgn'), [('HWND', 'hWnd', {}), ('HRGN', 'hRgn', {}), ('BOOL', 'bErase', {})]],
[('int', 'SetWindowRgn'), [('HWND', 'hWnd', {}), ('HRGN', 'hRgn', {}), ('BOOL', 'bRedraw', {})]],
[('int', 'GetWindowRgn'), [('HWND', 'hWnd', {}), ('HRGN', 'hRgn', {})]],
[('int', 'GetWindowRgnBox'), [('HWND', 'hWnd', {}), ('LPRECT', 'lprc', {'IO': 'O'})]],
[('int', 'ExcludeUpdateRgn'), [('HDC', 'hDC', {}), ('HWND', 'hWnd', {})]],
[('BOOL', 'InvalidateRect'), [('HWND', 'hWnd', {}), ('CONST RECT*', 'lpRect', {}), ('BOOL', 'bErase', {})]],
[('BOOL', 'ValidateRect'), [('HWND', 'hWnd', {}), ('CONST RECT*', 'lpRect', {})]],
[('BOOL', 'InvalidateRgn'), [('HWND', 'hWnd', {}), ('HRGN', 'hRgn', {}), ('BOOL', 'bErase', {})]],
[('BOOL', 'ValidateRgn'), [('HWND', 'hWnd', {}), ('HRGN', 'hRgn', {})]],
[('BOOL', 'RedrawWindow'), [('HWND', 'hWnd', {}), ('CONST RECT*', 'lprcUpdate', {}), ('HRGN', 'hrgnUpdate', {}), ('UINT', 'flags', {})]],
[('BOOL', 'LockWindowUpdate'), [('HWND', 'hWndLock', {})]],
[('BOOL', 'ScrollWindow'), [('HWND', 'hWnd', {}), ('int', 'XAmount', {}), ('int', 'YAmount', {}), ('CONST RECT*', 'lpRect', {}), ('CONST RECT*', 'lpClipRect', {})]],
[('BOOL', 'ScrollDC'), [('HDC', 'hDC', {}), ('int', 'dx', {}), ('int', 'dy', {}), ('CONST RECT*', 'lprcScroll', {}), ('CONST RECT*', 'lprcClip', {}), ('HRGN', 'hrgnUpdate', {}), ('LPRECT', 'lprcUpdate', {'IO': 'O'})]],
[('int', 'ScrollWindowEx'), [('HWND', 'hWnd', {}), ('int', 'dx', {}), ('int', 'dy', {}), ('CONST RECT*', 'prcScroll', {}), ('CONST RECT*', 'prcClip', {}), ('HRGN', 'hrgnUpdate', {}), ('LPRECT', 'prcUpdate', {'IO': 'O'}), ('UINT', 'flags', {})]],
[('int', 'SetScrollPos'), [('HWND', 'hWnd', {}), ('int', 'nBar', {}), ('int', 'nPos', {}), ('BOOL', 'bRedraw', {})]],
[('int', 'GetScrollPos'), [('HWND', 'hWnd', {}), ('int', 'nBar', {})]],
[('BOOL', 'SetScrollRange'), [('HWND', 'hWnd', {}), ('int', 'nBar', {}), ('int', 'nMinPos', {}), ('int', 'nMaxPos', {}), ('BOOL', 'bRedraw', {})]],
[('BOOL', 'GetScrollRange'), [('HWND', 'hWnd', {}), ('int', 'nBar', {}), ('LPINT', 'lpMinPos', {'IO': 'O'}), ('LPINT', 'lpMaxPos', {'IO': 'O'})]],
[('BOOL', 'ShowScrollBar'), [('HWND', 'hWnd', {}), ('int', 'wBar', {}), ('BOOL', 'bShow', {})]],
[('BOOL', 'EnableScrollBar'), [('HWND', 'hWnd', {}), ('UINT', 'wSBflags', {}), ('UINT', 'wArrows', {})]],
[('BOOL', 'SetPropA'), [('HWND', 'hWnd', {}), ('LPCSTR', 'lpString', {}), ('HANDLE', 'hData', {})]],
[('BOOL', 'SetPropW'), [('HWND', 'hWnd', {}), ('LPCWSTR', 'lpString', {}), ('HANDLE', 'hData', {})]],
[('HANDLE', 'GetPropA'), [('HWND', 'hWnd', {}), ('LPCSTR', 'lpString', {})]],
[('HANDLE', 'GetPropW'), [('HWND', 'hWnd', {}), ('LPCWSTR', 'lpString', {})]],
[('HANDLE', 'RemovePropA'), [('HWND', 'hWnd', {}), ('LPCSTR', 'lpString', {})]],
[('HANDLE', 'RemovePropW'), [('HWND', 'hWnd', {}), ('LPCWSTR', 'lpString', {})]],
[('int', 'EnumPropsExA'), [('HWND', 'hWnd', {}), ('PROPENUMPROCEXA', 'lpEnumFunc', {}), ('LPARAM', 'lParam', {})]],
[('int', 'EnumPropsExW'), [('HWND', 'hWnd', {}), ('PROPENUMPROCEXW', 'lpEnumFunc', {}), ('LPARAM', 'lParam', {})]],
[('int', 'EnumPropsA'), [('HWND', 'hWnd', {}), ('PROPENUMPROCA', 'lpEnumFunc', {})]],
[('int', 'EnumPropsW'), [('HWND', 'hWnd', {}), ('PROPENUMPROCW', 'lpEnumFunc', {})]],
[('BOOL', 'SetWindowTextA'), [('HWND', 'hWnd', {}), ('LPCSTR', 'lpString', {})]],
[('BOOL', 'SetWindowTextW'), [('HWND', 'hWnd', {}), ('LPCWSTR', 'lpString', {})]],
[('int', 'GetWindowTextA'), [('HWND', 'hWnd', {}), ('LPSTR', 'lpString', {'IO': 'O', 'cnt': 'nMaxCount'}), ('int', 'nMaxCount', {})]],
[('int', 'GetWindowTextW'), [('HWND', 'hWnd', {}), ('LPWSTR', 'lpString', {'IO': 'O', 'cnt': 'nMaxCount'}), ('int', 'nMaxCount', {})]],
[('int', 'GetWindowTextLengthA'), [('HWND', 'hWnd', {})]],
[('int', 'GetWindowTextLengthW'), [('HWND', 'hWnd', {})]],
[('BOOL', 'GetClientRect'), [('HWND', 'hWnd', {}), ('LPRECT', 'lpRect', {'IO': 'O'})]],
[('BOOL', 'GetWindowRect'), [('HWND', 'hWnd', {}), ('LPRECT', 'lpRect', {'IO': 'O'})]],
[('BOOL', 'AdjustWindowRect'), [('LPRECT', 'lpRect', {'IO': 'IO'}), ('DWORD', 'dwStyle', {}), ('BOOL', 'bMenu', {})]],
[('BOOL', 'AdjustWindowRectEx'), [('LPRECT', 'lpRect', {'IO': 'IO'}), ('DWORD', 'dwStyle', {}), ('BOOL', 'bMenu', {}), ('DWORD', 'dwExStyle', {})]],
[('BOOL', 'SetWindowContextHelpId'), [('HWND', 'arg0', {}), ('DWORD', 'arg1', {})]],
[('DWORD', 'GetWindowContextHelpId'), [('HWND', 'arg0', {})]],
[('BOOL', 'SetMenuContextHelpId'), [('HMENU', 'arg0', {}), ('DWORD', 'arg1', {})]],
[('DWORD', 'GetMenuContextHelpId'), [('HMENU', 'arg0', {})]],
[('int', 'MessageBoxA'), [('HWND', 'hWnd', {}), ('LPCSTR', 'lpText', {}), ('LPCSTR', 'lpCaption', {}), ('UINT', 'uType', {})]],
[('int', 'MessageBoxW'), [('HWND', 'hWnd', {}), ('LPCWSTR', 'lpText', {}), ('LPCWSTR', 'lpCaption', {}), ('UINT', 'uType', {})]],
[('int', 'MessageBoxExA'), [('HWND', 'hWnd', {}), ('LPCSTR', 'lpText', {}), ('LPCSTR', 'lpCaption', {}), ('UINT', 'uType', {}), ('WORD', 'wLanguageId', {})]],
[('int', 'MessageBoxExW'), [('HWND', 'hWnd', {}), ('LPCWSTR', 'lpText', {}), ('LPCWSTR', 'lpCaption', {}), ('UINT', 'uType', {}), ('WORD', 'wLanguageId', {})]],
[('int', 'MessageBoxIndirectA'), [('CONST MSGBOXPARAMSA*', ' lpmbp', {})]],
[('int', 'MessageBoxIndirectW'), [('CONST MSGBOXPARAMSW*', ' lpmbp', {})]],
[('BOOL', 'MessageBeep'), [('UINT', 'uType', {})]],
[('int', 'ShowCursor'), [('BOOL', 'bShow', {})]],
[('BOOL', 'SetCursorPos'), [('int', 'X', {}), ('int', 'Y', {})]],
[('BOOL', 'SetPhysicalCursorPos'), [('int', 'X', {}), ('int', 'Y', {})]],
[('HCURSOR', 'SetCursor'), [('HCURSOR', 'hCursor', {})]],
[('BOOL', 'GetCursorPos'), [('LPPOINT', 'lpPoint', {'IO': 'O'})]],
[('BOOL', 'GetPhysicalCursorPos'), [('LPPOINT', 'lpPoint', {'IO': 'O'})]],
[('BOOL', 'ClipCursor'), [('CONST RECT*', 'lpRect', {})]],
[('BOOL', 'GetClipCursor'), [('LPRECT', 'lpRect', {'IO': 'O'})]],
[('HCURSOR', 'GetCursor'), []],
[('BOOL', 'CreateCaret'), [('HWND', 'hWnd', {}), ('HBITMAP', 'hBitmap', {}), ('int', 'nWidth', {}), ('int', 'nHeight', {})]],
[('UINT', 'GetCaretBlinkTime'), []],
[('BOOL', 'SetCaretBlinkTime'), [('UINT', 'uMSeconds', {})]],
[('BOOL', 'DestroyCaret'), []],
[('BOOL', 'HideCaret'), [('HWND', 'hWnd', {})]],
[('BOOL', 'ShowCaret'), [('HWND', 'hWnd', {})]],
[('BOOL', 'SetCaretPos'), [('int', 'X', {}), ('int', 'Y', {})]],
[('BOOL', 'GetCaretPos'), [('LPPOINT', 'lpPoint', {'IO': 'O'})]],
[('BOOL', 'ClientToScreen'), [('HWND', 'hWnd', {}), ('LPPOINT', 'lpPoint', {'IO': 'IO'})]],
[('BOOL', 'ScreenToClient'), [('HWND', 'hWnd', {}), ('LPPOINT', 'lpPoint', {'IO': 'IO'})]],
[('BOOL', 'LogicalToPhysicalPoint'), [('HWND', 'hWnd', {}), ('LPPOINT', 'lpPoint', {'IO': 'IO'})]],
[('BOOL', 'PhysicalToLogicalPoint'), [('HWND', 'hWnd', {}), ('LPPOINT', 'lpPoint', {'IO': 'IO'})]],
[('int', 'MapWindowPoints'), [('HWND', 'hWndFrom', {}), ('HWND', 'hWndTo', {}), ('LPPOINT', 'lpPoints', {'IO': 'IO', 'cnt': 'cPoints'}), ('UINT', 'cPoints', {})]],
[('HWND', 'WindowFromPoint'), [('POINT', 'Point', {})]],
[('HWND', 'WindowFromPhysicalPoint'), [('POINT', 'Point', {})]],
[('HWND', 'ChildWindowFromPoint'), [('HWND', 'hWndParent', {}), ('POINT', 'Point', {})]],
[('HWND', 'ChildWindowFromPointEx'), [('HWND', 'hwnd', {}), ('POINT', 'pt', {}), ('UINT', 'flags', {})]],
[('DWORD', 'GetSysColor'), [('int', 'nIndex', {})]],
[('HBRUSH', 'GetSysColorBrush'), [('int', 'nIndex', {})]],
[('BOOL', 'SetSysColors'), [('int', 'cElements', {}), ('CONST INT*', ' lpaElements', {'cnt': 'cElements'}), ('CONST COLORREF*', ' lpaRgbValues', {'cnt': 'cElements'})]],
[('BOOL', 'DrawFocusRect'), [('HDC', 'hDC', {}), ('CONST RECT*', ' lprc', {})]],
[('int', 'FillRect'), [('HDC', 'hDC', {}), ('CONST RECT*', 'lprc', {}), ('HBRUSH', 'hbr', {})]],
[('int', 'FrameRect'), [('HDC', 'hDC', {}), ('CONST RECT*', 'lprc', {}), ('HBRUSH', 'hbr', {})]],
[('BOOL', 'InvertRect'), [('HDC', 'hDC', {}), ('CONST RECT*', 'lprc', {})]],
[('BOOL', 'SetRect'), [('LPRECT', 'lprc', {'IO': 'O'}), ('int', 'xLeft', {}), ('int', 'yTop', {}), ('int', 'xRight', {}), ('int', 'yBottom', {})]],
[('BOOL', 'SetRectEmpty'), [('LPRECT', 'lprc', {'IO': 'O'})]],
[('BOOL', 'CopyRect'), [('LPRECT', 'lprcDst', {'IO': 'O'}), ('CONST RECT*', 'lprcSrc', {})]],
[('BOOL', 'InflateRect'), [('LPRECT', 'lprc', {'IO': 'IO'}), ('int', 'dx', {}), ('int', 'dy', {})]],
[('BOOL', 'IntersectRect'), [('LPRECT', 'lprcDst', {'IO': 'O'}), ('CONST RECT*', 'lprcSrc1', {}), ('CONST RECT*', 'lprcSrc2', {})]],
[('BOOL', 'UnionRect'), [('LPRECT', 'lprcDst', {'IO': 'O'}), ('CONST RECT*', 'lprcSrc1', {}), ('CONST RECT*', 'lprcSrc2', {})]],
[('BOOL', 'SubtractRect'), [('LPRECT', 'lprcDst', {'IO': 'O'}), ('CONST RECT*', 'lprcSrc1', {}), ('CONST RECT*', 'lprcSrc2', {})]],
[('BOOL', 'OffsetRect'), [('LPRECT', 'lprc', {'IO': 'IO'}), ('int', 'dx', {}), ('int', 'dy', {})]],
[('BOOL', 'IsRectEmpty'), [('CONST RECT*', 'lprc', {})]],
[('BOOL', 'EqualRect'), [('CONST RECT*', 'lprc1', {}), ('CONST RECT*', 'lprc2', {})]],
[('BOOL', 'PtInRect'), [('CONST RECT*', 'lprc', {}), ('POINT', 'pt', {})]],
[('WORD', 'GetWindowWord'), [('HWND', 'hWnd', {}), ('int', 'nIndex', {})]],
[('WORD', 'SetWindowWord'), [('HWND', 'hWnd', {}), ('int', 'nIndex', {}), ('WORD', 'wNewWord', {})]],
[('LONG', 'GetWindowLongA'), [('HWND', 'hWnd', {}), ('int', 'nIndex', {})]],
[('LONG', 'GetWindowLongW'), [('HWND', 'hWnd', {}), ('int', 'nIndex', {})]],
[('LONG', 'SetWindowLongA'), [('HWND', 'hWnd', {}), ('int', 'nIndex', {}), ('LONG', 'dwNewLong', {})]],
[('LONG', 'SetWindowLongW'), [('HWND', 'hWnd', {}), ('int', 'nIndex', {}), ('LONG', 'dwNewLong', {})]],
[('LONG_PTR', 'GetWindowLongPtrA'), [('HWND', 'hWnd', {}), ('int', 'nIndex', {})]],
[('LONG_PTR', 'GetWindowLongPtrW'), [('HWND', 'hWnd', {}), ('int', 'nIndex', {})]],
[('LONG_PTR', 'SetWindowLongPtrA'), [('HWND', 'hWnd', {}), ('int', 'nIndex', {}), ('LONG_PTR', 'dwNewLong', {})]],
[('LONG_PTR', 'SetWindowLongPtrW'), [('HWND', 'hWnd', {}), ('int', 'nIndex', {}), ('LONG_PTR', 'dwNewLong', {})]],
[('WORD', 'GetClassWord'), [('HWND', 'hWnd', {}), ('int', 'nIndex', {})]],
[('WORD', 'SetClassWord'), [('HWND', 'hWnd', {}), ('int', 'nIndex', {}), ('WORD', 'wNewWord', {})]],
[('DWORD', 'GetClassLongA'), [('HWND', 'hWnd', {}), ('int', 'nIndex', {})]],
[('DWORD', 'GetClassLongW'), [('HWND', 'hWnd', {}), ('int', 'nIndex', {})]],
[('DWORD', 'SetClassLongA'), [('HWND', 'hWnd', {}), ('int', 'nIndex', {}), ('LONG', 'dwNewLong', {})]],
[('DWORD', 'SetClassLongW'), [('HWND', 'hWnd', {}), ('int', 'nIndex', {}), ('LONG', 'dwNewLong', {})]],
[('ULONG_PTR', 'GetClassLongPtrA'), [('HWND', 'hWnd', {}), ('int', 'nIndex', {})]],
[('ULONG_PTR', 'GetClassLongPtrW'), [('HWND', 'hWnd', {}), ('int', 'nIndex', {})]],
[('ULONG_PTR', 'SetClassLongPtrA'), [('HWND', 'hWnd', {}), ('int', 'nIndex', {}), ('LONG_PTR', 'dwNewLong', {})]],
[('ULONG_PTR', 'SetClassLongPtrW'), [('HWND', 'hWnd', {}), ('int', 'nIndex', {}), ('LONG_PTR', 'dwNewLong', {})]],
[('BOOL', 'GetProcessDefaultLayout'), [('DWORD*', 'pdwDefaultLayout', {'IO': 'O'})]],
[('BOOL', 'SetProcessDefaultLayout'), [('DWORD', 'dwDefaultLayout', {})]],
[('HWND', 'GetDesktopWindow'), []],
[('HWND', 'GetParent'), [('HWND', 'hWnd', {})]],
[('HWND', 'SetParent'), [('HWND', 'hWndChild', {}), ('HWND', 'hWndNewParent', {})]],
[('BOOL', 'EnumChildWindows'), [('HWND', 'hWndParent', {}), ('WNDENUMPROC', 'lpEnumFunc', {}), ('LPARAM', 'lParam', {})]],
[('HWND', 'FindWindowA'), [('LPCSTR', 'lpClassName', {}), ('LPCSTR', 'lpWindowName', {})]],
[('HWND', 'FindWindowW'), [('LPCWSTR', 'lpClassName', {}), ('LPCWSTR', 'lpWindowName', {})]],
[('HWND', 'FindWindowExA'), [('HWND', 'hWndParent', {}), ('HWND', 'hWndChildAfter', {}), ('LPCSTR', 'lpszClass', {}), ('LPCSTR', 'lpszWindow', {})]],
[('HWND', 'FindWindowExW'), [('HWND', 'hWndParent', {}), ('HWND', 'hWndChildAfter', {}), ('LPCWSTR', 'lpszClass', {}), ('LPCWSTR', 'lpszWindow', {})]],
[('HWND', 'GetShellWindow'), []],
[('BOOL', 'RegisterShellHookWindow'), [('HWND', 'hwnd', {})]],
[('BOOL', 'DeregisterShellHookWindow'), [('HWND', 'hwnd', {})]],
[('BOOL', 'EnumWindows'), [('WNDENUMPROC', 'lpEnumFunc', {}), ('LPARAM', 'lParam', {})]],
[('BOOL', 'EnumThreadWindows'), [('DWORD', 'dwThreadId', {}), ('WNDENUMPROC', 'lpfn', {}), ('LPARAM', 'lParam', {})]],
[('int', 'GetClassNameA'), [('HWND', 'hWnd', {}), ('LPSTR', 'lpClassName', {'IO': 'O', 'cnt': 'nMaxCount, ret'}), ('int', 'nMaxCount', {})]],
[('int', 'GetClassNameW'), [('HWND', 'hWnd', {}), ('LPWSTR', 'lpClassName', {'IO': 'O', 'cnt': 'nMaxCount, ret'}), ('int', 'nMaxCount', {})]],
[('HWND', 'GetTopWindow'), [('HWND', 'hWnd', {})]],
[('DWORD', 'GetWindowThreadProcessId'), [('HWND', 'hWnd', {}), ('LPDWORD', 'lpdwProcessId', {'IO': 'O'})]],
[('BOOL', 'IsGUIThread'), [('BOOL', 'bConvert', {})]],
[('HWND', 'GetLastActivePopup'), [('HWND', 'hWnd', {})]],
[('HWND', 'GetWindow'), [('HWND', 'hWnd', {}), ('UINT', 'uCmd', {})]],
[('HHOOK', 'SetWindowsHookA'), [('int', 'nFilterType', {}), ('HOOKPROC', 'pfnFilterProc', {})]],
[('HHOOK', 'SetWindowsHookW'), [('int', 'nFilterType', {}), ('HOOKPROC', 'pfnFilterProc', {})]],
[('BOOL', 'UnhookWindowsHook'), [('int', 'nCode', {}), ('HOOKPROC', 'pfnFilterProc', {})]],
[('HHOOK', 'SetWindowsHookExA'), [('int', 'idHook', {}), ('HOOKPROC', 'lpfn', {}), ('HINSTANCE', 'hmod', {}), ('DWORD', 'dwThreadId', {})]],
[('HHOOK', 'SetWindowsHookExW'), [('int', 'idHook', {}), ('HOOKPROC', 'lpfn', {}), ('HINSTANCE', 'hmod', {}), ('DWORD', 'dwThreadId', {})]],
[('BOOL', 'UnhookWindowsHookEx'), [('HHOOK', 'hhk', {})]],
[('LRESULT', 'CallNextHookEx'), [('HHOOK', 'hhk', {}), ('int', 'nCode', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('BOOL', 'CheckMenuRadioItem'), [('HMENU', 'hmenu', {}), ('UINT', 'first', {}), ('UINT', 'last', {}), ('UINT', 'check', {}), ('UINT', 'flags', {})]],
[('HBITMAP', 'LoadBitmapA'), [('HINSTANCE', 'hInstance', {}), ('LPCSTR', 'lpBitmapName', {})]],
[('HBITMAP', 'LoadBitmapW'), [('HINSTANCE', 'hInstance', {}), ('LPCWSTR', 'lpBitmapName', {})]],
[('HCURSOR', 'LoadCursorA'), [('HINSTANCE', 'hInstance', {}), ('LPCSTR', 'lpCursorName', {})]],
[('HCURSOR', 'LoadCursorW'), [('HINSTANCE', 'hInstance', {}), ('LPCWSTR', 'lpCursorName', {})]],
[('HCURSOR', 'LoadCursorFromFileA'), [('LPCSTR', 'lpFileName', {})]],
[('HCURSOR', 'LoadCursorFromFileW'), [('LPCWSTR', 'lpFileName', {})]],
[('HCURSOR', 'CreateCursor'), [('HINSTANCE', 'hInst', {}), ('int', 'xHotSpot', {}), ('int', 'yHotSpot', {}), ('int', 'nWidth', {}), ('int', 'nHeight', {}), ('CONST VOID*', 'pvANDPlane', {}), ('CONST VOID*', 'pvXORPlane', {})]],
[('BOOL', 'DestroyCursor'), [('HCURSOR', 'hCursor', {})]],
[('BOOL', 'SetSystemCursor'), [('HCURSOR', 'hcur', {}), ('DWORD', 'id', {})]],
[('HICON', 'LoadIconA'), [('HINSTANCE', 'hInstance', {}), ('LPCSTR', 'lpIconName', {})]],
[('HICON', 'LoadIconW'), [('HINSTANCE', 'hInstance', {}), ('LPCWSTR', 'lpIconName', {})]],
[('UINT', 'PrivateExtractIconsA'), [('LPCSTR', 'szFileName', {}), ('int', 'nIconIndex', {}), ('int', 'cxIcon', {}), ('int', 'cyIcon', {}), ('HICON*', 'phicon', {'IO': 'O', 'cnt': 'nIcons, ret'}), ('UINT*', 'piconid', {'IO': 'O', 'cnt': 'nIcons, ret'}), ('UINT', 'nIcons', {}), ('UINT', 'flags', {})]],
[('UINT', 'PrivateExtractIconsW'), [('LPCWSTR', 'szFileName', {}), ('int', 'nIconIndex', {}), ('int', 'cxIcon', {}), ('int', 'cyIcon', {}), ('HICON*', 'phicon', {'IO': 'O', 'cnt': 'nIcons, ret'}), ('UINT*', 'piconid', {'IO': 'O', 'cnt': 'nIcons, ret'}), ('UINT', 'nIcons', {}), ('UINT', 'flags', {})]],
[('HICON', 'CreateIcon'), [('HINSTANCE', 'hInstance', {}), ('int', 'nWidth', {}), ('int', 'nHeight', {}), ('BYTE', 'cPlanes', {}), ('BYTE', 'cBitsPixel', {}), ('CONST BYTE*', 'lpbANDbits', {}), ('CONST BYTE*', 'lpbXORbits', {})]],
[('BOOL', 'DestroyIcon'), [('HICON', 'hIcon', {})]],
[('int', 'LookupIconIdFromDirectory'), [('PBYTE', 'presbits', {}), ('BOOL', 'fIcon', {})]],
[('int', 'LookupIconIdFromDirectoryEx'), [('PBYTE', 'presbits', {}), ('BOOL', 'fIcon', {}), ('int', 'cxDesired', {}), ('int', 'cyDesired', {}), ('UINT', 'Flags', {})]],
[('HICON', 'CreateIconFromResource'), [('PBYTE', 'presbits', {}), ('DWORD', 'dwResSize', {}), ('BOOL', 'fIcon', {}), ('DWORD', 'dwVer', {})]],
[('HICON', 'CreateIconFromResourceEx'), [('PBYTE', 'presbits', {}), ('DWORD', 'dwResSize', {}), ('BOOL', 'fIcon', {}), ('DWORD', 'dwVer', {}), ('int', 'cxDesired', {}), ('int', 'cyDesired', {}), ('UINT', 'Flags', {})]],
[('HANDLE', 'LoadImageA'), [('HINSTANCE', 'hInst', {}), ('LPCSTR', 'name', {}), ('UINT', 'type', {}), ('int', 'cx', {}), ('int', 'cy', {}), ('UINT', 'fuLoad', {})]],
[('HANDLE', 'LoadImageW'), [('HINSTANCE', 'hInst', {}), ('LPCWSTR', 'name', {}), ('UINT', 'type', {}), ('int', 'cx', {}), ('int', 'cy', {}), ('UINT', 'fuLoad', {})]],
[('HANDLE', 'CopyImage'), [('HANDLE', 'h', {}), ('UINT', 'type', {}), ('int', 'cx', {}), ('int', 'cy', {}), ('UINT', 'flags', {})]],
[('HICON', 'CreateIconIndirect'), [('PICONINFO', 'piconinfo', {})]],
[('HICON', 'CopyIcon'), [('HICON', 'hIcon', {})]],
[('BOOL', 'GetIconInfo'), [('HICON', 'hIcon', {}), ('PICONINFO', 'piconinfo', {'IO': 'O'})]],
[('BOOL', 'GetIconInfoExA'), [('HICON', 'hicon', {}), ('PICONINFOEXA', 'piconinfo', {'IO': 'IO'})]],
[('BOOL', 'GetIconInfoExW'), [('HICON', 'hicon', {}), ('PICONINFOEXW', 'piconinfo', {'IO': 'IO'})]],
[('int', 'LoadStringA'), [('HINSTANCE', 'hInstance', {}), ('UINT', 'uID', {}), ('LPSTR', 'lpBuffer', {'IO': 'O', 'cnt': 'cchBufferMax, ret + 1'}), ('int', 'cchBufferMax', {})]],
[('int', 'LoadStringW'), [('HINSTANCE', 'hInstance', {}), ('UINT', 'uID', {}), ('LPWSTR', 'lpBuffer', {'IO': 'O', 'cnt': 'cchBufferMax, ret + 1'}), ('int', 'cchBufferMax', {})]],
[('BOOL', 'IsDialogMessageA'), [('HWND', 'hDlg', {}), ('LPMSG', 'lpMsg', {})]],
[('BOOL', 'IsDialogMessageW'), [('HWND', 'hDlg', {}), ('LPMSG', 'lpMsg', {})]],
[('BOOL', 'MapDialogRect'), [('HWND', 'hDlg', {}), ('LPRECT', 'lpRect', {'IO': 'IO'})]],
[('int', 'DlgDirListA'), [('HWND', 'hDlg', {}), ('LPSTR', 'lpPathSpec', {'IO': 'IO'}), ('int', 'nIDListBox', {}), ('int', 'nIDStaticPath', {}), ('UINT', 'uFileType', {})]],
[('int', 'DlgDirListW'), [('HWND', 'hDlg', {}), ('LPWSTR', 'lpPathSpec', {'IO': 'IO'}), ('int', 'nIDListBox', {}), ('int', 'nIDStaticPath', {}), ('UINT', 'uFileType', {})]],
[('BOOL', 'DlgDirSelectExA'), [('HWND', 'hwndDlg', {}), ('LPSTR', 'lpString', {'IO': 'O', 'cnt': 'chCount'}), ('int', 'chCount', {}), ('int', 'idListBox', {})]],
[('BOOL', 'DlgDirSelectExW'), [('HWND', 'hwndDlg', {}), ('LPWSTR', 'lpString', {'IO': 'O', 'cnt': 'chCount'}), ('int', 'chCount', {}), ('int', 'idListBox', {})]],
[('int', 'DlgDirListComboBoxA'), [('HWND', 'hDlg', {}), ('LPSTR', 'lpPathSpec', {'IO': 'IO'}), ('int', 'nIDComboBox', {}), ('int', 'nIDStaticPath', {}), ('UINT', 'uFiletype', {})]],
[('int', 'DlgDirListComboBoxW'), [('HWND', 'hDlg', {}), ('LPWSTR', 'lpPathSpec', {'IO': 'IO'}), ('int', 'nIDComboBox', {}), ('int', 'nIDStaticPath', {}), ('UINT', 'uFiletype', {})]],
[('BOOL', 'DlgDirSelectComboBoxExA'), [('HWND', 'hwndDlg', {}), ('LPSTR', 'lpString', {'IO': 'O', 'cnt': 'cchOut'}), ('int', 'cchOut', {}), ('int', 'idComboBox', {})]],
[('BOOL', 'DlgDirSelectComboBoxExW'), [('HWND', 'hwndDlg', {}), ('LPWSTR', 'lpString', {'IO': 'O', 'cnt': 'cchOut'}), ('int', 'cchOut', {}), ('int', 'idComboBox', {})]],
[('int', 'SetScrollInfo'), [('HWND', 'hwnd', {}), ('int', 'nBar', {}), ('LPCSCROLLINFO', 'lpsi', {}), ('BOOL', 'redraw', {})]],
[('BOOL', 'GetScrollInfo'), [('HWND', 'hwnd', {}), ('int', 'nBar', {}), ('LPSCROLLINFO', 'lpsi', {'IO': 'IO'})]],
[('LRESULT', 'DefFrameProcA'), [('HWND', 'hWnd', {}), ('HWND', 'hWndMDIClient', {}), ('UINT', 'uMsg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('LRESULT', 'DefFrameProcW'), [('HWND', 'hWnd', {}), ('HWND', 'hWndMDIClient', {}), ('UINT', 'uMsg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('LRESULT', 'DefMDIChildProcA'), [('HWND', 'hWnd', {}), ('UINT', 'uMsg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('LRESULT', 'DefMDIChildProcW'), [('HWND', 'hWnd', {}), ('UINT', 'uMsg', {}), ('WPARAM', 'wParam', {}), ('LPARAM', 'lParam', {})]],
[('BOOL', 'TranslateMDISysAccel'), [('HWND', 'hWndClient', {}), ('LPMSG', 'lpMsg', {})]],
[('UINT', 'ArrangeIconicWindows'), [('HWND', 'hWnd', {})]],
[('HWND', 'CreateMDIWindowA'), [('LPCSTR', 'lpClassName', {}), ('LPCSTR', 'lpWindowName', {}), ('DWORD', 'dwStyle', {}), ('int', 'X', {}), ('int', 'Y', {}), ('int', 'nWidth', {}), ('int', 'nHeight', {}), ('HWND', 'hWndParent', {}), ('HINSTANCE', 'hInstance', {}), ('LPARAM', 'lParam', {})]],
[('HWND', 'CreateMDIWindowW'), [('LPCWSTR', 'lpClassName', {}), ('LPCWSTR', 'lpWindowName', {}), ('DWORD', 'dwStyle', {}), ('int', 'X', {}), ('int', 'Y', {}), ('int', 'nWidth', {}), ('int', 'nHeight', {}), ('HWND', 'hWndParent', {}), ('HINSTANCE', 'hInstance', {}), ('LPARAM', 'lParam', {})]],
[('WORD', 'TileWindows'), [('HWND', 'hwndParent', {}), ('UINT', 'wHow', {}), ('CONST RECT*', ' lpRect', {}), ('UINT', 'cKids', {}), ('CONST HWND*', ' lpKids', {'cnt': 'cKids'})]],
[('WORD', 'CascadeWindows'), [('HWND', 'hwndParent', {}), ('UINT', 'wHow', {}), ('CONST RECT*', ' lpRect', {}), ('UINT', 'cKids', {}), ('CONST HWND*', ' lpKids', {'cnt': 'cKids'})]],
[('BOOL', 'WinHelpA'), [('HWND', 'hWndMain', {}), ('LPCSTR', 'lpszHelp', {}), ('UINT', 'uCommand', {}), ('ULONG_PTR', 'dwData', {})]],
[('BOOL', 'WinHelpW'), [('HWND', 'hWndMain', {}), ('LPCWSTR', 'lpszHelp', {}), ('UINT', 'uCommand', {}), ('ULONG_PTR', 'dwData', {})]],
[('DWORD', 'GetGuiResources'), [('HANDLE', 'hProcess', {}), ('DWORD', 'uiFlags', {})]],
[('LONG', 'ChangeDisplaySettingsA'), [('DEVMODEA*', ' lpDevMode', {}), ('DWORD', 'dwFlags', {})]],
[('LONG', 'ChangeDisplaySettingsW'), [('DEVMODEW*', ' lpDevMode', {}), ('DWORD', 'dwFlags', {})]],
[('LONG', 'ChangeDisplaySettingsExA'), [('LPCSTR', 'lpszDeviceName', {}), ('DEVMODEA*', ' lpDevMode', {}), ('HWND', 'hwnd', {}), ('DWORD', 'dwflags', {}), ('LPVOID', 'lParam', {})]],
[('LONG', 'ChangeDisplaySettingsExW'), [('LPCWSTR', 'lpszDeviceName', {}), ('DEVMODEW*', ' lpDevMode', {}), ('HWND', 'hwnd', {}), ('DWORD', 'dwflags', {}), ('LPVOID', 'lParam', {})]],
[('BOOL', 'EnumDisplaySettingsA'), [('LPCSTR', 'lpszDeviceName', {}), ('DWORD', 'iModeNum', {}), ('DEVMODEA*', ' lpDevMode', {'IO': 'IO'})]],
[('BOOL', 'EnumDisplaySettingsW'), [('LPCWSTR', 'lpszDeviceName', {}), ('DWORD', 'iModeNum', {}), ('DEVMODEW*', ' lpDevMode', {'IO': 'IO'})]],
[('BOOL', 'EnumDisplaySettingsExA'), [('LPCSTR', 'lpszDeviceName', {}), ('DWORD', 'iModeNum', {}), ('DEVMODEA*', ' lpDevMode', {'IO': 'IO'}), ('DWORD', 'dwFlags', {})]],
[('BOOL', 'EnumDisplaySettingsExW'), [('LPCWSTR', 'lpszDeviceName', {}), ('DWORD', 'iModeNum', {}), ('DEVMODEW*', ' lpDevMode', {'IO': 'IO'}), ('DWORD', 'dwFlags', {})]],
[('BOOL', 'EnumDisplayDevicesA'), [('LPCSTR', 'lpDevice', {}), ('DWORD', 'iDevNum', {}), ('PDISPLAY_DEVICEA', 'lpDisplayDevice', {'IO': 'IO'}), ('DWORD', 'dwFlags', {})]],
[('BOOL', 'EnumDisplayDevicesW'), [('LPCWSTR', 'lpDevice', {}), ('DWORD', 'iDevNum', {}), ('PDISPLAY_DEVICEW', 'lpDisplayDevice', {'IO': 'IO'}), ('DWORD', 'dwFlags', {})]],
[('LONG', 'GetDisplayConfigBufferSizes'), [('UINT32', 'flags', {}), ('UINT32*', ' numPathArrayElements', {'IO': 'O'}), ('UINT32*', ' numModeInfoArrayElements', {'IO': 'O'})]],
[('LONG', 'SetDisplayConfig'), [('UINT32', 'numPathArrayElements', {}), ('DISPLAYCONFIG_PATH_INFO*', ' pathArray', {'cnt': 'numPathArrayElements'}), ('UINT32', 'numModeInfoArrayElements', {}), ('DISPLAYCONFIG_MODE_INFO*', ' modeInfoArray', {'cnt': 'numModeInfoArrayElements'}), ('UINT32', 'flags', {})]],
[('LONG', 'QueryDisplayConfig'), [('UINT32', 'flags', {}), ('UINT32*', ' numPathArrayElements', {'IO': 'IO'}), ('DISPLAYCONFIG_PATH_INFO*', ' pathArray', {'IO': 'O', 'cnt': '*numPathArrayElements, *numPathArrayElements'}), ('UINT32*', ' numModeInfoArrayElements', {'IO': 'IO'}), ('DISPLAYCONFIG_MODE_INFO*', ' modeInfoArray', {'IO': 'O', 'cnt': '*numModeInfoArrayElements, *numModeInfoArrayElements'}), ('DISPLAYCONFIG_TOPOLOGY_ID*', ' currentTopologyId', {'IO': 'O'})]],
[('LONG', 'DisplayConfigGetDeviceInfo'), [('DISPLAYCONFIG_DEVICE_INFO_HEADER*', ' requestPacket', {'IO': 'IO'})]],
[('LONG', 'DisplayConfigSetDeviceInfo'), [('DISPLAYCONFIG_DEVICE_INFO_HEADER*', ' setPacket', {})]],
[('BOOL', 'SystemParametersInfoA'), [('UINT', 'uiAction', {}), ('UINT', 'uiParam', {}), ('PVOID', 'pvParam', {'IO': 'IO'}), ('UINT', 'fWinIni', {})]],
[('BOOL', 'SystemParametersInfoW'), [('UINT', 'uiAction', {}), ('UINT', 'uiParam', {}), ('PVOID', 'pvParam', {'IO': 'IO'}), ('UINT', 'fWinIni', {})]],
[('BOOL', 'SoundSentry'), []],
[('VOID', 'SetDebugErrorLevel'), [('DWORD', 'dwLevel', {})]],
[('VOID', 'SetLastErrorEx'), [('DWORD', 'dwErrCode', {}), ('DWORD', 'dwType', {})]],
[('int', 'InternalGetWindowText'), [('HWND', 'hWnd', {}), ('LPWSTR', 'pString', {'IO': 'O', 'cnt': 'cchMaxCount, ret + 1'}), ('int', 'cchMaxCount', {})]],
[('BOOL', 'CancelShutdown'), []],
[('HMONITOR', 'MonitorFromPoint'), [('POINT', 'pt', {}), ('DWORD', 'dwFlags', {})]],
[('HMONITOR', 'MonitorFromRect'), [('LPCRECT', 'lprc', {}), ('DWORD', 'dwFlags', {})]],
[('HMONITOR', 'MonitorFromWindow'), [('HWND', 'hwnd', {}), ('DWORD', 'dwFlags', {})]],
[('BOOL', 'GetMonitorInfoA'), [('HMONITOR', 'hMonitor', {}), ('LPMONITORINFO', 'lpmi', {'IO': 'IO'})]],
[('BOOL', 'GetMonitorInfoW'), [('HMONITOR', 'hMonitor', {}), ('LPMONITORINFO', 'lpmi', {'IO': 'IO'})]],
[('BOOL', 'EnumDisplayMonitors'), [('HDC', 'hdc', {}), ('LPCRECT', 'lprcClip', {}), ('MONITORENUMPROC', 'lpfnEnum', {}), ('LPARAM', 'dwData', {})]],
[('VOID', 'NotifyWinEvent'), [('DWORD', 'event', {}), ('HWND', 'hwnd', {}), ('LONG', 'idObject', {}), ('LONG', 'idChild', {})]],
[('HWINEVENTHOOK', 'SetWinEventHook'), [('DWORD', 'eventMin', {}), ('DWORD', 'eventMax', {}), ('HMODULE', 'hmodWinEventProc', {}), ('WINEVENTPROC', 'pfnWinEventProc', {}), ('DWORD', 'idProcess', {}), ('DWORD', 'idThread', {}), ('DWORD', 'dwFlags', {})]],
[('BOOL', 'IsWinEventHookInstalled'), [('DWORD', 'event', {})]],
[('BOOL', 'UnhookWinEvent'), [('HWINEVENTHOOK', 'hWinEventHook', {})]],
[('BOOL', 'GetGUIThreadInfo'), [('DWORD', 'idThread', {}), ('PGUITHREADINFO', 'pgui', {'IO': 'IO'})]],
[('BOOL', 'BlockInput'), [('BOOL', 'fBlockIt', {})]],
[('BOOL', 'SetProcessDPIAware'), []],
[('BOOL', 'IsProcessDPIAware'), []],
[('UINT', 'GetWindowModuleFileNameA'), [('HWND', 'hwnd', {}), ('LPSTR', 'pszFileName', {'IO': 'O', 'cnt': 'cchFileNameMax, ret'}), ('UINT', 'cchFileNameMax', {})]],
[('UINT', 'GetWindowModuleFileNameW'), [('HWND', 'hwnd', {}), ('LPWSTR', 'pszFileName', {'IO': 'O', 'cnt': 'cchFileNameMax, ret'}), ('UINT', 'cchFileNameMax', {})]],
[('BOOL', 'GetCursorInfo'), [('PCURSORINFO', 'pci', {'IO': 'IO'})]],
[('BOOL', 'GetWindowInfo'), [('HWND', 'hwnd', {}), ('PWINDOWINFO', 'pwi', {'IO': 'IO'})]],
[('BOOL', 'GetTitleBarInfo'), [('HWND', 'hwnd', {}), ('PTITLEBARINFO', 'pti', {'IO': 'IO'})]],
[('BOOL', 'GetMenuBarInfo'), [('HWND', 'hwnd', {}), ('LONG', 'idObject', {}), ('LONG', 'idItem', {}), ('PMENUBARINFO', 'pmbi', {'IO': 'IO'})]],
[('BOOL', 'GetScrollBarInfo'), [('HWND', 'hwnd', {}), ('LONG', 'idObject', {}), ('PSCROLLBARINFO', 'psbi', {'IO': 'IO'})]],
[('BOOL', 'GetComboBoxInfo'), [('HWND', 'hwndCombo', {}), ('PCOMBOBOXINFO', 'pcbi', {'IO': 'IO'})]],
[('HWND', 'GetAncestor'), [('HWND', 'hwnd', {}), ('UINT', 'gaFlags', {})]],
[('HWND', 'RealChildWindowFromPoint'), [('HWND', 'hwndParent', {}), ('POINT', 'ptParentClientCoords', {})]],
[('UINT', 'RealGetWindowClassA'), [('HWND', 'hwnd', {}), ('LPSTR', 'ptszClassName', {'IO': 'O', 'cnt': 'cchClassNameMax, ret'}), ('UINT', 'cchClassNameMax', {})]],
[('UINT', 'RealGetWindowClassW'), [('HWND', 'hwnd', {}), ('LPWSTR', 'ptszClassName', {'IO': 'O', 'cnt': 'cchClassNameMax, ret'}), ('UINT', 'cchClassNameMax', {})]],
[('BOOL', 'GetAltTabInfoA'), [('HWND', 'hwnd', {}), ('int', 'iItem', {}), ('PALTTABINFO', 'pati', {'IO': 'IO'}), ('LPSTR', 'pszItemText', {'IO': 'O', 'cnt': 'cchItemText'}), ('UINT', 'cchItemText', {})]],
[('BOOL', 'GetAltTabInfoW'), [('HWND', 'hwnd', {}), ('int', 'iItem', {}), ('PALTTABINFO', 'pati', {'IO': 'IO'}), ('LPWSTR', 'pszItemText', {'IO': 'O', 'cnt': 'cchItemText'}), ('UINT', 'cchItemText', {})]],
[('DWORD', 'GetListBoxInfo'), [('HWND', 'hwnd', {})]],
[('BOOL', 'LockWorkStation'), []],
[('BOOL', 'UserHandleGrantAccess'), [('HANDLE', 'hUserHandle', {}), ('HANDLE', 'hJob', {}), ('BOOL', 'bGrant', {})]],
[('UINT', 'GetRawInputData'), [('HRAWINPUT', 'hRawInput', {}), ('UINT', 'uiCommand', {}), ('LPVOID', 'pData', {'IO': 'O'}), ('PUINT', 'pcbSize', {'IO': 'IO'}), ('UINT', 'cbSizeHeader', {})]],
[('UINT', 'GetRawInputDeviceInfoA'), [('HANDLE', 'hDevice', {}), ('UINT', 'uiCommand', {}), ('LPVOID', 'pData', {'IO': 'IO'}), ('PUINT', 'pcbSize', {'IO': 'IO'})]],
[('UINT', 'GetRawInputDeviceInfoW'), [('HANDLE', 'hDevice', {}), ('UINT', 'uiCommand', {}), ('LPVOID', 'pData', {'IO': 'IO'}), ('PUINT', 'pcbSize', {'IO': 'IO'})]],
[('UINT', 'GetRawInputBuffer'), [('PRAWINPUT', 'pData', {'IO': 'O'}), ('PUINT', 'pcbSize', {'IO': 'IO'}), ('UINT', 'cbSizeHeader', {})]],
[('BOOL', 'RegisterRawInputDevices'), [('PCRAWINPUTDEVICE', 'pRawInputDevices', {'cnt': 'uiNumDevices'}), ('UINT', 'uiNumDevices', {}), ('UINT', 'cbSize', {})]],
[('UINT', 'GetRegisteredRawInputDevices'), [('PRAWINPUTDEVICE', 'pRawInputDevices', {'IO': 'O', 'cnt': ' *puiNumDevices'}), ('PUINT', 'puiNumDevices', {'IO': 'IO'}), ('UINT', 'cbSize', {})]],
[('UINT', 'GetRawInputDeviceList'), [('PRAWINPUTDEVICELIST', 'pRawInputDeviceList', {'IO': 'O', 'cnt': '*puiNumDevices'}), ('PUINT', 'puiNumDevices', {'IO': 'IO'}), ('UINT', 'cbSize', {})]],
[('LRESULT', 'DefRawInputProc'), [('PRAWINPUT*', ' paRawInput', {'cnt': 'nInput'}), ('INT', 'nInput', {}), ('UINT', 'cbSizeHeader', {})]],
[('BOOL', 'ChangeWindowMessageFilter'), [('UINT', 'message', {}), ('DWORD', 'dwFlag', {})]],
[('BOOL', 'ChangeWindowMessageFilterEx'), [('HWND', 'hwnd', {}), ('UINT', 'message', {}), ('DWORD', 'action', {}), ('PCHANGEFILTERSTRUCT', 'pChangeFilterStruct', {'IO': 'IO'})]],
[('BOOL', 'GetGestureInfo'), [('HGESTUREINFO', 'hGestureInfo', {}), ('PGESTUREINFO', 'pGestureInfo', {'IO': 'O'})]],
[('BOOL', 'GetGestureExtraArgs'), [('HGESTUREINFO', 'hGestureInfo', {}), ('UINT', 'cbExtraArgs', {}), ('PBYTE', 'pExtraArgs', {'IO': 'O'})]],
[('BOOL', 'CloseGestureInfoHandle'), [('HGESTUREINFO', 'hGestureInfo', {})]],
[('BOOL', 'SetGestureConfig'), [('HWND', 'hwnd', {}), ('DWORD', 'dwReserved', {}), ('UINT', 'cIDs', {}), ('PGESTURECONFIG', 'pGestureConfig', {'cnt': 'cIDs'}), ('UINT', 'cbSize', {})]],
[('BOOL', 'GetGestureConfig'), [('HWND', 'hwnd', {}), ('DWORD', 'dwReserved', {}), ('DWORD', 'dwFlags', {}), ('PUINT', 'pcIDs', {}), ('PGESTURECONFIG', 'pGestureConfig', {'IO': 'IO', 'cnt': '*pcIDs'}), ('UINT', 'cbSize', {})]],
[('BOOL', 'ShutdownBlockReasonCreate'), [('HWND', 'hWnd', {}), ('LPCWSTR', 'pwszReason', {})]],
[('BOOL', 'ShutdownBlockReasonQuery'), [('HWND', 'hWnd', {}), ('LPWSTR', 'pwszBuff', {'IO': 'O', 'cnt': '*pcchBuff'}), ('DWORD*', 'pcchBuff', {'IO': 'IO'})]],
[('BOOL', 'ShutdownBlockReasonDestroy'), [('HWND', 'hWnd', {})]],
]
