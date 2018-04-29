
/*
Copyright (c) 2017 HyungSeok Han and Sang Kil Cha at SoftSec, KAIST

See the file LICENCE for copying permission.
*/
#include "stdafx.h"
#include <easyhook.h>
#include <Windows.h>

#ifndef LOG_PATH
#define LOG_PATH "D:\\log.txt"
#endif

HANDLE g_mutex;
const char* log_path = LOG_PATH;

typedef BOOL (WINAPI *RemoveMenu_fun) (HMENU hMenu,UINT uPosition,UINT uFlags);
RemoveMenu_fun pRemoveMenu = RemoveMenu;
HOOK_TRACE_INFO hHookRemoveMenu = { 0 };
ULONG HookRemoveMenu_ACLEntries[1] = { 0 };
BOOL fake_RemoveMenu(HMENU hMenu,UINT uPosition,UINT uFlags){
	BOOL ret = pRemoveMenu(hMenu,uPosition,uFlags);
	fprintf(fp,"OUT ['RemoveMenu',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *AttachThreadInput_fun) (DWORD idAttach,DWORD idAttachTo,BOOL fAttach);
AttachThreadInput_fun pAttachThreadInput = AttachThreadInput;
HOOK_TRACE_INFO hHookAttachThreadInput = { 0 };
ULONG HookAttachThreadInput_ACLEntries[1] = { 0 };
BOOL fake_AttachThreadInput(DWORD idAttach,DWORD idAttachTo,BOOL fAttach){
	BOOL ret = pAttachThreadInput(idAttach,idAttachTo,fAttach);
	fprintf(fp,"OUT ['AttachThreadInput',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *SetFocus_fun) (HWND hWnd);
SetFocus_fun pSetFocus = SetFocus;
HOOK_TRACE_INFO hHookSetFocus = { 0 };
ULONG HookSetFocus_ACLEntries[1] = { 0 };
HWND fake_SetFocus(HWND hWnd){
	HWND ret = pSetFocus(hWnd);
	fprintf(fp,"OUT ['SetFocus',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HCURSOR (WINAPI *SetCursor_fun) (HCURSOR hCursor);
SetCursor_fun pSetCursor = SetCursor;
HOOK_TRACE_INFO hHookSetCursor = { 0 };
ULONG HookSetCursor_ACLEntries[1] = { 0 };
HCURSOR fake_SetCursor(HCURSOR hCursor){
	HCURSOR ret = pSetCursor(hCursor);
	fprintf(fp,"OUT ['SetCursor',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HCURSOR),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HCURSOR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LONG (WINAPI *ChangeDisplaySettingsExA_fun) (LPCSTR lpszDeviceName,DEVMODEA*  lpDevMode,HWND hwnd,DWORD dwflags,LPVOID lParam);
ChangeDisplaySettingsExA_fun pChangeDisplaySettingsExA = ChangeDisplaySettingsExA;
HOOK_TRACE_INFO hHookChangeDisplaySettingsExA = { 0 };
ULONG HookChangeDisplaySettingsExA_ACLEntries[1] = { 0 };
LONG fake_ChangeDisplaySettingsExA(LPCSTR lpszDeviceName,DEVMODEA*  lpDevMode,HWND hwnd,DWORD dwflags,LPVOID lParam){
	LONG ret = pChangeDisplaySettingsExA(lpszDeviceName, lpDevMode,hwnd,dwflags,lParam);
	fprintf(fp,"OUT ['ChangeDisplaySettingsExA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LONG),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LONG));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *LookupIconIdFromDirectory_fun) (PBYTE presbits,BOOL fIcon);
LookupIconIdFromDirectory_fun pLookupIconIdFromDirectory = LookupIconIdFromDirectory;
HOOK_TRACE_INFO hHookLookupIconIdFromDirectory = { 0 };
ULONG HookLookupIconIdFromDirectory_ACLEntries[1] = { 0 };
int fake_LookupIconIdFromDirectory(PBYTE presbits,BOOL fIcon){
	int ret = pLookupIconIdFromDirectory(presbits,fIcon);
	fprintf(fp,"OUT ['LookupIconIdFromDirectory',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsWindowVisible_fun) (HWND hWnd);
IsWindowVisible_fun pIsWindowVisible = IsWindowVisible;
HOOK_TRACE_INFO hHookIsWindowVisible = { 0 };
ULONG HookIsWindowVisible_ACLEntries[1] = { 0 };
BOOL fake_IsWindowVisible(HWND hWnd){
	BOOL ret = pIsWindowVisible(hWnd);
	fprintf(fp,"OUT ['IsWindowVisible',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *MenuItemFromPoint_fun) (HWND hWnd,HMENU hMenu,POINT ptScreen);
MenuItemFromPoint_fun pMenuItemFromPoint = MenuItemFromPoint;
HOOK_TRACE_INFO hHookMenuItemFromPoint = { 0 };
ULONG HookMenuItemFromPoint_ACLEntries[1] = { 0 };
int fake_MenuItemFromPoint(HWND hWnd,HMENU hMenu,POINT ptScreen){
	int ret = pMenuItemFromPoint(hWnd,hMenu,ptScreen);
	fprintf(fp,"OUT ['MenuItemFromPoint',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LRESULT (WINAPI *CallNextHookEx_fun) (HHOOK hhk,int nCode,WPARAM wParam,LPARAM lParam);
CallNextHookEx_fun pCallNextHookEx = CallNextHookEx;
HOOK_TRACE_INFO hHookCallNextHookEx = { 0 };
ULONG HookCallNextHookEx_ACLEntries[1] = { 0 };
LRESULT fake_CallNextHookEx(HHOOK hhk,int nCode,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pCallNextHookEx(hhk,nCode,wParam,lParam);
	fprintf(fp,"OUT ['CallNextHookEx',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LRESULT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LRESULT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ShowCaret_fun) (HWND hWnd);
ShowCaret_fun pShowCaret = ShowCaret;
HOOK_TRACE_INFO hHookShowCaret = { 0 };
ULONG HookShowCaret_ACLEntries[1] = { 0 };
BOOL fake_ShowCaret(HWND hWnd){
	BOOL ret = pShowCaret(hWnd);
	fprintf(fp,"OUT ['ShowCaret',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef ATOM (WINAPI *RegisterClassExA_fun) (CONST WNDCLASSEXA* arg0);
RegisterClassExA_fun pRegisterClassExA = RegisterClassExA;
HOOK_TRACE_INFO hHookRegisterClassExA = { 0 };
ULONG HookRegisterClassExA_ACLEntries[1] = { 0 };
ATOM fake_RegisterClassExA(CONST WNDCLASSEXA* arg0){
	ATOM ret = pRegisterClassExA(arg0);
	fprintf(fp,"OUT ['RegisterClassExA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%hx,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(ATOM),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%hx, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(ATOM));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetDlgItemInt_fun) (HWND hDlg,int nIDDlgItem,UINT uValue,BOOL bSigned);
SetDlgItemInt_fun pSetDlgItemInt = SetDlgItemInt;
HOOK_TRACE_INFO hHookSetDlgItemInt = { 0 };
ULONG HookSetDlgItemInt_ACLEntries[1] = { 0 };
BOOL fake_SetDlgItemInt(HWND hDlg,int nIDDlgItem,UINT uValue,BOOL bSigned){
	BOOL ret = pSetDlgItemInt(hDlg,nIDDlgItem,uValue,bSigned);
	fprintf(fp,"OUT ['SetDlgItemInt',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LRESULT (WINAPI *DefMDIChildProcA_fun) (HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
DefMDIChildProcA_fun pDefMDIChildProcA = DefMDIChildProcA;
HOOK_TRACE_INFO hHookDefMDIChildProcA = { 0 };
ULONG HookDefMDIChildProcA_ACLEntries[1] = { 0 };
LRESULT fake_DefMDIChildProcA(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pDefMDIChildProcA(hWnd,uMsg,wParam,lParam);
	fprintf(fp,"OUT ['DefMDIChildProcA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LRESULT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LRESULT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *CloseWindow_fun) (HWND hWnd);
CloseWindow_fun pCloseWindow = CloseWindow;
HOOK_TRACE_INFO hHookCloseWindow = { 0 };
ULONG HookCloseWindow_ACLEntries[1] = { 0 };
BOOL fake_CloseWindow(HWND hWnd){
	BOOL ret = pCloseWindow(hWnd);
	fprintf(fp,"OUT ['CloseWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetProcessDefaultLayout_fun) (DWORD dwDefaultLayout);
SetProcessDefaultLayout_fun pSetProcessDefaultLayout = SetProcessDefaultLayout;
HOOK_TRACE_INFO hHookSetProcessDefaultLayout = { 0 };
ULONG HookSetProcessDefaultLayout_ACLEntries[1] = { 0 };
BOOL fake_SetProcessDefaultLayout(DWORD dwDefaultLayout){
	BOOL ret = pSetProcessDefaultLayout(dwDefaultLayout);
	fprintf(fp,"OUT ['SetProcessDefaultLayout',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *DrawIcon_fun) (HDC hDC,int X,int Y,HICON hIcon);
DrawIcon_fun pDrawIcon = DrawIcon;
HOOK_TRACE_INFO hHookDrawIcon = { 0 };
ULONG HookDrawIcon_ACLEntries[1] = { 0 };
BOOL fake_DrawIcon(HDC hDC,int X,int Y,HICON hIcon){
	BOOL ret = pDrawIcon(hDC,X,Y,hIcon);
	fprintf(fp,"OUT ['DrawIcon',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *TranslateAcceleratorA_fun) (HWND hWnd,HACCEL hAccTable,LPMSG lpMsg);
TranslateAcceleratorA_fun pTranslateAcceleratorA = TranslateAcceleratorA;
HOOK_TRACE_INFO hHookTranslateAcceleratorA = { 0 };
ULONG HookTranslateAcceleratorA_ACLEntries[1] = { 0 };
int fake_TranslateAcceleratorA(HWND hWnd,HACCEL hAccTable,LPMSG lpMsg){
	int ret = pTranslateAcceleratorA(hWnd,hAccTable,lpMsg);
	fprintf(fp,"OUT ['TranslateAcceleratorA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *GetQueueStatus_fun) (UINT flags);
GetQueueStatus_fun pGetQueueStatus = GetQueueStatus;
HOOK_TRACE_INFO hHookGetQueueStatus = { 0 };
ULONG HookGetQueueStatus_ACLEntries[1] = { 0 };
DWORD fake_GetQueueStatus(UINT flags){
	DWORD ret = pGetQueueStatus(flags);
	fprintf(fp,"OUT ['GetQueueStatus',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *DestroyWindow_fun) (HWND hWnd);
DestroyWindow_fun pDestroyWindow = DestroyWindow;
HOOK_TRACE_INFO hHookDestroyWindow = { 0 };
ULONG HookDestroyWindow_ACLEntries[1] = { 0 };
BOOL fake_DestroyWindow(HWND hWnd){
	BOOL ret = pDestroyWindow(hWnd);
	fprintf(fp,"OUT ['DestroyWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LONG (WINAPI *ChangeDisplaySettingsExW_fun) (LPCWSTR lpszDeviceName,DEVMODEW*  lpDevMode,HWND hwnd,DWORD dwflags,LPVOID lParam);
ChangeDisplaySettingsExW_fun pChangeDisplaySettingsExW = ChangeDisplaySettingsExW;
HOOK_TRACE_INFO hHookChangeDisplaySettingsExW = { 0 };
ULONG HookChangeDisplaySettingsExW_ACLEntries[1] = { 0 };
LONG fake_ChangeDisplaySettingsExW(LPCWSTR lpszDeviceName,DEVMODEW*  lpDevMode,HWND hwnd,DWORD dwflags,LPVOID lParam){
	LONG ret = pChangeDisplaySettingsExW(lpszDeviceName, lpDevMode,hwnd,dwflags,lParam);
	fprintf(fp,"OUT ['ChangeDisplaySettingsExW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LONG),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LONG));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HKL (WINAPI *LoadKeyboardLayoutA_fun) (LPCSTR pwszKLID,UINT Flags);
LoadKeyboardLayoutA_fun pLoadKeyboardLayoutA = LoadKeyboardLayoutA;
HOOK_TRACE_INFO hHookLoadKeyboardLayoutA = { 0 };
ULONG HookLoadKeyboardLayoutA_ACLEntries[1] = { 0 };
HKL fake_LoadKeyboardLayoutA(LPCSTR pwszKLID,UINT Flags){
	HKL ret = pLoadKeyboardLayoutA(pwszKLID,Flags);
	fprintf(fp,"OUT ['LoadKeyboardLayoutA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HKL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HKL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef ATOM (WINAPI *RegisterClassA_fun) (CONST WNDCLASSA* lpWndClass);
RegisterClassA_fun pRegisterClassA = RegisterClassA;
HOOK_TRACE_INFO hHookRegisterClassA = { 0 };
ULONG HookRegisterClassA_ACLEntries[1] = { 0 };
ATOM fake_RegisterClassA(CONST WNDCLASSA* lpWndClass){
	ATOM ret = pRegisterClassA(lpWndClass);
	fprintf(fp,"OUT ['RegisterClassA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%hx,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(ATOM),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%hx, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(ATOM));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HICON (WINAPI *CreateIconFromResourceEx_fun) (PBYTE presbits,DWORD dwResSize,BOOL fIcon,DWORD dwVer,int cxDesired,int cyDesired,UINT Flags);
CreateIconFromResourceEx_fun pCreateIconFromResourceEx = CreateIconFromResourceEx;
HOOK_TRACE_INFO hHookCreateIconFromResourceEx = { 0 };
ULONG HookCreateIconFromResourceEx_ACLEntries[1] = { 0 };
HICON fake_CreateIconFromResourceEx(PBYTE presbits,DWORD dwResSize,BOOL fIcon,DWORD dwVer,int cxDesired,int cyDesired,UINT Flags){
	HICON ret = pCreateIconFromResourceEx(presbits,dwResSize,fIcon,dwVer,cxDesired,cyDesired,Flags);
	fprintf(fp,"OUT ['CreateIconFromResourceEx',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HICON),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HICON));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LONG (WINAPI *ChangeDisplaySettingsW_fun) (DEVMODEW*  lpDevMode,DWORD dwFlags);
ChangeDisplaySettingsW_fun pChangeDisplaySettingsW = ChangeDisplaySettingsW;
HOOK_TRACE_INFO hHookChangeDisplaySettingsW = { 0 };
ULONG HookChangeDisplaySettingsW_ACLEntries[1] = { 0 };
LONG fake_ChangeDisplaySettingsW(DEVMODEW*  lpDevMode,DWORD dwFlags){
	LONG ret = pChangeDisplaySettingsW( lpDevMode,dwFlags);
	fprintf(fp,"OUT ['ChangeDisplaySettingsW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LONG),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LONG));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetWindowPos_fun) (HWND hWnd,HWND hWndInsertAfter,int X,int Y,int cx,int cy,UINT uFlags);
SetWindowPos_fun pSetWindowPos = SetWindowPos;
HOOK_TRACE_INFO hHookSetWindowPos = { 0 };
ULONG HookSetWindowPos_ACLEntries[1] = { 0 };
BOOL fake_SetWindowPos(HWND hWnd,HWND hWndInsertAfter,int X,int Y,int cx,int cy,UINT uFlags){
	BOOL ret = pSetWindowPos(hWnd,hWndInsertAfter,X,Y,cx,cy,uFlags);
	fprintf(fp,"OUT ['SetWindowPos',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *RegisterTouchWindow_fun) (HWND hwnd,ULONG ulFlags);
RegisterTouchWindow_fun pRegisterTouchWindow = RegisterTouchWindow;
HOOK_TRACE_INFO hHookRegisterTouchWindow = { 0 };
ULONG HookRegisterTouchWindow_ACLEntries[1] = { 0 };
BOOL fake_RegisterTouchWindow(HWND hwnd,ULONG ulFlags){
	BOOL ret = pRegisterTouchWindow(hwnd,ulFlags);
	fprintf(fp,"OUT ['RegisterTouchWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetPropA_fun) (HWND hWnd,LPCSTR lpString,HANDLE hData);
SetPropA_fun pSetPropA = SetPropA;
HOOK_TRACE_INFO hHookSetPropA = { 0 };
ULONG HookSetPropA_ACLEntries[1] = { 0 };
BOOL fake_SetPropA(HWND hWnd,LPCSTR lpString,HANDLE hData){
	BOOL ret = pSetPropA(hWnd,lpString,hData);
	fprintf(fp,"OUT ['SetPropA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *GetWindowTextLengthA_fun) (HWND hWnd);
GetWindowTextLengthA_fun pGetWindowTextLengthA = GetWindowTextLengthA;
HOOK_TRACE_INFO hHookGetWindowTextLengthA = { 0 };
ULONG HookGetWindowTextLengthA_ACLEntries[1] = { 0 };
int fake_GetWindowTextLengthA(HWND hWnd){
	int ret = pGetWindowTextLengthA(hWnd);
	fprintf(fp,"OUT ['GetWindowTextLengthA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HACCEL (WINAPI *CreateAcceleratorTableA_fun) (LPACCEL paccel,int cAccel);
CreateAcceleratorTableA_fun pCreateAcceleratorTableA = CreateAcceleratorTableA;
HOOK_TRACE_INFO hHookCreateAcceleratorTableA = { 0 };
ULONG HookCreateAcceleratorTableA_ACLEntries[1] = { 0 };
HACCEL fake_CreateAcceleratorTableA(LPACCEL paccel,int cAccel){
	HACCEL ret = pCreateAcceleratorTableA(paccel,cAccel);
	fprintf(fp,"OUT ['CreateAcceleratorTableA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HACCEL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HACCEL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *CreateDialogIndirectParamW_fun) (HINSTANCE hInstance,LPCDLGTEMPLATEW lpTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
CreateDialogIndirectParamW_fun pCreateDialogIndirectParamW = CreateDialogIndirectParamW;
HOOK_TRACE_INFO hHookCreateDialogIndirectParamW = { 0 };
ULONG HookCreateDialogIndirectParamW_ACLEntries[1] = { 0 };
HWND fake_CreateDialogIndirectParamW(HINSTANCE hInstance,LPCDLGTEMPLATEW lpTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam){
	HWND ret = pCreateDialogIndirectParamW(hInstance,lpTemplate,hWndParent,lpDialogFunc,dwInitParam);
	fprintf(fp,"OUT ['CreateDialogIndirectParamW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HKL (WINAPI *ActivateKeyboardLayout_fun) (HKL hkl,UINT Flags);
ActivateKeyboardLayout_fun pActivateKeyboardLayout = ActivateKeyboardLayout;
HOOK_TRACE_INFO hHookActivateKeyboardLayout = { 0 };
ULONG HookActivateKeyboardLayout_ACLEntries[1] = { 0 };
HKL fake_ActivateKeyboardLayout(HKL hkl,UINT Flags){
	HKL ret = pActivateKeyboardLayout(hkl,Flags);
	fprintf(fp,"OUT ['ActivateKeyboardLayout',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HKL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HKL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LONG (WINAPI *GetWindowLongW_fun) (HWND hWnd,int nIndex);
GetWindowLongW_fun pGetWindowLongW = GetWindowLongW;
HOOK_TRACE_INFO hHookGetWindowLongW = { 0 };
ULONG HookGetWindowLongW_ACLEntries[1] = { 0 };
LONG fake_GetWindowLongW(HWND hWnd,int nIndex){
	LONG ret = pGetWindowLongW(hWnd,nIndex);
	fprintf(fp,"OUT ['GetWindowLongW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LONG),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LONG));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetIconInfo_fun) (HICON hIcon,PICONINFO piconinfo);
GetIconInfo_fun pGetIconInfo = GetIconInfo;
HOOK_TRACE_INFO hHookGetIconInfo = { 0 };
ULONG HookGetIconInfo_ACLEntries[1] = { 0 };
BOOL fake_GetIconInfo(HICON hIcon,PICONINFO piconinfo){
	BOOL ret = pGetIconInfo(hIcon,piconinfo);
	fprintf(fp,"OUT ['GetIconInfo',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'piconinfo','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",piconinfo, sizeof(PICONINFO),1);
 	else fprintf(fp,"{'name':'piconinfo','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",piconinfo,sizeof(PICONINFO));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LRESULT (WINAPI *DispatchMessageW_fun) (CONST MSG* lpMsg);
DispatchMessageW_fun pDispatchMessageW = DispatchMessageW;
HOOK_TRACE_INFO hHookDispatchMessageW = { 0 };
ULONG HookDispatchMessageW_ACLEntries[1] = { 0 };
LRESULT fake_DispatchMessageW(CONST MSG* lpMsg){
	LRESULT ret = pDispatchMessageW(lpMsg);
	fprintf(fp,"OUT ['DispatchMessageW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LRESULT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LRESULT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetCursorPos_fun) (int X,int Y);
SetCursorPos_fun pSetCursorPos = SetCursorPos;
HOOK_TRACE_INFO hHookSetCursorPos = { 0 };
ULONG HookSetCursorPos_ACLEntries[1] = { 0 };
BOOL fake_SetCursorPos(int X,int Y){
	BOOL ret = pSetCursorPos(X,Y);
	fprintf(fp,"OUT ['SetCursorPos',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *CalculatePopupWindowPosition_fun) (CONST POINT* anchorPoint,CONST SIZE* windowSize,UINT flags,RECT* excludeRect,RECT* popupWindowPosition);
CalculatePopupWindowPosition_fun pCalculatePopupWindowPosition = CalculatePopupWindowPosition;
HOOK_TRACE_INFO hHookCalculatePopupWindowPosition = { 0 };
ULONG HookCalculatePopupWindowPosition_ACLEntries[1] = { 0 };
BOOL fake_CalculatePopupWindowPosition(CONST POINT* anchorPoint,CONST SIZE* windowSize,UINT flags,RECT* excludeRect,RECT* popupWindowPosition){
	BOOL ret = pCalculatePopupWindowPosition(anchorPoint,windowSize,flags,excludeRect,popupWindowPosition);
	fprintf(fp,"OUT ['CalculatePopupWindowPosition',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'popupWindowPosition','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",popupWindowPosition, sizeof(RECT*),1);
 	else fprintf(fp,"{'name':'popupWindowPosition','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",popupWindowPosition,sizeof(RECT*));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *ArrangeIconicWindows_fun) (HWND hWnd);
ArrangeIconicWindows_fun pArrangeIconicWindows = ArrangeIconicWindows;
HOOK_TRACE_INFO hHookArrangeIconicWindows = { 0 };
ULONG HookArrangeIconicWindows_ACLEntries[1] = { 0 };
UINT fake_ArrangeIconicWindows(HWND hWnd){
	UINT ret = pArrangeIconicWindows(hWnd);
	fprintf(fp,"OUT ['ArrangeIconicWindows',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LRESULT (WINAPI *CallWindowProcW_fun) (WNDPROC lpPrevWndFunc,HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
CallWindowProcW_fun pCallWindowProcW = CallWindowProcW;
HOOK_TRACE_INFO hHookCallWindowProcW = { 0 };
ULONG HookCallWindowProcW_ACLEntries[1] = { 0 };
LRESULT fake_CallWindowProcW(WNDPROC lpPrevWndFunc,HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pCallWindowProcW(lpPrevWndFunc,hWnd,Msg,wParam,lParam);
	fprintf(fp,"OUT ['CallWindowProcW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LRESULT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LRESULT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LONG (WINAPI *QueryDisplayConfig_fun) (UINT32 flags,UINT32*  numPathArrayElements,DISPLAYCONFIG_PATH_INFO*  pathArray,UINT32*  numModeInfoArrayElements,DISPLAYCONFIG_MODE_INFO*  modeInfoArray,DISPLAYCONFIG_TOPOLOGY_ID*  currentTopologyId);
QueryDisplayConfig_fun pQueryDisplayConfig = QueryDisplayConfig;
HOOK_TRACE_INFO hHookQueryDisplayConfig = { 0 };
ULONG HookQueryDisplayConfig_ACLEntries[1] = { 0 };
LONG fake_QueryDisplayConfig(UINT32 flags,UINT32*  numPathArrayElements,DISPLAYCONFIG_PATH_INFO*  pathArray,UINT32*  numModeInfoArrayElements,DISPLAYCONFIG_MODE_INFO*  modeInfoArray,DISPLAYCONFIG_TOPOLOGY_ID*  currentTopologyId){
	LONG ret = pQueryDisplayConfig(flags, numPathArrayElements, pathArray, numModeInfoArrayElements, modeInfoArray, currentTopologyId);
	fprintf(fp,"OUT ['QueryDisplayConfig',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LONG),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LONG));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':' numPathArrayElements','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[", numPathArrayElements, sizeof(UINT32*),1);
 	else fprintf(fp,"{'name':' numPathArrayElements','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[", numPathArrayElements,sizeof(UINT32*));
	fprintf(fp,"]},");
 	if(numPathArrayElements &&  *numPathArrayElements && 1) fprintf(fp,"{'name':' pathArray','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[", pathArray, sizeof(DISPLAYCONFIG_PATH_INFO*),*numPathArrayElements, *numPathArrayElements);
 	else fprintf(fp,"{'name':' pathArray','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[", pathArray,sizeof(DISPLAYCONFIG_PATH_INFO*));
	if(numPathArrayElements &&  *numPathArrayElements &&  pathArray){
		for(int i=0; i<*numPathArrayElements <  *numPathArrayElements ? *numPathArrayElements :  *numPathArrayElements;i++){
			fprintf(fp,"0x%x,", pathArray[i]);
		}
	}
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':' numModeInfoArrayElements','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[", numModeInfoArrayElements, sizeof(UINT32*),1);
 	else fprintf(fp,"{'name':' numModeInfoArrayElements','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[", numModeInfoArrayElements,sizeof(UINT32*));
	fprintf(fp,"]},");
 	if(numModeInfoArrayElements &&  *numModeInfoArrayElements && 1) fprintf(fp,"{'name':' modeInfoArray','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[", modeInfoArray, sizeof(DISPLAYCONFIG_MODE_INFO*),*numModeInfoArrayElements, *numModeInfoArrayElements);
 	else fprintf(fp,"{'name':' modeInfoArray','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[", modeInfoArray,sizeof(DISPLAYCONFIG_MODE_INFO*));
	if(numModeInfoArrayElements &&  *numModeInfoArrayElements &&  modeInfoArray){
		for(int i=0; i<*numModeInfoArrayElements <  *numModeInfoArrayElements ? *numModeInfoArrayElements :  *numModeInfoArrayElements;i++){
			fprintf(fp,"0x%x,", modeInfoArray[i]);
		}
	}
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':' currentTopologyId','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[", currentTopologyId, sizeof(DISPLAYCONFIG_TOPOLOGY_ID*),1);
 	else fprintf(fp,"{'name':' currentTopologyId','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[", currentTopologyId,sizeof(DISPLAYCONFIG_TOPOLOGY_ID*));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *MapVirtualKeyExW_fun) (UINT uCode,UINT uMapType,HKL dwhkl);
MapVirtualKeyExW_fun pMapVirtualKeyExW = MapVirtualKeyExW;
HOOK_TRACE_INFO hHookMapVirtualKeyExW = { 0 };
ULONG HookMapVirtualKeyExW_ACLEntries[1] = { 0 };
UINT fake_MapVirtualKeyExW(UINT uCode,UINT uMapType,HKL dwhkl){
	UINT ret = pMapVirtualKeyExW(uCode,uMapType,dwhkl);
	fprintf(fp,"OUT ['MapVirtualKeyExW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetThreadDesktop_fun) (HDESK hDesktop);
SetThreadDesktop_fun pSetThreadDesktop = SetThreadDesktop;
HOOK_TRACE_INFO hHookSetThreadDesktop = { 0 };
ULONG HookSetThreadDesktop_ACLEntries[1] = { 0 };
BOOL fake_SetThreadDesktop(HDESK hDesktop){
	BOOL ret = pSetThreadDesktop(hDesktop);
	fprintf(fp,"OUT ['SetThreadDesktop',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef VOID (WINAPI *mouse_event_fun) (DWORD dwFlags,DWORD dx,DWORD dy,DWORD dwData,ULONG_PTR dwExtraInfo);
mouse_event_fun pmouse_event = mouse_event;
HOOK_TRACE_INFO hHookmouse_event = { 0 };
ULONG Hookmouse_event_ACLEntries[1] = { 0 };
VOID fake_mouse_event(DWORD dwFlags,DWORD dx,DWORD dy,DWORD dwData,ULONG_PTR dwExtraInfo){
	pmouse_event(dwFlags,dx,dy,dwData,dwExtraInfo);
	fprintf(fp,"OUT ['mouse_event',");
	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
}


typedef HMENU (WINAPI *CreatePopupMenu_fun) ();
CreatePopupMenu_fun pCreatePopupMenu = CreatePopupMenu;
HOOK_TRACE_INFO hHookCreatePopupMenu = { 0 };
ULONG HookCreatePopupMenu_ACLEntries[1] = { 0 };
HMENU fake_CreatePopupMenu(){
	HMENU ret = pCreatePopupMenu();
	fprintf(fp,"OUT ['CreatePopupMenu',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HMENU),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HMENU));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ShowOwnedPopups_fun) (HWND hWnd,BOOL fShow);
ShowOwnedPopups_fun pShowOwnedPopups = ShowOwnedPopups;
HOOK_TRACE_INFO hHookShowOwnedPopups = { 0 };
ULONG HookShowOwnedPopups_ACLEntries[1] = { 0 };
BOOL fake_ShowOwnedPopups(HWND hWnd,BOOL fShow){
	BOOL ret = pShowOwnedPopups(hWnd,fShow);
	fprintf(fp,"OUT ['ShowOwnedPopups',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetScrollRange_fun) (HWND hWnd,int nBar,int nMinPos,int nMaxPos,BOOL bRedraw);
SetScrollRange_fun pSetScrollRange = SetScrollRange;
HOOK_TRACE_INFO hHookSetScrollRange = { 0 };
ULONG HookSetScrollRange_ACLEntries[1] = { 0 };
BOOL fake_SetScrollRange(HWND hWnd,int nBar,int nMinPos,int nMaxPos,BOOL bRedraw){
	BOOL ret = pSetScrollRange(hWnd,nBar,nMinPos,nMaxPos,bRedraw);
	fprintf(fp,"OUT ['SetScrollRange',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EnumWindowStationsA_fun) (WINSTAENUMPROCA lpEnumFunc,LPARAM lParam);
EnumWindowStationsA_fun pEnumWindowStationsA = EnumWindowStationsA;
HOOK_TRACE_INFO hHookEnumWindowStationsA = { 0 };
ULONG HookEnumWindowStationsA_ACLEntries[1] = { 0 };
BOOL fake_EnumWindowStationsA(WINSTAENUMPROCA lpEnumFunc,LPARAM lParam){
	BOOL ret = pEnumWindowStationsA(lpEnumFunc,lParam);
	fprintf(fp,"OUT ['EnumWindowStationsA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetClipCursor_fun) (LPRECT lpRect);
GetClipCursor_fun pGetClipCursor = GetClipCursor;
HOOK_TRACE_INFO hHookGetClipCursor = { 0 };
ULONG HookGetClipCursor_ACLEntries[1] = { 0 };
BOOL fake_GetClipCursor(LPRECT lpRect){
	BOOL ret = pGetClipCursor(lpRect);
	fprintf(fp,"OUT ['GetClipCursor',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpRect','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpRect, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'lpRect','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpRect,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HANDLE (WINAPI *SetClipboardData_fun) (UINT uFormat,HANDLE hMem);
SetClipboardData_fun pSetClipboardData = SetClipboardData;
HOOK_TRACE_INFO hHookSetClipboardData = { 0 };
ULONG HookSetClipboardData_ACLEntries[1] = { 0 };
HANDLE fake_SetClipboardData(UINT uFormat,HANDLE hMem){
	HANDLE ret = pSetClipboardData(uFormat,hMem);
	fprintf(fp,"OUT ['SetClipboardData',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HANDLE),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HANDLE));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetWindowDisplayAffinity_fun) (HWND hWnd,DWORD*  pdwAffinity);
GetWindowDisplayAffinity_fun pGetWindowDisplayAffinity = GetWindowDisplayAffinity;
HOOK_TRACE_INFO hHookGetWindowDisplayAffinity = { 0 };
ULONG HookGetWindowDisplayAffinity_ACLEntries[1] = { 0 };
BOOL fake_GetWindowDisplayAffinity(HWND hWnd,DWORD*  pdwAffinity){
	BOOL ret = pGetWindowDisplayAffinity(hWnd, pdwAffinity);
	fprintf(fp,"OUT ['GetWindowDisplayAffinity',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':' pdwAffinity','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[", pdwAffinity, sizeof(DWORD*),1);
 	else fprintf(fp,"{'name':' pdwAffinity','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[", pdwAffinity,sizeof(DWORD*));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *AppendMenuA_fun) (HMENU hMenu,UINT uFlags,UINT_PTR uIDNewItem,LPCSTR lpNewItem);
AppendMenuA_fun pAppendMenuA = AppendMenuA;
HOOK_TRACE_INFO hHookAppendMenuA = { 0 };
ULONG HookAppendMenuA_ACLEntries[1] = { 0 };
BOOL fake_AppendMenuA(HMENU hMenu,UINT uFlags,UINT_PTR uIDNewItem,LPCSTR lpNewItem){
	BOOL ret = pAppendMenuA(hMenu,uFlags,uIDNewItem,lpNewItem);
	fprintf(fp,"OUT ['AppendMenuA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *CharToOemBuffW_fun) (LPCWSTR lpszSrc,LPSTR lpszDst,DWORD cchDstLength);
CharToOemBuffW_fun pCharToOemBuffW = CharToOemBuffW;
HOOK_TRACE_INFO hHookCharToOemBuffW = { 0 };
ULONG HookCharToOemBuffW_ACLEntries[1] = { 0 };
BOOL fake_CharToOemBuffW(LPCWSTR lpszSrc,LPSTR lpszDst,DWORD cchDstLength){
	BOOL ret = pCharToOemBuffW(lpszSrc,lpszDst,cchDstLength);
	fprintf(fp,"OUT ['CharToOemBuffW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpszDst','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpszDst, sizeof(LPSTR),cchDstLength);
 	else fprintf(fp,"{'name':'lpszDst','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpszDst,sizeof(LPSTR));
	if(lpszDst){
		for(int i=0; i<cchDstLength;i++){
			fprintf(fp,"0x%x,",lpszDst[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HDESK (WINAPI *OpenDesktopW_fun) (LPCWSTR lpszDesktop,DWORD dwFlags,BOOL fInherit,ACCESS_MASK dwDesiredAccess);
OpenDesktopW_fun pOpenDesktopW = OpenDesktopW;
HOOK_TRACE_INFO hHookOpenDesktopW = { 0 };
ULONG HookOpenDesktopW_ACLEntries[1] = { 0 };
HDESK fake_OpenDesktopW(LPCWSTR lpszDesktop,DWORD dwFlags,BOOL fInherit,ACCESS_MASK dwDesiredAccess){
	HDESK ret = pOpenDesktopW(lpszDesktop,dwFlags,fInherit,dwDesiredAccess);
	fprintf(fp,"OUT ['OpenDesktopW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HDESK),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HDESK));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LRESULT (WINAPI *DefFrameProcA_fun) (HWND hWnd,HWND hWndMDIClient,UINT uMsg,WPARAM wParam,LPARAM lParam);
DefFrameProcA_fun pDefFrameProcA = DefFrameProcA;
HOOK_TRACE_INFO hHookDefFrameProcA = { 0 };
ULONG HookDefFrameProcA_ACLEntries[1] = { 0 };
LRESULT fake_DefFrameProcA(HWND hWnd,HWND hWndMDIClient,UINT uMsg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pDefFrameProcA(hWnd,hWndMDIClient,uMsg,wParam,lParam);
	fprintf(fp,"OUT ['DefFrameProcA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LRESULT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LRESULT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetSysColors_fun) (int cElements,CONST INT*  lpaElements,CONST COLORREF*  lpaRgbValues);
SetSysColors_fun pSetSysColors = SetSysColors;
HOOK_TRACE_INFO hHookSetSysColors = { 0 };
ULONG HookSetSysColors_ACLEntries[1] = { 0 };
BOOL fake_SetSysColors(int cElements,CONST INT*  lpaElements,CONST COLORREF*  lpaRgbValues){
	BOOL ret = pSetSysColors(cElements, lpaElements, lpaRgbValues);
	fprintf(fp,"OUT ['SetSysColors',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *DestroyIcon_fun) (HICON hIcon);
DestroyIcon_fun pDestroyIcon = DestroyIcon;
HOOK_TRACE_INFO hHookDestroyIcon = { 0 };
ULONG HookDestroyIcon_ACLEntries[1] = { 0 };
BOOL fake_DestroyIcon(HICON hIcon){
	BOOL ret = pDestroyIcon(hIcon);
	fprintf(fp,"OUT ['DestroyIcon',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *AdjustWindowRectEx_fun) (LPRECT lpRect,DWORD dwStyle,BOOL bMenu,DWORD dwExStyle);
AdjustWindowRectEx_fun pAdjustWindowRectEx = AdjustWindowRectEx;
HOOK_TRACE_INFO hHookAdjustWindowRectEx = { 0 };
ULONG HookAdjustWindowRectEx_ACLEntries[1] = { 0 };
BOOL fake_AdjustWindowRectEx(LPRECT lpRect,DWORD dwStyle,BOOL bMenu,DWORD dwExStyle){
	BOOL ret = pAdjustWindowRectEx(lpRect,dwStyle,bMenu,dwExStyle);
	fprintf(fp,"OUT ['AdjustWindowRectEx',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpRect','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpRect, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'lpRect','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpRect,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EqualRect_fun) (CONST RECT* lprc1,CONST RECT* lprc2);
EqualRect_fun pEqualRect = EqualRect;
HOOK_TRACE_INFO hHookEqualRect = { 0 };
ULONG HookEqualRect_ACLEntries[1] = { 0 };
BOOL fake_EqualRect(CONST RECT* lprc1,CONST RECT* lprc2){
	BOOL ret = pEqualRect(lprc1,lprc2);
	fprintf(fp,"OUT ['EqualRect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef WORD (WINAPI *GetWindowWord_fun) (HWND hWnd,int nIndex);
GetWindowWord_fun pGetWindowWord = GetWindowWord;
HOOK_TRACE_INFO hHookGetWindowWord = { 0 };
ULONG HookGetWindowWord_ACLEntries[1] = { 0 };
WORD fake_GetWindowWord(HWND hWnd,int nIndex){
	WORD ret = pGetWindowWord(hWnd,nIndex);
	fprintf(fp,"OUT ['GetWindowWord',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%hx,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(WORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%hx, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(WORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *InternalGetWindowText_fun) (HWND hWnd,LPWSTR pString,int cchMaxCount);
InternalGetWindowText_fun pInternalGetWindowText = InternalGetWindowText;
HOOK_TRACE_INFO hHookInternalGetWindowText = { 0 };
ULONG HookInternalGetWindowText_ACLEntries[1] = { 0 };
int fake_InternalGetWindowText(HWND hWnd,LPWSTR pString,int cchMaxCount){
	int ret = pInternalGetWindowText(hWnd,pString,cchMaxCount);
	fprintf(fp,"OUT ['InternalGetWindowText',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'pString',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': %p,", pString);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': %p,", pString);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),cchMaxCount, ret + 1);
 	}else 
	{
		fprintf(fp,"{'name':'pString',");
		fwprintf(fp, L"'value': %p, ", pString);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	if(pString){
		for(int i=0; i<cchMaxCount <  ret + 1 ? cchMaxCount :  ret + 1;i++){
			fprintf(fp,"0x%x,",pString[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetWindowTextW_fun) (HWND hWnd,LPCWSTR lpString);
SetWindowTextW_fun pSetWindowTextW = SetWindowTextW;
HOOK_TRACE_INFO hHookSetWindowTextW = { 0 };
ULONG HookSetWindowTextW_ACLEntries[1] = { 0 };
BOOL fake_SetWindowTextW(HWND hWnd,LPCWSTR lpString){
	BOOL ret = pSetWindowTextW(hWnd,lpString);
	fprintf(fp,"OUT ['SetWindowTextW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *GetTabbedTextExtentA_fun) (HDC hdc,LPCSTR lpString,int chCount,int nTabPositions,CONST INT* lpnTabStopPositions);
GetTabbedTextExtentA_fun pGetTabbedTextExtentA = GetTabbedTextExtentA;
HOOK_TRACE_INFO hHookGetTabbedTextExtentA = { 0 };
ULONG HookGetTabbedTextExtentA_ACLEntries[1] = { 0 };
DWORD fake_GetTabbedTextExtentA(HDC hdc,LPCSTR lpString,int chCount,int nTabPositions,CONST INT* lpnTabStopPositions){
	DWORD ret = pGetTabbedTextExtentA(hdc,lpString,chCount,nTabPositions,lpnTabStopPositions);
	fprintf(fp,"OUT ['GetTabbedTextExtentA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *GetParent_fun) (HWND hWnd);
GetParent_fun pGetParent = GetParent;
HOOK_TRACE_INFO hHookGetParent = { 0 };
ULONG HookGetParent_ACLEntries[1] = { 0 };
HWND fake_GetParent(HWND hWnd){
	HWND ret = pGetParent(hWnd);
	fprintf(fp,"OUT ['GetParent',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetIconInfoExW_fun) (HICON hicon,PICONINFOEXW piconinfo);
GetIconInfoExW_fun pGetIconInfoExW = GetIconInfoExW;
HOOK_TRACE_INFO hHookGetIconInfoExW = { 0 };
ULONG HookGetIconInfoExW_ACLEntries[1] = { 0 };
BOOL fake_GetIconInfoExW(HICON hicon,PICONINFOEXW piconinfo){
	BOOL ret = pGetIconInfoExW(hicon,piconinfo);
	fprintf(fp,"OUT ['GetIconInfoExW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'piconinfo','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",piconinfo, sizeof(PICONINFOEXW),1);
 	else fprintf(fp,"{'name':'piconinfo','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",piconinfo,sizeof(PICONINFOEXW));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *ChildWindowFromPointEx_fun) (HWND hwnd,POINT pt,UINT flags);
ChildWindowFromPointEx_fun pChildWindowFromPointEx = ChildWindowFromPointEx;
HOOK_TRACE_INFO hHookChildWindowFromPointEx = { 0 };
ULONG HookChildWindowFromPointEx_ACLEntries[1] = { 0 };
HWND fake_ChildWindowFromPointEx(HWND hwnd,POINT pt,UINT flags){
	HWND ret = pChildWindowFromPointEx(hwnd,pt,flags);
	fprintf(fp,"OUT ['ChildWindowFromPointEx',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HDWP (WINAPI *DeferWindowPos_fun) (HDWP hWinPosInfo,HWND hWnd,HWND hWndInsertAfter,int x,int y,int cx,int cy,UINT uFlags);
DeferWindowPos_fun pDeferWindowPos = DeferWindowPos;
HOOK_TRACE_INFO hHookDeferWindowPos = { 0 };
ULONG HookDeferWindowPos_ACLEntries[1] = { 0 };
HDWP fake_DeferWindowPos(HDWP hWinPosInfo,HWND hWnd,HWND hWndInsertAfter,int x,int y,int cx,int cy,UINT uFlags){
	HDWP ret = pDeferWindowPos(hWinPosInfo,hWnd,hWndInsertAfter,x,y,cx,cy,uFlags);
	fprintf(fp,"OUT ['DeferWindowPos',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HDWP),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HDWP));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *MapVirtualKeyExA_fun) (UINT uCode,UINT uMapType,HKL dwhkl);
MapVirtualKeyExA_fun pMapVirtualKeyExA = MapVirtualKeyExA;
HOOK_TRACE_INFO hHookMapVirtualKeyExA = { 0 };
ULONG HookMapVirtualKeyExA_ACLEntries[1] = { 0 };
UINT fake_MapVirtualKeyExA(UINT uCode,UINT uMapType,HKL dwhkl){
	UINT ret = pMapVirtualKeyExA(uCode,uMapType,dwhkl);
	fprintf(fp,"OUT ['MapVirtualKeyExA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *GetClassNameW_fun) (HWND hWnd,LPWSTR lpClassName,int nMaxCount);
GetClassNameW_fun pGetClassNameW = GetClassNameW;
HOOK_TRACE_INFO hHookGetClassNameW = { 0 };
ULONG HookGetClassNameW_ACLEntries[1] = { 0 };
int fake_GetClassNameW(HWND hWnd,LPWSTR lpClassName,int nMaxCount){
	int ret = pGetClassNameW(hWnd,lpClassName,nMaxCount);
	fprintf(fp,"OUT ['GetClassNameW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'lpClassName',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': %p,", lpClassName);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': %p,", lpClassName);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),nMaxCount, ret);
 	}else 
	{
		fprintf(fp,"{'name':'lpClassName',");
		fwprintf(fp, L"'value': %p, ", lpClassName);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	if(lpClassName){
		for(int i=0; i<nMaxCount <  ret ? nMaxCount :  ret;i++){
			fprintf(fp,"0x%x,",lpClassName[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *AppendMenuW_fun) (HMENU hMenu,UINT uFlags,UINT_PTR uIDNewItem,LPCWSTR lpNewItem);
AppendMenuW_fun pAppendMenuW = AppendMenuW;
HOOK_TRACE_INFO hHookAppendMenuW = { 0 };
ULONG HookAppendMenuW_ACLEntries[1] = { 0 };
BOOL fake_AppendMenuW(HMENU hMenu,UINT uFlags,UINT_PTR uIDNewItem,LPCWSTR lpNewItem){
	BOOL ret = pAppendMenuW(hMenu,uFlags,uIDNewItem,lpNewItem);
	fprintf(fp,"OUT ['AppendMenuW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HANDLE (WINAPI *LoadImageW_fun) (HINSTANCE hInst,LPCWSTR name,UINT type,int cx,int cy,UINT fuLoad);
LoadImageW_fun pLoadImageW = LoadImageW;
HOOK_TRACE_INFO hHookLoadImageW = { 0 };
ULONG HookLoadImageW_ACLEntries[1] = { 0 };
HANDLE fake_LoadImageW(HINSTANCE hInst,LPCWSTR name,UINT type,int cx,int cy,UINT fuLoad){
	HANDLE ret = pLoadImageW(hInst,name,type,cx,cy,fuLoad);
	fprintf(fp,"OUT ['LoadImageW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HANDLE),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HANDLE));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *LoadStringW_fun) (HINSTANCE hInstance,UINT uID,LPWSTR lpBuffer,int cchBufferMax);
LoadStringW_fun pLoadStringW = LoadStringW;
HOOK_TRACE_INFO hHookLoadStringW = { 0 };
ULONG HookLoadStringW_ACLEntries[1] = { 0 };
int fake_LoadStringW(HINSTANCE hInstance,UINT uID,LPWSTR lpBuffer,int cchBufferMax){
	int ret = pLoadStringW(hInstance,uID,lpBuffer,cchBufferMax);
	fprintf(fp,"OUT ['LoadStringW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'lpBuffer',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': %p,", lpBuffer);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': %p,", lpBuffer);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),cchBufferMax, ret + 1);
 	}else 
	{
		fprintf(fp,"{'name':'lpBuffer',");
		fwprintf(fp, L"'value': %p, ", lpBuffer);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	if(lpBuffer){
		for(int i=0; i<cchBufferMax <  ret + 1 ? cchBufferMax :  ret + 1;i++){
			fprintf(fp,"0x%x,",lpBuffer[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *RealChildWindowFromPoint_fun) (HWND hwndParent,POINT ptParentClientCoords);
RealChildWindowFromPoint_fun pRealChildWindowFromPoint = RealChildWindowFromPoint;
HOOK_TRACE_INFO hHookRealChildWindowFromPoint = { 0 };
ULONG HookRealChildWindowFromPoint_ACLEntries[1] = { 0 };
HWND fake_RealChildWindowFromPoint(HWND hwndParent,POINT ptParentClientCoords){
	HWND ret = pRealChildWindowFromPoint(hwndParent,ptParentClientCoords);
	fprintf(fp,"OUT ['RealChildWindowFromPoint',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *CheckRadioButton_fun) (HWND hDlg,int nIDFirstButton,int nIDLastButton,int nIDCheckButton);
CheckRadioButton_fun pCheckRadioButton = CheckRadioButton;
HOOK_TRACE_INFO hHookCheckRadioButton = { 0 };
ULONG HookCheckRadioButton_ACLEntries[1] = { 0 };
BOOL fake_CheckRadioButton(HWND hDlg,int nIDFirstButton,int nIDLastButton,int nIDCheckButton){
	BOOL ret = pCheckRadioButton(hDlg,nIDFirstButton,nIDLastButton,nIDCheckButton);
	fprintf(fp,"OUT ['CheckRadioButton',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetScrollInfo_fun) (HWND hwnd,int nBar,LPSCROLLINFO lpsi);
GetScrollInfo_fun pGetScrollInfo = GetScrollInfo;
HOOK_TRACE_INFO hHookGetScrollInfo = { 0 };
ULONG HookGetScrollInfo_ACLEntries[1] = { 0 };
BOOL fake_GetScrollInfo(HWND hwnd,int nBar,LPSCROLLINFO lpsi){
	BOOL ret = pGetScrollInfo(hwnd,nBar,lpsi);
	fprintf(fp,"OUT ['GetScrollInfo',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpsi','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpsi, sizeof(LPSCROLLINFO),1);
 	else fprintf(fp,"{'name':'lpsi','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpsi,sizeof(LPSCROLLINFO));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *GetKeyNameTextA_fun) (LONG lParam,LPSTR lpString,int cchSize);
GetKeyNameTextA_fun pGetKeyNameTextA = GetKeyNameTextA;
HOOK_TRACE_INFO hHookGetKeyNameTextA = { 0 };
ULONG HookGetKeyNameTextA_ACLEntries[1] = { 0 };
int fake_GetKeyNameTextA(LONG lParam,LPSTR lpString,int cchSize){
	int ret = pGetKeyNameTextA(lParam,lpString,cchSize);
	fprintf(fp,"OUT ['GetKeyNameTextA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpString','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpString, sizeof(LPSTR),cchSize);
 	else fprintf(fp,"{'name':'lpString','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpString,sizeof(LPSTR));
	if(lpString){
		for(int i=0; i<cchSize;i++){
			fprintf(fp,"0x%x,",lpString[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HBRUSH (WINAPI *GetSysColorBrush_fun) (int nIndex);
GetSysColorBrush_fun pGetSysColorBrush = GetSysColorBrush;
HOOK_TRACE_INFO hHookGetSysColorBrush = { 0 };
ULONG HookGetSysColorBrush_ACLEntries[1] = { 0 };
HBRUSH fake_GetSysColorBrush(int nIndex){
	HBRUSH ret = pGetSysColorBrush(nIndex);
	fprintf(fp,"OUT ['GetSysColorBrush',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HBRUSH),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HBRUSH));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HMENU (WINAPI *LoadMenuIndirectW_fun) (CONST MENUTEMPLATEW* lpMenuTemplate);
LoadMenuIndirectW_fun pLoadMenuIndirectW = LoadMenuIndirectW;
HOOK_TRACE_INFO hHookLoadMenuIndirectW = { 0 };
ULONG HookLoadMenuIndirectW_ACLEntries[1] = { 0 };
HMENU fake_LoadMenuIndirectW(CONST MENUTEMPLATEW* lpMenuTemplate){
	HMENU ret = pLoadMenuIndirectW(lpMenuTemplate);
	fprintf(fp,"OUT ['LoadMenuIndirectW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HMENU),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HMENU));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *TrackPopupMenuEx_fun) (HMENU arg0,UINT arg1,int arg2,int arg3,HWND arg4,LPTPMPARAMS arg5);
TrackPopupMenuEx_fun pTrackPopupMenuEx = TrackPopupMenuEx;
HOOK_TRACE_INFO hHookTrackPopupMenuEx = { 0 };
ULONG HookTrackPopupMenuEx_ACLEntries[1] = { 0 };
BOOL fake_TrackPopupMenuEx(HMENU arg0,UINT arg1,int arg2,int arg3,HWND arg4,LPTPMPARAMS arg5){
	BOOL ret = pTrackPopupMenuEx(arg0,arg1,arg2,arg3,arg4,arg5);
	fprintf(fp,"OUT ['TrackPopupMenuEx',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetDoubleClickTime_fun) (UINT arg0);
SetDoubleClickTime_fun pSetDoubleClickTime = SetDoubleClickTime;
HOOK_TRACE_INFO hHookSetDoubleClickTime = { 0 };
ULONG HookSetDoubleClickTime_ACLEntries[1] = { 0 };
BOOL fake_SetDoubleClickTime(UINT arg0){
	BOOL ret = pSetDoubleClickTime(arg0);
	fprintf(fp,"OUT ['SetDoubleClickTime',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsProcessDPIAware_fun) ();
IsProcessDPIAware_fun pIsProcessDPIAware = IsProcessDPIAware;
HOOK_TRACE_INFO hHookIsProcessDPIAware = { 0 };
ULONG HookIsProcessDPIAware_ACLEntries[1] = { 0 };
BOOL fake_IsProcessDPIAware(){
	BOOL ret = pIsProcessDPIAware();
	fprintf(fp,"OUT ['IsProcessDPIAware',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LRESULT (WINAPI *DefFrameProcW_fun) (HWND hWnd,HWND hWndMDIClient,UINT uMsg,WPARAM wParam,LPARAM lParam);
DefFrameProcW_fun pDefFrameProcW = DefFrameProcW;
HOOK_TRACE_INFO hHookDefFrameProcW = { 0 };
ULONG HookDefFrameProcW_ACLEntries[1] = { 0 };
LRESULT fake_DefFrameProcW(HWND hWnd,HWND hWndMDIClient,UINT uMsg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pDefFrameProcW(hWnd,hWndMDIClient,uMsg,wParam,lParam);
	fprintf(fp,"OUT ['DefFrameProcW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LRESULT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LRESULT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef SHORT (WINAPI *VkKeyScanW_fun) (WCHAR ch);
VkKeyScanW_fun pVkKeyScanW = VkKeyScanW;
HOOK_TRACE_INFO hHookVkKeyScanW = { 0 };
ULONG HookVkKeyScanW_ACLEntries[1] = { 0 };
SHORT fake_VkKeyScanW(WCHAR ch){
	SHORT ret = pVkKeyScanW(ch);
	fprintf(fp,"OUT ['VkKeyScanW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%hx,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(SHORT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%hx, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(SHORT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EnumDisplayMonitors_fun) (HDC hdc,LPCRECT lprcClip,MONITORENUMPROC lpfnEnum,LPARAM dwData);
EnumDisplayMonitors_fun pEnumDisplayMonitors = EnumDisplayMonitors;
HOOK_TRACE_INFO hHookEnumDisplayMonitors = { 0 };
ULONG HookEnumDisplayMonitors_ACLEntries[1] = { 0 };
BOOL fake_EnumDisplayMonitors(HDC hdc,LPCRECT lprcClip,MONITORENUMPROC lpfnEnum,LPARAM dwData){
	BOOL ret = pEnumDisplayMonitors(hdc,lprcClip,lpfnEnum,dwData);
	fprintf(fp,"OUT ['EnumDisplayMonitors',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HBITMAP (WINAPI *LoadBitmapW_fun) (HINSTANCE hInstance,LPCWSTR lpBitmapName);
LoadBitmapW_fun pLoadBitmapW = LoadBitmapW;
HOOK_TRACE_INFO hHookLoadBitmapW = { 0 };
ULONG HookLoadBitmapW_ACLEntries[1] = { 0 };
HBITMAP fake_LoadBitmapW(HINSTANCE hInstance,LPCWSTR lpBitmapName){
	HBITMAP ret = pLoadBitmapW(hInstance,lpBitmapName);
	fprintf(fp,"OUT ['LoadBitmapW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HBITMAP),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HBITMAP));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *HideCaret_fun) (HWND hWnd);
HideCaret_fun pHideCaret = HideCaret;
HOOK_TRACE_INFO hHookHideCaret = { 0 };
ULONG HookHideCaret_ACLEntries[1] = { 0 };
BOOL fake_HideCaret(HWND hWnd){
	BOOL ret = pHideCaret(hWnd);
	fprintf(fp,"OUT ['HideCaret',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *DrawEdge_fun) (HDC hdc,LPRECT qrc,UINT edge,UINT grfFlags);
DrawEdge_fun pDrawEdge = DrawEdge;
HOOK_TRACE_INFO hHookDrawEdge = { 0 };
ULONG HookDrawEdge_ACLEntries[1] = { 0 };
BOOL fake_DrawEdge(HDC hdc,LPRECT qrc,UINT edge,UINT grfFlags){
	BOOL ret = pDrawEdge(hdc,qrc,edge,grfFlags);
	fprintf(fp,"OUT ['DrawEdge',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'qrc','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",qrc, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'qrc','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",qrc,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *CharUpperBuffA_fun) (LPSTR lpsz,DWORD cchLength);
CharUpperBuffA_fun pCharUpperBuffA = CharUpperBuffA;
HOOK_TRACE_INFO hHookCharUpperBuffA = { 0 };
ULONG HookCharUpperBuffA_ACLEntries[1] = { 0 };
DWORD fake_CharUpperBuffA(LPSTR lpsz,DWORD cchLength){
	DWORD ret = pCharUpperBuffA(lpsz,cchLength);
	fprintf(fp,"OUT ['CharUpperBuffA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpsz','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpsz, sizeof(LPSTR),cchLength);
 	else fprintf(fp,"{'name':'lpsz','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpsz,sizeof(LPSTR));
	if(lpsz){
		for(int i=0; i<cchLength;i++){
			fprintf(fp,"0x%x,",lpsz[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef ULONG_PTR (WINAPI *SetClassLongPtrW_fun) (HWND hWnd,int nIndex,LONG_PTR dwNewLong);
SetClassLongPtrW_fun pSetClassLongPtrW = SetClassLongPtrW;
HOOK_TRACE_INFO hHookSetClassLongPtrW = { 0 };
ULONG HookSetClassLongPtrW_ACLEntries[1] = { 0 };
ULONG_PTR fake_SetClassLongPtrW(HWND hWnd,int nIndex,LONG_PTR dwNewLong){
	ULONG_PTR ret = pSetClassLongPtrW(hWnd,nIndex,dwNewLong);
	fprintf(fp,"OUT ['SetClassLongPtrW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(ULONG_PTR),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(ULONG_PTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EnumWindowStationsW_fun) (WINSTAENUMPROCW lpEnumFunc,LPARAM lParam);
EnumWindowStationsW_fun pEnumWindowStationsW = EnumWindowStationsW;
HOOK_TRACE_INFO hHookEnumWindowStationsW = { 0 };
ULONG HookEnumWindowStationsW_ACLEntries[1] = { 0 };
BOOL fake_EnumWindowStationsW(WINSTAENUMPROCW lpEnumFunc,LPARAM lParam){
	BOOL ret = pEnumWindowStationsW(lpEnumFunc,lParam);
	fprintf(fp,"OUT ['EnumWindowStationsW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EnumDisplaySettingsExA_fun) (LPCSTR lpszDeviceName,DWORD iModeNum,DEVMODEA*  lpDevMode,DWORD dwFlags);
EnumDisplaySettingsExA_fun pEnumDisplaySettingsExA = EnumDisplaySettingsExA;
HOOK_TRACE_INFO hHookEnumDisplaySettingsExA = { 0 };
ULONG HookEnumDisplaySettingsExA_ACLEntries[1] = { 0 };
BOOL fake_EnumDisplaySettingsExA(LPCSTR lpszDeviceName,DWORD iModeNum,DEVMODEA*  lpDevMode,DWORD dwFlags){
	BOOL ret = pEnumDisplaySettingsExA(lpszDeviceName,iModeNum, lpDevMode,dwFlags);
	fprintf(fp,"OUT ['EnumDisplaySettingsExA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':' lpDevMode','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[", lpDevMode, sizeof(DEVMODEA*),1);
 	else fprintf(fp,"{'name':' lpDevMode','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[", lpDevMode,sizeof(DEVMODEA*));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetMenuItemRect_fun) (HWND hWnd,HMENU hMenu,UINT uItem,LPRECT lprcItem);
GetMenuItemRect_fun pGetMenuItemRect = GetMenuItemRect;
HOOK_TRACE_INFO hHookGetMenuItemRect = { 0 };
ULONG HookGetMenuItemRect_ACLEntries[1] = { 0 };
BOOL fake_GetMenuItemRect(HWND hWnd,HMENU hMenu,UINT uItem,LPRECT lprcItem){
	BOOL ret = pGetMenuItemRect(hWnd,hMenu,uItem,lprcItem);
	fprintf(fp,"OUT ['GetMenuItemRect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lprcItem','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lprcItem, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'lprcItem','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lprcItem,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ReplyMessage_fun) (LRESULT lResult);
ReplyMessage_fun pReplyMessage = ReplyMessage;
HOOK_TRACE_INFO hHookReplyMessage = { 0 };
ULONG HookReplyMessage_ACLEntries[1] = { 0 };
BOOL fake_ReplyMessage(LRESULT lResult){
	BOOL ret = pReplyMessage(lResult);
	fprintf(fp,"OUT ['ReplyMessage',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *AnimateWindow_fun) (HWND hWnd,DWORD dwTime,DWORD dwFlags);
AnimateWindow_fun pAnimateWindow = AnimateWindow;
HOOK_TRACE_INFO hHookAnimateWindow = { 0 };
ULONG HookAnimateWindow_ACLEntries[1] = { 0 };
BOOL fake_AnimateWindow(HWND hWnd,DWORD dwTime,DWORD dwFlags){
	BOOL ret = pAnimateWindow(hWnd,dwTime,dwFlags);
	fprintf(fp,"OUT ['AnimateWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *SendInput_fun) (UINT cInputs,LPINPUT pInputs,int cbSize);
SendInput_fun pSendInput = SendInput;
HOOK_TRACE_INFO hHookSendInput = { 0 };
ULONG HookSendInput_ACLEntries[1] = { 0 };
UINT fake_SendInput(UINT cInputs,LPINPUT pInputs,int cbSize){
	UINT ret = pSendInput(cInputs,pInputs,cbSize);
	fprintf(fp,"OUT ['SendInput',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EnableScrollBar_fun) (HWND hWnd,UINT wSBflags,UINT wArrows);
EnableScrollBar_fun pEnableScrollBar = EnableScrollBar;
HOOK_TRACE_INFO hHookEnableScrollBar = { 0 };
ULONG HookEnableScrollBar_ACLEntries[1] = { 0 };
BOOL fake_EnableScrollBar(HWND hWnd,UINT wSBflags,UINT wArrows){
	BOOL ret = pEnableScrollBar(hWnd,wSBflags,wArrows);
	fprintf(fp,"OUT ['EnableScrollBar',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *GetMenuDefaultItem_fun) (HMENU hMenu,UINT fByPos,UINT gmdiFlags);
GetMenuDefaultItem_fun pGetMenuDefaultItem = GetMenuDefaultItem;
HOOK_TRACE_INFO hHookGetMenuDefaultItem = { 0 };
ULONG HookGetMenuDefaultItem_ACLEntries[1] = { 0 };
UINT fake_GetMenuDefaultItem(HMENU hMenu,UINT fByPos,UINT gmdiFlags){
	UINT ret = pGetMenuDefaultItem(hMenu,fByPos,gmdiFlags);
	fprintf(fp,"OUT ['GetMenuDefaultItem',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *EnumPropsA_fun) (HWND hWnd,PROPENUMPROCA lpEnumFunc);
EnumPropsA_fun pEnumPropsA = EnumPropsA;
HOOK_TRACE_INFO hHookEnumPropsA = { 0 };
ULONG HookEnumPropsA_ACLEntries[1] = { 0 };
int fake_EnumPropsA(HWND hWnd,PROPENUMPROCA lpEnumFunc){
	int ret = pEnumPropsA(hWnd,lpEnumFunc);
	fprintf(fp,"OUT ['EnumPropsA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *TranslateMessage_fun) (CONST MSG* lpMsg);
TranslateMessage_fun pTranslateMessage = TranslateMessage;
HOOK_TRACE_INFO hHookTranslateMessage = { 0 };
ULONG HookTranslateMessage_ACLEntries[1] = { 0 };
BOOL fake_TranslateMessage(CONST MSG* lpMsg){
	BOOL ret = pTranslateMessage(lpMsg);
	fprintf(fp,"OUT ['TranslateMessage',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LPSTR (WINAPI *CharNextA_fun) (LPCSTR lpsz);
CharNextA_fun pCharNextA = CharNextA;
HOOK_TRACE_INFO hHookCharNextA = { 0 };
ULONG HookCharNextA_ACLEntries[1] = { 0 };
LPSTR fake_CharNextA(LPCSTR lpsz){
	LPSTR ret = pCharNextA(lpsz);
	fprintf(fp,"OUT ['CharNextA',");
	if(1) fprintf(fp,"{'name':'ret','value': '\"%s\"','size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LPSTR),1);
 	else fprintf(fp,"{'name':'ret','value': '\"%s\"', 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LPSTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *GetForegroundWindow_fun) ();
GetForegroundWindow_fun pGetForegroundWindow = GetForegroundWindow;
HOOK_TRACE_INFO hHookGetForegroundWindow = { 0 };
ULONG HookGetForegroundWindow_ACLEntries[1] = { 0 };
HWND fake_GetForegroundWindow(){
	HWND ret = pGetForegroundWindow();
	fprintf(fp,"OUT ['GetForegroundWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LPSTR (WINAPI *CharLowerA_fun) (LPSTR lpsz);
CharLowerA_fun pCharLowerA = CharLowerA;
HOOK_TRACE_INFO hHookCharLowerA = { 0 };
ULONG HookCharLowerA_ACLEntries[1] = { 0 };
LPSTR fake_CharLowerA(LPSTR lpsz){
	LPSTR ret = pCharLowerA(lpsz);
	fprintf(fp,"OUT ['CharLowerA',");
	if(1) fprintf(fp,"{'name':'ret','value': '\"%s\"','size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LPSTR),1);
 	else fprintf(fp,"{'name':'ret','value': '\"%s\"', 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LPSTR));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpsz','value': '\"%s\"','size' : 0x%lx,'cnt':0x%x, 'data':[",lpsz, sizeof(LPSTR),1);
 	else fprintf(fp,"{'name':'lpsz','value': '\"%s\"', 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpsz,sizeof(LPSTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsRectEmpty_fun) (CONST RECT* lprc);
IsRectEmpty_fun pIsRectEmpty = IsRectEmpty;
HOOK_TRACE_INFO hHookIsRectEmpty = { 0 };
ULONG HookIsRectEmpty_ACLEntries[1] = { 0 };
BOOL fake_IsRectEmpty(CONST RECT* lprc){
	BOOL ret = pIsRectEmpty(lprc);
	fprintf(fp,"OUT ['IsRectEmpty',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *OpenClipboard_fun) (HWND hWndNewOwner);
OpenClipboard_fun pOpenClipboard = OpenClipboard;
HOOK_TRACE_INFO hHookOpenClipboard = { 0 };
ULONG HookOpenClipboard_ACLEntries[1] = { 0 };
BOOL fake_OpenClipboard(HWND hWndNewOwner){
	BOOL ret = pOpenClipboard(hWndNewOwner);
	fprintf(fp,"OUT ['OpenClipboard',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *GetKeyboardLayoutList_fun) (int nBuff,HKL* lpList);
GetKeyboardLayoutList_fun pGetKeyboardLayoutList = GetKeyboardLayoutList;
HOOK_TRACE_INFO hHookGetKeyboardLayoutList = { 0 };
ULONG HookGetKeyboardLayoutList_ACLEntries[1] = { 0 };
int fake_GetKeyboardLayoutList(int nBuff,HKL* lpList){
	int ret = pGetKeyboardLayoutList(nBuff,lpList);
	fprintf(fp,"OUT ['GetKeyboardLayoutList',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpList','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpList, sizeof(HKL*),nBuff, ret);
 	else fprintf(fp,"{'name':'lpList','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpList,sizeof(HKL*));
	if(lpList){
		for(int i=0; i<nBuff <  ret ? nBuff :  ret;i++){
			fprintf(fp,"0x%x,",lpList[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HICON (WINAPI *CopyIcon_fun) (HICON hIcon);
CopyIcon_fun pCopyIcon = CopyIcon;
HOOK_TRACE_INFO hHookCopyIcon = { 0 };
ULONG HookCopyIcon_ACLEntries[1] = { 0 };
HICON fake_CopyIcon(HICON hIcon){
	HICON ret = pCopyIcon(hIcon);
	fprintf(fp,"OUT ['CopyIcon',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HICON),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HICON));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *DlgDirListA_fun) (HWND hDlg,LPSTR lpPathSpec,int nIDListBox,int nIDStaticPath,UINT uFileType);
DlgDirListA_fun pDlgDirListA = DlgDirListA;
HOOK_TRACE_INFO hHookDlgDirListA = { 0 };
ULONG HookDlgDirListA_ACLEntries[1] = { 0 };
int fake_DlgDirListA(HWND hDlg,LPSTR lpPathSpec,int nIDListBox,int nIDStaticPath,UINT uFileType){
	int ret = pDlgDirListA(hDlg,lpPathSpec,nIDListBox,nIDStaticPath,uFileType);
	fprintf(fp,"OUT ['DlgDirListA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpPathSpec','value': '\"%s\"','size' : 0x%lx,'cnt':0x%x, 'data':[",lpPathSpec, sizeof(LPSTR),1);
 	else fprintf(fp,"{'name':'lpPathSpec','value': '\"%s\"', 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpPathSpec,sizeof(LPSTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *RedrawWindow_fun) (HWND hWnd,CONST RECT* lprcUpdate,HRGN hrgnUpdate,UINT flags);
RedrawWindow_fun pRedrawWindow = RedrawWindow;
HOOK_TRACE_INFO hHookRedrawWindow = { 0 };
ULONG HookRedrawWindow_ACLEntries[1] = { 0 };
BOOL fake_RedrawWindow(HWND hWnd,CONST RECT* lprcUpdate,HRGN hrgnUpdate,UINT flags){
	BOOL ret = pRedrawWindow(hWnd,lprcUpdate,hrgnUpdate,flags);
	fprintf(fp,"OUT ['RedrawWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EndDialog_fun) (HWND hDlg,INT_PTR nResult);
EndDialog_fun pEndDialog = EndDialog;
HOOK_TRACE_INFO hHookEndDialog = { 0 };
ULONG HookEndDialog_ACLEntries[1] = { 0 };
BOOL fake_EndDialog(HWND hDlg,INT_PTR nResult){
	BOOL ret = pEndDialog(hDlg,nResult);
	fprintf(fp,"OUT ['EndDialog',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *MessageBeep_fun) (UINT uType);
MessageBeep_fun pMessageBeep = MessageBeep;
HOOK_TRACE_INFO hHookMessageBeep = { 0 };
ULONG HookMessageBeep_ACLEntries[1] = { 0 };
BOOL fake_MessageBeep(UINT uType){
	BOOL ret = pMessageBeep(uType);
	fprintf(fp,"OUT ['MessageBeep',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *CloseWindowStation_fun) (HWINSTA hWinSta);
CloseWindowStation_fun pCloseWindowStation = CloseWindowStation;
HOOK_TRACE_INFO hHookCloseWindowStation = { 0 };
ULONG HookCloseWindowStation_ACLEntries[1] = { 0 };
BOOL fake_CloseWindowStation(HWINSTA hWinSta){
	BOOL ret = pCloseWindowStation(hWinSta);
	fprintf(fp,"OUT ['CloseWindowStation',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef WORD (WINAPI *GetClassWord_fun) (HWND hWnd,int nIndex);
GetClassWord_fun pGetClassWord = GetClassWord;
HOOK_TRACE_INFO hHookGetClassWord = { 0 };
ULONG HookGetClassWord_ACLEntries[1] = { 0 };
WORD fake_GetClassWord(HWND hWnd,int nIndex){
	WORD ret = pGetClassWord(hWnd,nIndex);
	fprintf(fp,"OUT ['GetClassWord',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%hx,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(WORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%hx, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(WORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HDESK (WINAPI *CreateDesktopExA_fun) (LPCSTR lpszDesktop,LPCSTR lpszDevice,DEVMODEA*  pDevmode,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa,ULONG ulHeapSize,PVOID pvoid);
CreateDesktopExA_fun pCreateDesktopExA = CreateDesktopExA;
HOOK_TRACE_INFO hHookCreateDesktopExA = { 0 };
ULONG HookCreateDesktopExA_ACLEntries[1] = { 0 };
HDESK fake_CreateDesktopExA(LPCSTR lpszDesktop,LPCSTR lpszDevice,DEVMODEA*  pDevmode,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa,ULONG ulHeapSize,PVOID pvoid){
	HDESK ret = pCreateDesktopExA(lpszDesktop,lpszDevice, pDevmode,dwFlags,dwDesiredAccess,lpsa,ulHeapSize,pvoid);
	fprintf(fp,"OUT ['CreateDesktopExA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HDESK),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HDESK));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HMENU (WINAPI *GetSystemMenu_fun) (HWND hWnd,BOOL bRevert);
GetSystemMenu_fun pGetSystemMenu = GetSystemMenu;
HOOK_TRACE_INFO hHookGetSystemMenu = { 0 };
ULONG HookGetSystemMenu_ACLEntries[1] = { 0 };
HMENU fake_GetSystemMenu(HWND hWnd,BOOL bRevert){
	HMENU ret = pGetSystemMenu(hWnd,bRevert);
	fprintf(fp,"OUT ['GetSystemMenu',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HMENU),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HMENU));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *RegisterWindowMessageA_fun) (LPCSTR lpString);
RegisterWindowMessageA_fun pRegisterWindowMessageA = RegisterWindowMessageA;
HOOK_TRACE_INFO hHookRegisterWindowMessageA = { 0 };
ULONG HookRegisterWindowMessageA_ACLEntries[1] = { 0 };
UINT fake_RegisterWindowMessageA(LPCSTR lpString){
	UINT ret = pRegisterWindowMessageA(lpString);
	fprintf(fp,"OUT ['RegisterWindowMessageA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *GetRegisteredRawInputDevices_fun) (PRAWINPUTDEVICE pRawInputDevices,PUINT puiNumDevices,UINT cbSize);
GetRegisteredRawInputDevices_fun pGetRegisteredRawInputDevices = GetRegisteredRawInputDevices;
HOOK_TRACE_INFO hHookGetRegisteredRawInputDevices = { 0 };
ULONG HookGetRegisteredRawInputDevices_ACLEntries[1] = { 0 };
UINT fake_GetRegisteredRawInputDevices(PRAWINPUTDEVICE pRawInputDevices,PUINT puiNumDevices,UINT cbSize){
	UINT ret = pGetRegisteredRawInputDevices(pRawInputDevices,puiNumDevices,cbSize);
	fprintf(fp,"OUT ['GetRegisteredRawInputDevices',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pRawInputDevices','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pRawInputDevices, sizeof(PRAWINPUTDEVICE), *puiNumDevices);
 	else fprintf(fp,"{'name':'pRawInputDevices','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pRawInputDevices,sizeof(PRAWINPUTDEVICE));
	if(pRawInputDevices){
		for(int i=0; i< *puiNumDevices;i++){
			fprintf(fp,"0x%x,",pRawInputDevices[i]);
		}
	}
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'puiNumDevices','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",puiNumDevices, sizeof(PUINT),1);
 	else fprintf(fp,"{'name':'puiNumDevices','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",puiNumDevices,sizeof(PUINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HICON (WINAPI *LoadIconW_fun) (HINSTANCE hInstance,LPCWSTR lpIconName);
LoadIconW_fun pLoadIconW = LoadIconW;
HOOK_TRACE_INFO hHookLoadIconW = { 0 };
ULONG HookLoadIconW_ACLEntries[1] = { 0 };
HICON fake_LoadIconW(HINSTANCE hInstance,LPCWSTR lpIconName){
	HICON ret = pLoadIconW(hInstance,lpIconName);
	fprintf(fp,"OUT ['LoadIconW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HICON),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HICON));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *GetWindowContextHelpId_fun) (HWND arg0);
GetWindowContextHelpId_fun pGetWindowContextHelpId = GetWindowContextHelpId;
HOOK_TRACE_INFO hHookGetWindowContextHelpId = { 0 };
ULONG HookGetWindowContextHelpId_ACLEntries[1] = { 0 };
DWORD fake_GetWindowContextHelpId(HWND arg0){
	DWORD ret = pGetWindowContextHelpId(arg0);
	fprintf(fp,"OUT ['GetWindowContextHelpId',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef long (WINAPI *BroadcastSystemMessageW_fun) (DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam);
BroadcastSystemMessageW_fun pBroadcastSystemMessageW = BroadcastSystemMessageW;
HOOK_TRACE_INFO hHookBroadcastSystemMessageW = { 0 };
ULONG HookBroadcastSystemMessageW_ACLEntries[1] = { 0 };
long fake_BroadcastSystemMessageW(DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam){
	long ret = pBroadcastSystemMessageW(flags,lpInfo,Msg,wParam,lParam);
	fprintf(fp,"OUT ['BroadcastSystemMessageW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%llx,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(long),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%llx, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(long));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpInfo','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpInfo, sizeof(LPDWORD),1);
 	else fprintf(fp,"{'name':'lpInfo','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpInfo,sizeof(LPDWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EnumDesktopsW_fun) (HWINSTA hwinsta,DESKTOPENUMPROCW lpEnumFunc,LPARAM lParam);
EnumDesktopsW_fun pEnumDesktopsW = EnumDesktopsW;
HOOK_TRACE_INFO hHookEnumDesktopsW = { 0 };
ULONG HookEnumDesktopsW_ACLEntries[1] = { 0 };
BOOL fake_EnumDesktopsW(HWINSTA hwinsta,DESKTOPENUMPROCW lpEnumFunc,LPARAM lParam){
	BOOL ret = pEnumDesktopsW(hwinsta,lpEnumFunc,lParam);
	fprintf(fp,"OUT ['EnumDesktopsW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef ULONG_PTR (WINAPI *SetClassLongPtrA_fun) (HWND hWnd,int nIndex,LONG_PTR dwNewLong);
SetClassLongPtrA_fun pSetClassLongPtrA = SetClassLongPtrA;
HOOK_TRACE_INFO hHookSetClassLongPtrA = { 0 };
ULONG HookSetClassLongPtrA_ACLEntries[1] = { 0 };
ULONG_PTR fake_SetClassLongPtrA(HWND hWnd,int nIndex,LONG_PTR dwNewLong){
	ULONG_PTR ret = pSetClassLongPtrA(hWnd,nIndex,dwNewLong);
	fprintf(fp,"OUT ['SetClassLongPtrA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(ULONG_PTR),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(ULONG_PTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *MsgWaitForMultipleObjectsEx_fun) (DWORD nCount,CONST HANDLE* pHandles,DWORD dwMilliseconds,DWORD dwWakeMask,DWORD dwFlags);
MsgWaitForMultipleObjectsEx_fun pMsgWaitForMultipleObjectsEx = MsgWaitForMultipleObjectsEx;
HOOK_TRACE_INFO hHookMsgWaitForMultipleObjectsEx = { 0 };
ULONG HookMsgWaitForMultipleObjectsEx_ACLEntries[1] = { 0 };
DWORD fake_MsgWaitForMultipleObjectsEx(DWORD nCount,CONST HANDLE* pHandles,DWORD dwMilliseconds,DWORD dwWakeMask,DWORD dwFlags){
	DWORD ret = pMsgWaitForMultipleObjectsEx(nCount,pHandles,dwMilliseconds,dwWakeMask,dwFlags);
	fprintf(fp,"OUT ['MsgWaitForMultipleObjectsEx',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *UnregisterTouchWindow_fun) (HWND hwnd);
UnregisterTouchWindow_fun pUnregisterTouchWindow = UnregisterTouchWindow;
HOOK_TRACE_INFO hHookUnregisterTouchWindow = { 0 };
ULONG HookUnregisterTouchWindow_ACLEntries[1] = { 0 };
BOOL fake_UnregisterTouchWindow(HWND hwnd){
	BOOL ret = pUnregisterTouchWindow(hwnd);
	fprintf(fp,"OUT ['UnregisterTouchWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *GetClassNameA_fun) (HWND hWnd,LPSTR lpClassName,int nMaxCount);
GetClassNameA_fun pGetClassNameA = GetClassNameA;
HOOK_TRACE_INFO hHookGetClassNameA = { 0 };
ULONG HookGetClassNameA_ACLEntries[1] = { 0 };
int fake_GetClassNameA(HWND hWnd,LPSTR lpClassName,int nMaxCount){
	int ret = pGetClassNameA(hWnd,lpClassName,nMaxCount);
	fprintf(fp,"OUT ['GetClassNameA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpClassName','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpClassName, sizeof(LPSTR),nMaxCount, ret);
 	else fprintf(fp,"{'name':'lpClassName','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpClassName,sizeof(LPSTR));
	if(lpClassName){
		for(int i=0; i<nMaxCount <  ret ? nMaxCount :  ret;i++){
			fprintf(fp,"0x%x,",lpClassName[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsCharAlphaNumericW_fun) (WCHAR ch);
IsCharAlphaNumericW_fun pIsCharAlphaNumericW = IsCharAlphaNumericW;
HOOK_TRACE_INFO hHookIsCharAlphaNumericW = { 0 };
ULONG HookIsCharAlphaNumericW_ACLEntries[1] = { 0 };
BOOL fake_IsCharAlphaNumericW(WCHAR ch){
	BOOL ret = pIsCharAlphaNumericW(ch);
	fprintf(fp,"OUT ['IsCharAlphaNumericW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetUserObjectSecurity_fun) (HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID);
SetUserObjectSecurity_fun pSetUserObjectSecurity = SetUserObjectSecurity;
HOOK_TRACE_INFO hHookSetUserObjectSecurity = { 0 };
ULONG HookSetUserObjectSecurity_ACLEntries[1] = { 0 };
BOOL fake_SetUserObjectSecurity(HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID){
	BOOL ret = pSetUserObjectSecurity(hObj,pSIRequested,pSID);
	fprintf(fp,"OUT ['SetUserObjectSecurity',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EnumDisplaySettingsExW_fun) (LPCWSTR lpszDeviceName,DWORD iModeNum,DEVMODEW*  lpDevMode,DWORD dwFlags);
EnumDisplaySettingsExW_fun pEnumDisplaySettingsExW = EnumDisplaySettingsExW;
HOOK_TRACE_INFO hHookEnumDisplaySettingsExW = { 0 };
ULONG HookEnumDisplaySettingsExW_ACLEntries[1] = { 0 };
BOOL fake_EnumDisplaySettingsExW(LPCWSTR lpszDeviceName,DWORD iModeNum,DEVMODEW*  lpDevMode,DWORD dwFlags){
	BOOL ret = pEnumDisplaySettingsExW(lpszDeviceName,iModeNum, lpDevMode,dwFlags);
	fprintf(fp,"OUT ['EnumDisplaySettingsExW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':' lpDevMode','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[", lpDevMode, sizeof(DEVMODEW*),1);
 	else fprintf(fp,"{'name':' lpDevMode','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[", lpDevMode,sizeof(DEVMODEW*));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *PaintDesktop_fun) (HDC hdc);
PaintDesktop_fun pPaintDesktop = PaintDesktop;
HOOK_TRACE_INFO hHookPaintDesktop = { 0 };
ULONG HookPaintDesktop_ACLEntries[1] = { 0 };
BOOL fake_PaintDesktop(HDC hdc){
	BOOL ret = pPaintDesktop(hdc);
	fprintf(fp,"OUT ['PaintDesktop',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef VOID (WINAPI *SetLastErrorEx_fun) (DWORD dwErrCode,DWORD dwType);
SetLastErrorEx_fun pSetLastErrorEx = SetLastErrorEx;
HOOK_TRACE_INFO hHookSetLastErrorEx = { 0 };
ULONG HookSetLastErrorEx_ACLEntries[1] = { 0 };
VOID fake_SetLastErrorEx(DWORD dwErrCode,DWORD dwType){
	pSetLastErrorEx(dwErrCode,dwType);
	fprintf(fp,"OUT ['SetLastErrorEx',");
	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
}


typedef BOOL (WINAPI *IsDialogMessageW_fun) (HWND hDlg,LPMSG lpMsg);
IsDialogMessageW_fun pIsDialogMessageW = IsDialogMessageW;
HOOK_TRACE_INFO hHookIsDialogMessageW = { 0 };
ULONG HookIsDialogMessageW_ACLEntries[1] = { 0 };
BOOL fake_IsDialogMessageW(HWND hDlg,LPMSG lpMsg){
	BOOL ret = pIsDialogMessageW(hDlg,lpMsg);
	fprintf(fp,"OUT ['IsDialogMessageW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EnumDisplayDevicesW_fun) (LPCWSTR lpDevice,DWORD iDevNum,PDISPLAY_DEVICEW lpDisplayDevice,DWORD dwFlags);
EnumDisplayDevicesW_fun pEnumDisplayDevicesW = EnumDisplayDevicesW;
HOOK_TRACE_INFO hHookEnumDisplayDevicesW = { 0 };
ULONG HookEnumDisplayDevicesW_ACLEntries[1] = { 0 };
BOOL fake_EnumDisplayDevicesW(LPCWSTR lpDevice,DWORD iDevNum,PDISPLAY_DEVICEW lpDisplayDevice,DWORD dwFlags){
	BOOL ret = pEnumDisplayDevicesW(lpDevice,iDevNum,lpDisplayDevice,dwFlags);
	fprintf(fp,"OUT ['EnumDisplayDevicesW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpDisplayDevice','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpDisplayDevice, sizeof(PDISPLAY_DEVICEW),1);
 	else fprintf(fp,"{'name':'lpDisplayDevice','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpDisplayDevice,sizeof(PDISPLAY_DEVICEW));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetPhysicalCursorPos_fun) (LPPOINT lpPoint);
GetPhysicalCursorPos_fun pGetPhysicalCursorPos = GetPhysicalCursorPos;
HOOK_TRACE_INFO hHookGetPhysicalCursorPos = { 0 };
ULONG HookGetPhysicalCursorPos_ACLEntries[1] = { 0 };
BOOL fake_GetPhysicalCursorPos(LPPOINT lpPoint){
	BOOL ret = pGetPhysicalCursorPos(lpPoint);
	fprintf(fp,"OUT ['GetPhysicalCursorPos',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpPoint','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpPoint, sizeof(LPPOINT),1);
 	else fprintf(fp,"{'name':'lpPoint','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpPoint,sizeof(LPPOINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *GetRawInputDeviceInfoW_fun) (HANDLE hDevice,UINT uiCommand,LPVOID pData,PUINT pcbSize);
GetRawInputDeviceInfoW_fun pGetRawInputDeviceInfoW = GetRawInputDeviceInfoW;
HOOK_TRACE_INFO hHookGetRawInputDeviceInfoW = { 0 };
ULONG HookGetRawInputDeviceInfoW_ACLEntries[1] = { 0 };
UINT fake_GetRawInputDeviceInfoW(HANDLE hDevice,UINT uiCommand,LPVOID pData,PUINT pcbSize){
	UINT ret = pGetRawInputDeviceInfoW(hDevice,uiCommand,pData,pcbSize);
	fprintf(fp,"OUT ['GetRawInputDeviceInfoW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pData','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pData, sizeof(LPVOID),1);
 	else fprintf(fp,"{'name':'pData','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pData,sizeof(LPVOID));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pcbSize','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pcbSize, sizeof(PUINT),1);
 	else fprintf(fp,"{'name':'pcbSize','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pcbSize,sizeof(PUINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *GetWindowModuleFileNameA_fun) (HWND hwnd,LPSTR pszFileName,UINT cchFileNameMax);
GetWindowModuleFileNameA_fun pGetWindowModuleFileNameA = GetWindowModuleFileNameA;
HOOK_TRACE_INFO hHookGetWindowModuleFileNameA = { 0 };
ULONG HookGetWindowModuleFileNameA_ACLEntries[1] = { 0 };
UINT fake_GetWindowModuleFileNameA(HWND hwnd,LPSTR pszFileName,UINT cchFileNameMax){
	UINT ret = pGetWindowModuleFileNameA(hwnd,pszFileName,cchFileNameMax);
	fprintf(fp,"OUT ['GetWindowModuleFileNameA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pszFileName','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pszFileName, sizeof(LPSTR),cchFileNameMax, ret);
 	else fprintf(fp,"{'name':'pszFileName','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pszFileName,sizeof(LPSTR));
	if(pszFileName){
		for(int i=0; i<cchFileNameMax <  ret ? cchFileNameMax :  ret;i++){
			fprintf(fp,"0x%x,",pszFileName[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef VOID (WINAPI *DisableProcessWindowsGhosting_fun) ();
DisableProcessWindowsGhosting_fun pDisableProcessWindowsGhosting = DisableProcessWindowsGhosting;
HOOK_TRACE_INFO hHookDisableProcessWindowsGhosting = { 0 };
ULONG HookDisableProcessWindowsGhosting_ACLEntries[1] = { 0 };
VOID fake_DisableProcessWindowsGhosting(){
	pDisableProcessWindowsGhosting();
	fprintf(fp,"OUT ['DisableProcessWindowsGhosting',");
	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
}


typedef BOOL (WINAPI *SubtractRect_fun) (LPRECT lprcDst,CONST RECT* lprcSrc1,CONST RECT* lprcSrc2);
SubtractRect_fun pSubtractRect = SubtractRect;
HOOK_TRACE_INFO hHookSubtractRect = { 0 };
ULONG HookSubtractRect_ACLEntries[1] = { 0 };
BOOL fake_SubtractRect(LPRECT lprcDst,CONST RECT* lprcSrc1,CONST RECT* lprcSrc2){
	BOOL ret = pSubtractRect(lprcDst,lprcSrc1,lprcSrc2);
	fprintf(fp,"OUT ['SubtractRect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lprcDst','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lprcDst, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'lprcDst','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lprcDst,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *FlashWindow_fun) (HWND hWnd,BOOL bInvert);
FlashWindow_fun pFlashWindow = FlashWindow;
HOOK_TRACE_INFO hHookFlashWindow = { 0 };
ULONG HookFlashWindow_ACLEntries[1] = { 0 };
BOOL fake_FlashWindow(HWND hWnd,BOOL bInvert){
	BOOL ret = pFlashWindow(hWnd,bInvert);
	fprintf(fp,"OUT ['FlashWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LONG (WINAPI *DisplayConfigGetDeviceInfo_fun) (DISPLAYCONFIG_DEVICE_INFO_HEADER*  requestPacket);
DisplayConfigGetDeviceInfo_fun pDisplayConfigGetDeviceInfo = DisplayConfigGetDeviceInfo;
HOOK_TRACE_INFO hHookDisplayConfigGetDeviceInfo = { 0 };
ULONG HookDisplayConfigGetDeviceInfo_ACLEntries[1] = { 0 };
LONG fake_DisplayConfigGetDeviceInfo(DISPLAYCONFIG_DEVICE_INFO_HEADER*  requestPacket){
	LONG ret = pDisplayConfigGetDeviceInfo( requestPacket);
	fprintf(fp,"OUT ['DisplayConfigGetDeviceInfo',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LONG),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LONG));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':' requestPacket','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[", requestPacket, sizeof(DISPLAYCONFIG_DEVICE_INFO_HEADER*),1);
 	else fprintf(fp,"{'name':' requestPacket','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[", requestPacket,sizeof(DISPLAYCONFIG_DEVICE_INFO_HEADER*));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetForegroundWindow_fun) (HWND hWnd);
SetForegroundWindow_fun pSetForegroundWindow = SetForegroundWindow;
HOOK_TRACE_INFO hHookSetForegroundWindow = { 0 };
ULONG HookSetForegroundWindow_ACLEntries[1] = { 0 };
BOOL fake_SetForegroundWindow(HWND hWnd){
	BOOL ret = pSetForegroundWindow(hWnd);
	fprintf(fp,"OUT ['SetForegroundWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWINSTA (WINAPI *CreateWindowStationW_fun) (LPCWSTR lpwinsta,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa);
CreateWindowStationW_fun pCreateWindowStationW = CreateWindowStationW;
HOOK_TRACE_INFO hHookCreateWindowStationW = { 0 };
ULONG HookCreateWindowStationW_ACLEntries[1] = { 0 };
HWINSTA fake_CreateWindowStationW(LPCWSTR lpwinsta,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa){
	HWINSTA ret = pCreateWindowStationW(lpwinsta,dwFlags,dwDesiredAccess,lpsa);
	fprintf(fp,"OUT ['CreateWindowStationW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWINSTA),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWINSTA));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *OffsetRect_fun) (LPRECT lprc,int dx,int dy);
OffsetRect_fun pOffsetRect = OffsetRect;
HOOK_TRACE_INFO hHookOffsetRect = { 0 };
ULONG HookOffsetRect_ACLEntries[1] = { 0 };
BOOL fake_OffsetRect(LPRECT lprc,int dx,int dy){
	BOOL ret = pOffsetRect(lprc,dx,dy);
	fprintf(fp,"OUT ['OffsetRect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lprc','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lprc, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'lprc','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lprc,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *DlgDirListComboBoxA_fun) (HWND hDlg,LPSTR lpPathSpec,int nIDComboBox,int nIDStaticPath,UINT uFiletype);
DlgDirListComboBoxA_fun pDlgDirListComboBoxA = DlgDirListComboBoxA;
HOOK_TRACE_INFO hHookDlgDirListComboBoxA = { 0 };
ULONG HookDlgDirListComboBoxA_ACLEntries[1] = { 0 };
int fake_DlgDirListComboBoxA(HWND hDlg,LPSTR lpPathSpec,int nIDComboBox,int nIDStaticPath,UINT uFiletype){
	int ret = pDlgDirListComboBoxA(hDlg,lpPathSpec,nIDComboBox,nIDStaticPath,uFiletype);
	fprintf(fp,"OUT ['DlgDirListComboBoxA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpPathSpec','value': '\"%s\"','size' : 0x%lx,'cnt':0x%x, 'data':[",lpPathSpec, sizeof(LPSTR),1);
 	else fprintf(fp,"{'name':'lpPathSpec','value': '\"%s\"', 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpPathSpec,sizeof(LPSTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetMenuItemInfoW_fun) (HMENU hmenu,UINT item,BOOL fByPosition,LPMENUITEMINFOW lpmii);
GetMenuItemInfoW_fun pGetMenuItemInfoW = GetMenuItemInfoW;
HOOK_TRACE_INFO hHookGetMenuItemInfoW = { 0 };
ULONG HookGetMenuItemInfoW_ACLEntries[1] = { 0 };
BOOL fake_GetMenuItemInfoW(HMENU hmenu,UINT item,BOOL fByPosition,LPMENUITEMINFOW lpmii){
	BOOL ret = pGetMenuItemInfoW(hmenu,item,fByPosition,lpmii);
	fprintf(fp,"OUT ['GetMenuItemInfoW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpmii','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpmii, sizeof(LPMENUITEMINFOW),1);
 	else fprintf(fp,"{'name':'lpmii','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpmii,sizeof(LPMENUITEMINFOW));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef long (WINAPI *BroadcastSystemMessageExW_fun) (DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo);
BroadcastSystemMessageExW_fun pBroadcastSystemMessageExW = BroadcastSystemMessageExW;
HOOK_TRACE_INFO hHookBroadcastSystemMessageExW = { 0 };
ULONG HookBroadcastSystemMessageExW_ACLEntries[1] = { 0 };
long fake_BroadcastSystemMessageExW(DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo){
	long ret = pBroadcastSystemMessageExW(flags,lpInfo,Msg,wParam,lParam,pbsmInfo);
	fprintf(fp,"OUT ['BroadcastSystemMessageExW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%llx,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(long),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%llx, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(long));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpInfo','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpInfo, sizeof(LPDWORD),1);
 	else fprintf(fp,"{'name':'lpInfo','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpInfo,sizeof(LPDWORD));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pbsmInfo','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pbsmInfo, sizeof(PBSMINFO),1);
 	else fprintf(fp,"{'name':'pbsmInfo','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pbsmInfo,sizeof(PBSMINFO));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetGestureConfig_fun) (HWND hwnd,DWORD dwReserved,DWORD dwFlags,PUINT pcIDs,PGESTURECONFIG pGestureConfig,UINT cbSize);
GetGestureConfig_fun pGetGestureConfig = GetGestureConfig;
HOOK_TRACE_INFO hHookGetGestureConfig = { 0 };
ULONG HookGetGestureConfig_ACLEntries[1] = { 0 };
BOOL fake_GetGestureConfig(HWND hwnd,DWORD dwReserved,DWORD dwFlags,PUINT pcIDs,PGESTURECONFIG pGestureConfig,UINT cbSize){
	BOOL ret = pGetGestureConfig(hwnd,dwReserved,dwFlags,pcIDs,pGestureConfig,cbSize);
	fprintf(fp,"OUT ['GetGestureConfig',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(pcIDs && 1) fprintf(fp,"{'name':'pGestureConfig','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pGestureConfig, sizeof(PGESTURECONFIG),*pcIDs);
 	else fprintf(fp,"{'name':'pGestureConfig','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pGestureConfig,sizeof(PGESTURECONFIG));
	if(pcIDs && pGestureConfig){
		for(int i=0; i<*pcIDs;i++){
			fprintf(fp,"0x%x,",pGestureConfig[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SwitchDesktop_fun) (HDESK hDesktop);
SwitchDesktop_fun pSwitchDesktop = SwitchDesktop;
HOOK_TRACE_INFO hHookSwitchDesktop = { 0 };
ULONG HookSwitchDesktop_ACLEntries[1] = { 0 };
BOOL fake_SwitchDesktop(HDESK hDesktop){
	BOOL ret = pSwitchDesktop(hDesktop);
	fprintf(fp,"OUT ['SwitchDesktop',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *GetNextDlgGroupItem_fun) (HWND hDlg,HWND hCtl,BOOL bPrevious);
GetNextDlgGroupItem_fun pGetNextDlgGroupItem = GetNextDlgGroupItem;
HOOK_TRACE_INFO hHookGetNextDlgGroupItem = { 0 };
ULONG HookGetNextDlgGroupItem_ACLEntries[1] = { 0 };
HWND fake_GetNextDlgGroupItem(HWND hDlg,HWND hCtl,BOOL bPrevious){
	HWND ret = pGetNextDlgGroupItem(hDlg,hCtl,bPrevious);
	fprintf(fp,"OUT ['GetNextDlgGroupItem',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *MessageBoxIndirectA_fun) (CONST MSGBOXPARAMSA*  lpmbp);
MessageBoxIndirectA_fun pMessageBoxIndirectA = MessageBoxIndirectA;
HOOK_TRACE_INFO hHookMessageBoxIndirectA = { 0 };
ULONG HookMessageBoxIndirectA_ACLEntries[1] = { 0 };
int fake_MessageBoxIndirectA(CONST MSGBOXPARAMSA*  lpmbp){
	int ret = pMessageBoxIndirectA( lpmbp);
	fprintf(fp,"OUT ['MessageBoxIndirectA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *DestroyCursor_fun) (HCURSOR hCursor);
DestroyCursor_fun pDestroyCursor = DestroyCursor;
HOOK_TRACE_INFO hHookDestroyCursor = { 0 };
ULONG HookDestroyCursor_ACLEntries[1] = { 0 };
BOOL fake_DestroyCursor(HCURSOR hCursor){
	BOOL ret = pDestroyCursor(hCursor);
	fprintf(fp,"OUT ['DestroyCursor',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SoundSentry_fun) ();
SoundSentry_fun pSoundSentry = SoundSentry;
HOOK_TRACE_INFO hHookSoundSentry = { 0 };
ULONG HookSoundSentry_ACLEntries[1] = { 0 };
BOOL fake_SoundSentry(){
	BOOL ret = pSoundSentry();
	fprintf(fp,"OUT ['SoundSentry',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HACCEL (WINAPI *CreateAcceleratorTableW_fun) (LPACCEL paccel,int cAccel);
CreateAcceleratorTableW_fun pCreateAcceleratorTableW = CreateAcceleratorTableW;
HOOK_TRACE_INFO hHookCreateAcceleratorTableW = { 0 };
ULONG HookCreateAcceleratorTableW_ACLEntries[1] = { 0 };
HACCEL fake_CreateAcceleratorTableW(LPACCEL paccel,int cAccel){
	HACCEL ret = pCreateAcceleratorTableW(paccel,cAccel);
	fprintf(fp,"OUT ['CreateAcceleratorTableW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HACCEL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HACCEL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *GetCapture_fun) ();
GetCapture_fun pGetCapture = GetCapture;
HOOK_TRACE_INFO hHookGetCapture = { 0 };
ULONG HookGetCapture_ACLEntries[1] = { 0 };
HWND fake_GetCapture(){
	HWND ret = pGetCapture();
	fprintf(fp,"OUT ['GetCapture',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *GetDesktopWindow_fun) ();
GetDesktopWindow_fun pGetDesktopWindow = GetDesktopWindow;
HOOK_TRACE_INFO hHookGetDesktopWindow = { 0 };
ULONG HookGetDesktopWindow_ACLEntries[1] = { 0 };
HWND fake_GetDesktopWindow(){
	HWND ret = pGetDesktopWindow();
	fprintf(fp,"OUT ['GetDesktopWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LPARAM (WINAPI *SetMessageExtraInfo_fun) (LPARAM lParam);
SetMessageExtraInfo_fun pSetMessageExtraInfo = SetMessageExtraInfo;
HOOK_TRACE_INFO hHookSetMessageExtraInfo = { 0 };
ULONG HookSetMessageExtraInfo_ACLEntries[1] = { 0 };
LPARAM fake_SetMessageExtraInfo(LPARAM lParam){
	LPARAM ret = pSetMessageExtraInfo(lParam);
	fprintf(fp,"OUT ['SetMessageExtraInfo',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LPARAM),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LPARAM));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HDESK (WINAPI *CreateDesktopW_fun) (LPCWSTR lpszDesktop,LPCWSTR lpszDevice,DEVMODEW*  pDevmode,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa);
CreateDesktopW_fun pCreateDesktopW = CreateDesktopW;
HOOK_TRACE_INFO hHookCreateDesktopW = { 0 };
ULONG HookCreateDesktopW_ACLEntries[1] = { 0 };
HDESK fake_CreateDesktopW(LPCWSTR lpszDesktop,LPCWSTR lpszDevice,DEVMODEW*  pDevmode,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa){
	HDESK ret = pCreateDesktopW(lpszDesktop,lpszDevice, pDevmode,dwFlags,dwDesiredAccess,lpsa);
	fprintf(fp,"OUT ['CreateDesktopW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HDESK),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HDESK));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsWindow_fun) (HWND hWnd);
IsWindow_fun pIsWindow = IsWindow;
HOOK_TRACE_INFO hHookIsWindow = { 0 };
ULONG HookIsWindow_ACLEntries[1] = { 0 };
BOOL fake_IsWindow(HWND hWnd){
	BOOL ret = pIsWindow(hWnd);
	fprintf(fp,"OUT ['IsWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HDESK (WINAPI *OpenDesktopA_fun) (LPCSTR lpszDesktop,DWORD dwFlags,BOOL fInherit,ACCESS_MASK dwDesiredAccess);
OpenDesktopA_fun pOpenDesktopA = OpenDesktopA;
HOOK_TRACE_INFO hHookOpenDesktopA = { 0 };
ULONG HookOpenDesktopA_ACLEntries[1] = { 0 };
HDESK fake_OpenDesktopA(LPCSTR lpszDesktop,DWORD dwFlags,BOOL fInherit,ACCESS_MASK dwDesiredAccess){
	HDESK ret = pOpenDesktopA(lpszDesktop,dwFlags,fInherit,dwDesiredAccess);
	fprintf(fp,"OUT ['OpenDesktopA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HDESK),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HDESK));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *WinHelpA_fun) (HWND hWndMain,LPCSTR lpszHelp,UINT uCommand,ULONG_PTR dwData);
WinHelpA_fun pWinHelpA = WinHelpA;
HOOK_TRACE_INFO hHookWinHelpA = { 0 };
ULONG HookWinHelpA_ACLEntries[1] = { 0 };
BOOL fake_WinHelpA(HWND hWndMain,LPCSTR lpszHelp,UINT uCommand,ULONG_PTR dwData){
	BOOL ret = pWinHelpA(hWndMain,lpszHelp,uCommand,dwData);
	fprintf(fp,"OUT ['WinHelpA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ChangeWindowMessageFilterEx_fun) (HWND hwnd,UINT message,DWORD action,PCHANGEFILTERSTRUCT pChangeFilterStruct);
ChangeWindowMessageFilterEx_fun pChangeWindowMessageFilterEx = ChangeWindowMessageFilterEx;
HOOK_TRACE_INFO hHookChangeWindowMessageFilterEx = { 0 };
ULONG HookChangeWindowMessageFilterEx_ACLEntries[1] = { 0 };
BOOL fake_ChangeWindowMessageFilterEx(HWND hwnd,UINT message,DWORD action,PCHANGEFILTERSTRUCT pChangeFilterStruct){
	BOOL ret = pChangeWindowMessageFilterEx(hwnd,message,action,pChangeFilterStruct);
	fprintf(fp,"OUT ['ChangeWindowMessageFilterEx',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pChangeFilterStruct','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",pChangeFilterStruct, sizeof(PCHANGEFILTERSTRUCT),1);
 	else fprintf(fp,"{'name':'pChangeFilterStruct','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pChangeFilterStruct,sizeof(PCHANGEFILTERSTRUCT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *CloseGestureInfoHandle_fun) (HGESTUREINFO hGestureInfo);
CloseGestureInfoHandle_fun pCloseGestureInfoHandle = CloseGestureInfoHandle;
HOOK_TRACE_INFO hHookCloseGestureInfoHandle = { 0 };
ULONG HookCloseGestureInfoHandle_ACLEntries[1] = { 0 };
BOOL fake_CloseGestureInfoHandle(HGESTUREINFO hGestureInfo){
	BOOL ret = pCloseGestureInfoHandle(hGestureInfo);
	fprintf(fp,"OUT ['CloseGestureInfoHandle',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EnumWindows_fun) (WNDENUMPROC lpEnumFunc,LPARAM lParam);
EnumWindows_fun pEnumWindows = EnumWindows;
HOOK_TRACE_INFO hHookEnumWindows = { 0 };
ULONG HookEnumWindows_ACLEntries[1] = { 0 };
BOOL fake_EnumWindows(WNDENUMPROC lpEnumFunc,LPARAM lParam){
	BOOL ret = pEnumWindows(lpEnumFunc,lParam);
	fprintf(fp,"OUT ['EnumWindows',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HCURSOR (WINAPI *CreateCursor_fun) (HINSTANCE hInst,int xHotSpot,int yHotSpot,int nWidth,int nHeight,CONST VOID* pvANDPlane,CONST VOID* pvXORPlane);
CreateCursor_fun pCreateCursor = CreateCursor;
HOOK_TRACE_INFO hHookCreateCursor = { 0 };
ULONG HookCreateCursor_ACLEntries[1] = { 0 };
HCURSOR fake_CreateCursor(HINSTANCE hInst,int xHotSpot,int yHotSpot,int nWidth,int nHeight,CONST VOID* pvANDPlane,CONST VOID* pvXORPlane){
	HCURSOR ret = pCreateCursor(hInst,xHotSpot,yHotSpot,nWidth,nHeight,pvANDPlane,pvXORPlane);
	fprintf(fp,"OUT ['CreateCursor',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HCURSOR),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HCURSOR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HDWP (WINAPI *BeginDeferWindowPos_fun) (int nNumWindows);
BeginDeferWindowPos_fun pBeginDeferWindowPos = BeginDeferWindowPos;
HOOK_TRACE_INFO hHookBeginDeferWindowPos = { 0 };
ULONG HookBeginDeferWindowPos_ACLEntries[1] = { 0 };
HDWP fake_BeginDeferWindowPos(int nNumWindows){
	HDWP ret = pBeginDeferWindowPos(nNumWindows);
	fprintf(fp,"OUT ['BeginDeferWindowPos',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HDWP),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HDWP));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetWindowDisplayAffinity_fun) (HWND hWnd,DWORD dwAffinity);
SetWindowDisplayAffinity_fun pSetWindowDisplayAffinity = SetWindowDisplayAffinity;
HOOK_TRACE_INFO hHookSetWindowDisplayAffinity = { 0 };
ULONG HookSetWindowDisplayAffinity_ACLEntries[1] = { 0 };
BOOL fake_SetWindowDisplayAffinity(HWND hWnd,DWORD dwAffinity){
	BOOL ret = pSetWindowDisplayAffinity(hWnd,dwAffinity);
	fprintf(fp,"OUT ['SetWindowDisplayAffinity',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ScrollDC_fun) (HDC hDC,int dx,int dy,CONST RECT* lprcScroll,CONST RECT* lprcClip,HRGN hrgnUpdate,LPRECT lprcUpdate);
ScrollDC_fun pScrollDC = ScrollDC;
HOOK_TRACE_INFO hHookScrollDC = { 0 };
ULONG HookScrollDC_ACLEntries[1] = { 0 };
BOOL fake_ScrollDC(HDC hDC,int dx,int dy,CONST RECT* lprcScroll,CONST RECT* lprcClip,HRGN hrgnUpdate,LPRECT lprcUpdate){
	BOOL ret = pScrollDC(hDC,dx,dy,lprcScroll,lprcClip,hrgnUpdate,lprcUpdate);
	fprintf(fp,"OUT ['ScrollDC',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lprcUpdate','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lprcUpdate, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'lprcUpdate','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lprcUpdate,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EnumThreadWindows_fun) (DWORD dwThreadId,WNDENUMPROC lpfn,LPARAM lParam);
EnumThreadWindows_fun pEnumThreadWindows = EnumThreadWindows;
HOOK_TRACE_INFO hHookEnumThreadWindows = { 0 };
ULONG HookEnumThreadWindows_ACLEntries[1] = { 0 };
BOOL fake_EnumThreadWindows(DWORD dwThreadId,WNDENUMPROC lpfn,LPARAM lParam){
	BOOL ret = pEnumThreadWindows(dwThreadId,lpfn,lParam);
	fprintf(fp,"OUT ['EnumThreadWindows',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef long (WINAPI *BroadcastSystemMessageA_fun) (DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam);
BroadcastSystemMessageA_fun pBroadcastSystemMessageA = BroadcastSystemMessageA;
HOOK_TRACE_INFO hHookBroadcastSystemMessageA = { 0 };
ULONG HookBroadcastSystemMessageA_ACLEntries[1] = { 0 };
long fake_BroadcastSystemMessageA(DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam){
	long ret = pBroadcastSystemMessageA(flags,lpInfo,Msg,wParam,lParam);
	fprintf(fp,"OUT ['BroadcastSystemMessageA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%llx,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(long),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%llx, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(long));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpInfo','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpInfo, sizeof(LPDWORD),1);
 	else fprintf(fp,"{'name':'lpInfo','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpInfo,sizeof(LPDWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *GetKeyboardType_fun) (int nTypeFlag);
GetKeyboardType_fun pGetKeyboardType = GetKeyboardType;
HOOK_TRACE_INFO hHookGetKeyboardType = { 0 };
ULONG HookGetKeyboardType_ACLEntries[1] = { 0 };
int fake_GetKeyboardType(int nTypeFlag){
	int ret = pGetKeyboardType(nTypeFlag);
	fprintf(fp,"OUT ['GetKeyboardType',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *GetClipboardFormatNameW_fun) (UINT format,LPWSTR lpszFormatName,int cchMaxCount);
GetClipboardFormatNameW_fun pGetClipboardFormatNameW = GetClipboardFormatNameW;
HOOK_TRACE_INFO hHookGetClipboardFormatNameW = { 0 };
ULONG HookGetClipboardFormatNameW_ACLEntries[1] = { 0 };
int fake_GetClipboardFormatNameW(UINT format,LPWSTR lpszFormatName,int cchMaxCount){
	int ret = pGetClipboardFormatNameW(format,lpszFormatName,cchMaxCount);
	fprintf(fp,"OUT ['GetClipboardFormatNameW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'lpszFormatName',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': %p,", lpszFormatName);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': %p,", lpszFormatName);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),cchMaxCount);
 	}else 
	{
		fprintf(fp,"{'name':'lpszFormatName',");
		fwprintf(fp, L"'value': %p, ", lpszFormatName);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	if(lpszFormatName){
		for(int i=0; i<cchMaxCount;i++){
			fprintf(fp,"0x%x,",lpszFormatName[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsClipboardFormatAvailable_fun) (UINT format);
IsClipboardFormatAvailable_fun pIsClipboardFormatAvailable = IsClipboardFormatAvailable;
HOOK_TRACE_INFO hHookIsClipboardFormatAvailable = { 0 };
ULONG HookIsClipboardFormatAvailable_ACLEntries[1] = { 0 };
BOOL fake_IsClipboardFormatAvailable(UINT format){
	BOOL ret = pIsClipboardFormatAvailable(format);
	fprintf(fp,"OUT ['IsClipboardFormatAvailable',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef INT_PTR (WINAPI *DialogBoxIndirectParamA_fun) (HINSTANCE hInstance,LPCDLGTEMPLATEA hDialogTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
DialogBoxIndirectParamA_fun pDialogBoxIndirectParamA = DialogBoxIndirectParamA;
HOOK_TRACE_INFO hHookDialogBoxIndirectParamA = { 0 };
ULONG HookDialogBoxIndirectParamA_ACLEntries[1] = { 0 };
INT_PTR fake_DialogBoxIndirectParamA(HINSTANCE hInstance,LPCDLGTEMPLATEA hDialogTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam){
	INT_PTR ret = pDialogBoxIndirectParamA(hInstance,hDialogTemplate,hWndParent,lpDialogFunc,dwInitParam);
	fprintf(fp,"OUT ['DialogBoxIndirectParamA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(INT_PTR),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(INT_PTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HMENU (WINAPI *GetMenu_fun) (HWND hWnd);
GetMenu_fun pGetMenu = GetMenu;
HOOK_TRACE_INFO hHookGetMenu = { 0 };
ULONG HookGetMenu_ACLEntries[1] = { 0 };
HMENU fake_GetMenu(HWND hWnd){
	HMENU ret = pGetMenu(hWnd);
	fprintf(fp,"OUT ['GetMenu',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HMENU),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HMENU));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *GetRawInputBuffer_fun) (PRAWINPUT pData,PUINT pcbSize,UINT cbSizeHeader);
GetRawInputBuffer_fun pGetRawInputBuffer = GetRawInputBuffer;
HOOK_TRACE_INFO hHookGetRawInputBuffer = { 0 };
ULONG HookGetRawInputBuffer_ACLEntries[1] = { 0 };
UINT fake_GetRawInputBuffer(PRAWINPUT pData,PUINT pcbSize,UINT cbSizeHeader){
	UINT ret = pGetRawInputBuffer(pData,pcbSize,cbSizeHeader);
	fprintf(fp,"OUT ['GetRawInputBuffer',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pData','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pData, sizeof(PRAWINPUT),1);
 	else fprintf(fp,"{'name':'pData','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pData,sizeof(PRAWINPUT));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pcbSize','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pcbSize, sizeof(PUINT),1);
 	else fprintf(fp,"{'name':'pcbSize','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pcbSize,sizeof(PUINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *CountClipboardFormats_fun) ();
CountClipboardFormats_fun pCountClipboardFormats = CountClipboardFormats;
HOOK_TRACE_INFO hHookCountClipboardFormats = { 0 };
ULONG HookCountClipboardFormats_ACLEntries[1] = { 0 };
int fake_CountClipboardFormats(){
	int ret = pCountClipboardFormats();
	fprintf(fp,"OUT ['CountClipboardFormats',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *FrameRect_fun) (HDC hDC,CONST RECT* lprc,HBRUSH hbr);
FrameRect_fun pFrameRect = FrameRect;
HOOK_TRACE_INFO hHookFrameRect = { 0 };
ULONG HookFrameRect_ACLEntries[1] = { 0 };
int fake_FrameRect(HDC hDC,CONST RECT* lprc,HBRUSH hbr){
	int ret = pFrameRect(hDC,lprc,hbr);
	fprintf(fp,"OUT ['FrameRect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *EnumPropsW_fun) (HWND hWnd,PROPENUMPROCW lpEnumFunc);
EnumPropsW_fun pEnumPropsW = EnumPropsW;
HOOK_TRACE_INFO hHookEnumPropsW = { 0 };
ULONG HookEnumPropsW_ACLEntries[1] = { 0 };
int fake_EnumPropsW(HWND hWnd,PROPENUMPROCW lpEnumFunc){
	int ret = pEnumPropsW(hWnd,lpEnumFunc);
	fprintf(fp,"OUT ['EnumPropsW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *InSendMessageEx_fun) (LPVOID lpReserved);
InSendMessageEx_fun pInSendMessageEx = InSendMessageEx;
HOOK_TRACE_INFO hHookInSendMessageEx = { 0 };
ULONG HookInSendMessageEx_ACLEntries[1] = { 0 };
DWORD fake_InSendMessageEx(LPVOID lpReserved){
	DWORD ret = pInSendMessageEx(lpReserved);
	fprintf(fp,"OUT ['InSendMessageEx',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *GetLastActivePopup_fun) (HWND hWnd);
GetLastActivePopup_fun pGetLastActivePopup = GetLastActivePopup;
HOOK_TRACE_INFO hHookGetLastActivePopup = { 0 };
ULONG HookGetLastActivePopup_ACLEntries[1] = { 0 };
HWND fake_GetLastActivePopup(HWND hWnd){
	HWND ret = pGetLastActivePopup(hWnd);
	fprintf(fp,"OUT ['GetLastActivePopup',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *PostMessageW_fun) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
PostMessageW_fun pPostMessageW = PostMessageW;
HOOK_TRACE_INFO hHookPostMessageW = { 0 };
ULONG HookPostMessageW_ACLEntries[1] = { 0 };
BOOL fake_PostMessageW(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam){
	BOOL ret = pPostMessageW(hWnd,Msg,wParam,lParam);
	fprintf(fp,"OUT ['PostMessageW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *DrawTextExW_fun) (HDC hdc,LPWSTR lpchText,int cchText,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp);
DrawTextExW_fun pDrawTextExW = DrawTextExW;
HOOK_TRACE_INFO hHookDrawTextExW = { 0 };
ULONG HookDrawTextExW_ACLEntries[1] = { 0 };
int fake_DrawTextExW(HDC hdc,LPWSTR lpchText,int cchText,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp){
	int ret = pDrawTextExW(hdc,lpchText,cchText,lprc,format,lpdtp);
	fprintf(fp,"OUT ['DrawTextExW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'lpchText',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': %p,", lpchText);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': %p,", lpchText);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),cchText);
 	}else 
	{
		fprintf(fp,"{'name':'lpchText',");
		fwprintf(fp, L"'value': %p, ", lpchText);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	if(lpchText){
		for(int i=0; i<cchText;i++){
			fprintf(fp,"0x%x,",lpchText[i]);
		}
	}
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lprc','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lprc, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'lprc','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lprc,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetMonitorInfoW_fun) (HMONITOR hMonitor,LPMONITORINFO lpmi);
GetMonitorInfoW_fun pGetMonitorInfoW = GetMonitorInfoW;
HOOK_TRACE_INFO hHookGetMonitorInfoW = { 0 };
ULONG HookGetMonitorInfoW_ACLEntries[1] = { 0 };
BOOL fake_GetMonitorInfoW(HMONITOR hMonitor,LPMONITORINFO lpmi){
	BOOL ret = pGetMonitorInfoW(hMonitor,lpmi);
	fprintf(fp,"OUT ['GetMonitorInfoW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpmi','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpmi, sizeof(LPMONITORINFO),1);
 	else fprintf(fp,"{'name':'lpmi','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpmi,sizeof(LPMONITORINFO));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *MessageBoxW_fun) (HWND hWnd,LPCWSTR lpText,LPCWSTR lpCaption,UINT uType);
MessageBoxW_fun pMessageBoxW = MessageBoxW;
HOOK_TRACE_INFO hHookMessageBoxW = { 0 };
ULONG HookMessageBoxW_ACLEntries[1] = { 0 };
int fake_MessageBoxW(HWND hWnd,LPCWSTR lpText,LPCWSTR lpCaption,UINT uType){
	int ret = pMessageBoxW(hWnd,lpText,lpCaption,uType);
	fprintf(fp,"OUT ['MessageBoxW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsWindowUnicode_fun) (HWND hWnd);
IsWindowUnicode_fun pIsWindowUnicode = IsWindowUnicode;
HOOK_TRACE_INFO hHookIsWindowUnicode = { 0 };
ULONG HookIsWindowUnicode_ACLEntries[1] = { 0 };
BOOL fake_IsWindowUnicode(HWND hWnd){
	BOOL ret = pIsWindowUnicode(hWnd);
	fprintf(fp,"OUT ['IsWindowUnicode',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LRESULT (WINAPI *DispatchMessageA_fun) (CONST MSG* lpMsg);
DispatchMessageA_fun pDispatchMessageA = DispatchMessageA;
HOOK_TRACE_INFO hHookDispatchMessageA = { 0 };
ULONG HookDispatchMessageA_ACLEntries[1] = { 0 };
LRESULT fake_DispatchMessageA(CONST MSG* lpMsg){
	LRESULT ret = pDispatchMessageA(lpMsg);
	fprintf(fp,"OUT ['DispatchMessageA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LRESULT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LRESULT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *PostThreadMessageA_fun) (DWORD idThread,UINT Msg,WPARAM wParam,LPARAM lParam);
PostThreadMessageA_fun pPostThreadMessageA = PostThreadMessageA;
HOOK_TRACE_INFO hHookPostThreadMessageA = { 0 };
ULONG HookPostThreadMessageA_ACLEntries[1] = { 0 };
BOOL fake_PostThreadMessageA(DWORD idThread,UINT Msg,WPARAM wParam,LPARAM lParam){
	BOOL ret = pPostThreadMessageA(idThread,Msg,wParam,lParam);
	fprintf(fp,"OUT ['PostThreadMessageA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *UnregisterHotKey_fun) (HWND hWnd,int id);
UnregisterHotKey_fun pUnregisterHotKey = UnregisterHotKey;
HOOK_TRACE_INFO hHookUnregisterHotKey = { 0 };
ULONG HookUnregisterHotKey_ACLEntries[1] = { 0 };
BOOL fake_UnregisterHotKey(HWND hWnd,int id){
	BOOL ret = pUnregisterHotKey(hWnd,id);
	fprintf(fp,"OUT ['UnregisterHotKey',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *CreateDialogIndirectParamA_fun) (HINSTANCE hInstance,LPCDLGTEMPLATEA lpTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
CreateDialogIndirectParamA_fun pCreateDialogIndirectParamA = CreateDialogIndirectParamA;
HOOK_TRACE_INFO hHookCreateDialogIndirectParamA = { 0 };
ULONG HookCreateDialogIndirectParamA_ACLEntries[1] = { 0 };
HWND fake_CreateDialogIndirectParamA(HINSTANCE hInstance,LPCDLGTEMPLATEA lpTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam){
	HWND ret = pCreateDialogIndirectParamA(hInstance,lpTemplate,hWndParent,lpDialogFunc,dwInitParam);
	fprintf(fp,"OUT ['CreateDialogIndirectParamA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *OemToCharA_fun) (LPCSTR pSrc,LPSTR pDst);
OemToCharA_fun pOemToCharA = OemToCharA;
HOOK_TRACE_INFO hHookOemToCharA = { 0 };
ULONG HookOemToCharA_ACLEntries[1] = { 0 };
BOOL fake_OemToCharA(LPCSTR pSrc,LPSTR pDst){
	BOOL ret = pOemToCharA(pSrc,pDst);
	fprintf(fp,"OUT ['OemToCharA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pDst','value': '\"%s\"','size' : 0x%lx,'cnt':0x%x, 'data':[",pDst, sizeof(LPSTR),1);
 	else fprintf(fp,"{'name':'pDst','value': '\"%s\"', 'size' : 0x%lx,'cnt':'undefined', 'data':[",pDst,sizeof(LPSTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetCursorPos_fun) (LPPOINT lpPoint);
GetCursorPos_fun pGetCursorPos = GetCursorPos;
HOOK_TRACE_INFO hHookGetCursorPos = { 0 };
ULONG HookGetCursorPos_ACLEntries[1] = { 0 };
BOOL fake_GetCursorPos(LPPOINT lpPoint){
	BOOL ret = pGetCursorPos(lpPoint);
	fprintf(fp,"OUT ['GetCursorPos',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpPoint','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpPoint, sizeof(LPPOINT),1);
 	else fprintf(fp,"{'name':'lpPoint','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpPoint,sizeof(LPPOINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *CharUpperBuffW_fun) (LPWSTR lpsz,DWORD cchLength);
CharUpperBuffW_fun pCharUpperBuffW = CharUpperBuffW;
HOOK_TRACE_INFO hHookCharUpperBuffW = { 0 };
ULONG HookCharUpperBuffW_ACLEntries[1] = { 0 };
DWORD fake_CharUpperBuffW(LPWSTR lpsz,DWORD cchLength){
	DWORD ret = pCharUpperBuffW(lpsz,cchLength);
	fprintf(fp,"OUT ['CharUpperBuffW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'lpsz',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': %p,", lpsz);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': %p,", lpsz);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),cchLength);
 	}else 
	{
		fprintf(fp,"{'name':'lpsz',");
		fwprintf(fp, L"'value': %p, ", lpsz);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	if(lpsz){
		for(int i=0; i<cchLength;i++){
			fprintf(fp,"0x%x,",lpsz[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *GetSystemMetrics_fun) (int nIndex);
GetSystemMetrics_fun pGetSystemMetrics = GetSystemMetrics;
HOOK_TRACE_INFO hHookGetSystemMetrics = { 0 };
ULONG HookGetSystemMetrics_ACLEntries[1] = { 0 };
int fake_GetSystemMetrics(int nIndex){
	int ret = pGetSystemMetrics(nIndex);
	fprintf(fp,"OUT ['GetSystemMetrics',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetKeyboardState_fun) (PBYTE lpKeyState);
GetKeyboardState_fun pGetKeyboardState = GetKeyboardState;
HOOK_TRACE_INFO hHookGetKeyboardState = { 0 };
ULONG HookGetKeyboardState_ACLEntries[1] = { 0 };
BOOL fake_GetKeyboardState(PBYTE lpKeyState){
	BOOL ret = pGetKeyboardState(lpKeyState);
	fprintf(fp,"OUT ['GetKeyboardState',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpKeyState','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpKeyState, sizeof(PBYTE),256);
 	else fprintf(fp,"{'name':'lpKeyState','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpKeyState,sizeof(PBYTE));
	if(lpKeyState){
		for(int i=0; i<256;i++){
			fprintf(fp,"0x%x,",lpKeyState[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsWindowEnabled_fun) (HWND hWnd);
IsWindowEnabled_fun pIsWindowEnabled = IsWindowEnabled;
HOOK_TRACE_INFO hHookIsWindowEnabled = { 0 };
ULONG HookIsWindowEnabled_ACLEntries[1] = { 0 };
BOOL fake_IsWindowEnabled(HWND hWnd){
	BOOL ret = pIsWindowEnabled(hWnd);
	fprintf(fp,"OUT ['IsWindowEnabled',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SwapMouseButton_fun) (BOOL fSwap);
SwapMouseButton_fun pSwapMouseButton = SwapMouseButton;
HOOK_TRACE_INFO hHookSwapMouseButton = { 0 };
ULONG HookSwapMouseButton_ACLEntries[1] = { 0 };
BOOL fake_SwapMouseButton(BOOL fSwap){
	BOOL ret = pSwapMouseButton(fSwap);
	fprintf(fp,"OUT ['SwapMouseButton',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *UnregisterPowerSettingNotification_fun) (HPOWERNOTIFY Handle);
UnregisterPowerSettingNotification_fun pUnregisterPowerSettingNotification = UnregisterPowerSettingNotification;
HOOK_TRACE_INFO hHookUnregisterPowerSettingNotification = { 0 };
ULONG HookUnregisterPowerSettingNotification_ACLEntries[1] = { 0 };
BOOL fake_UnregisterPowerSettingNotification(HPOWERNOTIFY Handle){
	BOOL ret = pUnregisterPowerSettingNotification(Handle);
	fprintf(fp,"OUT ['UnregisterPowerSettingNotification',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *InsertMenuItemA_fun) (HMENU hmenu,UINT item,BOOL fByPosition,LPCMENUITEMINFOA lpmi);
InsertMenuItemA_fun pInsertMenuItemA = InsertMenuItemA;
HOOK_TRACE_INFO hHookInsertMenuItemA = { 0 };
ULONG HookInsertMenuItemA_ACLEntries[1] = { 0 };
BOOL fake_InsertMenuItemA(HMENU hmenu,UINT item,BOOL fByPosition,LPCMENUITEMINFOA lpmi){
	BOOL ret = pInsertMenuItemA(hmenu,item,fByPosition,lpmi);
	fprintf(fp,"OUT ['InsertMenuItemA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *UpdateLayeredWindow_fun) (HWND hWnd,HDC hdcDst,POINT*  pptDst,SIZE*  psize,HDC hdcSrc,POINT*  pptSrc,COLORREF crKey,BLENDFUNCTION*  pblend,DWORD dwFlags);
UpdateLayeredWindow_fun pUpdateLayeredWindow = UpdateLayeredWindow;
HOOK_TRACE_INFO hHookUpdateLayeredWindow = { 0 };
ULONG HookUpdateLayeredWindow_ACLEntries[1] = { 0 };
BOOL fake_UpdateLayeredWindow(HWND hWnd,HDC hdcDst,POINT*  pptDst,SIZE*  psize,HDC hdcSrc,POINT*  pptSrc,COLORREF crKey,BLENDFUNCTION*  pblend,DWORD dwFlags){
	BOOL ret = pUpdateLayeredWindow(hWnd,hdcDst, pptDst, psize,hdcSrc, pptSrc,crKey, pblend,dwFlags);
	fprintf(fp,"OUT ['UpdateLayeredWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HCURSOR (WINAPI *GetCursor_fun) ();
GetCursor_fun pGetCursor = GetCursor;
HOOK_TRACE_INFO hHookGetCursor = { 0 };
ULONG HookGetCursor_ACLEntries[1] = { 0 };
HCURSOR fake_GetCursor(){
	HCURSOR ret = pGetCursor();
	fprintf(fp,"OUT ['GetCursor',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HCURSOR),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HCURSOR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LONG (WINAPI *SetWindowLongW_fun) (HWND hWnd,int nIndex,LONG dwNewLong);
SetWindowLongW_fun pSetWindowLongW = SetWindowLongW;
HOOK_TRACE_INFO hHookSetWindowLongW = { 0 };
ULONG HookSetWindowLongW_ACLEntries[1] = { 0 };
LONG fake_SetWindowLongW(HWND hWnd,int nIndex,LONG dwNewLong){
	LONG ret = pSetWindowLongW(hWnd,nIndex,dwNewLong);
	fprintf(fp,"OUT ['SetWindowLongW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LONG),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LONG));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HHOOK (WINAPI *SetWindowsHookExA_fun) (int idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId);
SetWindowsHookExA_fun pSetWindowsHookExA = SetWindowsHookExA;
HOOK_TRACE_INFO hHookSetWindowsHookExA = { 0 };
ULONG HookSetWindowsHookExA_ACLEntries[1] = { 0 };
HHOOK fake_SetWindowsHookExA(int idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId){
	HHOOK ret = pSetWindowsHookExA(idHook,lpfn,hmod,dwThreadId);
	fprintf(fp,"OUT ['SetWindowsHookExA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HHOOK),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HHOOK));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *CancelShutdown_fun) ();
CancelShutdown_fun pCancelShutdown = CancelShutdown;
HOOK_TRACE_INFO hHookCancelShutdown = { 0 };
ULONG HookCancelShutdown_ACLEntries[1] = { 0 };
BOOL fake_CancelShutdown(){
	BOOL ret = pCancelShutdown();
	fprintf(fp,"OUT ['CancelShutdown',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HHOOK (WINAPI *SetWindowsHookExW_fun) (int idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId);
SetWindowsHookExW_fun pSetWindowsHookExW = SetWindowsHookExW;
HOOK_TRACE_INFO hHookSetWindowsHookExW = { 0 };
ULONG HookSetWindowsHookExW_ACLEntries[1] = { 0 };
HHOOK fake_SetWindowsHookExW(int idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId){
	HHOOK ret = pSetWindowsHookExW(idHook,lpfn,hmod,dwThreadId);
	fprintf(fp,"OUT ['SetWindowsHookExW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HHOOK),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HHOOK));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LONG_PTR (WINAPI *SetWindowLongPtrW_fun) (HWND hWnd,int nIndex,LONG_PTR dwNewLong);
SetWindowLongPtrW_fun pSetWindowLongPtrW = SetWindowLongPtrW;
HOOK_TRACE_INFO hHookSetWindowLongPtrW = { 0 };
ULONG HookSetWindowLongPtrW_ACLEntries[1] = { 0 };
LONG_PTR fake_SetWindowLongPtrW(HWND hWnd,int nIndex,LONG_PTR dwNewLong){
	LONG_PTR ret = pSetWindowLongPtrW(hWnd,nIndex,dwNewLong);
	fprintf(fp,"OUT ['SetWindowLongPtrW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LONG_PTR),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LONG_PTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *CopyAcceleratorTableA_fun) (HACCEL hAccelSrc,LPACCEL lpAccelDst,int cAccelEntries);
CopyAcceleratorTableA_fun pCopyAcceleratorTableA = CopyAcceleratorTableA;
HOOK_TRACE_INFO hHookCopyAcceleratorTableA = { 0 };
ULONG HookCopyAcceleratorTableA_ACLEntries[1] = { 0 };
int fake_CopyAcceleratorTableA(HACCEL hAccelSrc,LPACCEL lpAccelDst,int cAccelEntries){
	int ret = pCopyAcceleratorTableA(hAccelSrc,lpAccelDst,cAccelEntries);
	fprintf(fp,"OUT ['CopyAcceleratorTableA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpAccelDst','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpAccelDst, sizeof(LPACCEL),cAccelEntries, ret);
 	else fprintf(fp,"{'name':'lpAccelDst','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpAccelDst,sizeof(LPACCEL));
	if(lpAccelDst){
		for(int i=0; i<cAccelEntries <  ret ? cAccelEntries :  ret;i++){
			fprintf(fp,"0x%x,",lpAccelDst[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *WindowFromDC_fun) (HDC hDC);
WindowFromDC_fun pWindowFromDC = WindowFromDC;
HOOK_TRACE_INFO hHookWindowFromDC = { 0 };
ULONG HookWindowFromDC_ACLEntries[1] = { 0 };
HWND fake_WindowFromDC(HDC hDC){
	HWND ret = pWindowFromDC(hDC);
	fprintf(fp,"OUT ['WindowFromDC',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HANDLE (WINAPI *GetClipboardData_fun) (UINT uFormat);
GetClipboardData_fun pGetClipboardData = GetClipboardData;
HOOK_TRACE_INFO hHookGetClipboardData = { 0 };
ULONG HookGetClipboardData_ACLEntries[1] = { 0 };
HANDLE fake_GetClipboardData(UINT uFormat){
	HANDLE ret = pGetClipboardData(uFormat);
	fprintf(fp,"OUT ['GetClipboardData',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HANDLE),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HANDLE));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HDESK (WINAPI *CreateDesktopA_fun) (LPCSTR lpszDesktop,LPCSTR lpszDevice,DEVMODEA*  pDevmode,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa);
CreateDesktopA_fun pCreateDesktopA = CreateDesktopA;
HOOK_TRACE_INFO hHookCreateDesktopA = { 0 };
ULONG HookCreateDesktopA_ACLEntries[1] = { 0 };
HDESK fake_CreateDesktopA(LPCSTR lpszDesktop,LPCSTR lpszDevice,DEVMODEA*  pDevmode,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa){
	HDESK ret = pCreateDesktopA(lpszDesktop,lpszDevice, pDevmode,dwFlags,dwDesiredAccess,lpsa);
	fprintf(fp,"OUT ['CreateDesktopA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HDESK),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HDESK));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *CreateDialogParamW_fun) (HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
CreateDialogParamW_fun pCreateDialogParamW = CreateDialogParamW;
HOOK_TRACE_INFO hHookCreateDialogParamW = { 0 };
ULONG HookCreateDialogParamW_ACLEntries[1] = { 0 };
HWND fake_CreateDialogParamW(HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam){
	HWND ret = pCreateDialogParamW(hInstance,lpTemplateName,hWndParent,lpDialogFunc,dwInitParam);
	fprintf(fp,"OUT ['CreateDialogParamW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SystemParametersInfoW_fun) (UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni);
SystemParametersInfoW_fun pSystemParametersInfoW = SystemParametersInfoW;
HOOK_TRACE_INFO hHookSystemParametersInfoW = { 0 };
ULONG HookSystemParametersInfoW_ACLEntries[1] = { 0 };
BOOL fake_SystemParametersInfoW(UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni){
	BOOL ret = pSystemParametersInfoW(uiAction,uiParam,pvParam,fWinIni);
	fprintf(fp,"OUT ['SystemParametersInfoW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pvParam','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pvParam, sizeof(PVOID),1);
 	else fprintf(fp,"{'name':'pvParam','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pvParam,sizeof(PVOID));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef SHORT (WINAPI *VkKeyScanExW_fun) (WCHAR ch,HKL dwhkl);
VkKeyScanExW_fun pVkKeyScanExW = VkKeyScanExW;
HOOK_TRACE_INFO hHookVkKeyScanExW = { 0 };
ULONG HookVkKeyScanExW_ACLEntries[1] = { 0 };
SHORT fake_VkKeyScanExW(WCHAR ch,HKL dwhkl){
	SHORT ret = pVkKeyScanExW(ch,dwhkl);
	fprintf(fp,"OUT ['VkKeyScanExW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%hx,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(SHORT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%hx, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(SHORT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *LoadStringA_fun) (HINSTANCE hInstance,UINT uID,LPSTR lpBuffer,int cchBufferMax);
LoadStringA_fun pLoadStringA = LoadStringA;
HOOK_TRACE_INFO hHookLoadStringA = { 0 };
ULONG HookLoadStringA_ACLEntries[1] = { 0 };
int fake_LoadStringA(HINSTANCE hInstance,UINT uID,LPSTR lpBuffer,int cchBufferMax){
	int ret = pLoadStringA(hInstance,uID,lpBuffer,cchBufferMax);
	fprintf(fp,"OUT ['LoadStringA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpBuffer','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpBuffer, sizeof(LPSTR),cchBufferMax, ret + 1);
 	else fprintf(fp,"{'name':'lpBuffer','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpBuffer,sizeof(LPSTR));
	if(lpBuffer){
		for(int i=0; i<cchBufferMax <  ret + 1 ? cchBufferMax :  ret + 1;i++){
			fprintf(fp,"0x%x,",lpBuffer[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EnumDisplaySettingsA_fun) (LPCSTR lpszDeviceName,DWORD iModeNum,DEVMODEA*  lpDevMode);
EnumDisplaySettingsA_fun pEnumDisplaySettingsA = EnumDisplaySettingsA;
HOOK_TRACE_INFO hHookEnumDisplaySettingsA = { 0 };
ULONG HookEnumDisplaySettingsA_ACLEntries[1] = { 0 };
BOOL fake_EnumDisplaySettingsA(LPCSTR lpszDeviceName,DWORD iModeNum,DEVMODEA*  lpDevMode){
	BOOL ret = pEnumDisplaySettingsA(lpszDeviceName,iModeNum, lpDevMode);
	fprintf(fp,"OUT ['EnumDisplaySettingsA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':' lpDevMode','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[", lpDevMode, sizeof(DEVMODEA*),1);
 	else fprintf(fp,"{'name':' lpDevMode','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[", lpDevMode,sizeof(DEVMODEA*));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *GetPriorityClipboardFormat_fun) (UINT* paFormatPriorityList,int cFormats);
GetPriorityClipboardFormat_fun pGetPriorityClipboardFormat = GetPriorityClipboardFormat;
HOOK_TRACE_INFO hHookGetPriorityClipboardFormat = { 0 };
ULONG HookGetPriorityClipboardFormat_ACLEntries[1] = { 0 };
int fake_GetPriorityClipboardFormat(UINT* paFormatPriorityList,int cFormats){
	int ret = pGetPriorityClipboardFormat(paFormatPriorityList,cFormats);
	fprintf(fp,"OUT ['GetPriorityClipboardFormat',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetMenuDefaultItem_fun) (HMENU hMenu,UINT uItem,UINT fByPos);
SetMenuDefaultItem_fun pSetMenuDefaultItem = SetMenuDefaultItem;
HOOK_TRACE_INFO hHookSetMenuDefaultItem = { 0 };
ULONG HookSetMenuDefaultItem_ACLEntries[1] = { 0 };
BOOL fake_SetMenuDefaultItem(HMENU hMenu,UINT uItem,UINT fByPos){
	BOOL ret = pSetMenuDefaultItem(hMenu,uItem,fByPos);
	fprintf(fp,"OUT ['SetMenuDefaultItem',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *GetDoubleClickTime_fun) ();
GetDoubleClickTime_fun pGetDoubleClickTime = GetDoubleClickTime;
HOOK_TRACE_INFO hHookGetDoubleClickTime = { 0 };
ULONG HookGetDoubleClickTime_ACLEntries[1] = { 0 };
UINT fake_GetDoubleClickTime(){
	UINT ret = pGetDoubleClickTime();
	fprintf(fp,"OUT ['GetDoubleClickTime',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EnableMenuItem_fun) (HMENU hMenu,UINT uIDEnableItem,UINT uEnable);
EnableMenuItem_fun pEnableMenuItem = EnableMenuItem;
HOOK_TRACE_INFO hHookEnableMenuItem = { 0 };
ULONG HookEnableMenuItem_ACLEntries[1] = { 0 };
BOOL fake_EnableMenuItem(HMENU hMenu,UINT uIDEnableItem,UINT uEnable){
	BOOL ret = pEnableMenuItem(hMenu,uIDEnableItem,uEnable);
	fprintf(fp,"OUT ['EnableMenuItem',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *PhysicalToLogicalPoint_fun) (HWND hWnd,LPPOINT lpPoint);
PhysicalToLogicalPoint_fun pPhysicalToLogicalPoint = PhysicalToLogicalPoint;
HOOK_TRACE_INFO hHookPhysicalToLogicalPoint = { 0 };
ULONG HookPhysicalToLogicalPoint_ACLEntries[1] = { 0 };
BOOL fake_PhysicalToLogicalPoint(HWND hWnd,LPPOINT lpPoint){
	BOOL ret = pPhysicalToLogicalPoint(hWnd,lpPoint);
	fprintf(fp,"OUT ['PhysicalToLogicalPoint',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpPoint','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpPoint, sizeof(LPPOINT),1);
 	else fprintf(fp,"{'name':'lpPoint','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpPoint,sizeof(LPPOINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *DlgDirListW_fun) (HWND hDlg,LPWSTR lpPathSpec,int nIDListBox,int nIDStaticPath,UINT uFileType);
DlgDirListW_fun pDlgDirListW = DlgDirListW;
HOOK_TRACE_INFO hHookDlgDirListW = { 0 };
ULONG HookDlgDirListW_ACLEntries[1] = { 0 };
int fake_DlgDirListW(HWND hDlg,LPWSTR lpPathSpec,int nIDListBox,int nIDStaticPath,UINT uFileType){
	int ret = pDlgDirListW(hDlg,lpPathSpec,nIDListBox,nIDStaticPath,uFileType);
	fprintf(fp,"OUT ['DlgDirListW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'lpPathSpec',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': '\"%s\"',", lpPathSpec);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': '\"%s\"',", lpPathSpec);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),1);
 	}else 
	{
		fprintf(fp,"{'name':'lpPathSpec',");
		fwprintf(fp, L"'value': '\"%s\"', ", lpPathSpec);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *DrawStateA_fun) (HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfnCallBack,LPARAM lData,WPARAM wData,int x,int y,int cx,int cy,UINT uFlags);
DrawStateA_fun pDrawStateA = DrawStateA;
HOOK_TRACE_INFO hHookDrawStateA = { 0 };
ULONG HookDrawStateA_ACLEntries[1] = { 0 };
BOOL fake_DrawStateA(HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfnCallBack,LPARAM lData,WPARAM wData,int x,int y,int cx,int cy,UINT uFlags){
	BOOL ret = pDrawStateA(hdc,hbrFore,qfnCallBack,lData,wData,x,y,cx,cy,uFlags);
	fprintf(fp,"OUT ['DrawStateA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *GetMenuState_fun) (HMENU hMenu,UINT uId,UINT uFlags);
GetMenuState_fun pGetMenuState = GetMenuState;
HOOK_TRACE_INFO hHookGetMenuState = { 0 };
ULONG HookGetMenuState_ACLEntries[1] = { 0 };
UINT fake_GetMenuState(HMENU hMenu,UINT uId,UINT uFlags){
	UINT ret = pGetMenuState(hMenu,uId,uFlags);
	fprintf(fp,"OUT ['GetMenuState',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LRESULT (WINAPI *DefRawInputProc_fun) (PRAWINPUT*  paRawInput,INT nInput,UINT cbSizeHeader);
DefRawInputProc_fun pDefRawInputProc = DefRawInputProc;
HOOK_TRACE_INFO hHookDefRawInputProc = { 0 };
ULONG HookDefRawInputProc_ACLEntries[1] = { 0 };
LRESULT fake_DefRawInputProc(PRAWINPUT*  paRawInput,INT nInput,UINT cbSizeHeader){
	LRESULT ret = pDefRawInputProc( paRawInput,nInput,cbSizeHeader);
	fprintf(fp,"OUT ['DefRawInputProc',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LRESULT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LRESULT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *InvalidateRgn_fun) (HWND hWnd,HRGN hRgn,BOOL bErase);
InvalidateRgn_fun pInvalidateRgn = InvalidateRgn;
HOOK_TRACE_INFO hHookInvalidateRgn = { 0 };
ULONG HookInvalidateRgn_ACLEntries[1] = { 0 };
BOOL fake_InvalidateRgn(HWND hWnd,HRGN hRgn,BOOL bErase){
	BOOL ret = pInvalidateRgn(hWnd,hRgn,bErase);
	fprintf(fp,"OUT ['InvalidateRgn',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *InsertMenuItemW_fun) (HMENU hmenu,UINT item,BOOL fByPosition,LPCMENUITEMINFOW lpmi);
InsertMenuItemW_fun pInsertMenuItemW = InsertMenuItemW;
HOOK_TRACE_INFO hHookInsertMenuItemW = { 0 };
ULONG HookInsertMenuItemW_ACLEntries[1] = { 0 };
BOOL fake_InsertMenuItemW(HMENU hmenu,UINT item,BOOL fByPosition,LPCMENUITEMINFOW lpmi){
	BOOL ret = pInsertMenuItemW(hmenu,item,fByPosition,lpmi);
	fprintf(fp,"OUT ['InsertMenuItemW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *GetRawInputDeviceInfoA_fun) (HANDLE hDevice,UINT uiCommand,LPVOID pData,PUINT pcbSize);
GetRawInputDeviceInfoA_fun pGetRawInputDeviceInfoA = GetRawInputDeviceInfoA;
HOOK_TRACE_INFO hHookGetRawInputDeviceInfoA = { 0 };
ULONG HookGetRawInputDeviceInfoA_ACLEntries[1] = { 0 };
UINT fake_GetRawInputDeviceInfoA(HANDLE hDevice,UINT uiCommand,LPVOID pData,PUINT pcbSize){
	UINT ret = pGetRawInputDeviceInfoA(hDevice,uiCommand,pData,pcbSize);
	fprintf(fp,"OUT ['GetRawInputDeviceInfoA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pData','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pData, sizeof(LPVOID),1);
 	else fprintf(fp,"{'name':'pData','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pData,sizeof(LPVOID));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pcbSize','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pcbSize, sizeof(PUINT),1);
 	else fprintf(fp,"{'name':'pcbSize','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pcbSize,sizeof(PUINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetTitleBarInfo_fun) (HWND hwnd,PTITLEBARINFO pti);
GetTitleBarInfo_fun pGetTitleBarInfo = GetTitleBarInfo;
HOOK_TRACE_INFO hHookGetTitleBarInfo = { 0 };
ULONG HookGetTitleBarInfo_ACLEntries[1] = { 0 };
BOOL fake_GetTitleBarInfo(HWND hwnd,PTITLEBARINFO pti){
	BOOL ret = pGetTitleBarInfo(hwnd,pti);
	fprintf(fp,"OUT ['GetTitleBarInfo',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pti','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pti, sizeof(PTITLEBARINFO),1);
 	else fprintf(fp,"{'name':'pti','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pti,sizeof(PTITLEBARINFO));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsCharAlphaW_fun) (WCHAR ch);
IsCharAlphaW_fun pIsCharAlphaW = IsCharAlphaW;
HOOK_TRACE_INFO hHookIsCharAlphaW = { 0 };
ULONG HookIsCharAlphaW_ACLEntries[1] = { 0 };
BOOL fake_IsCharAlphaW(WCHAR ch){
	BOOL ret = pIsCharAlphaW(ch);
	fprintf(fp,"OUT ['IsCharAlphaW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *ToAscii_fun) (UINT uVirtKey,UINT uScanCode,CONST BYTE* lpKeyState,LPWORD lpChar,UINT uFlags);
ToAscii_fun pToAscii = ToAscii;
HOOK_TRACE_INFO hHookToAscii = { 0 };
ULONG HookToAscii_ACLEntries[1] = { 0 };
int fake_ToAscii(UINT uVirtKey,UINT uScanCode,CONST BYTE* lpKeyState,LPWORD lpChar,UINT uFlags){
	int ret = pToAscii(uVirtKey,uScanCode,lpKeyState,lpChar,uFlags);
	fprintf(fp,"OUT ['ToAscii',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpChar','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpChar, sizeof(LPWORD),1);
 	else fprintf(fp,"{'name':'lpChar','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpChar,sizeof(LPWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HMENU (WINAPI *LoadMenuA_fun) (HINSTANCE hInstance,LPCSTR lpMenuName);
LoadMenuA_fun pLoadMenuA = LoadMenuA;
HOOK_TRACE_INFO hHookLoadMenuA = { 0 };
ULONG HookLoadMenuA_ACLEntries[1] = { 0 };
HMENU fake_LoadMenuA(HINSTANCE hInstance,LPCSTR lpMenuName){
	HMENU ret = pLoadMenuA(hInstance,lpMenuName);
	fprintf(fp,"OUT ['LoadMenuA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HMENU),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HMENU));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EndDeferWindowPos_fun) (HDWP hWinPosInfo);
EndDeferWindowPos_fun pEndDeferWindowPos = EndDeferWindowPos;
HOOK_TRACE_INFO hHookEndDeferWindowPos = { 0 };
ULONG HookEndDeferWindowPos_ACLEntries[1] = { 0 };
BOOL fake_EndDeferWindowPos(HDWP hWinPosInfo){
	BOOL ret = pEndDeferWindowPos(hWinPosInfo);
	fprintf(fp,"OUT ['EndDeferWindowPos',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsZoomed_fun) (HWND hWnd);
IsZoomed_fun pIsZoomed = IsZoomed;
HOOK_TRACE_INFO hHookIsZoomed = { 0 };
ULONG HookIsZoomed_ACLEntries[1] = { 0 };
BOOL fake_IsZoomed(HWND hWnd){
	BOOL ret = pIsZoomed(hWnd);
	fprintf(fp,"OUT ['IsZoomed',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HICON (WINAPI *CreateIconIndirect_fun) (PICONINFO piconinfo);
CreateIconIndirect_fun pCreateIconIndirect = CreateIconIndirect;
HOOK_TRACE_INFO hHookCreateIconIndirect = { 0 };
ULONG HookCreateIconIndirect_ACLEntries[1] = { 0 };
HICON fake_CreateIconIndirect(PICONINFO piconinfo){
	HICON ret = pCreateIconIndirect(piconinfo);
	fprintf(fp,"OUT ['CreateIconIndirect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HICON),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HICON));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ReleaseCapture_fun) ();
ReleaseCapture_fun pReleaseCapture = ReleaseCapture;
HOOK_TRACE_INFO hHookReleaseCapture = { 0 };
ULONG HookReleaseCapture_ACLEntries[1] = { 0 };
BOOL fake_ReleaseCapture(){
	BOOL ret = pReleaseCapture();
	fprintf(fp,"OUT ['ReleaseCapture',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *GetTopWindow_fun) (HWND hWnd);
GetTopWindow_fun pGetTopWindow = GetTopWindow;
HOOK_TRACE_INFO hHookGetTopWindow = { 0 };
ULONG HookGetTopWindow_ACLEntries[1] = { 0 };
HWND fake_GetTopWindow(HWND hWnd){
	HWND ret = pGetTopWindow(hWnd);
	fprintf(fp,"OUT ['GetTopWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *CheckMenuRadioItem_fun) (HMENU hmenu,UINT first,UINT last,UINT check,UINT flags);
CheckMenuRadioItem_fun pCheckMenuRadioItem = CheckMenuRadioItem;
HOOK_TRACE_INFO hHookCheckMenuRadioItem = { 0 };
ULONG HookCheckMenuRadioItem_ACLEntries[1] = { 0 };
BOOL fake_CheckMenuRadioItem(HMENU hmenu,UINT first,UINT last,UINT check,UINT flags){
	BOOL ret = pCheckMenuRadioItem(hmenu,first,last,check,flags);
	fprintf(fp,"OUT ['CheckMenuRadioItem',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ClipCursor_fun) (CONST RECT* lpRect);
ClipCursor_fun pClipCursor = ClipCursor;
HOOK_TRACE_INFO hHookClipCursor = { 0 };
ULONG HookClipCursor_ACLEntries[1] = { 0 };
BOOL fake_ClipCursor(CONST RECT* lpRect){
	BOOL ret = pClipCursor(lpRect);
	fprintf(fp,"OUT ['ClipCursor',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsMenu_fun) (HMENU hMenu);
IsMenu_fun pIsMenu = IsMenu;
HOOK_TRACE_INFO hHookIsMenu = { 0 };
ULONG HookIsMenu_ACLEntries[1] = { 0 };
BOOL fake_IsMenu(HMENU hMenu){
	BOOL ret = pIsMenu(hMenu);
	fprintf(fp,"OUT ['IsMenu',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetGestureExtraArgs_fun) (HGESTUREINFO hGestureInfo,UINT cbExtraArgs,PBYTE pExtraArgs);
GetGestureExtraArgs_fun pGetGestureExtraArgs = GetGestureExtraArgs;
HOOK_TRACE_INFO hHookGetGestureExtraArgs = { 0 };
ULONG HookGetGestureExtraArgs_ACLEntries[1] = { 0 };
BOOL fake_GetGestureExtraArgs(HGESTUREINFO hGestureInfo,UINT cbExtraArgs,PBYTE pExtraArgs){
	BOOL ret = pGetGestureExtraArgs(hGestureInfo,cbExtraArgs,pExtraArgs);
	fprintf(fp,"OUT ['GetGestureExtraArgs',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pExtraArgs','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pExtraArgs, sizeof(PBYTE),1);
 	else fprintf(fp,"{'name':'pExtraArgs','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pExtraArgs,sizeof(PBYTE));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetMenuItemInfoA_fun) (HMENU hmenu,UINT item,BOOL fByPosition,LPMENUITEMINFOA lpmii);
GetMenuItemInfoA_fun pGetMenuItemInfoA = GetMenuItemInfoA;
HOOK_TRACE_INFO hHookGetMenuItemInfoA = { 0 };
ULONG HookGetMenuItemInfoA_ACLEntries[1] = { 0 };
BOOL fake_GetMenuItemInfoA(HMENU hmenu,UINT item,BOOL fByPosition,LPMENUITEMINFOA lpmii){
	BOOL ret = pGetMenuItemInfoA(hmenu,item,fByPosition,lpmii);
	fprintf(fp,"OUT ['GetMenuItemInfoA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpmii','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpmii, sizeof(LPMENUITEMINFOA),1);
 	else fprintf(fp,"{'name':'lpmii','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpmii,sizeof(LPMENUITEMINFOA));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsCharLowerA_fun) (CHAR ch);
IsCharLowerA_fun pIsCharLowerA = IsCharLowerA;
HOOK_TRACE_INFO hHookIsCharLowerA = { 0 };
ULONG HookIsCharLowerA_ACLEntries[1] = { 0 };
BOOL fake_IsCharLowerA(CHAR ch){
	BOOL ret = pIsCharLowerA(ch);
	fprintf(fp,"OUT ['IsCharLowerA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LRESULT (WINAPI *SendMessageW_fun) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
SendMessageW_fun pSendMessageW = SendMessageW;
HOOK_TRACE_INFO hHookSendMessageW = { 0 };
ULONG HookSendMessageW_ACLEntries[1] = { 0 };
LRESULT fake_SendMessageW(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pSendMessageW(hWnd,Msg,wParam,lParam);
	fprintf(fp,"OUT ['SendMessageW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LRESULT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LRESULT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetMonitorInfoA_fun) (HMONITOR hMonitor,LPMONITORINFO lpmi);
GetMonitorInfoA_fun pGetMonitorInfoA = GetMonitorInfoA;
HOOK_TRACE_INFO hHookGetMonitorInfoA = { 0 };
ULONG HookGetMonitorInfoA_ACLEntries[1] = { 0 };
BOOL fake_GetMonitorInfoA(HMONITOR hMonitor,LPMONITORINFO lpmi){
	BOOL ret = pGetMonitorInfoA(hMonitor,lpmi);
	fprintf(fp,"OUT ['GetMonitorInfoA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpmi','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpmi, sizeof(LPMONITORINFO),1);
 	else fprintf(fp,"{'name':'lpmi','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpmi,sizeof(LPMONITORINFO));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetAltTabInfoW_fun) (HWND hwnd,int iItem,PALTTABINFO pati,LPWSTR pszItemText,UINT cchItemText);
GetAltTabInfoW_fun pGetAltTabInfoW = GetAltTabInfoW;
HOOK_TRACE_INFO hHookGetAltTabInfoW = { 0 };
ULONG HookGetAltTabInfoW_ACLEntries[1] = { 0 };
BOOL fake_GetAltTabInfoW(HWND hwnd,int iItem,PALTTABINFO pati,LPWSTR pszItemText,UINT cchItemText){
	BOOL ret = pGetAltTabInfoW(hwnd,iItem,pati,pszItemText,cchItemText);
	fprintf(fp,"OUT ['GetAltTabInfoW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pati','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pati, sizeof(PALTTABINFO),1);
 	else fprintf(fp,"{'name':'pati','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pati,sizeof(PALTTABINFO));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'pszItemText',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': %p,", pszItemText);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': %p,", pszItemText);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),cchItemText);
 	}else 
	{
		fprintf(fp,"{'name':'pszItemText',");
		fwprintf(fp, L"'value': %p, ", pszItemText);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	if(pszItemText){
		for(int i=0; i<cchItemText;i++){
			fprintf(fp,"0x%x,",pszItemText[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GrayStringA_fun) (HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lpData,int nCount,int X,int Y,int nWidth,int nHeight);
GrayStringA_fun pGrayStringA = GrayStringA;
HOOK_TRACE_INFO hHookGrayStringA = { 0 };
ULONG HookGrayStringA_ACLEntries[1] = { 0 };
BOOL fake_GrayStringA(HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lpData,int nCount,int X,int Y,int nWidth,int nHeight){
	BOOL ret = pGrayStringA(hDC,hBrush,lpOutputFunc,lpData,nCount,X,Y,nWidth,nHeight);
	fprintf(fp,"OUT ['GrayStringA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SendMessageCallbackW_fun) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lpResultCallBack,ULONG_PTR dwData);
SendMessageCallbackW_fun pSendMessageCallbackW = SendMessageCallbackW;
HOOK_TRACE_INFO hHookSendMessageCallbackW = { 0 };
ULONG HookSendMessageCallbackW_ACLEntries[1] = { 0 };
BOOL fake_SendMessageCallbackW(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lpResultCallBack,ULONG_PTR dwData){
	BOOL ret = pSendMessageCallbackW(hWnd,Msg,wParam,lParam,lpResultCallBack,dwData);
	fprintf(fp,"OUT ['SendMessageCallbackW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *GetRawInputData_fun) (HRAWINPUT hRawInput,UINT uiCommand,LPVOID pData,PUINT pcbSize,UINT cbSizeHeader);
GetRawInputData_fun pGetRawInputData = GetRawInputData;
HOOK_TRACE_INFO hHookGetRawInputData = { 0 };
ULONG HookGetRawInputData_ACLEntries[1] = { 0 };
UINT fake_GetRawInputData(HRAWINPUT hRawInput,UINT uiCommand,LPVOID pData,PUINT pcbSize,UINT cbSizeHeader){
	UINT ret = pGetRawInputData(hRawInput,uiCommand,pData,pcbSize,cbSizeHeader);
	fprintf(fp,"OUT ['GetRawInputData',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pData','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pData, sizeof(LPVOID),1);
 	else fprintf(fp,"{'name':'pData','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pData,sizeof(LPVOID));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pcbSize','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pcbSize, sizeof(PUINT),1);
 	else fprintf(fp,"{'name':'pcbSize','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pcbSize,sizeof(PUINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *GetClipboardFormatNameA_fun) (UINT format,LPSTR lpszFormatName,int cchMaxCount);
GetClipboardFormatNameA_fun pGetClipboardFormatNameA = GetClipboardFormatNameA;
HOOK_TRACE_INFO hHookGetClipboardFormatNameA = { 0 };
ULONG HookGetClipboardFormatNameA_ACLEntries[1] = { 0 };
int fake_GetClipboardFormatNameA(UINT format,LPSTR lpszFormatName,int cchMaxCount){
	int ret = pGetClipboardFormatNameA(format,lpszFormatName,cchMaxCount);
	fprintf(fp,"OUT ['GetClipboardFormatNameA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpszFormatName','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpszFormatName, sizeof(LPSTR),cchMaxCount);
 	else fprintf(fp,"{'name':'lpszFormatName','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpszFormatName,sizeof(LPSTR));
	if(lpszFormatName){
		for(int i=0; i<cchMaxCount;i++){
			fprintf(fp,"0x%x,",lpszFormatName[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *GetWindow_fun) (HWND hWnd,UINT uCmd);
GetWindow_fun pGetWindow = GetWindow;
HOOK_TRACE_INFO hHookGetWindow = { 0 };
ULONG HookGetWindow_ACLEntries[1] = { 0 };
HWND fake_GetWindow(HWND hWnd,UINT uCmd){
	HWND ret = pGetWindow(hWnd,uCmd);
	fprintf(fp,"OUT ['GetWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ExitWindowsEx_fun) (UINT uFlags,DWORD dwReason);
ExitWindowsEx_fun pExitWindowsEx = ExitWindowsEx;
HOOK_TRACE_INFO hHookExitWindowsEx = { 0 };
ULONG HookExitWindowsEx_ACLEntries[1] = { 0 };
BOOL fake_ExitWindowsEx(UINT uFlags,DWORD dwReason){
	BOOL ret = pExitWindowsEx(uFlags,dwReason);
	fprintf(fp,"OUT ['ExitWindowsEx',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *GetClipboardSequenceNumber_fun) ();
GetClipboardSequenceNumber_fun pGetClipboardSequenceNumber = GetClipboardSequenceNumber;
HOOK_TRACE_INFO hHookGetClipboardSequenceNumber = { 0 };
ULONG HookGetClipboardSequenceNumber_ACLEntries[1] = { 0 };
DWORD fake_GetClipboardSequenceNumber(){
	DWORD ret = pGetClipboardSequenceNumber();
	fprintf(fp,"OUT ['GetClipboardSequenceNumber',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *OemToCharBuffA_fun) (LPCSTR lpszSrc,LPSTR lpszDst,DWORD cchDstLength);
OemToCharBuffA_fun pOemToCharBuffA = OemToCharBuffA;
HOOK_TRACE_INFO hHookOemToCharBuffA = { 0 };
ULONG HookOemToCharBuffA_ACLEntries[1] = { 0 };
BOOL fake_OemToCharBuffA(LPCSTR lpszSrc,LPSTR lpszDst,DWORD cchDstLength){
	BOOL ret = pOemToCharBuffA(lpszSrc,lpszDst,cchDstLength);
	fprintf(fp,"OUT ['OemToCharBuffA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpszDst','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpszDst, sizeof(LPSTR),cchDstLength);
 	else fprintf(fp,"{'name':'lpszDst','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpszDst,sizeof(LPSTR));
	if(lpszDst){
		for(int i=0; i<cchDstLength;i++){
			fprintf(fp,"0x%x,",lpszDst[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *UserHandleGrantAccess_fun) (HANDLE hUserHandle,HANDLE hJob,BOOL bGrant);
UserHandleGrantAccess_fun pUserHandleGrantAccess = UserHandleGrantAccess;
HOOK_TRACE_INFO hHookUserHandleGrantAccess = { 0 };
ULONG HookUserHandleGrantAccess_ACLEntries[1] = { 0 };
BOOL fake_UserHandleGrantAccess(HANDLE hUserHandle,HANDLE hJob,BOOL bGrant){
	BOOL ret = pUserHandleGrantAccess(hUserHandle,hJob,bGrant);
	fprintf(fp,"OUT ['UserHandleGrantAccess',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ScrollWindow_fun) (HWND hWnd,int XAmount,int YAmount,CONST RECT* lpRect,CONST RECT* lpClipRect);
ScrollWindow_fun pScrollWindow = ScrollWindow;
HOOK_TRACE_INFO hHookScrollWindow = { 0 };
ULONG HookScrollWindow_ACLEntries[1] = { 0 };
BOOL fake_ScrollWindow(HWND hWnd,int XAmount,int YAmount,CONST RECT* lpRect,CONST RECT* lpClipRect){
	BOOL ret = pScrollWindow(hWnd,XAmount,YAmount,lpRect,lpClipRect);
	fprintf(fp,"OUT ['ScrollWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetSystemCursor_fun) (HCURSOR hcur,DWORD id);
SetSystemCursor_fun pSetSystemCursor = SetSystemCursor;
HOOK_TRACE_INFO hHookSetSystemCursor = { 0 };
ULONG HookSetSystemCursor_ACLEntries[1] = { 0 };
BOOL fake_SetSystemCursor(HCURSOR hcur,DWORD id){
	BOOL ret = pSetSystemCursor(hcur,id);
	fprintf(fp,"OUT ['SetSystemCursor',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *GetOpenClipboardWindow_fun) ();
GetOpenClipboardWindow_fun pGetOpenClipboardWindow = GetOpenClipboardWindow;
HOOK_TRACE_INFO hHookGetOpenClipboardWindow = { 0 };
ULONG HookGetOpenClipboardWindow_ACLEntries[1] = { 0 };
HWND fake_GetOpenClipboardWindow(){
	HWND ret = pGetOpenClipboardWindow();
	fprintf(fp,"OUT ['GetOpenClipboardWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *SetClassLongA_fun) (HWND hWnd,int nIndex,LONG dwNewLong);
SetClassLongA_fun pSetClassLongA = SetClassLongA;
HOOK_TRACE_INFO hHookSetClassLongA = { 0 };
ULONG HookSetClassLongA_ACLEntries[1] = { 0 };
DWORD fake_SetClassLongA(HWND hWnd,int nIndex,LONG dwNewLong){
	DWORD ret = pSetClassLongA(hWnd,nIndex,dwNewLong);
	fprintf(fp,"OUT ['SetClassLongA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsCharAlphaNumericA_fun) (CHAR ch);
IsCharAlphaNumericA_fun pIsCharAlphaNumericA = IsCharAlphaNumericA;
HOOK_TRACE_INFO hHookIsCharAlphaNumericA = { 0 };
ULONG HookIsCharAlphaNumericA_ACLEntries[1] = { 0 };
BOOL fake_IsCharAlphaNumericA(CHAR ch){
	BOOL ret = pIsCharAlphaNumericA(ch);
	fprintf(fp,"OUT ['IsCharAlphaNumericA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *GetMouseMovePointsEx_fun) (UINT cbSize,LPMOUSEMOVEPOINT lppt,LPMOUSEMOVEPOINT lpptBuf,int nBufPoints,DWORD resolution);
GetMouseMovePointsEx_fun pGetMouseMovePointsEx = GetMouseMovePointsEx;
HOOK_TRACE_INFO hHookGetMouseMovePointsEx = { 0 };
ULONG HookGetMouseMovePointsEx_ACLEntries[1] = { 0 };
int fake_GetMouseMovePointsEx(UINT cbSize,LPMOUSEMOVEPOINT lppt,LPMOUSEMOVEPOINT lpptBuf,int nBufPoints,DWORD resolution){
	int ret = pGetMouseMovePointsEx(cbSize,lppt,lpptBuf,nBufPoints,resolution);
	fprintf(fp,"OUT ['GetMouseMovePointsEx',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpptBuf','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpptBuf, sizeof(LPMOUSEMOVEPOINT),nBufPoints);
 	else fprintf(fp,"{'name':'lpptBuf','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpptBuf,sizeof(LPMOUSEMOVEPOINT));
	if(lpptBuf){
		for(int i=0; i<nBufPoints;i++){
			fprintf(fp,"0x%x,",lpptBuf[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *GetMenuItemID_fun) (HMENU hMenu,int nPos);
GetMenuItemID_fun pGetMenuItemID = GetMenuItemID;
HOOK_TRACE_INFO hHookGetMenuItemID = { 0 };
ULONG HookGetMenuItemID_ACLEntries[1] = { 0 };
UINT fake_GetMenuItemID(HMENU hMenu,int nPos){
	UINT ret = pGetMenuItemID(hMenu,nPos);
	fprintf(fp,"OUT ['GetMenuItemID',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *CheckMenuItem_fun) (HMENU hMenu,UINT uIDCheckItem,UINT uCheck);
CheckMenuItem_fun pCheckMenuItem = CheckMenuItem;
HOOK_TRACE_INFO hHookCheckMenuItem = { 0 };
ULONG HookCheckMenuItem_ACLEntries[1] = { 0 };
DWORD fake_CheckMenuItem(HMENU hMenu,UINT uIDCheckItem,UINT uCheck){
	DWORD ret = pCheckMenuItem(hMenu,uIDCheckItem,uCheck);
	fprintf(fp,"OUT ['CheckMenuItem',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *GetClipboardViewer_fun) ();
GetClipboardViewer_fun pGetClipboardViewer = GetClipboardViewer;
HOOK_TRACE_INFO hHookGetClipboardViewer = { 0 };
ULONG HookGetClipboardViewer_ACLEntries[1] = { 0 };
HWND fake_GetClipboardViewer(){
	HWND ret = pGetClipboardViewer();
	fprintf(fp,"OUT ['GetClipboardViewer',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *GetActiveWindow_fun) ();
GetActiveWindow_fun pGetActiveWindow = GetActiveWindow;
HOOK_TRACE_INFO hHookGetActiveWindow = { 0 };
ULONG HookGetActiveWindow_ACLEntries[1] = { 0 };
HWND fake_GetActiveWindow(){
	HWND ret = pGetActiveWindow();
	fprintf(fp,"OUT ['GetActiveWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetProcessDPIAware_fun) ();
SetProcessDPIAware_fun pSetProcessDPIAware = SetProcessDPIAware;
HOOK_TRACE_INFO hHookSetProcessDPIAware = { 0 };
ULONG HookSetProcessDPIAware_ACLEntries[1] = { 0 };
BOOL fake_SetProcessDPIAware(){
	BOOL ret = pSetProcessDPIAware();
	fprintf(fp,"OUT ['SetProcessDPIAware',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *SetScrollInfo_fun) (HWND hwnd,int nBar,LPCSCROLLINFO lpsi,BOOL redraw);
SetScrollInfo_fun pSetScrollInfo = SetScrollInfo;
HOOK_TRACE_INFO hHookSetScrollInfo = { 0 };
ULONG HookSetScrollInfo_ACLEntries[1] = { 0 };
int fake_SetScrollInfo(HWND hwnd,int nBar,LPCSCROLLINFO lpsi,BOOL redraw){
	int ret = pSetScrollInfo(hwnd,nBar,lpsi,redraw);
	fprintf(fp,"OUT ['SetScrollInfo',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *MapVirtualKeyW_fun) (UINT uCode,UINT uMapType);
MapVirtualKeyW_fun pMapVirtualKeyW = MapVirtualKeyW;
HOOK_TRACE_INFO hHookMapVirtualKeyW = { 0 };
ULONG HookMapVirtualKeyW_ACLEntries[1] = { 0 };
UINT fake_MapVirtualKeyW(UINT uCode,UINT uMapType){
	UINT ret = pMapVirtualKeyW(uCode,uMapType);
	fprintf(fp,"OUT ['MapVirtualKeyW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetMessageW_fun) (LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax);
GetMessageW_fun pGetMessageW = GetMessageW;
HOOK_TRACE_INFO hHookGetMessageW = { 0 };
ULONG HookGetMessageW_ACLEntries[1] = { 0 };
BOOL fake_GetMessageW(LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax){
	BOOL ret = pGetMessageW(lpMsg,hWnd,wMsgFilterMin,wMsgFilterMax);
	fprintf(fp,"OUT ['GetMessageW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpMsg','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpMsg, sizeof(LPMSG),1);
 	else fprintf(fp,"{'name':'lpMsg','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpMsg,sizeof(LPMSG));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetWindowContextHelpId_fun) (HWND arg0,DWORD arg1);
SetWindowContextHelpId_fun pSetWindowContextHelpId = SetWindowContextHelpId;
HOOK_TRACE_INFO hHookSetWindowContextHelpId = { 0 };
ULONG HookSetWindowContextHelpId_ACLEntries[1] = { 0 };
BOOL fake_SetWindowContextHelpId(HWND arg0,DWORD arg1){
	BOOL ret = pSetWindowContextHelpId(arg0,arg1);
	fprintf(fp,"OUT ['SetWindowContextHelpId',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetMessageA_fun) (LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax);
GetMessageA_fun pGetMessageA = GetMessageA;
HOOK_TRACE_INFO hHookGetMessageA = { 0 };
ULONG HookGetMessageA_ACLEntries[1] = { 0 };
BOOL fake_GetMessageA(LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax){
	BOOL ret = pGetMessageA(lpMsg,hWnd,wMsgFilterMin,wMsgFilterMax);
	fprintf(fp,"OUT ['GetMessageA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpMsg','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpMsg, sizeof(LPMSG),1);
 	else fprintf(fp,"{'name':'lpMsg','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpMsg,sizeof(LPMSG));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SystemParametersInfoA_fun) (UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni);
SystemParametersInfoA_fun pSystemParametersInfoA = SystemParametersInfoA;
HOOK_TRACE_INFO hHookSystemParametersInfoA = { 0 };
ULONG HookSystemParametersInfoA_ACLEntries[1] = { 0 };
BOOL fake_SystemParametersInfoA(UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni){
	BOOL ret = pSystemParametersInfoA(uiAction,uiParam,pvParam,fWinIni);
	fprintf(fp,"OUT ['SystemParametersInfoA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pvParam','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pvParam, sizeof(PVOID),1);
 	else fprintf(fp,"{'name':'pvParam','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pvParam,sizeof(PVOID));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HMENU (WINAPI *LoadMenuIndirectA_fun) (CONST MENUTEMPLATEA* lpMenuTemplate);
LoadMenuIndirectA_fun pLoadMenuIndirectA = LoadMenuIndirectA;
HOOK_TRACE_INFO hHookLoadMenuIndirectA = { 0 };
ULONG HookLoadMenuIndirectA_ACLEntries[1] = { 0 };
HMENU fake_LoadMenuIndirectA(CONST MENUTEMPLATEA* lpMenuTemplate){
	HMENU ret = pLoadMenuIndirectA(lpMenuTemplate);
	fprintf(fp,"OUT ['LoadMenuIndirectA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HMENU),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HMENU));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetClassInfoExW_fun) (HINSTANCE hInstance,LPCWSTR lpszClass,LPWNDCLASSEXW lpwcx);
GetClassInfoExW_fun pGetClassInfoExW = GetClassInfoExW;
HOOK_TRACE_INFO hHookGetClassInfoExW = { 0 };
ULONG HookGetClassInfoExW_ACLEntries[1] = { 0 };
BOOL fake_GetClassInfoExW(HINSTANCE hInstance,LPCWSTR lpszClass,LPWNDCLASSEXW lpwcx){
	BOOL ret = pGetClassInfoExW(hInstance,lpszClass,lpwcx);
	fprintf(fp,"OUT ['GetClassInfoExW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpwcx','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpwcx, sizeof(LPWNDCLASSEXW),1);
 	else fprintf(fp,"{'name':'lpwcx','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpwcx,sizeof(LPWNDCLASSEXW));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *EnumPropsExA_fun) (HWND hWnd,PROPENUMPROCEXA lpEnumFunc,LPARAM lParam);
EnumPropsExA_fun pEnumPropsExA = EnumPropsExA;
HOOK_TRACE_INFO hHookEnumPropsExA = { 0 };
ULONG HookEnumPropsExA_ACLEntries[1] = { 0 };
int fake_EnumPropsExA(HWND hWnd,PROPENUMPROCEXA lpEnumFunc,LPARAM lParam){
	int ret = pEnumPropsExA(hWnd,lpEnumFunc,lParam);
	fprintf(fp,"OUT ['EnumPropsExA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HMENU (WINAPI *LoadMenuW_fun) (HINSTANCE hInstance,LPCWSTR lpMenuName);
LoadMenuW_fun pLoadMenuW = LoadMenuW;
HOOK_TRACE_INFO hHookLoadMenuW = { 0 };
ULONG HookLoadMenuW_ACLEntries[1] = { 0 };
HMENU fake_LoadMenuW(HINSTANCE hInstance,LPCWSTR lpMenuName){
	HMENU ret = pLoadMenuW(hInstance,lpMenuName);
	fprintf(fp,"OUT ['LoadMenuW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HMENU),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HMENU));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *InsertMenuW_fun) (HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCWSTR lpNewItem);
InsertMenuW_fun pInsertMenuW = InsertMenuW;
HOOK_TRACE_INFO hHookInsertMenuW = { 0 };
ULONG HookInsertMenuW_ACLEntries[1] = { 0 };
BOOL fake_InsertMenuW(HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCWSTR lpNewItem){
	BOOL ret = pInsertMenuW(hMenu,uPosition,uFlags,uIDNewItem,lpNewItem);
	fprintf(fp,"OUT ['InsertMenuW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetDlgItemTextA_fun) (HWND hDlg,int nIDDlgItem,LPCSTR lpString);
SetDlgItemTextA_fun pSetDlgItemTextA = SetDlgItemTextA;
HOOK_TRACE_INFO hHookSetDlgItemTextA = { 0 };
ULONG HookSetDlgItemTextA_ACLEntries[1] = { 0 };
BOOL fake_SetDlgItemTextA(HWND hDlg,int nIDDlgItem,LPCSTR lpString){
	BOOL ret = pSetDlgItemTextA(hDlg,nIDDlgItem,lpString);
	fprintf(fp,"OUT ['SetDlgItemTextA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *FindWindowExA_fun) (HWND hWndParent,HWND hWndChildAfter,LPCSTR lpszClass,LPCSTR lpszWindow);
FindWindowExA_fun pFindWindowExA = FindWindowExA;
HOOK_TRACE_INFO hHookFindWindowExA = { 0 };
ULONG HookFindWindowExA_ACLEntries[1] = { 0 };
HWND fake_FindWindowExA(HWND hWndParent,HWND hWndChildAfter,LPCSTR lpszClass,LPCSTR lpszWindow){
	HWND ret = pFindWindowExA(hWndParent,hWndChildAfter,lpszClass,lpszWindow);
	fprintf(fp,"OUT ['FindWindowExA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LRESULT (WINAPI *SendDlgItemMessageW_fun) (HWND hDlg,int nIDDlgItem,UINT Msg,WPARAM wParam,LPARAM lParam);
SendDlgItemMessageW_fun pSendDlgItemMessageW = SendDlgItemMessageW;
HOOK_TRACE_INFO hHookSendDlgItemMessageW = { 0 };
ULONG HookSendDlgItemMessageW_ACLEntries[1] = { 0 };
LRESULT fake_SendDlgItemMessageW(HWND hDlg,int nIDDlgItem,UINT Msg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pSendDlgItemMessageW(hDlg,nIDDlgItem,Msg,wParam,lParam);
	fprintf(fp,"OUT ['SendDlgItemMessageW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LRESULT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LRESULT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetTouchInputInfo_fun) (HTOUCHINPUT hTouchInput,UINT cInputs,PTOUCHINPUT pInputs,int cbSize);
GetTouchInputInfo_fun pGetTouchInputInfo = GetTouchInputInfo;
HOOK_TRACE_INFO hHookGetTouchInputInfo = { 0 };
ULONG HookGetTouchInputInfo_ACLEntries[1] = { 0 };
BOOL fake_GetTouchInputInfo(HTOUCHINPUT hTouchInput,UINT cInputs,PTOUCHINPUT pInputs,int cbSize){
	BOOL ret = pGetTouchInputInfo(hTouchInput,cInputs,pInputs,cbSize);
	fprintf(fp,"OUT ['GetTouchInputInfo',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pInputs','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pInputs, sizeof(PTOUCHINPUT),cInputs);
 	else fprintf(fp,"{'name':'pInputs','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pInputs,sizeof(PTOUCHINPUT));
	if(pInputs){
		for(int i=0; i<cInputs;i++){
			fprintf(fp,"0x%x,",pInputs[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LRESULT (WINAPI *SendMessageTimeoutA_fun) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdwResult);
SendMessageTimeoutA_fun pSendMessageTimeoutA = SendMessageTimeoutA;
HOOK_TRACE_INFO hHookSendMessageTimeoutA = { 0 };
ULONG HookSendMessageTimeoutA_ACLEntries[1] = { 0 };
LRESULT fake_SendMessageTimeoutA(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdwResult){
	LRESULT ret = pSendMessageTimeoutA(hWnd,Msg,wParam,lParam,fuFlags,uTimeout,lpdwResult);
	fprintf(fp,"OUT ['SendMessageTimeoutA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LRESULT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LRESULT));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpdwResult','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpdwResult, sizeof(PDWORD_PTR),1);
 	else fprintf(fp,"{'name':'lpdwResult','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpdwResult,sizeof(PDWORD_PTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetMenuItemBitmaps_fun) (HMENU hMenu,UINT uPosition,UINT uFlags,HBITMAP hBitmapUnchecked,HBITMAP hBitmapChecked);
SetMenuItemBitmaps_fun pSetMenuItemBitmaps = SetMenuItemBitmaps;
HOOK_TRACE_INFO hHookSetMenuItemBitmaps = { 0 };
ULONG HookSetMenuItemBitmaps_ACLEntries[1] = { 0 };
BOOL fake_SetMenuItemBitmaps(HMENU hMenu,UINT uPosition,UINT uFlags,HBITMAP hBitmapUnchecked,HBITMAP hBitmapChecked){
	BOOL ret = pSetMenuItemBitmaps(hMenu,uPosition,uFlags,hBitmapUnchecked,hBitmapChecked);
	fprintf(fp,"OUT ['SetMenuItemBitmaps',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef VOID (WINAPI *SetDebugErrorLevel_fun) (DWORD dwLevel);
SetDebugErrorLevel_fun pSetDebugErrorLevel = SetDebugErrorLevel;
HOOK_TRACE_INFO hHookSetDebugErrorLevel = { 0 };
ULONG HookSetDebugErrorLevel_ACLEntries[1] = { 0 };
VOID fake_SetDebugErrorLevel(DWORD dwLevel){
	pSetDebugErrorLevel(dwLevel);
	fprintf(fp,"OUT ['SetDebugErrorLevel',");
	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
}


typedef BOOL (WINAPI *UnregisterClassA_fun) (LPCSTR lpClassName,HINSTANCE hInstance);
UnregisterClassA_fun pUnregisterClassA = UnregisterClassA;
HOOK_TRACE_INFO hHookUnregisterClassA = { 0 };
ULONG HookUnregisterClassA_ACLEntries[1] = { 0 };
BOOL fake_UnregisterClassA(LPCSTR lpClassName,HINSTANCE hInstance){
	BOOL ret = pUnregisterClassA(lpClassName,hInstance);
	fprintf(fp,"OUT ['UnregisterClassA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *GetCaretBlinkTime_fun) ();
GetCaretBlinkTime_fun pGetCaretBlinkTime = GetCaretBlinkTime;
HOOK_TRACE_INFO hHookGetCaretBlinkTime = { 0 };
ULONG HookGetCaretBlinkTime_ACLEntries[1] = { 0 };
UINT fake_GetCaretBlinkTime(){
	UINT ret = pGetCaretBlinkTime();
	fprintf(fp,"OUT ['GetCaretBlinkTime',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *CreateMDIWindowW_fun) (LPCWSTR lpClassName,LPCWSTR lpWindowName,DWORD dwStyle,int X,int Y,int nWidth,int nHeight,HWND hWndParent,HINSTANCE hInstance,LPARAM lParam);
CreateMDIWindowW_fun pCreateMDIWindowW = CreateMDIWindowW;
HOOK_TRACE_INFO hHookCreateMDIWindowW = { 0 };
ULONG HookCreateMDIWindowW_ACLEntries[1] = { 0 };
HWND fake_CreateMDIWindowW(LPCWSTR lpClassName,LPCWSTR lpWindowName,DWORD dwStyle,int X,int Y,int nWidth,int nHeight,HWND hWndParent,HINSTANCE hInstance,LPARAM lParam){
	HWND ret = pCreateMDIWindowW(lpClassName,lpWindowName,dwStyle,X,Y,nWidth,nHeight,hWndParent,hInstance,lParam);
	fprintf(fp,"OUT ['CreateMDIWindowW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *OpenIcon_fun) (HWND hWnd);
OpenIcon_fun pOpenIcon = OpenIcon;
HOOK_TRACE_INFO hHookOpenIcon = { 0 };
ULONG HookOpenIcon_ACLEntries[1] = { 0 };
BOOL fake_OpenIcon(HWND hWnd){
	BOOL ret = pOpenIcon(hWnd);
	fprintf(fp,"OUT ['OpenIcon',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HDEVNOTIFY (WINAPI *RegisterDeviceNotificationW_fun) (HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags);
RegisterDeviceNotificationW_fun pRegisterDeviceNotificationW = RegisterDeviceNotificationW;
HOOK_TRACE_INFO hHookRegisterDeviceNotificationW = { 0 };
ULONG HookRegisterDeviceNotificationW_ACLEntries[1] = { 0 };
HDEVNOTIFY fake_RegisterDeviceNotificationW(HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags){
	HDEVNOTIFY ret = pRegisterDeviceNotificationW(hRecipient,NotificationFilter,Flags);
	fprintf(fp,"OUT ['RegisterDeviceNotificationW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HDEVNOTIFY),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HDEVNOTIFY));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef SHORT (WINAPI *GetAsyncKeyState_fun) (int vKey);
GetAsyncKeyState_fun pGetAsyncKeyState = GetAsyncKeyState;
HOOK_TRACE_INFO hHookGetAsyncKeyState = { 0 };
ULONG HookGetAsyncKeyState_ACLEntries[1] = { 0 };
SHORT fake_GetAsyncKeyState(int vKey){
	SHORT ret = pGetAsyncKeyState(vKey);
	fprintf(fp,"OUT ['GetAsyncKeyState',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%hx,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(SHORT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%hx, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(SHORT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetWindowInfo_fun) (HWND hwnd,PWINDOWINFO pwi);
GetWindowInfo_fun pGetWindowInfo = GetWindowInfo;
HOOK_TRACE_INFO hHookGetWindowInfo = { 0 };
ULONG HookGetWindowInfo_ACLEntries[1] = { 0 };
BOOL fake_GetWindowInfo(HWND hwnd,PWINDOWINFO pwi){
	BOOL ret = pGetWindowInfo(hwnd,pwi);
	fprintf(fp,"OUT ['GetWindowInfo',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pwi','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pwi, sizeof(PWINDOWINFO),1);
 	else fprintf(fp,"{'name':'pwi','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pwi,sizeof(PWINDOWINFO));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsCharAlphaA_fun) (CHAR ch);
IsCharAlphaA_fun pIsCharAlphaA = IsCharAlphaA;
HOOK_TRACE_INFO hHookIsCharAlphaA = { 0 };
ULONG HookIsCharAlphaA_ACLEntries[1] = { 0 };
BOOL fake_IsCharAlphaA(CHAR ch){
	BOOL ret = pIsCharAlphaA(ch);
	fprintf(fp,"OUT ['IsCharAlphaA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *SetParent_fun) (HWND hWndChild,HWND hWndNewParent);
SetParent_fun pSetParent = SetParent;
HOOK_TRACE_INFO hHookSetParent = { 0 };
ULONG HookSetParent_ACLEntries[1] = { 0 };
HWND fake_SetParent(HWND hWndChild,HWND hWndNewParent){
	HWND ret = pSetParent(hWndChild,hWndNewParent);
	fprintf(fp,"OUT ['SetParent',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *DrawFocusRect_fun) (HDC hDC,CONST RECT*  lprc);
DrawFocusRect_fun pDrawFocusRect = DrawFocusRect;
HOOK_TRACE_INFO hHookDrawFocusRect = { 0 };
ULONG HookDrawFocusRect_ACLEntries[1] = { 0 };
BOOL fake_DrawFocusRect(HDC hDC,CONST RECT*  lprc){
	BOOL ret = pDrawFocusRect(hDC, lprc);
	fprintf(fp,"OUT ['DrawFocusRect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *ToUnicode_fun) (UINT wVirtKey,UINT wScanCode,CONST BYTE* lpKeyState,LPWSTR pwszBuff,int cchBuff,UINT wFlags);
ToUnicode_fun pToUnicode = ToUnicode;
HOOK_TRACE_INFO hHookToUnicode = { 0 };
ULONG HookToUnicode_ACLEntries[1] = { 0 };
int fake_ToUnicode(UINT wVirtKey,UINT wScanCode,CONST BYTE* lpKeyState,LPWSTR pwszBuff,int cchBuff,UINT wFlags){
	int ret = pToUnicode(wVirtKey,wScanCode,lpKeyState,pwszBuff,cchBuff,wFlags);
	fprintf(fp,"OUT ['ToUnicode',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'pwszBuff',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': %p,", pwszBuff);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': %p,", pwszBuff);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),cchBuff);
 	}else 
	{
		fprintf(fp,"{'name':'pwszBuff',");
		fwprintf(fp, L"'value': %p, ", pwszBuff);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	if(pwszBuff){
		for(int i=0; i<cchBuff;i++){
			fprintf(fp,"0x%x,",pwszBuff[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *MessageBoxExA_fun) (HWND hWnd,LPCSTR lpText,LPCSTR lpCaption,UINT uType,WORD wLanguageId);
MessageBoxExA_fun pMessageBoxExA = MessageBoxExA;
HOOK_TRACE_INFO hHookMessageBoxExA = { 0 };
ULONG HookMessageBoxExA_ACLEntries[1] = { 0 };
int fake_MessageBoxExA(HWND hWnd,LPCSTR lpText,LPCSTR lpCaption,UINT uType,WORD wLanguageId){
	int ret = pMessageBoxExA(hWnd,lpText,lpCaption,uType,wLanguageId);
	fprintf(fp,"OUT ['MessageBoxExA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *BringWindowToTop_fun) (HWND hWnd);
BringWindowToTop_fun pBringWindowToTop = BringWindowToTop;
HOOK_TRACE_INFO hHookBringWindowToTop = { 0 };
ULONG HookBringWindowToTop_ACLEntries[1] = { 0 };
BOOL fake_BringWindowToTop(HWND hWnd){
	BOOL ret = pBringWindowToTop(hWnd);
	fprintf(fp,"OUT ['BringWindowToTop',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *CreateMDIWindowA_fun) (LPCSTR lpClassName,LPCSTR lpWindowName,DWORD dwStyle,int X,int Y,int nWidth,int nHeight,HWND hWndParent,HINSTANCE hInstance,LPARAM lParam);
CreateMDIWindowA_fun pCreateMDIWindowA = CreateMDIWindowA;
HOOK_TRACE_INFO hHookCreateMDIWindowA = { 0 };
ULONG HookCreateMDIWindowA_ACLEntries[1] = { 0 };
HWND fake_CreateMDIWindowA(LPCSTR lpClassName,LPCSTR lpWindowName,DWORD dwStyle,int X,int Y,int nWidth,int nHeight,HWND hWndParent,HINSTANCE hInstance,LPARAM lParam){
	HWND ret = pCreateMDIWindowA(lpClassName,lpWindowName,dwStyle,X,Y,nWidth,nHeight,hWndParent,hInstance,lParam);
	fprintf(fp,"OUT ['CreateMDIWindowA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *ShowCursor_fun) (BOOL bShow);
ShowCursor_fun pShowCursor = ShowCursor;
HOOK_TRACE_INFO hHookShowCursor = { 0 };
ULONG HookShowCursor_ACLEntries[1] = { 0 };
int fake_ShowCursor(BOOL bShow){
	int ret = pShowCursor(bShow);
	fprintf(fp,"OUT ['ShowCursor',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *PrintWindow_fun) (HWND hwnd,HDC hdcBlt,UINT nFlags);
PrintWindow_fun pPrintWindow = PrintWindow;
HOOK_TRACE_INFO hHookPrintWindow = { 0 };
ULONG HookPrintWindow_ACLEntries[1] = { 0 };
BOOL fake_PrintWindow(HWND hwnd,HDC hdcBlt,UINT nFlags){
	BOOL ret = pPrintWindow(hwnd,hdcBlt,nFlags);
	fprintf(fp,"OUT ['PrintWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LONG_PTR (WINAPI *GetWindowLongPtrA_fun) (HWND hWnd,int nIndex);
GetWindowLongPtrA_fun pGetWindowLongPtrA = GetWindowLongPtrA;
HOOK_TRACE_INFO hHookGetWindowLongPtrA = { 0 };
ULONG HookGetWindowLongPtrA_ACLEntries[1] = { 0 };
LONG_PTR fake_GetWindowLongPtrA(HWND hWnd,int nIndex){
	LONG_PTR ret = pGetWindowLongPtrA(hWnd,nIndex);
	fprintf(fp,"OUT ['GetWindowLongPtrA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LONG_PTR),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LONG_PTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ModifyMenuA_fun) (HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCSTR lpNewItem);
ModifyMenuA_fun pModifyMenuA = ModifyMenuA;
HOOK_TRACE_INFO hHookModifyMenuA = { 0 };
ULONG HookModifyMenuA_ACLEntries[1] = { 0 };
BOOL fake_ModifyMenuA(HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCSTR lpNewItem){
	BOOL ret = pModifyMenuA(hMnu,uPosition,uFlags,uIDNewItem,lpNewItem);
	fprintf(fp,"OUT ['ModifyMenuA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *RegisterClipboardFormatW_fun) (LPCWSTR lpszFormat);
RegisterClipboardFormatW_fun pRegisterClipboardFormatW = RegisterClipboardFormatW;
HOOK_TRACE_INFO hHookRegisterClipboardFormatW = { 0 };
ULONG HookRegisterClipboardFormatW_ACLEntries[1] = { 0 };
UINT fake_RegisterClipboardFormatW(LPCWSTR lpszFormat){
	UINT ret = pRegisterClipboardFormatW(lpszFormat);
	fprintf(fp,"OUT ['RegisterClipboardFormatW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *MsgWaitForMultipleObjects_fun) (DWORD nCount,CONST HANDLE* pHandles,BOOL fWaitAll,DWORD dwMilliseconds,DWORD dwWakeMask);
MsgWaitForMultipleObjects_fun pMsgWaitForMultipleObjects = MsgWaitForMultipleObjects;
HOOK_TRACE_INFO hHookMsgWaitForMultipleObjects = { 0 };
ULONG HookMsgWaitForMultipleObjects_ACLEntries[1] = { 0 };
DWORD fake_MsgWaitForMultipleObjects(DWORD nCount,CONST HANDLE* pHandles,BOOL fWaitAll,DWORD dwMilliseconds,DWORD dwWakeMask){
	DWORD ret = pMsgWaitForMultipleObjects(nCount,pHandles,fWaitAll,dwMilliseconds,dwWakeMask);
	fprintf(fp,"OUT ['MsgWaitForMultipleObjects',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *RegisterShellHookWindow_fun) (HWND hwnd);
RegisterShellHookWindow_fun pRegisterShellHookWindow = RegisterShellHookWindow;
HOOK_TRACE_INFO hHookRegisterShellHookWindow = { 0 };
ULONG HookRegisterShellHookWindow_ACLEntries[1] = { 0 };
BOOL fake_RegisterShellHookWindow(HWND hwnd){
	BOOL ret = pRegisterShellHookWindow(hwnd);
	fprintf(fp,"OUT ['RegisterShellHookWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *GetMenuStringA_fun) (HMENU hMenu,UINT uIDItem,LPSTR lpString,int cchMax,UINT flags);
GetMenuStringA_fun pGetMenuStringA = GetMenuStringA;
HOOK_TRACE_INFO hHookGetMenuStringA = { 0 };
ULONG HookGetMenuStringA_ACLEntries[1] = { 0 };
int fake_GetMenuStringA(HMENU hMenu,UINT uIDItem,LPSTR lpString,int cchMax,UINT flags){
	int ret = pGetMenuStringA(hMenu,uIDItem,lpString,cchMax,flags);
	fprintf(fp,"OUT ['GetMenuStringA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpString','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpString, sizeof(LPSTR),cchMax);
 	else fprintf(fp,"{'name':'lpString','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpString,sizeof(LPSTR));
	if(lpString){
		for(int i=0; i<cchMax;i++){
			fprintf(fp,"0x%x,",lpString[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *PeekMessageW_fun) (LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax,UINT wRemoveMsg);
PeekMessageW_fun pPeekMessageW = PeekMessageW;
HOOK_TRACE_INFO hHookPeekMessageW = { 0 };
ULONG HookPeekMessageW_ACLEntries[1] = { 0 };
BOOL fake_PeekMessageW(LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax,UINT wRemoveMsg){
	BOOL ret = pPeekMessageW(lpMsg,hWnd,wMsgFilterMin,wMsgFilterMax,wRemoveMsg);
	fprintf(fp,"OUT ['PeekMessageW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpMsg','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpMsg, sizeof(LPMSG),1);
 	else fprintf(fp,"{'name':'lpMsg','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpMsg,sizeof(LPMSG));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetClassInfoA_fun) (HINSTANCE hInstance,LPCSTR lpClassName,LPWNDCLASSA lpWndClass);
GetClassInfoA_fun pGetClassInfoA = GetClassInfoA;
HOOK_TRACE_INFO hHookGetClassInfoA = { 0 };
ULONG HookGetClassInfoA_ACLEntries[1] = { 0 };
BOOL fake_GetClassInfoA(HINSTANCE hInstance,LPCSTR lpClassName,LPWNDCLASSA lpWndClass){
	BOOL ret = pGetClassInfoA(hInstance,lpClassName,lpWndClass);
	fprintf(fp,"OUT ['GetClassInfoA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpWndClass','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpWndClass, sizeof(LPWNDCLASSA),1);
 	else fprintf(fp,"{'name':'lpWndClass','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpWndClass,sizeof(LPWNDCLASSA));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ValidateRect_fun) (HWND hWnd,CONST RECT* lpRect);
ValidateRect_fun pValidateRect = ValidateRect;
HOOK_TRACE_INFO hHookValidateRect = { 0 };
ULONG HookValidateRect_ACLEntries[1] = { 0 };
BOOL fake_ValidateRect(HWND hWnd,CONST RECT* lpRect){
	BOOL ret = pValidateRect(hWnd,lpRect);
	fprintf(fp,"OUT ['ValidateRect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *InflateRect_fun) (LPRECT lprc,int dx,int dy);
InflateRect_fun pInflateRect = InflateRect;
HOOK_TRACE_INFO hHookInflateRect = { 0 };
ULONG HookInflateRect_ACLEntries[1] = { 0 };
BOOL fake_InflateRect(LPRECT lprc,int dx,int dy){
	BOOL ret = pInflateRect(lprc,dx,dy);
	fprintf(fp,"OUT ['InflateRect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lprc','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lprc, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'lprc','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lprc,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LRESULT (WINAPI *SendMessageTimeoutW_fun) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdwResult);
SendMessageTimeoutW_fun pSendMessageTimeoutW = SendMessageTimeoutW;
HOOK_TRACE_INFO hHookSendMessageTimeoutW = { 0 };
ULONG HookSendMessageTimeoutW_ACLEntries[1] = { 0 };
LRESULT fake_SendMessageTimeoutW(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdwResult){
	LRESULT ret = pSendMessageTimeoutW(hWnd,Msg,wParam,lParam,fuFlags,uTimeout,lpdwResult);
	fprintf(fp,"OUT ['SendMessageTimeoutW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LRESULT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LRESULT));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpdwResult','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpdwResult, sizeof(PDWORD_PTR),1);
 	else fprintf(fp,"{'name':'lpdwResult','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpdwResult,sizeof(PDWORD_PTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EnumDesktopsA_fun) (HWINSTA hwinsta,DESKTOPENUMPROCA lpEnumFunc,LPARAM lParam);
EnumDesktopsA_fun pEnumDesktopsA = EnumDesktopsA;
HOOK_TRACE_INFO hHookEnumDesktopsA = { 0 };
ULONG HookEnumDesktopsA_ACLEntries[1] = { 0 };
BOOL fake_EnumDesktopsA(HWINSTA hwinsta,DESKTOPENUMPROCA lpEnumFunc,LPARAM lParam){
	BOOL ret = pEnumDesktopsA(hwinsta,lpEnumFunc,lParam);
	fprintf(fp,"OUT ['EnumDesktopsA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HDEVNOTIFY (WINAPI *RegisterDeviceNotificationA_fun) (HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags);
RegisterDeviceNotificationA_fun pRegisterDeviceNotificationA = RegisterDeviceNotificationA;
HOOK_TRACE_INFO hHookRegisterDeviceNotificationA = { 0 };
ULONG HookRegisterDeviceNotificationA_ACLEntries[1] = { 0 };
HDEVNOTIFY fake_RegisterDeviceNotificationA(HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags){
	HDEVNOTIFY ret = pRegisterDeviceNotificationA(hRecipient,NotificationFilter,Flags);
	fprintf(fp,"OUT ['RegisterDeviceNotificationA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HDEVNOTIFY),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HDEVNOTIFY));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LONG (WINAPI *GetMessageTime_fun) ();
GetMessageTime_fun pGetMessageTime = GetMessageTime;
HOOK_TRACE_INFO hHookGetMessageTime = { 0 };
ULONG HookGetMessageTime_ACLEntries[1] = { 0 };
LONG fake_GetMessageTime(){
	LONG ret = pGetMessageTime();
	fprintf(fp,"OUT ['GetMessageTime',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LONG),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LONG));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EndMenu_fun) ();
EndMenu_fun pEndMenu = EndMenu;
HOOK_TRACE_INFO hHookEndMenu = { 0 };
ULONG HookEndMenu_ACLEntries[1] = { 0 };
BOOL fake_EndMenu(){
	BOOL ret = pEndMenu();
	fprintf(fp,"OUT ['EndMenu',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HDC (WINAPI *BeginPaint_fun) (HWND hWnd,LPPAINTSTRUCT lpPaint);
BeginPaint_fun pBeginPaint = BeginPaint;
HOOK_TRACE_INFO hHookBeginPaint = { 0 };
ULONG HookBeginPaint_ACLEntries[1] = { 0 };
HDC fake_BeginPaint(HWND hWnd,LPPAINTSTRUCT lpPaint){
	HDC ret = pBeginPaint(hWnd,lpPaint);
	fprintf(fp,"OUT ['BeginPaint',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HDC),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HDC));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpPaint','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpPaint, sizeof(LPPAINTSTRUCT),1);
 	else fprintf(fp,"{'name':'lpPaint','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpPaint,sizeof(LPPAINTSTRUCT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetRectEmpty_fun) (LPRECT lprc);
SetRectEmpty_fun pSetRectEmpty = SetRectEmpty;
HOOK_TRACE_INFO hHookSetRectEmpty = { 0 };
ULONG HookSetRectEmpty_ACLEntries[1] = { 0 };
BOOL fake_SetRectEmpty(LPRECT lprc){
	BOOL ret = pSetRectEmpty(lprc);
	fprintf(fp,"OUT ['SetRectEmpty',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lprc','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lprc, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'lprc','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lprc,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LONG (WINAPI *TabbedTextOutW_fun) (HDC hdc,int x,int y,LPCWSTR lpString,int chCount,int nTabPositions,CONST INT* lpnTabStopPositions,int nTabOrigin);
TabbedTextOutW_fun pTabbedTextOutW = TabbedTextOutW;
HOOK_TRACE_INFO hHookTabbedTextOutW = { 0 };
ULONG HookTabbedTextOutW_ACLEntries[1] = { 0 };
LONG fake_TabbedTextOutW(HDC hdc,int x,int y,LPCWSTR lpString,int chCount,int nTabPositions,CONST INT* lpnTabStopPositions,int nTabOrigin){
	LONG ret = pTabbedTextOutW(hdc,x,y,lpString,chCount,nTabPositions,lpnTabStopPositions,nTabOrigin);
	fprintf(fp,"OUT ['TabbedTextOutW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LONG),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LONG));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *InSendMessage_fun) ();
InSendMessage_fun pInSendMessage = InSendMessage;
HOOK_TRACE_INFO hHookInSendMessage = { 0 };
ULONG HookInSendMessage_ACLEntries[1] = { 0 };
BOOL fake_InSendMessage(){
	BOOL ret = pInSendMessage();
	fprintf(fp,"OUT ['InSendMessage',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HDC (WINAPI *GetWindowDC_fun) (HWND hWnd);
GetWindowDC_fun pGetWindowDC = GetWindowDC;
HOOK_TRACE_INFO hHookGetWindowDC = { 0 };
ULONG HookGetWindowDC_ACLEntries[1] = { 0 };
HDC fake_GetWindowDC(HWND hWnd){
	HDC ret = pGetWindowDC(hWnd);
	fprintf(fp,"OUT ['GetWindowDC',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HDC),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HDC));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *FindWindowA_fun) (LPCSTR lpClassName,LPCSTR lpWindowName);
FindWindowA_fun pFindWindowA = FindWindowA;
HOOK_TRACE_INFO hHookFindWindowA = { 0 };
ULONG HookFindWindowA_ACLEntries[1] = { 0 };
HWND fake_FindWindowA(LPCSTR lpClassName,LPCSTR lpWindowName){
	HWND ret = pFindWindowA(lpClassName,lpWindowName);
	fprintf(fp,"OUT ['FindWindowA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *DlgDirSelectComboBoxExW_fun) (HWND hwndDlg,LPWSTR lpString,int cchOut,int idComboBox);
DlgDirSelectComboBoxExW_fun pDlgDirSelectComboBoxExW = DlgDirSelectComboBoxExW;
HOOK_TRACE_INFO hHookDlgDirSelectComboBoxExW = { 0 };
ULONG HookDlgDirSelectComboBoxExW_ACLEntries[1] = { 0 };
BOOL fake_DlgDirSelectComboBoxExW(HWND hwndDlg,LPWSTR lpString,int cchOut,int idComboBox){
	BOOL ret = pDlgDirSelectComboBoxExW(hwndDlg,lpString,cchOut,idComboBox);
	fprintf(fp,"OUT ['DlgDirSelectComboBoxExW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'lpString',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': %p,", lpString);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': %p,", lpString);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),cchOut);
 	}else 
	{
		fprintf(fp,"{'name':'lpString',");
		fwprintf(fp, L"'value': %p, ", lpString);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	if(lpString){
		for(int i=0; i<cchOut;i++){
			fprintf(fp,"0x%x,",lpString[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SendNotifyMessageA_fun) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
SendNotifyMessageA_fun pSendNotifyMessageA = SendNotifyMessageA;
HOOK_TRACE_INFO hHookSendNotifyMessageA = { 0 };
ULONG HookSendNotifyMessageA_ACLEntries[1] = { 0 };
BOOL fake_SendNotifyMessageA(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam){
	BOOL ret = pSendNotifyMessageA(hWnd,Msg,wParam,lParam);
	fprintf(fp,"OUT ['SendNotifyMessageA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *DrawTextExA_fun) (HDC hdc,LPSTR lpchText,int cchText,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp);
DrawTextExA_fun pDrawTextExA = DrawTextExA;
HOOK_TRACE_INFO hHookDrawTextExA = { 0 };
ULONG HookDrawTextExA_ACLEntries[1] = { 0 };
int fake_DrawTextExA(HDC hdc,LPSTR lpchText,int cchText,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp){
	int ret = pDrawTextExA(hdc,lpchText,cchText,lprc,format,lpdtp);
	fprintf(fp,"OUT ['DrawTextExA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpchText','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpchText, sizeof(LPSTR),cchText);
 	else fprintf(fp,"{'name':'lpchText','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpchText,sizeof(LPSTR));
	if(lpchText){
		for(int i=0; i<cchText;i++){
			fprintf(fp,"0x%x,",lpchText[i]);
		}
	}
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lprc','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lprc, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'lprc','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lprc,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HPOWERNOTIFY (WINAPI *RegisterPowerSettingNotification_fun) (HANDLE hRecipient,LPCGUID PowerSettingGuid,DWORD Flags);
RegisterPowerSettingNotification_fun pRegisterPowerSettingNotification = RegisterPowerSettingNotification;
HOOK_TRACE_INFO hHookRegisterPowerSettingNotification = { 0 };
ULONG HookRegisterPowerSettingNotification_ACLEntries[1] = { 0 };
HPOWERNOTIFY fake_RegisterPowerSettingNotification(HANDLE hRecipient,LPCGUID PowerSettingGuid,DWORD Flags){
	HPOWERNOTIFY ret = pRegisterPowerSettingNotification(hRecipient,PowerSettingGuid,Flags);
	fprintf(fp,"OUT ['RegisterPowerSettingNotification',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HPOWERNOTIFY),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HPOWERNOTIFY));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *GetMenuContextHelpId_fun) (HMENU arg0);
GetMenuContextHelpId_fun pGetMenuContextHelpId = GetMenuContextHelpId;
HOOK_TRACE_INFO hHookGetMenuContextHelpId = { 0 };
ULONG HookGetMenuContextHelpId_ACLEntries[1] = { 0 };
DWORD fake_GetMenuContextHelpId(HMENU arg0){
	DWORD ret = pGetMenuContextHelpId(arg0);
	fprintf(fp,"OUT ['GetMenuContextHelpId',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *GetListBoxInfo_fun) (HWND hwnd);
GetListBoxInfo_fun pGetListBoxInfo = GetListBoxInfo;
HOOK_TRACE_INFO hHookGetListBoxInfo = { 0 };
ULONG HookGetListBoxInfo_ACLEntries[1] = { 0 };
DWORD fake_GetListBoxInfo(HWND hwnd){
	DWORD ret = pGetListBoxInfo(hwnd);
	fprintf(fp,"OUT ['GetListBoxInfo',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetRect_fun) (LPRECT lprc,int xLeft,int yTop,int xRight,int yBottom);
SetRect_fun pSetRect = SetRect;
HOOK_TRACE_INFO hHookSetRect = { 0 };
ULONG HookSetRect_ACLEntries[1] = { 0 };
BOOL fake_SetRect(LPRECT lprc,int xLeft,int yTop,int xRight,int yBottom){
	BOOL ret = pSetRect(lprc,xLeft,yTop,xRight,yBottom);
	fprintf(fp,"OUT ['SetRect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lprc','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lprc, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'lprc','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lprc,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *GetRawInputDeviceList_fun) (PRAWINPUTDEVICELIST pRawInputDeviceList,PUINT puiNumDevices,UINT cbSize);
GetRawInputDeviceList_fun pGetRawInputDeviceList = GetRawInputDeviceList;
HOOK_TRACE_INFO hHookGetRawInputDeviceList = { 0 };
ULONG HookGetRawInputDeviceList_ACLEntries[1] = { 0 };
UINT fake_GetRawInputDeviceList(PRAWINPUTDEVICELIST pRawInputDeviceList,PUINT puiNumDevices,UINT cbSize){
	UINT ret = pGetRawInputDeviceList(pRawInputDeviceList,puiNumDevices,cbSize);
	fprintf(fp,"OUT ['GetRawInputDeviceList',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	if(puiNumDevices && 1) fprintf(fp,"{'name':'pRawInputDeviceList','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pRawInputDeviceList, sizeof(PRAWINPUTDEVICELIST),*puiNumDevices);
 	else fprintf(fp,"{'name':'pRawInputDeviceList','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pRawInputDeviceList,sizeof(PRAWINPUTDEVICELIST));
	if(puiNumDevices && pRawInputDeviceList){
		for(int i=0; i<*puiNumDevices;i++){
			fprintf(fp,"0x%x,",pRawInputDeviceList[i]);
		}
	}
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'puiNumDevices','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",puiNumDevices, sizeof(PUINT),1);
 	else fprintf(fp,"{'name':'puiNumDevices','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",puiNumDevices,sizeof(PUINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetMessageQueue_fun) (int cMessagesMax);
SetMessageQueue_fun pSetMessageQueue = SetMessageQueue;
HOOK_TRACE_INFO hHookSetMessageQueue = { 0 };
ULONG HookSetMessageQueue_ACLEntries[1] = { 0 };
BOOL fake_SetMessageQueue(int cMessagesMax){
	BOOL ret = pSetMessageQueue(cMessagesMax);
	fprintf(fp,"OUT ['SetMessageQueue',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *GetClassLongA_fun) (HWND hWnd,int nIndex);
GetClassLongA_fun pGetClassLongA = GetClassLongA;
HOOK_TRACE_INFO hHookGetClassLongA = { 0 };
ULONG HookGetClassLongA_ACLEntries[1] = { 0 };
DWORD fake_GetClassLongA(HWND hWnd,int nIndex){
	DWORD ret = pGetClassLongA(hWnd,nIndex);
	fprintf(fp,"OUT ['GetClassLongA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *FlashWindowEx_fun) (PFLASHWINFO pfwi);
FlashWindowEx_fun pFlashWindowEx = FlashWindowEx;
HOOK_TRACE_INFO hHookFlashWindowEx = { 0 };
ULONG HookFlashWindowEx_ACLEntries[1] = { 0 };
BOOL fake_FlashWindowEx(PFLASHWINFO pfwi){
	BOOL ret = pFlashWindowEx(pfwi);
	fprintf(fp,"OUT ['FlashWindowEx',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HDC (WINAPI *GetDC_fun) (HWND hWnd);
GetDC_fun pGetDC = GetDC;
HOOK_TRACE_INFO hHookGetDC = { 0 };
ULONG HookGetDC_ACLEntries[1] = { 0 };
HDC fake_GetDC(HWND hWnd){
	HDC ret = pGetDC(hWnd);
	fprintf(fp,"OUT ['GetDC',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HDC),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HDC));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetMenuItemInfoW_fun) (HMENU hmenu,UINT item,BOOL fByPositon,LPCMENUITEMINFOW lpmii);
SetMenuItemInfoW_fun pSetMenuItemInfoW = SetMenuItemInfoW;
HOOK_TRACE_INFO hHookSetMenuItemInfoW = { 0 };
ULONG HookSetMenuItemInfoW_ACLEntries[1] = { 0 };
BOOL fake_SetMenuItemInfoW(HMENU hmenu,UINT item,BOOL fByPositon,LPCMENUITEMINFOW lpmii){
	BOOL ret = pSetMenuItemInfoW(hmenu,item,fByPositon,lpmii);
	fprintf(fp,"OUT ['SetMenuItemInfoW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HDC (WINAPI *GetDCEx_fun) (HWND hWnd,HRGN hrgnClip,DWORD flags);
GetDCEx_fun pGetDCEx = GetDCEx;
HOOK_TRACE_INFO hHookGetDCEx = { 0 };
ULONG HookGetDCEx_ACLEntries[1] = { 0 };
HDC fake_GetDCEx(HWND hWnd,HRGN hrgnClip,DWORD flags){
	HDC ret = pGetDCEx(hWnd,hrgnClip,flags);
	fprintf(fp,"OUT ['GetDCEx',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HDC),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HDC));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LONG_PTR (WINAPI *GetWindowLongPtrW_fun) (HWND hWnd,int nIndex);
GetWindowLongPtrW_fun pGetWindowLongPtrW = GetWindowLongPtrW;
HOOK_TRACE_INFO hHookGetWindowLongPtrW = { 0 };
ULONG HookGetWindowLongPtrW_ACLEntries[1] = { 0 };
LONG_PTR fake_GetWindowLongPtrW(HWND hWnd,int nIndex){
	LONG_PTR ret = pGetWindowLongPtrW(hWnd,nIndex);
	fprintf(fp,"OUT ['GetWindowLongPtrW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LONG_PTR),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LONG_PTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetLayeredWindowAttributes_fun) (HWND hwnd,COLORREF*  pcrKey,BYTE*  pbAlpha,DWORD*  pdwFlags);
GetLayeredWindowAttributes_fun pGetLayeredWindowAttributes = GetLayeredWindowAttributes;
HOOK_TRACE_INFO hHookGetLayeredWindowAttributes = { 0 };
ULONG HookGetLayeredWindowAttributes_ACLEntries[1] = { 0 };
BOOL fake_GetLayeredWindowAttributes(HWND hwnd,COLORREF*  pcrKey,BYTE*  pbAlpha,DWORD*  pdwFlags){
	BOOL ret = pGetLayeredWindowAttributes(hwnd, pcrKey, pbAlpha, pdwFlags);
	fprintf(fp,"OUT ['GetLayeredWindowAttributes',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':' pcrKey','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[", pcrKey, sizeof(COLORREF*),1);
 	else fprintf(fp,"{'name':' pcrKey','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[", pcrKey,sizeof(COLORREF*));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':' pbAlpha','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[", pbAlpha, sizeof(BYTE*),1);
 	else fprintf(fp,"{'name':' pbAlpha','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[", pbAlpha,sizeof(BYTE*));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':' pdwFlags','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[", pdwFlags, sizeof(DWORD*),1);
 	else fprintf(fp,"{'name':' pdwFlags','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[", pdwFlags,sizeof(DWORD*));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *ReleaseDC_fun) (HWND hWnd,HDC hDC);
ReleaseDC_fun pReleaseDC = ReleaseDC;
HOOK_TRACE_INFO hHookReleaseDC = { 0 };
ULONG HookReleaseDC_ACLEntries[1] = { 0 };
int fake_ReleaseDC(HWND hWnd,HDC hDC){
	int ret = pReleaseDC(hWnd,hDC);
	fprintf(fp,"OUT ['ReleaseDC',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef ATOM (WINAPI *RegisterClassW_fun) (CONST WNDCLASSW* lpWndClass);
RegisterClassW_fun pRegisterClassW = RegisterClassW;
HOOK_TRACE_INFO hHookRegisterClassW = { 0 };
ULONG HookRegisterClassW_ACLEntries[1] = { 0 };
ATOM fake_RegisterClassW(CONST WNDCLASSW* lpWndClass){
	ATOM ret = pRegisterClassW(lpWndClass);
	fprintf(fp,"OUT ['RegisterClassW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%hx,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(ATOM),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%hx, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(ATOM));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *GetWindowTextW_fun) (HWND hWnd,LPWSTR lpString,int nMaxCount);
GetWindowTextW_fun pGetWindowTextW = GetWindowTextW;
HOOK_TRACE_INFO hHookGetWindowTextW = { 0 };
ULONG HookGetWindowTextW_ACLEntries[1] = { 0 };
int fake_GetWindowTextW(HWND hWnd,LPWSTR lpString,int nMaxCount){
	int ret = pGetWindowTextW(hWnd,lpString,nMaxCount);
	fprintf(fp,"OUT ['GetWindowTextW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'lpString',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': %p,", lpString);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': %p,", lpString);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),nMaxCount);
 	}else 
	{
		fprintf(fp,"{'name':'lpString',");
		fwprintf(fp, L"'value': %p, ", lpString);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	if(lpString){
		for(int i=0; i<nMaxCount;i++){
			fprintf(fp,"0x%x,",lpString[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWINSTA (WINAPI *CreateWindowStationA_fun) (LPCSTR lpwinsta,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa);
CreateWindowStationA_fun pCreateWindowStationA = CreateWindowStationA;
HOOK_TRACE_INFO hHookCreateWindowStationA = { 0 };
ULONG HookCreateWindowStationA_ACLEntries[1] = { 0 };
HWINSTA fake_CreateWindowStationA(LPCSTR lpwinsta,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa){
	HWINSTA ret = pCreateWindowStationA(lpwinsta,dwFlags,dwDesiredAccess,lpsa);
	fprintf(fp,"OUT ['CreateWindowStationA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWINSTA),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWINSTA));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *DrawAnimatedRects_fun) (HWND hwnd,int idAni,CONST RECT* lprcFrom,CONST RECT* lprcTo);
DrawAnimatedRects_fun pDrawAnimatedRects = DrawAnimatedRects;
HOOK_TRACE_INFO hHookDrawAnimatedRects = { 0 };
ULONG HookDrawAnimatedRects_ACLEntries[1] = { 0 };
BOOL fake_DrawAnimatedRects(HWND hwnd,int idAni,CONST RECT* lprcFrom,CONST RECT* lprcTo){
	BOOL ret = pDrawAnimatedRects(hwnd,idAni,lprcFrom,lprcTo);
	fprintf(fp,"OUT ['DrawAnimatedRects',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *FillRect_fun) (HDC hDC,CONST RECT* lprc,HBRUSH hbr);
FillRect_fun pFillRect = FillRect;
HOOK_TRACE_INFO hHookFillRect = { 0 };
ULONG HookFillRect_ACLEntries[1] = { 0 };
int fake_FillRect(HDC hDC,CONST RECT* lprc,HBRUSH hbr){
	int ret = pFillRect(hDC,lprc,hbr);
	fprintf(fp,"OUT ['FillRect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *GetDlgItem_fun) (HWND hDlg,int nIDDlgItem);
GetDlgItem_fun pGetDlgItem = GetDlgItem;
HOOK_TRACE_INFO hHookGetDlgItem = { 0 };
ULONG HookGetDlgItem_ACLEntries[1] = { 0 };
HWND fake_GetDlgItem(HWND hDlg,int nIDDlgItem){
	HWND ret = pGetDlgItem(hDlg,nIDDlgItem);
	fprintf(fp,"OUT ['GetDlgItem',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *EnumPropsExW_fun) (HWND hWnd,PROPENUMPROCEXW lpEnumFunc,LPARAM lParam);
EnumPropsExW_fun pEnumPropsExW = EnumPropsExW;
HOOK_TRACE_INFO hHookEnumPropsExW = { 0 };
ULONG HookEnumPropsExW_ACLEntries[1] = { 0 };
int fake_EnumPropsExW(HWND hWnd,PROPENUMPROCEXW lpEnumFunc,LPARAM lParam){
	int ret = pEnumPropsExW(hWnd,lpEnumFunc,lParam);
	fprintf(fp,"OUT ['EnumPropsExW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *GetFocus_fun) ();
GetFocus_fun pGetFocus = GetFocus;
HOOK_TRACE_INFO hHookGetFocus = { 0 };
ULONG HookGetFocus_ACLEntries[1] = { 0 };
HWND fake_GetFocus(){
	HWND ret = pGetFocus();
	fprintf(fp,"OUT ['GetFocus',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetKeyboardLayoutNameW_fun) (LPWSTR pwszKLID);
GetKeyboardLayoutNameW_fun pGetKeyboardLayoutNameW = GetKeyboardLayoutNameW;
HOOK_TRACE_INFO hHookGetKeyboardLayoutNameW = { 0 };
ULONG HookGetKeyboardLayoutNameW_ACLEntries[1] = { 0 };
BOOL fake_GetKeyboardLayoutNameW(LPWSTR pwszKLID){
	BOOL ret = pGetKeyboardLayoutNameW(pwszKLID);
	fprintf(fp,"OUT ['GetKeyboardLayoutNameW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'pwszKLID',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': %p,", pwszKLID);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': %p,", pwszKLID);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),KL_NAMELENGTH);
 	}else 
	{
		fprintf(fp,"{'name':'pwszKLID',");
		fwprintf(fp, L"'value': %p, ", pwszKLID);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	if(pwszKLID){
		for(int i=0; i<KL_NAMELENGTH;i++){
			fprintf(fp,"0x%x,",pwszKLID[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *LockWindowUpdate_fun) (HWND hWndLock);
LockWindowUpdate_fun pLockWindowUpdate = LockWindowUpdate;
HOOK_TRACE_INFO hHookLockWindowUpdate = { 0 };
ULONG HookLockWindowUpdate_ACLEntries[1] = { 0 };
BOOL fake_LockWindowUpdate(HWND hWndLock){
	BOOL ret = pLockWindowUpdate(hWndLock);
	fprintf(fp,"OUT ['LockWindowUpdate',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetWindowRect_fun) (HWND hWnd,LPRECT lpRect);
GetWindowRect_fun pGetWindowRect = GetWindowRect;
HOOK_TRACE_INFO hHookGetWindowRect = { 0 };
ULONG HookGetWindowRect_ACLEntries[1] = { 0 };
BOOL fake_GetWindowRect(HWND hWnd,LPRECT lpRect){
	BOOL ret = pGetWindowRect(hWnd,lpRect);
	fprintf(fp,"OUT ['GetWindowRect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpRect','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpRect, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'lpRect','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpRect,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ShowWindowAsync_fun) (HWND hWnd,int nCmdShow);
ShowWindowAsync_fun pShowWindowAsync = ShowWindowAsync;
HOOK_TRACE_INFO hHookShowWindowAsync = { 0 };
ULONG HookShowWindowAsync_ACLEntries[1] = { 0 };
BOOL fake_ShowWindowAsync(HWND hWnd,int nCmdShow){
	BOOL ret = pShowWindowAsync(hWnd,nCmdShow);
	fprintf(fp,"OUT ['ShowWindowAsync',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *PrivateExtractIconsA_fun) (LPCSTR szFileName,int nIconIndex,int cxIcon,int cyIcon,HICON* phicon,UINT* piconid,UINT nIcons,UINT flags);
PrivateExtractIconsA_fun pPrivateExtractIconsA = PrivateExtractIconsA;
HOOK_TRACE_INFO hHookPrivateExtractIconsA = { 0 };
ULONG HookPrivateExtractIconsA_ACLEntries[1] = { 0 };
UINT fake_PrivateExtractIconsA(LPCSTR szFileName,int nIconIndex,int cxIcon,int cyIcon,HICON* phicon,UINT* piconid,UINT nIcons,UINT flags){
	UINT ret = pPrivateExtractIconsA(szFileName,nIconIndex,cxIcon,cyIcon,phicon,piconid,nIcons,flags);
	fprintf(fp,"OUT ['PrivateExtractIconsA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'phicon','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",phicon, sizeof(HICON*),nIcons, ret);
 	else fprintf(fp,"{'name':'phicon','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",phicon,sizeof(HICON*));
	if(phicon){
		for(int i=0; i<nIcons <  ret ? nIcons :  ret;i++){
			fprintf(fp,"0x%x,",phicon[i]);
		}
	}
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'piconid','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",piconid, sizeof(UINT*),nIcons, ret);
 	else fprintf(fp,"{'name':'piconid','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",piconid,sizeof(UINT*));
	if(piconid){
		for(int i=0; i<nIcons <  ret ? nIcons :  ret;i++){
			fprintf(fp,"0x%x,",piconid[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HCURSOR (WINAPI *LoadCursorA_fun) (HINSTANCE hInstance,LPCSTR lpCursorName);
LoadCursorA_fun pLoadCursorA = LoadCursorA;
HOOK_TRACE_INFO hHookLoadCursorA = { 0 };
ULONG HookLoadCursorA_ACLEntries[1] = { 0 };
HCURSOR fake_LoadCursorA(HINSTANCE hInstance,LPCSTR lpCursorName){
	HCURSOR ret = pLoadCursorA(hInstance,lpCursorName);
	fprintf(fp,"OUT ['LoadCursorA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HCURSOR),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HCURSOR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *CreateWindowExW_fun) (DWORD dwExStyle,LPCWSTR lpClassName,LPCWSTR lpWindowName,DWORD dwStyle,int X,int Y,int nWidth,int nHeight,HWND hWndParent,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
CreateWindowExW_fun pCreateWindowExW = CreateWindowExW;
HOOK_TRACE_INFO hHookCreateWindowExW = { 0 };
ULONG HookCreateWindowExW_ACLEntries[1] = { 0 };
HWND fake_CreateWindowExW(DWORD dwExStyle,LPCWSTR lpClassName,LPCWSTR lpWindowName,DWORD dwStyle,int X,int Y,int nWidth,int nHeight,HWND hWndParent,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam){
	HWND ret = pCreateWindowExW(dwExStyle,lpClassName,lpWindowName,dwStyle,X,Y,nWidth,nHeight,hWndParent,hMenu,hInstance,lpParam);
	fprintf(fp,"OUT ['CreateWindowExW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LPWSTR (WINAPI *CharLowerW_fun) (LPWSTR lpsz);
CharLowerW_fun pCharLowerW = CharLowerW;
HOOK_TRACE_INFO hHookCharLowerW = { 0 };
ULONG HookCharLowerW_ACLEntries[1] = { 0 };
LPWSTR fake_CharLowerW(LPWSTR lpsz){
	LPWSTR ret = pCharLowerW(lpsz);
	fprintf(fp,"OUT ['CharLowerW',");
	if(1)
	{
		fprintf(fp,"{'name':'ret',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': '\"%s\"',", ret);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': '\"%s\"',", ret);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),1);
 	}else 
	{
		fprintf(fp,"{'name':'ret',");
		fwprintf(fp, L"'value': '\"%s\"', ", ret);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'lpsz',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': '\"%s\"',", lpsz);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': '\"%s\"',", lpsz);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),1);
 	}else 
	{
		fprintf(fp,"{'name':'lpsz',");
		fwprintf(fp, L"'value': '\"%s\"', ", lpsz);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *CreateDialogParamA_fun) (HINSTANCE hInstance,LPCSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
CreateDialogParamA_fun pCreateDialogParamA = CreateDialogParamA;
HOOK_TRACE_INFO hHookCreateDialogParamA = { 0 };
ULONG HookCreateDialogParamA_ACLEntries[1] = { 0 };
HWND fake_CreateDialogParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam){
	HWND ret = pCreateDialogParamA(hInstance,lpTemplateName,hWndParent,lpDialogFunc,dwInitParam);
	fprintf(fp,"OUT ['CreateDialogParamA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HMONITOR (WINAPI *MonitorFromWindow_fun) (HWND hwnd,DWORD dwFlags);
MonitorFromWindow_fun pMonitorFromWindow = MonitorFromWindow;
HOOK_TRACE_INFO hHookMonitorFromWindow = { 0 };
ULONG HookMonitorFromWindow_ACLEntries[1] = { 0 };
HMONITOR fake_MonitorFromWindow(HWND hwnd,DWORD dwFlags){
	HMONITOR ret = pMonitorFromWindow(hwnd,dwFlags);
	fprintf(fp,"OUT ['MonitorFromWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HMONITOR),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HMONITOR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HMONITOR (WINAPI *MonitorFromPoint_fun) (POINT pt,DWORD dwFlags);
MonitorFromPoint_fun pMonitorFromPoint = MonitorFromPoint;
HOOK_TRACE_INFO hHookMonitorFromPoint = { 0 };
ULONG HookMonitorFromPoint_ACLEntries[1] = { 0 };
HMONITOR fake_MonitorFromPoint(POINT pt,DWORD dwFlags){
	HMONITOR ret = pMonitorFromPoint(pt,dwFlags);
	fprintf(fp,"OUT ['MonitorFromPoint',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HMONITOR),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HMONITOR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *SetActiveWindow_fun) (HWND hWnd);
SetActiveWindow_fun pSetActiveWindow = SetActiveWindow;
HOOK_TRACE_INFO hHookSetActiveWindow = { 0 };
ULONG HookSetActiveWindow_ACLEntries[1] = { 0 };
HWND fake_SetActiveWindow(HWND hWnd){
	HWND ret = pSetActiveWindow(hWnd);
	fprintf(fp,"OUT ['SetActiveWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HCURSOR (WINAPI *LoadCursorFromFileW_fun) (LPCWSTR lpFileName);
LoadCursorFromFileW_fun pLoadCursorFromFileW = LoadCursorFromFileW;
HOOK_TRACE_INFO hHookLoadCursorFromFileW = { 0 };
ULONG HookLoadCursorFromFileW_ACLEntries[1] = { 0 };
HCURSOR fake_LoadCursorFromFileW(LPCWSTR lpFileName){
	HCURSOR ret = pLoadCursorFromFileW(lpFileName);
	fprintf(fp,"OUT ['LoadCursorFromFileW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HCURSOR),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HCURSOR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ChangeWindowMessageFilter_fun) (UINT message,DWORD dwFlag);
ChangeWindowMessageFilter_fun pChangeWindowMessageFilter = ChangeWindowMessageFilter;
HOOK_TRACE_INFO hHookChangeWindowMessageFilter = { 0 };
ULONG HookChangeWindowMessageFilter_ACLEntries[1] = { 0 };
BOOL fake_ChangeWindowMessageFilter(UINT message,DWORD dwFlag){
	BOOL ret = pChangeWindowMessageFilter(message,dwFlag);
	fprintf(fp,"OUT ['ChangeWindowMessageFilter',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetGestureInfo_fun) (HGESTUREINFO hGestureInfo,PGESTUREINFO pGestureInfo);
GetGestureInfo_fun pGetGestureInfo = GetGestureInfo;
HOOK_TRACE_INFO hHookGetGestureInfo = { 0 };
ULONG HookGetGestureInfo_ACLEntries[1] = { 0 };
BOOL fake_GetGestureInfo(HGESTUREINFO hGestureInfo,PGESTUREINFO pGestureInfo){
	BOOL ret = pGetGestureInfo(hGestureInfo,pGestureInfo);
	fprintf(fp,"OUT ['GetGestureInfo',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pGestureInfo','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pGestureInfo, sizeof(PGESTUREINFO),1);
 	else fprintf(fp,"{'name':'pGestureInfo','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pGestureInfo,sizeof(PGESTUREINFO));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *SetWindowRgn_fun) (HWND hWnd,HRGN hRgn,BOOL bRedraw);
SetWindowRgn_fun pSetWindowRgn = SetWindowRgn;
HOOK_TRACE_INFO hHookSetWindowRgn = { 0 };
ULONG HookSetWindowRgn_ACLEntries[1] = { 0 };
int fake_SetWindowRgn(HWND hWnd,HRGN hRgn,BOOL bRedraw){
	int ret = pSetWindowRgn(hWnd,hRgn,bRedraw);
	fprintf(fp,"OUT ['SetWindowRgn',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HHOOK (WINAPI *SetWindowsHookW_fun) (int nFilterType,HOOKPROC pfnFilterProc);
SetWindowsHookW_fun pSetWindowsHookW = SetWindowsHookW;
HOOK_TRACE_INFO hHookSetWindowsHookW = { 0 };
ULONG HookSetWindowsHookW_ACLEntries[1] = { 0 };
HHOOK fake_SetWindowsHookW(int nFilterType,HOOKPROC pfnFilterProc){
	HHOOK ret = pSetWindowsHookW(nFilterType,pfnFilterProc);
	fprintf(fp,"OUT ['SetWindowsHookW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HHOOK),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HHOOK));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *InsertMenuA_fun) (HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCSTR lpNewItem);
InsertMenuA_fun pInsertMenuA = InsertMenuA;
HOOK_TRACE_INFO hHookInsertMenuA = { 0 };
ULONG HookInsertMenuA_ACLEntries[1] = { 0 };
BOOL fake_InsertMenuA(HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCSTR lpNewItem){
	BOOL ret = pInsertMenuA(hMenu,uPosition,uFlags,uIDNewItem,lpNewItem);
	fprintf(fp,"OUT ['InsertMenuA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HCURSOR (WINAPI *LoadCursorFromFileA_fun) (LPCSTR lpFileName);
LoadCursorFromFileA_fun pLoadCursorFromFileA = LoadCursorFromFileA;
HOOK_TRACE_INFO hHookLoadCursorFromFileA = { 0 };
ULONG HookLoadCursorFromFileA_ACLEntries[1] = { 0 };
HCURSOR fake_LoadCursorFromFileA(LPCSTR lpFileName){
	HCURSOR ret = pLoadCursorFromFileA(lpFileName);
	fprintf(fp,"OUT ['LoadCursorFromFileA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HCURSOR),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HCURSOR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HICON (WINAPI *CreateIcon_fun) (HINSTANCE hInstance,int nWidth,int nHeight,BYTE cPlanes,BYTE cBitsPixel,CONST BYTE* lpbANDbits,CONST BYTE* lpbXORbits);
CreateIcon_fun pCreateIcon = CreateIcon;
HOOK_TRACE_INFO hHookCreateIcon = { 0 };
ULONG HookCreateIcon_ACLEntries[1] = { 0 };
HICON fake_CreateIcon(HINSTANCE hInstance,int nWidth,int nHeight,BYTE cPlanes,BYTE cBitsPixel,CONST BYTE* lpbANDbits,CONST BYTE* lpbXORbits){
	HICON ret = pCreateIcon(hInstance,nWidth,nHeight,cPlanes,cBitsPixel,lpbANDbits,lpbXORbits);
	fprintf(fp,"OUT ['CreateIcon',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HICON),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HICON));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *DestroyAcceleratorTable_fun) (HACCEL hAccel);
DestroyAcceleratorTable_fun pDestroyAcceleratorTable = DestroyAcceleratorTable;
HOOK_TRACE_INFO hHookDestroyAcceleratorTable = { 0 };
ULONG HookDestroyAcceleratorTable_ACLEntries[1] = { 0 };
BOOL fake_DestroyAcceleratorTable(HACCEL hAccel){
	BOOL ret = pDestroyAcceleratorTable(hAccel);
	fprintf(fp,"OUT ['DestroyAcceleratorTable',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *RegisterClipboardFormatA_fun) (LPCSTR lpszFormat);
RegisterClipboardFormatA_fun pRegisterClipboardFormatA = RegisterClipboardFormatA;
HOOK_TRACE_INFO hHookRegisterClipboardFormatA = { 0 };
ULONG HookRegisterClipboardFormatA_ACLEntries[1] = { 0 };
UINT fake_RegisterClipboardFormatA(LPCSTR lpszFormat){
	UINT ret = pRegisterClipboardFormatA(lpszFormat);
	fprintf(fp,"OUT ['RegisterClipboardFormatA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *BlockInput_fun) (BOOL fBlockIt);
BlockInput_fun pBlockInput = BlockInput;
HOOK_TRACE_INFO hHookBlockInput = { 0 };
ULONG HookBlockInput_ACLEntries[1] = { 0 };
BOOL fake_BlockInput(BOOL fBlockIt){
	BOOL ret = pBlockInput(fBlockIt);
	fprintf(fp,"OUT ['BlockInput',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetCursorInfo_fun) (PCURSORINFO pci);
GetCursorInfo_fun pGetCursorInfo = GetCursorInfo;
HOOK_TRACE_INFO hHookGetCursorInfo = { 0 };
ULONG HookGetCursorInfo_ACLEntries[1] = { 0 };
BOOL fake_GetCursorInfo(PCURSORINFO pci){
	BOOL ret = pGetCursorInfo(pci);
	fprintf(fp,"OUT ['GetCursorInfo',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pci','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pci, sizeof(PCURSORINFO),1);
 	else fprintf(fp,"{'name':'pci','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pci,sizeof(PCURSORINFO));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *CloseDesktop_fun) (HDESK hDesktop);
CloseDesktop_fun pCloseDesktop = CloseDesktop;
HOOK_TRACE_INFO hHookCloseDesktop = { 0 };
ULONG HookCloseDesktop_ACLEntries[1] = { 0 };
BOOL fake_CloseDesktop(HDESK hDesktop){
	BOOL ret = pCloseDesktop(hDesktop);
	fprintf(fp,"OUT ['CloseDesktop',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *UnloadKeyboardLayout_fun) (HKL hkl);
UnloadKeyboardLayout_fun pUnloadKeyboardLayout = UnloadKeyboardLayout;
HOOK_TRACE_INFO hHookUnloadKeyboardLayout = { 0 };
ULONG HookUnloadKeyboardLayout_ACLEntries[1] = { 0 };
BOOL fake_UnloadKeyboardLayout(HKL hkl){
	BOOL ret = pUnloadKeyboardLayout(hkl);
	fprintf(fp,"OUT ['UnloadKeyboardLayout',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LONG (WINAPI *SetWindowLongA_fun) (HWND hWnd,int nIndex,LONG dwNewLong);
SetWindowLongA_fun pSetWindowLongA = SetWindowLongA;
HOOK_TRACE_INFO hHookSetWindowLongA = { 0 };
ULONG HookSetWindowLongA_ACLEntries[1] = { 0 };
LONG fake_SetWindowLongA(HWND hWnd,int nIndex,LONG dwNewLong){
	LONG ret = pSetWindowLongA(hWnd,nIndex,dwNewLong);
	fprintf(fp,"OUT ['SetWindowLongA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LONG),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LONG));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *GetDlgItemTextA_fun) (HWND hDlg,int nIDDlgItem,LPSTR lpString,int cchMax);
GetDlgItemTextA_fun pGetDlgItemTextA = GetDlgItemTextA;
HOOK_TRACE_INFO hHookGetDlgItemTextA = { 0 };
ULONG HookGetDlgItemTextA_ACLEntries[1] = { 0 };
UINT fake_GetDlgItemTextA(HWND hDlg,int nIDDlgItem,LPSTR lpString,int cchMax){
	UINT ret = pGetDlgItemTextA(hDlg,nIDDlgItem,lpString,cchMax);
	fprintf(fp,"OUT ['GetDlgItemTextA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpString','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpString, sizeof(LPSTR),cchMax);
 	else fprintf(fp,"{'name':'lpString','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpString,sizeof(LPSTR));
	if(lpString){
		for(int i=0; i<cchMax;i++){
			fprintf(fp,"0x%x,",lpString[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *CreateCaret_fun) (HWND hWnd,HBITMAP hBitmap,int nWidth,int nHeight);
CreateCaret_fun pCreateCaret = CreateCaret;
HOOK_TRACE_INFO hHookCreateCaret = { 0 };
ULONG HookCreateCaret_ACLEntries[1] = { 0 };
BOOL fake_CreateCaret(HWND hWnd,HBITMAP hBitmap,int nWidth,int nHeight){
	BOOL ret = pCreateCaret(hWnd,hBitmap,nWidth,nHeight);
	fprintf(fp,"OUT ['CreateCaret',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetKeyboardLayoutNameA_fun) (LPSTR pwszKLID);
GetKeyboardLayoutNameA_fun pGetKeyboardLayoutNameA = GetKeyboardLayoutNameA;
HOOK_TRACE_INFO hHookGetKeyboardLayoutNameA = { 0 };
ULONG HookGetKeyboardLayoutNameA_ACLEntries[1] = { 0 };
BOOL fake_GetKeyboardLayoutNameA(LPSTR pwszKLID){
	BOOL ret = pGetKeyboardLayoutNameA(pwszKLID);
	fprintf(fp,"OUT ['GetKeyboardLayoutNameA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pwszKLID','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pwszKLID, sizeof(LPSTR),KL_NAMELENGTH);
 	else fprintf(fp,"{'name':'pwszKLID','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pwszKLID,sizeof(LPSTR));
	if(pwszKLID){
		for(int i=0; i<KL_NAMELENGTH;i++){
			fprintf(fp,"0x%x,",pwszKLID[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetScrollBarInfo_fun) (HWND hwnd,LONG idObject,PSCROLLBARINFO psbi);
GetScrollBarInfo_fun pGetScrollBarInfo = GetScrollBarInfo;
HOOK_TRACE_INFO hHookGetScrollBarInfo = { 0 };
ULONG HookGetScrollBarInfo_ACLEntries[1] = { 0 };
BOOL fake_GetScrollBarInfo(HWND hwnd,LONG idObject,PSCROLLBARINFO psbi){
	BOOL ret = pGetScrollBarInfo(hwnd,idObject,psbi);
	fprintf(fp,"OUT ['GetScrollBarInfo',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'psbi','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",psbi, sizeof(PSCROLLBARINFO),1);
 	else fprintf(fp,"{'name':'psbi','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",psbi,sizeof(PSCROLLBARINFO));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef WORD (WINAPI *TileWindows_fun) (HWND hwndParent,UINT wHow,CONST RECT*  lpRect,UINT cKids,CONST HWND*  lpKids);
TileWindows_fun pTileWindows = TileWindows;
HOOK_TRACE_INFO hHookTileWindows = { 0 };
ULONG HookTileWindows_ACLEntries[1] = { 0 };
WORD fake_TileWindows(HWND hwndParent,UINT wHow,CONST RECT*  lpRect,UINT cKids,CONST HWND*  lpKids){
	WORD ret = pTileWindows(hwndParent,wHow, lpRect,cKids, lpKids);
	fprintf(fp,"OUT ['TileWindows',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%hx,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(WORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%hx, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(WORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *UnregisterClassW_fun) (LPCWSTR lpClassName,HINSTANCE hInstance);
UnregisterClassW_fun pUnregisterClassW = UnregisterClassW;
HOOK_TRACE_INFO hHookUnregisterClassW = { 0 };
ULONG HookUnregisterClassW_ACLEntries[1] = { 0 };
BOOL fake_UnregisterClassW(LPCWSTR lpClassName,HINSTANCE hInstance){
	BOOL ret = pUnregisterClassW(lpClassName,hInstance);
	fprintf(fp,"OUT ['UnregisterClassW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef VOID (WINAPI *PostQuitMessage_fun) (int nExitCode);
PostQuitMessage_fun pPostQuitMessage = PostQuitMessage;
HOOK_TRACE_INFO hHookPostQuitMessage = { 0 };
ULONG HookPostQuitMessage_ACLEntries[1] = { 0 };
VOID fake_PostQuitMessage(int nExitCode){
	pPostQuitMessage(nExitCode);
	fprintf(fp,"OUT ['PostQuitMessage',");
	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
}


typedef BOOL (WINAPI *GrayStringW_fun) (HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lpData,int nCount,int X,int Y,int nWidth,int nHeight);
GrayStringW_fun pGrayStringW = GrayStringW;
HOOK_TRACE_INFO hHookGrayStringW = { 0 };
ULONG HookGrayStringW_ACLEntries[1] = { 0 };
BOOL fake_GrayStringW(HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lpData,int nCount,int X,int Y,int nWidth,int nHeight){
	BOOL ret = pGrayStringW(hDC,hBrush,lpOutputFunc,lpData,nCount,X,Y,nWidth,nHeight);
	fprintf(fp,"OUT ['GrayStringW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HKL (WINAPI *LoadKeyboardLayoutW_fun) (LPCWSTR pwszKLID,UINT Flags);
LoadKeyboardLayoutW_fun pLoadKeyboardLayoutW = LoadKeyboardLayoutW;
HOOK_TRACE_INFO hHookLoadKeyboardLayoutW = { 0 };
ULONG HookLoadKeyboardLayoutW_ACLEntries[1] = { 0 };
HKL fake_LoadKeyboardLayoutW(LPCWSTR pwszKLID,UINT Flags){
	HKL ret = pLoadKeyboardLayoutW(pwszKLID,Flags);
	fprintf(fp,"OUT ['LoadKeyboardLayoutW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HKL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HKL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *WindowFromPoint_fun) (POINT Point);
WindowFromPoint_fun pWindowFromPoint = WindowFromPoint;
HOOK_TRACE_INFO hHookWindowFromPoint = { 0 };
ULONG HookWindowFromPoint_ACLEntries[1] = { 0 };
HWND fake_WindowFromPoint(POINT Point){
	HWND ret = pWindowFromPoint(Point);
	fprintf(fp,"OUT ['WindowFromPoint',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef SHORT (WINAPI *GetKeyState_fun) (int nVirtKey);
GetKeyState_fun pGetKeyState = GetKeyState;
HOOK_TRACE_INFO hHookGetKeyState = { 0 };
ULONG HookGetKeyState_ACLEntries[1] = { 0 };
SHORT fake_GetKeyState(int nVirtKey){
	SHORT ret = pGetKeyState(nVirtKey);
	fprintf(fp,"OUT ['GetKeyState',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%hx,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(SHORT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%hx, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(SHORT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetCaretBlinkTime_fun) (UINT uMSeconds);
SetCaretBlinkTime_fun pSetCaretBlinkTime = SetCaretBlinkTime;
HOOK_TRACE_INFO hHookSetCaretBlinkTime = { 0 };
ULONG HookSetCaretBlinkTime_ACLEntries[1] = { 0 };
BOOL fake_SetCaretBlinkTime(UINT uMSeconds){
	BOOL ret = pSetCaretBlinkTime(uMSeconds);
	fprintf(fp,"OUT ['SetCaretBlinkTime',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef VOID (WINAPI *NotifyWinEvent_fun) (DWORD event,HWND hwnd,LONG idObject,LONG idChild);
NotifyWinEvent_fun pNotifyWinEvent = NotifyWinEvent;
HOOK_TRACE_INFO hHookNotifyWinEvent = { 0 };
ULONG HookNotifyWinEvent_ACLEntries[1] = { 0 };
VOID fake_NotifyWinEvent(DWORD event,HWND hwnd,LONG idObject,LONG idChild){
	pNotifyWinEvent(event,hwnd,idObject,idChild);
	fprintf(fp,"OUT ['NotifyWinEvent',");
	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
}


typedef BOOL (WINAPI *GetCaretPos_fun) (LPPOINT lpPoint);
GetCaretPos_fun pGetCaretPos = GetCaretPos;
HOOK_TRACE_INFO hHookGetCaretPos = { 0 };
ULONG HookGetCaretPos_ACLEntries[1] = { 0 };
BOOL fake_GetCaretPos(LPPOINT lpPoint){
	BOOL ret = pGetCaretPos(lpPoint);
	fprintf(fp,"OUT ['GetCaretPos',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpPoint','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpPoint, sizeof(LPPOINT),1);
 	else fprintf(fp,"{'name':'lpPoint','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpPoint,sizeof(LPPOINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetCaretPos_fun) (int X,int Y);
SetCaretPos_fun pSetCaretPos = SetCaretPos;
HOOK_TRACE_INFO hHookSetCaretPos = { 0 };
ULONG HookSetCaretPos_ACLEntries[1] = { 0 };
BOOL fake_SetCaretPos(int X,int Y){
	BOOL ret = pSetCaretPos(X,Y);
	fprintf(fp,"OUT ['SetCaretPos',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LONG (WINAPI *SetDisplayConfig_fun) (UINT32 numPathArrayElements,DISPLAYCONFIG_PATH_INFO*  pathArray,UINT32 numModeInfoArrayElements,DISPLAYCONFIG_MODE_INFO*  modeInfoArray,UINT32 flags);
SetDisplayConfig_fun pSetDisplayConfig = SetDisplayConfig;
HOOK_TRACE_INFO hHookSetDisplayConfig = { 0 };
ULONG HookSetDisplayConfig_ACLEntries[1] = { 0 };
LONG fake_SetDisplayConfig(UINT32 numPathArrayElements,DISPLAYCONFIG_PATH_INFO*  pathArray,UINT32 numModeInfoArrayElements,DISPLAYCONFIG_MODE_INFO*  modeInfoArray,UINT32 flags){
	LONG ret = pSetDisplayConfig(numPathArrayElements, pathArray,numModeInfoArrayElements, modeInfoArray,flags);
	fprintf(fp,"OUT ['SetDisplayConfig',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LONG),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LONG));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *GetAncestor_fun) (HWND hwnd,UINT gaFlags);
GetAncestor_fun pGetAncestor = GetAncestor;
HOOK_TRACE_INFO hHookGetAncestor = { 0 };
ULONG HookGetAncestor_ACLEntries[1] = { 0 };
HWND fake_GetAncestor(HWND hwnd,UINT gaFlags){
	HWND ret = pGetAncestor(hwnd,gaFlags);
	fprintf(fp,"OUT ['GetAncestor',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *ExcludeUpdateRgn_fun) (HDC hDC,HWND hWnd);
ExcludeUpdateRgn_fun pExcludeUpdateRgn = ExcludeUpdateRgn;
HOOK_TRACE_INFO hHookExcludeUpdateRgn = { 0 };
ULONG HookExcludeUpdateRgn_ACLEntries[1] = { 0 };
int fake_ExcludeUpdateRgn(HDC hDC,HWND hWnd){
	int ret = pExcludeUpdateRgn(hDC,hWnd);
	fprintf(fp,"OUT ['ExcludeUpdateRgn',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *OemKeyScan_fun) (WORD wOemChar);
OemKeyScan_fun pOemKeyScan = OemKeyScan;
HOOK_TRACE_INFO hHookOemKeyScan = { 0 };
ULONG HookOemKeyScan_ACLEntries[1] = { 0 };
DWORD fake_OemKeyScan(WORD wOemChar){
	DWORD ret = pOemKeyScan(wOemChar);
	fprintf(fp,"OUT ['OemKeyScan',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LRESULT (WINAPI *CallWindowProcA_fun) (WNDPROC lpPrevWndFunc,HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
CallWindowProcA_fun pCallWindowProcA = CallWindowProcA;
HOOK_TRACE_INFO hHookCallWindowProcA = { 0 };
ULONG HookCallWindowProcA_ACLEntries[1] = { 0 };
LRESULT fake_CallWindowProcA(WNDPROC lpPrevWndFunc,HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pCallWindowProcA(lpPrevWndFunc,hWnd,Msg,wParam,lParam);
	fprintf(fp,"OUT ['CallWindowProcA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LRESULT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LRESULT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LONG (WINAPI *GetWindowLongA_fun) (HWND hWnd,int nIndex);
GetWindowLongA_fun pGetWindowLongA = GetWindowLongA;
HOOK_TRACE_INFO hHookGetWindowLongA = { 0 };
ULONG HookGetWindowLongA_ACLEntries[1] = { 0 };
LONG fake_GetWindowLongA(HWND hWnd,int nIndex){
	LONG ret = pGetWindowLongA(hWnd,nIndex);
	fprintf(fp,"OUT ['GetWindowLongA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LONG),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LONG));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetScrollRange_fun) (HWND hWnd,int nBar,LPINT lpMinPos,LPINT lpMaxPos);
GetScrollRange_fun pGetScrollRange = GetScrollRange;
HOOK_TRACE_INFO hHookGetScrollRange = { 0 };
ULONG HookGetScrollRange_ACLEntries[1] = { 0 };
BOOL fake_GetScrollRange(HWND hWnd,int nBar,LPINT lpMinPos,LPINT lpMaxPos){
	BOOL ret = pGetScrollRange(hWnd,nBar,lpMinPos,lpMaxPos);
	fprintf(fp,"OUT ['GetScrollRange',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpMinPos','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpMinPos, sizeof(LPINT),1);
 	else fprintf(fp,"{'name':'lpMinPos','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpMinPos,sizeof(LPINT));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpMaxPos','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpMaxPos, sizeof(LPINT),1);
 	else fprintf(fp,"{'name':'lpMaxPos','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpMaxPos,sizeof(LPINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *TranslateAcceleratorW_fun) (HWND hWnd,HACCEL hAccTable,LPMSG lpMsg);
TranslateAcceleratorW_fun pTranslateAcceleratorW = TranslateAcceleratorW;
HOOK_TRACE_INFO hHookTranslateAcceleratorW = { 0 };
ULONG HookTranslateAcceleratorW_ACLEntries[1] = { 0 };
int fake_TranslateAcceleratorW(HWND hWnd,HACCEL hAccTable,LPMSG lpMsg){
	int ret = pTranslateAcceleratorW(hWnd,hAccTable,lpMsg);
	fprintf(fp,"OUT ['TranslateAcceleratorW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HANDLE (WINAPI *LoadImageA_fun) (HINSTANCE hInst,LPCSTR name,UINT type,int cx,int cy,UINT fuLoad);
LoadImageA_fun pLoadImageA = LoadImageA;
HOOK_TRACE_INFO hHookLoadImageA = { 0 };
ULONG HookLoadImageA_ACLEntries[1] = { 0 };
HANDLE fake_LoadImageA(HINSTANCE hInst,LPCSTR name,UINT type,int cx,int cy,UINT fuLoad){
	HANDLE ret = pLoadImageA(hInst,name,type,cx,cy,fuLoad);
	fprintf(fp,"OUT ['LoadImageA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HANDLE),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HANDLE));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *DrawTextA_fun) (HDC hdc,LPCSTR lpchText,int cchText,LPRECT lprc,UINT format);
DrawTextA_fun pDrawTextA = DrawTextA;
HOOK_TRACE_INFO hHookDrawTextA = { 0 };
ULONG HookDrawTextA_ACLEntries[1] = { 0 };
int fake_DrawTextA(HDC hdc,LPCSTR lpchText,int cchText,LPRECT lprc,UINT format){
	int ret = pDrawTextA(hdc,lpchText,cchText,lprc,format);
	fprintf(fp,"OUT ['DrawTextA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpchText','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpchText, sizeof(LPCSTR),cchText);
 	else fprintf(fp,"{'name':'lpchText','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpchText,sizeof(LPCSTR));
	if(lpchText){
		for(int i=0; i<cchText;i++){
			fprintf(fp,"0x%x,",lpchText[i]);
		}
	}
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lprc','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lprc, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'lprc','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lprc,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetWindowTextA_fun) (HWND hWnd,LPCSTR lpString);
SetWindowTextA_fun pSetWindowTextA = SetWindowTextA;
HOOK_TRACE_INFO hHookSetWindowTextA = { 0 };
ULONG HookSetWindowTextA_ACLEntries[1] = { 0 };
BOOL fake_SetWindowTextA(HWND hWnd,LPCSTR lpString){
	BOOL ret = pSetWindowTextA(hWnd,lpString);
	fprintf(fp,"OUT ['SetWindowTextA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *GetTabbedTextExtentW_fun) (HDC hdc,LPCWSTR lpString,int chCount,int nTabPositions,CONST INT* lpnTabStopPositions);
GetTabbedTextExtentW_fun pGetTabbedTextExtentW = GetTabbedTextExtentW;
HOOK_TRACE_INFO hHookGetTabbedTextExtentW = { 0 };
ULONG HookGetTabbedTextExtentW_ACLEntries[1] = { 0 };
DWORD fake_GetTabbedTextExtentW(HDC hdc,LPCWSTR lpString,int chCount,int nTabPositions,CONST INT* lpnTabStopPositions){
	DWORD ret = pGetTabbedTextExtentW(hdc,lpString,chCount,nTabPositions,lpnTabStopPositions);
	fprintf(fp,"OUT ['GetTabbedTextExtentW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HDESK (WINAPI *OpenInputDesktop_fun) (DWORD dwFlags,BOOL fInherit,ACCESS_MASK dwDesiredAccess);
OpenInputDesktop_fun pOpenInputDesktop = OpenInputDesktop;
HOOK_TRACE_INFO hHookOpenInputDesktop = { 0 };
ULONG HookOpenInputDesktop_ACLEntries[1] = { 0 };
HDESK fake_OpenInputDesktop(DWORD dwFlags,BOOL fInherit,ACCESS_MASK dwDesiredAccess){
	HDESK ret = pOpenInputDesktop(dwFlags,fInherit,dwDesiredAccess);
	fprintf(fp,"OUT ['OpenInputDesktop',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HDESK),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HDESK));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *GetShellWindow_fun) ();
GetShellWindow_fun pGetShellWindow = GetShellWindow;
HOOK_TRACE_INFO hHookGetShellWindow = { 0 };
ULONG HookGetShellWindow_ACLEntries[1] = { 0 };
HWND fake_GetShellWindow(){
	HWND ret = pGetShellWindow();
	fprintf(fp,"OUT ['GetShellWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *GetMenuStringW_fun) (HMENU hMenu,UINT uIDItem,LPWSTR lpString,int cchMax,UINT flags);
GetMenuStringW_fun pGetMenuStringW = GetMenuStringW;
HOOK_TRACE_INFO hHookGetMenuStringW = { 0 };
ULONG HookGetMenuStringW_ACLEntries[1] = { 0 };
int fake_GetMenuStringW(HMENU hMenu,UINT uIDItem,LPWSTR lpString,int cchMax,UINT flags){
	int ret = pGetMenuStringW(hMenu,uIDItem,lpString,cchMax,flags);
	fprintf(fp,"OUT ['GetMenuStringW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'lpString',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': %p,", lpString);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': %p,", lpString);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),cchMax);
 	}else 
	{
		fprintf(fp,"{'name':'lpString',");
		fwprintf(fp, L"'value': %p, ", lpString);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	if(lpString){
		for(int i=0; i<cchMax;i++){
			fprintf(fp,"0x%x,",lpString[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *GetUpdateRgn_fun) (HWND hWnd,HRGN hRgn,BOOL bErase);
GetUpdateRgn_fun pGetUpdateRgn = GetUpdateRgn;
HOOK_TRACE_INFO hHookGetUpdateRgn = { 0 };
ULONG HookGetUpdateRgn_ACLEntries[1] = { 0 };
int fake_GetUpdateRgn(HWND hWnd,HRGN hRgn,BOOL bErase){
	int ret = pGetUpdateRgn(hWnd,hRgn,bErase);
	fprintf(fp,"OUT ['GetUpdateRgn',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *GetDlgCtrlID_fun) (HWND hWnd);
GetDlgCtrlID_fun pGetDlgCtrlID = GetDlgCtrlID;
HOOK_TRACE_INFO hHookGetDlgCtrlID = { 0 };
ULONG HookGetDlgCtrlID_ACLEntries[1] = { 0 };
int fake_GetDlgCtrlID(HWND hWnd){
	int ret = pGetDlgCtrlID(hWnd);
	fprintf(fp,"OUT ['GetDlgCtrlID',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ValidateRgn_fun) (HWND hWnd,HRGN hRgn);
ValidateRgn_fun pValidateRgn = ValidateRgn;
HOOK_TRACE_INFO hHookValidateRgn = { 0 };
ULONG HookValidateRgn_ACLEntries[1] = { 0 };
BOOL fake_ValidateRgn(HWND hWnd,HRGN hRgn){
	BOOL ret = pValidateRgn(hWnd,hRgn);
	fprintf(fp,"OUT ['ValidateRgn',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *CopyRect_fun) (LPRECT lprcDst,CONST RECT* lprcSrc);
CopyRect_fun pCopyRect = CopyRect;
HOOK_TRACE_INFO hHookCopyRect = { 0 };
ULONG HookCopyRect_ACLEntries[1] = { 0 };
BOOL fake_CopyRect(LPRECT lprcDst,CONST RECT* lprcSrc){
	BOOL ret = pCopyRect(lprcDst,lprcSrc);
	fprintf(fp,"OUT ['CopyRect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lprcDst','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lprcDst, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'lprcDst','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lprcDst,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LRESULT (WINAPI *SendMessageA_fun) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
SendMessageA_fun pSendMessageA = SendMessageA;
HOOK_TRACE_INFO hHookSendMessageA = { 0 };
ULONG HookSendMessageA_ACLEntries[1] = { 0 };
LRESULT fake_SendMessageA(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pSendMessageA(hWnd,Msg,wParam,lParam);
	fprintf(fp,"OUT ['SendMessageA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LRESULT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LRESULT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *AddClipboardFormatListener_fun) (HWND hwnd);
AddClipboardFormatListener_fun pAddClipboardFormatListener = AddClipboardFormatListener;
HOOK_TRACE_INFO hHookAddClipboardFormatListener = { 0 };
ULONG HookAddClipboardFormatListener_ACLEntries[1] = { 0 };
BOOL fake_AddClipboardFormatListener(HWND hwnd){
	BOOL ret = pAddClipboardFormatListener(hwnd);
	fprintf(fp,"OUT ['AddClipboardFormatListener',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWINSTA (WINAPI *OpenWindowStationA_fun) (LPCSTR lpszWinSta,BOOL fInherit,ACCESS_MASK dwDesiredAccess);
OpenWindowStationA_fun pOpenWindowStationA = OpenWindowStationA;
HOOK_TRACE_INFO hHookOpenWindowStationA = { 0 };
ULONG HookOpenWindowStationA_ACLEntries[1] = { 0 };
HWINSTA fake_OpenWindowStationA(LPCSTR lpszWinSta,BOOL fInherit,ACCESS_MASK dwDesiredAccess){
	HWINSTA ret = pOpenWindowStationA(lpszWinSta,fInherit,dwDesiredAccess);
	fprintf(fp,"OUT ['OpenWindowStationA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWINSTA),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWINSTA));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef long (WINAPI *GetDialogBaseUnits_fun) ();
GetDialogBaseUnits_fun pGetDialogBaseUnits = GetDialogBaseUnits;
HOOK_TRACE_INFO hHookGetDialogBaseUnits = { 0 };
ULONG HookGetDialogBaseUnits_ACLEntries[1] = { 0 };
long fake_GetDialogBaseUnits(){
	long ret = pGetDialogBaseUnits();
	fprintf(fp,"OUT ['GetDialogBaseUnits',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%llx,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(long),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%llx, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(long));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *DrawCaption_fun) (HWND hwnd,HDC hdc,CONST RECT*  lprect,UINT flags);
DrawCaption_fun pDrawCaption = DrawCaption;
HOOK_TRACE_INFO hHookDrawCaption = { 0 };
ULONG HookDrawCaption_ACLEntries[1] = { 0 };
BOOL fake_DrawCaption(HWND hwnd,HDC hdc,CONST RECT*  lprect,UINT flags){
	BOOL ret = pDrawCaption(hwnd,hdc, lprect,flags);
	fprintf(fp,"OUT ['DrawCaption',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *GetWindowTextLengthW_fun) (HWND hWnd);
GetWindowTextLengthW_fun pGetWindowTextLengthW = GetWindowTextLengthW;
HOOK_TRACE_INFO hHookGetWindowTextLengthW = { 0 };
ULONG HookGetWindowTextLengthW_ACLEntries[1] = { 0 };
int fake_GetWindowTextLengthW(HWND hWnd){
	int ret = pGetWindowTextLengthW(hWnd);
	fprintf(fp,"OUT ['GetWindowTextLengthW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LONG (WINAPI *GetDisplayConfigBufferSizes_fun) (UINT32 flags,UINT32*  numPathArrayElements,UINT32*  numModeInfoArrayElements);
GetDisplayConfigBufferSizes_fun pGetDisplayConfigBufferSizes = GetDisplayConfigBufferSizes;
HOOK_TRACE_INFO hHookGetDisplayConfigBufferSizes = { 0 };
ULONG HookGetDisplayConfigBufferSizes_ACLEntries[1] = { 0 };
LONG fake_GetDisplayConfigBufferSizes(UINT32 flags,UINT32*  numPathArrayElements,UINT32*  numModeInfoArrayElements){
	LONG ret = pGetDisplayConfigBufferSizes(flags, numPathArrayElements, numModeInfoArrayElements);
	fprintf(fp,"OUT ['GetDisplayConfigBufferSizes',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LONG),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LONG));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':' numPathArrayElements','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[", numPathArrayElements, sizeof(UINT32*),1);
 	else fprintf(fp,"{'name':' numPathArrayElements','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[", numPathArrayElements,sizeof(UINT32*));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':' numModeInfoArrayElements','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[", numModeInfoArrayElements, sizeof(UINT32*),1);
 	else fprintf(fp,"{'name':' numModeInfoArrayElements','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[", numModeInfoArrayElements,sizeof(UINT32*));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *RegisterHotKey_fun) (HWND hWnd,int id,UINT fsModifiers,UINT vk);
RegisterHotKey_fun pRegisterHotKey = RegisterHotKey;
HOOK_TRACE_INFO hHookRegisterHotKey = { 0 };
ULONG HookRegisterHotKey_ACLEntries[1] = { 0 };
BOOL fake_RegisterHotKey(HWND hWnd,int id,UINT fsModifiers,UINT vk){
	BOOL ret = pRegisterHotKey(hWnd,id,fsModifiers,vk);
	fprintf(fp,"OUT ['RegisterHotKey',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetClassInfoW_fun) (HINSTANCE hInstance,LPCWSTR lpClassName,LPWNDCLASSW lpWndClass);
GetClassInfoW_fun pGetClassInfoW = GetClassInfoW;
HOOK_TRACE_INFO hHookGetClassInfoW = { 0 };
ULONG HookGetClassInfoW_ACLEntries[1] = { 0 };
BOOL fake_GetClassInfoW(HINSTANCE hInstance,LPCWSTR lpClassName,LPWNDCLASSW lpWndClass){
	BOOL ret = pGetClassInfoW(hInstance,lpClassName,lpWndClass);
	fprintf(fp,"OUT ['GetClassInfoW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpWndClass','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpWndClass, sizeof(LPWNDCLASSW),1);
 	else fprintf(fp,"{'name':'lpWndClass','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpWndClass,sizeof(LPWNDCLASSW));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EnumChildWindows_fun) (HWND hWndParent,WNDENUMPROC lpEnumFunc,LPARAM lParam);
EnumChildWindows_fun pEnumChildWindows = EnumChildWindows;
HOOK_TRACE_INFO hHookEnumChildWindows = { 0 };
ULONG HookEnumChildWindows_ACLEntries[1] = { 0 };
BOOL fake_EnumChildWindows(HWND hWndParent,WNDENUMPROC lpEnumFunc,LPARAM lParam){
	BOOL ret = pEnumChildWindows(hWndParent,lpEnumFunc,lParam);
	fprintf(fp,"OUT ['EnumChildWindows',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LPSTR (WINAPI *CharPrevA_fun) (LPCSTR lpszStart,LPCSTR lpszCurrent);
CharPrevA_fun pCharPrevA = CharPrevA;
HOOK_TRACE_INFO hHookCharPrevA = { 0 };
ULONG HookCharPrevA_ACLEntries[1] = { 0 };
LPSTR fake_CharPrevA(LPCSTR lpszStart,LPCSTR lpszCurrent){
	LPSTR ret = pCharPrevA(lpszStart,lpszCurrent);
	fprintf(fp,"OUT ['CharPrevA',");
	if(1) fprintf(fp,"{'name':'ret','value': '\"%s\"','size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LPSTR),1);
 	else fprintf(fp,"{'name':'ret','value': '\"%s\"', 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LPSTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWINSTA (WINAPI *GetProcessWindowStation_fun) ();
GetProcessWindowStation_fun pGetProcessWindowStation = GetProcessWindowStation;
HOOK_TRACE_INFO hHookGetProcessWindowStation = { 0 };
ULONG HookGetProcessWindowStation_ACLEntries[1] = { 0 };
HWINSTA fake_GetProcessWindowStation(){
	HWINSTA ret = pGetProcessWindowStation();
	fprintf(fp,"OUT ['GetProcessWindowStation',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWINSTA),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWINSTA));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *MapVirtualKeyA_fun) (UINT uCode,UINT uMapType);
MapVirtualKeyA_fun pMapVirtualKeyA = MapVirtualKeyA;
HOOK_TRACE_INFO hHookMapVirtualKeyA = { 0 };
ULONG HookMapVirtualKeyA_ACLEntries[1] = { 0 };
UINT fake_MapVirtualKeyA(UINT uCode,UINT uMapType){
	UINT ret = pMapVirtualKeyA(uCode,uMapType);
	fprintf(fp,"OUT ['MapVirtualKeyA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *UnhookWindowsHook_fun) (int nCode,HOOKPROC pfnFilterProc);
UnhookWindowsHook_fun pUnhookWindowsHook = UnhookWindowsHook;
HOOK_TRACE_INFO hHookUnhookWindowsHook = { 0 };
ULONG HookUnhookWindowsHook_ACLEntries[1] = { 0 };
BOOL fake_UnhookWindowsHook(int nCode,HOOKPROC pfnFilterProc){
	BOOL ret = pUnhookWindowsHook(nCode,pfnFilterProc);
	fprintf(fp,"OUT ['UnhookWindowsHook',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *CharToOemBuffA_fun) (LPCSTR lpszSrc,LPSTR lpszDst,DWORD cchDstLength);
CharToOemBuffA_fun pCharToOemBuffA = CharToOemBuffA;
HOOK_TRACE_INFO hHookCharToOemBuffA = { 0 };
ULONG HookCharToOemBuffA_ACLEntries[1] = { 0 };
BOOL fake_CharToOemBuffA(LPCSTR lpszSrc,LPSTR lpszDst,DWORD cchDstLength){
	BOOL ret = pCharToOemBuffA(lpszSrc,lpszDst,cchDstLength);
	fprintf(fp,"OUT ['CharToOemBuffA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpszDst','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpszDst, sizeof(LPSTR),cchDstLength);
 	else fprintf(fp,"{'name':'lpszDst','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpszDst,sizeof(LPSTR));
	if(lpszDst){
		for(int i=0; i<cchDstLength;i++){
			fprintf(fp,"0x%x,",lpszDst[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *MapWindowPoints_fun) (HWND hWndFrom,HWND hWndTo,LPPOINT lpPoints,UINT cPoints);
MapWindowPoints_fun pMapWindowPoints = MapWindowPoints;
HOOK_TRACE_INFO hHookMapWindowPoints = { 0 };
ULONG HookMapWindowPoints_ACLEntries[1] = { 0 };
int fake_MapWindowPoints(HWND hWndFrom,HWND hWndTo,LPPOINT lpPoints,UINT cPoints){
	int ret = pMapWindowPoints(hWndFrom,hWndTo,lpPoints,cPoints);
	fprintf(fp,"OUT ['MapWindowPoints',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpPoints','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpPoints, sizeof(LPPOINT),cPoints);
 	else fprintf(fp,"{'name':'lpPoints','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpPoints,sizeof(LPPOINT));
	if(lpPoints){
		for(int i=0; i<cPoints;i++){
			fprintf(fp,"0x%x,",lpPoints[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LPWSTR (WINAPI *CharUpperW_fun) (LPWSTR lpsz);
CharUpperW_fun pCharUpperW = CharUpperW;
HOOK_TRACE_INFO hHookCharUpperW = { 0 };
ULONG HookCharUpperW_ACLEntries[1] = { 0 };
LPWSTR fake_CharUpperW(LPWSTR lpsz){
	LPWSTR ret = pCharUpperW(lpsz);
	fprintf(fp,"OUT ['CharUpperW',");
	if(1)
	{
		fprintf(fp,"{'name':'ret',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': '\"%s\"',", ret);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': '\"%s\"',", ret);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),1);
 	}else 
	{
		fprintf(fp,"{'name':'ret',");
		fwprintf(fp, L"'value': '\"%s\"', ", ret);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'lpsz',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': '\"%s\"',", lpsz);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': '\"%s\"',", lpsz);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),1);
 	}else 
	{
		fprintf(fp,"{'name':'lpsz',");
		fwprintf(fp, L"'value': '\"%s\"', ", lpsz);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *WaitForInputIdle_fun) (HANDLE hProcess,DWORD dwMilliseconds);
WaitForInputIdle_fun pWaitForInputIdle = WaitForInputIdle;
HOOK_TRACE_INFO hHookWaitForInputIdle = { 0 };
ULONG HookWaitForInputIdle_ACLEntries[1] = { 0 };
DWORD fake_WaitForInputIdle(HANDLE hProcess,DWORD dwMilliseconds){
	DWORD ret = pWaitForInputIdle(hProcess,dwMilliseconds);
	fprintf(fp,"OUT ['WaitForInputIdle',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *MessageBoxA_fun) (HWND hWnd,LPCSTR lpText,LPCSTR lpCaption,UINT uType);
MessageBoxA_fun pMessageBoxA = MessageBoxA;
HOOK_TRACE_INFO hHookMessageBoxA = { 0 };
ULONG HookMessageBoxA_ACLEntries[1] = { 0 };
int fake_MessageBoxA(HWND hWnd,LPCSTR lpText,LPCSTR lpCaption,UINT uType){
	int ret = pMessageBoxA(hWnd,lpText,lpCaption,uType);
	fprintf(fp,"OUT ['MessageBoxA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SendNotifyMessageW_fun) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
SendNotifyMessageW_fun pSendNotifyMessageW = SendNotifyMessageW;
HOOK_TRACE_INFO hHookSendNotifyMessageW = { 0 };
ULONG HookSendNotifyMessageW_ACLEntries[1] = { 0 };
BOOL fake_SendNotifyMessageW(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam){
	BOOL ret = pSendNotifyMessageW(hWnd,Msg,wParam,lParam);
	fprintf(fp,"OUT ['SendNotifyMessageW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *FindWindowW_fun) (LPCWSTR lpClassName,LPCWSTR lpWindowName);
FindWindowW_fun pFindWindowW = FindWindowW;
HOOK_TRACE_INFO hHookFindWindowW = { 0 };
ULONG HookFindWindowW_ACLEntries[1] = { 0 };
HWND fake_FindWindowW(LPCWSTR lpClassName,LPCWSTR lpWindowName){
	HWND ret = pFindWindowW(lpClassName,lpWindowName);
	fprintf(fp,"OUT ['FindWindowW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *CallMsgFilterW_fun) (LPMSG lpMsg,int nCode);
CallMsgFilterW_fun pCallMsgFilterW = CallMsgFilterW;
HOOK_TRACE_INFO hHookCallMsgFilterW = { 0 };
ULONG HookCallMsgFilterW_ACLEntries[1] = { 0 };
BOOL fake_CallMsgFilterW(LPMSG lpMsg,int nCode){
	BOOL ret = pCallMsgFilterW(lpMsg,nCode);
	fprintf(fp,"OUT ['CallMsgFilterW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *RegisterRawInputDevices_fun) (PCRAWINPUTDEVICE pRawInputDevices,UINT uiNumDevices,UINT cbSize);
RegisterRawInputDevices_fun pRegisterRawInputDevices = RegisterRawInputDevices;
HOOK_TRACE_INFO hHookRegisterRawInputDevices = { 0 };
ULONG HookRegisterRawInputDevices_ACLEntries[1] = { 0 };
BOOL fake_RegisterRawInputDevices(PCRAWINPUTDEVICE pRawInputDevices,UINT uiNumDevices,UINT cbSize){
	BOOL ret = pRegisterRawInputDevices(pRawInputDevices,uiNumDevices,cbSize);
	fprintf(fp,"OUT ['RegisterRawInputDevices',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HMENU (WINAPI *GetSubMenu_fun) (HMENU hMenu,int nPos);
GetSubMenu_fun pGetSubMenu = GetSubMenu;
HOOK_TRACE_INFO hHookGetSubMenu = { 0 };
ULONG HookGetSubMenu_ACLEntries[1] = { 0 };
HMENU fake_GetSubMenu(HMENU hMenu,int nPos){
	HMENU ret = pGetSubMenu(hMenu,nPos);
	fprintf(fp,"OUT ['GetSubMenu',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HMENU),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HMENU));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef SHORT (WINAPI *VkKeyScanExA_fun) (CHAR ch,HKL dwhkl);
VkKeyScanExA_fun pVkKeyScanExA = VkKeyScanExA;
HOOK_TRACE_INFO hHookVkKeyScanExA = { 0 };
ULONG HookVkKeyScanExA_ACLEntries[1] = { 0 };
SHORT fake_VkKeyScanExA(CHAR ch,HKL dwhkl){
	SHORT ret = pVkKeyScanExA(ch,dwhkl);
	fprintf(fp,"OUT ['VkKeyScanExA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%hx,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(SHORT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%hx, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(SHORT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetUpdateRect_fun) (HWND hWnd,LPRECT lpRect,BOOL bErase);
GetUpdateRect_fun pGetUpdateRect = GetUpdateRect;
HOOK_TRACE_INFO hHookGetUpdateRect = { 0 };
ULONG HookGetUpdateRect_ACLEntries[1] = { 0 };
BOOL fake_GetUpdateRect(HWND hWnd,LPRECT lpRect,BOOL bErase){
	BOOL ret = pGetUpdateRect(hWnd,lpRect,bErase);
	fprintf(fp,"OUT ['GetUpdateRect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpRect','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpRect, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'lpRect','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpRect,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *DrawStateW_fun) (HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfnCallBack,LPARAM lData,WPARAM wData,int x,int y,int cx,int cy,UINT uFlags);
DrawStateW_fun pDrawStateW = DrawStateW;
HOOK_TRACE_INFO hHookDrawStateW = { 0 };
ULONG HookDrawStateW_ACLEntries[1] = { 0 };
BOOL fake_DrawStateW(HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfnCallBack,LPARAM lData,WPARAM wData,int x,int y,int cx,int cy,UINT uFlags){
	BOOL ret = pDrawStateW(hdc,hbrFore,qfnCallBack,lData,wData,x,y,cx,cy,uFlags);
	fprintf(fp,"OUT ['DrawStateW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef ULONG_PTR (WINAPI *GetClassLongPtrA_fun) (HWND hWnd,int nIndex);
GetClassLongPtrA_fun pGetClassLongPtrA = GetClassLongPtrA;
HOOK_TRACE_INFO hHookGetClassLongPtrA = { 0 };
ULONG HookGetClassLongPtrA_ACLEntries[1] = { 0 };
ULONG_PTR fake_GetClassLongPtrA(HWND hWnd,int nIndex){
	ULONG_PTR ret = pGetClassLongPtrA(hWnd,nIndex);
	fprintf(fp,"OUT ['GetClassLongPtrA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(ULONG_PTR),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(ULONG_PTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *TrackMouseEvent_fun) (LPTRACKMOUSEEVENT lpEventTrack);
TrackMouseEvent_fun pTrackMouseEvent = TrackMouseEvent;
HOOK_TRACE_INFO hHookTrackMouseEvent = { 0 };
ULONG HookTrackMouseEvent_ACLEntries[1] = { 0 };
BOOL fake_TrackMouseEvent(LPTRACKMOUSEEVENT lpEventTrack){
	BOOL ret = pTrackMouseEvent(lpEventTrack);
	fprintf(fp,"OUT ['TrackMouseEvent',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpEventTrack','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpEventTrack, sizeof(LPTRACKMOUSEEVENT),1);
 	else fprintf(fp,"{'name':'lpEventTrack','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpEventTrack,sizeof(LPTRACKMOUSEEVENT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetKeyboardState_fun) (LPBYTE lpKeyState);
SetKeyboardState_fun pSetKeyboardState = SetKeyboardState;
HOOK_TRACE_INFO hHookSetKeyboardState = { 0 };
ULONG HookSetKeyboardState_ACLEntries[1] = { 0 };
BOOL fake_SetKeyboardState(LPBYTE lpKeyState){
	BOOL ret = pSetKeyboardState(lpKeyState);
	fprintf(fp,"OUT ['SetKeyboardState',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *UpdateWindow_fun) (HWND hWnd);
UpdateWindow_fun pUpdateWindow = UpdateWindow;
HOOK_TRACE_INFO hHookUpdateWindow = { 0 };
ULONG HookUpdateWindow_ACLEntries[1] = { 0 };
BOOL fake_UpdateWindow(HWND hWnd){
	BOOL ret = pUpdateWindow(hWnd);
	fprintf(fp,"OUT ['UpdateWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *ChildWindowFromPoint_fun) (HWND hWndParent,POINT Point);
ChildWindowFromPoint_fun pChildWindowFromPoint = ChildWindowFromPoint;
HOOK_TRACE_INFO hHookChildWindowFromPoint = { 0 };
ULONG HookChildWindowFromPoint_ACLEntries[1] = { 0 };
HWND fake_ChildWindowFromPoint(HWND hWndParent,POINT Point){
	HWND ret = pChildWindowFromPoint(hWndParent,Point);
	fprintf(fp,"OUT ['ChildWindowFromPoint',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *ScrollWindowEx_fun) (HWND hWnd,int dx,int dy,CONST RECT* prcScroll,CONST RECT* prcClip,HRGN hrgnUpdate,LPRECT prcUpdate,UINT flags);
ScrollWindowEx_fun pScrollWindowEx = ScrollWindowEx;
HOOK_TRACE_INFO hHookScrollWindowEx = { 0 };
ULONG HookScrollWindowEx_ACLEntries[1] = { 0 };
int fake_ScrollWindowEx(HWND hWnd,int dx,int dy,CONST RECT* prcScroll,CONST RECT* prcClip,HRGN hrgnUpdate,LPRECT prcUpdate,UINT flags){
	int ret = pScrollWindowEx(hWnd,dx,dy,prcScroll,prcClip,hrgnUpdate,prcUpdate,flags);
	fprintf(fp,"OUT ['ScrollWindowEx',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'prcUpdate','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",prcUpdate, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'prcUpdate','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",prcUpdate,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *GetMessagePos_fun) ();
GetMessagePos_fun pGetMessagePos = GetMessagePos;
HOOK_TRACE_INFO hHookGetMessagePos = { 0 };
ULONG HookGetMessagePos_ACLEntries[1] = { 0 };
DWORD fake_GetMessagePos(){
	DWORD ret = pGetMessagePos();
	fprintf(fp,"OUT ['GetMessagePos',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *MapDialogRect_fun) (HWND hDlg,LPRECT lpRect);
MapDialogRect_fun pMapDialogRect = MapDialogRect;
HOOK_TRACE_INFO hHookMapDialogRect = { 0 };
ULONG HookMapDialogRect_ACLEntries[1] = { 0 };
BOOL fake_MapDialogRect(HWND hDlg,LPRECT lpRect){
	BOOL ret = pMapDialogRect(hDlg,lpRect);
	fprintf(fp,"OUT ['MapDialogRect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpRect','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpRect, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'lpRect','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpRect,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ChangeClipboardChain_fun) (HWND hWndRemove,HWND hWndNewNext);
ChangeClipboardChain_fun pChangeClipboardChain = ChangeClipboardChain;
HOOK_TRACE_INFO hHookChangeClipboardChain = { 0 };
ULONG HookChangeClipboardChain_ACLEntries[1] = { 0 };
BOOL fake_ChangeClipboardChain(HWND hWndRemove,HWND hWndNewNext){
	BOOL ret = pChangeClipboardChain(hWndRemove,hWndNewNext);
	fprintf(fp,"OUT ['ChangeClipboardChain',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HBITMAP (WINAPI *LoadBitmapA_fun) (HINSTANCE hInstance,LPCSTR lpBitmapName);
LoadBitmapA_fun pLoadBitmapA = LoadBitmapA;
HOOK_TRACE_INFO hHookLoadBitmapA = { 0 };
ULONG HookLoadBitmapA_ACLEntries[1] = { 0 };
HBITMAP fake_LoadBitmapA(HINSTANCE hInstance,LPCSTR lpBitmapName){
	HBITMAP ret = pLoadBitmapA(hInstance,lpBitmapName);
	fprintf(fp,"OUT ['LoadBitmapA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HBITMAP),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HBITMAP));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef WORD (WINAPI *CascadeWindows_fun) (HWND hwndParent,UINT wHow,CONST RECT*  lpRect,UINT cKids,CONST HWND*  lpKids);
CascadeWindows_fun pCascadeWindows = CascadeWindows;
HOOK_TRACE_INFO hHookCascadeWindows = { 0 };
ULONG HookCascadeWindows_ACLEntries[1] = { 0 };
WORD fake_CascadeWindows(HWND hwndParent,UINT wHow,CONST RECT*  lpRect,UINT cKids,CONST HWND*  lpKids){
	WORD ret = pCascadeWindows(hwndParent,wHow, lpRect,cKids, lpKids);
	fprintf(fp,"OUT ['CascadeWindows',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%hx,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(WORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%hx, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(WORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HDESK (WINAPI *GetThreadDesktop_fun) (DWORD dwThreadId);
GetThreadDesktop_fun pGetThreadDesktop = GetThreadDesktop;
HOOK_TRACE_INFO hHookGetThreadDesktop = { 0 };
ULONG HookGetThreadDesktop_ACLEntries[1] = { 0 };
HDESK fake_GetThreadDesktop(DWORD dwThreadId){
	HDESK ret = pGetThreadDesktop(dwThreadId);
	fprintf(fp,"OUT ['GetThreadDesktop',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HDESK),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HDESK));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetUpdatedClipboardFormats_fun) (PUINT lpuiFormats,UINT cFormats,PUINT pcFormatsOut);
GetUpdatedClipboardFormats_fun pGetUpdatedClipboardFormats = GetUpdatedClipboardFormats;
HOOK_TRACE_INFO hHookGetUpdatedClipboardFormats = { 0 };
ULONG HookGetUpdatedClipboardFormats_ACLEntries[1] = { 0 };
BOOL fake_GetUpdatedClipboardFormats(PUINT lpuiFormats,UINT cFormats,PUINT pcFormatsOut){
	BOOL ret = pGetUpdatedClipboardFormats(lpuiFormats,cFormats,pcFormatsOut);
	fprintf(fp,"OUT ['GetUpdatedClipboardFormats',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpuiFormats','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpuiFormats, sizeof(PUINT),cFormats);
 	else fprintf(fp,"{'name':'lpuiFormats','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpuiFormats,sizeof(PUINT));
	if(lpuiFormats){
		for(int i=0; i<cFormats;i++){
			fprintf(fp,"0x%x,",lpuiFormats[i]);
		}
	}
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pcFormatsOut','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pcFormatsOut, sizeof(PUINT),1);
 	else fprintf(fp,"{'name':'pcFormatsOut','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pcFormatsOut,sizeof(PUINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ShutdownBlockReasonCreate_fun) (HWND hWnd,LPCWSTR pwszReason);
ShutdownBlockReasonCreate_fun pShutdownBlockReasonCreate = ShutdownBlockReasonCreate;
HOOK_TRACE_INFO hHookShutdownBlockReasonCreate = { 0 };
ULONG HookShutdownBlockReasonCreate_ACLEntries[1] = { 0 };
BOOL fake_ShutdownBlockReasonCreate(HWND hWnd,LPCWSTR pwszReason){
	BOOL ret = pShutdownBlockReasonCreate(hWnd,pwszReason);
	fprintf(fp,"OUT ['ShutdownBlockReasonCreate',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *GetKBCodePage_fun) ();
GetKBCodePage_fun pGetKBCodePage = GetKBCodePage;
HOOK_TRACE_INFO hHookGetKBCodePage = { 0 };
ULONG HookGetKBCodePage_ACLEntries[1] = { 0 };
UINT fake_GetKBCodePage(){
	UINT ret = pGetKBCodePage();
	fprintf(fp,"OUT ['GetKBCodePage',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *EnumClipboardFormats_fun) (UINT format);
EnumClipboardFormats_fun pEnumClipboardFormats = EnumClipboardFormats;
HOOK_TRACE_INFO hHookEnumClipboardFormats = { 0 };
ULONG HookEnumClipboardFormats_ACLEntries[1] = { 0 };
UINT fake_EnumClipboardFormats(UINT format){
	UINT ret = pEnumClipboardFormats(format);
	fprintf(fp,"OUT ['EnumClipboardFormats',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HICON (WINAPI *LoadIconA_fun) (HINSTANCE hInstance,LPCSTR lpIconName);
LoadIconA_fun pLoadIconA = LoadIconA;
HOOK_TRACE_INFO hHookLoadIconA = { 0 };
ULONG HookLoadIconA_ACLEntries[1] = { 0 };
HICON fake_LoadIconA(HINSTANCE hInstance,LPCSTR lpIconName){
	HICON ret = pLoadIconA(hInstance,lpIconName);
	fprintf(fp,"OUT ['LoadIconA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HICON),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HICON));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *InvertRect_fun) (HDC hDC,CONST RECT* lprc);
InvertRect_fun pInvertRect = InvertRect;
HOOK_TRACE_INFO hHookInvertRect = { 0 };
ULONG HookInvertRect_ACLEntries[1] = { 0 };
BOOL fake_InvertRect(HDC hDC,CONST RECT* lprc){
	BOOL ret = pInvertRect(hDC,lprc);
	fprintf(fp,"OUT ['InvertRect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EndPaint_fun) (HWND hWnd,CONST PAINTSTRUCT* lpPaint);
EndPaint_fun pEndPaint = EndPaint;
HOOK_TRACE_INFO hHookEndPaint = { 0 };
ULONG HookEndPaint_ACLEntries[1] = { 0 };
BOOL fake_EndPaint(HWND hWnd,CONST PAINTSTRUCT* lpPaint){
	BOOL ret = pEndPaint(hWnd,lpPaint);
	fprintf(fp,"OUT ['EndPaint',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ShutdownBlockReasonDestroy_fun) (HWND hWnd);
ShutdownBlockReasonDestroy_fun pShutdownBlockReasonDestroy = ShutdownBlockReasonDestroy;
HOOK_TRACE_INFO hHookShutdownBlockReasonDestroy = { 0 };
ULONG HookShutdownBlockReasonDestroy_ACLEntries[1] = { 0 };
BOOL fake_ShutdownBlockReasonDestroy(HWND hWnd){
	BOOL ret = pShutdownBlockReasonDestroy(hWnd);
	fprintf(fp,"OUT ['ShutdownBlockReasonDestroy',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *AdjustWindowRect_fun) (LPRECT lpRect,DWORD dwStyle,BOOL bMenu);
AdjustWindowRect_fun pAdjustWindowRect = AdjustWindowRect;
HOOK_TRACE_INFO hHookAdjustWindowRect = { 0 };
ULONG HookAdjustWindowRect_ACLEntries[1] = { 0 };
BOOL fake_AdjustWindowRect(LPRECT lpRect,DWORD dwStyle,BOOL bMenu){
	BOOL ret = pAdjustWindowRect(lpRect,dwStyle,bMenu);
	fprintf(fp,"OUT ['AdjustWindowRect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpRect','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpRect, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'lpRect','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpRect,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *WindowFromPhysicalPoint_fun) (POINT Point);
WindowFromPhysicalPoint_fun pWindowFromPhysicalPoint = WindowFromPhysicalPoint;
HOOK_TRACE_INFO hHookWindowFromPhysicalPoint = { 0 };
ULONG HookWindowFromPhysicalPoint_ACLEntries[1] = { 0 };
HWND fake_WindowFromPhysicalPoint(POINT Point){
	HWND ret = pWindowFromPhysicalPoint(Point);
	fprintf(fp,"OUT ['WindowFromPhysicalPoint',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *GetGuiResources_fun) (HANDLE hProcess,DWORD uiFlags);
GetGuiResources_fun pGetGuiResources = GetGuiResources;
HOOK_TRACE_INFO hHookGetGuiResources = { 0 };
ULONG HookGetGuiResources_ACLEntries[1] = { 0 };
DWORD fake_GetGuiResources(HANDLE hProcess,DWORD uiFlags){
	DWORD ret = pGetGuiResources(hProcess,uiFlags);
	fprintf(fp,"OUT ['GetGuiResources',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *RegisterWindowMessageW_fun) (LPCWSTR lpString);
RegisterWindowMessageW_fun pRegisterWindowMessageW = RegisterWindowMessageW;
HOOK_TRACE_INFO hHookRegisterWindowMessageW = { 0 };
ULONG HookRegisterWindowMessageW_ACLEntries[1] = { 0 };
UINT fake_RegisterWindowMessageW(LPCWSTR lpString){
	UINT ret = pRegisterWindowMessageW(lpString);
	fprintf(fp,"OUT ['RegisterWindowMessageW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *IsDlgButtonChecked_fun) (HWND hDlg,int nIDButton);
IsDlgButtonChecked_fun pIsDlgButtonChecked = IsDlgButtonChecked;
HOOK_TRACE_INFO hHookIsDlgButtonChecked = { 0 };
ULONG HookIsDlgButtonChecked_ACLEntries[1] = { 0 };
UINT fake_IsDlgButtonChecked(HWND hDlg,int nIDButton){
	UINT ret = pIsDlgButtonChecked(hDlg,nIDButton);
	fprintf(fp,"OUT ['IsDlgButtonChecked',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *RemoveClipboardFormatListener_fun) (HWND hwnd);
RemoveClipboardFormatListener_fun pRemoveClipboardFormatListener = RemoveClipboardFormatListener;
HOOK_TRACE_INFO hHookRemoveClipboardFormatListener = { 0 };
ULONG HookRemoveClipboardFormatListener_ACLEntries[1] = { 0 };
BOOL fake_RemoveClipboardFormatListener(HWND hwnd){
	BOOL ret = pRemoveClipboardFormatListener(hwnd);
	fprintf(fp,"OUT ['RemoveClipboardFormatListener',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *GetWindowRgn_fun) (HWND hWnd,HRGN hRgn);
GetWindowRgn_fun pGetWindowRgn = GetWindowRgn;
HOOK_TRACE_INFO hHookGetWindowRgn = { 0 };
ULONG HookGetWindowRgn_ACLEntries[1] = { 0 };
int fake_GetWindowRgn(HWND hWnd,HRGN hRgn){
	int ret = pGetWindowRgn(hWnd,hRgn);
	fprintf(fp,"OUT ['GetWindowRgn',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetAltTabInfoA_fun) (HWND hwnd,int iItem,PALTTABINFO pati,LPSTR pszItemText,UINT cchItemText);
GetAltTabInfoA_fun pGetAltTabInfoA = GetAltTabInfoA;
HOOK_TRACE_INFO hHookGetAltTabInfoA = { 0 };
ULONG HookGetAltTabInfoA_ACLEntries[1] = { 0 };
BOOL fake_GetAltTabInfoA(HWND hwnd,int iItem,PALTTABINFO pati,LPSTR pszItemText,UINT cchItemText){
	BOOL ret = pGetAltTabInfoA(hwnd,iItem,pati,pszItemText,cchItemText);
	fprintf(fp,"OUT ['GetAltTabInfoA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pati','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pati, sizeof(PALTTABINFO),1);
 	else fprintf(fp,"{'name':'pati','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pati,sizeof(PALTTABINFO));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pszItemText','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pszItemText, sizeof(LPSTR),cchItemText);
 	else fprintf(fp,"{'name':'pszItemText','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pszItemText,sizeof(LPSTR));
	if(pszItemText){
		for(int i=0; i<cchItemText;i++){
			fprintf(fp,"0x%x,",pszItemText[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LPSTR (WINAPI *CharUpperA_fun) (LPSTR lpsz);
CharUpperA_fun pCharUpperA = CharUpperA;
HOOK_TRACE_INFO hHookCharUpperA = { 0 };
ULONG HookCharUpperA_ACLEntries[1] = { 0 };
LPSTR fake_CharUpperA(LPSTR lpsz){
	LPSTR ret = pCharUpperA(lpsz);
	fprintf(fp,"OUT ['CharUpperA',");
	if(1) fprintf(fp,"{'name':'ret','value': '\"%s\"','size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LPSTR),1);
 	else fprintf(fp,"{'name':'ret','value': '\"%s\"', 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LPSTR));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpsz','value': '\"%s\"','size' : 0x%lx,'cnt':0x%x, 'data':[",lpsz, sizeof(LPSTR),1);
 	else fprintf(fp,"{'name':'lpsz','value': '\"%s\"', 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpsz,sizeof(LPSTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsWow64Message_fun) ();
IsWow64Message_fun pIsWow64Message = IsWow64Message;
HOOK_TRACE_INFO hHookIsWow64Message = { 0 };
ULONG HookIsWow64Message_ACLEntries[1] = { 0 };
BOOL fake_IsWow64Message(){
	BOOL ret = pIsWow64Message();
	fprintf(fp,"OUT ['IsWow64Message',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetMenuContextHelpId_fun) (HMENU arg0,DWORD arg1);
SetMenuContextHelpId_fun pSetMenuContextHelpId = SetMenuContextHelpId;
HOOK_TRACE_INFO hHookSetMenuContextHelpId = { 0 };
ULONG HookSetMenuContextHelpId_ACLEntries[1] = { 0 };
BOOL fake_SetMenuContextHelpId(HMENU arg0,DWORD arg1){
	BOOL ret = pSetMenuContextHelpId(arg0,arg1);
	fprintf(fp,"OUT ['SetMenuContextHelpId',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsIconic_fun) (HWND hWnd);
IsIconic_fun pIsIconic = IsIconic;
HOOK_TRACE_INFO hHookIsIconic = { 0 };
ULONG HookIsIconic_ACLEntries[1] = { 0 };
BOOL fake_IsIconic(HWND hWnd){
	BOOL ret = pIsIconic(hWnd);
	fprintf(fp,"OUT ['IsIconic',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetGestureConfig_fun) (HWND hwnd,DWORD dwReserved,UINT cIDs,PGESTURECONFIG pGestureConfig,UINT cbSize);
SetGestureConfig_fun pSetGestureConfig = SetGestureConfig;
HOOK_TRACE_INFO hHookSetGestureConfig = { 0 };
ULONG HookSetGestureConfig_ACLEntries[1] = { 0 };
BOOL fake_SetGestureConfig(HWND hwnd,DWORD dwReserved,UINT cIDs,PGESTURECONFIG pGestureConfig,UINT cbSize){
	BOOL ret = pSetGestureConfig(hwnd,dwReserved,cIDs,pGestureConfig,cbSize);
	fprintf(fp,"OUT ['SetGestureConfig',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LRESULT (WINAPI *SendDlgItemMessageA_fun) (HWND hDlg,int nIDDlgItem,UINT Msg,WPARAM wParam,LPARAM lParam);
SendDlgItemMessageA_fun pSendDlgItemMessageA = SendDlgItemMessageA;
HOOK_TRACE_INFO hHookSendDlgItemMessageA = { 0 };
ULONG HookSendDlgItemMessageA_ACLEntries[1] = { 0 };
LRESULT fake_SendDlgItemMessageA(HWND hDlg,int nIDDlgItem,UINT Msg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pSendDlgItemMessageA(hDlg,nIDDlgItem,Msg,wParam,lParam);
	fprintf(fp,"OUT ['SendDlgItemMessageA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LRESULT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LRESULT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LONG (WINAPI *TabbedTextOutA_fun) (HDC hdc,int x,int y,LPCSTR lpString,int chCount,int nTabPositions,CONST INT* lpnTabStopPositions,int nTabOrigin);
TabbedTextOutA_fun pTabbedTextOutA = TabbedTextOutA;
HOOK_TRACE_INFO hHookTabbedTextOutA = { 0 };
ULONG HookTabbedTextOutA_ACLEntries[1] = { 0 };
LONG fake_TabbedTextOutA(HDC hdc,int x,int y,LPCSTR lpString,int chCount,int nTabPositions,CONST INT* lpnTabStopPositions,int nTabOrigin){
	LONG ret = pTabbedTextOutA(hdc,x,y,lpString,chCount,nTabPositions,lpnTabStopPositions,nTabOrigin);
	fprintf(fp,"OUT ['TabbedTextOutA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LONG),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LONG));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetMenu_fun) (HWND hWnd,HMENU hMenu);
SetMenu_fun pSetMenu = SetMenu;
HOOK_TRACE_INFO hHookSetMenu = { 0 };
ULONG HookSetMenu_ACLEntries[1] = { 0 };
BOOL fake_SetMenu(HWND hWnd,HMENU hMenu){
	BOOL ret = pSetMenu(hWnd,hMenu);
	fprintf(fp,"OUT ['SetMenu',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HMONITOR (WINAPI *MonitorFromRect_fun) (LPCRECT lprc,DWORD dwFlags);
MonitorFromRect_fun pMonitorFromRect = MonitorFromRect;
HOOK_TRACE_INFO hHookMonitorFromRect = { 0 };
ULONG HookMonitorFromRect_ACLEntries[1] = { 0 };
HMONITOR fake_MonitorFromRect(LPCRECT lprc,DWORD dwFlags){
	HMONITOR ret = pMonitorFromRect(lprc,dwFlags);
	fprintf(fp,"OUT ['MonitorFromRect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HMONITOR),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HMONITOR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *UnionRect_fun) (LPRECT lprcDst,CONST RECT* lprcSrc1,CONST RECT* lprcSrc2);
UnionRect_fun pUnionRect = UnionRect;
HOOK_TRACE_INFO hHookUnionRect = { 0 };
ULONG HookUnionRect_ACLEntries[1] = { 0 };
BOOL fake_UnionRect(LPRECT lprcDst,CONST RECT* lprcSrc1,CONST RECT* lprcSrc2){
	BOOL ret = pUnionRect(lprcDst,lprcSrc1,lprcSrc2);
	fprintf(fp,"OUT ['UnionRect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lprcDst','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lprcDst, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'lprcDst','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lprcDst,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *PostThreadMessageW_fun) (DWORD idThread,UINT Msg,WPARAM wParam,LPARAM lParam);
PostThreadMessageW_fun pPostThreadMessageW = PostThreadMessageW;
HOOK_TRACE_INFO hHookPostThreadMessageW = { 0 };
ULONG HookPostThreadMessageW_ACLEntries[1] = { 0 };
BOOL fake_PostThreadMessageW(DWORD idThread,UINT Msg,WPARAM wParam,LPARAM lParam){
	BOOL ret = pPostThreadMessageW(idThread,Msg,wParam,lParam);
	fprintf(fp,"OUT ['PostThreadMessageW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetUserObjectInformationA_fun) (HANDLE hObj,int nIndex,PVOID pvInfo,DWORD nLength,LPDWORD lpnLengthNeeded);
GetUserObjectInformationA_fun pGetUserObjectInformationA = GetUserObjectInformationA;
HOOK_TRACE_INFO hHookGetUserObjectInformationA = { 0 };
ULONG HookGetUserObjectInformationA_ACLEntries[1] = { 0 };
BOOL fake_GetUserObjectInformationA(HANDLE hObj,int nIndex,PVOID pvInfo,DWORD nLength,LPDWORD lpnLengthNeeded){
	BOOL ret = pGetUserObjectInformationA(hObj,nIndex,pvInfo,nLength,lpnLengthNeeded);
	fprintf(fp,"OUT ['GetUserObjectInformationA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pvInfo','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pvInfo, sizeof(PVOID),1);
 	else fprintf(fp,"{'name':'pvInfo','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pvInfo,sizeof(PVOID));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpnLengthNeeded','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpnLengthNeeded, sizeof(LPDWORD),1);
 	else fprintf(fp,"{'name':'lpnLengthNeeded','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpnLengthNeeded,sizeof(LPDWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ChangeMenuW_fun) (HMENU hMenu,UINT cmd,LPCWSTR lpszNewItem,UINT cmdInsert,UINT flags);
ChangeMenuW_fun pChangeMenuW = ChangeMenuW;
HOOK_TRACE_INFO hHookChangeMenuW = { 0 };
ULONG HookChangeMenuW_ACLEntries[1] = { 0 };
BOOL fake_ChangeMenuW(HMENU hMenu,UINT cmd,LPCWSTR lpszNewItem,UINT cmdInsert,UINT flags){
	BOOL ret = pChangeMenuW(hMenu,cmd,lpszNewItem,cmdInsert,flags);
	fprintf(fp,"OUT ['ChangeMenuW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HANDLE (WINAPI *RemovePropA_fun) (HWND hWnd,LPCSTR lpString);
RemovePropA_fun pRemovePropA = RemovePropA;
HOOK_TRACE_INFO hHookRemovePropA = { 0 };
ULONG HookRemovePropA_ACLEntries[1] = { 0 };
HANDLE fake_RemovePropA(HWND hWnd,LPCSTR lpString){
	HANDLE ret = pRemovePropA(hWnd,lpString);
	fprintf(fp,"OUT ['RemovePropA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HANDLE),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HANDLE));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetClientRect_fun) (HWND hWnd,LPRECT lpRect);
GetClientRect_fun pGetClientRect = GetClientRect;
HOOK_TRACE_INFO hHookGetClientRect = { 0 };
ULONG HookGetClientRect_ACLEntries[1] = { 0 };
BOOL fake_GetClientRect(HWND hWnd,LPRECT lpRect){
	BOOL ret = pGetClientRect(hWnd,lpRect);
	fprintf(fp,"OUT ['GetClientRect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpRect','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpRect, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'lpRect','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpRect,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *KillTimer_fun) (HWND hWnd,UINT_PTR uIDEvent);
KillTimer_fun pKillTimer = KillTimer;
HOOK_TRACE_INFO hHookKillTimer = { 0 };
ULONG HookKillTimer_ACLEntries[1] = { 0 };
BOOL fake_KillTimer(HWND hWnd,UINT_PTR uIDEvent){
	BOOL ret = pKillTimer(hWnd,uIDEvent);
	fprintf(fp,"OUT ['KillTimer',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsHungAppWindow_fun) (HWND hwnd);
IsHungAppWindow_fun pIsHungAppWindow = IsHungAppWindow;
HOOK_TRACE_INFO hHookIsHungAppWindow = { 0 };
ULONG HookIsHungAppWindow_ACLEntries[1] = { 0 };
BOOL fake_IsHungAppWindow(HWND hwnd){
	BOOL ret = pIsHungAppWindow(hwnd);
	fprintf(fp,"OUT ['IsHungAppWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *HiliteMenuItem_fun) (HWND hWnd,HMENU hMenu,UINT uIDHiliteItem,UINT uHilite);
HiliteMenuItem_fun pHiliteMenuItem = HiliteMenuItem;
HOOK_TRACE_INFO hHookHiliteMenuItem = { 0 };
ULONG HookHiliteMenuItem_ACLEntries[1] = { 0 };
BOOL fake_HiliteMenuItem(HWND hWnd,HMENU hMenu,UINT uIDHiliteItem,UINT uHilite){
	BOOL ret = pHiliteMenuItem(hWnd,hMenu,uIDHiliteItem,uHilite);
	fprintf(fp,"OUT ['HiliteMenuItem',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *PeekMessageA_fun) (LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax,UINT wRemoveMsg);
PeekMessageA_fun pPeekMessageA = PeekMessageA;
HOOK_TRACE_INFO hHookPeekMessageA = { 0 };
ULONG HookPeekMessageA_ACLEntries[1] = { 0 };
BOOL fake_PeekMessageA(LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax,UINT wRemoveMsg){
	BOOL ret = pPeekMessageA(lpMsg,hWnd,wMsgFilterMin,wMsgFilterMax,wRemoveMsg);
	fprintf(fp,"OUT ['PeekMessageA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpMsg','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpMsg, sizeof(LPMSG),1);
 	else fprintf(fp,"{'name':'lpMsg','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpMsg,sizeof(LPMSG));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetDlgItemTextW_fun) (HWND hDlg,int nIDDlgItem,LPCWSTR lpString);
SetDlgItemTextW_fun pSetDlgItemTextW = SetDlgItemTextW;
HOOK_TRACE_INFO hHookSetDlgItemTextW = { 0 };
ULONG HookSetDlgItemTextW_ACLEntries[1] = { 0 };
BOOL fake_SetDlgItemTextW(HWND hDlg,int nIDDlgItem,LPCWSTR lpString){
	BOOL ret = pSetDlgItemTextW(hDlg,nIDDlgItem,lpString);
	fprintf(fp,"OUT ['SetDlgItemTextW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef INT_PTR (WINAPI *DialogBoxIndirectParamW_fun) (HINSTANCE hInstance,LPCDLGTEMPLATEW hDialogTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
DialogBoxIndirectParamW_fun pDialogBoxIndirectParamW = DialogBoxIndirectParamW;
HOOK_TRACE_INFO hHookDialogBoxIndirectParamW = { 0 };
ULONG HookDialogBoxIndirectParamW_ACLEntries[1] = { 0 };
INT_PTR fake_DialogBoxIndirectParamW(HINSTANCE hInstance,LPCDLGTEMPLATEW hDialogTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam){
	INT_PTR ret = pDialogBoxIndirectParamW(hInstance,hDialogTemplate,hWndParent,lpDialogFunc,dwInitParam);
	fprintf(fp,"OUT ['DialogBoxIndirectParamW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(INT_PTR),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(INT_PTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *GetScrollPos_fun) (HWND hWnd,int nBar);
GetScrollPos_fun pGetScrollPos = GetScrollPos;
HOOK_TRACE_INFO hHookGetScrollPos = { 0 };
ULONG HookGetScrollPos_ACLEntries[1] = { 0 };
int fake_GetScrollPos(HWND hWnd,int nBar){
	int ret = pGetScrollPos(hWnd,nBar);
	fprintf(fp,"OUT ['GetScrollPos',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef WORD (WINAPI *SetClassWord_fun) (HWND hWnd,int nIndex,WORD wNewWord);
SetClassWord_fun pSetClassWord = SetClassWord;
HOOK_TRACE_INFO hHookSetClassWord = { 0 };
ULONG HookSetClassWord_ACLEntries[1] = { 0 };
WORD fake_SetClassWord(HWND hWnd,int nIndex,WORD wNewWord){
	WORD ret = pSetClassWord(hWnd,nIndex,wNewWord);
	fprintf(fp,"OUT ['SetClassWord',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%hx,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(WORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%hx, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(WORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *CloseClipboard_fun) ();
CloseClipboard_fun pCloseClipboard = CloseClipboard;
HOOK_TRACE_INFO hHookCloseClipboard = { 0 };
ULONG HookCloseClipboard_ACLEntries[1] = { 0 };
BOOL fake_CloseClipboard(){
	BOOL ret = pCloseClipboard();
	fprintf(fp,"OUT ['CloseClipboard',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *WaitMessage_fun) ();
WaitMessage_fun pWaitMessage = WaitMessage;
HOOK_TRACE_INFO hHookWaitMessage = { 0 };
ULONG HookWaitMessage_ACLEntries[1] = { 0 };
BOOL fake_WaitMessage(){
	BOOL ret = pWaitMessage();
	fprintf(fp,"OUT ['WaitMessage',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HACCEL (WINAPI *LoadAcceleratorsW_fun) (HINSTANCE hInstance,LPCWSTR lpTableName);
LoadAcceleratorsW_fun pLoadAcceleratorsW = LoadAcceleratorsW;
HOOK_TRACE_INFO hHookLoadAcceleratorsW = { 0 };
ULONG HookLoadAcceleratorsW_ACLEntries[1] = { 0 };
HACCEL fake_LoadAcceleratorsW(HINSTANCE hInstance,LPCWSTR lpTableName){
	HACCEL ret = pLoadAcceleratorsW(hInstance,lpTableName);
	fprintf(fp,"OUT ['LoadAcceleratorsW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HACCEL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HACCEL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EnableWindow_fun) (HWND hWnd,BOOL bEnable);
EnableWindow_fun pEnableWindow = EnableWindow;
HOOK_TRACE_INFO hHookEnableWindow = { 0 };
ULONG HookEnableWindow_ACLEntries[1] = { 0 };
BOOL fake_EnableWindow(HWND hWnd,BOOL bEnable){
	BOOL ret = pEnableWindow(hWnd,bEnable);
	fprintf(fp,"OUT ['EnableWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HICON (WINAPI *CreateIconFromResource_fun) (PBYTE presbits,DWORD dwResSize,BOOL fIcon,DWORD dwVer);
CreateIconFromResource_fun pCreateIconFromResource = CreateIconFromResource;
HOOK_TRACE_INFO hHookCreateIconFromResource = { 0 };
ULONG HookCreateIconFromResource_ACLEntries[1] = { 0 };
HICON fake_CreateIconFromResource(PBYTE presbits,DWORD dwResSize,BOOL fIcon,DWORD dwVer){
	HICON ret = pCreateIconFromResource(presbits,dwResSize,fIcon,dwVer);
	fprintf(fp,"OUT ['CreateIconFromResource',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HICON),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HICON));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *DlgDirListComboBoxW_fun) (HWND hDlg,LPWSTR lpPathSpec,int nIDComboBox,int nIDStaticPath,UINT uFiletype);
DlgDirListComboBoxW_fun pDlgDirListComboBoxW = DlgDirListComboBoxW;
HOOK_TRACE_INFO hHookDlgDirListComboBoxW = { 0 };
ULONG HookDlgDirListComboBoxW_ACLEntries[1] = { 0 };
int fake_DlgDirListComboBoxW(HWND hDlg,LPWSTR lpPathSpec,int nIDComboBox,int nIDStaticPath,UINT uFiletype){
	int ret = pDlgDirListComboBoxW(hDlg,lpPathSpec,nIDComboBox,nIDStaticPath,uFiletype);
	fprintf(fp,"OUT ['DlgDirListComboBoxW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'lpPathSpec',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': '\"%s\"',", lpPathSpec);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': '\"%s\"',", lpPathSpec);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),1);
 	}else 
	{
		fprintf(fp,"{'name':'lpPathSpec',");
		fwprintf(fp, L"'value': '\"%s\"', ", lpPathSpec);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsTouchWindow_fun) (HWND hwnd,PULONG pulFlags);
IsTouchWindow_fun pIsTouchWindow = IsTouchWindow;
HOOK_TRACE_INFO hHookIsTouchWindow = { 0 };
ULONG HookIsTouchWindow_ACLEntries[1] = { 0 };
BOOL fake_IsTouchWindow(HWND hwnd,PULONG pulFlags){
	BOOL ret = pIsTouchWindow(hwnd,pulFlags);
	fprintf(fp,"OUT ['IsTouchWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pulFlags','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pulFlags, sizeof(PULONG),1);
 	else fprintf(fp,"{'name':'pulFlags','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pulFlags,sizeof(PULONG));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsChild_fun) (HWND hWndParent,HWND hWnd);
IsChild_fun pIsChild = IsChild;
HOOK_TRACE_INFO hHookIsChild = { 0 };
ULONG HookIsChild_ACLEntries[1] = { 0 };
BOOL fake_IsChild(HWND hWndParent,HWND hWnd){
	BOOL ret = pIsChild(hWndParent,hWnd);
	fprintf(fp,"OUT ['IsChild',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EmptyClipboard_fun) ();
EmptyClipboard_fun pEmptyClipboard = EmptyClipboard;
HOOK_TRACE_INFO hHookEmptyClipboard = { 0 };
ULONG HookEmptyClipboard_ACLEntries[1] = { 0 };
BOOL fake_EmptyClipboard(){
	BOOL ret = pEmptyClipboard();
	fprintf(fp,"OUT ['EmptyClipboard',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetLastInputInfo_fun) (PLASTINPUTINFO plii);
GetLastInputInfo_fun pGetLastInputInfo = GetLastInputInfo;
HOOK_TRACE_INFO hHookGetLastInputInfo = { 0 };
ULONG HookGetLastInputInfo_ACLEntries[1] = { 0 };
BOOL fake_GetLastInputInfo(PLASTINPUTINFO plii){
	BOOL ret = pGetLastInputInfo(plii);
	fprintf(fp,"OUT ['GetLastInputInfo',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'plii','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",plii, sizeof(PLASTINPUTINFO),1);
 	else fprintf(fp,"{'name':'plii','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",plii,sizeof(PLASTINPUTINFO));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *PostMessageA_fun) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
PostMessageA_fun pPostMessageA = PostMessageA;
HOOK_TRACE_INFO hHookPostMessageA = { 0 };
ULONG HookPostMessageA_ACLEntries[1] = { 0 };
BOOL fake_PostMessageA(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam){
	BOOL ret = pPostMessageA(hWnd,Msg,wParam,lParam);
	fprintf(fp,"OUT ['PostMessageA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *DestroyMenu_fun) (HMENU hMenu);
DestroyMenu_fun pDestroyMenu = DestroyMenu;
HOOK_TRACE_INFO hHookDestroyMenu = { 0 };
ULONG HookDestroyMenu_ACLEntries[1] = { 0 };
BOOL fake_DestroyMenu(HMENU hMenu){
	BOOL ret = pDestroyMenu(hMenu);
	fprintf(fp,"OUT ['DestroyMenu',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetIconInfoExA_fun) (HICON hicon,PICONINFOEXA piconinfo);
GetIconInfoExA_fun pGetIconInfoExA = GetIconInfoExA;
HOOK_TRACE_INFO hHookGetIconInfoExA = { 0 };
ULONG HookGetIconInfoExA_ACLEntries[1] = { 0 };
BOOL fake_GetIconInfoExA(HICON hicon,PICONINFOEXA piconinfo){
	BOOL ret = pGetIconInfoExA(hicon,piconinfo);
	fprintf(fp,"OUT ['GetIconInfoExA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'piconinfo','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",piconinfo, sizeof(PICONINFOEXA),1);
 	else fprintf(fp,"{'name':'piconinfo','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",piconinfo,sizeof(PICONINFOEXA));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *CallMsgFilterA_fun) (LPMSG lpMsg,int nCode);
CallMsgFilterA_fun pCallMsgFilterA = CallMsgFilterA;
HOOK_TRACE_INFO hHookCallMsgFilterA = { 0 };
ULONG HookCallMsgFilterA_ACLEntries[1] = { 0 };
BOOL fake_CallMsgFilterA(LPMSG lpMsg,int nCode){
	BOOL ret = pCallMsgFilterA(lpMsg,nCode);
	fprintf(fp,"OUT ['CallMsgFilterA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsDialogMessageA_fun) (HWND hDlg,LPMSG lpMsg);
IsDialogMessageA_fun pIsDialogMessageA = IsDialogMessageA;
HOOK_TRACE_INFO hHookIsDialogMessageA = { 0 };
ULONG HookIsDialogMessageA_ACLEntries[1] = { 0 };
BOOL fake_IsDialogMessageA(HWND hDlg,LPMSG lpMsg){
	BOOL ret = pIsDialogMessageA(hDlg,lpMsg);
	fprintf(fp,"OUT ['IsDialogMessageA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *GetSysColor_fun) (int nIndex);
GetSysColor_fun pGetSysColor = GetSysColor;
HOOK_TRACE_INFO hHookGetSysColor = { 0 };
ULONG HookGetSysColor_ACLEntries[1] = { 0 };
DWORD fake_GetSysColor(int nIndex){
	DWORD ret = pGetSysColor(nIndex);
	fprintf(fp,"OUT ['GetSysColor',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EnumDisplaySettingsW_fun) (LPCWSTR lpszDeviceName,DWORD iModeNum,DEVMODEW*  lpDevMode);
EnumDisplaySettingsW_fun pEnumDisplaySettingsW = EnumDisplaySettingsW;
HOOK_TRACE_INFO hHookEnumDisplaySettingsW = { 0 };
ULONG HookEnumDisplaySettingsW_ACLEntries[1] = { 0 };
BOOL fake_EnumDisplaySettingsW(LPCWSTR lpszDeviceName,DWORD iModeNum,DEVMODEW*  lpDevMode){
	BOOL ret = pEnumDisplaySettingsW(lpszDeviceName,iModeNum, lpDevMode);
	fprintf(fp,"OUT ['EnumDisplaySettingsW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':' lpDevMode','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[", lpDevMode, sizeof(DEVMODEW*),1);
 	else fprintf(fp,"{'name':' lpDevMode','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[", lpDevMode,sizeof(DEVMODEW*));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *InvalidateRect_fun) (HWND hWnd,CONST RECT* lpRect,BOOL bErase);
InvalidateRect_fun pInvalidateRect = InvalidateRect;
HOOK_TRACE_INFO hHookInvalidateRect = { 0 };
ULONG HookInvalidateRect_ACLEntries[1] = { 0 };
BOOL fake_InvalidateRect(HWND hWnd,CONST RECT* lpRect,BOOL bErase){
	BOOL ret = pInvalidateRect(hWnd,lpRect,bErase);
	fprintf(fp,"OUT ['InvalidateRect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *AnyPopup_fun) ();
AnyPopup_fun pAnyPopup = AnyPopup;
HOOK_TRACE_INFO hHookAnyPopup = { 0 };
ULONG HookAnyPopup_ACLEntries[1] = { 0 };
BOOL fake_AnyPopup(){
	BOOL ret = pAnyPopup();
	fprintf(fp,"OUT ['AnyPopup',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef long (WINAPI *BroadcastSystemMessage_fun) (DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam);
BroadcastSystemMessage_fun pBroadcastSystemMessage = BroadcastSystemMessage;
HOOK_TRACE_INFO hHookBroadcastSystemMessage = { 0 };
ULONG HookBroadcastSystemMessage_ACLEntries[1] = { 0 };
long fake_BroadcastSystemMessage(DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam){
	long ret = pBroadcastSystemMessage(flags,lpInfo,Msg,wParam,lParam);
	fprintf(fp,"OUT ['BroadcastSystemMessage',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%llx,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(long),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%llx, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(long));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpInfo','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpInfo, sizeof(LPDWORD),1);
 	else fprintf(fp,"{'name':'lpInfo','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpInfo,sizeof(LPDWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef ULONG_PTR (WINAPI *GetClassLongPtrW_fun) (HWND hWnd,int nIndex);
GetClassLongPtrW_fun pGetClassLongPtrW = GetClassLongPtrW;
HOOK_TRACE_INFO hHookGetClassLongPtrW = { 0 };
ULONG HookGetClassLongPtrW_ACLEntries[1] = { 0 };
ULONG_PTR fake_GetClassLongPtrW(HWND hWnd,int nIndex){
	ULONG_PTR ret = pGetClassLongPtrW(hWnd,nIndex);
	fprintf(fp,"OUT ['GetClassLongPtrW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(ULONG_PTR),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(ULONG_PTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *GetDlgItemTextW_fun) (HWND hDlg,int nIDDlgItem,LPWSTR lpString,int cchMax);
GetDlgItemTextW_fun pGetDlgItemTextW = GetDlgItemTextW;
HOOK_TRACE_INFO hHookGetDlgItemTextW = { 0 };
ULONG HookGetDlgItemTextW_ACLEntries[1] = { 0 };
UINT fake_GetDlgItemTextW(HWND hDlg,int nIDDlgItem,LPWSTR lpString,int cchMax){
	UINT ret = pGetDlgItemTextW(hDlg,nIDDlgItem,lpString,cchMax);
	fprintf(fp,"OUT ['GetDlgItemTextW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'lpString',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': %p,", lpString);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': %p,", lpString);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),cchMax);
 	}else 
	{
		fprintf(fp,"{'name':'lpString',");
		fwprintf(fp, L"'value': %p, ", lpString);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	if(lpString){
		for(int i=0; i<cchMax;i++){
			fprintf(fp,"0x%x,",lpString[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *PrivateExtractIconsW_fun) (LPCWSTR szFileName,int nIconIndex,int cxIcon,int cyIcon,HICON* phicon,UINT* piconid,UINT nIcons,UINT flags);
PrivateExtractIconsW_fun pPrivateExtractIconsW = PrivateExtractIconsW;
HOOK_TRACE_INFO hHookPrivateExtractIconsW = { 0 };
ULONG HookPrivateExtractIconsW_ACLEntries[1] = { 0 };
UINT fake_PrivateExtractIconsW(LPCWSTR szFileName,int nIconIndex,int cxIcon,int cyIcon,HICON* phicon,UINT* piconid,UINT nIcons,UINT flags){
	UINT ret = pPrivateExtractIconsW(szFileName,nIconIndex,cxIcon,cyIcon,phicon,piconid,nIcons,flags);
	fprintf(fp,"OUT ['PrivateExtractIconsW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'phicon','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",phicon, sizeof(HICON*),nIcons, ret);
 	else fprintf(fp,"{'name':'phicon','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",phicon,sizeof(HICON*));
	if(phicon){
		for(int i=0; i<nIcons <  ret ? nIcons :  ret;i++){
			fprintf(fp,"0x%x,",phicon[i]);
		}
	}
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'piconid','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",piconid, sizeof(UINT*),nIcons, ret);
 	else fprintf(fp,"{'name':'piconid','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",piconid,sizeof(UINT*));
	if(piconid){
		for(int i=0; i<nIcons <  ret ? nIcons :  ret;i++){
			fprintf(fp,"0x%x,",piconid[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *UpdateLayeredWindowIndirect_fun) (HWND hWnd,CONST UPDATELAYEREDWINDOWINFO*  pULWInfo);
UpdateLayeredWindowIndirect_fun pUpdateLayeredWindowIndirect = UpdateLayeredWindowIndirect;
HOOK_TRACE_INFO hHookUpdateLayeredWindowIndirect = { 0 };
ULONG HookUpdateLayeredWindowIndirect_ACLEntries[1] = { 0 };
BOOL fake_UpdateLayeredWindowIndirect(HWND hWnd,CONST UPDATELAYEREDWINDOWINFO*  pULWInfo){
	BOOL ret = pUpdateLayeredWindowIndirect(hWnd, pULWInfo);
	fprintf(fp,"OUT ['UpdateLayeredWindowIndirect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetPhysicalCursorPos_fun) (int X,int Y);
SetPhysicalCursorPos_fun pSetPhysicalCursorPos = SetPhysicalCursorPos;
HOOK_TRACE_INFO hHookSetPhysicalCursorPos = { 0 };
ULONG HookSetPhysicalCursorPos_ACLEntries[1] = { 0 };
BOOL fake_SetPhysicalCursorPos(int X,int Y){
	BOOL ret = pSetPhysicalCursorPos(X,Y);
	fprintf(fp,"OUT ['SetPhysicalCursorPos',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetLayeredWindowAttributes_fun) (HWND hwnd,COLORREF crKey,BYTE bAlpha,DWORD dwFlags);
SetLayeredWindowAttributes_fun pSetLayeredWindowAttributes = SetLayeredWindowAttributes;
HOOK_TRACE_INFO hHookSetLayeredWindowAttributes = { 0 };
ULONG HookSetLayeredWindowAttributes_ACLEntries[1] = { 0 };
BOOL fake_SetLayeredWindowAttributes(HWND hwnd,COLORREF crKey,BYTE bAlpha,DWORD dwFlags){
	BOOL ret = pSetLayeredWindowAttributes(hwnd,crKey,bAlpha,dwFlags);
	fprintf(fp,"OUT ['SetLayeredWindowAttributes',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef WORD (WINAPI *SetWindowWord_fun) (HWND hWnd,int nIndex,WORD wNewWord);
SetWindowWord_fun pSetWindowWord = SetWindowWord;
HOOK_TRACE_INFO hHookSetWindowWord = { 0 };
ULONG HookSetWindowWord_ACLEntries[1] = { 0 };
WORD fake_SetWindowWord(HWND hWnd,int nIndex,WORD wNewWord){
	WORD ret = pSetWindowWord(hWnd,nIndex,wNewWord);
	fprintf(fp,"OUT ['SetWindowWord',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%hx,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(WORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%hx, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(WORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *DeregisterShellHookWindow_fun) (HWND hwnd);
DeregisterShellHookWindow_fun pDeregisterShellHookWindow = DeregisterShellHookWindow;
HOOK_TRACE_INFO hHookDeregisterShellHookWindow = { 0 };
ULONG HookDeregisterShellHookWindow_ACLEntries[1] = { 0 };
BOOL fake_DeregisterShellHookWindow(HWND hwnd){
	BOOL ret = pDeregisterShellHookWindow(hwnd);
	fprintf(fp,"OUT ['DeregisterShellHookWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HACCEL (WINAPI *LoadAcceleratorsA_fun) (HINSTANCE hInstance,LPCSTR lpTableName);
LoadAcceleratorsA_fun pLoadAcceleratorsA = LoadAcceleratorsA;
HOOK_TRACE_INFO hHookLoadAcceleratorsA = { 0 };
ULONG HookLoadAcceleratorsA_ACLEntries[1] = { 0 };
HACCEL fake_LoadAcceleratorsA(HINSTANCE hInstance,LPCSTR lpTableName){
	HACCEL ret = pLoadAcceleratorsA(hInstance,lpTableName);
	fprintf(fp,"OUT ['LoadAcceleratorsA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HACCEL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HACCEL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *DragObject_fun) (HWND hwndParent,HWND hwndFrom,UINT fmt,ULONG_PTR data,HCURSOR hcur);
DragObject_fun pDragObject = DragObject;
HOOK_TRACE_INFO hHookDragObject = { 0 };
ULONG HookDragObject_ACLEntries[1] = { 0 };
DWORD fake_DragObject(HWND hwndParent,HWND hwndFrom,UINT fmt,ULONG_PTR data,HCURSOR hcur){
	DWORD ret = pDragObject(hwndParent,hwndFrom,fmt,data,hcur);
	fprintf(fp,"OUT ['DragObject',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HANDLE (WINAPI *RemovePropW_fun) (HWND hWnd,LPCWSTR lpString);
RemovePropW_fun pRemovePropW = RemovePropW;
HOOK_TRACE_INFO hHookRemovePropW = { 0 };
ULONG HookRemovePropW_ACLEntries[1] = { 0 };
HANDLE fake_RemovePropW(HWND hWnd,LPCWSTR lpString){
	HANDLE ret = pRemovePropW(hWnd,lpString);
	fprintf(fp,"OUT ['RemovePropW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HANDLE),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HANDLE));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsCharUpperA_fun) (CHAR ch);
IsCharUpperA_fun pIsCharUpperA = IsCharUpperA;
HOOK_TRACE_INFO hHookIsCharUpperA = { 0 };
ULONG HookIsCharUpperA_ACLEntries[1] = { 0 };
BOOL fake_IsCharUpperA(CHAR ch){
	BOOL ret = pIsCharUpperA(ch);
	fprintf(fp,"OUT ['IsCharUpperA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *DlgDirSelectExA_fun) (HWND hwndDlg,LPSTR lpString,int chCount,int idListBox);
DlgDirSelectExA_fun pDlgDirSelectExA = DlgDirSelectExA;
HOOK_TRACE_INFO hHookDlgDirSelectExA = { 0 };
ULONG HookDlgDirSelectExA_ACLEntries[1] = { 0 };
BOOL fake_DlgDirSelectExA(HWND hwndDlg,LPSTR lpString,int chCount,int idListBox){
	BOOL ret = pDlgDirSelectExA(hwndDlg,lpString,chCount,idListBox);
	fprintf(fp,"OUT ['DlgDirSelectExA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpString','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpString, sizeof(LPSTR),chCount);
 	else fprintf(fp,"{'name':'lpString','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpString,sizeof(LPSTR));
	if(lpString){
		for(int i=0; i<chCount;i++){
			fprintf(fp,"0x%x,",lpString[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *CloseTouchInputHandle_fun) (HTOUCHINPUT hTouchInput);
CloseTouchInputHandle_fun pCloseTouchInputHandle = CloseTouchInputHandle;
HOOK_TRACE_INFO hHookCloseTouchInputHandle = { 0 };
ULONG HookCloseTouchInputHandle_ACLEntries[1] = { 0 };
BOOL fake_CloseTouchInputHandle(HTOUCHINPUT hTouchInput){
	BOOL ret = pCloseTouchInputHandle(hTouchInput);
	fprintf(fp,"OUT ['CloseTouchInputHandle',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LONG (WINAPI *ChangeDisplaySettingsA_fun) (DEVMODEA*  lpDevMode,DWORD dwFlags);
ChangeDisplaySettingsA_fun pChangeDisplaySettingsA = ChangeDisplaySettingsA;
HOOK_TRACE_INFO hHookChangeDisplaySettingsA = { 0 };
ULONG HookChangeDisplaySettingsA_ACLEntries[1] = { 0 };
LONG fake_ChangeDisplaySettingsA(DEVMODEA*  lpDevMode,DWORD dwFlags){
	LONG ret = pChangeDisplaySettingsA( lpDevMode,dwFlags);
	fprintf(fp,"OUT ['ChangeDisplaySettingsA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LONG),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LONG));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ScreenToClient_fun) (HWND hWnd,LPPOINT lpPoint);
ScreenToClient_fun pScreenToClient = ScreenToClient;
HOOK_TRACE_INFO hHookScreenToClient = { 0 };
ULONG HookScreenToClient_ACLEntries[1] = { 0 };
BOOL fake_ScreenToClient(HWND hWnd,LPPOINT lpPoint){
	BOOL ret = pScreenToClient(hWnd,lpPoint);
	fprintf(fp,"OUT ['ScreenToClient',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpPoint','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpPoint, sizeof(LPPOINT),1);
 	else fprintf(fp,"{'name':'lpPoint','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpPoint,sizeof(LPPOINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ModifyMenuW_fun) (HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCWSTR lpNewItem);
ModifyMenuW_fun pModifyMenuW = ModifyMenuW;
HOOK_TRACE_INFO hHookModifyMenuW = { 0 };
ULONG HookModifyMenuW_ACLEntries[1] = { 0 };
BOOL fake_ModifyMenuW(HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCWSTR lpNewItem){
	BOOL ret = pModifyMenuW(hMnu,uPosition,uFlags,uIDNewItem,lpNewItem);
	fprintf(fp,"OUT ['ModifyMenuW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *MessageBoxExW_fun) (HWND hWnd,LPCWSTR lpText,LPCWSTR lpCaption,UINT uType,WORD wLanguageId);
MessageBoxExW_fun pMessageBoxExW = MessageBoxExW;
HOOK_TRACE_INFO hHookMessageBoxExW = { 0 };
ULONG HookMessageBoxExW_ACLEntries[1] = { 0 };
int fake_MessageBoxExW(HWND hWnd,LPCWSTR lpText,LPCWSTR lpCaption,UINT uType,WORD wLanguageId){
	int ret = pMessageBoxExW(hWnd,lpText,lpCaption,uType,wLanguageId);
	fprintf(fp,"OUT ['MessageBoxExW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef VOID (WINAPI *keybd_event_fun) (BYTE bVk,BYTE bScan,DWORD dwFlags,ULONG_PTR dwExtraInfo);
keybd_event_fun pkeybd_event = keybd_event;
HOOK_TRACE_INFO hHookkeybd_event = { 0 };
ULONG Hookkeybd_event_ACLEntries[1] = { 0 };
VOID fake_keybd_event(BYTE bVk,BYTE bScan,DWORD dwFlags,ULONG_PTR dwExtraInfo){
	pkeybd_event(bVk,bScan,dwFlags,dwExtraInfo);
	fprintf(fp,"OUT ['keybd_event',");
	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
}


typedef BOOL (WINAPI *LockSetForegroundWindow_fun) (UINT uLockCode);
LockSetForegroundWindow_fun pLockSetForegroundWindow = LockSetForegroundWindow;
HOOK_TRACE_INFO hHookLockSetForegroundWindow = { 0 };
ULONG HookLockSetForegroundWindow_ACLEntries[1] = { 0 };
BOOL fake_LockSetForegroundWindow(UINT uLockCode){
	BOOL ret = pLockSetForegroundWindow(uLockCode);
	fprintf(fp,"OUT ['LockSetForegroundWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LONG (WINAPI *GetMenuCheckMarkDimensions_fun) ();
GetMenuCheckMarkDimensions_fun pGetMenuCheckMarkDimensions = GetMenuCheckMarkDimensions;
HOOK_TRACE_INFO hHookGetMenuCheckMarkDimensions = { 0 };
ULONG HookGetMenuCheckMarkDimensions_ACLEntries[1] = { 0 };
LONG fake_GetMenuCheckMarkDimensions(){
	LONG ret = pGetMenuCheckMarkDimensions();
	fprintf(fp,"OUT ['GetMenuCheckMarkDimensions',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LONG),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LONG));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *SetClassLongW_fun) (HWND hWnd,int nIndex,LONG dwNewLong);
SetClassLongW_fun pSetClassLongW = SetClassLongW;
HOOK_TRACE_INFO hHookSetClassLongW = { 0 };
ULONG HookSetClassLongW_ACLEntries[1] = { 0 };
DWORD fake_SetClassLongW(HWND hWnd,int nIndex,LONG dwNewLong){
	DWORD ret = pSetClassLongW(hWnd,nIndex,dwNewLong);
	fprintf(fp,"OUT ['SetClassLongW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LPWSTR (WINAPI *CharNextW_fun) (LPCWSTR lpsz);
CharNextW_fun pCharNextW = CharNextW;
HOOK_TRACE_INFO hHookCharNextW = { 0 };
ULONG HookCharNextW_ACLEntries[1] = { 0 };
LPWSTR fake_CharNextW(LPCWSTR lpsz){
	LPWSTR ret = pCharNextW(lpsz);
	fprintf(fp,"OUT ['CharNextW',");
	if(1)
	{
		fprintf(fp,"{'name':'ret',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': '\"%s\"',", ret);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': '\"%s\"',", ret);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),1);
 	}else 
	{
		fprintf(fp,"{'name':'ret',");
		fwprintf(fp, L"'value': '\"%s\"', ", ret);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *LogicalToPhysicalPoint_fun) (HWND hWnd,LPPOINT lpPoint);
LogicalToPhysicalPoint_fun pLogicalToPhysicalPoint = LogicalToPhysicalPoint;
HOOK_TRACE_INFO hHookLogicalToPhysicalPoint = { 0 };
ULONG HookLogicalToPhysicalPoint_ACLEntries[1] = { 0 };
BOOL fake_LogicalToPhysicalPoint(HWND hWnd,LPPOINT lpPoint){
	BOOL ret = pLogicalToPhysicalPoint(hWnd,lpPoint);
	fprintf(fp,"OUT ['LogicalToPhysicalPoint',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpPoint','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpPoint, sizeof(LPPOINT),1);
 	else fprintf(fp,"{'name':'lpPoint','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpPoint,sizeof(LPPOINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HCURSOR (WINAPI *LoadCursorW_fun) (HINSTANCE hInstance,LPCWSTR lpCursorName);
LoadCursorW_fun pLoadCursorW = LoadCursorW;
HOOK_TRACE_INFO hHookLoadCursorW = { 0 };
ULONG HookLoadCursorW_ACLEntries[1] = { 0 };
HCURSOR fake_LoadCursorW(HINSTANCE hInstance,LPCWSTR lpCursorName){
	HCURSOR ret = pLoadCursorW(hInstance,lpCursorName);
	fprintf(fp,"OUT ['LoadCursorW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HCURSOR),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HCURSOR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *GetClassLongW_fun) (HWND hWnd,int nIndex);
GetClassLongW_fun pGetClassLongW = GetClassLongW;
HOOK_TRACE_INFO hHookGetClassLongW = { 0 };
ULONG HookGetClassLongW_ACLEntries[1] = { 0 };
DWORD fake_GetClassLongW(HWND hWnd,int nIndex){
	DWORD ret = pGetClassLongW(hWnd,nIndex);
	fprintf(fp,"OUT ['GetClassLongW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EnumDesktopWindows_fun) (HDESK hDesktop,WNDENUMPROC lpfn,LPARAM lParam);
EnumDesktopWindows_fun pEnumDesktopWindows = EnumDesktopWindows;
HOOK_TRACE_INFO hHookEnumDesktopWindows = { 0 };
ULONG HookEnumDesktopWindows_ACLEntries[1] = { 0 };
BOOL fake_EnumDesktopWindows(HDESK hDesktop,WNDENUMPROC lpfn,LPARAM lParam){
	BOOL ret = pEnumDesktopWindows(hDesktop,lpfn,lParam);
	fprintf(fp,"OUT ['EnumDesktopWindows',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LRESULT (WINAPI *DefWindowProcW_fun) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
DefWindowProcW_fun pDefWindowProcW = DefWindowProcW;
HOOK_TRACE_INFO hHookDefWindowProcW = { 0 };
ULONG HookDefWindowProcW_ACLEntries[1] = { 0 };
LRESULT fake_DefWindowProcW(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pDefWindowProcW(hWnd,Msg,wParam,lParam);
	fprintf(fp,"OUT ['DefWindowProcW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LRESULT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LRESULT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *UnregisterDeviceNotification_fun) (HDEVNOTIFY handle);
UnregisterDeviceNotification_fun pUnregisterDeviceNotification = UnregisterDeviceNotification;
HOOK_TRACE_INFO hHookUnregisterDeviceNotification = { 0 };
ULONG HookUnregisterDeviceNotification_ACLEntries[1] = { 0 };
BOOL fake_UnregisterDeviceNotification(HDEVNOTIFY handle){
	BOOL ret = pUnregisterDeviceNotification(handle);
	fprintf(fp,"OUT ['UnregisterDeviceNotification',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *DlgDirSelectExW_fun) (HWND hwndDlg,LPWSTR lpString,int chCount,int idListBox);
DlgDirSelectExW_fun pDlgDirSelectExW = DlgDirSelectExW;
HOOK_TRACE_INFO hHookDlgDirSelectExW = { 0 };
ULONG HookDlgDirSelectExW_ACLEntries[1] = { 0 };
BOOL fake_DlgDirSelectExW(HWND hwndDlg,LPWSTR lpString,int chCount,int idListBox){
	BOOL ret = pDlgDirSelectExW(hwndDlg,lpString,chCount,idListBox);
	fprintf(fp,"OUT ['DlgDirSelectExW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'lpString',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': %p,", lpString);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': %p,", lpString);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),chCount);
 	}else 
	{
		fprintf(fp,"{'name':'lpString',");
		fwprintf(fp, L"'value': %p, ", lpString);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	if(lpString){
		for(int i=0; i<chCount;i++){
			fprintf(fp,"0x%x,",lpString[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetGUIThreadInfo_fun) (DWORD idThread,PGUITHREADINFO pgui);
GetGUIThreadInfo_fun pGetGUIThreadInfo = GetGUIThreadInfo;
HOOK_TRACE_INFO hHookGetGUIThreadInfo = { 0 };
ULONG HookGetGUIThreadInfo_ACLEntries[1] = { 0 };
BOOL fake_GetGUIThreadInfo(DWORD idThread,PGUITHREADINFO pgui){
	BOOL ret = pGetGUIThreadInfo(idThread,pgui);
	fprintf(fp,"OUT ['GetGUIThreadInfo',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pgui','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pgui, sizeof(PGUITHREADINFO),1);
 	else fprintf(fp,"{'name':'pgui','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pgui,sizeof(PGUITHREADINFO));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HANDLE (WINAPI *CopyImage_fun) (HANDLE h,UINT type,int cx,int cy,UINT flags);
CopyImage_fun pCopyImage = CopyImage;
HOOK_TRACE_INFO hHookCopyImage = { 0 };
ULONG HookCopyImage_ACLEntries[1] = { 0 };
HANDLE fake_CopyImage(HANDLE h,UINT type,int cx,int cy,UINT flags){
	HANDLE ret = pCopyImage(h,type,cx,cy,flags);
	fprintf(fp,"OUT ['CopyImage',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HANDLE),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HANDLE));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *RealGetWindowClassW_fun) (HWND hwnd,LPWSTR ptszClassName,UINT cchClassNameMax);
RealGetWindowClassW_fun pRealGetWindowClassW = RealGetWindowClassW;
HOOK_TRACE_INFO hHookRealGetWindowClassW = { 0 };
ULONG HookRealGetWindowClassW_ACLEntries[1] = { 0 };
UINT fake_RealGetWindowClassW(HWND hwnd,LPWSTR ptszClassName,UINT cchClassNameMax){
	UINT ret = pRealGetWindowClassW(hwnd,ptszClassName,cchClassNameMax);
	fprintf(fp,"OUT ['RealGetWindowClassW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'ptszClassName',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': %p,", ptszClassName);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': %p,", ptszClassName);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),cchClassNameMax, ret);
 	}else 
	{
		fprintf(fp,"{'name':'ptszClassName',");
		fwprintf(fp, L"'value': %p, ", ptszClassName);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	if(ptszClassName){
		for(int i=0; i<cchClassNameMax <  ret ? cchClassNameMax :  ret;i++){
			fprintf(fp,"0x%x,",ptszClassName[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetWindowPlacement_fun) (HWND hWnd,WINDOWPLACEMENT* lpwndpl);
GetWindowPlacement_fun pGetWindowPlacement = GetWindowPlacement;
HOOK_TRACE_INFO hHookGetWindowPlacement = { 0 };
ULONG HookGetWindowPlacement_ACLEntries[1] = { 0 };
BOOL fake_GetWindowPlacement(HWND hWnd,WINDOWPLACEMENT* lpwndpl){
	BOOL ret = pGetWindowPlacement(hWnd,lpwndpl);
	fprintf(fp,"OUT ['GetWindowPlacement',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpwndpl','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpwndpl, sizeof(WINDOWPLACEMENT*),1);
 	else fprintf(fp,"{'name':'lpwndpl','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpwndpl,sizeof(WINDOWPLACEMENT*));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *FindWindowExW_fun) (HWND hWndParent,HWND hWndChildAfter,LPCWSTR lpszClass,LPCWSTR lpszWindow);
FindWindowExW_fun pFindWindowExW = FindWindowExW;
HOOK_TRACE_INFO hHookFindWindowExW = { 0 };
ULONG HookFindWindowExW_ACLEntries[1] = { 0 };
HWND fake_FindWindowExW(HWND hWndParent,HWND hWndChildAfter,LPCWSTR lpszClass,LPCWSTR lpszWindow){
	HWND ret = pFindWindowExW(hWndParent,hWndChildAfter,lpszClass,lpszWindow);
	fprintf(fp,"OUT ['FindWindowExW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *SetScrollPos_fun) (HWND hWnd,int nBar,int nPos,BOOL bRedraw);
SetScrollPos_fun pSetScrollPos = SetScrollPos;
HOOK_TRACE_INFO hHookSetScrollPos = { 0 };
ULONG HookSetScrollPos_ACLEntries[1] = { 0 };
int fake_SetScrollPos(HWND hWnd,int nBar,int nPos,BOOL bRedraw){
	int ret = pSetScrollPos(hWnd,nBar,nPos,bRedraw);
	fprintf(fp,"OUT ['SetScrollPos',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *TrackPopupMenu_fun) (HMENU hMenu,UINT uFlags,int x,int y,int nReserved,HWND hWnd,CONST RECT* prcRect);
TrackPopupMenu_fun pTrackPopupMenu = TrackPopupMenu;
HOOK_TRACE_INFO hHookTrackPopupMenu = { 0 };
ULONG HookTrackPopupMenu_ACLEntries[1] = { 0 };
BOOL fake_TrackPopupMenu(HMENU hMenu,UINT uFlags,int x,int y,int nReserved,HWND hWnd,CONST RECT* prcRect){
	BOOL ret = pTrackPopupMenu(hMenu,uFlags,x,y,nReserved,hWnd,prcRect);
	fprintf(fp,"OUT ['TrackPopupMenu',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *CharToOemA_fun) (LPCSTR pSrc,LPSTR pDst);
CharToOemA_fun pCharToOemA = CharToOemA;
HOOK_TRACE_INFO hHookCharToOemA = { 0 };
ULONG HookCharToOemA_ACLEntries[1] = { 0 };
BOOL fake_CharToOemA(LPCSTR pSrc,LPSTR pDst){
	BOOL ret = pCharToOemA(pSrc,pDst);
	fprintf(fp,"OUT ['CharToOemA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pDst','value': '\"%s\"','size' : 0x%lx,'cnt':0x%x, 'data':[",pDst, sizeof(LPSTR),1);
 	else fprintf(fp,"{'name':'pDst','value': '\"%s\"', 'size' : 0x%lx,'cnt':'undefined', 'data':[",pDst,sizeof(LPSTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *GetDlgItemInt_fun) (HWND hDlg,int nIDDlgItem,BOOL* lpTranslated,BOOL bSigned);
GetDlgItemInt_fun pGetDlgItemInt = GetDlgItemInt;
HOOK_TRACE_INFO hHookGetDlgItemInt = { 0 };
ULONG HookGetDlgItemInt_ACLEntries[1] = { 0 };
UINT fake_GetDlgItemInt(HWND hDlg,int nIDDlgItem,BOOL* lpTranslated,BOOL bSigned){
	UINT ret = pGetDlgItemInt(hDlg,nIDDlgItem,lpTranslated,bSigned);
	fprintf(fp,"OUT ['GetDlgItemInt',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpTranslated','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpTranslated, sizeof(BOOL*),1);
 	else fprintf(fp,"{'name':'lpTranslated','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpTranslated,sizeof(BOOL*));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HMENU (WINAPI *CreateMenu_fun) ();
CreateMenu_fun pCreateMenu = CreateMenu;
HOOK_TRACE_INFO hHookCreateMenu = { 0 };
ULONG HookCreateMenu_ACLEntries[1] = { 0 };
HMENU fake_CreateMenu(){
	HMENU ret = pCreateMenu();
	fprintf(fp,"OUT ['CreateMenu',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HMENU),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HMENU));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ChangeMenuA_fun) (HMENU hMenu,UINT cmd,LPCSTR lpszNewItem,UINT cmdInsert,UINT flags);
ChangeMenuA_fun pChangeMenuA = ChangeMenuA;
HOOK_TRACE_INFO hHookChangeMenuA = { 0 };
ULONG HookChangeMenuA_ACLEntries[1] = { 0 };
BOOL fake_ChangeMenuA(HMENU hMenu,UINT cmd,LPCSTR lpszNewItem,UINT cmdInsert,UINT flags){
	BOOL ret = pChangeMenuA(hMenu,cmd,lpszNewItem,cmdInsert,flags);
	fprintf(fp,"OUT ['ChangeMenuA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HDESK (WINAPI *CreateDesktopExW_fun) (LPCWSTR lpszDesktop,LPCWSTR lpszDevice,DEVMODEW*  pDevmode,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa,ULONG ulHeapSize,PVOID pvoid);
CreateDesktopExW_fun pCreateDesktopExW = CreateDesktopExW;
HOOK_TRACE_INFO hHookCreateDesktopExW = { 0 };
ULONG HookCreateDesktopExW_ACLEntries[1] = { 0 };
HDESK fake_CreateDesktopExW(LPCWSTR lpszDesktop,LPCWSTR lpszDevice,DEVMODEW*  pDevmode,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa,ULONG ulHeapSize,PVOID pvoid){
	HDESK ret = pCreateDesktopExW(lpszDesktop,lpszDevice, pDevmode,dwFlags,dwDesiredAccess,lpsa,ulHeapSize,pvoid);
	fprintf(fp,"OUT ['CreateDesktopExW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HDESK),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HDESK));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef INT_PTR (WINAPI *DialogBoxParamA_fun) (HINSTANCE hInstance,LPCSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
DialogBoxParamA_fun pDialogBoxParamA = DialogBoxParamA;
HOOK_TRACE_INFO hHookDialogBoxParamA = { 0 };
ULONG HookDialogBoxParamA_ACLEntries[1] = { 0 };
INT_PTR fake_DialogBoxParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam){
	INT_PTR ret = pDialogBoxParamA(hInstance,lpTemplateName,hWndParent,lpDialogFunc,dwInitParam);
	fprintf(fp,"OUT ['DialogBoxParamA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(INT_PTR),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(INT_PTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetProcessDefaultLayout_fun) (DWORD* pdwDefaultLayout);
GetProcessDefaultLayout_fun pGetProcessDefaultLayout = GetProcessDefaultLayout;
HOOK_TRACE_INFO hHookGetProcessDefaultLayout = { 0 };
ULONG HookGetProcessDefaultLayout_ACLEntries[1] = { 0 };
BOOL fake_GetProcessDefaultLayout(DWORD* pdwDefaultLayout){
	BOOL ret = pGetProcessDefaultLayout(pdwDefaultLayout);
	fprintf(fp,"OUT ['GetProcessDefaultLayout',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pdwDefaultLayout','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pdwDefaultLayout, sizeof(DWORD*),1);
 	else fprintf(fp,"{'name':'pdwDefaultLayout','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pdwDefaultLayout,sizeof(DWORD*));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HANDLE (WINAPI *GetPropA_fun) (HWND hWnd,LPCSTR lpString);
GetPropA_fun pGetPropA = GetPropA;
HOOK_TRACE_INFO hHookGetPropA = { 0 };
ULONG HookGetPropA_ACLEntries[1] = { 0 };
HANDLE fake_GetPropA(HWND hWnd,LPCSTR lpString){
	HANDLE ret = pGetPropA(hWnd,lpString);
	fprintf(fp,"OUT ['GetPropA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HANDLE),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HANDLE));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetMenuInfo_fun) (HMENU arg0,LPMENUINFO arg1);
GetMenuInfo_fun pGetMenuInfo = GetMenuInfo;
HOOK_TRACE_INFO hHookGetMenuInfo = { 0 };
ULONG HookGetMenuInfo_ACLEntries[1] = { 0 };
BOOL fake_GetMenuInfo(HMENU arg0,LPMENUINFO arg1){
	BOOL ret = pGetMenuInfo(arg0,arg1);
	fprintf(fp,"OUT ['GetMenuInfo',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'arg1','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",arg1, sizeof(LPMENUINFO),1);
 	else fprintf(fp,"{'name':'arg1','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",arg1,sizeof(LPMENUINFO));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *PtInRect_fun) (CONST RECT* lprc,POINT pt);
PtInRect_fun pPtInRect = PtInRect;
HOOK_TRACE_INFO hHookPtInRect = { 0 };
ULONG HookPtInRect_ACLEntries[1] = { 0 };
BOOL fake_PtInRect(CONST RECT* lprc,POINT pt){
	BOOL ret = pPtInRect(lprc,pt);
	fprintf(fp,"OUT ['PtInRect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *CopyAcceleratorTableW_fun) (HACCEL hAccelSrc,LPACCEL lpAccelDst,int cAccelEntries);
CopyAcceleratorTableW_fun pCopyAcceleratorTableW = CopyAcceleratorTableW;
HOOK_TRACE_INFO hHookCopyAcceleratorTableW = { 0 };
ULONG HookCopyAcceleratorTableW_ACLEntries[1] = { 0 };
int fake_CopyAcceleratorTableW(HACCEL hAccelSrc,LPACCEL lpAccelDst,int cAccelEntries){
	int ret = pCopyAcceleratorTableW(hAccelSrc,lpAccelDst,cAccelEntries);
	fprintf(fp,"OUT ['CopyAcceleratorTableW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpAccelDst','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpAccelDst, sizeof(LPACCEL),cAccelEntries, ret);
 	else fprintf(fp,"{'name':'lpAccelDst','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpAccelDst,sizeof(LPACCEL));
	if(lpAccelDst){
		for(int i=0; i<cAccelEntries <  ret ? cAccelEntries :  ret;i++){
			fprintf(fp,"0x%x,",lpAccelDst[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *OemToCharBuffW_fun) (LPCSTR lpszSrc,LPWSTR lpszDst,DWORD cchDstLength);
OemToCharBuffW_fun pOemToCharBuffW = OemToCharBuffW;
HOOK_TRACE_INFO hHookOemToCharBuffW = { 0 };
ULONG HookOemToCharBuffW_ACLEntries[1] = { 0 };
BOOL fake_OemToCharBuffW(LPCSTR lpszSrc,LPWSTR lpszDst,DWORD cchDstLength){
	BOOL ret = pOemToCharBuffW(lpszSrc,lpszDst,cchDstLength);
	fprintf(fp,"OUT ['OemToCharBuffW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'lpszDst',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': %p,", lpszDst);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': %p,", lpszDst);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),cchDstLength);
 	}else 
	{
		fprintf(fp,"{'name':'lpszDst',");
		fwprintf(fp, L"'value': %p, ", lpszDst);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	if(lpszDst){
		for(int i=0; i<cchDstLength;i++){
			fprintf(fp,"0x%x,",lpszDst[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *LookupIconIdFromDirectoryEx_fun) (PBYTE presbits,BOOL fIcon,int cxDesired,int cyDesired,UINT Flags);
LookupIconIdFromDirectoryEx_fun pLookupIconIdFromDirectoryEx = LookupIconIdFromDirectoryEx;
HOOK_TRACE_INFO hHookLookupIconIdFromDirectoryEx = { 0 };
ULONG HookLookupIconIdFromDirectoryEx_ACLEntries[1] = { 0 };
int fake_LookupIconIdFromDirectoryEx(PBYTE presbits,BOOL fIcon,int cxDesired,int cyDesired,UINT Flags){
	int ret = pLookupIconIdFromDirectoryEx(presbits,fIcon,cxDesired,cyDesired,Flags);
	fprintf(fp,"OUT ['LookupIconIdFromDirectoryEx',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *WinHelpW_fun) (HWND hWndMain,LPCWSTR lpszHelp,UINT uCommand,ULONG_PTR dwData);
WinHelpW_fun pWinHelpW = WinHelpW;
HOOK_TRACE_INFO hHookWinHelpW = { 0 };
ULONG HookWinHelpW_ACLEntries[1] = { 0 };
BOOL fake_WinHelpW(HWND hWndMain,LPCWSTR lpszHelp,UINT uCommand,ULONG_PTR dwData){
	BOOL ret = pWinHelpW(hWndMain,lpszHelp,uCommand,dwData);
	fprintf(fp,"OUT ['WinHelpW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LONG_PTR (WINAPI *SetWindowLongPtrA_fun) (HWND hWnd,int nIndex,LONG_PTR dwNewLong);
SetWindowLongPtrA_fun pSetWindowLongPtrA = SetWindowLongPtrA;
HOOK_TRACE_INFO hHookSetWindowLongPtrA = { 0 };
ULONG HookSetWindowLongPtrA_ACLEntries[1] = { 0 };
LONG_PTR fake_SetWindowLongPtrA(HWND hWnd,int nIndex,LONG_PTR dwNewLong){
	LONG_PTR ret = pSetWindowLongPtrA(hWnd,nIndex,dwNewLong);
	fprintf(fp,"OUT ['SetWindowLongPtrA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LONG_PTR),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LONG_PTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *CharToOemW_fun) (LPCWSTR pSrc,LPSTR pDst);
CharToOemW_fun pCharToOemW = CharToOemW;
HOOK_TRACE_INFO hHookCharToOemW = { 0 };
ULONG HookCharToOemW_ACLEntries[1] = { 0 };
BOOL fake_CharToOemW(LPCWSTR pSrc,LPSTR pDst){
	BOOL ret = pCharToOemW(pSrc,pDst);
	fprintf(fp,"OUT ['CharToOemW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pDst','value': '\"%s\"','size' : 0x%lx,'cnt':0x%x, 'data':[",pDst, sizeof(LPSTR),1);
 	else fprintf(fp,"{'name':'pDst','value': '\"%s\"', 'size' : 0x%lx,'cnt':'undefined', 'data':[",pDst,sizeof(LPSTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *CreateWindowExA_fun) (DWORD dwExStyle,LPCSTR lpClassName,LPCSTR lpWindowName,DWORD dwStyle,int X,int Y,int nWidth,int nHeight,HWND hWndParent,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
CreateWindowExA_fun pCreateWindowExA = CreateWindowExA;
HOOK_TRACE_INFO hHookCreateWindowExA = { 0 };
ULONG HookCreateWindowExA_ACLEntries[1] = { 0 };
HWND fake_CreateWindowExA(DWORD dwExStyle,LPCSTR lpClassName,LPCSTR lpWindowName,DWORD dwStyle,int X,int Y,int nWidth,int nHeight,HWND hWndParent,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam){
	HWND ret = pCreateWindowExA(dwExStyle,lpClassName,lpWindowName,dwStyle,X,Y,nWidth,nHeight,hWndParent,hMenu,hInstance,lpParam);
	fprintf(fp,"OUT ['CreateWindowExA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LPSTR (WINAPI *CharPrevExA_fun) (WORD CodePage,LPCSTR lpStart,LPCSTR lpCurrentChar,DWORD dwFlags);
CharPrevExA_fun pCharPrevExA = CharPrevExA;
HOOK_TRACE_INFO hHookCharPrevExA = { 0 };
ULONG HookCharPrevExA_ACLEntries[1] = { 0 };
LPSTR fake_CharPrevExA(WORD CodePage,LPCSTR lpStart,LPCSTR lpCurrentChar,DWORD dwFlags){
	LPSTR ret = pCharPrevExA(CodePage,lpStart,lpCurrentChar,dwFlags);
	fprintf(fp,"OUT ['CharPrevExA',");
	if(1) fprintf(fp,"{'name':'ret','value': '\"%s\"','size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LPSTR),1);
 	else fprintf(fp,"{'name':'ret','value': '\"%s\"', 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LPSTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HANDLE (WINAPI *GetPropW_fun) (HWND hWnd,LPCWSTR lpString);
GetPropW_fun pGetPropW = GetPropW;
HOOK_TRACE_INFO hHookGetPropW = { 0 };
ULONG HookGetPropW_ACLEntries[1] = { 0 };
HANDLE fake_GetPropW(HWND hWnd,LPCWSTR lpString){
	HANDLE ret = pGetPropW(hWnd,lpString);
	fprintf(fp,"OUT ['GetPropW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HANDLE),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HANDLE));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *GetWindowModuleFileNameW_fun) (HWND hwnd,LPWSTR pszFileName,UINT cchFileNameMax);
GetWindowModuleFileNameW_fun pGetWindowModuleFileNameW = GetWindowModuleFileNameW;
HOOK_TRACE_INFO hHookGetWindowModuleFileNameW = { 0 };
ULONG HookGetWindowModuleFileNameW_ACLEntries[1] = { 0 };
UINT fake_GetWindowModuleFileNameW(HWND hwnd,LPWSTR pszFileName,UINT cchFileNameMax){
	UINT ret = pGetWindowModuleFileNameW(hwnd,pszFileName,cchFileNameMax);
	fprintf(fp,"OUT ['GetWindowModuleFileNameW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'pszFileName',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': %p,", pszFileName);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': %p,", pszFileName);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),cchFileNameMax, ret);
 	}else 
	{
		fprintf(fp,"{'name':'pszFileName',");
		fwprintf(fp, L"'value': %p, ", pszFileName);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	if(pszFileName){
		for(int i=0; i<cchFileNameMax <  ret ? cchFileNameMax :  ret;i++){
			fprintf(fp,"0x%x,",pszFileName[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *DestroyCaret_fun) ();
DestroyCaret_fun pDestroyCaret = DestroyCaret;
HOOK_TRACE_INFO hHookDestroyCaret = { 0 };
ULONG HookDestroyCaret_ACLEntries[1] = { 0 };
BOOL fake_DestroyCaret(){
	BOOL ret = pDestroyCaret();
	fprintf(fp,"OUT ['DestroyCaret',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *MessageBoxIndirectW_fun) (CONST MSGBOXPARAMSW*  lpmbp);
MessageBoxIndirectW_fun pMessageBoxIndirectW = MessageBoxIndirectW;
HOOK_TRACE_INFO hHookMessageBoxIndirectW = { 0 };
ULONG HookMessageBoxIndirectW_ACLEntries[1] = { 0 };
int fake_MessageBoxIndirectW(CONST MSGBOXPARAMSW*  lpmbp){
	int ret = pMessageBoxIndirectW( lpmbp);
	fprintf(fp,"OUT ['MessageBoxIndirectW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *UnhookWindowsHookEx_fun) (HHOOK hhk);
UnhookWindowsHookEx_fun pUnhookWindowsHookEx = UnhookWindowsHookEx;
HOOK_TRACE_INFO hHookUnhookWindowsHookEx = { 0 };
ULONG HookUnhookWindowsHookEx_ACLEntries[1] = { 0 };
BOOL fake_UnhookWindowsHookEx(HHOOK hhk){
	BOOL ret = pUnhookWindowsHookEx(hhk);
	fprintf(fp,"OUT ['UnhookWindowsHookEx',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsCharLowerW_fun) (WCHAR ch);
IsCharLowerW_fun pIsCharLowerW = IsCharLowerW;
HOOK_TRACE_INFO hHookIsCharLowerW = { 0 };
ULONG HookIsCharLowerW_ACLEntries[1] = { 0 };
BOOL fake_IsCharLowerW(WCHAR ch){
	BOOL ret = pIsCharLowerW(ch);
	fprintf(fp,"OUT ['IsCharLowerW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HKL (WINAPI *GetKeyboardLayout_fun) (DWORD idThread);
GetKeyboardLayout_fun pGetKeyboardLayout = GetKeyboardLayout;
HOOK_TRACE_INFO hHookGetKeyboardLayout = { 0 };
ULONG HookGetKeyboardLayout_ACLEntries[1] = { 0 };
HKL fake_GetKeyboardLayout(DWORD idThread){
	HKL ret = pGetKeyboardLayout(idThread);
	fprintf(fp,"OUT ['GetKeyboardLayout',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HKL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HKL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *ToUnicodeEx_fun) (UINT wVirtKey,UINT wScanCode,CONST BYTE* lpKeyState,LPWSTR pwszBuff,int cchBuff,UINT wFlags,HKL dwhkl);
ToUnicodeEx_fun pToUnicodeEx = ToUnicodeEx;
HOOK_TRACE_INFO hHookToUnicodeEx = { 0 };
ULONG HookToUnicodeEx_ACLEntries[1] = { 0 };
int fake_ToUnicodeEx(UINT wVirtKey,UINT wScanCode,CONST BYTE* lpKeyState,LPWSTR pwszBuff,int cchBuff,UINT wFlags,HKL dwhkl){
	int ret = pToUnicodeEx(wVirtKey,wScanCode,lpKeyState,pwszBuff,cchBuff,wFlags,dwhkl);
	fprintf(fp,"OUT ['ToUnicodeEx',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'pwszBuff',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': %p,", pwszBuff);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': %p,", pwszBuff);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),cchBuff);
 	}else 
	{
		fprintf(fp,"{'name':'pwszBuff',");
		fwprintf(fp, L"'value': %p, ", pwszBuff);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	if(pwszBuff){
		for(int i=0; i<cchBuff;i++){
			fprintf(fp,"0x%x,",pwszBuff[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetUserObjectInformationW_fun) (HANDLE hObj,int nIndex,PVOID pvInfo,DWORD nLength);
SetUserObjectInformationW_fun pSetUserObjectInformationW = SetUserObjectInformationW;
HOOK_TRACE_INFO hHookSetUserObjectInformationW = { 0 };
ULONG HookSetUserObjectInformationW_ACLEntries[1] = { 0 };
BOOL fake_SetUserObjectInformationW(HANDLE hObj,int nIndex,PVOID pvInfo,DWORD nLength){
	BOOL ret = pSetUserObjectInformationW(hObj,nIndex,pvInfo,nLength);
	fprintf(fp,"OUT ['SetUserObjectInformationW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT (WINAPI *RealGetWindowClassA_fun) (HWND hwnd,LPSTR ptszClassName,UINT cchClassNameMax);
RealGetWindowClassA_fun pRealGetWindowClassA = RealGetWindowClassA;
HOOK_TRACE_INFO hHookRealGetWindowClassA = { 0 };
ULONG HookRealGetWindowClassA_ACLEntries[1] = { 0 };
UINT fake_RealGetWindowClassA(HWND hwnd,LPSTR ptszClassName,UINT cchClassNameMax){
	UINT ret = pRealGetWindowClassA(hwnd,ptszClassName,cchClassNameMax);
	fprintf(fp,"OUT ['RealGetWindowClassA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'ptszClassName','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",ptszClassName, sizeof(LPSTR),cchClassNameMax, ret);
 	else fprintf(fp,"{'name':'ptszClassName','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ptszClassName,sizeof(LPSTR));
	if(ptszClassName){
		for(int i=0; i<cchClassNameMax <  ret ? cchClassNameMax :  ret;i++){
			fprintf(fp,"0x%x,",ptszClassName[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetUserObjectInformationA_fun) (HANDLE hObj,int nIndex,PVOID pvInfo,DWORD nLength);
SetUserObjectInformationA_fun pSetUserObjectInformationA = SetUserObjectInformationA;
HOOK_TRACE_INFO hHookSetUserObjectInformationA = { 0 };
ULONG HookSetUserObjectInformationA_ACLEntries[1] = { 0 };
BOOL fake_SetUserObjectInformationA(HANDLE hObj,int nIndex,PVOID pvInfo,DWORD nLength){
	BOOL ret = pSetUserObjectInformationA(hObj,nIndex,pvInfo,nLength);
	fprintf(fp,"OUT ['SetUserObjectInformationA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetClassInfoExA_fun) (HINSTANCE hInstance,LPCSTR lpszClass,LPWNDCLASSEXA lpwcx);
GetClassInfoExA_fun pGetClassInfoExA = GetClassInfoExA;
HOOK_TRACE_INFO hHookGetClassInfoExA = { 0 };
ULONG HookGetClassInfoExA_ACLEntries[1] = { 0 };
BOOL fake_GetClassInfoExA(HINSTANCE hInstance,LPCSTR lpszClass,LPWNDCLASSEXA lpwcx){
	BOOL ret = pGetClassInfoExA(hInstance,lpszClass,lpwcx);
	fprintf(fp,"OUT ['GetClassInfoExA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpwcx','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpwcx, sizeof(LPWNDCLASSEXA),1);
 	else fprintf(fp,"{'name':'lpwcx','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpwcx,sizeof(LPWNDCLASSEXA));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetMenuBarInfo_fun) (HWND hwnd,LONG idObject,LONG idItem,PMENUBARINFO pmbi);
GetMenuBarInfo_fun pGetMenuBarInfo = GetMenuBarInfo;
HOOK_TRACE_INFO hHookGetMenuBarInfo = { 0 };
ULONG HookGetMenuBarInfo_ACLEntries[1] = { 0 };
BOOL fake_GetMenuBarInfo(HWND hwnd,LONG idObject,LONG idItem,PMENUBARINFO pmbi){
	BOOL ret = pGetMenuBarInfo(hwnd,idObject,idItem,pmbi);
	fprintf(fp,"OUT ['GetMenuBarInfo',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pmbi','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pmbi, sizeof(PMENUBARINFO),1);
 	else fprintf(fp,"{'name':'pmbi','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pmbi,sizeof(PMENUBARINFO));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetMenuItemInfoA_fun) (HMENU hmenu,UINT item,BOOL fByPositon,LPCMENUITEMINFOA lpmii);
SetMenuItemInfoA_fun pSetMenuItemInfoA = SetMenuItemInfoA;
HOOK_TRACE_INFO hHookSetMenuItemInfoA = { 0 };
ULONG HookSetMenuItemInfoA_ACLEntries[1] = { 0 };
BOOL fake_SetMenuItemInfoA(HMENU hmenu,UINT item,BOOL fByPositon,LPCMENUITEMINFOA lpmii){
	BOOL ret = pSetMenuItemInfoA(hmenu,item,fByPositon,lpmii);
	fprintf(fp,"OUT ['SetMenuItemInfoA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ShutdownBlockReasonQuery_fun) (HWND hWnd,LPWSTR pwszBuff,DWORD* pcchBuff);
ShutdownBlockReasonQuery_fun pShutdownBlockReasonQuery = ShutdownBlockReasonQuery;
HOOK_TRACE_INFO hHookShutdownBlockReasonQuery = { 0 };
ULONG HookShutdownBlockReasonQuery_ACLEntries[1] = { 0 };
BOOL fake_ShutdownBlockReasonQuery(HWND hWnd,LPWSTR pwszBuff,DWORD* pcchBuff){
	BOOL ret = pShutdownBlockReasonQuery(hWnd,pwszBuff,pcchBuff);
	fprintf(fp,"OUT ['ShutdownBlockReasonQuery',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(pcchBuff && 1)
	{
		fprintf(fp,"{'name':'pwszBuff',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': %p,", pwszBuff);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': %p,", pwszBuff);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),*pcchBuff);
 	}else 
	{
		fprintf(fp,"{'name':'pwszBuff',");
		fwprintf(fp, L"'value': %p, ", pwszBuff);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	if(pcchBuff && pwszBuff){
		for(int i=0; i<*pcchBuff;i++){
			fprintf(fp,"0x%x,",pwszBuff[i]);
		}
	}
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pcchBuff','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pcchBuff, sizeof(DWORD*),1);
 	else fprintf(fp,"{'name':'pcchBuff','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pcchBuff,sizeof(DWORD*));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LPWSTR (WINAPI *CharPrevW_fun) (LPCWSTR lpszStart,LPCWSTR lpszCurrent);
CharPrevW_fun pCharPrevW = CharPrevW;
HOOK_TRACE_INFO hHookCharPrevW = { 0 };
ULONG HookCharPrevW_ACLEntries[1] = { 0 };
LPWSTR fake_CharPrevW(LPCWSTR lpszStart,LPCWSTR lpszCurrent){
	LPWSTR ret = pCharPrevW(lpszStart,lpszCurrent);
	fprintf(fp,"OUT ['CharPrevW',");
	if(1)
	{
		fprintf(fp,"{'name':'ret',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': '\"%s\"',", ret);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': '\"%s\"',", ret);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),1);
 	}else 
	{
		fprintf(fp,"{'name':'ret',");
		fwprintf(fp, L"'value': '\"%s\"', ", ret);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *CheckDlgButton_fun) (HWND hDlg,int nIDButton,UINT uCheck);
CheckDlgButton_fun pCheckDlgButton = CheckDlgButton;
HOOK_TRACE_INFO hHookCheckDlgButton = { 0 };
ULONG HookCheckDlgButton_ACLEntries[1] = { 0 };
BOOL fake_CheckDlgButton(HWND hDlg,int nIDButton,UINT uCheck){
	BOOL ret = pCheckDlgButton(hDlg,nIDButton,uCheck);
	fprintf(fp,"OUT ['CheckDlgButton',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ClientToScreen_fun) (HWND hWnd,LPPOINT lpPoint);
ClientToScreen_fun pClientToScreen = ClientToScreen;
HOOK_TRACE_INFO hHookClientToScreen = { 0 };
ULONG HookClientToScreen_ACLEntries[1] = { 0 };
BOOL fake_ClientToScreen(HWND hWnd,LPPOINT lpPoint){
	BOOL ret = pClientToScreen(hWnd,lpPoint);
	fprintf(fp,"OUT ['ClientToScreen',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpPoint','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpPoint, sizeof(LPPOINT),1);
 	else fprintf(fp,"{'name':'lpPoint','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpPoint,sizeof(LPPOINT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *DlgDirSelectComboBoxExA_fun) (HWND hwndDlg,LPSTR lpString,int cchOut,int idComboBox);
DlgDirSelectComboBoxExA_fun pDlgDirSelectComboBoxExA = DlgDirSelectComboBoxExA;
HOOK_TRACE_INFO hHookDlgDirSelectComboBoxExA = { 0 };
ULONG HookDlgDirSelectComboBoxExA_ACLEntries[1] = { 0 };
BOOL fake_DlgDirSelectComboBoxExA(HWND hwndDlg,LPSTR lpString,int cchOut,int idComboBox){
	BOOL ret = pDlgDirSelectComboBoxExA(hwndDlg,lpString,cchOut,idComboBox);
	fprintf(fp,"OUT ['DlgDirSelectComboBoxExA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpString','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpString, sizeof(LPSTR),cchOut);
 	else fprintf(fp,"{'name':'lpString','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpString,sizeof(LPSTR));
	if(lpString){
		for(int i=0; i<cchOut;i++){
			fprintf(fp,"0x%x,",lpString[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *DrawTextW_fun) (HDC hdc,LPCWSTR lpchText,int cchText,LPRECT lprc,UINT format);
DrawTextW_fun pDrawTextW = DrawTextW;
HOOK_TRACE_INFO hHookDrawTextW = { 0 };
ULONG HookDrawTextW_ACLEntries[1] = { 0 };
int fake_DrawTextW(HDC hdc,LPCWSTR lpchText,int cchText,LPRECT lprc,UINT format){
	int ret = pDrawTextW(hdc,lpchText,cchText,lprc,format);
	fprintf(fp,"OUT ['DrawTextW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'lpchText',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': %p,", lpchText);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': %p,", lpchText);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPCWSTR),cchText);
 	}else 
	{
		fprintf(fp,"{'name':'lpchText',");
		fwprintf(fp, L"'value': %p, ", lpchText);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPCWSTR));
	}
	if(lpchText){
		for(int i=0; i<cchText;i++){
			fprintf(fp,"0x%x,",lpchText[i]);
		}
	}
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lprc','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lprc, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'lprc','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lprc,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LRESULT (WINAPI *DefDlgProcW_fun) (HWND hDlg,UINT Msg,WPARAM wParam,LPARAM lParam);
DefDlgProcW_fun pDefDlgProcW = DefDlgProcW;
HOOK_TRACE_INFO hHookDefDlgProcW = { 0 };
ULONG HookDefDlgProcW_ACLEntries[1] = { 0 };
LRESULT fake_DefDlgProcW(HWND hDlg,UINT Msg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pDefDlgProcW(hDlg,Msg,wParam,lParam);
	fprintf(fp,"OUT ['DefDlgProcW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LRESULT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LRESULT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWINEVENTHOOK (WINAPI *SetWinEventHook_fun) (DWORD eventMin,DWORD eventMax,HMODULE hmodWinEventProc,WINEVENTPROC pfnWinEventProc,DWORD idProcess,DWORD idThread,DWORD dwFlags);
SetWinEventHook_fun pSetWinEventHook = SetWinEventHook;
HOOK_TRACE_INFO hHookSetWinEventHook = { 0 };
ULONG HookSetWinEventHook_ACLEntries[1] = { 0 };
HWINEVENTHOOK fake_SetWinEventHook(DWORD eventMin,DWORD eventMax,HMODULE hmodWinEventProc,WINEVENTPROC pfnWinEventProc,DWORD idProcess,DWORD idThread,DWORD dwFlags){
	HWINEVENTHOOK ret = pSetWinEventHook(eventMin,eventMax,hmodWinEventProc,pfnWinEventProc,idProcess,idThread,dwFlags);
	fprintf(fp,"OUT ['SetWinEventHook',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWINEVENTHOOK),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWINEVENTHOOK));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ShowWindow_fun) (HWND hWnd,int nCmdShow);
ShowWindow_fun pShowWindow = ShowWindow;
HOOK_TRACE_INFO hHookShowWindow = { 0 };
ULONG HookShowWindow_ACLEntries[1] = { 0 };
BOOL fake_ShowWindow(HWND hWnd,int nCmdShow){
	BOOL ret = pShowWindow(hWnd,nCmdShow);
	fprintf(fp,"OUT ['ShowWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetPropW_fun) (HWND hWnd,LPCWSTR lpString,HANDLE hData);
SetPropW_fun pSetPropW = SetPropW;
HOOK_TRACE_INFO hHookSetPropW = { 0 };
ULONG HookSetPropW_ACLEntries[1] = { 0 };
BOOL fake_SetPropW(HWND hWnd,LPCWSTR lpString,HANDLE hData){
	BOOL ret = pSetPropW(hWnd,lpString,hData);
	fprintf(fp,"OUT ['SetPropW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *ToAsciiEx_fun) (UINT uVirtKey,UINT uScanCode,CONST BYTE* lpKeyState,LPWORD lpChar,UINT uFlags,HKL dwhkl);
ToAsciiEx_fun pToAsciiEx = ToAsciiEx;
HOOK_TRACE_INFO hHookToAsciiEx = { 0 };
ULONG HookToAsciiEx_ACLEntries[1] = { 0 };
int fake_ToAsciiEx(UINT uVirtKey,UINT uScanCode,CONST BYTE* lpKeyState,LPWORD lpChar,UINT uFlags,HKL dwhkl){
	int ret = pToAsciiEx(uVirtKey,uScanCode,lpKeyState,lpChar,uFlags,dwhkl);
	fprintf(fp,"OUT ['ToAsciiEx',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpChar','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpChar, sizeof(LPWORD),1);
 	else fprintf(fp,"{'name':'lpChar','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpChar,sizeof(LPWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef SHORT (WINAPI *VkKeyScanA_fun) (CHAR ch);
VkKeyScanA_fun pVkKeyScanA = VkKeyScanA;
HOOK_TRACE_INFO hHookVkKeyScanA = { 0 };
ULONG HookVkKeyScanA_ACLEntries[1] = { 0 };
SHORT fake_VkKeyScanA(CHAR ch){
	SHORT ret = pVkKeyScanA(ch);
	fprintf(fp,"OUT ['VkKeyScanA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%hx,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(SHORT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%hx, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(SHORT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SendMessageCallbackA_fun) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lpResultCallBack,ULONG_PTR dwData);
SendMessageCallbackA_fun pSendMessageCallbackA = SendMessageCallbackA;
HOOK_TRACE_INFO hHookSendMessageCallbackA = { 0 };
ULONG HookSendMessageCallbackA_ACLEntries[1] = { 0 };
BOOL fake_SendMessageCallbackA(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lpResultCallBack,ULONG_PTR dwData){
	BOOL ret = pSendMessageCallbackA(hWnd,Msg,wParam,lParam,lpResultCallBack,dwData);
	fprintf(fp,"OUT ['SendMessageCallbackA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *SetClipboardViewer_fun) (HWND hWndNewViewer);
SetClipboardViewer_fun pSetClipboardViewer = SetClipboardViewer;
HOOK_TRACE_INFO hHookSetClipboardViewer = { 0 };
ULONG HookSetClipboardViewer_ACLEntries[1] = { 0 };
HWND fake_SetClipboardViewer(HWND hWndNewViewer){
	HWND ret = pSetClipboardViewer(hWndNewViewer);
	fprintf(fp,"OUT ['SetClipboardViewer',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetInputState_fun) ();
GetInputState_fun pGetInputState = GetInputState;
HOOK_TRACE_INFO hHookGetInputState = { 0 };
ULONG HookGetInputState_ACLEntries[1] = { 0 };
BOOL fake_GetInputState(){
	BOOL ret = pGetInputState();
	fprintf(fp,"OUT ['GetInputState',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LRESULT (WINAPI *DefMDIChildProcW_fun) (HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
DefMDIChildProcW_fun pDefMDIChildProcW = DefMDIChildProcW;
HOOK_TRACE_INFO hHookDefMDIChildProcW = { 0 };
ULONG HookDefMDIChildProcW_ACLEntries[1] = { 0 };
LRESULT fake_DefMDIChildProcW(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pDefMDIChildProcW(hWnd,uMsg,wParam,lParam);
	fprintf(fp,"OUT ['DefMDIChildProcW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LRESULT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LRESULT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IntersectRect_fun) (LPRECT lprcDst,CONST RECT* lprcSrc1,CONST RECT* lprcSrc2);
IntersectRect_fun pIntersectRect = IntersectRect;
HOOK_TRACE_INFO hHookIntersectRect = { 0 };
ULONG HookIntersectRect_ACLEntries[1] = { 0 };
BOOL fake_IntersectRect(LPRECT lprcDst,CONST RECT* lprcSrc1,CONST RECT* lprcSrc2){
	BOOL ret = pIntersectRect(lprcDst,lprcSrc1,lprcSrc2);
	fprintf(fp,"OUT ['IntersectRect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lprcDst','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lprcDst, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'lprcDst','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lprcDst,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetWindowPlacement_fun) (HWND hWnd,CONST WINDOWPLACEMENT* lpwndpl);
SetWindowPlacement_fun pSetWindowPlacement = SetWindowPlacement;
HOOK_TRACE_INFO hHookSetWindowPlacement = { 0 };
ULONG HookSetWindowPlacement_ACLEntries[1] = { 0 };
BOOL fake_SetWindowPlacement(HWND hWnd,CONST WINDOWPLACEMENT* lpwndpl){
	BOOL ret = pSetWindowPlacement(hWnd,lpwndpl);
	fprintf(fp,"OUT ['SetWindowPlacement',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *GetNextDlgTabItem_fun) (HWND hDlg,HWND hCtl,BOOL bPrevious);
GetNextDlgTabItem_fun pGetNextDlgTabItem = GetNextDlgTabItem;
HOOK_TRACE_INFO hHookGetNextDlgTabItem = { 0 };
ULONG HookGetNextDlgTabItem_ACLEntries[1] = { 0 };
HWND fake_GetNextDlgTabItem(HWND hDlg,HWND hCtl,BOOL bPrevious){
	HWND ret = pGetNextDlgTabItem(hDlg,hCtl,bPrevious);
	fprintf(fp,"OUT ['GetNextDlgTabItem',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *SetCapture_fun) (HWND hWnd);
SetCapture_fun pSetCapture = SetCapture;
HOOK_TRACE_INFO hHookSetCapture = { 0 };
ULONG HookSetCapture_ACLEntries[1] = { 0 };
HWND fake_SetCapture(HWND hWnd){
	HWND ret = pSetCapture(hWnd);
	fprintf(fp,"OUT ['SetCapture',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LONG (WINAPI *DisplayConfigSetDeviceInfo_fun) (DISPLAYCONFIG_DEVICE_INFO_HEADER*  setPacket);
DisplayConfigSetDeviceInfo_fun pDisplayConfigSetDeviceInfo = DisplayConfigSetDeviceInfo;
HOOK_TRACE_INFO hHookDisplayConfigSetDeviceInfo = { 0 };
ULONG HookDisplayConfigSetDeviceInfo_ACLEntries[1] = { 0 };
LONG fake_DisplayConfigSetDeviceInfo(DISPLAYCONFIG_DEVICE_INFO_HEADER*  setPacket){
	LONG ret = pDisplayConfigSetDeviceInfo( setPacket);
	fprintf(fp,"OUT ['DisplayConfigSetDeviceInfo',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LONG),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LONG));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *GetWindowTextA_fun) (HWND hWnd,LPSTR lpString,int nMaxCount);
GetWindowTextA_fun pGetWindowTextA = GetWindowTextA;
HOOK_TRACE_INFO hHookGetWindowTextA = { 0 };
ULONG HookGetWindowTextA_ACLEntries[1] = { 0 };
int fake_GetWindowTextA(HWND hWnd,LPSTR lpString,int nMaxCount){
	int ret = pGetWindowTextA(hWnd,lpString,nMaxCount);
	fprintf(fp,"OUT ['GetWindowTextA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpString','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpString, sizeof(LPSTR),nMaxCount);
 	else fprintf(fp,"{'name':'lpString','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpString,sizeof(LPSTR));
	if(lpString){
		for(int i=0; i<nMaxCount;i++){
			fprintf(fp,"0x%x,",lpString[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetMenuInfo_fun) (HMENU arg0,LPCMENUINFO arg1);
SetMenuInfo_fun pSetMenuInfo = SetMenuInfo;
HOOK_TRACE_INFO hHookSetMenuInfo = { 0 };
ULONG HookSetMenuInfo_ACLEntries[1] = { 0 };
BOOL fake_SetMenuInfo(HMENU arg0,LPCMENUINFO arg1){
	BOOL ret = pSetMenuInfo(arg0,arg1);
	fprintf(fp,"OUT ['SetMenuInfo',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *TranslateMDISysAccel_fun) (HWND hWndClient,LPMSG lpMsg);
TranslateMDISysAccel_fun pTranslateMDISysAccel = TranslateMDISysAccel;
HOOK_TRACE_INFO hHookTranslateMDISysAccel = { 0 };
ULONG HookTranslateMDISysAccel_ACLEntries[1] = { 0 };
BOOL fake_TranslateMDISysAccel(HWND hWndClient,LPMSG lpMsg){
	BOOL ret = pTranslateMDISysAccel(hWndClient,lpMsg);
	fprintf(fp,"OUT ['TranslateMDISysAccel',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef INT_PTR (WINAPI *DialogBoxParamW_fun) (HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
DialogBoxParamW_fun pDialogBoxParamW = DialogBoxParamW;
HOOK_TRACE_INFO hHookDialogBoxParamW = { 0 };
ULONG HookDialogBoxParamW_ACLEntries[1] = { 0 };
INT_PTR fake_DialogBoxParamW(HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam){
	INT_PTR ret = pDialogBoxParamW(hInstance,lpTemplateName,hWndParent,lpDialogFunc,dwInitParam);
	fprintf(fp,"OUT ['DialogBoxParamW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(INT_PTR),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(INT_PTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetComboBoxInfo_fun) (HWND hwndCombo,PCOMBOBOXINFO pcbi);
GetComboBoxInfo_fun pGetComboBoxInfo = GetComboBoxInfo;
HOOK_TRACE_INFO hHookGetComboBoxInfo = { 0 };
ULONG HookGetComboBoxInfo_ACLEntries[1] = { 0 };
BOOL fake_GetComboBoxInfo(HWND hwndCombo,PCOMBOBOXINFO pcbi){
	BOOL ret = pGetComboBoxInfo(hwndCombo,pcbi);
	fprintf(fp,"OUT ['GetComboBoxInfo',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pcbi','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pcbi, sizeof(PCOMBOBOXINFO),1);
 	else fprintf(fp,"{'name':'pcbi','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pcbi,sizeof(PCOMBOBOXINFO));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsCharUpperW_fun) (WCHAR ch);
IsCharUpperW_fun pIsCharUpperW = IsCharUpperW;
HOOK_TRACE_INFO hHookIsCharUpperW = { 0 };
ULONG HookIsCharUpperW_ACLEntries[1] = { 0 };
BOOL fake_IsCharUpperW(WCHAR ch){
	BOOL ret = pIsCharUpperW(ch);
	fprintf(fp,"OUT ['IsCharUpperW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetUserObjectInformationW_fun) (HANDLE hObj,int nIndex,PVOID pvInfo,DWORD nLength,LPDWORD lpnLengthNeeded);
GetUserObjectInformationW_fun pGetUserObjectInformationW = GetUserObjectInformationW;
HOOK_TRACE_INFO hHookGetUserObjectInformationW = { 0 };
ULONG HookGetUserObjectInformationW_ACLEntries[1] = { 0 };
BOOL fake_GetUserObjectInformationW(HANDLE hObj,int nIndex,PVOID pvInfo,DWORD nLength,LPDWORD lpnLengthNeeded){
	BOOL ret = pGetUserObjectInformationW(hObj,nIndex,pvInfo,nLength,lpnLengthNeeded);
	fprintf(fp,"OUT ['GetUserObjectInformationW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pvInfo','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pvInfo, sizeof(PVOID),1);
 	else fprintf(fp,"{'name':'pvInfo','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pvInfo,sizeof(PVOID));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpnLengthNeeded','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpnLengthNeeded, sizeof(LPDWORD),1);
 	else fprintf(fp,"{'name':'lpnLengthNeeded','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpnLengthNeeded,sizeof(LPDWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LPARAM (WINAPI *GetMessageExtraInfo_fun) ();
GetMessageExtraInfo_fun pGetMessageExtraInfo = GetMessageExtraInfo;
HOOK_TRACE_INFO hHookGetMessageExtraInfo = { 0 };
ULONG HookGetMessageExtraInfo_ACLEntries[1] = { 0 };
LPARAM fake_GetMessageExtraInfo(){
	LPARAM ret = pGetMessageExtraInfo();
	fprintf(fp,"OUT ['GetMessageExtraInfo',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LPARAM),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LPARAM));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *EnumDisplayDevicesA_fun) (LPCSTR lpDevice,DWORD iDevNum,PDISPLAY_DEVICEA lpDisplayDevice,DWORD dwFlags);
EnumDisplayDevicesA_fun pEnumDisplayDevicesA = EnumDisplayDevicesA;
HOOK_TRACE_INFO hHookEnumDisplayDevicesA = { 0 };
ULONG HookEnumDisplayDevicesA_ACLEntries[1] = { 0 };
BOOL fake_EnumDisplayDevicesA(LPCSTR lpDevice,DWORD iDevNum,PDISPLAY_DEVICEA lpDisplayDevice,DWORD dwFlags){
	BOOL ret = pEnumDisplayDevicesA(lpDevice,iDevNum,lpDisplayDevice,dwFlags);
	fprintf(fp,"OUT ['EnumDisplayDevicesA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpDisplayDevice','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpDisplayDevice, sizeof(PDISPLAY_DEVICEA),1);
 	else fprintf(fp,"{'name':'lpDisplayDevice','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpDisplayDevice,sizeof(PDISPLAY_DEVICEA));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *MoveWindow_fun) (HWND hWnd,int X,int Y,int nWidth,int nHeight,BOOL bRepaint);
MoveWindow_fun pMoveWindow = MoveWindow;
HOOK_TRACE_INFO hHookMoveWindow = { 0 };
ULONG HookMoveWindow_ACLEntries[1] = { 0 };
BOOL fake_MoveWindow(HWND hWnd,int X,int Y,int nWidth,int nHeight,BOOL bRepaint){
	BOOL ret = pMoveWindow(hWnd,X,Y,nWidth,nHeight,bRepaint);
	fprintf(fp,"OUT ['MoveWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *GetUserObjectSecurity_fun) (HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID,DWORD nLength,LPDWORD lpnLengthNeeded);
GetUserObjectSecurity_fun pGetUserObjectSecurity = GetUserObjectSecurity;
HOOK_TRACE_INFO hHookGetUserObjectSecurity = { 0 };
ULONG HookGetUserObjectSecurity_ACLEntries[1] = { 0 };
BOOL fake_GetUserObjectSecurity(HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID,DWORD nLength,LPDWORD lpnLengthNeeded){
	BOOL ret = pGetUserObjectSecurity(hObj,pSIRequested,pSID,nLength,lpnLengthNeeded);
	fprintf(fp,"OUT ['GetUserObjectSecurity',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pSID','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pSID, sizeof(PSECURITY_DESCRIPTOR),1);
 	else fprintf(fp,"{'name':'pSID','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pSID,sizeof(PSECURITY_DESCRIPTOR));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpnLengthNeeded','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpnLengthNeeded, sizeof(LPDWORD),1);
 	else fprintf(fp,"{'name':'lpnLengthNeeded','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpnLengthNeeded,sizeof(LPDWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *DrawFrameControl_fun) (HDC arg0,LPRECT arg1,UINT arg2,UINT arg3);
DrawFrameControl_fun pDrawFrameControl = DrawFrameControl;
HOOK_TRACE_INFO hHookDrawFrameControl = { 0 };
ULONG HookDrawFrameControl_ACLEntries[1] = { 0 };
BOOL fake_DrawFrameControl(HDC arg0,LPRECT arg1,UINT arg2,UINT arg3){
	BOOL ret = pDrawFrameControl(arg0,arg1,arg2,arg3);
	fprintf(fp,"OUT ['DrawFrameControl',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'arg1','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",arg1, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'arg1','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",arg1,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LRESULT (WINAPI *DefWindowProcA_fun) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
DefWindowProcA_fun pDefWindowProcA = DefWindowProcA;
HOOK_TRACE_INFO hHookDefWindowProcA = { 0 };
ULONG HookDefWindowProcA_ACLEntries[1] = { 0 };
LRESULT fake_DefWindowProcA(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pDefWindowProcA(hWnd,Msg,wParam,lParam);
	fprintf(fp,"OUT ['DefWindowProcA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LRESULT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LRESULT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *DrawMenuBar_fun) (HWND hWnd);
DrawMenuBar_fun pDrawMenuBar = DrawMenuBar;
HOOK_TRACE_INFO hHookDrawMenuBar = { 0 };
ULONG HookDrawMenuBar_ACLEntries[1] = { 0 };
BOOL fake_DrawMenuBar(HWND hWnd){
	BOOL ret = pDrawMenuBar(hWnd);
	fprintf(fp,"OUT ['DrawMenuBar',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *AllowSetForegroundWindow_fun) (DWORD dwProcessId);
AllowSetForegroundWindow_fun pAllowSetForegroundWindow = AllowSetForegroundWindow;
HOOK_TRACE_INFO hHookAllowSetForegroundWindow = { 0 };
ULONG HookAllowSetForegroundWindow_ACLEntries[1] = { 0 };
BOOL fake_AllowSetForegroundWindow(DWORD dwProcessId){
	BOOL ret = pAllowSetForegroundWindow(dwProcessId);
	fprintf(fp,"OUT ['AllowSetForegroundWindow',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWINSTA (WINAPI *OpenWindowStationW_fun) (LPCWSTR lpszWinSta,BOOL fInherit,ACCESS_MASK dwDesiredAccess);
OpenWindowStationW_fun pOpenWindowStationW = OpenWindowStationW;
HOOK_TRACE_INFO hHookOpenWindowStationW = { 0 };
ULONG HookOpenWindowStationW_ACLEntries[1] = { 0 };
HWINSTA fake_OpenWindowStationW(LPCWSTR lpszWinSta,BOOL fInherit,ACCESS_MASK dwDesiredAccess){
	HWINSTA ret = pOpenWindowStationW(lpszWinSta,fInherit,dwDesiredAccess);
	fprintf(fp,"OUT ['OpenWindowStationW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWINSTA),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWINSTA));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *UnhookWinEvent_fun) (HWINEVENTHOOK hWinEventHook);
UnhookWinEvent_fun pUnhookWinEvent = UnhookWinEvent;
HOOK_TRACE_INFO hHookUnhookWinEvent = { 0 };
ULONG HookUnhookWinEvent_ACLEntries[1] = { 0 };
BOOL fake_UnhookWinEvent(HWINEVENTHOOK hWinEventHook){
	BOOL ret = pUnhookWinEvent(hWinEventHook);
	fprintf(fp,"OUT ['UnhookWinEvent',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HWND (WINAPI *GetClipboardOwner_fun) ();
GetClipboardOwner_fun pGetClipboardOwner = GetClipboardOwner;
HOOK_TRACE_INFO hHookGetClipboardOwner = { 0 };
ULONG HookGetClipboardOwner_ACLEntries[1] = { 0 };
HWND fake_GetClipboardOwner(){
	HWND ret = pGetClipboardOwner();
	fprintf(fp,"OUT ['GetClipboardOwner',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HWND),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HWND));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LRESULT (WINAPI *DefDlgProcA_fun) (HWND hDlg,UINT Msg,WPARAM wParam,LPARAM lParam);
DefDlgProcA_fun pDefDlgProcA = DefDlgProcA;
HOOK_TRACE_INFO hHookDefDlgProcA = { 0 };
ULONG HookDefDlgProcA_ACLEntries[1] = { 0 };
LRESULT fake_DefDlgProcA(HWND hDlg,UINT Msg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pDefDlgProcA(hDlg,Msg,wParam,lParam);
	fprintf(fp,"OUT ['DefDlgProcA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LRESULT),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LRESULT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *DeleteMenu_fun) (HMENU hMenu,UINT uPosition,UINT uFlags);
DeleteMenu_fun pDeleteMenu = DeleteMenu;
HOOK_TRACE_INFO hHookDeleteMenu = { 0 };
ULONG HookDeleteMenu_ACLEntries[1] = { 0 };
BOOL fake_DeleteMenu(HMENU hMenu,UINT uPosition,UINT uFlags){
	BOOL ret = pDeleteMenu(hMenu,uPosition,uFlags);
	fprintf(fp,"OUT ['DeleteMenu',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef long (WINAPI *BroadcastSystemMessageExA_fun) (DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo);
BroadcastSystemMessageExA_fun pBroadcastSystemMessageExA = BroadcastSystemMessageExA;
HOOK_TRACE_INFO hHookBroadcastSystemMessageExA = { 0 };
ULONG HookBroadcastSystemMessageExA_ACLEntries[1] = { 0 };
long fake_BroadcastSystemMessageExA(DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo){
	long ret = pBroadcastSystemMessageExA(flags,lpInfo,Msg,wParam,lParam,pbsmInfo);
	fprintf(fp,"OUT ['BroadcastSystemMessageExA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%llx,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(long),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%llx, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(long));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpInfo','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpInfo, sizeof(LPDWORD),1);
 	else fprintf(fp,"{'name':'lpInfo','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpInfo,sizeof(LPDWORD));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'pbsmInfo','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",pbsmInfo, sizeof(PBSMINFO),1);
 	else fprintf(fp,"{'name':'pbsmInfo','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",pbsmInfo,sizeof(PBSMINFO));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsGUIThread_fun) (BOOL bConvert);
IsGUIThread_fun pIsGUIThread = IsGUIThread;
HOOK_TRACE_INFO hHookIsGUIThread = { 0 };
ULONG HookIsGUIThread_ACLEntries[1] = { 0 };
BOOL fake_IsGUIThread(BOOL bConvert){
	BOOL ret = pIsGUIThread(bConvert);
	fprintf(fp,"OUT ['IsGUIThread',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *LockWorkStation_fun) ();
LockWorkStation_fun pLockWorkStation = LockWorkStation;
HOOK_TRACE_INFO hHookLockWorkStation = { 0 };
ULONG HookLockWorkStation_ACLEntries[1] = { 0 };
BOOL fake_LockWorkStation(){
	BOOL ret = pLockWorkStation();
	fprintf(fp,"OUT ['LockWorkStation',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *IsWinEventHookInstalled_fun) (DWORD event);
IsWinEventHookInstalled_fun pIsWinEventHookInstalled = IsWinEventHookInstalled;
HOOK_TRACE_INFO hHookIsWinEventHookInstalled = { 0 };
ULONG HookIsWinEventHookInstalled_ACLEntries[1] = { 0 };
BOOL fake_IsWinEventHookInstalled(DWORD event){
	BOOL ret = pIsWinEventHookInstalled(event);
	fprintf(fp,"OUT ['IsWinEventHookInstalled',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *OemToCharW_fun) (LPCSTR pSrc,LPWSTR pDst);
OemToCharW_fun pOemToCharW = OemToCharW;
HOOK_TRACE_INFO hHookOemToCharW = { 0 };
ULONG HookOemToCharW_ACLEntries[1] = { 0 };
BOOL fake_OemToCharW(LPCSTR pSrc,LPWSTR pDst){
	BOOL ret = pOemToCharW(pSrc,pDst);
	fprintf(fp,"OUT ['OemToCharW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'pDst',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': '\"%s\"',", pDst);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': '\"%s\"',", pDst);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),1);
 	}else 
	{
		fprintf(fp,"{'name':'pDst',");
		fwprintf(fp, L"'value': '\"%s\"', ", pDst);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *DragDetect_fun) (HWND hwnd,POINT pt);
DragDetect_fun pDragDetect = DragDetect;
HOOK_TRACE_INFO hHookDragDetect = { 0 };
ULONG HookDragDetect_ACLEntries[1] = { 0 };
BOOL fake_DragDetect(HWND hwnd,POINT pt){
	BOOL ret = pDragDetect(hwnd,pt);
	fprintf(fp,"OUT ['DragDetect',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *GetKeyNameTextW_fun) (LONG lParam,LPWSTR lpString,int cchSize);
GetKeyNameTextW_fun pGetKeyNameTextW = GetKeyNameTextW;
HOOK_TRACE_INFO hHookGetKeyNameTextW = { 0 };
ULONG HookGetKeyNameTextW_ACLEntries[1] = { 0 };
int fake_GetKeyNameTextW(LONG lParam,LPWSTR lpString,int cchSize){
	int ret = pGetKeyNameTextW(lParam,lpString,cchSize);
	fprintf(fp,"OUT ['GetKeyNameTextW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'lpString',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': %p,", lpString);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': %p,", lpString);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),cchSize);
 	}else 
	{
		fprintf(fp,"{'name':'lpString',");
		fwprintf(fp, L"'value': %p, ", lpString);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	if(lpString){
		for(int i=0; i<cchSize;i++){
			fprintf(fp,"0x%x,",lpString[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *GetWindowThreadProcessId_fun) (HWND hWnd,LPDWORD lpdwProcessId);
GetWindowThreadProcessId_fun pGetWindowThreadProcessId = GetWindowThreadProcessId;
HOOK_TRACE_INFO hHookGetWindowThreadProcessId = { 0 };
ULONG HookGetWindowThreadProcessId_ACLEntries[1] = { 0 };
DWORD fake_GetWindowThreadProcessId(HWND hWnd,LPDWORD lpdwProcessId){
	DWORD ret = pGetWindowThreadProcessId(hWnd,lpdwProcessId);
	fprintf(fp,"OUT ['GetWindowThreadProcessId',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpdwProcessId','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpdwProcessId, sizeof(LPDWORD),1);
 	else fprintf(fp,"{'name':'lpdwProcessId','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpdwProcessId,sizeof(LPDWORD));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef UINT_PTR (WINAPI *SetTimer_fun) (HWND hWnd,UINT_PTR nIDEvent,UINT uElapse,TIMERPROC lpTimerFunc);
SetTimer_fun pSetTimer = SetTimer;
HOOK_TRACE_INFO hHookSetTimer = { 0 };
ULONG HookSetTimer_ACLEntries[1] = { 0 };
UINT_PTR fake_SetTimer(HWND hWnd,UINT_PTR nIDEvent,UINT uElapse,TIMERPROC lpTimerFunc){
	UINT_PTR ret = pSetTimer(hWnd,nIDEvent,uElapse,lpTimerFunc);
	fprintf(fp,"OUT ['SetTimer',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(UINT_PTR),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(UINT_PTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *GetWindowRgnBox_fun) (HWND hWnd,LPRECT lprc);
GetWindowRgnBox_fun pGetWindowRgnBox = GetWindowRgnBox;
HOOK_TRACE_INFO hHookGetWindowRgnBox = { 0 };
ULONG HookGetWindowRgnBox_ACLEntries[1] = { 0 };
int fake_GetWindowRgnBox(HWND hWnd,LPRECT lprc){
	int ret = pGetWindowRgnBox(hWnd,lprc);
	fprintf(fp,"OUT ['GetWindowRgnBox',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lprc','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lprc, sizeof(LPRECT),1);
 	else fprintf(fp,"{'name':'lprc','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lprc,sizeof(LPRECT));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef LPSTR (WINAPI *CharNextExA_fun) (WORD CodePage,LPCSTR lpCurrentChar,DWORD dwFlags);
CharNextExA_fun pCharNextExA = CharNextExA;
HOOK_TRACE_INFO hHookCharNextExA = { 0 };
ULONG HookCharNextExA_ACLEntries[1] = { 0 };
LPSTR fake_CharNextExA(WORD CodePage,LPCSTR lpCurrentChar,DWORD dwFlags){
	LPSTR ret = pCharNextExA(CodePage,lpCurrentChar,dwFlags);
	fprintf(fp,"OUT ['CharNextExA',");
	if(1) fprintf(fp,"{'name':'ret','value': '\"%s\"','size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(LPSTR),1);
 	else fprintf(fp,"{'name':'ret','value': '\"%s\"', 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(LPSTR));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef VOID (WINAPI *SwitchToThisWindow_fun) (HWND hwnd,BOOL fUnknown);
SwitchToThisWindow_fun pSwitchToThisWindow = SwitchToThisWindow;
HOOK_TRACE_INFO hHookSwitchToThisWindow = { 0 };
ULONG HookSwitchToThisWindow_ACLEntries[1] = { 0 };
VOID fake_SwitchToThisWindow(HWND hwnd,BOOL fUnknown){
	pSwitchToThisWindow(hwnd,fUnknown);
	fprintf(fp,"OUT ['SwitchToThisWindow',");
	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
}


typedef DWORD (WINAPI *CharLowerBuffA_fun) (LPSTR lpsz,DWORD cchLength);
CharLowerBuffA_fun pCharLowerBuffA = CharLowerBuffA;
HOOK_TRACE_INFO hHookCharLowerBuffA = { 0 };
ULONG HookCharLowerBuffA_ACLEntries[1] = { 0 };
DWORD fake_CharLowerBuffA(LPSTR lpsz,DWORD cchLength){
	DWORD ret = pCharLowerBuffA(lpsz,cchLength);
	fprintf(fp,"OUT ['CharLowerBuffA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	if(1) fprintf(fp,"{'name':'lpsz','value': %p,'size' : 0x%lx,'cnt':0x%x, 'data':[",lpsz, sizeof(LPSTR),cchLength);
 	else fprintf(fp,"{'name':'lpsz','value': %p, 'size' : 0x%lx,'cnt':'undefined', 'data':[",lpsz,sizeof(LPSTR));
	if(lpsz){
		for(int i=0; i<cchLength;i++){
			fprintf(fp,"0x%x,",lpsz[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef int (WINAPI *GetMenuItemCount_fun) (HMENU hMenu);
GetMenuItemCount_fun pGetMenuItemCount = GetMenuItemCount;
HOOK_TRACE_INFO hHookGetMenuItemCount = { 0 };
ULONG HookGetMenuItemCount_ACLEntries[1] = { 0 };
int fake_GetMenuItemCount(HMENU hMenu){
	int ret = pGetMenuItemCount(hMenu);
	fprintf(fp,"OUT ['GetMenuItemCount',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(int),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(int));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *SetProcessWindowStation_fun) (HWINSTA hWinSta);
SetProcessWindowStation_fun pSetProcessWindowStation = SetProcessWindowStation;
HOOK_TRACE_INFO hHookSetProcessWindowStation = { 0 };
ULONG HookSetProcessWindowStation_ACLEntries[1] = { 0 };
BOOL fake_SetProcessWindowStation(HWINSTA hWinSta){
	BOOL ret = pSetProcessWindowStation(hWinSta);
	fprintf(fp,"OUT ['SetProcessWindowStation',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef HHOOK (WINAPI *SetWindowsHookA_fun) (int nFilterType,HOOKPROC pfnFilterProc);
SetWindowsHookA_fun pSetWindowsHookA = SetWindowsHookA;
HOOK_TRACE_INFO hHookSetWindowsHookA = { 0 };
ULONG HookSetWindowsHookA_ACLEntries[1] = { 0 };
HHOOK fake_SetWindowsHookA(int nFilterType,HOOKPROC pfnFilterProc){
	HHOOK ret = pSetWindowsHookA(nFilterType,pfnFilterProc);
	fprintf(fp,"OUT ['SetWindowsHookA',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(HHOOK),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(HHOOK));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef BOOL (WINAPI *ShowScrollBar_fun) (HWND hWnd,int wBar,BOOL bShow);
ShowScrollBar_fun pShowScrollBar = ShowScrollBar;
HOOK_TRACE_INFO hHookShowScrollBar = { 0 };
ULONG HookShowScrollBar_ACLEntries[1] = { 0 };
BOOL fake_ShowScrollBar(HWND hWnd,int wBar,BOOL bShow){
	BOOL ret = pShowScrollBar(hWnd,wBar,bShow);
	fprintf(fp,"OUT ['ShowScrollBar',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(BOOL),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(BOOL));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef DWORD (WINAPI *CharLowerBuffW_fun) (LPWSTR lpsz,DWORD cchLength);
CharLowerBuffW_fun pCharLowerBuffW = CharLowerBuffW;
HOOK_TRACE_INFO hHookCharLowerBuffW = { 0 };
ULONG HookCharLowerBuffW_ACLEntries[1] = { 0 };
DWORD fake_CharLowerBuffW(LPWSTR lpsz,DWORD cchLength){
	DWORD ret = pCharLowerBuffW(lpsz,cchLength);
	fprintf(fp,"OUT ['CharLowerBuffW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%x,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(DWORD),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%x, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(DWORD));
	fprintf(fp,"]},");
 	if(1)
	{
		fprintf(fp,"{'name':'lpsz',");
		__try
		{
			WCHAR tmp[100] = { 0 };
			swprintf_s(tmp, L"'value': %p,", lpsz);
			fwprintf(fp, L"%s", tmp);
		}
		__except(1)
		{
			fprintf(fp, "'value': %p,", lpsz);

		}
		fprintf(fp, "'size' : 0x%lx,'cnt':0x%x, 'data':[", sizeof(LPWSTR),cchLength);
 	}else 
	{
		fprintf(fp,"{'name':'lpsz',");
		fwprintf(fp, L"'value': %p, ", lpsz);
		fprintf(fp, "'size' : 0x%lx,'cnt':'undefined', 'data':[",sizeof(LPWSTR));
	}
	if(lpsz){
		for(int i=0; i<cchLength;i++){
			fprintf(fp,"0x%x,",lpsz[i]);
		}
	}
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


typedef ATOM (WINAPI *RegisterClassExW_fun) (CONST WNDCLASSEXW* arg0);
RegisterClassExW_fun pRegisterClassExW = RegisterClassExW;
HOOK_TRACE_INFO hHookRegisterClassExW = { 0 };
ULONG HookRegisterClassExW_ACLEntries[1] = { 0 };
ATOM fake_RegisterClassExW(CONST WNDCLASSEXW* arg0){
	ATOM ret = pRegisterClassExW(arg0);
	fprintf(fp,"OUT ['RegisterClassExW',");
	if(1) fprintf(fp,"{'name':'ret','value': 0x%hx,'size' : 0x%lx,'cnt':0x%x, 'data':[",ret, sizeof(ATOM),1);
 	else fprintf(fp,"{'name':'ret','value': 0x%hx, 'size' : 0x%lx,'cnt':'undefined', 'data':[",ret,sizeof(ATOM));
	fprintf(fp,"]},");
 	fprintf(fp,"]\n");
	fclose(fp);
	ReleaseMutex(g_mutex);
	return ret;
}


void PrepareRealApiEntry()
{
    HMODULE huser32 = LoadLibrary(L"User32.dll");
	pRemoveMenu = (RemoveMenu_fun)GetProcAddress(huser32, "RemoveMenu");
	pAttachThreadInput = (AttachThreadInput_fun)GetProcAddress(huser32, "AttachThreadInput");
	pSetFocus = (SetFocus_fun)GetProcAddress(huser32, "SetFocus");
	pSetCursor = (SetCursor_fun)GetProcAddress(huser32, "SetCursor");
	pChangeDisplaySettingsExA = (ChangeDisplaySettingsExA_fun)GetProcAddress(huser32, "ChangeDisplaySettingsExA");
	pLookupIconIdFromDirectory = (LookupIconIdFromDirectory_fun)GetProcAddress(huser32, "LookupIconIdFromDirectory");
	pIsWindowVisible = (IsWindowVisible_fun)GetProcAddress(huser32, "IsWindowVisible");
	pMenuItemFromPoint = (MenuItemFromPoint_fun)GetProcAddress(huser32, "MenuItemFromPoint");
	pCallNextHookEx = (CallNextHookEx_fun)GetProcAddress(huser32, "CallNextHookEx");
	pShowCaret = (ShowCaret_fun)GetProcAddress(huser32, "ShowCaret");
	pRegisterClassExA = (RegisterClassExA_fun)GetProcAddress(huser32, "RegisterClassExA");
	pSetDlgItemInt = (SetDlgItemInt_fun)GetProcAddress(huser32, "SetDlgItemInt");
	pDefMDIChildProcA = (DefMDIChildProcA_fun)GetProcAddress(huser32, "DefMDIChildProcA");
	pCloseWindow = (CloseWindow_fun)GetProcAddress(huser32, "CloseWindow");
	pSetProcessDefaultLayout = (SetProcessDefaultLayout_fun)GetProcAddress(huser32, "SetProcessDefaultLayout");
	pDrawIcon = (DrawIcon_fun)GetProcAddress(huser32, "DrawIcon");
	pTranslateAcceleratorA = (TranslateAcceleratorA_fun)GetProcAddress(huser32, "TranslateAcceleratorA");
	pGetQueueStatus = (GetQueueStatus_fun)GetProcAddress(huser32, "GetQueueStatus");
	pDestroyWindow = (DestroyWindow_fun)GetProcAddress(huser32, "DestroyWindow");
	pChangeDisplaySettingsExW = (ChangeDisplaySettingsExW_fun)GetProcAddress(huser32, "ChangeDisplaySettingsExW");
	pLoadKeyboardLayoutA = (LoadKeyboardLayoutA_fun)GetProcAddress(huser32, "LoadKeyboardLayoutA");
	pRegisterClassA = (RegisterClassA_fun)GetProcAddress(huser32, "RegisterClassA");
	pCreateIconFromResourceEx = (CreateIconFromResourceEx_fun)GetProcAddress(huser32, "CreateIconFromResourceEx");
	pChangeDisplaySettingsW = (ChangeDisplaySettingsW_fun)GetProcAddress(huser32, "ChangeDisplaySettingsW");
	pSetWindowPos = (SetWindowPos_fun)GetProcAddress(huser32, "SetWindowPos");
	pRegisterTouchWindow = (RegisterTouchWindow_fun)GetProcAddress(huser32, "RegisterTouchWindow");
	pSetPropA = (SetPropA_fun)GetProcAddress(huser32, "SetPropA");
	pGetWindowTextLengthA = (GetWindowTextLengthA_fun)GetProcAddress(huser32, "GetWindowTextLengthA");
	pCreateAcceleratorTableA = (CreateAcceleratorTableA_fun)GetProcAddress(huser32, "CreateAcceleratorTableA");
	pCreateDialogIndirectParamW = (CreateDialogIndirectParamW_fun)GetProcAddress(huser32, "CreateDialogIndirectParamW");
	pActivateKeyboardLayout = (ActivateKeyboardLayout_fun)GetProcAddress(huser32, "ActivateKeyboardLayout");
	pGetWindowLongW = (GetWindowLongW_fun)GetProcAddress(huser32, "GetWindowLongW");
	pGetIconInfo = (GetIconInfo_fun)GetProcAddress(huser32, "GetIconInfo");
	pDispatchMessageW = (DispatchMessageW_fun)GetProcAddress(huser32, "DispatchMessageW");
	pSetCursorPos = (SetCursorPos_fun)GetProcAddress(huser32, "SetCursorPos");
	pCalculatePopupWindowPosition = (CalculatePopupWindowPosition_fun)GetProcAddress(huser32, "CalculatePopupWindowPosition");
	pArrangeIconicWindows = (ArrangeIconicWindows_fun)GetProcAddress(huser32, "ArrangeIconicWindows");
	pCallWindowProcW = (CallWindowProcW_fun)GetProcAddress(huser32, "CallWindowProcW");
	pQueryDisplayConfig = (QueryDisplayConfig_fun)GetProcAddress(huser32, "QueryDisplayConfig");
	pMapVirtualKeyExW = (MapVirtualKeyExW_fun)GetProcAddress(huser32, "MapVirtualKeyExW");
	pSetThreadDesktop = (SetThreadDesktop_fun)GetProcAddress(huser32, "SetThreadDesktop");
	pmouse_event = (mouse_event_fun)GetProcAddress(huser32, "mouse_event");
	pCreatePopupMenu = (CreatePopupMenu_fun)GetProcAddress(huser32, "CreatePopupMenu");
	pShowOwnedPopups = (ShowOwnedPopups_fun)GetProcAddress(huser32, "ShowOwnedPopups");
	pSetScrollRange = (SetScrollRange_fun)GetProcAddress(huser32, "SetScrollRange");
	pEnumWindowStationsA = (EnumWindowStationsA_fun)GetProcAddress(huser32, "EnumWindowStationsA");
	pGetClipCursor = (GetClipCursor_fun)GetProcAddress(huser32, "GetClipCursor");
	pSetClipboardData = (SetClipboardData_fun)GetProcAddress(huser32, "SetClipboardData");
	pGetWindowDisplayAffinity = (GetWindowDisplayAffinity_fun)GetProcAddress(huser32, "GetWindowDisplayAffinity");
	pAppendMenuA = (AppendMenuA_fun)GetProcAddress(huser32, "AppendMenuA");
	pCharToOemBuffW = (CharToOemBuffW_fun)GetProcAddress(huser32, "CharToOemBuffW");
	pOpenDesktopW = (OpenDesktopW_fun)GetProcAddress(huser32, "OpenDesktopW");
	pDefFrameProcA = (DefFrameProcA_fun)GetProcAddress(huser32, "DefFrameProcA");
	pSetSysColors = (SetSysColors_fun)GetProcAddress(huser32, "SetSysColors");
	pDestroyIcon = (DestroyIcon_fun)GetProcAddress(huser32, "DestroyIcon");
	pAdjustWindowRectEx = (AdjustWindowRectEx_fun)GetProcAddress(huser32, "AdjustWindowRectEx");
	pEqualRect = (EqualRect_fun)GetProcAddress(huser32, "EqualRect");
	pGetWindowWord = (GetWindowWord_fun)GetProcAddress(huser32, "GetWindowWord");
	pInternalGetWindowText = (InternalGetWindowText_fun)GetProcAddress(huser32, "InternalGetWindowText");
	pSetWindowTextW = (SetWindowTextW_fun)GetProcAddress(huser32, "SetWindowTextW");
	pGetTabbedTextExtentA = (GetTabbedTextExtentA_fun)GetProcAddress(huser32, "GetTabbedTextExtentA");
	pGetParent = (GetParent_fun)GetProcAddress(huser32, "GetParent");
	pGetIconInfoExW = (GetIconInfoExW_fun)GetProcAddress(huser32, "GetIconInfoExW");
	pChildWindowFromPointEx = (ChildWindowFromPointEx_fun)GetProcAddress(huser32, "ChildWindowFromPointEx");
	pDeferWindowPos = (DeferWindowPos_fun)GetProcAddress(huser32, "DeferWindowPos");
	pMapVirtualKeyExA = (MapVirtualKeyExA_fun)GetProcAddress(huser32, "MapVirtualKeyExA");
	pGetClassNameW = (GetClassNameW_fun)GetProcAddress(huser32, "GetClassNameW");
	pAppendMenuW = (AppendMenuW_fun)GetProcAddress(huser32, "AppendMenuW");
	pLoadImageW = (LoadImageW_fun)GetProcAddress(huser32, "LoadImageW");
	pLoadStringW = (LoadStringW_fun)GetProcAddress(huser32, "LoadStringW");
	pRealChildWindowFromPoint = (RealChildWindowFromPoint_fun)GetProcAddress(huser32, "RealChildWindowFromPoint");
	pCheckRadioButton = (CheckRadioButton_fun)GetProcAddress(huser32, "CheckRadioButton");
	pGetScrollInfo = (GetScrollInfo_fun)GetProcAddress(huser32, "GetScrollInfo");
	pGetKeyNameTextA = (GetKeyNameTextA_fun)GetProcAddress(huser32, "GetKeyNameTextA");
	pGetSysColorBrush = (GetSysColorBrush_fun)GetProcAddress(huser32, "GetSysColorBrush");
	pLoadMenuIndirectW = (LoadMenuIndirectW_fun)GetProcAddress(huser32, "LoadMenuIndirectW");
	pTrackPopupMenuEx = (TrackPopupMenuEx_fun)GetProcAddress(huser32, "TrackPopupMenuEx");
	pSetDoubleClickTime = (SetDoubleClickTime_fun)GetProcAddress(huser32, "SetDoubleClickTime");
	pIsProcessDPIAware = (IsProcessDPIAware_fun)GetProcAddress(huser32, "IsProcessDPIAware");
	pDefFrameProcW = (DefFrameProcW_fun)GetProcAddress(huser32, "DefFrameProcW");
	pVkKeyScanW = (VkKeyScanW_fun)GetProcAddress(huser32, "VkKeyScanW");
	pEnumDisplayMonitors = (EnumDisplayMonitors_fun)GetProcAddress(huser32, "EnumDisplayMonitors");
	pLoadBitmapW = (LoadBitmapW_fun)GetProcAddress(huser32, "LoadBitmapW");
	pHideCaret = (HideCaret_fun)GetProcAddress(huser32, "HideCaret");
	pDrawEdge = (DrawEdge_fun)GetProcAddress(huser32, "DrawEdge");
	pCharUpperBuffA = (CharUpperBuffA_fun)GetProcAddress(huser32, "CharUpperBuffA");
	pSetClassLongPtrW = (SetClassLongPtrW_fun)GetProcAddress(huser32, "SetClassLongPtrW");
	pEnumWindowStationsW = (EnumWindowStationsW_fun)GetProcAddress(huser32, "EnumWindowStationsW");
	pEnumDisplaySettingsExA = (EnumDisplaySettingsExA_fun)GetProcAddress(huser32, "EnumDisplaySettingsExA");
	pGetMenuItemRect = (GetMenuItemRect_fun)GetProcAddress(huser32, "GetMenuItemRect");
	pReplyMessage = (ReplyMessage_fun)GetProcAddress(huser32, "ReplyMessage");
	pAnimateWindow = (AnimateWindow_fun)GetProcAddress(huser32, "AnimateWindow");
	pSendInput = (SendInput_fun)GetProcAddress(huser32, "SendInput");
	pEnableScrollBar = (EnableScrollBar_fun)GetProcAddress(huser32, "EnableScrollBar");
	pGetMenuDefaultItem = (GetMenuDefaultItem_fun)GetProcAddress(huser32, "GetMenuDefaultItem");
	pEnumPropsA = (EnumPropsA_fun)GetProcAddress(huser32, "EnumPropsA");
	pTranslateMessage = (TranslateMessage_fun)GetProcAddress(huser32, "TranslateMessage");
	pCharNextA = (CharNextA_fun)GetProcAddress(huser32, "CharNextA");
	pGetForegroundWindow = (GetForegroundWindow_fun)GetProcAddress(huser32, "GetForegroundWindow");
	pCharLowerA = (CharLowerA_fun)GetProcAddress(huser32, "CharLowerA");
	pIsRectEmpty = (IsRectEmpty_fun)GetProcAddress(huser32, "IsRectEmpty");
	pOpenClipboard = (OpenClipboard_fun)GetProcAddress(huser32, "OpenClipboard");
	pGetKeyboardLayoutList = (GetKeyboardLayoutList_fun)GetProcAddress(huser32, "GetKeyboardLayoutList");
	pCopyIcon = (CopyIcon_fun)GetProcAddress(huser32, "CopyIcon");
	pDlgDirListA = (DlgDirListA_fun)GetProcAddress(huser32, "DlgDirListA");
	pRedrawWindow = (RedrawWindow_fun)GetProcAddress(huser32, "RedrawWindow");
	pEndDialog = (EndDialog_fun)GetProcAddress(huser32, "EndDialog");
	pMessageBeep = (MessageBeep_fun)GetProcAddress(huser32, "MessageBeep");
	pCloseWindowStation = (CloseWindowStation_fun)GetProcAddress(huser32, "CloseWindowStation");
	pGetClassWord = (GetClassWord_fun)GetProcAddress(huser32, "GetClassWord");
	pCreateDesktopExA = (CreateDesktopExA_fun)GetProcAddress(huser32, "CreateDesktopExA");
	pGetSystemMenu = (GetSystemMenu_fun)GetProcAddress(huser32, "GetSystemMenu");
	pRegisterWindowMessageA = (RegisterWindowMessageA_fun)GetProcAddress(huser32, "RegisterWindowMessageA");
	pGetRegisteredRawInputDevices = (GetRegisteredRawInputDevices_fun)GetProcAddress(huser32, "GetRegisteredRawInputDevices");
	pLoadIconW = (LoadIconW_fun)GetProcAddress(huser32, "LoadIconW");
	pGetWindowContextHelpId = (GetWindowContextHelpId_fun)GetProcAddress(huser32, "GetWindowContextHelpId");
	pBroadcastSystemMessageW = (BroadcastSystemMessageW_fun)GetProcAddress(huser32, "BroadcastSystemMessageW");
	pEnumDesktopsW = (EnumDesktopsW_fun)GetProcAddress(huser32, "EnumDesktopsW");
	pSetClassLongPtrA = (SetClassLongPtrA_fun)GetProcAddress(huser32, "SetClassLongPtrA");
	pMsgWaitForMultipleObjectsEx = (MsgWaitForMultipleObjectsEx_fun)GetProcAddress(huser32, "MsgWaitForMultipleObjectsEx");
	pUnregisterTouchWindow = (UnregisterTouchWindow_fun)GetProcAddress(huser32, "UnregisterTouchWindow");
	pGetClassNameA = (GetClassNameA_fun)GetProcAddress(huser32, "GetClassNameA");
	pIsCharAlphaNumericW = (IsCharAlphaNumericW_fun)GetProcAddress(huser32, "IsCharAlphaNumericW");
	pSetUserObjectSecurity = (SetUserObjectSecurity_fun)GetProcAddress(huser32, "SetUserObjectSecurity");
	pEnumDisplaySettingsExW = (EnumDisplaySettingsExW_fun)GetProcAddress(huser32, "EnumDisplaySettingsExW");
	pPaintDesktop = (PaintDesktop_fun)GetProcAddress(huser32, "PaintDesktop");
	pSetLastErrorEx = (SetLastErrorEx_fun)GetProcAddress(huser32, "SetLastErrorEx");
	pIsDialogMessageW = (IsDialogMessageW_fun)GetProcAddress(huser32, "IsDialogMessageW");
	pEnumDisplayDevicesW = (EnumDisplayDevicesW_fun)GetProcAddress(huser32, "EnumDisplayDevicesW");
	pGetPhysicalCursorPos = (GetPhysicalCursorPos_fun)GetProcAddress(huser32, "GetPhysicalCursorPos");
	pGetRawInputDeviceInfoW = (GetRawInputDeviceInfoW_fun)GetProcAddress(huser32, "GetRawInputDeviceInfoW");
	pGetWindowModuleFileNameA = (GetWindowModuleFileNameA_fun)GetProcAddress(huser32, "GetWindowModuleFileNameA");
	pDisableProcessWindowsGhosting = (DisableProcessWindowsGhosting_fun)GetProcAddress(huser32, "DisableProcessWindowsGhosting");
	pSubtractRect = (SubtractRect_fun)GetProcAddress(huser32, "SubtractRect");
	pFlashWindow = (FlashWindow_fun)GetProcAddress(huser32, "FlashWindow");
	pDisplayConfigGetDeviceInfo = (DisplayConfigGetDeviceInfo_fun)GetProcAddress(huser32, "DisplayConfigGetDeviceInfo");
	pSetForegroundWindow = (SetForegroundWindow_fun)GetProcAddress(huser32, "SetForegroundWindow");
	pCreateWindowStationW = (CreateWindowStationW_fun)GetProcAddress(huser32, "CreateWindowStationW");
	pOffsetRect = (OffsetRect_fun)GetProcAddress(huser32, "OffsetRect");
	pDlgDirListComboBoxA = (DlgDirListComboBoxA_fun)GetProcAddress(huser32, "DlgDirListComboBoxA");
	pGetMenuItemInfoW = (GetMenuItemInfoW_fun)GetProcAddress(huser32, "GetMenuItemInfoW");
	pBroadcastSystemMessageExW = (BroadcastSystemMessageExW_fun)GetProcAddress(huser32, "BroadcastSystemMessageExW");
	pGetGestureConfig = (GetGestureConfig_fun)GetProcAddress(huser32, "GetGestureConfig");
	pSwitchDesktop = (SwitchDesktop_fun)GetProcAddress(huser32, "SwitchDesktop");
	pGetNextDlgGroupItem = (GetNextDlgGroupItem_fun)GetProcAddress(huser32, "GetNextDlgGroupItem");
	pMessageBoxIndirectA = (MessageBoxIndirectA_fun)GetProcAddress(huser32, "MessageBoxIndirectA");
	pDestroyCursor = (DestroyCursor_fun)GetProcAddress(huser32, "DestroyCursor");
	pSoundSentry = (SoundSentry_fun)GetProcAddress(huser32, "SoundSentry");
	pCreateAcceleratorTableW = (CreateAcceleratorTableW_fun)GetProcAddress(huser32, "CreateAcceleratorTableW");
	pGetCapture = (GetCapture_fun)GetProcAddress(huser32, "GetCapture");
	pGetDesktopWindow = (GetDesktopWindow_fun)GetProcAddress(huser32, "GetDesktopWindow");
	pSetMessageExtraInfo = (SetMessageExtraInfo_fun)GetProcAddress(huser32, "SetMessageExtraInfo");
	pCreateDesktopW = (CreateDesktopW_fun)GetProcAddress(huser32, "CreateDesktopW");
	pIsWindow = (IsWindow_fun)GetProcAddress(huser32, "IsWindow");
	pOpenDesktopA = (OpenDesktopA_fun)GetProcAddress(huser32, "OpenDesktopA");
	pWinHelpA = (WinHelpA_fun)GetProcAddress(huser32, "WinHelpA");
	pChangeWindowMessageFilterEx = (ChangeWindowMessageFilterEx_fun)GetProcAddress(huser32, "ChangeWindowMessageFilterEx");
	pCloseGestureInfoHandle = (CloseGestureInfoHandle_fun)GetProcAddress(huser32, "CloseGestureInfoHandle");
	pEnumWindows = (EnumWindows_fun)GetProcAddress(huser32, "EnumWindows");
	pCreateCursor = (CreateCursor_fun)GetProcAddress(huser32, "CreateCursor");
	pBeginDeferWindowPos = (BeginDeferWindowPos_fun)GetProcAddress(huser32, "BeginDeferWindowPos");
	pSetWindowDisplayAffinity = (SetWindowDisplayAffinity_fun)GetProcAddress(huser32, "SetWindowDisplayAffinity");
	pScrollDC = (ScrollDC_fun)GetProcAddress(huser32, "ScrollDC");
	pEnumThreadWindows = (EnumThreadWindows_fun)GetProcAddress(huser32, "EnumThreadWindows");
	pBroadcastSystemMessageA = (BroadcastSystemMessageA_fun)GetProcAddress(huser32, "BroadcastSystemMessageA");
	pGetKeyboardType = (GetKeyboardType_fun)GetProcAddress(huser32, "GetKeyboardType");
	pGetClipboardFormatNameW = (GetClipboardFormatNameW_fun)GetProcAddress(huser32, "GetClipboardFormatNameW");
	pIsClipboardFormatAvailable = (IsClipboardFormatAvailable_fun)GetProcAddress(huser32, "IsClipboardFormatAvailable");
	pDialogBoxIndirectParamA = (DialogBoxIndirectParamA_fun)GetProcAddress(huser32, "DialogBoxIndirectParamA");
	pGetMenu = (GetMenu_fun)GetProcAddress(huser32, "GetMenu");
	pGetRawInputBuffer = (GetRawInputBuffer_fun)GetProcAddress(huser32, "GetRawInputBuffer");
	pCountClipboardFormats = (CountClipboardFormats_fun)GetProcAddress(huser32, "CountClipboardFormats");
	pFrameRect = (FrameRect_fun)GetProcAddress(huser32, "FrameRect");
	pEnumPropsW = (EnumPropsW_fun)GetProcAddress(huser32, "EnumPropsW");
	pInSendMessageEx = (InSendMessageEx_fun)GetProcAddress(huser32, "InSendMessageEx");
	pGetLastActivePopup = (GetLastActivePopup_fun)GetProcAddress(huser32, "GetLastActivePopup");
	pPostMessageW = (PostMessageW_fun)GetProcAddress(huser32, "PostMessageW");
	pDrawTextExW = (DrawTextExW_fun)GetProcAddress(huser32, "DrawTextExW");
	pGetMonitorInfoW = (GetMonitorInfoW_fun)GetProcAddress(huser32, "GetMonitorInfoW");
	pMessageBoxW = (MessageBoxW_fun)GetProcAddress(huser32, "MessageBoxW");
	pIsWindowUnicode = (IsWindowUnicode_fun)GetProcAddress(huser32, "IsWindowUnicode");
	pDispatchMessageA = (DispatchMessageA_fun)GetProcAddress(huser32, "DispatchMessageA");
	pPostThreadMessageA = (PostThreadMessageA_fun)GetProcAddress(huser32, "PostThreadMessageA");
	pUnregisterHotKey = (UnregisterHotKey_fun)GetProcAddress(huser32, "UnregisterHotKey");
	pCreateDialogIndirectParamA = (CreateDialogIndirectParamA_fun)GetProcAddress(huser32, "CreateDialogIndirectParamA");
	pOemToCharA = (OemToCharA_fun)GetProcAddress(huser32, "OemToCharA");
	pGetCursorPos = (GetCursorPos_fun)GetProcAddress(huser32, "GetCursorPos");
	pCharUpperBuffW = (CharUpperBuffW_fun)GetProcAddress(huser32, "CharUpperBuffW");
	pGetSystemMetrics = (GetSystemMetrics_fun)GetProcAddress(huser32, "GetSystemMetrics");
	pGetKeyboardState = (GetKeyboardState_fun)GetProcAddress(huser32, "GetKeyboardState");
	pIsWindowEnabled = (IsWindowEnabled_fun)GetProcAddress(huser32, "IsWindowEnabled");
	pSwapMouseButton = (SwapMouseButton_fun)GetProcAddress(huser32, "SwapMouseButton");
	pUnregisterPowerSettingNotification = (UnregisterPowerSettingNotification_fun)GetProcAddress(huser32, "UnregisterPowerSettingNotification");
	pInsertMenuItemA = (InsertMenuItemA_fun)GetProcAddress(huser32, "InsertMenuItemA");
	pUpdateLayeredWindow = (UpdateLayeredWindow_fun)GetProcAddress(huser32, "UpdateLayeredWindow");
	pGetCursor = (GetCursor_fun)GetProcAddress(huser32, "GetCursor");
	pSetWindowLongW = (SetWindowLongW_fun)GetProcAddress(huser32, "SetWindowLongW");
	pSetWindowsHookExA = (SetWindowsHookExA_fun)GetProcAddress(huser32, "SetWindowsHookExA");
	pCancelShutdown = (CancelShutdown_fun)GetProcAddress(huser32, "CancelShutdown");
	pSetWindowsHookExW = (SetWindowsHookExW_fun)GetProcAddress(huser32, "SetWindowsHookExW");
	pSetWindowLongPtrW = (SetWindowLongPtrW_fun)GetProcAddress(huser32, "SetWindowLongPtrW");
	pCopyAcceleratorTableA = (CopyAcceleratorTableA_fun)GetProcAddress(huser32, "CopyAcceleratorTableA");
	pWindowFromDC = (WindowFromDC_fun)GetProcAddress(huser32, "WindowFromDC");
	pGetClipboardData = (GetClipboardData_fun)GetProcAddress(huser32, "GetClipboardData");
	pCreateDesktopA = (CreateDesktopA_fun)GetProcAddress(huser32, "CreateDesktopA");
	pCreateDialogParamW = (CreateDialogParamW_fun)GetProcAddress(huser32, "CreateDialogParamW");
	pSystemParametersInfoW = (SystemParametersInfoW_fun)GetProcAddress(huser32, "SystemParametersInfoW");
	pVkKeyScanExW = (VkKeyScanExW_fun)GetProcAddress(huser32, "VkKeyScanExW");
	pLoadStringA = (LoadStringA_fun)GetProcAddress(huser32, "LoadStringA");
	pEnumDisplaySettingsA = (EnumDisplaySettingsA_fun)GetProcAddress(huser32, "EnumDisplaySettingsA");
	pGetPriorityClipboardFormat = (GetPriorityClipboardFormat_fun)GetProcAddress(huser32, "GetPriorityClipboardFormat");
	pSetMenuDefaultItem = (SetMenuDefaultItem_fun)GetProcAddress(huser32, "SetMenuDefaultItem");
	pGetDoubleClickTime = (GetDoubleClickTime_fun)GetProcAddress(huser32, "GetDoubleClickTime");
	pEnableMenuItem = (EnableMenuItem_fun)GetProcAddress(huser32, "EnableMenuItem");
	pPhysicalToLogicalPoint = (PhysicalToLogicalPoint_fun)GetProcAddress(huser32, "PhysicalToLogicalPoint");
	pDlgDirListW = (DlgDirListW_fun)GetProcAddress(huser32, "DlgDirListW");
	pDrawStateA = (DrawStateA_fun)GetProcAddress(huser32, "DrawStateA");
	pGetMenuState = (GetMenuState_fun)GetProcAddress(huser32, "GetMenuState");
	pDefRawInputProc = (DefRawInputProc_fun)GetProcAddress(huser32, "DefRawInputProc");
	pInvalidateRgn = (InvalidateRgn_fun)GetProcAddress(huser32, "InvalidateRgn");
	pInsertMenuItemW = (InsertMenuItemW_fun)GetProcAddress(huser32, "InsertMenuItemW");
	pGetRawInputDeviceInfoA = (GetRawInputDeviceInfoA_fun)GetProcAddress(huser32, "GetRawInputDeviceInfoA");
	pGetTitleBarInfo = (GetTitleBarInfo_fun)GetProcAddress(huser32, "GetTitleBarInfo");
	pIsCharAlphaW = (IsCharAlphaW_fun)GetProcAddress(huser32, "IsCharAlphaW");
	pToAscii = (ToAscii_fun)GetProcAddress(huser32, "ToAscii");
	pLoadMenuA = (LoadMenuA_fun)GetProcAddress(huser32, "LoadMenuA");
	pEndDeferWindowPos = (EndDeferWindowPos_fun)GetProcAddress(huser32, "EndDeferWindowPos");
	pIsZoomed = (IsZoomed_fun)GetProcAddress(huser32, "IsZoomed");
	pCreateIconIndirect = (CreateIconIndirect_fun)GetProcAddress(huser32, "CreateIconIndirect");
	pReleaseCapture = (ReleaseCapture_fun)GetProcAddress(huser32, "ReleaseCapture");
	pGetTopWindow = (GetTopWindow_fun)GetProcAddress(huser32, "GetTopWindow");
	pCheckMenuRadioItem = (CheckMenuRadioItem_fun)GetProcAddress(huser32, "CheckMenuRadioItem");
	pClipCursor = (ClipCursor_fun)GetProcAddress(huser32, "ClipCursor");
	pIsMenu = (IsMenu_fun)GetProcAddress(huser32, "IsMenu");
	pGetGestureExtraArgs = (GetGestureExtraArgs_fun)GetProcAddress(huser32, "GetGestureExtraArgs");
	pGetMenuItemInfoA = (GetMenuItemInfoA_fun)GetProcAddress(huser32, "GetMenuItemInfoA");
	pIsCharLowerA = (IsCharLowerA_fun)GetProcAddress(huser32, "IsCharLowerA");
	pSendMessageW = (SendMessageW_fun)GetProcAddress(huser32, "SendMessageW");
	pGetMonitorInfoA = (GetMonitorInfoA_fun)GetProcAddress(huser32, "GetMonitorInfoA");
	pGetAltTabInfoW = (GetAltTabInfoW_fun)GetProcAddress(huser32, "GetAltTabInfoW");
	pGrayStringA = (GrayStringA_fun)GetProcAddress(huser32, "GrayStringA");
	pSendMessageCallbackW = (SendMessageCallbackW_fun)GetProcAddress(huser32, "SendMessageCallbackW");
	pGetRawInputData = (GetRawInputData_fun)GetProcAddress(huser32, "GetRawInputData");
	pGetClipboardFormatNameA = (GetClipboardFormatNameA_fun)GetProcAddress(huser32, "GetClipboardFormatNameA");
	pGetWindow = (GetWindow_fun)GetProcAddress(huser32, "GetWindow");
	pExitWindowsEx = (ExitWindowsEx_fun)GetProcAddress(huser32, "ExitWindowsEx");
	pGetClipboardSequenceNumber = (GetClipboardSequenceNumber_fun)GetProcAddress(huser32, "GetClipboardSequenceNumber");
	pOemToCharBuffA = (OemToCharBuffA_fun)GetProcAddress(huser32, "OemToCharBuffA");
	pUserHandleGrantAccess = (UserHandleGrantAccess_fun)GetProcAddress(huser32, "UserHandleGrantAccess");
	pScrollWindow = (ScrollWindow_fun)GetProcAddress(huser32, "ScrollWindow");
	pSetSystemCursor = (SetSystemCursor_fun)GetProcAddress(huser32, "SetSystemCursor");
	pGetOpenClipboardWindow = (GetOpenClipboardWindow_fun)GetProcAddress(huser32, "GetOpenClipboardWindow");
	pSetClassLongA = (SetClassLongA_fun)GetProcAddress(huser32, "SetClassLongA");
	pIsCharAlphaNumericA = (IsCharAlphaNumericA_fun)GetProcAddress(huser32, "IsCharAlphaNumericA");
	pGetMouseMovePointsEx = (GetMouseMovePointsEx_fun)GetProcAddress(huser32, "GetMouseMovePointsEx");
	pGetMenuItemID = (GetMenuItemID_fun)GetProcAddress(huser32, "GetMenuItemID");
	pCheckMenuItem = (CheckMenuItem_fun)GetProcAddress(huser32, "CheckMenuItem");
	pGetClipboardViewer = (GetClipboardViewer_fun)GetProcAddress(huser32, "GetClipboardViewer");
	pGetActiveWindow = (GetActiveWindow_fun)GetProcAddress(huser32, "GetActiveWindow");
	pSetProcessDPIAware = (SetProcessDPIAware_fun)GetProcAddress(huser32, "SetProcessDPIAware");
	pSetScrollInfo = (SetScrollInfo_fun)GetProcAddress(huser32, "SetScrollInfo");
	pMapVirtualKeyW = (MapVirtualKeyW_fun)GetProcAddress(huser32, "MapVirtualKeyW");
	pGetMessageW = (GetMessageW_fun)GetProcAddress(huser32, "GetMessageW");
	pSetWindowContextHelpId = (SetWindowContextHelpId_fun)GetProcAddress(huser32, "SetWindowContextHelpId");
	pGetMessageA = (GetMessageA_fun)GetProcAddress(huser32, "GetMessageA");
	pSystemParametersInfoA = (SystemParametersInfoA_fun)GetProcAddress(huser32, "SystemParametersInfoA");
	pLoadMenuIndirectA = (LoadMenuIndirectA_fun)GetProcAddress(huser32, "LoadMenuIndirectA");
	pGetClassInfoExW = (GetClassInfoExW_fun)GetProcAddress(huser32, "GetClassInfoExW");
	pEnumPropsExA = (EnumPropsExA_fun)GetProcAddress(huser32, "EnumPropsExA");
	pLoadMenuW = (LoadMenuW_fun)GetProcAddress(huser32, "LoadMenuW");
	pInsertMenuW = (InsertMenuW_fun)GetProcAddress(huser32, "InsertMenuW");
	pSetDlgItemTextA = (SetDlgItemTextA_fun)GetProcAddress(huser32, "SetDlgItemTextA");
	pFindWindowExA = (FindWindowExA_fun)GetProcAddress(huser32, "FindWindowExA");
	pSendDlgItemMessageW = (SendDlgItemMessageW_fun)GetProcAddress(huser32, "SendDlgItemMessageW");
	pGetTouchInputInfo = (GetTouchInputInfo_fun)GetProcAddress(huser32, "GetTouchInputInfo");
	pSendMessageTimeoutA = (SendMessageTimeoutA_fun)GetProcAddress(huser32, "SendMessageTimeoutA");
	pSetMenuItemBitmaps = (SetMenuItemBitmaps_fun)GetProcAddress(huser32, "SetMenuItemBitmaps");
	pSetDebugErrorLevel = (SetDebugErrorLevel_fun)GetProcAddress(huser32, "SetDebugErrorLevel");
	pUnregisterClassA = (UnregisterClassA_fun)GetProcAddress(huser32, "UnregisterClassA");
	pGetCaretBlinkTime = (GetCaretBlinkTime_fun)GetProcAddress(huser32, "GetCaretBlinkTime");
	pCreateMDIWindowW = (CreateMDIWindowW_fun)GetProcAddress(huser32, "CreateMDIWindowW");
	pOpenIcon = (OpenIcon_fun)GetProcAddress(huser32, "OpenIcon");
	pRegisterDeviceNotificationW = (RegisterDeviceNotificationW_fun)GetProcAddress(huser32, "RegisterDeviceNotificationW");
	pGetAsyncKeyState = (GetAsyncKeyState_fun)GetProcAddress(huser32, "GetAsyncKeyState");
	pGetWindowInfo = (GetWindowInfo_fun)GetProcAddress(huser32, "GetWindowInfo");
	pIsCharAlphaA = (IsCharAlphaA_fun)GetProcAddress(huser32, "IsCharAlphaA");
	pSetParent = (SetParent_fun)GetProcAddress(huser32, "SetParent");
	pDrawFocusRect = (DrawFocusRect_fun)GetProcAddress(huser32, "DrawFocusRect");
	pToUnicode = (ToUnicode_fun)GetProcAddress(huser32, "ToUnicode");
	pMessageBoxExA = (MessageBoxExA_fun)GetProcAddress(huser32, "MessageBoxExA");
	pBringWindowToTop = (BringWindowToTop_fun)GetProcAddress(huser32, "BringWindowToTop");
	pCreateMDIWindowA = (CreateMDIWindowA_fun)GetProcAddress(huser32, "CreateMDIWindowA");
	pShowCursor = (ShowCursor_fun)GetProcAddress(huser32, "ShowCursor");
	pPrintWindow = (PrintWindow_fun)GetProcAddress(huser32, "PrintWindow");
	pGetWindowLongPtrA = (GetWindowLongPtrA_fun)GetProcAddress(huser32, "GetWindowLongPtrA");
	pModifyMenuA = (ModifyMenuA_fun)GetProcAddress(huser32, "ModifyMenuA");
	pRegisterClipboardFormatW = (RegisterClipboardFormatW_fun)GetProcAddress(huser32, "RegisterClipboardFormatW");
	pMsgWaitForMultipleObjects = (MsgWaitForMultipleObjects_fun)GetProcAddress(huser32, "MsgWaitForMultipleObjects");
	pRegisterShellHookWindow = (RegisterShellHookWindow_fun)GetProcAddress(huser32, "RegisterShellHookWindow");
	pGetMenuStringA = (GetMenuStringA_fun)GetProcAddress(huser32, "GetMenuStringA");
	pPeekMessageW = (PeekMessageW_fun)GetProcAddress(huser32, "PeekMessageW");
	pGetClassInfoA = (GetClassInfoA_fun)GetProcAddress(huser32, "GetClassInfoA");
	pValidateRect = (ValidateRect_fun)GetProcAddress(huser32, "ValidateRect");
	pInflateRect = (InflateRect_fun)GetProcAddress(huser32, "InflateRect");
	pSendMessageTimeoutW = (SendMessageTimeoutW_fun)GetProcAddress(huser32, "SendMessageTimeoutW");
	pEnumDesktopsA = (EnumDesktopsA_fun)GetProcAddress(huser32, "EnumDesktopsA");
	pRegisterDeviceNotificationA = (RegisterDeviceNotificationA_fun)GetProcAddress(huser32, "RegisterDeviceNotificationA");
	pGetMessageTime = (GetMessageTime_fun)GetProcAddress(huser32, "GetMessageTime");
	pEndMenu = (EndMenu_fun)GetProcAddress(huser32, "EndMenu");
	pBeginPaint = (BeginPaint_fun)GetProcAddress(huser32, "BeginPaint");
	pSetRectEmpty = (SetRectEmpty_fun)GetProcAddress(huser32, "SetRectEmpty");
	pTabbedTextOutW = (TabbedTextOutW_fun)GetProcAddress(huser32, "TabbedTextOutW");
	pInSendMessage = (InSendMessage_fun)GetProcAddress(huser32, "InSendMessage");
	pGetWindowDC = (GetWindowDC_fun)GetProcAddress(huser32, "GetWindowDC");
	pFindWindowA = (FindWindowA_fun)GetProcAddress(huser32, "FindWindowA");
	pDlgDirSelectComboBoxExW = (DlgDirSelectComboBoxExW_fun)GetProcAddress(huser32, "DlgDirSelectComboBoxExW");
	pSendNotifyMessageA = (SendNotifyMessageA_fun)GetProcAddress(huser32, "SendNotifyMessageA");
	pDrawTextExA = (DrawTextExA_fun)GetProcAddress(huser32, "DrawTextExA");
	pRegisterPowerSettingNotification = (RegisterPowerSettingNotification_fun)GetProcAddress(huser32, "RegisterPowerSettingNotification");
	pGetMenuContextHelpId = (GetMenuContextHelpId_fun)GetProcAddress(huser32, "GetMenuContextHelpId");
	pGetListBoxInfo = (GetListBoxInfo_fun)GetProcAddress(huser32, "GetListBoxInfo");
	pSetRect = (SetRect_fun)GetProcAddress(huser32, "SetRect");
	pGetRawInputDeviceList = (GetRawInputDeviceList_fun)GetProcAddress(huser32, "GetRawInputDeviceList");
	pSetMessageQueue = (SetMessageQueue_fun)GetProcAddress(huser32, "SetMessageQueue");
	pGetClassLongA = (GetClassLongA_fun)GetProcAddress(huser32, "GetClassLongA");
	pFlashWindowEx = (FlashWindowEx_fun)GetProcAddress(huser32, "FlashWindowEx");
	pGetDC = (GetDC_fun)GetProcAddress(huser32, "GetDC");
	pSetMenuItemInfoW = (SetMenuItemInfoW_fun)GetProcAddress(huser32, "SetMenuItemInfoW");
	pGetDCEx = (GetDCEx_fun)GetProcAddress(huser32, "GetDCEx");
	pGetWindowLongPtrW = (GetWindowLongPtrW_fun)GetProcAddress(huser32, "GetWindowLongPtrW");
	pGetLayeredWindowAttributes = (GetLayeredWindowAttributes_fun)GetProcAddress(huser32, "GetLayeredWindowAttributes");
	pReleaseDC = (ReleaseDC_fun)GetProcAddress(huser32, "ReleaseDC");
	pRegisterClassW = (RegisterClassW_fun)GetProcAddress(huser32, "RegisterClassW");
	pGetWindowTextW = (GetWindowTextW_fun)GetProcAddress(huser32, "GetWindowTextW");
	pCreateWindowStationA = (CreateWindowStationA_fun)GetProcAddress(huser32, "CreateWindowStationA");
	pDrawAnimatedRects = (DrawAnimatedRects_fun)GetProcAddress(huser32, "DrawAnimatedRects");
	pFillRect = (FillRect_fun)GetProcAddress(huser32, "FillRect");
	pGetDlgItem = (GetDlgItem_fun)GetProcAddress(huser32, "GetDlgItem");
	pEnumPropsExW = (EnumPropsExW_fun)GetProcAddress(huser32, "EnumPropsExW");
	pGetFocus = (GetFocus_fun)GetProcAddress(huser32, "GetFocus");
	pGetKeyboardLayoutNameW = (GetKeyboardLayoutNameW_fun)GetProcAddress(huser32, "GetKeyboardLayoutNameW");
	pLockWindowUpdate = (LockWindowUpdate_fun)GetProcAddress(huser32, "LockWindowUpdate");
	pGetWindowRect = (GetWindowRect_fun)GetProcAddress(huser32, "GetWindowRect");
	pShowWindowAsync = (ShowWindowAsync_fun)GetProcAddress(huser32, "ShowWindowAsync");
	pPrivateExtractIconsA = (PrivateExtractIconsA_fun)GetProcAddress(huser32, "PrivateExtractIconsA");
	pLoadCursorA = (LoadCursorA_fun)GetProcAddress(huser32, "LoadCursorA");
	pCreateWindowExW = (CreateWindowExW_fun)GetProcAddress(huser32, "CreateWindowExW");
	pCharLowerW = (CharLowerW_fun)GetProcAddress(huser32, "CharLowerW");
	pCreateDialogParamA = (CreateDialogParamA_fun)GetProcAddress(huser32, "CreateDialogParamA");
	pMonitorFromWindow = (MonitorFromWindow_fun)GetProcAddress(huser32, "MonitorFromWindow");
	pMonitorFromPoint = (MonitorFromPoint_fun)GetProcAddress(huser32, "MonitorFromPoint");
	pSetActiveWindow = (SetActiveWindow_fun)GetProcAddress(huser32, "SetActiveWindow");
	pLoadCursorFromFileW = (LoadCursorFromFileW_fun)GetProcAddress(huser32, "LoadCursorFromFileW");
	pChangeWindowMessageFilter = (ChangeWindowMessageFilter_fun)GetProcAddress(huser32, "ChangeWindowMessageFilter");
	pGetGestureInfo = (GetGestureInfo_fun)GetProcAddress(huser32, "GetGestureInfo");
	pSetWindowRgn = (SetWindowRgn_fun)GetProcAddress(huser32, "SetWindowRgn");
	pSetWindowsHookW = (SetWindowsHookW_fun)GetProcAddress(huser32, "SetWindowsHookW");
	pInsertMenuA = (InsertMenuA_fun)GetProcAddress(huser32, "InsertMenuA");
	pLoadCursorFromFileA = (LoadCursorFromFileA_fun)GetProcAddress(huser32, "LoadCursorFromFileA");
	pCreateIcon = (CreateIcon_fun)GetProcAddress(huser32, "CreateIcon");
	pDestroyAcceleratorTable = (DestroyAcceleratorTable_fun)GetProcAddress(huser32, "DestroyAcceleratorTable");
	pRegisterClipboardFormatA = (RegisterClipboardFormatA_fun)GetProcAddress(huser32, "RegisterClipboardFormatA");
	pBlockInput = (BlockInput_fun)GetProcAddress(huser32, "BlockInput");
	pGetCursorInfo = (GetCursorInfo_fun)GetProcAddress(huser32, "GetCursorInfo");
	pCloseDesktop = (CloseDesktop_fun)GetProcAddress(huser32, "CloseDesktop");
	pUnloadKeyboardLayout = (UnloadKeyboardLayout_fun)GetProcAddress(huser32, "UnloadKeyboardLayout");
	pSetWindowLongA = (SetWindowLongA_fun)GetProcAddress(huser32, "SetWindowLongA");
	pGetDlgItemTextA = (GetDlgItemTextA_fun)GetProcAddress(huser32, "GetDlgItemTextA");
	pCreateCaret = (CreateCaret_fun)GetProcAddress(huser32, "CreateCaret");
	pGetKeyboardLayoutNameA = (GetKeyboardLayoutNameA_fun)GetProcAddress(huser32, "GetKeyboardLayoutNameA");
	pGetScrollBarInfo = (GetScrollBarInfo_fun)GetProcAddress(huser32, "GetScrollBarInfo");
	pTileWindows = (TileWindows_fun)GetProcAddress(huser32, "TileWindows");
	pUnregisterClassW = (UnregisterClassW_fun)GetProcAddress(huser32, "UnregisterClassW");
	pPostQuitMessage = (PostQuitMessage_fun)GetProcAddress(huser32, "PostQuitMessage");
	pGrayStringW = (GrayStringW_fun)GetProcAddress(huser32, "GrayStringW");
	pLoadKeyboardLayoutW = (LoadKeyboardLayoutW_fun)GetProcAddress(huser32, "LoadKeyboardLayoutW");
	pWindowFromPoint = (WindowFromPoint_fun)GetProcAddress(huser32, "WindowFromPoint");
	pGetKeyState = (GetKeyState_fun)GetProcAddress(huser32, "GetKeyState");
	pSetCaretBlinkTime = (SetCaretBlinkTime_fun)GetProcAddress(huser32, "SetCaretBlinkTime");
	pNotifyWinEvent = (NotifyWinEvent_fun)GetProcAddress(huser32, "NotifyWinEvent");
	pGetCaretPos = (GetCaretPos_fun)GetProcAddress(huser32, "GetCaretPos");
	pSetCaretPos = (SetCaretPos_fun)GetProcAddress(huser32, "SetCaretPos");
	pSetDisplayConfig = (SetDisplayConfig_fun)GetProcAddress(huser32, "SetDisplayConfig");
	pGetAncestor = (GetAncestor_fun)GetProcAddress(huser32, "GetAncestor");
	pExcludeUpdateRgn = (ExcludeUpdateRgn_fun)GetProcAddress(huser32, "ExcludeUpdateRgn");
	pOemKeyScan = (OemKeyScan_fun)GetProcAddress(huser32, "OemKeyScan");
	pCallWindowProcA = (CallWindowProcA_fun)GetProcAddress(huser32, "CallWindowProcA");
	pGetWindowLongA = (GetWindowLongA_fun)GetProcAddress(huser32, "GetWindowLongA");
	pGetScrollRange = (GetScrollRange_fun)GetProcAddress(huser32, "GetScrollRange");
	pTranslateAcceleratorW = (TranslateAcceleratorW_fun)GetProcAddress(huser32, "TranslateAcceleratorW");
	pLoadImageA = (LoadImageA_fun)GetProcAddress(huser32, "LoadImageA");
	pDrawTextA = (DrawTextA_fun)GetProcAddress(huser32, "DrawTextA");
	pSetWindowTextA = (SetWindowTextA_fun)GetProcAddress(huser32, "SetWindowTextA");
	pGetTabbedTextExtentW = (GetTabbedTextExtentW_fun)GetProcAddress(huser32, "GetTabbedTextExtentW");
	pOpenInputDesktop = (OpenInputDesktop_fun)GetProcAddress(huser32, "OpenInputDesktop");
	pGetShellWindow = (GetShellWindow_fun)GetProcAddress(huser32, "GetShellWindow");
	pGetMenuStringW = (GetMenuStringW_fun)GetProcAddress(huser32, "GetMenuStringW");
	pGetUpdateRgn = (GetUpdateRgn_fun)GetProcAddress(huser32, "GetUpdateRgn");
	pGetDlgCtrlID = (GetDlgCtrlID_fun)GetProcAddress(huser32, "GetDlgCtrlID");
	pValidateRgn = (ValidateRgn_fun)GetProcAddress(huser32, "ValidateRgn");
	pCopyRect = (CopyRect_fun)GetProcAddress(huser32, "CopyRect");
	pSendMessageA = (SendMessageA_fun)GetProcAddress(huser32, "SendMessageA");
	pAddClipboardFormatListener = (AddClipboardFormatListener_fun)GetProcAddress(huser32, "AddClipboardFormatListener");
	pOpenWindowStationA = (OpenWindowStationA_fun)GetProcAddress(huser32, "OpenWindowStationA");
	pGetDialogBaseUnits = (GetDialogBaseUnits_fun)GetProcAddress(huser32, "GetDialogBaseUnits");
	pDrawCaption = (DrawCaption_fun)GetProcAddress(huser32, "DrawCaption");
	pGetWindowTextLengthW = (GetWindowTextLengthW_fun)GetProcAddress(huser32, "GetWindowTextLengthW");
	pGetDisplayConfigBufferSizes = (GetDisplayConfigBufferSizes_fun)GetProcAddress(huser32, "GetDisplayConfigBufferSizes");
	pRegisterHotKey = (RegisterHotKey_fun)GetProcAddress(huser32, "RegisterHotKey");
	pGetClassInfoW = (GetClassInfoW_fun)GetProcAddress(huser32, "GetClassInfoW");
	pEnumChildWindows = (EnumChildWindows_fun)GetProcAddress(huser32, "EnumChildWindows");
	pCharPrevA = (CharPrevA_fun)GetProcAddress(huser32, "CharPrevA");
	pGetProcessWindowStation = (GetProcessWindowStation_fun)GetProcAddress(huser32, "GetProcessWindowStation");
	pMapVirtualKeyA = (MapVirtualKeyA_fun)GetProcAddress(huser32, "MapVirtualKeyA");
	pUnhookWindowsHook = (UnhookWindowsHook_fun)GetProcAddress(huser32, "UnhookWindowsHook");
	pCharToOemBuffA = (CharToOemBuffA_fun)GetProcAddress(huser32, "CharToOemBuffA");
	pMapWindowPoints = (MapWindowPoints_fun)GetProcAddress(huser32, "MapWindowPoints");
	pCharUpperW = (CharUpperW_fun)GetProcAddress(huser32, "CharUpperW");
	pWaitForInputIdle = (WaitForInputIdle_fun)GetProcAddress(huser32, "WaitForInputIdle");
	pMessageBoxA = (MessageBoxA_fun)GetProcAddress(huser32, "MessageBoxA");
	pSendNotifyMessageW = (SendNotifyMessageW_fun)GetProcAddress(huser32, "SendNotifyMessageW");
	pFindWindowW = (FindWindowW_fun)GetProcAddress(huser32, "FindWindowW");
	pCallMsgFilterW = (CallMsgFilterW_fun)GetProcAddress(huser32, "CallMsgFilterW");
	pRegisterRawInputDevices = (RegisterRawInputDevices_fun)GetProcAddress(huser32, "RegisterRawInputDevices");
	pGetSubMenu = (GetSubMenu_fun)GetProcAddress(huser32, "GetSubMenu");
	pVkKeyScanExA = (VkKeyScanExA_fun)GetProcAddress(huser32, "VkKeyScanExA");
	pGetUpdateRect = (GetUpdateRect_fun)GetProcAddress(huser32, "GetUpdateRect");
	pDrawStateW = (DrawStateW_fun)GetProcAddress(huser32, "DrawStateW");
	pGetClassLongPtrA = (GetClassLongPtrA_fun)GetProcAddress(huser32, "GetClassLongPtrA");
	pTrackMouseEvent = (TrackMouseEvent_fun)GetProcAddress(huser32, "TrackMouseEvent");
	pSetKeyboardState = (SetKeyboardState_fun)GetProcAddress(huser32, "SetKeyboardState");
	pUpdateWindow = (UpdateWindow_fun)GetProcAddress(huser32, "UpdateWindow");
	pChildWindowFromPoint = (ChildWindowFromPoint_fun)GetProcAddress(huser32, "ChildWindowFromPoint");
	pScrollWindowEx = (ScrollWindowEx_fun)GetProcAddress(huser32, "ScrollWindowEx");
	pGetMessagePos = (GetMessagePos_fun)GetProcAddress(huser32, "GetMessagePos");
	pMapDialogRect = (MapDialogRect_fun)GetProcAddress(huser32, "MapDialogRect");
	pChangeClipboardChain = (ChangeClipboardChain_fun)GetProcAddress(huser32, "ChangeClipboardChain");
	pLoadBitmapA = (LoadBitmapA_fun)GetProcAddress(huser32, "LoadBitmapA");
	pCascadeWindows = (CascadeWindows_fun)GetProcAddress(huser32, "CascadeWindows");
	pGetThreadDesktop = (GetThreadDesktop_fun)GetProcAddress(huser32, "GetThreadDesktop");
	pGetUpdatedClipboardFormats = (GetUpdatedClipboardFormats_fun)GetProcAddress(huser32, "GetUpdatedClipboardFormats");
	pShutdownBlockReasonCreate = (ShutdownBlockReasonCreate_fun)GetProcAddress(huser32, "ShutdownBlockReasonCreate");
	pGetKBCodePage = (GetKBCodePage_fun)GetProcAddress(huser32, "GetKBCodePage");
	pEnumClipboardFormats = (EnumClipboardFormats_fun)GetProcAddress(huser32, "EnumClipboardFormats");
	pLoadIconA = (LoadIconA_fun)GetProcAddress(huser32, "LoadIconA");
	pInvertRect = (InvertRect_fun)GetProcAddress(huser32, "InvertRect");
	pEndPaint = (EndPaint_fun)GetProcAddress(huser32, "EndPaint");
	pShutdownBlockReasonDestroy = (ShutdownBlockReasonDestroy_fun)GetProcAddress(huser32, "ShutdownBlockReasonDestroy");
	pAdjustWindowRect = (AdjustWindowRect_fun)GetProcAddress(huser32, "AdjustWindowRect");
	pWindowFromPhysicalPoint = (WindowFromPhysicalPoint_fun)GetProcAddress(huser32, "WindowFromPhysicalPoint");
	pGetGuiResources = (GetGuiResources_fun)GetProcAddress(huser32, "GetGuiResources");
	pRegisterWindowMessageW = (RegisterWindowMessageW_fun)GetProcAddress(huser32, "RegisterWindowMessageW");
	pIsDlgButtonChecked = (IsDlgButtonChecked_fun)GetProcAddress(huser32, "IsDlgButtonChecked");
	pRemoveClipboardFormatListener = (RemoveClipboardFormatListener_fun)GetProcAddress(huser32, "RemoveClipboardFormatListener");
	pGetWindowRgn = (GetWindowRgn_fun)GetProcAddress(huser32, "GetWindowRgn");
	pGetAltTabInfoA = (GetAltTabInfoA_fun)GetProcAddress(huser32, "GetAltTabInfoA");
	pCharUpperA = (CharUpperA_fun)GetProcAddress(huser32, "CharUpperA");
	pIsWow64Message = (IsWow64Message_fun)GetProcAddress(huser32, "IsWow64Message");
	pSetMenuContextHelpId = (SetMenuContextHelpId_fun)GetProcAddress(huser32, "SetMenuContextHelpId");
	pIsIconic = (IsIconic_fun)GetProcAddress(huser32, "IsIconic");
	pSetGestureConfig = (SetGestureConfig_fun)GetProcAddress(huser32, "SetGestureConfig");
	pSendDlgItemMessageA = (SendDlgItemMessageA_fun)GetProcAddress(huser32, "SendDlgItemMessageA");
	pTabbedTextOutA = (TabbedTextOutA_fun)GetProcAddress(huser32, "TabbedTextOutA");
	pSetMenu = (SetMenu_fun)GetProcAddress(huser32, "SetMenu");
	pMonitorFromRect = (MonitorFromRect_fun)GetProcAddress(huser32, "MonitorFromRect");
	pUnionRect = (UnionRect_fun)GetProcAddress(huser32, "UnionRect");
	pPostThreadMessageW = (PostThreadMessageW_fun)GetProcAddress(huser32, "PostThreadMessageW");
	pGetUserObjectInformationA = (GetUserObjectInformationA_fun)GetProcAddress(huser32, "GetUserObjectInformationA");
	pChangeMenuW = (ChangeMenuW_fun)GetProcAddress(huser32, "ChangeMenuW");
	pRemovePropA = (RemovePropA_fun)GetProcAddress(huser32, "RemovePropA");
	pGetClientRect = (GetClientRect_fun)GetProcAddress(huser32, "GetClientRect");
	pKillTimer = (KillTimer_fun)GetProcAddress(huser32, "KillTimer");
	pIsHungAppWindow = (IsHungAppWindow_fun)GetProcAddress(huser32, "IsHungAppWindow");
	pHiliteMenuItem = (HiliteMenuItem_fun)GetProcAddress(huser32, "HiliteMenuItem");
	pPeekMessageA = (PeekMessageA_fun)GetProcAddress(huser32, "PeekMessageA");
	pSetDlgItemTextW = (SetDlgItemTextW_fun)GetProcAddress(huser32, "SetDlgItemTextW");
	pDialogBoxIndirectParamW = (DialogBoxIndirectParamW_fun)GetProcAddress(huser32, "DialogBoxIndirectParamW");
	pGetScrollPos = (GetScrollPos_fun)GetProcAddress(huser32, "GetScrollPos");
	pSetClassWord = (SetClassWord_fun)GetProcAddress(huser32, "SetClassWord");
	pCloseClipboard = (CloseClipboard_fun)GetProcAddress(huser32, "CloseClipboard");
	pWaitMessage = (WaitMessage_fun)GetProcAddress(huser32, "WaitMessage");
	pLoadAcceleratorsW = (LoadAcceleratorsW_fun)GetProcAddress(huser32, "LoadAcceleratorsW");
	pEnableWindow = (EnableWindow_fun)GetProcAddress(huser32, "EnableWindow");
	pCreateIconFromResource = (CreateIconFromResource_fun)GetProcAddress(huser32, "CreateIconFromResource");
	pDlgDirListComboBoxW = (DlgDirListComboBoxW_fun)GetProcAddress(huser32, "DlgDirListComboBoxW");
	pIsTouchWindow = (IsTouchWindow_fun)GetProcAddress(huser32, "IsTouchWindow");
	pIsChild = (IsChild_fun)GetProcAddress(huser32, "IsChild");
	pEmptyClipboard = (EmptyClipboard_fun)GetProcAddress(huser32, "EmptyClipboard");
	pGetLastInputInfo = (GetLastInputInfo_fun)GetProcAddress(huser32, "GetLastInputInfo");
	pPostMessageA = (PostMessageA_fun)GetProcAddress(huser32, "PostMessageA");
	pDestroyMenu = (DestroyMenu_fun)GetProcAddress(huser32, "DestroyMenu");
	pGetIconInfoExA = (GetIconInfoExA_fun)GetProcAddress(huser32, "GetIconInfoExA");
	pCallMsgFilterA = (CallMsgFilterA_fun)GetProcAddress(huser32, "CallMsgFilterA");
	pIsDialogMessageA = (IsDialogMessageA_fun)GetProcAddress(huser32, "IsDialogMessageA");
	pGetSysColor = (GetSysColor_fun)GetProcAddress(huser32, "GetSysColor");
	pEnumDisplaySettingsW = (EnumDisplaySettingsW_fun)GetProcAddress(huser32, "EnumDisplaySettingsW");
	pInvalidateRect = (InvalidateRect_fun)GetProcAddress(huser32, "InvalidateRect");
	pAnyPopup = (AnyPopup_fun)GetProcAddress(huser32, "AnyPopup");
	pBroadcastSystemMessage = (BroadcastSystemMessage_fun)GetProcAddress(huser32, "BroadcastSystemMessage");
	pGetClassLongPtrW = (GetClassLongPtrW_fun)GetProcAddress(huser32, "GetClassLongPtrW");
	pGetDlgItemTextW = (GetDlgItemTextW_fun)GetProcAddress(huser32, "GetDlgItemTextW");
	pPrivateExtractIconsW = (PrivateExtractIconsW_fun)GetProcAddress(huser32, "PrivateExtractIconsW");
	pUpdateLayeredWindowIndirect = (UpdateLayeredWindowIndirect_fun)GetProcAddress(huser32, "UpdateLayeredWindowIndirect");
	pSetPhysicalCursorPos = (SetPhysicalCursorPos_fun)GetProcAddress(huser32, "SetPhysicalCursorPos");
	pSetLayeredWindowAttributes = (SetLayeredWindowAttributes_fun)GetProcAddress(huser32, "SetLayeredWindowAttributes");
	pSetWindowWord = (SetWindowWord_fun)GetProcAddress(huser32, "SetWindowWord");
	pDeregisterShellHookWindow = (DeregisterShellHookWindow_fun)GetProcAddress(huser32, "DeregisterShellHookWindow");
	pLoadAcceleratorsA = (LoadAcceleratorsA_fun)GetProcAddress(huser32, "LoadAcceleratorsA");
	pDragObject = (DragObject_fun)GetProcAddress(huser32, "DragObject");
	pRemovePropW = (RemovePropW_fun)GetProcAddress(huser32, "RemovePropW");
	pIsCharUpperA = (IsCharUpperA_fun)GetProcAddress(huser32, "IsCharUpperA");
	pDlgDirSelectExA = (DlgDirSelectExA_fun)GetProcAddress(huser32, "DlgDirSelectExA");
	pCloseTouchInputHandle = (CloseTouchInputHandle_fun)GetProcAddress(huser32, "CloseTouchInputHandle");
	pChangeDisplaySettingsA = (ChangeDisplaySettingsA_fun)GetProcAddress(huser32, "ChangeDisplaySettingsA");
	pScreenToClient = (ScreenToClient_fun)GetProcAddress(huser32, "ScreenToClient");
	pModifyMenuW = (ModifyMenuW_fun)GetProcAddress(huser32, "ModifyMenuW");
	pMessageBoxExW = (MessageBoxExW_fun)GetProcAddress(huser32, "MessageBoxExW");
	pkeybd_event = (keybd_event_fun)GetProcAddress(huser32, "keybd_event");
	pLockSetForegroundWindow = (LockSetForegroundWindow_fun)GetProcAddress(huser32, "LockSetForegroundWindow");
	pGetMenuCheckMarkDimensions = (GetMenuCheckMarkDimensions_fun)GetProcAddress(huser32, "GetMenuCheckMarkDimensions");
	pSetClassLongW = (SetClassLongW_fun)GetProcAddress(huser32, "SetClassLongW");
	pCharNextW = (CharNextW_fun)GetProcAddress(huser32, "CharNextW");
	pLogicalToPhysicalPoint = (LogicalToPhysicalPoint_fun)GetProcAddress(huser32, "LogicalToPhysicalPoint");
	pLoadCursorW = (LoadCursorW_fun)GetProcAddress(huser32, "LoadCursorW");
	pGetClassLongW = (GetClassLongW_fun)GetProcAddress(huser32, "GetClassLongW");
	pEnumDesktopWindows = (EnumDesktopWindows_fun)GetProcAddress(huser32, "EnumDesktopWindows");
	pDefWindowProcW = (DefWindowProcW_fun)GetProcAddress(huser32, "DefWindowProcW");
	pUnregisterDeviceNotification = (UnregisterDeviceNotification_fun)GetProcAddress(huser32, "UnregisterDeviceNotification");
	pDlgDirSelectExW = (DlgDirSelectExW_fun)GetProcAddress(huser32, "DlgDirSelectExW");
	pGetGUIThreadInfo = (GetGUIThreadInfo_fun)GetProcAddress(huser32, "GetGUIThreadInfo");
	pCopyImage = (CopyImage_fun)GetProcAddress(huser32, "CopyImage");
	pRealGetWindowClassW = (RealGetWindowClassW_fun)GetProcAddress(huser32, "RealGetWindowClassW");
	pGetWindowPlacement = (GetWindowPlacement_fun)GetProcAddress(huser32, "GetWindowPlacement");
	pFindWindowExW = (FindWindowExW_fun)GetProcAddress(huser32, "FindWindowExW");
	pSetScrollPos = (SetScrollPos_fun)GetProcAddress(huser32, "SetScrollPos");
	pTrackPopupMenu = (TrackPopupMenu_fun)GetProcAddress(huser32, "TrackPopupMenu");
	pCharToOemA = (CharToOemA_fun)GetProcAddress(huser32, "CharToOemA");
	pGetDlgItemInt = (GetDlgItemInt_fun)GetProcAddress(huser32, "GetDlgItemInt");
	pCreateMenu = (CreateMenu_fun)GetProcAddress(huser32, "CreateMenu");
	pChangeMenuA = (ChangeMenuA_fun)GetProcAddress(huser32, "ChangeMenuA");
	pCreateDesktopExW = (CreateDesktopExW_fun)GetProcAddress(huser32, "CreateDesktopExW");
	pDialogBoxParamA = (DialogBoxParamA_fun)GetProcAddress(huser32, "DialogBoxParamA");
	pGetProcessDefaultLayout = (GetProcessDefaultLayout_fun)GetProcAddress(huser32, "GetProcessDefaultLayout");
	pGetPropA = (GetPropA_fun)GetProcAddress(huser32, "GetPropA");
	pGetMenuInfo = (GetMenuInfo_fun)GetProcAddress(huser32, "GetMenuInfo");
	pPtInRect = (PtInRect_fun)GetProcAddress(huser32, "PtInRect");
	pCopyAcceleratorTableW = (CopyAcceleratorTableW_fun)GetProcAddress(huser32, "CopyAcceleratorTableW");
	pOemToCharBuffW = (OemToCharBuffW_fun)GetProcAddress(huser32, "OemToCharBuffW");
	pLookupIconIdFromDirectoryEx = (LookupIconIdFromDirectoryEx_fun)GetProcAddress(huser32, "LookupIconIdFromDirectoryEx");
	pWinHelpW = (WinHelpW_fun)GetProcAddress(huser32, "WinHelpW");
	pSetWindowLongPtrA = (SetWindowLongPtrA_fun)GetProcAddress(huser32, "SetWindowLongPtrA");
	pCharToOemW = (CharToOemW_fun)GetProcAddress(huser32, "CharToOemW");
	pCreateWindowExA = (CreateWindowExA_fun)GetProcAddress(huser32, "CreateWindowExA");
	pCharPrevExA = (CharPrevExA_fun)GetProcAddress(huser32, "CharPrevExA");
	pGetPropW = (GetPropW_fun)GetProcAddress(huser32, "GetPropW");
	pGetWindowModuleFileNameW = (GetWindowModuleFileNameW_fun)GetProcAddress(huser32, "GetWindowModuleFileNameW");
	pDestroyCaret = (DestroyCaret_fun)GetProcAddress(huser32, "DestroyCaret");
	pMessageBoxIndirectW = (MessageBoxIndirectW_fun)GetProcAddress(huser32, "MessageBoxIndirectW");
	pUnhookWindowsHookEx = (UnhookWindowsHookEx_fun)GetProcAddress(huser32, "UnhookWindowsHookEx");
	pIsCharLowerW = (IsCharLowerW_fun)GetProcAddress(huser32, "IsCharLowerW");
	pGetKeyboardLayout = (GetKeyboardLayout_fun)GetProcAddress(huser32, "GetKeyboardLayout");
	pToUnicodeEx = (ToUnicodeEx_fun)GetProcAddress(huser32, "ToUnicodeEx");
	pSetUserObjectInformationW = (SetUserObjectInformationW_fun)GetProcAddress(huser32, "SetUserObjectInformationW");
	pRealGetWindowClassA = (RealGetWindowClassA_fun)GetProcAddress(huser32, "RealGetWindowClassA");
	pSetUserObjectInformationA = (SetUserObjectInformationA_fun)GetProcAddress(huser32, "SetUserObjectInformationA");
	pGetClassInfoExA = (GetClassInfoExA_fun)GetProcAddress(huser32, "GetClassInfoExA");
	pGetMenuBarInfo = (GetMenuBarInfo_fun)GetProcAddress(huser32, "GetMenuBarInfo");
	pSetMenuItemInfoA = (SetMenuItemInfoA_fun)GetProcAddress(huser32, "SetMenuItemInfoA");
	pShutdownBlockReasonQuery = (ShutdownBlockReasonQuery_fun)GetProcAddress(huser32, "ShutdownBlockReasonQuery");
	pCharPrevW = (CharPrevW_fun)GetProcAddress(huser32, "CharPrevW");
	pCheckDlgButton = (CheckDlgButton_fun)GetProcAddress(huser32, "CheckDlgButton");
	pClientToScreen = (ClientToScreen_fun)GetProcAddress(huser32, "ClientToScreen");
	pDlgDirSelectComboBoxExA = (DlgDirSelectComboBoxExA_fun)GetProcAddress(huser32, "DlgDirSelectComboBoxExA");
	pDrawTextW = (DrawTextW_fun)GetProcAddress(huser32, "DrawTextW");
	pDefDlgProcW = (DefDlgProcW_fun)GetProcAddress(huser32, "DefDlgProcW");
	pSetWinEventHook = (SetWinEventHook_fun)GetProcAddress(huser32, "SetWinEventHook");
	pShowWindow = (ShowWindow_fun)GetProcAddress(huser32, "ShowWindow");
	pSetPropW = (SetPropW_fun)GetProcAddress(huser32, "SetPropW");
	pToAsciiEx = (ToAsciiEx_fun)GetProcAddress(huser32, "ToAsciiEx");
	pVkKeyScanA = (VkKeyScanA_fun)GetProcAddress(huser32, "VkKeyScanA");
	pSendMessageCallbackA = (SendMessageCallbackA_fun)GetProcAddress(huser32, "SendMessageCallbackA");
	pSetClipboardViewer = (SetClipboardViewer_fun)GetProcAddress(huser32, "SetClipboardViewer");
	pGetInputState = (GetInputState_fun)GetProcAddress(huser32, "GetInputState");
	pDefMDIChildProcW = (DefMDIChildProcW_fun)GetProcAddress(huser32, "DefMDIChildProcW");
	pIntersectRect = (IntersectRect_fun)GetProcAddress(huser32, "IntersectRect");
	pSetWindowPlacement = (SetWindowPlacement_fun)GetProcAddress(huser32, "SetWindowPlacement");
	pGetNextDlgTabItem = (GetNextDlgTabItem_fun)GetProcAddress(huser32, "GetNextDlgTabItem");
	pSetCapture = (SetCapture_fun)GetProcAddress(huser32, "SetCapture");
	pDisplayConfigSetDeviceInfo = (DisplayConfigSetDeviceInfo_fun)GetProcAddress(huser32, "DisplayConfigSetDeviceInfo");
	pGetWindowTextA = (GetWindowTextA_fun)GetProcAddress(huser32, "GetWindowTextA");
	pSetMenuInfo = (SetMenuInfo_fun)GetProcAddress(huser32, "SetMenuInfo");
	pTranslateMDISysAccel = (TranslateMDISysAccel_fun)GetProcAddress(huser32, "TranslateMDISysAccel");
	pDialogBoxParamW = (DialogBoxParamW_fun)GetProcAddress(huser32, "DialogBoxParamW");
	pGetComboBoxInfo = (GetComboBoxInfo_fun)GetProcAddress(huser32, "GetComboBoxInfo");
	pIsCharUpperW = (IsCharUpperW_fun)GetProcAddress(huser32, "IsCharUpperW");
	pGetUserObjectInformationW = (GetUserObjectInformationW_fun)GetProcAddress(huser32, "GetUserObjectInformationW");
	pGetMessageExtraInfo = (GetMessageExtraInfo_fun)GetProcAddress(huser32, "GetMessageExtraInfo");
	pEnumDisplayDevicesA = (EnumDisplayDevicesA_fun)GetProcAddress(huser32, "EnumDisplayDevicesA");
	pMoveWindow = (MoveWindow_fun)GetProcAddress(huser32, "MoveWindow");
	pGetUserObjectSecurity = (GetUserObjectSecurity_fun)GetProcAddress(huser32, "GetUserObjectSecurity");
	pDrawFrameControl = (DrawFrameControl_fun)GetProcAddress(huser32, "DrawFrameControl");
	pDefWindowProcA = (DefWindowProcA_fun)GetProcAddress(huser32, "DefWindowProcA");
	pDrawMenuBar = (DrawMenuBar_fun)GetProcAddress(huser32, "DrawMenuBar");
	pAllowSetForegroundWindow = (AllowSetForegroundWindow_fun)GetProcAddress(huser32, "AllowSetForegroundWindow");
	pOpenWindowStationW = (OpenWindowStationW_fun)GetProcAddress(huser32, "OpenWindowStationW");
	pUnhookWinEvent = (UnhookWinEvent_fun)GetProcAddress(huser32, "UnhookWinEvent");
	pGetClipboardOwner = (GetClipboardOwner_fun)GetProcAddress(huser32, "GetClipboardOwner");
	pDefDlgProcA = (DefDlgProcA_fun)GetProcAddress(huser32, "DefDlgProcA");
	pDeleteMenu = (DeleteMenu_fun)GetProcAddress(huser32, "DeleteMenu");
	pBroadcastSystemMessageExA = (BroadcastSystemMessageExA_fun)GetProcAddress(huser32, "BroadcastSystemMessageExA");
	pIsGUIThread = (IsGUIThread_fun)GetProcAddress(huser32, "IsGUIThread");
	pLockWorkStation = (LockWorkStation_fun)GetProcAddress(huser32, "LockWorkStation");
	pIsWinEventHookInstalled = (IsWinEventHookInstalled_fun)GetProcAddress(huser32, "IsWinEventHookInstalled");
	pOemToCharW = (OemToCharW_fun)GetProcAddress(huser32, "OemToCharW");
	pDragDetect = (DragDetect_fun)GetProcAddress(huser32, "DragDetect");
	pGetKeyNameTextW = (GetKeyNameTextW_fun)GetProcAddress(huser32, "GetKeyNameTextW");
	pGetWindowThreadProcessId = (GetWindowThreadProcessId_fun)GetProcAddress(huser32, "GetWindowThreadProcessId");
	pSetTimer = (SetTimer_fun)GetProcAddress(huser32, "SetTimer");
	pGetWindowRgnBox = (GetWindowRgnBox_fun)GetProcAddress(huser32, "GetWindowRgnBox");
	pCharNextExA = (CharNextExA_fun)GetProcAddress(huser32, "CharNextExA");
	pSwitchToThisWindow = (SwitchToThisWindow_fun)GetProcAddress(huser32, "SwitchToThisWindow");
	pCharLowerBuffA = (CharLowerBuffA_fun)GetProcAddress(huser32, "CharLowerBuffA");
	pGetMenuItemCount = (GetMenuItemCount_fun)GetProcAddress(huser32, "GetMenuItemCount");
	pSetProcessWindowStation = (SetProcessWindowStation_fun)GetProcAddress(huser32, "SetProcessWindowStation");
	pSetWindowsHookA = (SetWindowsHookA_fun)GetProcAddress(huser32, "SetWindowsHookA");
	pShowScrollBar = (ShowScrollBar_fun)GetProcAddress(huser32, "ShowScrollBar");
	pCharLowerBuffW = (CharLowerBuffW_fun)GetProcAddress(huser32, "CharLowerBuffW");
	pRegisterClassExW = (RegisterClassExW_fun)GetProcAddress(huser32, "RegisterClassExW");

}

extern "C" void __declspec(dllexport) __stdcall NativeInjectionEntryPoint(REMOTE_ENTRY_INFO* inRemoteInfo);

void __stdcall NativeInjectionEntryPoint(REMOTE_ENTRY_INFO* inRemoteInfo)
{
    PrepareRealApiEntry();

	LhInstallHook(pRemoveMenu, fake_RemoveMenu, NULL, &hHookRemoveMenu);
	LhSetExclusiveACL(HookRemoveMenu_ACLEntries, 1, &&hHookRemoveMenu);

	LhInstallHook(pAttachThreadInput, fake_AttachThreadInput, NULL, &hHookAttachThreadInput);
	LhSetExclusiveACL(HookAttachThreadInput_ACLEntries, 1, &&hHookAttachThreadInput);

	LhInstallHook(pSetFocus, fake_SetFocus, NULL, &hHookSetFocus);
	LhSetExclusiveACL(HookSetFocus_ACLEntries, 1, &&hHookSetFocus);

	LhInstallHook(pSetCursor, fake_SetCursor, NULL, &hHookSetCursor);
	LhSetExclusiveACL(HookSetCursor_ACLEntries, 1, &&hHookSetCursor);

	LhInstallHook(pChangeDisplaySettingsExA, fake_ChangeDisplaySettingsExA, NULL, &hHookChangeDisplaySettingsExA);
	LhSetExclusiveACL(HookChangeDisplaySettingsExA_ACLEntries, 1, &&hHookChangeDisplaySettingsExA);

	LhInstallHook(pLookupIconIdFromDirectory, fake_LookupIconIdFromDirectory, NULL, &hHookLookupIconIdFromDirectory);
	LhSetExclusiveACL(HookLookupIconIdFromDirectory_ACLEntries, 1, &&hHookLookupIconIdFromDirectory);

	LhInstallHook(pIsWindowVisible, fake_IsWindowVisible, NULL, &hHookIsWindowVisible);
	LhSetExclusiveACL(HookIsWindowVisible_ACLEntries, 1, &&hHookIsWindowVisible);

	LhInstallHook(pMenuItemFromPoint, fake_MenuItemFromPoint, NULL, &hHookMenuItemFromPoint);
	LhSetExclusiveACL(HookMenuItemFromPoint_ACLEntries, 1, &&hHookMenuItemFromPoint);

	LhInstallHook(pCallNextHookEx, fake_CallNextHookEx, NULL, &hHookCallNextHookEx);
	LhSetExclusiveACL(HookCallNextHookEx_ACLEntries, 1, &&hHookCallNextHookEx);

	LhInstallHook(pShowCaret, fake_ShowCaret, NULL, &hHookShowCaret);
	LhSetExclusiveACL(HookShowCaret_ACLEntries, 1, &&hHookShowCaret);

	LhInstallHook(pRegisterClassExA, fake_RegisterClassExA, NULL, &hHookRegisterClassExA);
	LhSetExclusiveACL(HookRegisterClassExA_ACLEntries, 1, &&hHookRegisterClassExA);

	LhInstallHook(pSetDlgItemInt, fake_SetDlgItemInt, NULL, &hHookSetDlgItemInt);
	LhSetExclusiveACL(HookSetDlgItemInt_ACLEntries, 1, &&hHookSetDlgItemInt);

	LhInstallHook(pDefMDIChildProcA, fake_DefMDIChildProcA, NULL, &hHookDefMDIChildProcA);
	LhSetExclusiveACL(HookDefMDIChildProcA_ACLEntries, 1, &&hHookDefMDIChildProcA);

	LhInstallHook(pCloseWindow, fake_CloseWindow, NULL, &hHookCloseWindow);
	LhSetExclusiveACL(HookCloseWindow_ACLEntries, 1, &&hHookCloseWindow);

	LhInstallHook(pSetProcessDefaultLayout, fake_SetProcessDefaultLayout, NULL, &hHookSetProcessDefaultLayout);
	LhSetExclusiveACL(HookSetProcessDefaultLayout_ACLEntries, 1, &&hHookSetProcessDefaultLayout);

	LhInstallHook(pDrawIcon, fake_DrawIcon, NULL, &hHookDrawIcon);
	LhSetExclusiveACL(HookDrawIcon_ACLEntries, 1, &&hHookDrawIcon);

	LhInstallHook(pTranslateAcceleratorA, fake_TranslateAcceleratorA, NULL, &hHookTranslateAcceleratorA);
	LhSetExclusiveACL(HookTranslateAcceleratorA_ACLEntries, 1, &&hHookTranslateAcceleratorA);

	LhInstallHook(pGetQueueStatus, fake_GetQueueStatus, NULL, &hHookGetQueueStatus);
	LhSetExclusiveACL(HookGetQueueStatus_ACLEntries, 1, &&hHookGetQueueStatus);

	LhInstallHook(pDestroyWindow, fake_DestroyWindow, NULL, &hHookDestroyWindow);
	LhSetExclusiveACL(HookDestroyWindow_ACLEntries, 1, &&hHookDestroyWindow);

	LhInstallHook(pChangeDisplaySettingsExW, fake_ChangeDisplaySettingsExW, NULL, &hHookChangeDisplaySettingsExW);
	LhSetExclusiveACL(HookChangeDisplaySettingsExW_ACLEntries, 1, &&hHookChangeDisplaySettingsExW);

	LhInstallHook(pLoadKeyboardLayoutA, fake_LoadKeyboardLayoutA, NULL, &hHookLoadKeyboardLayoutA);
	LhSetExclusiveACL(HookLoadKeyboardLayoutA_ACLEntries, 1, &&hHookLoadKeyboardLayoutA);

	LhInstallHook(pRegisterClassA, fake_RegisterClassA, NULL, &hHookRegisterClassA);
	LhSetExclusiveACL(HookRegisterClassA_ACLEntries, 1, &&hHookRegisterClassA);

	LhInstallHook(pCreateIconFromResourceEx, fake_CreateIconFromResourceEx, NULL, &hHookCreateIconFromResourceEx);
	LhSetExclusiveACL(HookCreateIconFromResourceEx_ACLEntries, 1, &&hHookCreateIconFromResourceEx);

	LhInstallHook(pChangeDisplaySettingsW, fake_ChangeDisplaySettingsW, NULL, &hHookChangeDisplaySettingsW);
	LhSetExclusiveACL(HookChangeDisplaySettingsW_ACLEntries, 1, &&hHookChangeDisplaySettingsW);

	LhInstallHook(pSetWindowPos, fake_SetWindowPos, NULL, &hHookSetWindowPos);
	LhSetExclusiveACL(HookSetWindowPos_ACLEntries, 1, &&hHookSetWindowPos);

	LhInstallHook(pRegisterTouchWindow, fake_RegisterTouchWindow, NULL, &hHookRegisterTouchWindow);
	LhSetExclusiveACL(HookRegisterTouchWindow_ACLEntries, 1, &&hHookRegisterTouchWindow);

	LhInstallHook(pSetPropA, fake_SetPropA, NULL, &hHookSetPropA);
	LhSetExclusiveACL(HookSetPropA_ACLEntries, 1, &&hHookSetPropA);

	LhInstallHook(pGetWindowTextLengthA, fake_GetWindowTextLengthA, NULL, &hHookGetWindowTextLengthA);
	LhSetExclusiveACL(HookGetWindowTextLengthA_ACLEntries, 1, &&hHookGetWindowTextLengthA);

	LhInstallHook(pCreateAcceleratorTableA, fake_CreateAcceleratorTableA, NULL, &hHookCreateAcceleratorTableA);
	LhSetExclusiveACL(HookCreateAcceleratorTableA_ACLEntries, 1, &&hHookCreateAcceleratorTableA);

	LhInstallHook(pCreateDialogIndirectParamW, fake_CreateDialogIndirectParamW, NULL, &hHookCreateDialogIndirectParamW);
	LhSetExclusiveACL(HookCreateDialogIndirectParamW_ACLEntries, 1, &&hHookCreateDialogIndirectParamW);

	LhInstallHook(pActivateKeyboardLayout, fake_ActivateKeyboardLayout, NULL, &hHookActivateKeyboardLayout);
	LhSetExclusiveACL(HookActivateKeyboardLayout_ACLEntries, 1, &&hHookActivateKeyboardLayout);

	LhInstallHook(pGetWindowLongW, fake_GetWindowLongW, NULL, &hHookGetWindowLongW);
	LhSetExclusiveACL(HookGetWindowLongW_ACLEntries, 1, &&hHookGetWindowLongW);

	LhInstallHook(pGetIconInfo, fake_GetIconInfo, NULL, &hHookGetIconInfo);
	LhSetExclusiveACL(HookGetIconInfo_ACLEntries, 1, &&hHookGetIconInfo);

	LhInstallHook(pDispatchMessageW, fake_DispatchMessageW, NULL, &hHookDispatchMessageW);
	LhSetExclusiveACL(HookDispatchMessageW_ACLEntries, 1, &&hHookDispatchMessageW);

	LhInstallHook(pSetCursorPos, fake_SetCursorPos, NULL, &hHookSetCursorPos);
	LhSetExclusiveACL(HookSetCursorPos_ACLEntries, 1, &&hHookSetCursorPos);

	LhInstallHook(pCalculatePopupWindowPosition, fake_CalculatePopupWindowPosition, NULL, &hHookCalculatePopupWindowPosition);
	LhSetExclusiveACL(HookCalculatePopupWindowPosition_ACLEntries, 1, &&hHookCalculatePopupWindowPosition);

	LhInstallHook(pArrangeIconicWindows, fake_ArrangeIconicWindows, NULL, &hHookArrangeIconicWindows);
	LhSetExclusiveACL(HookArrangeIconicWindows_ACLEntries, 1, &&hHookArrangeIconicWindows);

	LhInstallHook(pCallWindowProcW, fake_CallWindowProcW, NULL, &hHookCallWindowProcW);
	LhSetExclusiveACL(HookCallWindowProcW_ACLEntries, 1, &&hHookCallWindowProcW);

	LhInstallHook(pQueryDisplayConfig, fake_QueryDisplayConfig, NULL, &hHookQueryDisplayConfig);
	LhSetExclusiveACL(HookQueryDisplayConfig_ACLEntries, 1, &&hHookQueryDisplayConfig);

	LhInstallHook(pMapVirtualKeyExW, fake_MapVirtualKeyExW, NULL, &hHookMapVirtualKeyExW);
	LhSetExclusiveACL(HookMapVirtualKeyExW_ACLEntries, 1, &&hHookMapVirtualKeyExW);

	LhInstallHook(pSetThreadDesktop, fake_SetThreadDesktop, NULL, &hHookSetThreadDesktop);
	LhSetExclusiveACL(HookSetThreadDesktop_ACLEntries, 1, &&hHookSetThreadDesktop);

	LhInstallHook(pmouse_event, fake_mouse_event, NULL, &hHookmouse_event);
	LhSetExclusiveACL(Hookmouse_event_ACLEntries, 1, &&hHookmouse_event);

	LhInstallHook(pCreatePopupMenu, fake_CreatePopupMenu, NULL, &hHookCreatePopupMenu);
	LhSetExclusiveACL(HookCreatePopupMenu_ACLEntries, 1, &&hHookCreatePopupMenu);

	LhInstallHook(pShowOwnedPopups, fake_ShowOwnedPopups, NULL, &hHookShowOwnedPopups);
	LhSetExclusiveACL(HookShowOwnedPopups_ACLEntries, 1, &&hHookShowOwnedPopups);

	LhInstallHook(pSetScrollRange, fake_SetScrollRange, NULL, &hHookSetScrollRange);
	LhSetExclusiveACL(HookSetScrollRange_ACLEntries, 1, &&hHookSetScrollRange);

	LhInstallHook(pEnumWindowStationsA, fake_EnumWindowStationsA, NULL, &hHookEnumWindowStationsA);
	LhSetExclusiveACL(HookEnumWindowStationsA_ACLEntries, 1, &&hHookEnumWindowStationsA);

	LhInstallHook(pGetClipCursor, fake_GetClipCursor, NULL, &hHookGetClipCursor);
	LhSetExclusiveACL(HookGetClipCursor_ACLEntries, 1, &&hHookGetClipCursor);

	LhInstallHook(pSetClipboardData, fake_SetClipboardData, NULL, &hHookSetClipboardData);
	LhSetExclusiveACL(HookSetClipboardData_ACLEntries, 1, &&hHookSetClipboardData);

	LhInstallHook(pGetWindowDisplayAffinity, fake_GetWindowDisplayAffinity, NULL, &hHookGetWindowDisplayAffinity);
	LhSetExclusiveACL(HookGetWindowDisplayAffinity_ACLEntries, 1, &&hHookGetWindowDisplayAffinity);

	LhInstallHook(pAppendMenuA, fake_AppendMenuA, NULL, &hHookAppendMenuA);
	LhSetExclusiveACL(HookAppendMenuA_ACLEntries, 1, &&hHookAppendMenuA);

	LhInstallHook(pCharToOemBuffW, fake_CharToOemBuffW, NULL, &hHookCharToOemBuffW);
	LhSetExclusiveACL(HookCharToOemBuffW_ACLEntries, 1, &&hHookCharToOemBuffW);

	LhInstallHook(pOpenDesktopW, fake_OpenDesktopW, NULL, &hHookOpenDesktopW);
	LhSetExclusiveACL(HookOpenDesktopW_ACLEntries, 1, &&hHookOpenDesktopW);

	LhInstallHook(pDefFrameProcA, fake_DefFrameProcA, NULL, &hHookDefFrameProcA);
	LhSetExclusiveACL(HookDefFrameProcA_ACLEntries, 1, &&hHookDefFrameProcA);

	LhInstallHook(pSetSysColors, fake_SetSysColors, NULL, &hHookSetSysColors);
	LhSetExclusiveACL(HookSetSysColors_ACLEntries, 1, &&hHookSetSysColors);

	LhInstallHook(pDestroyIcon, fake_DestroyIcon, NULL, &hHookDestroyIcon);
	LhSetExclusiveACL(HookDestroyIcon_ACLEntries, 1, &&hHookDestroyIcon);

	LhInstallHook(pAdjustWindowRectEx, fake_AdjustWindowRectEx, NULL, &hHookAdjustWindowRectEx);
	LhSetExclusiveACL(HookAdjustWindowRectEx_ACLEntries, 1, &&hHookAdjustWindowRectEx);

	LhInstallHook(pEqualRect, fake_EqualRect, NULL, &hHookEqualRect);
	LhSetExclusiveACL(HookEqualRect_ACLEntries, 1, &&hHookEqualRect);

	LhInstallHook(pGetWindowWord, fake_GetWindowWord, NULL, &hHookGetWindowWord);
	LhSetExclusiveACL(HookGetWindowWord_ACLEntries, 1, &&hHookGetWindowWord);

	LhInstallHook(pInternalGetWindowText, fake_InternalGetWindowText, NULL, &hHookInternalGetWindowText);
	LhSetExclusiveACL(HookInternalGetWindowText_ACLEntries, 1, &&hHookInternalGetWindowText);

	LhInstallHook(pSetWindowTextW, fake_SetWindowTextW, NULL, &hHookSetWindowTextW);
	LhSetExclusiveACL(HookSetWindowTextW_ACLEntries, 1, &&hHookSetWindowTextW);

	LhInstallHook(pGetTabbedTextExtentA, fake_GetTabbedTextExtentA, NULL, &hHookGetTabbedTextExtentA);
	LhSetExclusiveACL(HookGetTabbedTextExtentA_ACLEntries, 1, &&hHookGetTabbedTextExtentA);

	LhInstallHook(pGetParent, fake_GetParent, NULL, &hHookGetParent);
	LhSetExclusiveACL(HookGetParent_ACLEntries, 1, &&hHookGetParent);

	LhInstallHook(pGetIconInfoExW, fake_GetIconInfoExW, NULL, &hHookGetIconInfoExW);
	LhSetExclusiveACL(HookGetIconInfoExW_ACLEntries, 1, &&hHookGetIconInfoExW);

	LhInstallHook(pChildWindowFromPointEx, fake_ChildWindowFromPointEx, NULL, &hHookChildWindowFromPointEx);
	LhSetExclusiveACL(HookChildWindowFromPointEx_ACLEntries, 1, &&hHookChildWindowFromPointEx);

	LhInstallHook(pDeferWindowPos, fake_DeferWindowPos, NULL, &hHookDeferWindowPos);
	LhSetExclusiveACL(HookDeferWindowPos_ACLEntries, 1, &&hHookDeferWindowPos);

	LhInstallHook(pMapVirtualKeyExA, fake_MapVirtualKeyExA, NULL, &hHookMapVirtualKeyExA);
	LhSetExclusiveACL(HookMapVirtualKeyExA_ACLEntries, 1, &&hHookMapVirtualKeyExA);

	LhInstallHook(pGetClassNameW, fake_GetClassNameW, NULL, &hHookGetClassNameW);
	LhSetExclusiveACL(HookGetClassNameW_ACLEntries, 1, &&hHookGetClassNameW);

	LhInstallHook(pAppendMenuW, fake_AppendMenuW, NULL, &hHookAppendMenuW);
	LhSetExclusiveACL(HookAppendMenuW_ACLEntries, 1, &&hHookAppendMenuW);

	LhInstallHook(pLoadImageW, fake_LoadImageW, NULL, &hHookLoadImageW);
	LhSetExclusiveACL(HookLoadImageW_ACLEntries, 1, &&hHookLoadImageW);

	LhInstallHook(pLoadStringW, fake_LoadStringW, NULL, &hHookLoadStringW);
	LhSetExclusiveACL(HookLoadStringW_ACLEntries, 1, &&hHookLoadStringW);

	LhInstallHook(pRealChildWindowFromPoint, fake_RealChildWindowFromPoint, NULL, &hHookRealChildWindowFromPoint);
	LhSetExclusiveACL(HookRealChildWindowFromPoint_ACLEntries, 1, &&hHookRealChildWindowFromPoint);

	LhInstallHook(pCheckRadioButton, fake_CheckRadioButton, NULL, &hHookCheckRadioButton);
	LhSetExclusiveACL(HookCheckRadioButton_ACLEntries, 1, &&hHookCheckRadioButton);

	LhInstallHook(pGetScrollInfo, fake_GetScrollInfo, NULL, &hHookGetScrollInfo);
	LhSetExclusiveACL(HookGetScrollInfo_ACLEntries, 1, &&hHookGetScrollInfo);

	LhInstallHook(pGetKeyNameTextA, fake_GetKeyNameTextA, NULL, &hHookGetKeyNameTextA);
	LhSetExclusiveACL(HookGetKeyNameTextA_ACLEntries, 1, &&hHookGetKeyNameTextA);

	LhInstallHook(pGetSysColorBrush, fake_GetSysColorBrush, NULL, &hHookGetSysColorBrush);
	LhSetExclusiveACL(HookGetSysColorBrush_ACLEntries, 1, &&hHookGetSysColorBrush);

	LhInstallHook(pLoadMenuIndirectW, fake_LoadMenuIndirectW, NULL, &hHookLoadMenuIndirectW);
	LhSetExclusiveACL(HookLoadMenuIndirectW_ACLEntries, 1, &&hHookLoadMenuIndirectW);

	LhInstallHook(pTrackPopupMenuEx, fake_TrackPopupMenuEx, NULL, &hHookTrackPopupMenuEx);
	LhSetExclusiveACL(HookTrackPopupMenuEx_ACLEntries, 1, &&hHookTrackPopupMenuEx);

	LhInstallHook(pSetDoubleClickTime, fake_SetDoubleClickTime, NULL, &hHookSetDoubleClickTime);
	LhSetExclusiveACL(HookSetDoubleClickTime_ACLEntries, 1, &&hHookSetDoubleClickTime);

	LhInstallHook(pIsProcessDPIAware, fake_IsProcessDPIAware, NULL, &hHookIsProcessDPIAware);
	LhSetExclusiveACL(HookIsProcessDPIAware_ACLEntries, 1, &&hHookIsProcessDPIAware);

	LhInstallHook(pDefFrameProcW, fake_DefFrameProcW, NULL, &hHookDefFrameProcW);
	LhSetExclusiveACL(HookDefFrameProcW_ACLEntries, 1, &&hHookDefFrameProcW);

	LhInstallHook(pVkKeyScanW, fake_VkKeyScanW, NULL, &hHookVkKeyScanW);
	LhSetExclusiveACL(HookVkKeyScanW_ACLEntries, 1, &&hHookVkKeyScanW);

	LhInstallHook(pEnumDisplayMonitors, fake_EnumDisplayMonitors, NULL, &hHookEnumDisplayMonitors);
	LhSetExclusiveACL(HookEnumDisplayMonitors_ACLEntries, 1, &&hHookEnumDisplayMonitors);

	LhInstallHook(pLoadBitmapW, fake_LoadBitmapW, NULL, &hHookLoadBitmapW);
	LhSetExclusiveACL(HookLoadBitmapW_ACLEntries, 1, &&hHookLoadBitmapW);

	LhInstallHook(pHideCaret, fake_HideCaret, NULL, &hHookHideCaret);
	LhSetExclusiveACL(HookHideCaret_ACLEntries, 1, &&hHookHideCaret);

	LhInstallHook(pDrawEdge, fake_DrawEdge, NULL, &hHookDrawEdge);
	LhSetExclusiveACL(HookDrawEdge_ACLEntries, 1, &&hHookDrawEdge);

	LhInstallHook(pCharUpperBuffA, fake_CharUpperBuffA, NULL, &hHookCharUpperBuffA);
	LhSetExclusiveACL(HookCharUpperBuffA_ACLEntries, 1, &&hHookCharUpperBuffA);

	LhInstallHook(pSetClassLongPtrW, fake_SetClassLongPtrW, NULL, &hHookSetClassLongPtrW);
	LhSetExclusiveACL(HookSetClassLongPtrW_ACLEntries, 1, &&hHookSetClassLongPtrW);

	LhInstallHook(pEnumWindowStationsW, fake_EnumWindowStationsW, NULL, &hHookEnumWindowStationsW);
	LhSetExclusiveACL(HookEnumWindowStationsW_ACLEntries, 1, &&hHookEnumWindowStationsW);

	LhInstallHook(pEnumDisplaySettingsExA, fake_EnumDisplaySettingsExA, NULL, &hHookEnumDisplaySettingsExA);
	LhSetExclusiveACL(HookEnumDisplaySettingsExA_ACLEntries, 1, &&hHookEnumDisplaySettingsExA);

	LhInstallHook(pGetMenuItemRect, fake_GetMenuItemRect, NULL, &hHookGetMenuItemRect);
	LhSetExclusiveACL(HookGetMenuItemRect_ACLEntries, 1, &&hHookGetMenuItemRect);

	LhInstallHook(pReplyMessage, fake_ReplyMessage, NULL, &hHookReplyMessage);
	LhSetExclusiveACL(HookReplyMessage_ACLEntries, 1, &&hHookReplyMessage);

	LhInstallHook(pAnimateWindow, fake_AnimateWindow, NULL, &hHookAnimateWindow);
	LhSetExclusiveACL(HookAnimateWindow_ACLEntries, 1, &&hHookAnimateWindow);

	LhInstallHook(pSendInput, fake_SendInput, NULL, &hHookSendInput);
	LhSetExclusiveACL(HookSendInput_ACLEntries, 1, &&hHookSendInput);

	LhInstallHook(pEnableScrollBar, fake_EnableScrollBar, NULL, &hHookEnableScrollBar);
	LhSetExclusiveACL(HookEnableScrollBar_ACLEntries, 1, &&hHookEnableScrollBar);

	LhInstallHook(pGetMenuDefaultItem, fake_GetMenuDefaultItem, NULL, &hHookGetMenuDefaultItem);
	LhSetExclusiveACL(HookGetMenuDefaultItem_ACLEntries, 1, &&hHookGetMenuDefaultItem);

	LhInstallHook(pEnumPropsA, fake_EnumPropsA, NULL, &hHookEnumPropsA);
	LhSetExclusiveACL(HookEnumPropsA_ACLEntries, 1, &&hHookEnumPropsA);

	LhInstallHook(pTranslateMessage, fake_TranslateMessage, NULL, &hHookTranslateMessage);
	LhSetExclusiveACL(HookTranslateMessage_ACLEntries, 1, &&hHookTranslateMessage);

	LhInstallHook(pCharNextA, fake_CharNextA, NULL, &hHookCharNextA);
	LhSetExclusiveACL(HookCharNextA_ACLEntries, 1, &&hHookCharNextA);

	LhInstallHook(pGetForegroundWindow, fake_GetForegroundWindow, NULL, &hHookGetForegroundWindow);
	LhSetExclusiveACL(HookGetForegroundWindow_ACLEntries, 1, &&hHookGetForegroundWindow);

	LhInstallHook(pCharLowerA, fake_CharLowerA, NULL, &hHookCharLowerA);
	LhSetExclusiveACL(HookCharLowerA_ACLEntries, 1, &&hHookCharLowerA);

	LhInstallHook(pIsRectEmpty, fake_IsRectEmpty, NULL, &hHookIsRectEmpty);
	LhSetExclusiveACL(HookIsRectEmpty_ACLEntries, 1, &&hHookIsRectEmpty);

	LhInstallHook(pOpenClipboard, fake_OpenClipboard, NULL, &hHookOpenClipboard);
	LhSetExclusiveACL(HookOpenClipboard_ACLEntries, 1, &&hHookOpenClipboard);

	LhInstallHook(pGetKeyboardLayoutList, fake_GetKeyboardLayoutList, NULL, &hHookGetKeyboardLayoutList);
	LhSetExclusiveACL(HookGetKeyboardLayoutList_ACLEntries, 1, &&hHookGetKeyboardLayoutList);

	LhInstallHook(pCopyIcon, fake_CopyIcon, NULL, &hHookCopyIcon);
	LhSetExclusiveACL(HookCopyIcon_ACLEntries, 1, &&hHookCopyIcon);

	LhInstallHook(pDlgDirListA, fake_DlgDirListA, NULL, &hHookDlgDirListA);
	LhSetExclusiveACL(HookDlgDirListA_ACLEntries, 1, &&hHookDlgDirListA);

	LhInstallHook(pRedrawWindow, fake_RedrawWindow, NULL, &hHookRedrawWindow);
	LhSetExclusiveACL(HookRedrawWindow_ACLEntries, 1, &&hHookRedrawWindow);

	LhInstallHook(pEndDialog, fake_EndDialog, NULL, &hHookEndDialog);
	LhSetExclusiveACL(HookEndDialog_ACLEntries, 1, &&hHookEndDialog);

	LhInstallHook(pMessageBeep, fake_MessageBeep, NULL, &hHookMessageBeep);
	LhSetExclusiveACL(HookMessageBeep_ACLEntries, 1, &&hHookMessageBeep);

	LhInstallHook(pCloseWindowStation, fake_CloseWindowStation, NULL, &hHookCloseWindowStation);
	LhSetExclusiveACL(HookCloseWindowStation_ACLEntries, 1, &&hHookCloseWindowStation);

	LhInstallHook(pGetClassWord, fake_GetClassWord, NULL, &hHookGetClassWord);
	LhSetExclusiveACL(HookGetClassWord_ACLEntries, 1, &&hHookGetClassWord);

	LhInstallHook(pCreateDesktopExA, fake_CreateDesktopExA, NULL, &hHookCreateDesktopExA);
	LhSetExclusiveACL(HookCreateDesktopExA_ACLEntries, 1, &&hHookCreateDesktopExA);

	LhInstallHook(pGetSystemMenu, fake_GetSystemMenu, NULL, &hHookGetSystemMenu);
	LhSetExclusiveACL(HookGetSystemMenu_ACLEntries, 1, &&hHookGetSystemMenu);

	LhInstallHook(pRegisterWindowMessageA, fake_RegisterWindowMessageA, NULL, &hHookRegisterWindowMessageA);
	LhSetExclusiveACL(HookRegisterWindowMessageA_ACLEntries, 1, &&hHookRegisterWindowMessageA);

	LhInstallHook(pGetRegisteredRawInputDevices, fake_GetRegisteredRawInputDevices, NULL, &hHookGetRegisteredRawInputDevices);
	LhSetExclusiveACL(HookGetRegisteredRawInputDevices_ACLEntries, 1, &&hHookGetRegisteredRawInputDevices);

	LhInstallHook(pLoadIconW, fake_LoadIconW, NULL, &hHookLoadIconW);
	LhSetExclusiveACL(HookLoadIconW_ACLEntries, 1, &&hHookLoadIconW);

	LhInstallHook(pGetWindowContextHelpId, fake_GetWindowContextHelpId, NULL, &hHookGetWindowContextHelpId);
	LhSetExclusiveACL(HookGetWindowContextHelpId_ACLEntries, 1, &&hHookGetWindowContextHelpId);

	LhInstallHook(pBroadcastSystemMessageW, fake_BroadcastSystemMessageW, NULL, &hHookBroadcastSystemMessageW);
	LhSetExclusiveACL(HookBroadcastSystemMessageW_ACLEntries, 1, &&hHookBroadcastSystemMessageW);

	LhInstallHook(pEnumDesktopsW, fake_EnumDesktopsW, NULL, &hHookEnumDesktopsW);
	LhSetExclusiveACL(HookEnumDesktopsW_ACLEntries, 1, &&hHookEnumDesktopsW);

	LhInstallHook(pSetClassLongPtrA, fake_SetClassLongPtrA, NULL, &hHookSetClassLongPtrA);
	LhSetExclusiveACL(HookSetClassLongPtrA_ACLEntries, 1, &&hHookSetClassLongPtrA);

	LhInstallHook(pMsgWaitForMultipleObjectsEx, fake_MsgWaitForMultipleObjectsEx, NULL, &hHookMsgWaitForMultipleObjectsEx);
	LhSetExclusiveACL(HookMsgWaitForMultipleObjectsEx_ACLEntries, 1, &&hHookMsgWaitForMultipleObjectsEx);

	LhInstallHook(pUnregisterTouchWindow, fake_UnregisterTouchWindow, NULL, &hHookUnregisterTouchWindow);
	LhSetExclusiveACL(HookUnregisterTouchWindow_ACLEntries, 1, &&hHookUnregisterTouchWindow);

	LhInstallHook(pGetClassNameA, fake_GetClassNameA, NULL, &hHookGetClassNameA);
	LhSetExclusiveACL(HookGetClassNameA_ACLEntries, 1, &&hHookGetClassNameA);

	LhInstallHook(pIsCharAlphaNumericW, fake_IsCharAlphaNumericW, NULL, &hHookIsCharAlphaNumericW);
	LhSetExclusiveACL(HookIsCharAlphaNumericW_ACLEntries, 1, &&hHookIsCharAlphaNumericW);

	LhInstallHook(pSetUserObjectSecurity, fake_SetUserObjectSecurity, NULL, &hHookSetUserObjectSecurity);
	LhSetExclusiveACL(HookSetUserObjectSecurity_ACLEntries, 1, &&hHookSetUserObjectSecurity);

	LhInstallHook(pEnumDisplaySettingsExW, fake_EnumDisplaySettingsExW, NULL, &hHookEnumDisplaySettingsExW);
	LhSetExclusiveACL(HookEnumDisplaySettingsExW_ACLEntries, 1, &&hHookEnumDisplaySettingsExW);

	LhInstallHook(pPaintDesktop, fake_PaintDesktop, NULL, &hHookPaintDesktop);
	LhSetExclusiveACL(HookPaintDesktop_ACLEntries, 1, &&hHookPaintDesktop);

	LhInstallHook(pSetLastErrorEx, fake_SetLastErrorEx, NULL, &hHookSetLastErrorEx);
	LhSetExclusiveACL(HookSetLastErrorEx_ACLEntries, 1, &&hHookSetLastErrorEx);

	LhInstallHook(pIsDialogMessageW, fake_IsDialogMessageW, NULL, &hHookIsDialogMessageW);
	LhSetExclusiveACL(HookIsDialogMessageW_ACLEntries, 1, &&hHookIsDialogMessageW);

	LhInstallHook(pEnumDisplayDevicesW, fake_EnumDisplayDevicesW, NULL, &hHookEnumDisplayDevicesW);
	LhSetExclusiveACL(HookEnumDisplayDevicesW_ACLEntries, 1, &&hHookEnumDisplayDevicesW);

	LhInstallHook(pGetPhysicalCursorPos, fake_GetPhysicalCursorPos, NULL, &hHookGetPhysicalCursorPos);
	LhSetExclusiveACL(HookGetPhysicalCursorPos_ACLEntries, 1, &&hHookGetPhysicalCursorPos);

	LhInstallHook(pGetRawInputDeviceInfoW, fake_GetRawInputDeviceInfoW, NULL, &hHookGetRawInputDeviceInfoW);
	LhSetExclusiveACL(HookGetRawInputDeviceInfoW_ACLEntries, 1, &&hHookGetRawInputDeviceInfoW);

	LhInstallHook(pGetWindowModuleFileNameA, fake_GetWindowModuleFileNameA, NULL, &hHookGetWindowModuleFileNameA);
	LhSetExclusiveACL(HookGetWindowModuleFileNameA_ACLEntries, 1, &&hHookGetWindowModuleFileNameA);

	LhInstallHook(pDisableProcessWindowsGhosting, fake_DisableProcessWindowsGhosting, NULL, &hHookDisableProcessWindowsGhosting);
	LhSetExclusiveACL(HookDisableProcessWindowsGhosting_ACLEntries, 1, &&hHookDisableProcessWindowsGhosting);

	LhInstallHook(pSubtractRect, fake_SubtractRect, NULL, &hHookSubtractRect);
	LhSetExclusiveACL(HookSubtractRect_ACLEntries, 1, &&hHookSubtractRect);

	LhInstallHook(pFlashWindow, fake_FlashWindow, NULL, &hHookFlashWindow);
	LhSetExclusiveACL(HookFlashWindow_ACLEntries, 1, &&hHookFlashWindow);

	LhInstallHook(pDisplayConfigGetDeviceInfo, fake_DisplayConfigGetDeviceInfo, NULL, &hHookDisplayConfigGetDeviceInfo);
	LhSetExclusiveACL(HookDisplayConfigGetDeviceInfo_ACLEntries, 1, &&hHookDisplayConfigGetDeviceInfo);

	LhInstallHook(pSetForegroundWindow, fake_SetForegroundWindow, NULL, &hHookSetForegroundWindow);
	LhSetExclusiveACL(HookSetForegroundWindow_ACLEntries, 1, &&hHookSetForegroundWindow);

	LhInstallHook(pCreateWindowStationW, fake_CreateWindowStationW, NULL, &hHookCreateWindowStationW);
	LhSetExclusiveACL(HookCreateWindowStationW_ACLEntries, 1, &&hHookCreateWindowStationW);

	LhInstallHook(pOffsetRect, fake_OffsetRect, NULL, &hHookOffsetRect);
	LhSetExclusiveACL(HookOffsetRect_ACLEntries, 1, &&hHookOffsetRect);

	LhInstallHook(pDlgDirListComboBoxA, fake_DlgDirListComboBoxA, NULL, &hHookDlgDirListComboBoxA);
	LhSetExclusiveACL(HookDlgDirListComboBoxA_ACLEntries, 1, &&hHookDlgDirListComboBoxA);

	LhInstallHook(pGetMenuItemInfoW, fake_GetMenuItemInfoW, NULL, &hHookGetMenuItemInfoW);
	LhSetExclusiveACL(HookGetMenuItemInfoW_ACLEntries, 1, &&hHookGetMenuItemInfoW);

	LhInstallHook(pBroadcastSystemMessageExW, fake_BroadcastSystemMessageExW, NULL, &hHookBroadcastSystemMessageExW);
	LhSetExclusiveACL(HookBroadcastSystemMessageExW_ACLEntries, 1, &&hHookBroadcastSystemMessageExW);

	LhInstallHook(pGetGestureConfig, fake_GetGestureConfig, NULL, &hHookGetGestureConfig);
	LhSetExclusiveACL(HookGetGestureConfig_ACLEntries, 1, &&hHookGetGestureConfig);

	LhInstallHook(pSwitchDesktop, fake_SwitchDesktop, NULL, &hHookSwitchDesktop);
	LhSetExclusiveACL(HookSwitchDesktop_ACLEntries, 1, &&hHookSwitchDesktop);

	LhInstallHook(pGetNextDlgGroupItem, fake_GetNextDlgGroupItem, NULL, &hHookGetNextDlgGroupItem);
	LhSetExclusiveACL(HookGetNextDlgGroupItem_ACLEntries, 1, &&hHookGetNextDlgGroupItem);

	LhInstallHook(pMessageBoxIndirectA, fake_MessageBoxIndirectA, NULL, &hHookMessageBoxIndirectA);
	LhSetExclusiveACL(HookMessageBoxIndirectA_ACLEntries, 1, &&hHookMessageBoxIndirectA);

	LhInstallHook(pDestroyCursor, fake_DestroyCursor, NULL, &hHookDestroyCursor);
	LhSetExclusiveACL(HookDestroyCursor_ACLEntries, 1, &&hHookDestroyCursor);

	LhInstallHook(pSoundSentry, fake_SoundSentry, NULL, &hHookSoundSentry);
	LhSetExclusiveACL(HookSoundSentry_ACLEntries, 1, &&hHookSoundSentry);

	LhInstallHook(pCreateAcceleratorTableW, fake_CreateAcceleratorTableW, NULL, &hHookCreateAcceleratorTableW);
	LhSetExclusiveACL(HookCreateAcceleratorTableW_ACLEntries, 1, &&hHookCreateAcceleratorTableW);

	LhInstallHook(pGetCapture, fake_GetCapture, NULL, &hHookGetCapture);
	LhSetExclusiveACL(HookGetCapture_ACLEntries, 1, &&hHookGetCapture);

	LhInstallHook(pGetDesktopWindow, fake_GetDesktopWindow, NULL, &hHookGetDesktopWindow);
	LhSetExclusiveACL(HookGetDesktopWindow_ACLEntries, 1, &&hHookGetDesktopWindow);

	LhInstallHook(pSetMessageExtraInfo, fake_SetMessageExtraInfo, NULL, &hHookSetMessageExtraInfo);
	LhSetExclusiveACL(HookSetMessageExtraInfo_ACLEntries, 1, &&hHookSetMessageExtraInfo);

	LhInstallHook(pCreateDesktopW, fake_CreateDesktopW, NULL, &hHookCreateDesktopW);
	LhSetExclusiveACL(HookCreateDesktopW_ACLEntries, 1, &&hHookCreateDesktopW);

	LhInstallHook(pIsWindow, fake_IsWindow, NULL, &hHookIsWindow);
	LhSetExclusiveACL(HookIsWindow_ACLEntries, 1, &&hHookIsWindow);

	LhInstallHook(pOpenDesktopA, fake_OpenDesktopA, NULL, &hHookOpenDesktopA);
	LhSetExclusiveACL(HookOpenDesktopA_ACLEntries, 1, &&hHookOpenDesktopA);

	LhInstallHook(pWinHelpA, fake_WinHelpA, NULL, &hHookWinHelpA);
	LhSetExclusiveACL(HookWinHelpA_ACLEntries, 1, &&hHookWinHelpA);

	LhInstallHook(pChangeWindowMessageFilterEx, fake_ChangeWindowMessageFilterEx, NULL, &hHookChangeWindowMessageFilterEx);
	LhSetExclusiveACL(HookChangeWindowMessageFilterEx_ACLEntries, 1, &&hHookChangeWindowMessageFilterEx);

	LhInstallHook(pCloseGestureInfoHandle, fake_CloseGestureInfoHandle, NULL, &hHookCloseGestureInfoHandle);
	LhSetExclusiveACL(HookCloseGestureInfoHandle_ACLEntries, 1, &&hHookCloseGestureInfoHandle);

	LhInstallHook(pEnumWindows, fake_EnumWindows, NULL, &hHookEnumWindows);
	LhSetExclusiveACL(HookEnumWindows_ACLEntries, 1, &&hHookEnumWindows);

	LhInstallHook(pCreateCursor, fake_CreateCursor, NULL, &hHookCreateCursor);
	LhSetExclusiveACL(HookCreateCursor_ACLEntries, 1, &&hHookCreateCursor);

	LhInstallHook(pBeginDeferWindowPos, fake_BeginDeferWindowPos, NULL, &hHookBeginDeferWindowPos);
	LhSetExclusiveACL(HookBeginDeferWindowPos_ACLEntries, 1, &&hHookBeginDeferWindowPos);

	LhInstallHook(pSetWindowDisplayAffinity, fake_SetWindowDisplayAffinity, NULL, &hHookSetWindowDisplayAffinity);
	LhSetExclusiveACL(HookSetWindowDisplayAffinity_ACLEntries, 1, &&hHookSetWindowDisplayAffinity);

	LhInstallHook(pScrollDC, fake_ScrollDC, NULL, &hHookScrollDC);
	LhSetExclusiveACL(HookScrollDC_ACLEntries, 1, &&hHookScrollDC);

	LhInstallHook(pEnumThreadWindows, fake_EnumThreadWindows, NULL, &hHookEnumThreadWindows);
	LhSetExclusiveACL(HookEnumThreadWindows_ACLEntries, 1, &&hHookEnumThreadWindows);

	LhInstallHook(pBroadcastSystemMessageA, fake_BroadcastSystemMessageA, NULL, &hHookBroadcastSystemMessageA);
	LhSetExclusiveACL(HookBroadcastSystemMessageA_ACLEntries, 1, &&hHookBroadcastSystemMessageA);

	LhInstallHook(pGetKeyboardType, fake_GetKeyboardType, NULL, &hHookGetKeyboardType);
	LhSetExclusiveACL(HookGetKeyboardType_ACLEntries, 1, &&hHookGetKeyboardType);

	LhInstallHook(pGetClipboardFormatNameW, fake_GetClipboardFormatNameW, NULL, &hHookGetClipboardFormatNameW);
	LhSetExclusiveACL(HookGetClipboardFormatNameW_ACLEntries, 1, &&hHookGetClipboardFormatNameW);

	LhInstallHook(pIsClipboardFormatAvailable, fake_IsClipboardFormatAvailable, NULL, &hHookIsClipboardFormatAvailable);
	LhSetExclusiveACL(HookIsClipboardFormatAvailable_ACLEntries, 1, &&hHookIsClipboardFormatAvailable);

	LhInstallHook(pDialogBoxIndirectParamA, fake_DialogBoxIndirectParamA, NULL, &hHookDialogBoxIndirectParamA);
	LhSetExclusiveACL(HookDialogBoxIndirectParamA_ACLEntries, 1, &&hHookDialogBoxIndirectParamA);

	LhInstallHook(pGetMenu, fake_GetMenu, NULL, &hHookGetMenu);
	LhSetExclusiveACL(HookGetMenu_ACLEntries, 1, &&hHookGetMenu);

	LhInstallHook(pGetRawInputBuffer, fake_GetRawInputBuffer, NULL, &hHookGetRawInputBuffer);
	LhSetExclusiveACL(HookGetRawInputBuffer_ACLEntries, 1, &&hHookGetRawInputBuffer);

	LhInstallHook(pCountClipboardFormats, fake_CountClipboardFormats, NULL, &hHookCountClipboardFormats);
	LhSetExclusiveACL(HookCountClipboardFormats_ACLEntries, 1, &&hHookCountClipboardFormats);

	LhInstallHook(pFrameRect, fake_FrameRect, NULL, &hHookFrameRect);
	LhSetExclusiveACL(HookFrameRect_ACLEntries, 1, &&hHookFrameRect);

	LhInstallHook(pEnumPropsW, fake_EnumPropsW, NULL, &hHookEnumPropsW);
	LhSetExclusiveACL(HookEnumPropsW_ACLEntries, 1, &&hHookEnumPropsW);

	LhInstallHook(pInSendMessageEx, fake_InSendMessageEx, NULL, &hHookInSendMessageEx);
	LhSetExclusiveACL(HookInSendMessageEx_ACLEntries, 1, &&hHookInSendMessageEx);

	LhInstallHook(pGetLastActivePopup, fake_GetLastActivePopup, NULL, &hHookGetLastActivePopup);
	LhSetExclusiveACL(HookGetLastActivePopup_ACLEntries, 1, &&hHookGetLastActivePopup);

	LhInstallHook(pPostMessageW, fake_PostMessageW, NULL, &hHookPostMessageW);
	LhSetExclusiveACL(HookPostMessageW_ACLEntries, 1, &&hHookPostMessageW);

	LhInstallHook(pDrawTextExW, fake_DrawTextExW, NULL, &hHookDrawTextExW);
	LhSetExclusiveACL(HookDrawTextExW_ACLEntries, 1, &&hHookDrawTextExW);

	LhInstallHook(pGetMonitorInfoW, fake_GetMonitorInfoW, NULL, &hHookGetMonitorInfoW);
	LhSetExclusiveACL(HookGetMonitorInfoW_ACLEntries, 1, &&hHookGetMonitorInfoW);

	LhInstallHook(pMessageBoxW, fake_MessageBoxW, NULL, &hHookMessageBoxW);
	LhSetExclusiveACL(HookMessageBoxW_ACLEntries, 1, &&hHookMessageBoxW);

	LhInstallHook(pIsWindowUnicode, fake_IsWindowUnicode, NULL, &hHookIsWindowUnicode);
	LhSetExclusiveACL(HookIsWindowUnicode_ACLEntries, 1, &&hHookIsWindowUnicode);

	LhInstallHook(pDispatchMessageA, fake_DispatchMessageA, NULL, &hHookDispatchMessageA);
	LhSetExclusiveACL(HookDispatchMessageA_ACLEntries, 1, &&hHookDispatchMessageA);

	LhInstallHook(pPostThreadMessageA, fake_PostThreadMessageA, NULL, &hHookPostThreadMessageA);
	LhSetExclusiveACL(HookPostThreadMessageA_ACLEntries, 1, &&hHookPostThreadMessageA);

	LhInstallHook(pUnregisterHotKey, fake_UnregisterHotKey, NULL, &hHookUnregisterHotKey);
	LhSetExclusiveACL(HookUnregisterHotKey_ACLEntries, 1, &&hHookUnregisterHotKey);

	LhInstallHook(pCreateDialogIndirectParamA, fake_CreateDialogIndirectParamA, NULL, &hHookCreateDialogIndirectParamA);
	LhSetExclusiveACL(HookCreateDialogIndirectParamA_ACLEntries, 1, &&hHookCreateDialogIndirectParamA);

	LhInstallHook(pOemToCharA, fake_OemToCharA, NULL, &hHookOemToCharA);
	LhSetExclusiveACL(HookOemToCharA_ACLEntries, 1, &&hHookOemToCharA);

	LhInstallHook(pGetCursorPos, fake_GetCursorPos, NULL, &hHookGetCursorPos);
	LhSetExclusiveACL(HookGetCursorPos_ACLEntries, 1, &&hHookGetCursorPos);

	LhInstallHook(pCharUpperBuffW, fake_CharUpperBuffW, NULL, &hHookCharUpperBuffW);
	LhSetExclusiveACL(HookCharUpperBuffW_ACLEntries, 1, &&hHookCharUpperBuffW);

	LhInstallHook(pGetSystemMetrics, fake_GetSystemMetrics, NULL, &hHookGetSystemMetrics);
	LhSetExclusiveACL(HookGetSystemMetrics_ACLEntries, 1, &&hHookGetSystemMetrics);

	LhInstallHook(pGetKeyboardState, fake_GetKeyboardState, NULL, &hHookGetKeyboardState);
	LhSetExclusiveACL(HookGetKeyboardState_ACLEntries, 1, &&hHookGetKeyboardState);

	LhInstallHook(pIsWindowEnabled, fake_IsWindowEnabled, NULL, &hHookIsWindowEnabled);
	LhSetExclusiveACL(HookIsWindowEnabled_ACLEntries, 1, &&hHookIsWindowEnabled);

	LhInstallHook(pSwapMouseButton, fake_SwapMouseButton, NULL, &hHookSwapMouseButton);
	LhSetExclusiveACL(HookSwapMouseButton_ACLEntries, 1, &&hHookSwapMouseButton);

	LhInstallHook(pUnregisterPowerSettingNotification, fake_UnregisterPowerSettingNotification, NULL, &hHookUnregisterPowerSettingNotification);
	LhSetExclusiveACL(HookUnregisterPowerSettingNotification_ACLEntries, 1, &&hHookUnregisterPowerSettingNotification);

	LhInstallHook(pInsertMenuItemA, fake_InsertMenuItemA, NULL, &hHookInsertMenuItemA);
	LhSetExclusiveACL(HookInsertMenuItemA_ACLEntries, 1, &&hHookInsertMenuItemA);

	LhInstallHook(pUpdateLayeredWindow, fake_UpdateLayeredWindow, NULL, &hHookUpdateLayeredWindow);
	LhSetExclusiveACL(HookUpdateLayeredWindow_ACLEntries, 1, &&hHookUpdateLayeredWindow);

	LhInstallHook(pGetCursor, fake_GetCursor, NULL, &hHookGetCursor);
	LhSetExclusiveACL(HookGetCursor_ACLEntries, 1, &&hHookGetCursor);

	LhInstallHook(pSetWindowLongW, fake_SetWindowLongW, NULL, &hHookSetWindowLongW);
	LhSetExclusiveACL(HookSetWindowLongW_ACLEntries, 1, &&hHookSetWindowLongW);

	LhInstallHook(pSetWindowsHookExA, fake_SetWindowsHookExA, NULL, &hHookSetWindowsHookExA);
	LhSetExclusiveACL(HookSetWindowsHookExA_ACLEntries, 1, &&hHookSetWindowsHookExA);

	LhInstallHook(pCancelShutdown, fake_CancelShutdown, NULL, &hHookCancelShutdown);
	LhSetExclusiveACL(HookCancelShutdown_ACLEntries, 1, &&hHookCancelShutdown);

	LhInstallHook(pSetWindowsHookExW, fake_SetWindowsHookExW, NULL, &hHookSetWindowsHookExW);
	LhSetExclusiveACL(HookSetWindowsHookExW_ACLEntries, 1, &&hHookSetWindowsHookExW);

	LhInstallHook(pSetWindowLongPtrW, fake_SetWindowLongPtrW, NULL, &hHookSetWindowLongPtrW);
	LhSetExclusiveACL(HookSetWindowLongPtrW_ACLEntries, 1, &&hHookSetWindowLongPtrW);

	LhInstallHook(pCopyAcceleratorTableA, fake_CopyAcceleratorTableA, NULL, &hHookCopyAcceleratorTableA);
	LhSetExclusiveACL(HookCopyAcceleratorTableA_ACLEntries, 1, &&hHookCopyAcceleratorTableA);

	LhInstallHook(pWindowFromDC, fake_WindowFromDC, NULL, &hHookWindowFromDC);
	LhSetExclusiveACL(HookWindowFromDC_ACLEntries, 1, &&hHookWindowFromDC);

	LhInstallHook(pGetClipboardData, fake_GetClipboardData, NULL, &hHookGetClipboardData);
	LhSetExclusiveACL(HookGetClipboardData_ACLEntries, 1, &&hHookGetClipboardData);

	LhInstallHook(pCreateDesktopA, fake_CreateDesktopA, NULL, &hHookCreateDesktopA);
	LhSetExclusiveACL(HookCreateDesktopA_ACLEntries, 1, &&hHookCreateDesktopA);

	LhInstallHook(pCreateDialogParamW, fake_CreateDialogParamW, NULL, &hHookCreateDialogParamW);
	LhSetExclusiveACL(HookCreateDialogParamW_ACLEntries, 1, &&hHookCreateDialogParamW);

	LhInstallHook(pSystemParametersInfoW, fake_SystemParametersInfoW, NULL, &hHookSystemParametersInfoW);
	LhSetExclusiveACL(HookSystemParametersInfoW_ACLEntries, 1, &&hHookSystemParametersInfoW);

	LhInstallHook(pVkKeyScanExW, fake_VkKeyScanExW, NULL, &hHookVkKeyScanExW);
	LhSetExclusiveACL(HookVkKeyScanExW_ACLEntries, 1, &&hHookVkKeyScanExW);

	LhInstallHook(pLoadStringA, fake_LoadStringA, NULL, &hHookLoadStringA);
	LhSetExclusiveACL(HookLoadStringA_ACLEntries, 1, &&hHookLoadStringA);

	LhInstallHook(pEnumDisplaySettingsA, fake_EnumDisplaySettingsA, NULL, &hHookEnumDisplaySettingsA);
	LhSetExclusiveACL(HookEnumDisplaySettingsA_ACLEntries, 1, &&hHookEnumDisplaySettingsA);

	LhInstallHook(pGetPriorityClipboardFormat, fake_GetPriorityClipboardFormat, NULL, &hHookGetPriorityClipboardFormat);
	LhSetExclusiveACL(HookGetPriorityClipboardFormat_ACLEntries, 1, &&hHookGetPriorityClipboardFormat);

	LhInstallHook(pSetMenuDefaultItem, fake_SetMenuDefaultItem, NULL, &hHookSetMenuDefaultItem);
	LhSetExclusiveACL(HookSetMenuDefaultItem_ACLEntries, 1, &&hHookSetMenuDefaultItem);

	LhInstallHook(pGetDoubleClickTime, fake_GetDoubleClickTime, NULL, &hHookGetDoubleClickTime);
	LhSetExclusiveACL(HookGetDoubleClickTime_ACLEntries, 1, &&hHookGetDoubleClickTime);

	LhInstallHook(pEnableMenuItem, fake_EnableMenuItem, NULL, &hHookEnableMenuItem);
	LhSetExclusiveACL(HookEnableMenuItem_ACLEntries, 1, &&hHookEnableMenuItem);

	LhInstallHook(pPhysicalToLogicalPoint, fake_PhysicalToLogicalPoint, NULL, &hHookPhysicalToLogicalPoint);
	LhSetExclusiveACL(HookPhysicalToLogicalPoint_ACLEntries, 1, &&hHookPhysicalToLogicalPoint);

	LhInstallHook(pDlgDirListW, fake_DlgDirListW, NULL, &hHookDlgDirListW);
	LhSetExclusiveACL(HookDlgDirListW_ACLEntries, 1, &&hHookDlgDirListW);

	LhInstallHook(pDrawStateA, fake_DrawStateA, NULL, &hHookDrawStateA);
	LhSetExclusiveACL(HookDrawStateA_ACLEntries, 1, &&hHookDrawStateA);

	LhInstallHook(pGetMenuState, fake_GetMenuState, NULL, &hHookGetMenuState);
	LhSetExclusiveACL(HookGetMenuState_ACLEntries, 1, &&hHookGetMenuState);

	LhInstallHook(pDefRawInputProc, fake_DefRawInputProc, NULL, &hHookDefRawInputProc);
	LhSetExclusiveACL(HookDefRawInputProc_ACLEntries, 1, &&hHookDefRawInputProc);

	LhInstallHook(pInvalidateRgn, fake_InvalidateRgn, NULL, &hHookInvalidateRgn);
	LhSetExclusiveACL(HookInvalidateRgn_ACLEntries, 1, &&hHookInvalidateRgn);

	LhInstallHook(pInsertMenuItemW, fake_InsertMenuItemW, NULL, &hHookInsertMenuItemW);
	LhSetExclusiveACL(HookInsertMenuItemW_ACLEntries, 1, &&hHookInsertMenuItemW);

	LhInstallHook(pGetRawInputDeviceInfoA, fake_GetRawInputDeviceInfoA, NULL, &hHookGetRawInputDeviceInfoA);
	LhSetExclusiveACL(HookGetRawInputDeviceInfoA_ACLEntries, 1, &&hHookGetRawInputDeviceInfoA);

	LhInstallHook(pGetTitleBarInfo, fake_GetTitleBarInfo, NULL, &hHookGetTitleBarInfo);
	LhSetExclusiveACL(HookGetTitleBarInfo_ACLEntries, 1, &&hHookGetTitleBarInfo);

	LhInstallHook(pIsCharAlphaW, fake_IsCharAlphaW, NULL, &hHookIsCharAlphaW);
	LhSetExclusiveACL(HookIsCharAlphaW_ACLEntries, 1, &&hHookIsCharAlphaW);

	LhInstallHook(pToAscii, fake_ToAscii, NULL, &hHookToAscii);
	LhSetExclusiveACL(HookToAscii_ACLEntries, 1, &&hHookToAscii);

	LhInstallHook(pLoadMenuA, fake_LoadMenuA, NULL, &hHookLoadMenuA);
	LhSetExclusiveACL(HookLoadMenuA_ACLEntries, 1, &&hHookLoadMenuA);

	LhInstallHook(pEndDeferWindowPos, fake_EndDeferWindowPos, NULL, &hHookEndDeferWindowPos);
	LhSetExclusiveACL(HookEndDeferWindowPos_ACLEntries, 1, &&hHookEndDeferWindowPos);

	LhInstallHook(pIsZoomed, fake_IsZoomed, NULL, &hHookIsZoomed);
	LhSetExclusiveACL(HookIsZoomed_ACLEntries, 1, &&hHookIsZoomed);

	LhInstallHook(pCreateIconIndirect, fake_CreateIconIndirect, NULL, &hHookCreateIconIndirect);
	LhSetExclusiveACL(HookCreateIconIndirect_ACLEntries, 1, &&hHookCreateIconIndirect);

	LhInstallHook(pReleaseCapture, fake_ReleaseCapture, NULL, &hHookReleaseCapture);
	LhSetExclusiveACL(HookReleaseCapture_ACLEntries, 1, &&hHookReleaseCapture);

	LhInstallHook(pGetTopWindow, fake_GetTopWindow, NULL, &hHookGetTopWindow);
	LhSetExclusiveACL(HookGetTopWindow_ACLEntries, 1, &&hHookGetTopWindow);

	LhInstallHook(pCheckMenuRadioItem, fake_CheckMenuRadioItem, NULL, &hHookCheckMenuRadioItem);
	LhSetExclusiveACL(HookCheckMenuRadioItem_ACLEntries, 1, &&hHookCheckMenuRadioItem);

	LhInstallHook(pClipCursor, fake_ClipCursor, NULL, &hHookClipCursor);
	LhSetExclusiveACL(HookClipCursor_ACLEntries, 1, &&hHookClipCursor);

	LhInstallHook(pIsMenu, fake_IsMenu, NULL, &hHookIsMenu);
	LhSetExclusiveACL(HookIsMenu_ACLEntries, 1, &&hHookIsMenu);

	LhInstallHook(pGetGestureExtraArgs, fake_GetGestureExtraArgs, NULL, &hHookGetGestureExtraArgs);
	LhSetExclusiveACL(HookGetGestureExtraArgs_ACLEntries, 1, &&hHookGetGestureExtraArgs);

	LhInstallHook(pGetMenuItemInfoA, fake_GetMenuItemInfoA, NULL, &hHookGetMenuItemInfoA);
	LhSetExclusiveACL(HookGetMenuItemInfoA_ACLEntries, 1, &&hHookGetMenuItemInfoA);

	LhInstallHook(pIsCharLowerA, fake_IsCharLowerA, NULL, &hHookIsCharLowerA);
	LhSetExclusiveACL(HookIsCharLowerA_ACLEntries, 1, &&hHookIsCharLowerA);

	LhInstallHook(pSendMessageW, fake_SendMessageW, NULL, &hHookSendMessageW);
	LhSetExclusiveACL(HookSendMessageW_ACLEntries, 1, &&hHookSendMessageW);

	LhInstallHook(pGetMonitorInfoA, fake_GetMonitorInfoA, NULL, &hHookGetMonitorInfoA);
	LhSetExclusiveACL(HookGetMonitorInfoA_ACLEntries, 1, &&hHookGetMonitorInfoA);

	LhInstallHook(pGetAltTabInfoW, fake_GetAltTabInfoW, NULL, &hHookGetAltTabInfoW);
	LhSetExclusiveACL(HookGetAltTabInfoW_ACLEntries, 1, &&hHookGetAltTabInfoW);

	LhInstallHook(pGrayStringA, fake_GrayStringA, NULL, &hHookGrayStringA);
	LhSetExclusiveACL(HookGrayStringA_ACLEntries, 1, &&hHookGrayStringA);

	LhInstallHook(pSendMessageCallbackW, fake_SendMessageCallbackW, NULL, &hHookSendMessageCallbackW);
	LhSetExclusiveACL(HookSendMessageCallbackW_ACLEntries, 1, &&hHookSendMessageCallbackW);

	LhInstallHook(pGetRawInputData, fake_GetRawInputData, NULL, &hHookGetRawInputData);
	LhSetExclusiveACL(HookGetRawInputData_ACLEntries, 1, &&hHookGetRawInputData);

	LhInstallHook(pGetClipboardFormatNameA, fake_GetClipboardFormatNameA, NULL, &hHookGetClipboardFormatNameA);
	LhSetExclusiveACL(HookGetClipboardFormatNameA_ACLEntries, 1, &&hHookGetClipboardFormatNameA);

	LhInstallHook(pGetWindow, fake_GetWindow, NULL, &hHookGetWindow);
	LhSetExclusiveACL(HookGetWindow_ACLEntries, 1, &&hHookGetWindow);

	LhInstallHook(pExitWindowsEx, fake_ExitWindowsEx, NULL, &hHookExitWindowsEx);
	LhSetExclusiveACL(HookExitWindowsEx_ACLEntries, 1, &&hHookExitWindowsEx);

	LhInstallHook(pGetClipboardSequenceNumber, fake_GetClipboardSequenceNumber, NULL, &hHookGetClipboardSequenceNumber);
	LhSetExclusiveACL(HookGetClipboardSequenceNumber_ACLEntries, 1, &&hHookGetClipboardSequenceNumber);

	LhInstallHook(pOemToCharBuffA, fake_OemToCharBuffA, NULL, &hHookOemToCharBuffA);
	LhSetExclusiveACL(HookOemToCharBuffA_ACLEntries, 1, &&hHookOemToCharBuffA);

	LhInstallHook(pUserHandleGrantAccess, fake_UserHandleGrantAccess, NULL, &hHookUserHandleGrantAccess);
	LhSetExclusiveACL(HookUserHandleGrantAccess_ACLEntries, 1, &&hHookUserHandleGrantAccess);

	LhInstallHook(pScrollWindow, fake_ScrollWindow, NULL, &hHookScrollWindow);
	LhSetExclusiveACL(HookScrollWindow_ACLEntries, 1, &&hHookScrollWindow);

	LhInstallHook(pSetSystemCursor, fake_SetSystemCursor, NULL, &hHookSetSystemCursor);
	LhSetExclusiveACL(HookSetSystemCursor_ACLEntries, 1, &&hHookSetSystemCursor);

	LhInstallHook(pGetOpenClipboardWindow, fake_GetOpenClipboardWindow, NULL, &hHookGetOpenClipboardWindow);
	LhSetExclusiveACL(HookGetOpenClipboardWindow_ACLEntries, 1, &&hHookGetOpenClipboardWindow);

	LhInstallHook(pSetClassLongA, fake_SetClassLongA, NULL, &hHookSetClassLongA);
	LhSetExclusiveACL(HookSetClassLongA_ACLEntries, 1, &&hHookSetClassLongA);

	LhInstallHook(pIsCharAlphaNumericA, fake_IsCharAlphaNumericA, NULL, &hHookIsCharAlphaNumericA);
	LhSetExclusiveACL(HookIsCharAlphaNumericA_ACLEntries, 1, &&hHookIsCharAlphaNumericA);

	LhInstallHook(pGetMouseMovePointsEx, fake_GetMouseMovePointsEx, NULL, &hHookGetMouseMovePointsEx);
	LhSetExclusiveACL(HookGetMouseMovePointsEx_ACLEntries, 1, &&hHookGetMouseMovePointsEx);

	LhInstallHook(pGetMenuItemID, fake_GetMenuItemID, NULL, &hHookGetMenuItemID);
	LhSetExclusiveACL(HookGetMenuItemID_ACLEntries, 1, &&hHookGetMenuItemID);

	LhInstallHook(pCheckMenuItem, fake_CheckMenuItem, NULL, &hHookCheckMenuItem);
	LhSetExclusiveACL(HookCheckMenuItem_ACLEntries, 1, &&hHookCheckMenuItem);

	LhInstallHook(pGetClipboardViewer, fake_GetClipboardViewer, NULL, &hHookGetClipboardViewer);
	LhSetExclusiveACL(HookGetClipboardViewer_ACLEntries, 1, &&hHookGetClipboardViewer);

	LhInstallHook(pGetActiveWindow, fake_GetActiveWindow, NULL, &hHookGetActiveWindow);
	LhSetExclusiveACL(HookGetActiveWindow_ACLEntries, 1, &&hHookGetActiveWindow);

	LhInstallHook(pSetProcessDPIAware, fake_SetProcessDPIAware, NULL, &hHookSetProcessDPIAware);
	LhSetExclusiveACL(HookSetProcessDPIAware_ACLEntries, 1, &&hHookSetProcessDPIAware);

	LhInstallHook(pSetScrollInfo, fake_SetScrollInfo, NULL, &hHookSetScrollInfo);
	LhSetExclusiveACL(HookSetScrollInfo_ACLEntries, 1, &&hHookSetScrollInfo);

	LhInstallHook(pMapVirtualKeyW, fake_MapVirtualKeyW, NULL, &hHookMapVirtualKeyW);
	LhSetExclusiveACL(HookMapVirtualKeyW_ACLEntries, 1, &&hHookMapVirtualKeyW);

	LhInstallHook(pGetMessageW, fake_GetMessageW, NULL, &hHookGetMessageW);
	LhSetExclusiveACL(HookGetMessageW_ACLEntries, 1, &&hHookGetMessageW);

	LhInstallHook(pSetWindowContextHelpId, fake_SetWindowContextHelpId, NULL, &hHookSetWindowContextHelpId);
	LhSetExclusiveACL(HookSetWindowContextHelpId_ACLEntries, 1, &&hHookSetWindowContextHelpId);

	LhInstallHook(pGetMessageA, fake_GetMessageA, NULL, &hHookGetMessageA);
	LhSetExclusiveACL(HookGetMessageA_ACLEntries, 1, &&hHookGetMessageA);

	LhInstallHook(pSystemParametersInfoA, fake_SystemParametersInfoA, NULL, &hHookSystemParametersInfoA);
	LhSetExclusiveACL(HookSystemParametersInfoA_ACLEntries, 1, &&hHookSystemParametersInfoA);

	LhInstallHook(pLoadMenuIndirectA, fake_LoadMenuIndirectA, NULL, &hHookLoadMenuIndirectA);
	LhSetExclusiveACL(HookLoadMenuIndirectA_ACLEntries, 1, &&hHookLoadMenuIndirectA);

	LhInstallHook(pGetClassInfoExW, fake_GetClassInfoExW, NULL, &hHookGetClassInfoExW);
	LhSetExclusiveACL(HookGetClassInfoExW_ACLEntries, 1, &&hHookGetClassInfoExW);

	LhInstallHook(pEnumPropsExA, fake_EnumPropsExA, NULL, &hHookEnumPropsExA);
	LhSetExclusiveACL(HookEnumPropsExA_ACLEntries, 1, &&hHookEnumPropsExA);

	LhInstallHook(pLoadMenuW, fake_LoadMenuW, NULL, &hHookLoadMenuW);
	LhSetExclusiveACL(HookLoadMenuW_ACLEntries, 1, &&hHookLoadMenuW);

	LhInstallHook(pInsertMenuW, fake_InsertMenuW, NULL, &hHookInsertMenuW);
	LhSetExclusiveACL(HookInsertMenuW_ACLEntries, 1, &&hHookInsertMenuW);

	LhInstallHook(pSetDlgItemTextA, fake_SetDlgItemTextA, NULL, &hHookSetDlgItemTextA);
	LhSetExclusiveACL(HookSetDlgItemTextA_ACLEntries, 1, &&hHookSetDlgItemTextA);

	LhInstallHook(pFindWindowExA, fake_FindWindowExA, NULL, &hHookFindWindowExA);
	LhSetExclusiveACL(HookFindWindowExA_ACLEntries, 1, &&hHookFindWindowExA);

	LhInstallHook(pSendDlgItemMessageW, fake_SendDlgItemMessageW, NULL, &hHookSendDlgItemMessageW);
	LhSetExclusiveACL(HookSendDlgItemMessageW_ACLEntries, 1, &&hHookSendDlgItemMessageW);

	LhInstallHook(pGetTouchInputInfo, fake_GetTouchInputInfo, NULL, &hHookGetTouchInputInfo);
	LhSetExclusiveACL(HookGetTouchInputInfo_ACLEntries, 1, &&hHookGetTouchInputInfo);

	LhInstallHook(pSendMessageTimeoutA, fake_SendMessageTimeoutA, NULL, &hHookSendMessageTimeoutA);
	LhSetExclusiveACL(HookSendMessageTimeoutA_ACLEntries, 1, &&hHookSendMessageTimeoutA);

	LhInstallHook(pSetMenuItemBitmaps, fake_SetMenuItemBitmaps, NULL, &hHookSetMenuItemBitmaps);
	LhSetExclusiveACL(HookSetMenuItemBitmaps_ACLEntries, 1, &&hHookSetMenuItemBitmaps);

	LhInstallHook(pSetDebugErrorLevel, fake_SetDebugErrorLevel, NULL, &hHookSetDebugErrorLevel);
	LhSetExclusiveACL(HookSetDebugErrorLevel_ACLEntries, 1, &&hHookSetDebugErrorLevel);

	LhInstallHook(pUnregisterClassA, fake_UnregisterClassA, NULL, &hHookUnregisterClassA);
	LhSetExclusiveACL(HookUnregisterClassA_ACLEntries, 1, &&hHookUnregisterClassA);

	LhInstallHook(pGetCaretBlinkTime, fake_GetCaretBlinkTime, NULL, &hHookGetCaretBlinkTime);
	LhSetExclusiveACL(HookGetCaretBlinkTime_ACLEntries, 1, &&hHookGetCaretBlinkTime);

	LhInstallHook(pCreateMDIWindowW, fake_CreateMDIWindowW, NULL, &hHookCreateMDIWindowW);
	LhSetExclusiveACL(HookCreateMDIWindowW_ACLEntries, 1, &&hHookCreateMDIWindowW);

	LhInstallHook(pOpenIcon, fake_OpenIcon, NULL, &hHookOpenIcon);
	LhSetExclusiveACL(HookOpenIcon_ACLEntries, 1, &&hHookOpenIcon);

	LhInstallHook(pRegisterDeviceNotificationW, fake_RegisterDeviceNotificationW, NULL, &hHookRegisterDeviceNotificationW);
	LhSetExclusiveACL(HookRegisterDeviceNotificationW_ACLEntries, 1, &&hHookRegisterDeviceNotificationW);

	LhInstallHook(pGetAsyncKeyState, fake_GetAsyncKeyState, NULL, &hHookGetAsyncKeyState);
	LhSetExclusiveACL(HookGetAsyncKeyState_ACLEntries, 1, &&hHookGetAsyncKeyState);

	LhInstallHook(pGetWindowInfo, fake_GetWindowInfo, NULL, &hHookGetWindowInfo);
	LhSetExclusiveACL(HookGetWindowInfo_ACLEntries, 1, &&hHookGetWindowInfo);

	LhInstallHook(pIsCharAlphaA, fake_IsCharAlphaA, NULL, &hHookIsCharAlphaA);
	LhSetExclusiveACL(HookIsCharAlphaA_ACLEntries, 1, &&hHookIsCharAlphaA);

	LhInstallHook(pSetParent, fake_SetParent, NULL, &hHookSetParent);
	LhSetExclusiveACL(HookSetParent_ACLEntries, 1, &&hHookSetParent);

	LhInstallHook(pDrawFocusRect, fake_DrawFocusRect, NULL, &hHookDrawFocusRect);
	LhSetExclusiveACL(HookDrawFocusRect_ACLEntries, 1, &&hHookDrawFocusRect);

	LhInstallHook(pToUnicode, fake_ToUnicode, NULL, &hHookToUnicode);
	LhSetExclusiveACL(HookToUnicode_ACLEntries, 1, &&hHookToUnicode);

	LhInstallHook(pMessageBoxExA, fake_MessageBoxExA, NULL, &hHookMessageBoxExA);
	LhSetExclusiveACL(HookMessageBoxExA_ACLEntries, 1, &&hHookMessageBoxExA);

	LhInstallHook(pBringWindowToTop, fake_BringWindowToTop, NULL, &hHookBringWindowToTop);
	LhSetExclusiveACL(HookBringWindowToTop_ACLEntries, 1, &&hHookBringWindowToTop);

	LhInstallHook(pCreateMDIWindowA, fake_CreateMDIWindowA, NULL, &hHookCreateMDIWindowA);
	LhSetExclusiveACL(HookCreateMDIWindowA_ACLEntries, 1, &&hHookCreateMDIWindowA);

	LhInstallHook(pShowCursor, fake_ShowCursor, NULL, &hHookShowCursor);
	LhSetExclusiveACL(HookShowCursor_ACLEntries, 1, &&hHookShowCursor);

	LhInstallHook(pPrintWindow, fake_PrintWindow, NULL, &hHookPrintWindow);
	LhSetExclusiveACL(HookPrintWindow_ACLEntries, 1, &&hHookPrintWindow);

	LhInstallHook(pGetWindowLongPtrA, fake_GetWindowLongPtrA, NULL, &hHookGetWindowLongPtrA);
	LhSetExclusiveACL(HookGetWindowLongPtrA_ACLEntries, 1, &&hHookGetWindowLongPtrA);

	LhInstallHook(pModifyMenuA, fake_ModifyMenuA, NULL, &hHookModifyMenuA);
	LhSetExclusiveACL(HookModifyMenuA_ACLEntries, 1, &&hHookModifyMenuA);

	LhInstallHook(pRegisterClipboardFormatW, fake_RegisterClipboardFormatW, NULL, &hHookRegisterClipboardFormatW);
	LhSetExclusiveACL(HookRegisterClipboardFormatW_ACLEntries, 1, &&hHookRegisterClipboardFormatW);

	LhInstallHook(pMsgWaitForMultipleObjects, fake_MsgWaitForMultipleObjects, NULL, &hHookMsgWaitForMultipleObjects);
	LhSetExclusiveACL(HookMsgWaitForMultipleObjects_ACLEntries, 1, &&hHookMsgWaitForMultipleObjects);

	LhInstallHook(pRegisterShellHookWindow, fake_RegisterShellHookWindow, NULL, &hHookRegisterShellHookWindow);
	LhSetExclusiveACL(HookRegisterShellHookWindow_ACLEntries, 1, &&hHookRegisterShellHookWindow);

	LhInstallHook(pGetMenuStringA, fake_GetMenuStringA, NULL, &hHookGetMenuStringA);
	LhSetExclusiveACL(HookGetMenuStringA_ACLEntries, 1, &&hHookGetMenuStringA);

	LhInstallHook(pPeekMessageW, fake_PeekMessageW, NULL, &hHookPeekMessageW);
	LhSetExclusiveACL(HookPeekMessageW_ACLEntries, 1, &&hHookPeekMessageW);

	LhInstallHook(pGetClassInfoA, fake_GetClassInfoA, NULL, &hHookGetClassInfoA);
	LhSetExclusiveACL(HookGetClassInfoA_ACLEntries, 1, &&hHookGetClassInfoA);

	LhInstallHook(pValidateRect, fake_ValidateRect, NULL, &hHookValidateRect);
	LhSetExclusiveACL(HookValidateRect_ACLEntries, 1, &&hHookValidateRect);

	LhInstallHook(pInflateRect, fake_InflateRect, NULL, &hHookInflateRect);
	LhSetExclusiveACL(HookInflateRect_ACLEntries, 1, &&hHookInflateRect);

	LhInstallHook(pSendMessageTimeoutW, fake_SendMessageTimeoutW, NULL, &hHookSendMessageTimeoutW);
	LhSetExclusiveACL(HookSendMessageTimeoutW_ACLEntries, 1, &&hHookSendMessageTimeoutW);

	LhInstallHook(pEnumDesktopsA, fake_EnumDesktopsA, NULL, &hHookEnumDesktopsA);
	LhSetExclusiveACL(HookEnumDesktopsA_ACLEntries, 1, &&hHookEnumDesktopsA);

	LhInstallHook(pRegisterDeviceNotificationA, fake_RegisterDeviceNotificationA, NULL, &hHookRegisterDeviceNotificationA);
	LhSetExclusiveACL(HookRegisterDeviceNotificationA_ACLEntries, 1, &&hHookRegisterDeviceNotificationA);

	LhInstallHook(pGetMessageTime, fake_GetMessageTime, NULL, &hHookGetMessageTime);
	LhSetExclusiveACL(HookGetMessageTime_ACLEntries, 1, &&hHookGetMessageTime);

	LhInstallHook(pEndMenu, fake_EndMenu, NULL, &hHookEndMenu);
	LhSetExclusiveACL(HookEndMenu_ACLEntries, 1, &&hHookEndMenu);

	LhInstallHook(pBeginPaint, fake_BeginPaint, NULL, &hHookBeginPaint);
	LhSetExclusiveACL(HookBeginPaint_ACLEntries, 1, &&hHookBeginPaint);

	LhInstallHook(pSetRectEmpty, fake_SetRectEmpty, NULL, &hHookSetRectEmpty);
	LhSetExclusiveACL(HookSetRectEmpty_ACLEntries, 1, &&hHookSetRectEmpty);

	LhInstallHook(pTabbedTextOutW, fake_TabbedTextOutW, NULL, &hHookTabbedTextOutW);
	LhSetExclusiveACL(HookTabbedTextOutW_ACLEntries, 1, &&hHookTabbedTextOutW);

	LhInstallHook(pInSendMessage, fake_InSendMessage, NULL, &hHookInSendMessage);
	LhSetExclusiveACL(HookInSendMessage_ACLEntries, 1, &&hHookInSendMessage);

	LhInstallHook(pGetWindowDC, fake_GetWindowDC, NULL, &hHookGetWindowDC);
	LhSetExclusiveACL(HookGetWindowDC_ACLEntries, 1, &&hHookGetWindowDC);

	LhInstallHook(pFindWindowA, fake_FindWindowA, NULL, &hHookFindWindowA);
	LhSetExclusiveACL(HookFindWindowA_ACLEntries, 1, &&hHookFindWindowA);

	LhInstallHook(pDlgDirSelectComboBoxExW, fake_DlgDirSelectComboBoxExW, NULL, &hHookDlgDirSelectComboBoxExW);
	LhSetExclusiveACL(HookDlgDirSelectComboBoxExW_ACLEntries, 1, &&hHookDlgDirSelectComboBoxExW);

	LhInstallHook(pSendNotifyMessageA, fake_SendNotifyMessageA, NULL, &hHookSendNotifyMessageA);
	LhSetExclusiveACL(HookSendNotifyMessageA_ACLEntries, 1, &&hHookSendNotifyMessageA);

	LhInstallHook(pDrawTextExA, fake_DrawTextExA, NULL, &hHookDrawTextExA);
	LhSetExclusiveACL(HookDrawTextExA_ACLEntries, 1, &&hHookDrawTextExA);

	LhInstallHook(pRegisterPowerSettingNotification, fake_RegisterPowerSettingNotification, NULL, &hHookRegisterPowerSettingNotification);
	LhSetExclusiveACL(HookRegisterPowerSettingNotification_ACLEntries, 1, &&hHookRegisterPowerSettingNotification);

	LhInstallHook(pGetMenuContextHelpId, fake_GetMenuContextHelpId, NULL, &hHookGetMenuContextHelpId);
	LhSetExclusiveACL(HookGetMenuContextHelpId_ACLEntries, 1, &&hHookGetMenuContextHelpId);

	LhInstallHook(pGetListBoxInfo, fake_GetListBoxInfo, NULL, &hHookGetListBoxInfo);
	LhSetExclusiveACL(HookGetListBoxInfo_ACLEntries, 1, &&hHookGetListBoxInfo);

	LhInstallHook(pSetRect, fake_SetRect, NULL, &hHookSetRect);
	LhSetExclusiveACL(HookSetRect_ACLEntries, 1, &&hHookSetRect);

	LhInstallHook(pGetRawInputDeviceList, fake_GetRawInputDeviceList, NULL, &hHookGetRawInputDeviceList);
	LhSetExclusiveACL(HookGetRawInputDeviceList_ACLEntries, 1, &&hHookGetRawInputDeviceList);

	LhInstallHook(pSetMessageQueue, fake_SetMessageQueue, NULL, &hHookSetMessageQueue);
	LhSetExclusiveACL(HookSetMessageQueue_ACLEntries, 1, &&hHookSetMessageQueue);

	LhInstallHook(pGetClassLongA, fake_GetClassLongA, NULL, &hHookGetClassLongA);
	LhSetExclusiveACL(HookGetClassLongA_ACLEntries, 1, &&hHookGetClassLongA);

	LhInstallHook(pFlashWindowEx, fake_FlashWindowEx, NULL, &hHookFlashWindowEx);
	LhSetExclusiveACL(HookFlashWindowEx_ACLEntries, 1, &&hHookFlashWindowEx);

	LhInstallHook(pGetDC, fake_GetDC, NULL, &hHookGetDC);
	LhSetExclusiveACL(HookGetDC_ACLEntries, 1, &&hHookGetDC);

	LhInstallHook(pSetMenuItemInfoW, fake_SetMenuItemInfoW, NULL, &hHookSetMenuItemInfoW);
	LhSetExclusiveACL(HookSetMenuItemInfoW_ACLEntries, 1, &&hHookSetMenuItemInfoW);

	LhInstallHook(pGetDCEx, fake_GetDCEx, NULL, &hHookGetDCEx);
	LhSetExclusiveACL(HookGetDCEx_ACLEntries, 1, &&hHookGetDCEx);

	LhInstallHook(pGetWindowLongPtrW, fake_GetWindowLongPtrW, NULL, &hHookGetWindowLongPtrW);
	LhSetExclusiveACL(HookGetWindowLongPtrW_ACLEntries, 1, &&hHookGetWindowLongPtrW);

	LhInstallHook(pGetLayeredWindowAttributes, fake_GetLayeredWindowAttributes, NULL, &hHookGetLayeredWindowAttributes);
	LhSetExclusiveACL(HookGetLayeredWindowAttributes_ACLEntries, 1, &&hHookGetLayeredWindowAttributes);

	LhInstallHook(pReleaseDC, fake_ReleaseDC, NULL, &hHookReleaseDC);
	LhSetExclusiveACL(HookReleaseDC_ACLEntries, 1, &&hHookReleaseDC);

	LhInstallHook(pRegisterClassW, fake_RegisterClassW, NULL, &hHookRegisterClassW);
	LhSetExclusiveACL(HookRegisterClassW_ACLEntries, 1, &&hHookRegisterClassW);

	LhInstallHook(pGetWindowTextW, fake_GetWindowTextW, NULL, &hHookGetWindowTextW);
	LhSetExclusiveACL(HookGetWindowTextW_ACLEntries, 1, &&hHookGetWindowTextW);

	LhInstallHook(pCreateWindowStationA, fake_CreateWindowStationA, NULL, &hHookCreateWindowStationA);
	LhSetExclusiveACL(HookCreateWindowStationA_ACLEntries, 1, &&hHookCreateWindowStationA);

	LhInstallHook(pDrawAnimatedRects, fake_DrawAnimatedRects, NULL, &hHookDrawAnimatedRects);
	LhSetExclusiveACL(HookDrawAnimatedRects_ACLEntries, 1, &&hHookDrawAnimatedRects);

	LhInstallHook(pFillRect, fake_FillRect, NULL, &hHookFillRect);
	LhSetExclusiveACL(HookFillRect_ACLEntries, 1, &&hHookFillRect);

	LhInstallHook(pGetDlgItem, fake_GetDlgItem, NULL, &hHookGetDlgItem);
	LhSetExclusiveACL(HookGetDlgItem_ACLEntries, 1, &&hHookGetDlgItem);

	LhInstallHook(pEnumPropsExW, fake_EnumPropsExW, NULL, &hHookEnumPropsExW);
	LhSetExclusiveACL(HookEnumPropsExW_ACLEntries, 1, &&hHookEnumPropsExW);

	LhInstallHook(pGetFocus, fake_GetFocus, NULL, &hHookGetFocus);
	LhSetExclusiveACL(HookGetFocus_ACLEntries, 1, &&hHookGetFocus);

	LhInstallHook(pGetKeyboardLayoutNameW, fake_GetKeyboardLayoutNameW, NULL, &hHookGetKeyboardLayoutNameW);
	LhSetExclusiveACL(HookGetKeyboardLayoutNameW_ACLEntries, 1, &&hHookGetKeyboardLayoutNameW);

	LhInstallHook(pLockWindowUpdate, fake_LockWindowUpdate, NULL, &hHookLockWindowUpdate);
	LhSetExclusiveACL(HookLockWindowUpdate_ACLEntries, 1, &&hHookLockWindowUpdate);

	LhInstallHook(pGetWindowRect, fake_GetWindowRect, NULL, &hHookGetWindowRect);
	LhSetExclusiveACL(HookGetWindowRect_ACLEntries, 1, &&hHookGetWindowRect);

	LhInstallHook(pShowWindowAsync, fake_ShowWindowAsync, NULL, &hHookShowWindowAsync);
	LhSetExclusiveACL(HookShowWindowAsync_ACLEntries, 1, &&hHookShowWindowAsync);

	LhInstallHook(pPrivateExtractIconsA, fake_PrivateExtractIconsA, NULL, &hHookPrivateExtractIconsA);
	LhSetExclusiveACL(HookPrivateExtractIconsA_ACLEntries, 1, &&hHookPrivateExtractIconsA);

	LhInstallHook(pLoadCursorA, fake_LoadCursorA, NULL, &hHookLoadCursorA);
	LhSetExclusiveACL(HookLoadCursorA_ACLEntries, 1, &&hHookLoadCursorA);

	LhInstallHook(pCreateWindowExW, fake_CreateWindowExW, NULL, &hHookCreateWindowExW);
	LhSetExclusiveACL(HookCreateWindowExW_ACLEntries, 1, &&hHookCreateWindowExW);

	LhInstallHook(pCharLowerW, fake_CharLowerW, NULL, &hHookCharLowerW);
	LhSetExclusiveACL(HookCharLowerW_ACLEntries, 1, &&hHookCharLowerW);

	LhInstallHook(pCreateDialogParamA, fake_CreateDialogParamA, NULL, &hHookCreateDialogParamA);
	LhSetExclusiveACL(HookCreateDialogParamA_ACLEntries, 1, &&hHookCreateDialogParamA);

	LhInstallHook(pMonitorFromWindow, fake_MonitorFromWindow, NULL, &hHookMonitorFromWindow);
	LhSetExclusiveACL(HookMonitorFromWindow_ACLEntries, 1, &&hHookMonitorFromWindow);

	LhInstallHook(pMonitorFromPoint, fake_MonitorFromPoint, NULL, &hHookMonitorFromPoint);
	LhSetExclusiveACL(HookMonitorFromPoint_ACLEntries, 1, &&hHookMonitorFromPoint);

	LhInstallHook(pSetActiveWindow, fake_SetActiveWindow, NULL, &hHookSetActiveWindow);
	LhSetExclusiveACL(HookSetActiveWindow_ACLEntries, 1, &&hHookSetActiveWindow);

	LhInstallHook(pLoadCursorFromFileW, fake_LoadCursorFromFileW, NULL, &hHookLoadCursorFromFileW);
	LhSetExclusiveACL(HookLoadCursorFromFileW_ACLEntries, 1, &&hHookLoadCursorFromFileW);

	LhInstallHook(pChangeWindowMessageFilter, fake_ChangeWindowMessageFilter, NULL, &hHookChangeWindowMessageFilter);
	LhSetExclusiveACL(HookChangeWindowMessageFilter_ACLEntries, 1, &&hHookChangeWindowMessageFilter);

	LhInstallHook(pGetGestureInfo, fake_GetGestureInfo, NULL, &hHookGetGestureInfo);
	LhSetExclusiveACL(HookGetGestureInfo_ACLEntries, 1, &&hHookGetGestureInfo);

	LhInstallHook(pSetWindowRgn, fake_SetWindowRgn, NULL, &hHookSetWindowRgn);
	LhSetExclusiveACL(HookSetWindowRgn_ACLEntries, 1, &&hHookSetWindowRgn);

	LhInstallHook(pSetWindowsHookW, fake_SetWindowsHookW, NULL, &hHookSetWindowsHookW);
	LhSetExclusiveACL(HookSetWindowsHookW_ACLEntries, 1, &&hHookSetWindowsHookW);

	LhInstallHook(pInsertMenuA, fake_InsertMenuA, NULL, &hHookInsertMenuA);
	LhSetExclusiveACL(HookInsertMenuA_ACLEntries, 1, &&hHookInsertMenuA);

	LhInstallHook(pLoadCursorFromFileA, fake_LoadCursorFromFileA, NULL, &hHookLoadCursorFromFileA);
	LhSetExclusiveACL(HookLoadCursorFromFileA_ACLEntries, 1, &&hHookLoadCursorFromFileA);

	LhInstallHook(pCreateIcon, fake_CreateIcon, NULL, &hHookCreateIcon);
	LhSetExclusiveACL(HookCreateIcon_ACLEntries, 1, &&hHookCreateIcon);

	LhInstallHook(pDestroyAcceleratorTable, fake_DestroyAcceleratorTable, NULL, &hHookDestroyAcceleratorTable);
	LhSetExclusiveACL(HookDestroyAcceleratorTable_ACLEntries, 1, &&hHookDestroyAcceleratorTable);

	LhInstallHook(pRegisterClipboardFormatA, fake_RegisterClipboardFormatA, NULL, &hHookRegisterClipboardFormatA);
	LhSetExclusiveACL(HookRegisterClipboardFormatA_ACLEntries, 1, &&hHookRegisterClipboardFormatA);

	LhInstallHook(pBlockInput, fake_BlockInput, NULL, &hHookBlockInput);
	LhSetExclusiveACL(HookBlockInput_ACLEntries, 1, &&hHookBlockInput);

	LhInstallHook(pGetCursorInfo, fake_GetCursorInfo, NULL, &hHookGetCursorInfo);
	LhSetExclusiveACL(HookGetCursorInfo_ACLEntries, 1, &&hHookGetCursorInfo);

	LhInstallHook(pCloseDesktop, fake_CloseDesktop, NULL, &hHookCloseDesktop);
	LhSetExclusiveACL(HookCloseDesktop_ACLEntries, 1, &&hHookCloseDesktop);

	LhInstallHook(pUnloadKeyboardLayout, fake_UnloadKeyboardLayout, NULL, &hHookUnloadKeyboardLayout);
	LhSetExclusiveACL(HookUnloadKeyboardLayout_ACLEntries, 1, &&hHookUnloadKeyboardLayout);

	LhInstallHook(pSetWindowLongA, fake_SetWindowLongA, NULL, &hHookSetWindowLongA);
	LhSetExclusiveACL(HookSetWindowLongA_ACLEntries, 1, &&hHookSetWindowLongA);

	LhInstallHook(pGetDlgItemTextA, fake_GetDlgItemTextA, NULL, &hHookGetDlgItemTextA);
	LhSetExclusiveACL(HookGetDlgItemTextA_ACLEntries, 1, &&hHookGetDlgItemTextA);

	LhInstallHook(pCreateCaret, fake_CreateCaret, NULL, &hHookCreateCaret);
	LhSetExclusiveACL(HookCreateCaret_ACLEntries, 1, &&hHookCreateCaret);

	LhInstallHook(pGetKeyboardLayoutNameA, fake_GetKeyboardLayoutNameA, NULL, &hHookGetKeyboardLayoutNameA);
	LhSetExclusiveACL(HookGetKeyboardLayoutNameA_ACLEntries, 1, &&hHookGetKeyboardLayoutNameA);

	LhInstallHook(pGetScrollBarInfo, fake_GetScrollBarInfo, NULL, &hHookGetScrollBarInfo);
	LhSetExclusiveACL(HookGetScrollBarInfo_ACLEntries, 1, &&hHookGetScrollBarInfo);

	LhInstallHook(pTileWindows, fake_TileWindows, NULL, &hHookTileWindows);
	LhSetExclusiveACL(HookTileWindows_ACLEntries, 1, &&hHookTileWindows);

	LhInstallHook(pUnregisterClassW, fake_UnregisterClassW, NULL, &hHookUnregisterClassW);
	LhSetExclusiveACL(HookUnregisterClassW_ACLEntries, 1, &&hHookUnregisterClassW);

	LhInstallHook(pPostQuitMessage, fake_PostQuitMessage, NULL, &hHookPostQuitMessage);
	LhSetExclusiveACL(HookPostQuitMessage_ACLEntries, 1, &&hHookPostQuitMessage);

	LhInstallHook(pGrayStringW, fake_GrayStringW, NULL, &hHookGrayStringW);
	LhSetExclusiveACL(HookGrayStringW_ACLEntries, 1, &&hHookGrayStringW);

	LhInstallHook(pLoadKeyboardLayoutW, fake_LoadKeyboardLayoutW, NULL, &hHookLoadKeyboardLayoutW);
	LhSetExclusiveACL(HookLoadKeyboardLayoutW_ACLEntries, 1, &&hHookLoadKeyboardLayoutW);

	LhInstallHook(pWindowFromPoint, fake_WindowFromPoint, NULL, &hHookWindowFromPoint);
	LhSetExclusiveACL(HookWindowFromPoint_ACLEntries, 1, &&hHookWindowFromPoint);

	LhInstallHook(pGetKeyState, fake_GetKeyState, NULL, &hHookGetKeyState);
	LhSetExclusiveACL(HookGetKeyState_ACLEntries, 1, &&hHookGetKeyState);

	LhInstallHook(pSetCaretBlinkTime, fake_SetCaretBlinkTime, NULL, &hHookSetCaretBlinkTime);
	LhSetExclusiveACL(HookSetCaretBlinkTime_ACLEntries, 1, &&hHookSetCaretBlinkTime);

	LhInstallHook(pNotifyWinEvent, fake_NotifyWinEvent, NULL, &hHookNotifyWinEvent);
	LhSetExclusiveACL(HookNotifyWinEvent_ACLEntries, 1, &&hHookNotifyWinEvent);

	LhInstallHook(pGetCaretPos, fake_GetCaretPos, NULL, &hHookGetCaretPos);
	LhSetExclusiveACL(HookGetCaretPos_ACLEntries, 1, &&hHookGetCaretPos);

	LhInstallHook(pSetCaretPos, fake_SetCaretPos, NULL, &hHookSetCaretPos);
	LhSetExclusiveACL(HookSetCaretPos_ACLEntries, 1, &&hHookSetCaretPos);

	LhInstallHook(pSetDisplayConfig, fake_SetDisplayConfig, NULL, &hHookSetDisplayConfig);
	LhSetExclusiveACL(HookSetDisplayConfig_ACLEntries, 1, &&hHookSetDisplayConfig);

	LhInstallHook(pGetAncestor, fake_GetAncestor, NULL, &hHookGetAncestor);
	LhSetExclusiveACL(HookGetAncestor_ACLEntries, 1, &&hHookGetAncestor);

	LhInstallHook(pExcludeUpdateRgn, fake_ExcludeUpdateRgn, NULL, &hHookExcludeUpdateRgn);
	LhSetExclusiveACL(HookExcludeUpdateRgn_ACLEntries, 1, &&hHookExcludeUpdateRgn);

	LhInstallHook(pOemKeyScan, fake_OemKeyScan, NULL, &hHookOemKeyScan);
	LhSetExclusiveACL(HookOemKeyScan_ACLEntries, 1, &&hHookOemKeyScan);

	LhInstallHook(pCallWindowProcA, fake_CallWindowProcA, NULL, &hHookCallWindowProcA);
	LhSetExclusiveACL(HookCallWindowProcA_ACLEntries, 1, &&hHookCallWindowProcA);

	LhInstallHook(pGetWindowLongA, fake_GetWindowLongA, NULL, &hHookGetWindowLongA);
	LhSetExclusiveACL(HookGetWindowLongA_ACLEntries, 1, &&hHookGetWindowLongA);

	LhInstallHook(pGetScrollRange, fake_GetScrollRange, NULL, &hHookGetScrollRange);
	LhSetExclusiveACL(HookGetScrollRange_ACLEntries, 1, &&hHookGetScrollRange);

	LhInstallHook(pTranslateAcceleratorW, fake_TranslateAcceleratorW, NULL, &hHookTranslateAcceleratorW);
	LhSetExclusiveACL(HookTranslateAcceleratorW_ACLEntries, 1, &&hHookTranslateAcceleratorW);

	LhInstallHook(pLoadImageA, fake_LoadImageA, NULL, &hHookLoadImageA);
	LhSetExclusiveACL(HookLoadImageA_ACLEntries, 1, &&hHookLoadImageA);

	LhInstallHook(pDrawTextA, fake_DrawTextA, NULL, &hHookDrawTextA);
	LhSetExclusiveACL(HookDrawTextA_ACLEntries, 1, &&hHookDrawTextA);

	LhInstallHook(pSetWindowTextA, fake_SetWindowTextA, NULL, &hHookSetWindowTextA);
	LhSetExclusiveACL(HookSetWindowTextA_ACLEntries, 1, &&hHookSetWindowTextA);

	LhInstallHook(pGetTabbedTextExtentW, fake_GetTabbedTextExtentW, NULL, &hHookGetTabbedTextExtentW);
	LhSetExclusiveACL(HookGetTabbedTextExtentW_ACLEntries, 1, &&hHookGetTabbedTextExtentW);

	LhInstallHook(pOpenInputDesktop, fake_OpenInputDesktop, NULL, &hHookOpenInputDesktop);
	LhSetExclusiveACL(HookOpenInputDesktop_ACLEntries, 1, &&hHookOpenInputDesktop);

	LhInstallHook(pGetShellWindow, fake_GetShellWindow, NULL, &hHookGetShellWindow);
	LhSetExclusiveACL(HookGetShellWindow_ACLEntries, 1, &&hHookGetShellWindow);

	LhInstallHook(pGetMenuStringW, fake_GetMenuStringW, NULL, &hHookGetMenuStringW);
	LhSetExclusiveACL(HookGetMenuStringW_ACLEntries, 1, &&hHookGetMenuStringW);

	LhInstallHook(pGetUpdateRgn, fake_GetUpdateRgn, NULL, &hHookGetUpdateRgn);
	LhSetExclusiveACL(HookGetUpdateRgn_ACLEntries, 1, &&hHookGetUpdateRgn);

	LhInstallHook(pGetDlgCtrlID, fake_GetDlgCtrlID, NULL, &hHookGetDlgCtrlID);
	LhSetExclusiveACL(HookGetDlgCtrlID_ACLEntries, 1, &&hHookGetDlgCtrlID);

	LhInstallHook(pValidateRgn, fake_ValidateRgn, NULL, &hHookValidateRgn);
	LhSetExclusiveACL(HookValidateRgn_ACLEntries, 1, &&hHookValidateRgn);

	LhInstallHook(pCopyRect, fake_CopyRect, NULL, &hHookCopyRect);
	LhSetExclusiveACL(HookCopyRect_ACLEntries, 1, &&hHookCopyRect);

	LhInstallHook(pSendMessageA, fake_SendMessageA, NULL, &hHookSendMessageA);
	LhSetExclusiveACL(HookSendMessageA_ACLEntries, 1, &&hHookSendMessageA);

	LhInstallHook(pAddClipboardFormatListener, fake_AddClipboardFormatListener, NULL, &hHookAddClipboardFormatListener);
	LhSetExclusiveACL(HookAddClipboardFormatListener_ACLEntries, 1, &&hHookAddClipboardFormatListener);

	LhInstallHook(pOpenWindowStationA, fake_OpenWindowStationA, NULL, &hHookOpenWindowStationA);
	LhSetExclusiveACL(HookOpenWindowStationA_ACLEntries, 1, &&hHookOpenWindowStationA);

	LhInstallHook(pGetDialogBaseUnits, fake_GetDialogBaseUnits, NULL, &hHookGetDialogBaseUnits);
	LhSetExclusiveACL(HookGetDialogBaseUnits_ACLEntries, 1, &&hHookGetDialogBaseUnits);

	LhInstallHook(pDrawCaption, fake_DrawCaption, NULL, &hHookDrawCaption);
	LhSetExclusiveACL(HookDrawCaption_ACLEntries, 1, &&hHookDrawCaption);

	LhInstallHook(pGetWindowTextLengthW, fake_GetWindowTextLengthW, NULL, &hHookGetWindowTextLengthW);
	LhSetExclusiveACL(HookGetWindowTextLengthW_ACLEntries, 1, &&hHookGetWindowTextLengthW);

	LhInstallHook(pGetDisplayConfigBufferSizes, fake_GetDisplayConfigBufferSizes, NULL, &hHookGetDisplayConfigBufferSizes);
	LhSetExclusiveACL(HookGetDisplayConfigBufferSizes_ACLEntries, 1, &&hHookGetDisplayConfigBufferSizes);

	LhInstallHook(pRegisterHotKey, fake_RegisterHotKey, NULL, &hHookRegisterHotKey);
	LhSetExclusiveACL(HookRegisterHotKey_ACLEntries, 1, &&hHookRegisterHotKey);

	LhInstallHook(pGetClassInfoW, fake_GetClassInfoW, NULL, &hHookGetClassInfoW);
	LhSetExclusiveACL(HookGetClassInfoW_ACLEntries, 1, &&hHookGetClassInfoW);

	LhInstallHook(pEnumChildWindows, fake_EnumChildWindows, NULL, &hHookEnumChildWindows);
	LhSetExclusiveACL(HookEnumChildWindows_ACLEntries, 1, &&hHookEnumChildWindows);

	LhInstallHook(pCharPrevA, fake_CharPrevA, NULL, &hHookCharPrevA);
	LhSetExclusiveACL(HookCharPrevA_ACLEntries, 1, &&hHookCharPrevA);

	LhInstallHook(pGetProcessWindowStation, fake_GetProcessWindowStation, NULL, &hHookGetProcessWindowStation);
	LhSetExclusiveACL(HookGetProcessWindowStation_ACLEntries, 1, &&hHookGetProcessWindowStation);

	LhInstallHook(pMapVirtualKeyA, fake_MapVirtualKeyA, NULL, &hHookMapVirtualKeyA);
	LhSetExclusiveACL(HookMapVirtualKeyA_ACLEntries, 1, &&hHookMapVirtualKeyA);

	LhInstallHook(pUnhookWindowsHook, fake_UnhookWindowsHook, NULL, &hHookUnhookWindowsHook);
	LhSetExclusiveACL(HookUnhookWindowsHook_ACLEntries, 1, &&hHookUnhookWindowsHook);

	LhInstallHook(pCharToOemBuffA, fake_CharToOemBuffA, NULL, &hHookCharToOemBuffA);
	LhSetExclusiveACL(HookCharToOemBuffA_ACLEntries, 1, &&hHookCharToOemBuffA);

	LhInstallHook(pMapWindowPoints, fake_MapWindowPoints, NULL, &hHookMapWindowPoints);
	LhSetExclusiveACL(HookMapWindowPoints_ACLEntries, 1, &&hHookMapWindowPoints);

	LhInstallHook(pCharUpperW, fake_CharUpperW, NULL, &hHookCharUpperW);
	LhSetExclusiveACL(HookCharUpperW_ACLEntries, 1, &&hHookCharUpperW);

	LhInstallHook(pWaitForInputIdle, fake_WaitForInputIdle, NULL, &hHookWaitForInputIdle);
	LhSetExclusiveACL(HookWaitForInputIdle_ACLEntries, 1, &&hHookWaitForInputIdle);

	LhInstallHook(pMessageBoxA, fake_MessageBoxA, NULL, &hHookMessageBoxA);
	LhSetExclusiveACL(HookMessageBoxA_ACLEntries, 1, &&hHookMessageBoxA);

	LhInstallHook(pSendNotifyMessageW, fake_SendNotifyMessageW, NULL, &hHookSendNotifyMessageW);
	LhSetExclusiveACL(HookSendNotifyMessageW_ACLEntries, 1, &&hHookSendNotifyMessageW);

	LhInstallHook(pFindWindowW, fake_FindWindowW, NULL, &hHookFindWindowW);
	LhSetExclusiveACL(HookFindWindowW_ACLEntries, 1, &&hHookFindWindowW);

	LhInstallHook(pCallMsgFilterW, fake_CallMsgFilterW, NULL, &hHookCallMsgFilterW);
	LhSetExclusiveACL(HookCallMsgFilterW_ACLEntries, 1, &&hHookCallMsgFilterW);

	LhInstallHook(pRegisterRawInputDevices, fake_RegisterRawInputDevices, NULL, &hHookRegisterRawInputDevices);
	LhSetExclusiveACL(HookRegisterRawInputDevices_ACLEntries, 1, &&hHookRegisterRawInputDevices);

	LhInstallHook(pGetSubMenu, fake_GetSubMenu, NULL, &hHookGetSubMenu);
	LhSetExclusiveACL(HookGetSubMenu_ACLEntries, 1, &&hHookGetSubMenu);

	LhInstallHook(pVkKeyScanExA, fake_VkKeyScanExA, NULL, &hHookVkKeyScanExA);
	LhSetExclusiveACL(HookVkKeyScanExA_ACLEntries, 1, &&hHookVkKeyScanExA);

	LhInstallHook(pGetUpdateRect, fake_GetUpdateRect, NULL, &hHookGetUpdateRect);
	LhSetExclusiveACL(HookGetUpdateRect_ACLEntries, 1, &&hHookGetUpdateRect);

	LhInstallHook(pDrawStateW, fake_DrawStateW, NULL, &hHookDrawStateW);
	LhSetExclusiveACL(HookDrawStateW_ACLEntries, 1, &&hHookDrawStateW);

	LhInstallHook(pGetClassLongPtrA, fake_GetClassLongPtrA, NULL, &hHookGetClassLongPtrA);
	LhSetExclusiveACL(HookGetClassLongPtrA_ACLEntries, 1, &&hHookGetClassLongPtrA);

	LhInstallHook(pTrackMouseEvent, fake_TrackMouseEvent, NULL, &hHookTrackMouseEvent);
	LhSetExclusiveACL(HookTrackMouseEvent_ACLEntries, 1, &&hHookTrackMouseEvent);

	LhInstallHook(pSetKeyboardState, fake_SetKeyboardState, NULL, &hHookSetKeyboardState);
	LhSetExclusiveACL(HookSetKeyboardState_ACLEntries, 1, &&hHookSetKeyboardState);

	LhInstallHook(pUpdateWindow, fake_UpdateWindow, NULL, &hHookUpdateWindow);
	LhSetExclusiveACL(HookUpdateWindow_ACLEntries, 1, &&hHookUpdateWindow);

	LhInstallHook(pChildWindowFromPoint, fake_ChildWindowFromPoint, NULL, &hHookChildWindowFromPoint);
	LhSetExclusiveACL(HookChildWindowFromPoint_ACLEntries, 1, &&hHookChildWindowFromPoint);

	LhInstallHook(pScrollWindowEx, fake_ScrollWindowEx, NULL, &hHookScrollWindowEx);
	LhSetExclusiveACL(HookScrollWindowEx_ACLEntries, 1, &&hHookScrollWindowEx);

	LhInstallHook(pGetMessagePos, fake_GetMessagePos, NULL, &hHookGetMessagePos);
	LhSetExclusiveACL(HookGetMessagePos_ACLEntries, 1, &&hHookGetMessagePos);

	LhInstallHook(pMapDialogRect, fake_MapDialogRect, NULL, &hHookMapDialogRect);
	LhSetExclusiveACL(HookMapDialogRect_ACLEntries, 1, &&hHookMapDialogRect);

	LhInstallHook(pChangeClipboardChain, fake_ChangeClipboardChain, NULL, &hHookChangeClipboardChain);
	LhSetExclusiveACL(HookChangeClipboardChain_ACLEntries, 1, &&hHookChangeClipboardChain);

	LhInstallHook(pLoadBitmapA, fake_LoadBitmapA, NULL, &hHookLoadBitmapA);
	LhSetExclusiveACL(HookLoadBitmapA_ACLEntries, 1, &&hHookLoadBitmapA);

	LhInstallHook(pCascadeWindows, fake_CascadeWindows, NULL, &hHookCascadeWindows);
	LhSetExclusiveACL(HookCascadeWindows_ACLEntries, 1, &&hHookCascadeWindows);

	LhInstallHook(pGetThreadDesktop, fake_GetThreadDesktop, NULL, &hHookGetThreadDesktop);
	LhSetExclusiveACL(HookGetThreadDesktop_ACLEntries, 1, &&hHookGetThreadDesktop);

	LhInstallHook(pGetUpdatedClipboardFormats, fake_GetUpdatedClipboardFormats, NULL, &hHookGetUpdatedClipboardFormats);
	LhSetExclusiveACL(HookGetUpdatedClipboardFormats_ACLEntries, 1, &&hHookGetUpdatedClipboardFormats);

	LhInstallHook(pShutdownBlockReasonCreate, fake_ShutdownBlockReasonCreate, NULL, &hHookShutdownBlockReasonCreate);
	LhSetExclusiveACL(HookShutdownBlockReasonCreate_ACLEntries, 1, &&hHookShutdownBlockReasonCreate);

	LhInstallHook(pGetKBCodePage, fake_GetKBCodePage, NULL, &hHookGetKBCodePage);
	LhSetExclusiveACL(HookGetKBCodePage_ACLEntries, 1, &&hHookGetKBCodePage);

	LhInstallHook(pEnumClipboardFormats, fake_EnumClipboardFormats, NULL, &hHookEnumClipboardFormats);
	LhSetExclusiveACL(HookEnumClipboardFormats_ACLEntries, 1, &&hHookEnumClipboardFormats);

	LhInstallHook(pLoadIconA, fake_LoadIconA, NULL, &hHookLoadIconA);
	LhSetExclusiveACL(HookLoadIconA_ACLEntries, 1, &&hHookLoadIconA);

	LhInstallHook(pInvertRect, fake_InvertRect, NULL, &hHookInvertRect);
	LhSetExclusiveACL(HookInvertRect_ACLEntries, 1, &&hHookInvertRect);

	LhInstallHook(pEndPaint, fake_EndPaint, NULL, &hHookEndPaint);
	LhSetExclusiveACL(HookEndPaint_ACLEntries, 1, &&hHookEndPaint);

	LhInstallHook(pShutdownBlockReasonDestroy, fake_ShutdownBlockReasonDestroy, NULL, &hHookShutdownBlockReasonDestroy);
	LhSetExclusiveACL(HookShutdownBlockReasonDestroy_ACLEntries, 1, &&hHookShutdownBlockReasonDestroy);

	LhInstallHook(pAdjustWindowRect, fake_AdjustWindowRect, NULL, &hHookAdjustWindowRect);
	LhSetExclusiveACL(HookAdjustWindowRect_ACLEntries, 1, &&hHookAdjustWindowRect);

	LhInstallHook(pWindowFromPhysicalPoint, fake_WindowFromPhysicalPoint, NULL, &hHookWindowFromPhysicalPoint);
	LhSetExclusiveACL(HookWindowFromPhysicalPoint_ACLEntries, 1, &&hHookWindowFromPhysicalPoint);

	LhInstallHook(pGetGuiResources, fake_GetGuiResources, NULL, &hHookGetGuiResources);
	LhSetExclusiveACL(HookGetGuiResources_ACLEntries, 1, &&hHookGetGuiResources);

	LhInstallHook(pRegisterWindowMessageW, fake_RegisterWindowMessageW, NULL, &hHookRegisterWindowMessageW);
	LhSetExclusiveACL(HookRegisterWindowMessageW_ACLEntries, 1, &&hHookRegisterWindowMessageW);

	LhInstallHook(pIsDlgButtonChecked, fake_IsDlgButtonChecked, NULL, &hHookIsDlgButtonChecked);
	LhSetExclusiveACL(HookIsDlgButtonChecked_ACLEntries, 1, &&hHookIsDlgButtonChecked);

	LhInstallHook(pRemoveClipboardFormatListener, fake_RemoveClipboardFormatListener, NULL, &hHookRemoveClipboardFormatListener);
	LhSetExclusiveACL(HookRemoveClipboardFormatListener_ACLEntries, 1, &&hHookRemoveClipboardFormatListener);

	LhInstallHook(pGetWindowRgn, fake_GetWindowRgn, NULL, &hHookGetWindowRgn);
	LhSetExclusiveACL(HookGetWindowRgn_ACLEntries, 1, &&hHookGetWindowRgn);

	LhInstallHook(pGetAltTabInfoA, fake_GetAltTabInfoA, NULL, &hHookGetAltTabInfoA);
	LhSetExclusiveACL(HookGetAltTabInfoA_ACLEntries, 1, &&hHookGetAltTabInfoA);

	LhInstallHook(pCharUpperA, fake_CharUpperA, NULL, &hHookCharUpperA);
	LhSetExclusiveACL(HookCharUpperA_ACLEntries, 1, &&hHookCharUpperA);

	LhInstallHook(pIsWow64Message, fake_IsWow64Message, NULL, &hHookIsWow64Message);
	LhSetExclusiveACL(HookIsWow64Message_ACLEntries, 1, &&hHookIsWow64Message);

	LhInstallHook(pSetMenuContextHelpId, fake_SetMenuContextHelpId, NULL, &hHookSetMenuContextHelpId);
	LhSetExclusiveACL(HookSetMenuContextHelpId_ACLEntries, 1, &&hHookSetMenuContextHelpId);

	LhInstallHook(pIsIconic, fake_IsIconic, NULL, &hHookIsIconic);
	LhSetExclusiveACL(HookIsIconic_ACLEntries, 1, &&hHookIsIconic);

	LhInstallHook(pSetGestureConfig, fake_SetGestureConfig, NULL, &hHookSetGestureConfig);
	LhSetExclusiveACL(HookSetGestureConfig_ACLEntries, 1, &&hHookSetGestureConfig);

	LhInstallHook(pSendDlgItemMessageA, fake_SendDlgItemMessageA, NULL, &hHookSendDlgItemMessageA);
	LhSetExclusiveACL(HookSendDlgItemMessageA_ACLEntries, 1, &&hHookSendDlgItemMessageA);

	LhInstallHook(pTabbedTextOutA, fake_TabbedTextOutA, NULL, &hHookTabbedTextOutA);
	LhSetExclusiveACL(HookTabbedTextOutA_ACLEntries, 1, &&hHookTabbedTextOutA);

	LhInstallHook(pSetMenu, fake_SetMenu, NULL, &hHookSetMenu);
	LhSetExclusiveACL(HookSetMenu_ACLEntries, 1, &&hHookSetMenu);

	LhInstallHook(pMonitorFromRect, fake_MonitorFromRect, NULL, &hHookMonitorFromRect);
	LhSetExclusiveACL(HookMonitorFromRect_ACLEntries, 1, &&hHookMonitorFromRect);

	LhInstallHook(pUnionRect, fake_UnionRect, NULL, &hHookUnionRect);
	LhSetExclusiveACL(HookUnionRect_ACLEntries, 1, &&hHookUnionRect);

	LhInstallHook(pPostThreadMessageW, fake_PostThreadMessageW, NULL, &hHookPostThreadMessageW);
	LhSetExclusiveACL(HookPostThreadMessageW_ACLEntries, 1, &&hHookPostThreadMessageW);

	LhInstallHook(pGetUserObjectInformationA, fake_GetUserObjectInformationA, NULL, &hHookGetUserObjectInformationA);
	LhSetExclusiveACL(HookGetUserObjectInformationA_ACLEntries, 1, &&hHookGetUserObjectInformationA);

	LhInstallHook(pChangeMenuW, fake_ChangeMenuW, NULL, &hHookChangeMenuW);
	LhSetExclusiveACL(HookChangeMenuW_ACLEntries, 1, &&hHookChangeMenuW);

	LhInstallHook(pRemovePropA, fake_RemovePropA, NULL, &hHookRemovePropA);
	LhSetExclusiveACL(HookRemovePropA_ACLEntries, 1, &&hHookRemovePropA);

	LhInstallHook(pGetClientRect, fake_GetClientRect, NULL, &hHookGetClientRect);
	LhSetExclusiveACL(HookGetClientRect_ACLEntries, 1, &&hHookGetClientRect);

	LhInstallHook(pKillTimer, fake_KillTimer, NULL, &hHookKillTimer);
	LhSetExclusiveACL(HookKillTimer_ACLEntries, 1, &&hHookKillTimer);

	LhInstallHook(pIsHungAppWindow, fake_IsHungAppWindow, NULL, &hHookIsHungAppWindow);
	LhSetExclusiveACL(HookIsHungAppWindow_ACLEntries, 1, &&hHookIsHungAppWindow);

	LhInstallHook(pHiliteMenuItem, fake_HiliteMenuItem, NULL, &hHookHiliteMenuItem);
	LhSetExclusiveACL(HookHiliteMenuItem_ACLEntries, 1, &&hHookHiliteMenuItem);

	LhInstallHook(pPeekMessageA, fake_PeekMessageA, NULL, &hHookPeekMessageA);
	LhSetExclusiveACL(HookPeekMessageA_ACLEntries, 1, &&hHookPeekMessageA);

	LhInstallHook(pSetDlgItemTextW, fake_SetDlgItemTextW, NULL, &hHookSetDlgItemTextW);
	LhSetExclusiveACL(HookSetDlgItemTextW_ACLEntries, 1, &&hHookSetDlgItemTextW);

	LhInstallHook(pDialogBoxIndirectParamW, fake_DialogBoxIndirectParamW, NULL, &hHookDialogBoxIndirectParamW);
	LhSetExclusiveACL(HookDialogBoxIndirectParamW_ACLEntries, 1, &&hHookDialogBoxIndirectParamW);

	LhInstallHook(pGetScrollPos, fake_GetScrollPos, NULL, &hHookGetScrollPos);
	LhSetExclusiveACL(HookGetScrollPos_ACLEntries, 1, &&hHookGetScrollPos);

	LhInstallHook(pSetClassWord, fake_SetClassWord, NULL, &hHookSetClassWord);
	LhSetExclusiveACL(HookSetClassWord_ACLEntries, 1, &&hHookSetClassWord);

	LhInstallHook(pCloseClipboard, fake_CloseClipboard, NULL, &hHookCloseClipboard);
	LhSetExclusiveACL(HookCloseClipboard_ACLEntries, 1, &&hHookCloseClipboard);

	LhInstallHook(pWaitMessage, fake_WaitMessage, NULL, &hHookWaitMessage);
	LhSetExclusiveACL(HookWaitMessage_ACLEntries, 1, &&hHookWaitMessage);

	LhInstallHook(pLoadAcceleratorsW, fake_LoadAcceleratorsW, NULL, &hHookLoadAcceleratorsW);
	LhSetExclusiveACL(HookLoadAcceleratorsW_ACLEntries, 1, &&hHookLoadAcceleratorsW);

	LhInstallHook(pEnableWindow, fake_EnableWindow, NULL, &hHookEnableWindow);
	LhSetExclusiveACL(HookEnableWindow_ACLEntries, 1, &&hHookEnableWindow);

	LhInstallHook(pCreateIconFromResource, fake_CreateIconFromResource, NULL, &hHookCreateIconFromResource);
	LhSetExclusiveACL(HookCreateIconFromResource_ACLEntries, 1, &&hHookCreateIconFromResource);

	LhInstallHook(pDlgDirListComboBoxW, fake_DlgDirListComboBoxW, NULL, &hHookDlgDirListComboBoxW);
	LhSetExclusiveACL(HookDlgDirListComboBoxW_ACLEntries, 1, &&hHookDlgDirListComboBoxW);

	LhInstallHook(pIsTouchWindow, fake_IsTouchWindow, NULL, &hHookIsTouchWindow);
	LhSetExclusiveACL(HookIsTouchWindow_ACLEntries, 1, &&hHookIsTouchWindow);

	LhInstallHook(pIsChild, fake_IsChild, NULL, &hHookIsChild);
	LhSetExclusiveACL(HookIsChild_ACLEntries, 1, &&hHookIsChild);

	LhInstallHook(pEmptyClipboard, fake_EmptyClipboard, NULL, &hHookEmptyClipboard);
	LhSetExclusiveACL(HookEmptyClipboard_ACLEntries, 1, &&hHookEmptyClipboard);

	LhInstallHook(pGetLastInputInfo, fake_GetLastInputInfo, NULL, &hHookGetLastInputInfo);
	LhSetExclusiveACL(HookGetLastInputInfo_ACLEntries, 1, &&hHookGetLastInputInfo);

	LhInstallHook(pPostMessageA, fake_PostMessageA, NULL, &hHookPostMessageA);
	LhSetExclusiveACL(HookPostMessageA_ACLEntries, 1, &&hHookPostMessageA);

	LhInstallHook(pDestroyMenu, fake_DestroyMenu, NULL, &hHookDestroyMenu);
	LhSetExclusiveACL(HookDestroyMenu_ACLEntries, 1, &&hHookDestroyMenu);

	LhInstallHook(pGetIconInfoExA, fake_GetIconInfoExA, NULL, &hHookGetIconInfoExA);
	LhSetExclusiveACL(HookGetIconInfoExA_ACLEntries, 1, &&hHookGetIconInfoExA);

	LhInstallHook(pCallMsgFilterA, fake_CallMsgFilterA, NULL, &hHookCallMsgFilterA);
	LhSetExclusiveACL(HookCallMsgFilterA_ACLEntries, 1, &&hHookCallMsgFilterA);

	LhInstallHook(pIsDialogMessageA, fake_IsDialogMessageA, NULL, &hHookIsDialogMessageA);
	LhSetExclusiveACL(HookIsDialogMessageA_ACLEntries, 1, &&hHookIsDialogMessageA);

	LhInstallHook(pGetSysColor, fake_GetSysColor, NULL, &hHookGetSysColor);
	LhSetExclusiveACL(HookGetSysColor_ACLEntries, 1, &&hHookGetSysColor);

	LhInstallHook(pEnumDisplaySettingsW, fake_EnumDisplaySettingsW, NULL, &hHookEnumDisplaySettingsW);
	LhSetExclusiveACL(HookEnumDisplaySettingsW_ACLEntries, 1, &&hHookEnumDisplaySettingsW);

	LhInstallHook(pInvalidateRect, fake_InvalidateRect, NULL, &hHookInvalidateRect);
	LhSetExclusiveACL(HookInvalidateRect_ACLEntries, 1, &&hHookInvalidateRect);

	LhInstallHook(pAnyPopup, fake_AnyPopup, NULL, &hHookAnyPopup);
	LhSetExclusiveACL(HookAnyPopup_ACLEntries, 1, &&hHookAnyPopup);

	LhInstallHook(pBroadcastSystemMessage, fake_BroadcastSystemMessage, NULL, &hHookBroadcastSystemMessage);
	LhSetExclusiveACL(HookBroadcastSystemMessage_ACLEntries, 1, &&hHookBroadcastSystemMessage);

	LhInstallHook(pGetClassLongPtrW, fake_GetClassLongPtrW, NULL, &hHookGetClassLongPtrW);
	LhSetExclusiveACL(HookGetClassLongPtrW_ACLEntries, 1, &&hHookGetClassLongPtrW);

	LhInstallHook(pGetDlgItemTextW, fake_GetDlgItemTextW, NULL, &hHookGetDlgItemTextW);
	LhSetExclusiveACL(HookGetDlgItemTextW_ACLEntries, 1, &&hHookGetDlgItemTextW);

	LhInstallHook(pPrivateExtractIconsW, fake_PrivateExtractIconsW, NULL, &hHookPrivateExtractIconsW);
	LhSetExclusiveACL(HookPrivateExtractIconsW_ACLEntries, 1, &&hHookPrivateExtractIconsW);

	LhInstallHook(pUpdateLayeredWindowIndirect, fake_UpdateLayeredWindowIndirect, NULL, &hHookUpdateLayeredWindowIndirect);
	LhSetExclusiveACL(HookUpdateLayeredWindowIndirect_ACLEntries, 1, &&hHookUpdateLayeredWindowIndirect);

	LhInstallHook(pSetPhysicalCursorPos, fake_SetPhysicalCursorPos, NULL, &hHookSetPhysicalCursorPos);
	LhSetExclusiveACL(HookSetPhysicalCursorPos_ACLEntries, 1, &&hHookSetPhysicalCursorPos);

	LhInstallHook(pSetLayeredWindowAttributes, fake_SetLayeredWindowAttributes, NULL, &hHookSetLayeredWindowAttributes);
	LhSetExclusiveACL(HookSetLayeredWindowAttributes_ACLEntries, 1, &&hHookSetLayeredWindowAttributes);

	LhInstallHook(pSetWindowWord, fake_SetWindowWord, NULL, &hHookSetWindowWord);
	LhSetExclusiveACL(HookSetWindowWord_ACLEntries, 1, &&hHookSetWindowWord);

	LhInstallHook(pDeregisterShellHookWindow, fake_DeregisterShellHookWindow, NULL, &hHookDeregisterShellHookWindow);
	LhSetExclusiveACL(HookDeregisterShellHookWindow_ACLEntries, 1, &&hHookDeregisterShellHookWindow);

	LhInstallHook(pLoadAcceleratorsA, fake_LoadAcceleratorsA, NULL, &hHookLoadAcceleratorsA);
	LhSetExclusiveACL(HookLoadAcceleratorsA_ACLEntries, 1, &&hHookLoadAcceleratorsA);

	LhInstallHook(pDragObject, fake_DragObject, NULL, &hHookDragObject);
	LhSetExclusiveACL(HookDragObject_ACLEntries, 1, &&hHookDragObject);

	LhInstallHook(pRemovePropW, fake_RemovePropW, NULL, &hHookRemovePropW);
	LhSetExclusiveACL(HookRemovePropW_ACLEntries, 1, &&hHookRemovePropW);

	LhInstallHook(pIsCharUpperA, fake_IsCharUpperA, NULL, &hHookIsCharUpperA);
	LhSetExclusiveACL(HookIsCharUpperA_ACLEntries, 1, &&hHookIsCharUpperA);

	LhInstallHook(pDlgDirSelectExA, fake_DlgDirSelectExA, NULL, &hHookDlgDirSelectExA);
	LhSetExclusiveACL(HookDlgDirSelectExA_ACLEntries, 1, &&hHookDlgDirSelectExA);

	LhInstallHook(pCloseTouchInputHandle, fake_CloseTouchInputHandle, NULL, &hHookCloseTouchInputHandle);
	LhSetExclusiveACL(HookCloseTouchInputHandle_ACLEntries, 1, &&hHookCloseTouchInputHandle);

	LhInstallHook(pChangeDisplaySettingsA, fake_ChangeDisplaySettingsA, NULL, &hHookChangeDisplaySettingsA);
	LhSetExclusiveACL(HookChangeDisplaySettingsA_ACLEntries, 1, &&hHookChangeDisplaySettingsA);

	LhInstallHook(pScreenToClient, fake_ScreenToClient, NULL, &hHookScreenToClient);
	LhSetExclusiveACL(HookScreenToClient_ACLEntries, 1, &&hHookScreenToClient);

	LhInstallHook(pModifyMenuW, fake_ModifyMenuW, NULL, &hHookModifyMenuW);
	LhSetExclusiveACL(HookModifyMenuW_ACLEntries, 1, &&hHookModifyMenuW);

	LhInstallHook(pMessageBoxExW, fake_MessageBoxExW, NULL, &hHookMessageBoxExW);
	LhSetExclusiveACL(HookMessageBoxExW_ACLEntries, 1, &&hHookMessageBoxExW);

	LhInstallHook(pkeybd_event, fake_keybd_event, NULL, &hHookkeybd_event);
	LhSetExclusiveACL(Hookkeybd_event_ACLEntries, 1, &&hHookkeybd_event);

	LhInstallHook(pLockSetForegroundWindow, fake_LockSetForegroundWindow, NULL, &hHookLockSetForegroundWindow);
	LhSetExclusiveACL(HookLockSetForegroundWindow_ACLEntries, 1, &&hHookLockSetForegroundWindow);

	LhInstallHook(pGetMenuCheckMarkDimensions, fake_GetMenuCheckMarkDimensions, NULL, &hHookGetMenuCheckMarkDimensions);
	LhSetExclusiveACL(HookGetMenuCheckMarkDimensions_ACLEntries, 1, &&hHookGetMenuCheckMarkDimensions);

	LhInstallHook(pSetClassLongW, fake_SetClassLongW, NULL, &hHookSetClassLongW);
	LhSetExclusiveACL(HookSetClassLongW_ACLEntries, 1, &&hHookSetClassLongW);

	LhInstallHook(pCharNextW, fake_CharNextW, NULL, &hHookCharNextW);
	LhSetExclusiveACL(HookCharNextW_ACLEntries, 1, &&hHookCharNextW);

	LhInstallHook(pLogicalToPhysicalPoint, fake_LogicalToPhysicalPoint, NULL, &hHookLogicalToPhysicalPoint);
	LhSetExclusiveACL(HookLogicalToPhysicalPoint_ACLEntries, 1, &&hHookLogicalToPhysicalPoint);

	LhInstallHook(pLoadCursorW, fake_LoadCursorW, NULL, &hHookLoadCursorW);
	LhSetExclusiveACL(HookLoadCursorW_ACLEntries, 1, &&hHookLoadCursorW);

	LhInstallHook(pGetClassLongW, fake_GetClassLongW, NULL, &hHookGetClassLongW);
	LhSetExclusiveACL(HookGetClassLongW_ACLEntries, 1, &&hHookGetClassLongW);

	LhInstallHook(pEnumDesktopWindows, fake_EnumDesktopWindows, NULL, &hHookEnumDesktopWindows);
	LhSetExclusiveACL(HookEnumDesktopWindows_ACLEntries, 1, &&hHookEnumDesktopWindows);

	LhInstallHook(pDefWindowProcW, fake_DefWindowProcW, NULL, &hHookDefWindowProcW);
	LhSetExclusiveACL(HookDefWindowProcW_ACLEntries, 1, &&hHookDefWindowProcW);

	LhInstallHook(pUnregisterDeviceNotification, fake_UnregisterDeviceNotification, NULL, &hHookUnregisterDeviceNotification);
	LhSetExclusiveACL(HookUnregisterDeviceNotification_ACLEntries, 1, &&hHookUnregisterDeviceNotification);

	LhInstallHook(pDlgDirSelectExW, fake_DlgDirSelectExW, NULL, &hHookDlgDirSelectExW);
	LhSetExclusiveACL(HookDlgDirSelectExW_ACLEntries, 1, &&hHookDlgDirSelectExW);

	LhInstallHook(pGetGUIThreadInfo, fake_GetGUIThreadInfo, NULL, &hHookGetGUIThreadInfo);
	LhSetExclusiveACL(HookGetGUIThreadInfo_ACLEntries, 1, &&hHookGetGUIThreadInfo);

	LhInstallHook(pCopyImage, fake_CopyImage, NULL, &hHookCopyImage);
	LhSetExclusiveACL(HookCopyImage_ACLEntries, 1, &&hHookCopyImage);

	LhInstallHook(pRealGetWindowClassW, fake_RealGetWindowClassW, NULL, &hHookRealGetWindowClassW);
	LhSetExclusiveACL(HookRealGetWindowClassW_ACLEntries, 1, &&hHookRealGetWindowClassW);

	LhInstallHook(pGetWindowPlacement, fake_GetWindowPlacement, NULL, &hHookGetWindowPlacement);
	LhSetExclusiveACL(HookGetWindowPlacement_ACLEntries, 1, &&hHookGetWindowPlacement);

	LhInstallHook(pFindWindowExW, fake_FindWindowExW, NULL, &hHookFindWindowExW);
	LhSetExclusiveACL(HookFindWindowExW_ACLEntries, 1, &&hHookFindWindowExW);

	LhInstallHook(pSetScrollPos, fake_SetScrollPos, NULL, &hHookSetScrollPos);
	LhSetExclusiveACL(HookSetScrollPos_ACLEntries, 1, &&hHookSetScrollPos);

	LhInstallHook(pTrackPopupMenu, fake_TrackPopupMenu, NULL, &hHookTrackPopupMenu);
	LhSetExclusiveACL(HookTrackPopupMenu_ACLEntries, 1, &&hHookTrackPopupMenu);

	LhInstallHook(pCharToOemA, fake_CharToOemA, NULL, &hHookCharToOemA);
	LhSetExclusiveACL(HookCharToOemA_ACLEntries, 1, &&hHookCharToOemA);

	LhInstallHook(pGetDlgItemInt, fake_GetDlgItemInt, NULL, &hHookGetDlgItemInt);
	LhSetExclusiveACL(HookGetDlgItemInt_ACLEntries, 1, &&hHookGetDlgItemInt);

	LhInstallHook(pCreateMenu, fake_CreateMenu, NULL, &hHookCreateMenu);
	LhSetExclusiveACL(HookCreateMenu_ACLEntries, 1, &&hHookCreateMenu);

	LhInstallHook(pChangeMenuA, fake_ChangeMenuA, NULL, &hHookChangeMenuA);
	LhSetExclusiveACL(HookChangeMenuA_ACLEntries, 1, &&hHookChangeMenuA);

	LhInstallHook(pCreateDesktopExW, fake_CreateDesktopExW, NULL, &hHookCreateDesktopExW);
	LhSetExclusiveACL(HookCreateDesktopExW_ACLEntries, 1, &&hHookCreateDesktopExW);

	LhInstallHook(pDialogBoxParamA, fake_DialogBoxParamA, NULL, &hHookDialogBoxParamA);
	LhSetExclusiveACL(HookDialogBoxParamA_ACLEntries, 1, &&hHookDialogBoxParamA);

	LhInstallHook(pGetProcessDefaultLayout, fake_GetProcessDefaultLayout, NULL, &hHookGetProcessDefaultLayout);
	LhSetExclusiveACL(HookGetProcessDefaultLayout_ACLEntries, 1, &&hHookGetProcessDefaultLayout);

	LhInstallHook(pGetPropA, fake_GetPropA, NULL, &hHookGetPropA);
	LhSetExclusiveACL(HookGetPropA_ACLEntries, 1, &&hHookGetPropA);

	LhInstallHook(pGetMenuInfo, fake_GetMenuInfo, NULL, &hHookGetMenuInfo);
	LhSetExclusiveACL(HookGetMenuInfo_ACLEntries, 1, &&hHookGetMenuInfo);

	LhInstallHook(pPtInRect, fake_PtInRect, NULL, &hHookPtInRect);
	LhSetExclusiveACL(HookPtInRect_ACLEntries, 1, &&hHookPtInRect);

	LhInstallHook(pCopyAcceleratorTableW, fake_CopyAcceleratorTableW, NULL, &hHookCopyAcceleratorTableW);
	LhSetExclusiveACL(HookCopyAcceleratorTableW_ACLEntries, 1, &&hHookCopyAcceleratorTableW);

	LhInstallHook(pOemToCharBuffW, fake_OemToCharBuffW, NULL, &hHookOemToCharBuffW);
	LhSetExclusiveACL(HookOemToCharBuffW_ACLEntries, 1, &&hHookOemToCharBuffW);

	LhInstallHook(pLookupIconIdFromDirectoryEx, fake_LookupIconIdFromDirectoryEx, NULL, &hHookLookupIconIdFromDirectoryEx);
	LhSetExclusiveACL(HookLookupIconIdFromDirectoryEx_ACLEntries, 1, &&hHookLookupIconIdFromDirectoryEx);

	LhInstallHook(pWinHelpW, fake_WinHelpW, NULL, &hHookWinHelpW);
	LhSetExclusiveACL(HookWinHelpW_ACLEntries, 1, &&hHookWinHelpW);

	LhInstallHook(pSetWindowLongPtrA, fake_SetWindowLongPtrA, NULL, &hHookSetWindowLongPtrA);
	LhSetExclusiveACL(HookSetWindowLongPtrA_ACLEntries, 1, &&hHookSetWindowLongPtrA);

	LhInstallHook(pCharToOemW, fake_CharToOemW, NULL, &hHookCharToOemW);
	LhSetExclusiveACL(HookCharToOemW_ACLEntries, 1, &&hHookCharToOemW);

	LhInstallHook(pCreateWindowExA, fake_CreateWindowExA, NULL, &hHookCreateWindowExA);
	LhSetExclusiveACL(HookCreateWindowExA_ACLEntries, 1, &&hHookCreateWindowExA);

	LhInstallHook(pCharPrevExA, fake_CharPrevExA, NULL, &hHookCharPrevExA);
	LhSetExclusiveACL(HookCharPrevExA_ACLEntries, 1, &&hHookCharPrevExA);

	LhInstallHook(pGetPropW, fake_GetPropW, NULL, &hHookGetPropW);
	LhSetExclusiveACL(HookGetPropW_ACLEntries, 1, &&hHookGetPropW);

	LhInstallHook(pGetWindowModuleFileNameW, fake_GetWindowModuleFileNameW, NULL, &hHookGetWindowModuleFileNameW);
	LhSetExclusiveACL(HookGetWindowModuleFileNameW_ACLEntries, 1, &&hHookGetWindowModuleFileNameW);

	LhInstallHook(pDestroyCaret, fake_DestroyCaret, NULL, &hHookDestroyCaret);
	LhSetExclusiveACL(HookDestroyCaret_ACLEntries, 1, &&hHookDestroyCaret);

	LhInstallHook(pMessageBoxIndirectW, fake_MessageBoxIndirectW, NULL, &hHookMessageBoxIndirectW);
	LhSetExclusiveACL(HookMessageBoxIndirectW_ACLEntries, 1, &&hHookMessageBoxIndirectW);

	LhInstallHook(pUnhookWindowsHookEx, fake_UnhookWindowsHookEx, NULL, &hHookUnhookWindowsHookEx);
	LhSetExclusiveACL(HookUnhookWindowsHookEx_ACLEntries, 1, &&hHookUnhookWindowsHookEx);

	LhInstallHook(pIsCharLowerW, fake_IsCharLowerW, NULL, &hHookIsCharLowerW);
	LhSetExclusiveACL(HookIsCharLowerW_ACLEntries, 1, &&hHookIsCharLowerW);

	LhInstallHook(pGetKeyboardLayout, fake_GetKeyboardLayout, NULL, &hHookGetKeyboardLayout);
	LhSetExclusiveACL(HookGetKeyboardLayout_ACLEntries, 1, &&hHookGetKeyboardLayout);

	LhInstallHook(pToUnicodeEx, fake_ToUnicodeEx, NULL, &hHookToUnicodeEx);
	LhSetExclusiveACL(HookToUnicodeEx_ACLEntries, 1, &&hHookToUnicodeEx);

	LhInstallHook(pSetUserObjectInformationW, fake_SetUserObjectInformationW, NULL, &hHookSetUserObjectInformationW);
	LhSetExclusiveACL(HookSetUserObjectInformationW_ACLEntries, 1, &&hHookSetUserObjectInformationW);

	LhInstallHook(pRealGetWindowClassA, fake_RealGetWindowClassA, NULL, &hHookRealGetWindowClassA);
	LhSetExclusiveACL(HookRealGetWindowClassA_ACLEntries, 1, &&hHookRealGetWindowClassA);

	LhInstallHook(pSetUserObjectInformationA, fake_SetUserObjectInformationA, NULL, &hHookSetUserObjectInformationA);
	LhSetExclusiveACL(HookSetUserObjectInformationA_ACLEntries, 1, &&hHookSetUserObjectInformationA);

	LhInstallHook(pGetClassInfoExA, fake_GetClassInfoExA, NULL, &hHookGetClassInfoExA);
	LhSetExclusiveACL(HookGetClassInfoExA_ACLEntries, 1, &&hHookGetClassInfoExA);

	LhInstallHook(pGetMenuBarInfo, fake_GetMenuBarInfo, NULL, &hHookGetMenuBarInfo);
	LhSetExclusiveACL(HookGetMenuBarInfo_ACLEntries, 1, &&hHookGetMenuBarInfo);

	LhInstallHook(pSetMenuItemInfoA, fake_SetMenuItemInfoA, NULL, &hHookSetMenuItemInfoA);
	LhSetExclusiveACL(HookSetMenuItemInfoA_ACLEntries, 1, &&hHookSetMenuItemInfoA);

	LhInstallHook(pShutdownBlockReasonQuery, fake_ShutdownBlockReasonQuery, NULL, &hHookShutdownBlockReasonQuery);
	LhSetExclusiveACL(HookShutdownBlockReasonQuery_ACLEntries, 1, &&hHookShutdownBlockReasonQuery);

	LhInstallHook(pCharPrevW, fake_CharPrevW, NULL, &hHookCharPrevW);
	LhSetExclusiveACL(HookCharPrevW_ACLEntries, 1, &&hHookCharPrevW);

	LhInstallHook(pCheckDlgButton, fake_CheckDlgButton, NULL, &hHookCheckDlgButton);
	LhSetExclusiveACL(HookCheckDlgButton_ACLEntries, 1, &&hHookCheckDlgButton);

	LhInstallHook(pClientToScreen, fake_ClientToScreen, NULL, &hHookClientToScreen);
	LhSetExclusiveACL(HookClientToScreen_ACLEntries, 1, &&hHookClientToScreen);

	LhInstallHook(pDlgDirSelectComboBoxExA, fake_DlgDirSelectComboBoxExA, NULL, &hHookDlgDirSelectComboBoxExA);
	LhSetExclusiveACL(HookDlgDirSelectComboBoxExA_ACLEntries, 1, &&hHookDlgDirSelectComboBoxExA);

	LhInstallHook(pDrawTextW, fake_DrawTextW, NULL, &hHookDrawTextW);
	LhSetExclusiveACL(HookDrawTextW_ACLEntries, 1, &&hHookDrawTextW);

	LhInstallHook(pDefDlgProcW, fake_DefDlgProcW, NULL, &hHookDefDlgProcW);
	LhSetExclusiveACL(HookDefDlgProcW_ACLEntries, 1, &&hHookDefDlgProcW);

	LhInstallHook(pSetWinEventHook, fake_SetWinEventHook, NULL, &hHookSetWinEventHook);
	LhSetExclusiveACL(HookSetWinEventHook_ACLEntries, 1, &&hHookSetWinEventHook);

	LhInstallHook(pShowWindow, fake_ShowWindow, NULL, &hHookShowWindow);
	LhSetExclusiveACL(HookShowWindow_ACLEntries, 1, &&hHookShowWindow);

	LhInstallHook(pSetPropW, fake_SetPropW, NULL, &hHookSetPropW);
	LhSetExclusiveACL(HookSetPropW_ACLEntries, 1, &&hHookSetPropW);

	LhInstallHook(pToAsciiEx, fake_ToAsciiEx, NULL, &hHookToAsciiEx);
	LhSetExclusiveACL(HookToAsciiEx_ACLEntries, 1, &&hHookToAsciiEx);

	LhInstallHook(pVkKeyScanA, fake_VkKeyScanA, NULL, &hHookVkKeyScanA);
	LhSetExclusiveACL(HookVkKeyScanA_ACLEntries, 1, &&hHookVkKeyScanA);

	LhInstallHook(pSendMessageCallbackA, fake_SendMessageCallbackA, NULL, &hHookSendMessageCallbackA);
	LhSetExclusiveACL(HookSendMessageCallbackA_ACLEntries, 1, &&hHookSendMessageCallbackA);

	LhInstallHook(pSetClipboardViewer, fake_SetClipboardViewer, NULL, &hHookSetClipboardViewer);
	LhSetExclusiveACL(HookSetClipboardViewer_ACLEntries, 1, &&hHookSetClipboardViewer);

	LhInstallHook(pGetInputState, fake_GetInputState, NULL, &hHookGetInputState);
	LhSetExclusiveACL(HookGetInputState_ACLEntries, 1, &&hHookGetInputState);

	LhInstallHook(pDefMDIChildProcW, fake_DefMDIChildProcW, NULL, &hHookDefMDIChildProcW);
	LhSetExclusiveACL(HookDefMDIChildProcW_ACLEntries, 1, &&hHookDefMDIChildProcW);

	LhInstallHook(pIntersectRect, fake_IntersectRect, NULL, &hHookIntersectRect);
	LhSetExclusiveACL(HookIntersectRect_ACLEntries, 1, &&hHookIntersectRect);

	LhInstallHook(pSetWindowPlacement, fake_SetWindowPlacement, NULL, &hHookSetWindowPlacement);
	LhSetExclusiveACL(HookSetWindowPlacement_ACLEntries, 1, &&hHookSetWindowPlacement);

	LhInstallHook(pGetNextDlgTabItem, fake_GetNextDlgTabItem, NULL, &hHookGetNextDlgTabItem);
	LhSetExclusiveACL(HookGetNextDlgTabItem_ACLEntries, 1, &&hHookGetNextDlgTabItem);

	LhInstallHook(pSetCapture, fake_SetCapture, NULL, &hHookSetCapture);
	LhSetExclusiveACL(HookSetCapture_ACLEntries, 1, &&hHookSetCapture);

	LhInstallHook(pDisplayConfigSetDeviceInfo, fake_DisplayConfigSetDeviceInfo, NULL, &hHookDisplayConfigSetDeviceInfo);
	LhSetExclusiveACL(HookDisplayConfigSetDeviceInfo_ACLEntries, 1, &&hHookDisplayConfigSetDeviceInfo);

	LhInstallHook(pGetWindowTextA, fake_GetWindowTextA, NULL, &hHookGetWindowTextA);
	LhSetExclusiveACL(HookGetWindowTextA_ACLEntries, 1, &&hHookGetWindowTextA);

	LhInstallHook(pSetMenuInfo, fake_SetMenuInfo, NULL, &hHookSetMenuInfo);
	LhSetExclusiveACL(HookSetMenuInfo_ACLEntries, 1, &&hHookSetMenuInfo);

	LhInstallHook(pTranslateMDISysAccel, fake_TranslateMDISysAccel, NULL, &hHookTranslateMDISysAccel);
	LhSetExclusiveACL(HookTranslateMDISysAccel_ACLEntries, 1, &&hHookTranslateMDISysAccel);

	LhInstallHook(pDialogBoxParamW, fake_DialogBoxParamW, NULL, &hHookDialogBoxParamW);
	LhSetExclusiveACL(HookDialogBoxParamW_ACLEntries, 1, &&hHookDialogBoxParamW);

	LhInstallHook(pGetComboBoxInfo, fake_GetComboBoxInfo, NULL, &hHookGetComboBoxInfo);
	LhSetExclusiveACL(HookGetComboBoxInfo_ACLEntries, 1, &&hHookGetComboBoxInfo);

	LhInstallHook(pIsCharUpperW, fake_IsCharUpperW, NULL, &hHookIsCharUpperW);
	LhSetExclusiveACL(HookIsCharUpperW_ACLEntries, 1, &&hHookIsCharUpperW);

	LhInstallHook(pGetUserObjectInformationW, fake_GetUserObjectInformationW, NULL, &hHookGetUserObjectInformationW);
	LhSetExclusiveACL(HookGetUserObjectInformationW_ACLEntries, 1, &&hHookGetUserObjectInformationW);

	LhInstallHook(pGetMessageExtraInfo, fake_GetMessageExtraInfo, NULL, &hHookGetMessageExtraInfo);
	LhSetExclusiveACL(HookGetMessageExtraInfo_ACLEntries, 1, &&hHookGetMessageExtraInfo);

	LhInstallHook(pEnumDisplayDevicesA, fake_EnumDisplayDevicesA, NULL, &hHookEnumDisplayDevicesA);
	LhSetExclusiveACL(HookEnumDisplayDevicesA_ACLEntries, 1, &&hHookEnumDisplayDevicesA);

	LhInstallHook(pMoveWindow, fake_MoveWindow, NULL, &hHookMoveWindow);
	LhSetExclusiveACL(HookMoveWindow_ACLEntries, 1, &&hHookMoveWindow);

	LhInstallHook(pGetUserObjectSecurity, fake_GetUserObjectSecurity, NULL, &hHookGetUserObjectSecurity);
	LhSetExclusiveACL(HookGetUserObjectSecurity_ACLEntries, 1, &&hHookGetUserObjectSecurity);

	LhInstallHook(pDrawFrameControl, fake_DrawFrameControl, NULL, &hHookDrawFrameControl);
	LhSetExclusiveACL(HookDrawFrameControl_ACLEntries, 1, &&hHookDrawFrameControl);

	LhInstallHook(pDefWindowProcA, fake_DefWindowProcA, NULL, &hHookDefWindowProcA);
	LhSetExclusiveACL(HookDefWindowProcA_ACLEntries, 1, &&hHookDefWindowProcA);

	LhInstallHook(pDrawMenuBar, fake_DrawMenuBar, NULL, &hHookDrawMenuBar);
	LhSetExclusiveACL(HookDrawMenuBar_ACLEntries, 1, &&hHookDrawMenuBar);

	LhInstallHook(pAllowSetForegroundWindow, fake_AllowSetForegroundWindow, NULL, &hHookAllowSetForegroundWindow);
	LhSetExclusiveACL(HookAllowSetForegroundWindow_ACLEntries, 1, &&hHookAllowSetForegroundWindow);

	LhInstallHook(pOpenWindowStationW, fake_OpenWindowStationW, NULL, &hHookOpenWindowStationW);
	LhSetExclusiveACL(HookOpenWindowStationW_ACLEntries, 1, &&hHookOpenWindowStationW);

	LhInstallHook(pUnhookWinEvent, fake_UnhookWinEvent, NULL, &hHookUnhookWinEvent);
	LhSetExclusiveACL(HookUnhookWinEvent_ACLEntries, 1, &&hHookUnhookWinEvent);

	LhInstallHook(pGetClipboardOwner, fake_GetClipboardOwner, NULL, &hHookGetClipboardOwner);
	LhSetExclusiveACL(HookGetClipboardOwner_ACLEntries, 1, &&hHookGetClipboardOwner);

	LhInstallHook(pDefDlgProcA, fake_DefDlgProcA, NULL, &hHookDefDlgProcA);
	LhSetExclusiveACL(HookDefDlgProcA_ACLEntries, 1, &&hHookDefDlgProcA);

	LhInstallHook(pDeleteMenu, fake_DeleteMenu, NULL, &hHookDeleteMenu);
	LhSetExclusiveACL(HookDeleteMenu_ACLEntries, 1, &&hHookDeleteMenu);

	LhInstallHook(pBroadcastSystemMessageExA, fake_BroadcastSystemMessageExA, NULL, &hHookBroadcastSystemMessageExA);
	LhSetExclusiveACL(HookBroadcastSystemMessageExA_ACLEntries, 1, &&hHookBroadcastSystemMessageExA);

	LhInstallHook(pIsGUIThread, fake_IsGUIThread, NULL, &hHookIsGUIThread);
	LhSetExclusiveACL(HookIsGUIThread_ACLEntries, 1, &&hHookIsGUIThread);

	LhInstallHook(pLockWorkStation, fake_LockWorkStation, NULL, &hHookLockWorkStation);
	LhSetExclusiveACL(HookLockWorkStation_ACLEntries, 1, &&hHookLockWorkStation);

	LhInstallHook(pIsWinEventHookInstalled, fake_IsWinEventHookInstalled, NULL, &hHookIsWinEventHookInstalled);
	LhSetExclusiveACL(HookIsWinEventHookInstalled_ACLEntries, 1, &&hHookIsWinEventHookInstalled);

	LhInstallHook(pOemToCharW, fake_OemToCharW, NULL, &hHookOemToCharW);
	LhSetExclusiveACL(HookOemToCharW_ACLEntries, 1, &&hHookOemToCharW);

	LhInstallHook(pDragDetect, fake_DragDetect, NULL, &hHookDragDetect);
	LhSetExclusiveACL(HookDragDetect_ACLEntries, 1, &&hHookDragDetect);

	LhInstallHook(pGetKeyNameTextW, fake_GetKeyNameTextW, NULL, &hHookGetKeyNameTextW);
	LhSetExclusiveACL(HookGetKeyNameTextW_ACLEntries, 1, &&hHookGetKeyNameTextW);

	LhInstallHook(pGetWindowThreadProcessId, fake_GetWindowThreadProcessId, NULL, &hHookGetWindowThreadProcessId);
	LhSetExclusiveACL(HookGetWindowThreadProcessId_ACLEntries, 1, &&hHookGetWindowThreadProcessId);

	LhInstallHook(pSetTimer, fake_SetTimer, NULL, &hHookSetTimer);
	LhSetExclusiveACL(HookSetTimer_ACLEntries, 1, &&hHookSetTimer);

	LhInstallHook(pGetWindowRgnBox, fake_GetWindowRgnBox, NULL, &hHookGetWindowRgnBox);
	LhSetExclusiveACL(HookGetWindowRgnBox_ACLEntries, 1, &&hHookGetWindowRgnBox);

	LhInstallHook(pCharNextExA, fake_CharNextExA, NULL, &hHookCharNextExA);
	LhSetExclusiveACL(HookCharNextExA_ACLEntries, 1, &&hHookCharNextExA);

	LhInstallHook(pSwitchToThisWindow, fake_SwitchToThisWindow, NULL, &hHookSwitchToThisWindow);
	LhSetExclusiveACL(HookSwitchToThisWindow_ACLEntries, 1, &&hHookSwitchToThisWindow);

	LhInstallHook(pCharLowerBuffA, fake_CharLowerBuffA, NULL, &hHookCharLowerBuffA);
	LhSetExclusiveACL(HookCharLowerBuffA_ACLEntries, 1, &&hHookCharLowerBuffA);

	LhInstallHook(pGetMenuItemCount, fake_GetMenuItemCount, NULL, &hHookGetMenuItemCount);
	LhSetExclusiveACL(HookGetMenuItemCount_ACLEntries, 1, &&hHookGetMenuItemCount);

	LhInstallHook(pSetProcessWindowStation, fake_SetProcessWindowStation, NULL, &hHookSetProcessWindowStation);
	LhSetExclusiveACL(HookSetProcessWindowStation_ACLEntries, 1, &&hHookSetProcessWindowStation);

	LhInstallHook(pSetWindowsHookA, fake_SetWindowsHookA, NULL, &hHookSetWindowsHookA);
	LhSetExclusiveACL(HookSetWindowsHookA_ACLEntries, 1, &&hHookSetWindowsHookA);

	LhInstallHook(pShowScrollBar, fake_ShowScrollBar, NULL, &hHookShowScrollBar);
	LhSetExclusiveACL(HookShowScrollBar_ACLEntries, 1, &&hHookShowScrollBar);

	LhInstallHook(pCharLowerBuffW, fake_CharLowerBuffW, NULL, &hHookCharLowerBuffW);
	LhSetExclusiveACL(HookCharLowerBuffW_ACLEntries, 1, &&hHookCharLowerBuffW);

	LhInstallHook(pRegisterClassExW, fake_RegisterClassExW, NULL, &hHookRegisterClassExW);
	LhSetExclusiveACL(HookRegisterClassExW_ACLEntries, 1, &&hHookRegisterClassExW);

    RhWakeUpProcess();
}
