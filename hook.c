
/*
Copyright (c) 2017 HyungSeok Han and Sang Kil Cha at SoftSec, KAIST

See the file LICENCE for copying permission.
*/
#include "stdafx.h"
#include "detours.h" 
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <excpt.h>

#pragma comment(lib, "detours.lib")
#ifndef LOG_PATH
#define LOG_PATH "D:\\log.txt"
#endif

__declspec(dllexport) VOID ExportFuncForSetDll(VOID)
{
	OutputDebugStringA("ExportFuncForSetDll");
}

HANDLE g_mutex;
const char* log_path = LOG_PATH;
HKL (WINAPI *pLoadKeyboardLayoutA) (LPCSTR pwszKLID,UINT Flags) = LoadKeyboardLayoutA;
HKL fake_LoadKeyboardLayoutA(LPCSTR pwszKLID,UINT Flags){
	HKL ret = pLoadKeyboardLayoutA(pwszKLID,Flags);
	OutputDebugStringA("LoadKeyboardLayoutA");
	return ret;
}

HKL (WINAPI *pLoadKeyboardLayoutW) (LPCWSTR pwszKLID,UINT Flags) = LoadKeyboardLayoutW;
HKL fake_LoadKeyboardLayoutW(LPCWSTR pwszKLID,UINT Flags){
	HKL ret = pLoadKeyboardLayoutW(pwszKLID,Flags);
	OutputDebugStringA("LoadKeyboardLayoutW");
	return ret;
}

HKL (WINAPI *pActivateKeyboardLayout) (HKL hkl,UINT Flags) = ActivateKeyboardLayout;
HKL fake_ActivateKeyboardLayout(HKL hkl,UINT Flags){
	HKL ret = pActivateKeyboardLayout(hkl,Flags);
	OutputDebugStringA("ActivateKeyboardLayout");
	return ret;
}

int (WINAPI *pToUnicodeEx) (UINT wVirtKey,UINT wScanCode,CONST BYTE* lpKeyState,LPWSTR pwszBuff,int cchBuff,UINT wFlags,HKL dwhkl) = ToUnicodeEx;
int fake_ToUnicodeEx(UINT wVirtKey,UINT wScanCode,CONST BYTE* lpKeyState,LPWSTR pwszBuff,int cchBuff,UINT wFlags,HKL dwhkl){
	int ret = pToUnicodeEx(wVirtKey,wScanCode,lpKeyState,pwszBuff,cchBuff,wFlags,dwhkl);
	OutputDebugStringA("ToUnicodeEx");
	return ret;
}

BOOL (WINAPI *pUnloadKeyboardLayout) (HKL hkl) = UnloadKeyboardLayout;
BOOL fake_UnloadKeyboardLayout(HKL hkl){
	BOOL ret = pUnloadKeyboardLayout(hkl);
	OutputDebugStringA("UnloadKeyboardLayout");
	return ret;
}

BOOL (WINAPI *pGetKeyboardLayoutNameA) (LPSTR pwszKLID) = GetKeyboardLayoutNameA;
BOOL fake_GetKeyboardLayoutNameA(LPSTR pwszKLID){
	BOOL ret = pGetKeyboardLayoutNameA(pwszKLID);
	OutputDebugStringA("GetKeyboardLayoutNameA");
	return ret;
}

BOOL (WINAPI *pGetKeyboardLayoutNameW) (LPWSTR pwszKLID) = GetKeyboardLayoutNameW;
BOOL fake_GetKeyboardLayoutNameW(LPWSTR pwszKLID){
	BOOL ret = pGetKeyboardLayoutNameW(pwszKLID);
	OutputDebugStringA("GetKeyboardLayoutNameW");
	return ret;
}

int (WINAPI *pGetKeyboardLayoutList) (int nBuff,HKL* lpList) = GetKeyboardLayoutList;
int fake_GetKeyboardLayoutList(int nBuff,HKL* lpList){
	int ret = pGetKeyboardLayoutList(nBuff,lpList);
	OutputDebugStringA("GetKeyboardLayoutList");
	return ret;
}

HKL (WINAPI *pGetKeyboardLayout) (DWORD idThread) = GetKeyboardLayout;
HKL fake_GetKeyboardLayout(DWORD idThread){
	HKL ret = pGetKeyboardLayout(idThread);
	OutputDebugStringA("GetKeyboardLayout");
	return ret;
}

int (WINAPI *pGetMouseMovePointsEx) (UINT cbSize,LPMOUSEMOVEPOINT lppt,LPMOUSEMOVEPOINT lpptBuf,int nBufPoints,DWORD resolution) = GetMouseMovePointsEx;
int fake_GetMouseMovePointsEx(UINT cbSize,LPMOUSEMOVEPOINT lppt,LPMOUSEMOVEPOINT lpptBuf,int nBufPoints,DWORD resolution){
	int ret = pGetMouseMovePointsEx(cbSize,lppt,lpptBuf,nBufPoints,resolution);
	OutputDebugStringA("GetMouseMovePointsEx");
	return ret;
}

HDESK (WINAPI *pCreateDesktopA) (LPCSTR lpszDesktop,LPCSTR lpszDevice,DEVMODEA*  pDevmode,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa) = CreateDesktopA;
HDESK fake_CreateDesktopA(LPCSTR lpszDesktop,LPCSTR lpszDevice,DEVMODEA*  pDevmode,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa){
	HDESK ret = pCreateDesktopA(lpszDesktop,lpszDevice, pDevmode,dwFlags,dwDesiredAccess,lpsa);
	OutputDebugStringA("CreateDesktopA");
	return ret;
}

HDESK (WINAPI *pCreateDesktopW) (LPCWSTR lpszDesktop,LPCWSTR lpszDevice,DEVMODEW*  pDevmode,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa) = CreateDesktopW;
HDESK fake_CreateDesktopW(LPCWSTR lpszDesktop,LPCWSTR lpszDevice,DEVMODEW*  pDevmode,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa){
	HDESK ret = pCreateDesktopW(lpszDesktop,lpszDevice, pDevmode,dwFlags,dwDesiredAccess,lpsa);
	OutputDebugStringA("CreateDesktopW");
	return ret;
}

HDESK (WINAPI *pCreateDesktopExA) (LPCSTR lpszDesktop,LPCSTR lpszDevice,DEVMODEA*  pDevmode,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa,ULONG ulHeapSize,PVOID pvoid) = CreateDesktopExA;
HDESK fake_CreateDesktopExA(LPCSTR lpszDesktop,LPCSTR lpszDevice,DEVMODEA*  pDevmode,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa,ULONG ulHeapSize,PVOID pvoid){
	HDESK ret = pCreateDesktopExA(lpszDesktop,lpszDevice, pDevmode,dwFlags,dwDesiredAccess,lpsa,ulHeapSize,pvoid);
	OutputDebugStringA("CreateDesktopExA");
	return ret;
}

HDESK (WINAPI *pCreateDesktopExW) (LPCWSTR lpszDesktop,LPCWSTR lpszDevice,DEVMODEW*  pDevmode,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa,ULONG ulHeapSize,PVOID pvoid) = CreateDesktopExW;
HDESK fake_CreateDesktopExW(LPCWSTR lpszDesktop,LPCWSTR lpszDevice,DEVMODEW*  pDevmode,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa,ULONG ulHeapSize,PVOID pvoid){
	HDESK ret = pCreateDesktopExW(lpszDesktop,lpszDevice, pDevmode,dwFlags,dwDesiredAccess,lpsa,ulHeapSize,pvoid);
	OutputDebugStringA("CreateDesktopExW");
	return ret;
}

HDESK (WINAPI *pOpenDesktopA) (LPCSTR lpszDesktop,DWORD dwFlags,BOOL fInherit,ACCESS_MASK dwDesiredAccess) = OpenDesktopA;
HDESK fake_OpenDesktopA(LPCSTR lpszDesktop,DWORD dwFlags,BOOL fInherit,ACCESS_MASK dwDesiredAccess){
	HDESK ret = pOpenDesktopA(lpszDesktop,dwFlags,fInherit,dwDesiredAccess);
	OutputDebugStringA("OpenDesktopA");
	return ret;
}

HDESK (WINAPI *pOpenDesktopW) (LPCWSTR lpszDesktop,DWORD dwFlags,BOOL fInherit,ACCESS_MASK dwDesiredAccess) = OpenDesktopW;
HDESK fake_OpenDesktopW(LPCWSTR lpszDesktop,DWORD dwFlags,BOOL fInherit,ACCESS_MASK dwDesiredAccess){
	HDESK ret = pOpenDesktopW(lpszDesktop,dwFlags,fInherit,dwDesiredAccess);
	OutputDebugStringA("OpenDesktopW");
	return ret;
}

HDESK (WINAPI *pOpenInputDesktop) (DWORD dwFlags,BOOL fInherit,ACCESS_MASK dwDesiredAccess) = OpenInputDesktop;
HDESK fake_OpenInputDesktop(DWORD dwFlags,BOOL fInherit,ACCESS_MASK dwDesiredAccess){
	HDESK ret = pOpenInputDesktop(dwFlags,fInherit,dwDesiredAccess);
	OutputDebugStringA("OpenInputDesktop");
	return ret;
}

BOOL (WINAPI *pEnumDesktopsA) (HWINSTA hwinsta,DESKTOPENUMPROCA lpEnumFunc,LPARAM lParam) = EnumDesktopsA;
BOOL fake_EnumDesktopsA(HWINSTA hwinsta,DESKTOPENUMPROCA lpEnumFunc,LPARAM lParam){
	BOOL ret = pEnumDesktopsA(hwinsta,lpEnumFunc,lParam);
	OutputDebugStringA("EnumDesktopsA");
	return ret;
}

BOOL (WINAPI *pEnumDesktopsW) (HWINSTA hwinsta,DESKTOPENUMPROCW lpEnumFunc,LPARAM lParam) = EnumDesktopsW;
BOOL fake_EnumDesktopsW(HWINSTA hwinsta,DESKTOPENUMPROCW lpEnumFunc,LPARAM lParam){
	BOOL ret = pEnumDesktopsW(hwinsta,lpEnumFunc,lParam);
	OutputDebugStringA("EnumDesktopsW");
	return ret;
}

BOOL (WINAPI *pEnumDesktopWindows) (HDESK hDesktop,WNDENUMPROC lpfn,LPARAM lParam) = EnumDesktopWindows;
BOOL fake_EnumDesktopWindows(HDESK hDesktop,WNDENUMPROC lpfn,LPARAM lParam){
	BOOL ret = pEnumDesktopWindows(hDesktop,lpfn,lParam);
	OutputDebugStringA("EnumDesktopWindows");
	return ret;
}

BOOL (WINAPI *pSwitchDesktop) (HDESK hDesktop) = SwitchDesktop;
BOOL fake_SwitchDesktop(HDESK hDesktop){
	BOOL ret = pSwitchDesktop(hDesktop);
	OutputDebugStringA("SwitchDesktop");
	return ret;
}

BOOL (WINAPI *pSetThreadDesktop) (HDESK hDesktop) = SetThreadDesktop;
BOOL fake_SetThreadDesktop(HDESK hDesktop){
	BOOL ret = pSetThreadDesktop(hDesktop);
	OutputDebugStringA("SetThreadDesktop");
	return ret;
}

BOOL (WINAPI *pCloseDesktop) (HDESK hDesktop) = CloseDesktop;
BOOL fake_CloseDesktop(HDESK hDesktop){
	BOOL ret = pCloseDesktop(hDesktop);
	OutputDebugStringA("CloseDesktop");
	return ret;
}

HDESK (WINAPI *pGetThreadDesktop) (DWORD dwThreadId) = GetThreadDesktop;
HDESK fake_GetThreadDesktop(DWORD dwThreadId){
	HDESK ret = pGetThreadDesktop(dwThreadId);
	OutputDebugStringA("GetThreadDesktop");
	return ret;
}

HWINSTA (WINAPI *pCreateWindowStationA) (LPCSTR lpwinsta,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa) = CreateWindowStationA;
HWINSTA fake_CreateWindowStationA(LPCSTR lpwinsta,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa){
	HWINSTA ret = pCreateWindowStationA(lpwinsta,dwFlags,dwDesiredAccess,lpsa);
	OutputDebugStringA("CreateWindowStationA");
	return ret;
}

HWINSTA (WINAPI *pCreateWindowStationW) (LPCWSTR lpwinsta,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa) = CreateWindowStationW;
HWINSTA fake_CreateWindowStationW(LPCWSTR lpwinsta,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa){
	HWINSTA ret = pCreateWindowStationW(lpwinsta,dwFlags,dwDesiredAccess,lpsa);
	OutputDebugStringA("CreateWindowStationW");
	return ret;
}

HWINSTA (WINAPI *pOpenWindowStationA) (LPCSTR lpszWinSta,BOOL fInherit,ACCESS_MASK dwDesiredAccess) = OpenWindowStationA;
HWINSTA fake_OpenWindowStationA(LPCSTR lpszWinSta,BOOL fInherit,ACCESS_MASK dwDesiredAccess){
	HWINSTA ret = pOpenWindowStationA(lpszWinSta,fInherit,dwDesiredAccess);
	OutputDebugStringA("OpenWindowStationA");
	return ret;
}

HWINSTA (WINAPI *pOpenWindowStationW) (LPCWSTR lpszWinSta,BOOL fInherit,ACCESS_MASK dwDesiredAccess) = OpenWindowStationW;
HWINSTA fake_OpenWindowStationW(LPCWSTR lpszWinSta,BOOL fInherit,ACCESS_MASK dwDesiredAccess){
	HWINSTA ret = pOpenWindowStationW(lpszWinSta,fInherit,dwDesiredAccess);
	OutputDebugStringA("OpenWindowStationW");
	return ret;
}

BOOL (WINAPI *pEnumWindowStationsA) (WINSTAENUMPROCA lpEnumFunc,LPARAM lParam) = EnumWindowStationsA;
BOOL fake_EnumWindowStationsA(WINSTAENUMPROCA lpEnumFunc,LPARAM lParam){
	BOOL ret = pEnumWindowStationsA(lpEnumFunc,lParam);
	OutputDebugStringA("EnumWindowStationsA");
	return ret;
}

BOOL (WINAPI *pEnumWindowStationsW) (WINSTAENUMPROCW lpEnumFunc,LPARAM lParam) = EnumWindowStationsW;
BOOL fake_EnumWindowStationsW(WINSTAENUMPROCW lpEnumFunc,LPARAM lParam){
	BOOL ret = pEnumWindowStationsW(lpEnumFunc,lParam);
	OutputDebugStringA("EnumWindowStationsW");
	return ret;
}

BOOL (WINAPI *pCloseWindowStation) (HWINSTA hWinSta) = CloseWindowStation;
BOOL fake_CloseWindowStation(HWINSTA hWinSta){
	BOOL ret = pCloseWindowStation(hWinSta);
	OutputDebugStringA("CloseWindowStation");
	return ret;
}

BOOL (WINAPI *pSetProcessWindowStation) (HWINSTA hWinSta) = SetProcessWindowStation;
BOOL fake_SetProcessWindowStation(HWINSTA hWinSta){
	BOOL ret = pSetProcessWindowStation(hWinSta);
	OutputDebugStringA("SetProcessWindowStation");
	return ret;
}

HWINSTA (WINAPI *pGetProcessWindowStation) () = GetProcessWindowStation;
HWINSTA fake_GetProcessWindowStation(){
	HWINSTA ret = pGetProcessWindowStation();
	OutputDebugStringA("GetProcessWindowStation");
	return ret;
}

BOOL (WINAPI *pSetUserObjectSecurity) (HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID) = SetUserObjectSecurity;
BOOL fake_SetUserObjectSecurity(HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID){
	BOOL ret = pSetUserObjectSecurity(hObj,pSIRequested,pSID);
	OutputDebugStringA("SetUserObjectSecurity");
	return ret;
}

BOOL (WINAPI *pGetUserObjectSecurity) (HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID,DWORD nLength,LPDWORD lpnLengthNeeded) = GetUserObjectSecurity;
BOOL fake_GetUserObjectSecurity(HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID,DWORD nLength,LPDWORD lpnLengthNeeded){
	BOOL ret = pGetUserObjectSecurity(hObj,pSIRequested,pSID,nLength,lpnLengthNeeded);
	OutputDebugStringA("GetUserObjectSecurity");
	return ret;
}

BOOL (WINAPI *pGetUserObjectInformationA) (HANDLE hObj,int nIndex,PVOID pvInfo,DWORD nLength,LPDWORD lpnLengthNeeded) = GetUserObjectInformationA;
BOOL fake_GetUserObjectInformationA(HANDLE hObj,int nIndex,PVOID pvInfo,DWORD nLength,LPDWORD lpnLengthNeeded){
	BOOL ret = pGetUserObjectInformationA(hObj,nIndex,pvInfo,nLength,lpnLengthNeeded);
	OutputDebugStringA("GetUserObjectInformationA");
	return ret;
}

BOOL (WINAPI *pGetUserObjectInformationW) (HANDLE hObj,int nIndex,PVOID pvInfo,DWORD nLength,LPDWORD lpnLengthNeeded) = GetUserObjectInformationW;
BOOL fake_GetUserObjectInformationW(HANDLE hObj,int nIndex,PVOID pvInfo,DWORD nLength,LPDWORD lpnLengthNeeded){
	BOOL ret = pGetUserObjectInformationW(hObj,nIndex,pvInfo,nLength,lpnLengthNeeded);
	OutputDebugStringA("GetUserObjectInformationW");
	return ret;
}

BOOL (WINAPI *pSetUserObjectInformationA) (HANDLE hObj,int nIndex,PVOID pvInfo,DWORD nLength) = SetUserObjectInformationA;
BOOL fake_SetUserObjectInformationA(HANDLE hObj,int nIndex,PVOID pvInfo,DWORD nLength){
	BOOL ret = pSetUserObjectInformationA(hObj,nIndex,pvInfo,nLength);
	OutputDebugStringA("SetUserObjectInformationA");
	return ret;
}

BOOL (WINAPI *pSetUserObjectInformationW) (HANDLE hObj,int nIndex,PVOID pvInfo,DWORD nLength) = SetUserObjectInformationW;
BOOL fake_SetUserObjectInformationW(HANDLE hObj,int nIndex,PVOID pvInfo,DWORD nLength){
	BOOL ret = pSetUserObjectInformationW(hObj,nIndex,pvInfo,nLength);
	OutputDebugStringA("SetUserObjectInformationW");
	return ret;
}

BOOL (WINAPI *pIsHungAppWindow) (HWND hwnd) = IsHungAppWindow;
BOOL fake_IsHungAppWindow(HWND hwnd){
	BOOL ret = pIsHungAppWindow(hwnd);
	OutputDebugStringA("IsHungAppWindow");
	return ret;
}

VOID (WINAPI *pDisableProcessWindowsGhosting) () = DisableProcessWindowsGhosting;
VOID fake_DisableProcessWindowsGhosting(){
	pDisableProcessWindowsGhosting();
	OutputDebugStringA("DisableProcessWindowsGhosting");
}

UINT (WINAPI *pRegisterWindowMessageA) (LPCSTR lpString) = RegisterWindowMessageA;
UINT fake_RegisterWindowMessageA(LPCSTR lpString){
	UINT ret = pRegisterWindowMessageA(lpString);
	OutputDebugStringA("RegisterWindowMessageA");
	return ret;
}

UINT (WINAPI *pRegisterWindowMessageW) (LPCWSTR lpString) = RegisterWindowMessageW;
UINT fake_RegisterWindowMessageW(LPCWSTR lpString){
	UINT ret = pRegisterWindowMessageW(lpString);
	OutputDebugStringA("RegisterWindowMessageW");
	return ret;
}

BOOL (WINAPI *pTrackMouseEvent) (LPTRACKMOUSEEVENT lpEventTrack) = TrackMouseEvent;
BOOL fake_TrackMouseEvent(LPTRACKMOUSEEVENT lpEventTrack){
	BOOL ret = pTrackMouseEvent(lpEventTrack);
	OutputDebugStringA("TrackMouseEvent");
	return ret;
}

BOOL (WINAPI *pDrawEdge) (HDC hdc,LPRECT qrc,UINT edge,UINT grfFlags) = DrawEdge;
BOOL fake_DrawEdge(HDC hdc,LPRECT qrc,UINT edge,UINT grfFlags){
	BOOL ret = pDrawEdge(hdc,qrc,edge,grfFlags);
	OutputDebugStringA("DrawEdge");
	return ret;
}

BOOL (WINAPI *pDrawFrameControl) (HDC arg0,LPRECT arg1,UINT arg2,UINT arg3) = DrawFrameControl;
BOOL fake_DrawFrameControl(HDC arg0,LPRECT arg1,UINT arg2,UINT arg3){
	BOOL ret = pDrawFrameControl(arg0,arg1,arg2,arg3);
	OutputDebugStringA("DrawFrameControl");
	return ret;
}

BOOL (WINAPI *pDrawCaption) (HWND hwnd,HDC hdc,CONST RECT*  lprect,UINT flags) = DrawCaption;
BOOL fake_DrawCaption(HWND hwnd,HDC hdc,CONST RECT*  lprect,UINT flags){
	BOOL ret = pDrawCaption(hwnd,hdc, lprect,flags);
	OutputDebugStringA("DrawCaption");
	return ret;
}

BOOL (WINAPI *pDrawAnimatedRects) (HWND hwnd,int idAni,CONST RECT* lprcFrom,CONST RECT* lprcTo) = DrawAnimatedRects;
BOOL fake_DrawAnimatedRects(HWND hwnd,int idAni,CONST RECT* lprcFrom,CONST RECT* lprcTo){
	BOOL ret = pDrawAnimatedRects(hwnd,idAni,lprcFrom,lprcTo);
	OutputDebugStringA("DrawAnimatedRects");
	return ret;
}

BOOL (WINAPI *pGetMessageA) (LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax) = GetMessageA;
BOOL fake_GetMessageA(LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax){
	BOOL ret = pGetMessageA(lpMsg,hWnd,wMsgFilterMin,wMsgFilterMax);
	OutputDebugStringA("GetMessageA");
	return ret;
}

BOOL (WINAPI *pGetMessageW) (LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax) = GetMessageW;
BOOL fake_GetMessageW(LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax){
	BOOL ret = pGetMessageW(lpMsg,hWnd,wMsgFilterMin,wMsgFilterMax);
	OutputDebugStringA("GetMessageW");
	return ret;
}

BOOL (WINAPI *pTranslateMessage) (CONST MSG* lpMsg) = TranslateMessage;
BOOL fake_TranslateMessage(CONST MSG* lpMsg){
	BOOL ret = pTranslateMessage(lpMsg);
	OutputDebugStringA("TranslateMessage");
	return ret;
}

LRESULT (WINAPI *pDispatchMessageA) (CONST MSG* lpMsg) = DispatchMessageA;
LRESULT fake_DispatchMessageA(CONST MSG* lpMsg){
	LRESULT ret = pDispatchMessageA(lpMsg);
	OutputDebugStringA("DispatchMessageA");
	return ret;
}

LRESULT (WINAPI *pDispatchMessageW) (CONST MSG* lpMsg) = DispatchMessageW;
LRESULT fake_DispatchMessageW(CONST MSG* lpMsg){
	LRESULT ret = pDispatchMessageW(lpMsg);
	OutputDebugStringA("DispatchMessageW");
	return ret;
}

BOOL (WINAPI *pSetMessageQueue) (int cMessagesMax) = SetMessageQueue;
BOOL fake_SetMessageQueue(int cMessagesMax){
	BOOL ret = pSetMessageQueue(cMessagesMax);
	OutputDebugStringA("SetMessageQueue");
	return ret;
}

BOOL (WINAPI *pPeekMessageA) (LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax,UINT wRemoveMsg) = PeekMessageA;
BOOL fake_PeekMessageA(LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax,UINT wRemoveMsg){
	BOOL ret = pPeekMessageA(lpMsg,hWnd,wMsgFilterMin,wMsgFilterMax,wRemoveMsg);
	OutputDebugStringA("PeekMessageA");
	return ret;
}

BOOL (WINAPI *pPeekMessageW) (LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax,UINT wRemoveMsg) = PeekMessageW;
BOOL fake_PeekMessageW(LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax,UINT wRemoveMsg){
	BOOL ret = pPeekMessageW(lpMsg,hWnd,wMsgFilterMin,wMsgFilterMax,wRemoveMsg);
	OutputDebugStringA("PeekMessageW");
	return ret;
}

BOOL (WINAPI *pRegisterHotKey) (HWND hWnd,int id,UINT fsModifiers,UINT vk) = RegisterHotKey;
BOOL fake_RegisterHotKey(HWND hWnd,int id,UINT fsModifiers,UINT vk){
	BOOL ret = pRegisterHotKey(hWnd,id,fsModifiers,vk);
	OutputDebugStringA("RegisterHotKey");
	return ret;
}

BOOL (WINAPI *pUnregisterHotKey) (HWND hWnd,int id) = UnregisterHotKey;
BOOL fake_UnregisterHotKey(HWND hWnd,int id){
	BOOL ret = pUnregisterHotKey(hWnd,id);
	OutputDebugStringA("UnregisterHotKey");
	return ret;
}

BOOL (WINAPI *pExitWindowsEx) (UINT uFlags,DWORD dwReason) = ExitWindowsEx;
BOOL fake_ExitWindowsEx(UINT uFlags,DWORD dwReason){
	BOOL ret = pExitWindowsEx(uFlags,dwReason);
	OutputDebugStringA("ExitWindowsEx");
	return ret;
}

BOOL (WINAPI *pSwapMouseButton) (BOOL fSwap) = SwapMouseButton;
BOOL fake_SwapMouseButton(BOOL fSwap){
	BOOL ret = pSwapMouseButton(fSwap);
	OutputDebugStringA("SwapMouseButton");
	return ret;
}

DWORD (WINAPI *pGetMessagePos) () = GetMessagePos;
DWORD fake_GetMessagePos(){
	DWORD ret = pGetMessagePos();
	OutputDebugStringA("GetMessagePos");
	return ret;
}

LONG (WINAPI *pGetMessageTime) () = GetMessageTime;
LONG fake_GetMessageTime(){
	LONG ret = pGetMessageTime();
	OutputDebugStringA("GetMessageTime");
	return ret;
}

LPARAM (WINAPI *pGetMessageExtraInfo) () = GetMessageExtraInfo;
LPARAM fake_GetMessageExtraInfo(){
	LPARAM ret = pGetMessageExtraInfo();
	OutputDebugStringA("GetMessageExtraInfo");
	return ret;
}

BOOL (WINAPI *pIsWow64Message) () = IsWow64Message;
BOOL fake_IsWow64Message(){
	BOOL ret = pIsWow64Message();
	OutputDebugStringA("IsWow64Message");
	return ret;
}

LPARAM (WINAPI *pSetMessageExtraInfo) (LPARAM lParam) = SetMessageExtraInfo;
LPARAM fake_SetMessageExtraInfo(LPARAM lParam){
	LPARAM ret = pSetMessageExtraInfo(lParam);
	OutputDebugStringA("SetMessageExtraInfo");
	return ret;
}

LRESULT (WINAPI *pSendMessageA) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam) = SendMessageA;
LRESULT fake_SendMessageA(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pSendMessageA(hWnd,Msg,wParam,lParam);
	OutputDebugStringA("SendMessageA");
	return ret;
}

LRESULT (WINAPI *pSendMessageW) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam) = SendMessageW;
LRESULT fake_SendMessageW(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pSendMessageW(hWnd,Msg,wParam,lParam);
	OutputDebugStringA("SendMessageW");
	return ret;
}

LRESULT (WINAPI *pSendMessageTimeoutA) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdwResult) = SendMessageTimeoutA;
LRESULT fake_SendMessageTimeoutA(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdwResult){
	LRESULT ret = pSendMessageTimeoutA(hWnd,Msg,wParam,lParam,fuFlags,uTimeout,lpdwResult);
	OutputDebugStringA("SendMessageTimeoutA");
	return ret;
}

LRESULT (WINAPI *pSendMessageTimeoutW) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdwResult) = SendMessageTimeoutW;
LRESULT fake_SendMessageTimeoutW(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdwResult){
	LRESULT ret = pSendMessageTimeoutW(hWnd,Msg,wParam,lParam,fuFlags,uTimeout,lpdwResult);
	OutputDebugStringA("SendMessageTimeoutW");
	return ret;
}

BOOL (WINAPI *pSendNotifyMessageA) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam) = SendNotifyMessageA;
BOOL fake_SendNotifyMessageA(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam){
	BOOL ret = pSendNotifyMessageA(hWnd,Msg,wParam,lParam);
	OutputDebugStringA("SendNotifyMessageA");
	return ret;
}

BOOL (WINAPI *pSendNotifyMessageW) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam) = SendNotifyMessageW;
BOOL fake_SendNotifyMessageW(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam){
	BOOL ret = pSendNotifyMessageW(hWnd,Msg,wParam,lParam);
	OutputDebugStringA("SendNotifyMessageW");
	return ret;
}

BOOL (WINAPI *pSendMessageCallbackA) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lpResultCallBack,ULONG_PTR dwData) = SendMessageCallbackA;
BOOL fake_SendMessageCallbackA(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lpResultCallBack,ULONG_PTR dwData){
	BOOL ret = pSendMessageCallbackA(hWnd,Msg,wParam,lParam,lpResultCallBack,dwData);
	OutputDebugStringA("SendMessageCallbackA");
	return ret;
}

BOOL (WINAPI *pSendMessageCallbackW) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lpResultCallBack,ULONG_PTR dwData) = SendMessageCallbackW;
BOOL fake_SendMessageCallbackW(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lpResultCallBack,ULONG_PTR dwData){
	BOOL ret = pSendMessageCallbackW(hWnd,Msg,wParam,lParam,lpResultCallBack,dwData);
	OutputDebugStringA("SendMessageCallbackW");
	return ret;
}

long (WINAPI *pBroadcastSystemMessageExA) (DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo) = BroadcastSystemMessageExA;
long fake_BroadcastSystemMessageExA(DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo){
	long ret = pBroadcastSystemMessageExA(flags,lpInfo,Msg,wParam,lParam,pbsmInfo);
	OutputDebugStringA("BroadcastSystemMessageExA");
	return ret;
}

long (WINAPI *pBroadcastSystemMessageExW) (DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo) = BroadcastSystemMessageExW;
long fake_BroadcastSystemMessageExW(DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo){
	long ret = pBroadcastSystemMessageExW(flags,lpInfo,Msg,wParam,lParam,pbsmInfo);
	OutputDebugStringA("BroadcastSystemMessageExW");
	return ret;
}

long (WINAPI *pBroadcastSystemMessageA) (DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam) = BroadcastSystemMessageA;
long fake_BroadcastSystemMessageA(DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam){
	long ret = pBroadcastSystemMessageA(flags,lpInfo,Msg,wParam,lParam);
	OutputDebugStringA("BroadcastSystemMessageA");
	return ret;
}

long (WINAPI *pBroadcastSystemMessageW) (DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam) = BroadcastSystemMessageW;
long fake_BroadcastSystemMessageW(DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam){
	long ret = pBroadcastSystemMessageW(flags,lpInfo,Msg,wParam,lParam);
	OutputDebugStringA("BroadcastSystemMessageW");
	return ret;
}

long (WINAPI *pBroadcastSystemMessage) (DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam) = BroadcastSystemMessage;
long fake_BroadcastSystemMessage(DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam){
	long ret = pBroadcastSystemMessage(flags,lpInfo,Msg,wParam,lParam);
	OutputDebugStringA("BroadcastSystemMessage");
	return ret;
}

HDEVNOTIFY (WINAPI *pRegisterDeviceNotificationA) (HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags) = RegisterDeviceNotificationA;
HDEVNOTIFY fake_RegisterDeviceNotificationA(HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags){
	HDEVNOTIFY ret = pRegisterDeviceNotificationA(hRecipient,NotificationFilter,Flags);
	OutputDebugStringA("RegisterDeviceNotificationA");
	return ret;
}

HDEVNOTIFY (WINAPI *pRegisterDeviceNotificationW) (HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags) = RegisterDeviceNotificationW;
HDEVNOTIFY fake_RegisterDeviceNotificationW(HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags){
	HDEVNOTIFY ret = pRegisterDeviceNotificationW(hRecipient,NotificationFilter,Flags);
	OutputDebugStringA("RegisterDeviceNotificationW");
	return ret;
}

BOOL (WINAPI *pUnregisterDeviceNotification) (HDEVNOTIFY handle) = UnregisterDeviceNotification;
BOOL fake_UnregisterDeviceNotification(HDEVNOTIFY handle){
	BOOL ret = pUnregisterDeviceNotification(handle);
	OutputDebugStringA("UnregisterDeviceNotification");
	return ret;
}

HPOWERNOTIFY (WINAPI *pRegisterPowerSettingNotification) (HANDLE hRecipient,LPCGUID PowerSettingGuid,DWORD Flags) = RegisterPowerSettingNotification;
HPOWERNOTIFY fake_RegisterPowerSettingNotification(HANDLE hRecipient,LPCGUID PowerSettingGuid,DWORD Flags){
	HPOWERNOTIFY ret = pRegisterPowerSettingNotification(hRecipient,PowerSettingGuid,Flags);
	OutputDebugStringA("RegisterPowerSettingNotification");
	return ret;
}

BOOL (WINAPI *pUnregisterPowerSettingNotification) (HPOWERNOTIFY Handle) = UnregisterPowerSettingNotification;
BOOL fake_UnregisterPowerSettingNotification(HPOWERNOTIFY Handle){
	BOOL ret = pUnregisterPowerSettingNotification(Handle);
	OutputDebugStringA("UnregisterPowerSettingNotification");
	return ret;
}

BOOL (WINAPI *pPostMessageA) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam) = PostMessageA;
BOOL fake_PostMessageA(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam){
	BOOL ret = pPostMessageA(hWnd,Msg,wParam,lParam);
	OutputDebugStringA("PostMessageA");
	return ret;
}

BOOL (WINAPI *pPostMessageW) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam) = PostMessageW;
BOOL fake_PostMessageW(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam){
	BOOL ret = pPostMessageW(hWnd,Msg,wParam,lParam);
	OutputDebugStringA("PostMessageW");
	return ret;
}

BOOL (WINAPI *pPostThreadMessageA) (DWORD idThread,UINT Msg,WPARAM wParam,LPARAM lParam) = PostThreadMessageA;
BOOL fake_PostThreadMessageA(DWORD idThread,UINT Msg,WPARAM wParam,LPARAM lParam){
	BOOL ret = pPostThreadMessageA(idThread,Msg,wParam,lParam);
	OutputDebugStringA("PostThreadMessageA");
	return ret;
}

BOOL (WINAPI *pPostThreadMessageW) (DWORD idThread,UINT Msg,WPARAM wParam,LPARAM lParam) = PostThreadMessageW;
BOOL fake_PostThreadMessageW(DWORD idThread,UINT Msg,WPARAM wParam,LPARAM lParam){
	BOOL ret = pPostThreadMessageW(idThread,Msg,wParam,lParam);
	OutputDebugStringA("PostThreadMessageW");
	return ret;
}

BOOL (WINAPI *pAttachThreadInput) (DWORD idAttach,DWORD idAttachTo,BOOL fAttach) = AttachThreadInput;
BOOL fake_AttachThreadInput(DWORD idAttach,DWORD idAttachTo,BOOL fAttach){
	BOOL ret = pAttachThreadInput(idAttach,idAttachTo,fAttach);
	OutputDebugStringA("AttachThreadInput");
	return ret;
}

BOOL (WINAPI *pReplyMessage) (LRESULT lResult) = ReplyMessage;
BOOL fake_ReplyMessage(LRESULT lResult){
	BOOL ret = pReplyMessage(lResult);
	OutputDebugStringA("ReplyMessage");
	return ret;
}

BOOL (WINAPI *pWaitMessage) () = WaitMessage;
BOOL fake_WaitMessage(){
	BOOL ret = pWaitMessage();
	OutputDebugStringA("WaitMessage");
	return ret;
}

DWORD (WINAPI *pWaitForInputIdle) (HANDLE hProcess,DWORD dwMilliseconds) = WaitForInputIdle;
DWORD fake_WaitForInputIdle(HANDLE hProcess,DWORD dwMilliseconds){
	DWORD ret = pWaitForInputIdle(hProcess,dwMilliseconds);
	OutputDebugStringA("WaitForInputIdle");
	return ret;
}

LRESULT (WINAPI *pDefWindowProcA) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam) = DefWindowProcA;
LRESULT fake_DefWindowProcA(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pDefWindowProcA(hWnd,Msg,wParam,lParam);
	OutputDebugStringA("DefWindowProcA");
	return ret;
}

LRESULT (WINAPI *pDefWindowProcW) (HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam) = DefWindowProcW;
LRESULT fake_DefWindowProcW(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pDefWindowProcW(hWnd,Msg,wParam,lParam);
	OutputDebugStringA("DefWindowProcW");
	return ret;
}

VOID (WINAPI *pPostQuitMessage) (int nExitCode) = PostQuitMessage;
VOID fake_PostQuitMessage(int nExitCode){
	pPostQuitMessage(nExitCode);
	OutputDebugStringA("PostQuitMessage");
}

LRESULT (WINAPI *pCallWindowProcA) (WNDPROC lpPrevWndFunc,HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam) = CallWindowProcA;
LRESULT fake_CallWindowProcA(WNDPROC lpPrevWndFunc,HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pCallWindowProcA(lpPrevWndFunc,hWnd,Msg,wParam,lParam);
	OutputDebugStringA("CallWindowProcA");
	return ret;
}

LRESULT (WINAPI *pCallWindowProcW) (WNDPROC lpPrevWndFunc,HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam) = CallWindowProcW;
LRESULT fake_CallWindowProcW(WNDPROC lpPrevWndFunc,HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pCallWindowProcW(lpPrevWndFunc,hWnd,Msg,wParam,lParam);
	OutputDebugStringA("CallWindowProcW");
	return ret;
}

BOOL (WINAPI *pInSendMessage) () = InSendMessage;
BOOL fake_InSendMessage(){
	BOOL ret = pInSendMessage();
	OutputDebugStringA("InSendMessage");
	return ret;
}

DWORD (WINAPI *pInSendMessageEx) (LPVOID lpReserved) = InSendMessageEx;
DWORD fake_InSendMessageEx(LPVOID lpReserved){
	DWORD ret = pInSendMessageEx(lpReserved);
	OutputDebugStringA("InSendMessageEx");
	return ret;
}

UINT (WINAPI *pGetDoubleClickTime) () = GetDoubleClickTime;
UINT fake_GetDoubleClickTime(){
	UINT ret = pGetDoubleClickTime();
	OutputDebugStringA("GetDoubleClickTime");
	return ret;
}

BOOL (WINAPI *pSetDoubleClickTime) (UINT arg0) = SetDoubleClickTime;
BOOL fake_SetDoubleClickTime(UINT arg0){
	BOOL ret = pSetDoubleClickTime(arg0);
	OutputDebugStringA("SetDoubleClickTime");
	return ret;
}

ATOM (WINAPI *pRegisterClassA) (CONST WNDCLASSA* lpWndClass) = RegisterClassA;
ATOM fake_RegisterClassA(CONST WNDCLASSA* lpWndClass){
	ATOM ret = pRegisterClassA(lpWndClass);
	OutputDebugStringA("RegisterClassA");
	return ret;
}

ATOM (WINAPI *pRegisterClassW) (CONST WNDCLASSW* lpWndClass) = RegisterClassW;
ATOM fake_RegisterClassW(CONST WNDCLASSW* lpWndClass){
	ATOM ret = pRegisterClassW(lpWndClass);
	OutputDebugStringA("RegisterClassW");
	return ret;
}

BOOL (WINAPI *pUnregisterClassA) (LPCSTR lpClassName,HINSTANCE hInstance) = UnregisterClassA;
BOOL fake_UnregisterClassA(LPCSTR lpClassName,HINSTANCE hInstance){
	BOOL ret = pUnregisterClassA(lpClassName,hInstance);
	OutputDebugStringA("UnregisterClassA");
	return ret;
}

BOOL (WINAPI *pUnregisterClassW) (LPCWSTR lpClassName,HINSTANCE hInstance) = UnregisterClassW;
BOOL fake_UnregisterClassW(LPCWSTR lpClassName,HINSTANCE hInstance){
	BOOL ret = pUnregisterClassW(lpClassName,hInstance);
	OutputDebugStringA("UnregisterClassW");
	return ret;
}

BOOL (WINAPI *pGetClassInfoA) (HINSTANCE hInstance,LPCSTR lpClassName,LPWNDCLASSA lpWndClass) = GetClassInfoA;
BOOL fake_GetClassInfoA(HINSTANCE hInstance,LPCSTR lpClassName,LPWNDCLASSA lpWndClass){
	BOOL ret = pGetClassInfoA(hInstance,lpClassName,lpWndClass);
	OutputDebugStringA("GetClassInfoA");
	return ret;
}

BOOL (WINAPI *pGetClassInfoW) (HINSTANCE hInstance,LPCWSTR lpClassName,LPWNDCLASSW lpWndClass) = GetClassInfoW;
BOOL fake_GetClassInfoW(HINSTANCE hInstance,LPCWSTR lpClassName,LPWNDCLASSW lpWndClass){
	BOOL ret = pGetClassInfoW(hInstance,lpClassName,lpWndClass);
	OutputDebugStringA("GetClassInfoW");
	return ret;
}

ATOM (WINAPI *pRegisterClassExA) (CONST WNDCLASSEXA* arg0) = RegisterClassExA;
ATOM fake_RegisterClassExA(CONST WNDCLASSEXA* arg0){
	ATOM ret = pRegisterClassExA(arg0);
	OutputDebugStringA("RegisterClassExA");
	return ret;
}

ATOM (WINAPI *pRegisterClassExW) (CONST WNDCLASSEXW* arg0) = RegisterClassExW;
ATOM fake_RegisterClassExW(CONST WNDCLASSEXW* arg0){
	ATOM ret = pRegisterClassExW(arg0);
	OutputDebugStringA("RegisterClassExW");
	return ret;
}

BOOL (WINAPI *pGetClassInfoExA) (HINSTANCE hInstance,LPCSTR lpszClass,LPWNDCLASSEXA lpwcx) = GetClassInfoExA;
BOOL fake_GetClassInfoExA(HINSTANCE hInstance,LPCSTR lpszClass,LPWNDCLASSEXA lpwcx){
	BOOL ret = pGetClassInfoExA(hInstance,lpszClass,lpwcx);
	OutputDebugStringA("GetClassInfoExA");
	return ret;
}

BOOL (WINAPI *pGetClassInfoExW) (HINSTANCE hInstance,LPCWSTR lpszClass,LPWNDCLASSEXW lpwcx) = GetClassInfoExW;
BOOL fake_GetClassInfoExW(HINSTANCE hInstance,LPCWSTR lpszClass,LPWNDCLASSEXW lpwcx){
	BOOL ret = pGetClassInfoExW(hInstance,lpszClass,lpwcx);
	OutputDebugStringA("GetClassInfoExW");
	return ret;
}

HWND (WINAPI *pCreateWindowExA) (DWORD dwExStyle,LPCSTR lpClassName,LPCSTR lpWindowName,DWORD dwStyle,int X,int Y,int nWidth,int nHeight,HWND hWndParent,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam) = CreateWindowExA;
HWND fake_CreateWindowExA(DWORD dwExStyle,LPCSTR lpClassName,LPCSTR lpWindowName,DWORD dwStyle,int X,int Y,int nWidth,int nHeight,HWND hWndParent,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam){
	HWND ret = pCreateWindowExA(dwExStyle,lpClassName,lpWindowName,dwStyle,X,Y,nWidth,nHeight,hWndParent,hMenu,hInstance,lpParam);
	OutputDebugStringA("CreateWindowExA");
	return ret;
}

HWND (WINAPI *pCreateWindowExW) (DWORD dwExStyle,LPCWSTR lpClassName,LPCWSTR lpWindowName,DWORD dwStyle,int X,int Y,int nWidth,int nHeight,HWND hWndParent,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam) = CreateWindowExW;
HWND fake_CreateWindowExW(DWORD dwExStyle,LPCWSTR lpClassName,LPCWSTR lpWindowName,DWORD dwStyle,int X,int Y,int nWidth,int nHeight,HWND hWndParent,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam){
	HWND ret = pCreateWindowExW(dwExStyle,lpClassName,lpWindowName,dwStyle,X,Y,nWidth,nHeight,hWndParent,hMenu,hInstance,lpParam);
	OutputDebugStringA("CreateWindowExW");
	return ret;
}

BOOL (WINAPI *pIsWindow) (HWND hWnd) = IsWindow;
BOOL fake_IsWindow(HWND hWnd){
	BOOL ret = pIsWindow(hWnd);
	OutputDebugStringA("IsWindow");
	return ret;
}

BOOL (WINAPI *pIsMenu) (HMENU hMenu) = IsMenu;
BOOL fake_IsMenu(HMENU hMenu){
	BOOL ret = pIsMenu(hMenu);
	OutputDebugStringA("IsMenu");
	return ret;
}

BOOL (WINAPI *pIsChild) (HWND hWndParent,HWND hWnd) = IsChild;
BOOL fake_IsChild(HWND hWndParent,HWND hWnd){
	BOOL ret = pIsChild(hWndParent,hWnd);
	OutputDebugStringA("IsChild");
	return ret;
}

BOOL (WINAPI *pDestroyWindow) (HWND hWnd) = DestroyWindow;
BOOL fake_DestroyWindow(HWND hWnd){
	BOOL ret = pDestroyWindow(hWnd);
	OutputDebugStringA("DestroyWindow");
	return ret;
}

BOOL (WINAPI *pShowWindow) (HWND hWnd,int nCmdShow) = ShowWindow;
BOOL fake_ShowWindow(HWND hWnd,int nCmdShow){
	BOOL ret = pShowWindow(hWnd,nCmdShow);
	OutputDebugStringA("ShowWindow");
	return ret;
}

BOOL (WINAPI *pAnimateWindow) (HWND hWnd,DWORD dwTime,DWORD dwFlags) = AnimateWindow;
BOOL fake_AnimateWindow(HWND hWnd,DWORD dwTime,DWORD dwFlags){
	BOOL ret = pAnimateWindow(hWnd,dwTime,dwFlags);
	OutputDebugStringA("AnimateWindow");
	return ret;
}

BOOL (WINAPI *pUpdateLayeredWindow) (HWND hWnd,HDC hdcDst,POINT*  pptDst,SIZE*  psize,HDC hdcSrc,POINT*  pptSrc,COLORREF crKey,BLENDFUNCTION*  pblend,DWORD dwFlags) = UpdateLayeredWindow;
BOOL fake_UpdateLayeredWindow(HWND hWnd,HDC hdcDst,POINT*  pptDst,SIZE*  psize,HDC hdcSrc,POINT*  pptSrc,COLORREF crKey,BLENDFUNCTION*  pblend,DWORD dwFlags){
	BOOL ret = pUpdateLayeredWindow(hWnd,hdcDst, pptDst, psize,hdcSrc, pptSrc,crKey, pblend,dwFlags);
	OutputDebugStringA("UpdateLayeredWindow");
	return ret;
}

BOOL (WINAPI *pUpdateLayeredWindowIndirect) (HWND hWnd,CONST UPDATELAYEREDWINDOWINFO*  pULWInfo) = UpdateLayeredWindowIndirect;
BOOL fake_UpdateLayeredWindowIndirect(HWND hWnd,CONST UPDATELAYEREDWINDOWINFO*  pULWInfo){
	BOOL ret = pUpdateLayeredWindowIndirect(hWnd, pULWInfo);
	OutputDebugStringA("UpdateLayeredWindowIndirect");
	return ret;
}

BOOL (WINAPI *pGetLayeredWindowAttributes) (HWND hwnd,COLORREF*  pcrKey,BYTE*  pbAlpha,DWORD*  pdwFlags) = GetLayeredWindowAttributes;
BOOL fake_GetLayeredWindowAttributes(HWND hwnd,COLORREF*  pcrKey,BYTE*  pbAlpha,DWORD*  pdwFlags){
	BOOL ret = pGetLayeredWindowAttributes(hwnd, pcrKey, pbAlpha, pdwFlags);
	OutputDebugStringA("GetLayeredWindowAttributes");
	return ret;
}

BOOL (WINAPI *pPrintWindow) (HWND hwnd,HDC hdcBlt,UINT nFlags) = PrintWindow;
BOOL fake_PrintWindow(HWND hwnd,HDC hdcBlt,UINT nFlags){
	BOOL ret = pPrintWindow(hwnd,hdcBlt,nFlags);
	OutputDebugStringA("PrintWindow");
	return ret;
}

BOOL (WINAPI *pSetLayeredWindowAttributes) (HWND hwnd,COLORREF crKey,BYTE bAlpha,DWORD dwFlags) = SetLayeredWindowAttributes;
BOOL fake_SetLayeredWindowAttributes(HWND hwnd,COLORREF crKey,BYTE bAlpha,DWORD dwFlags){
	BOOL ret = pSetLayeredWindowAttributes(hwnd,crKey,bAlpha,dwFlags);
	OutputDebugStringA("SetLayeredWindowAttributes");
	return ret;
}

BOOL (WINAPI *pShowWindowAsync) (HWND hWnd,int nCmdShow) = ShowWindowAsync;
BOOL fake_ShowWindowAsync(HWND hWnd,int nCmdShow){
	BOOL ret = pShowWindowAsync(hWnd,nCmdShow);
	OutputDebugStringA("ShowWindowAsync");
	return ret;
}

BOOL (WINAPI *pFlashWindow) (HWND hWnd,BOOL bInvert) = FlashWindow;
BOOL fake_FlashWindow(HWND hWnd,BOOL bInvert){
	BOOL ret = pFlashWindow(hWnd,bInvert);
	OutputDebugStringA("FlashWindow");
	return ret;
}

BOOL (WINAPI *pFlashWindowEx) (PFLASHWINFO pfwi) = FlashWindowEx;
BOOL fake_FlashWindowEx(PFLASHWINFO pfwi){
	BOOL ret = pFlashWindowEx(pfwi);
	OutputDebugStringA("FlashWindowEx");
	return ret;
}

BOOL (WINAPI *pShowOwnedPopups) (HWND hWnd,BOOL fShow) = ShowOwnedPopups;
BOOL fake_ShowOwnedPopups(HWND hWnd,BOOL fShow){
	BOOL ret = pShowOwnedPopups(hWnd,fShow);
	OutputDebugStringA("ShowOwnedPopups");
	return ret;
}

BOOL (WINAPI *pOpenIcon) (HWND hWnd) = OpenIcon;
BOOL fake_OpenIcon(HWND hWnd){
	BOOL ret = pOpenIcon(hWnd);
	OutputDebugStringA("OpenIcon");
	return ret;
}

BOOL (WINAPI *pCloseWindow) (HWND hWnd) = CloseWindow;
BOOL fake_CloseWindow(HWND hWnd){
	BOOL ret = pCloseWindow(hWnd);
	OutputDebugStringA("CloseWindow");
	return ret;
}

BOOL (WINAPI *pMoveWindow) (HWND hWnd,int X,int Y,int nWidth,int nHeight,BOOL bRepaint) = MoveWindow;
BOOL fake_MoveWindow(HWND hWnd,int X,int Y,int nWidth,int nHeight,BOOL bRepaint){
	BOOL ret = pMoveWindow(hWnd,X,Y,nWidth,nHeight,bRepaint);
	OutputDebugStringA("MoveWindow");
	return ret;
}

BOOL (WINAPI *pSetWindowPos) (HWND hWnd,HWND hWndInsertAfter,int X,int Y,int cx,int cy,UINT uFlags) = SetWindowPos;
BOOL fake_SetWindowPos(HWND hWnd,HWND hWndInsertAfter,int X,int Y,int cx,int cy,UINT uFlags){
	BOOL ret = pSetWindowPos(hWnd,hWndInsertAfter,X,Y,cx,cy,uFlags);
	OutputDebugStringA("SetWindowPos");
	return ret;
}

BOOL (WINAPI *pGetWindowPlacement) (HWND hWnd,WINDOWPLACEMENT* lpwndpl) = GetWindowPlacement;
BOOL fake_GetWindowPlacement(HWND hWnd,WINDOWPLACEMENT* lpwndpl){
	BOOL ret = pGetWindowPlacement(hWnd,lpwndpl);
	OutputDebugStringA("GetWindowPlacement");
	return ret;
}

BOOL (WINAPI *pSetWindowPlacement) (HWND hWnd,CONST WINDOWPLACEMENT* lpwndpl) = SetWindowPlacement;
BOOL fake_SetWindowPlacement(HWND hWnd,CONST WINDOWPLACEMENT* lpwndpl){
	BOOL ret = pSetWindowPlacement(hWnd,lpwndpl);
	OutputDebugStringA("SetWindowPlacement");
	return ret;
}

BOOL (WINAPI *pGetWindowDisplayAffinity) (HWND hWnd,DWORD*  pdwAffinity) = GetWindowDisplayAffinity;
BOOL fake_GetWindowDisplayAffinity(HWND hWnd,DWORD*  pdwAffinity){
	BOOL ret = pGetWindowDisplayAffinity(hWnd, pdwAffinity);
	OutputDebugStringA("GetWindowDisplayAffinity");
	return ret;
}

BOOL (WINAPI *pSetWindowDisplayAffinity) (HWND hWnd,DWORD dwAffinity) = SetWindowDisplayAffinity;
BOOL fake_SetWindowDisplayAffinity(HWND hWnd,DWORD dwAffinity){
	BOOL ret = pSetWindowDisplayAffinity(hWnd,dwAffinity);
	OutputDebugStringA("SetWindowDisplayAffinity");
	return ret;
}

HDWP (WINAPI *pBeginDeferWindowPos) (int nNumWindows) = BeginDeferWindowPos;
HDWP fake_BeginDeferWindowPos(int nNumWindows){
	HDWP ret = pBeginDeferWindowPos(nNumWindows);
	OutputDebugStringA("BeginDeferWindowPos");
	return ret;
}

HDWP (WINAPI *pDeferWindowPos) (HDWP hWinPosInfo,HWND hWnd,HWND hWndInsertAfter,int x,int y,int cx,int cy,UINT uFlags) = DeferWindowPos;
HDWP fake_DeferWindowPos(HDWP hWinPosInfo,HWND hWnd,HWND hWndInsertAfter,int x,int y,int cx,int cy,UINT uFlags){
	HDWP ret = pDeferWindowPos(hWinPosInfo,hWnd,hWndInsertAfter,x,y,cx,cy,uFlags);
	OutputDebugStringA("DeferWindowPos");
	return ret;
}

BOOL (WINAPI *pEndDeferWindowPos) (HDWP hWinPosInfo) = EndDeferWindowPos;
BOOL fake_EndDeferWindowPos(HDWP hWinPosInfo){
	BOOL ret = pEndDeferWindowPos(hWinPosInfo);
	OutputDebugStringA("EndDeferWindowPos");
	return ret;
}

BOOL (WINAPI *pIsWindowVisible) (HWND hWnd) = IsWindowVisible;
BOOL fake_IsWindowVisible(HWND hWnd){
	BOOL ret = pIsWindowVisible(hWnd);
	OutputDebugStringA("IsWindowVisible");
	return ret;
}

BOOL (WINAPI *pIsIconic) (HWND hWnd) = IsIconic;
BOOL fake_IsIconic(HWND hWnd){
	BOOL ret = pIsIconic(hWnd);
	OutputDebugStringA("IsIconic");
	return ret;
}

BOOL (WINAPI *pAnyPopup) () = AnyPopup;
BOOL fake_AnyPopup(){
	BOOL ret = pAnyPopup();
	OutputDebugStringA("AnyPopup");
	return ret;
}

BOOL (WINAPI *pBringWindowToTop) (HWND hWnd) = BringWindowToTop;
BOOL fake_BringWindowToTop(HWND hWnd){
	BOOL ret = pBringWindowToTop(hWnd);
	OutputDebugStringA("BringWindowToTop");
	return ret;
}

BOOL (WINAPI *pIsZoomed) (HWND hWnd) = IsZoomed;
BOOL fake_IsZoomed(HWND hWnd){
	BOOL ret = pIsZoomed(hWnd);
	OutputDebugStringA("IsZoomed");
	return ret;
}

HWND (WINAPI *pCreateDialogParamA) (HINSTANCE hInstance,LPCSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam) = CreateDialogParamA;
HWND fake_CreateDialogParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam){
	HWND ret = pCreateDialogParamA(hInstance,lpTemplateName,hWndParent,lpDialogFunc,dwInitParam);
	OutputDebugStringA("CreateDialogParamA");
	return ret;
}

HWND (WINAPI *pCreateDialogParamW) (HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam) = CreateDialogParamW;
HWND fake_CreateDialogParamW(HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam){
	HWND ret = pCreateDialogParamW(hInstance,lpTemplateName,hWndParent,lpDialogFunc,dwInitParam);
	OutputDebugStringA("CreateDialogParamW");
	return ret;
}

HWND (WINAPI *pCreateDialogIndirectParamA) (HINSTANCE hInstance,LPCDLGTEMPLATEA lpTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam) = CreateDialogIndirectParamA;
HWND fake_CreateDialogIndirectParamA(HINSTANCE hInstance,LPCDLGTEMPLATEA lpTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam){
	HWND ret = pCreateDialogIndirectParamA(hInstance,lpTemplate,hWndParent,lpDialogFunc,dwInitParam);
	OutputDebugStringA("CreateDialogIndirectParamA");
	return ret;
}

HWND (WINAPI *pCreateDialogIndirectParamW) (HINSTANCE hInstance,LPCDLGTEMPLATEW lpTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam) = CreateDialogIndirectParamW;
HWND fake_CreateDialogIndirectParamW(HINSTANCE hInstance,LPCDLGTEMPLATEW lpTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam){
	HWND ret = pCreateDialogIndirectParamW(hInstance,lpTemplate,hWndParent,lpDialogFunc,dwInitParam);
	OutputDebugStringA("CreateDialogIndirectParamW");
	return ret;
}

INT_PTR (WINAPI *pDialogBoxParamA) (HINSTANCE hInstance,LPCSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam) = DialogBoxParamA;
INT_PTR fake_DialogBoxParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam){
	INT_PTR ret = pDialogBoxParamA(hInstance,lpTemplateName,hWndParent,lpDialogFunc,dwInitParam);
	OutputDebugStringA("DialogBoxParamA");
	return ret;
}

INT_PTR (WINAPI *pDialogBoxParamW) (HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam) = DialogBoxParamW;
INT_PTR fake_DialogBoxParamW(HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam){
	INT_PTR ret = pDialogBoxParamW(hInstance,lpTemplateName,hWndParent,lpDialogFunc,dwInitParam);
	OutputDebugStringA("DialogBoxParamW");
	return ret;
}

INT_PTR (WINAPI *pDialogBoxIndirectParamA) (HINSTANCE hInstance,LPCDLGTEMPLATEA hDialogTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam) = DialogBoxIndirectParamA;
INT_PTR fake_DialogBoxIndirectParamA(HINSTANCE hInstance,LPCDLGTEMPLATEA hDialogTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam){
	INT_PTR ret = pDialogBoxIndirectParamA(hInstance,hDialogTemplate,hWndParent,lpDialogFunc,dwInitParam);
	OutputDebugStringA("DialogBoxIndirectParamA");
	return ret;
}

INT_PTR (WINAPI *pDialogBoxIndirectParamW) (HINSTANCE hInstance,LPCDLGTEMPLATEW hDialogTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam) = DialogBoxIndirectParamW;
INT_PTR fake_DialogBoxIndirectParamW(HINSTANCE hInstance,LPCDLGTEMPLATEW hDialogTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam){
	INT_PTR ret = pDialogBoxIndirectParamW(hInstance,hDialogTemplate,hWndParent,lpDialogFunc,dwInitParam);
	OutputDebugStringA("DialogBoxIndirectParamW");
	return ret;
}

BOOL (WINAPI *pEndDialog) (HWND hDlg,INT_PTR nResult) = EndDialog;
BOOL fake_EndDialog(HWND hDlg,INT_PTR nResult){
	BOOL ret = pEndDialog(hDlg,nResult);
	OutputDebugStringA("EndDialog");
	return ret;
}

HWND (WINAPI *pGetDlgItem) (HWND hDlg,int nIDDlgItem) = GetDlgItem;
HWND fake_GetDlgItem(HWND hDlg,int nIDDlgItem){
	HWND ret = pGetDlgItem(hDlg,nIDDlgItem);
	OutputDebugStringA("GetDlgItem");
	return ret;
}

BOOL (WINAPI *pSetDlgItemInt) (HWND hDlg,int nIDDlgItem,UINT uValue,BOOL bSigned) = SetDlgItemInt;
BOOL fake_SetDlgItemInt(HWND hDlg,int nIDDlgItem,UINT uValue,BOOL bSigned){
	BOOL ret = pSetDlgItemInt(hDlg,nIDDlgItem,uValue,bSigned);
	OutputDebugStringA("SetDlgItemInt");
	return ret;
}

UINT (WINAPI *pGetDlgItemInt) (HWND hDlg,int nIDDlgItem,BOOL* lpTranslated,BOOL bSigned) = GetDlgItemInt;
UINT fake_GetDlgItemInt(HWND hDlg,int nIDDlgItem,BOOL* lpTranslated,BOOL bSigned){
	UINT ret = pGetDlgItemInt(hDlg,nIDDlgItem,lpTranslated,bSigned);
	OutputDebugStringA("GetDlgItemInt");
	return ret;
}

BOOL (WINAPI *pSetDlgItemTextA) (HWND hDlg,int nIDDlgItem,LPCSTR lpString) = SetDlgItemTextA;
BOOL fake_SetDlgItemTextA(HWND hDlg,int nIDDlgItem,LPCSTR lpString){
	BOOL ret = pSetDlgItemTextA(hDlg,nIDDlgItem,lpString);
	OutputDebugStringA("SetDlgItemTextA");
	return ret;
}

BOOL (WINAPI *pSetDlgItemTextW) (HWND hDlg,int nIDDlgItem,LPCWSTR lpString) = SetDlgItemTextW;
BOOL fake_SetDlgItemTextW(HWND hDlg,int nIDDlgItem,LPCWSTR lpString){
	BOOL ret = pSetDlgItemTextW(hDlg,nIDDlgItem,lpString);
	OutputDebugStringA("SetDlgItemTextW");
	return ret;
}

UINT (WINAPI *pGetDlgItemTextA) (HWND hDlg,int nIDDlgItem,LPSTR lpString,int cchMax) = GetDlgItemTextA;
UINT fake_GetDlgItemTextA(HWND hDlg,int nIDDlgItem,LPSTR lpString,int cchMax){
	UINT ret = pGetDlgItemTextA(hDlg,nIDDlgItem,lpString,cchMax);
	OutputDebugStringA("GetDlgItemTextA");
	return ret;
}

UINT (WINAPI *pGetDlgItemTextW) (HWND hDlg,int nIDDlgItem,LPWSTR lpString,int cchMax) = GetDlgItemTextW;
UINT fake_GetDlgItemTextW(HWND hDlg,int nIDDlgItem,LPWSTR lpString,int cchMax){
	UINT ret = pGetDlgItemTextW(hDlg,nIDDlgItem,lpString,cchMax);
	OutputDebugStringA("GetDlgItemTextW");
	return ret;
}

BOOL (WINAPI *pCheckDlgButton) (HWND hDlg,int nIDButton,UINT uCheck) = CheckDlgButton;
BOOL fake_CheckDlgButton(HWND hDlg,int nIDButton,UINT uCheck){
	BOOL ret = pCheckDlgButton(hDlg,nIDButton,uCheck);
	OutputDebugStringA("CheckDlgButton");
	return ret;
}

BOOL (WINAPI *pCheckRadioButton) (HWND hDlg,int nIDFirstButton,int nIDLastButton,int nIDCheckButton) = CheckRadioButton;
BOOL fake_CheckRadioButton(HWND hDlg,int nIDFirstButton,int nIDLastButton,int nIDCheckButton){
	BOOL ret = pCheckRadioButton(hDlg,nIDFirstButton,nIDLastButton,nIDCheckButton);
	OutputDebugStringA("CheckRadioButton");
	return ret;
}

UINT (WINAPI *pIsDlgButtonChecked) (HWND hDlg,int nIDButton) = IsDlgButtonChecked;
UINT fake_IsDlgButtonChecked(HWND hDlg,int nIDButton){
	UINT ret = pIsDlgButtonChecked(hDlg,nIDButton);
	OutputDebugStringA("IsDlgButtonChecked");
	return ret;
}

LRESULT (WINAPI *pSendDlgItemMessageA) (HWND hDlg,int nIDDlgItem,UINT Msg,WPARAM wParam,LPARAM lParam) = SendDlgItemMessageA;
LRESULT fake_SendDlgItemMessageA(HWND hDlg,int nIDDlgItem,UINT Msg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pSendDlgItemMessageA(hDlg,nIDDlgItem,Msg,wParam,lParam);
	OutputDebugStringA("SendDlgItemMessageA");
	return ret;
}

LRESULT (WINAPI *pSendDlgItemMessageW) (HWND hDlg,int nIDDlgItem,UINT Msg,WPARAM wParam,LPARAM lParam) = SendDlgItemMessageW;
LRESULT fake_SendDlgItemMessageW(HWND hDlg,int nIDDlgItem,UINT Msg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pSendDlgItemMessageW(hDlg,nIDDlgItem,Msg,wParam,lParam);
	OutputDebugStringA("SendDlgItemMessageW");
	return ret;
}

HWND (WINAPI *pGetNextDlgGroupItem) (HWND hDlg,HWND hCtl,BOOL bPrevious) = GetNextDlgGroupItem;
HWND fake_GetNextDlgGroupItem(HWND hDlg,HWND hCtl,BOOL bPrevious){
	HWND ret = pGetNextDlgGroupItem(hDlg,hCtl,bPrevious);
	OutputDebugStringA("GetNextDlgGroupItem");
	return ret;
}

HWND (WINAPI *pGetNextDlgTabItem) (HWND hDlg,HWND hCtl,BOOL bPrevious) = GetNextDlgTabItem;
HWND fake_GetNextDlgTabItem(HWND hDlg,HWND hCtl,BOOL bPrevious){
	HWND ret = pGetNextDlgTabItem(hDlg,hCtl,bPrevious);
	OutputDebugStringA("GetNextDlgTabItem");
	return ret;
}

int (WINAPI *pGetDlgCtrlID) (HWND hWnd) = GetDlgCtrlID;
int fake_GetDlgCtrlID(HWND hWnd){
	int ret = pGetDlgCtrlID(hWnd);
	OutputDebugStringA("GetDlgCtrlID");
	return ret;
}

long (WINAPI *pGetDialogBaseUnits) () = GetDialogBaseUnits;
long fake_GetDialogBaseUnits(){
	long ret = pGetDialogBaseUnits();
	OutputDebugStringA("GetDialogBaseUnits");
	return ret;
}

LRESULT (WINAPI *pDefDlgProcA) (HWND hDlg,UINT Msg,WPARAM wParam,LPARAM lParam) = DefDlgProcA;
LRESULT fake_DefDlgProcA(HWND hDlg,UINT Msg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pDefDlgProcA(hDlg,Msg,wParam,lParam);
	OutputDebugStringA("DefDlgProcA");
	return ret;
}

LRESULT (WINAPI *pDefDlgProcW) (HWND hDlg,UINT Msg,WPARAM wParam,LPARAM lParam) = DefDlgProcW;
LRESULT fake_DefDlgProcW(HWND hDlg,UINT Msg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pDefDlgProcW(hDlg,Msg,wParam,lParam);
	OutputDebugStringA("DefDlgProcW");
	return ret;
}

BOOL (WINAPI *pCallMsgFilterA) (LPMSG lpMsg,int nCode) = CallMsgFilterA;
BOOL fake_CallMsgFilterA(LPMSG lpMsg,int nCode){
	BOOL ret = pCallMsgFilterA(lpMsg,nCode);
	OutputDebugStringA("CallMsgFilterA");
	return ret;
}

BOOL (WINAPI *pCallMsgFilterW) (LPMSG lpMsg,int nCode) = CallMsgFilterW;
BOOL fake_CallMsgFilterW(LPMSG lpMsg,int nCode){
	BOOL ret = pCallMsgFilterW(lpMsg,nCode);
	OutputDebugStringA("CallMsgFilterW");
	return ret;
}

BOOL (WINAPI *pOpenClipboard) (HWND hWndNewOwner) = OpenClipboard;
BOOL fake_OpenClipboard(HWND hWndNewOwner){
	BOOL ret = pOpenClipboard(hWndNewOwner);
	OutputDebugStringA("OpenClipboard");
	return ret;
}

BOOL (WINAPI *pCloseClipboard) () = CloseClipboard;
BOOL fake_CloseClipboard(){
	BOOL ret = pCloseClipboard();
	OutputDebugStringA("CloseClipboard");
	return ret;
}

DWORD (WINAPI *pGetClipboardSequenceNumber) () = GetClipboardSequenceNumber;
DWORD fake_GetClipboardSequenceNumber(){
	DWORD ret = pGetClipboardSequenceNumber();
	OutputDebugStringA("GetClipboardSequenceNumber");
	return ret;
}

HWND (WINAPI *pGetClipboardOwner) () = GetClipboardOwner;
HWND fake_GetClipboardOwner(){
	HWND ret = pGetClipboardOwner();
	OutputDebugStringA("GetClipboardOwner");
	return ret;
}

HWND (WINAPI *pSetClipboardViewer) (HWND hWndNewViewer) = SetClipboardViewer;
HWND fake_SetClipboardViewer(HWND hWndNewViewer){
	HWND ret = pSetClipboardViewer(hWndNewViewer);
	OutputDebugStringA("SetClipboardViewer");
	return ret;
}

HWND (WINAPI *pGetClipboardViewer) () = GetClipboardViewer;
HWND fake_GetClipboardViewer(){
	HWND ret = pGetClipboardViewer();
	OutputDebugStringA("GetClipboardViewer");
	return ret;
}

BOOL (WINAPI *pChangeClipboardChain) (HWND hWndRemove,HWND hWndNewNext) = ChangeClipboardChain;
BOOL fake_ChangeClipboardChain(HWND hWndRemove,HWND hWndNewNext){
	BOOL ret = pChangeClipboardChain(hWndRemove,hWndNewNext);
	OutputDebugStringA("ChangeClipboardChain");
	return ret;
}

HANDLE (WINAPI *pSetClipboardData) (UINT uFormat,HANDLE hMem) = SetClipboardData;
HANDLE fake_SetClipboardData(UINT uFormat,HANDLE hMem){
	HANDLE ret = pSetClipboardData(uFormat,hMem);
	OutputDebugStringA("SetClipboardData");
	return ret;
}

HANDLE (WINAPI *pGetClipboardData) (UINT uFormat) = GetClipboardData;
HANDLE fake_GetClipboardData(UINT uFormat){
	HANDLE ret = pGetClipboardData(uFormat);
	OutputDebugStringA("GetClipboardData");
	return ret;
}

UINT (WINAPI *pRegisterClipboardFormatA) (LPCSTR lpszFormat) = RegisterClipboardFormatA;
UINT fake_RegisterClipboardFormatA(LPCSTR lpszFormat){
	UINT ret = pRegisterClipboardFormatA(lpszFormat);
	OutputDebugStringA("RegisterClipboardFormatA");
	return ret;
}

UINT (WINAPI *pRegisterClipboardFormatW) (LPCWSTR lpszFormat) = RegisterClipboardFormatW;
UINT fake_RegisterClipboardFormatW(LPCWSTR lpszFormat){
	UINT ret = pRegisterClipboardFormatW(lpszFormat);
	OutputDebugStringA("RegisterClipboardFormatW");
	return ret;
}

int (WINAPI *pCountClipboardFormats) () = CountClipboardFormats;
int fake_CountClipboardFormats(){
	int ret = pCountClipboardFormats();
	OutputDebugStringA("CountClipboardFormats");
	return ret;
}

UINT (WINAPI *pEnumClipboardFormats) (UINT format) = EnumClipboardFormats;
UINT fake_EnumClipboardFormats(UINT format){
	UINT ret = pEnumClipboardFormats(format);
	OutputDebugStringA("EnumClipboardFormats");
	return ret;
}

int (WINAPI *pGetClipboardFormatNameA) (UINT format,LPSTR lpszFormatName,int cchMaxCount) = GetClipboardFormatNameA;
int fake_GetClipboardFormatNameA(UINT format,LPSTR lpszFormatName,int cchMaxCount){
	int ret = pGetClipboardFormatNameA(format,lpszFormatName,cchMaxCount);
	OutputDebugStringA("GetClipboardFormatNameA");
	return ret;
}

int (WINAPI *pGetClipboardFormatNameW) (UINT format,LPWSTR lpszFormatName,int cchMaxCount) = GetClipboardFormatNameW;
int fake_GetClipboardFormatNameW(UINT format,LPWSTR lpszFormatName,int cchMaxCount){
	int ret = pGetClipboardFormatNameW(format,lpszFormatName,cchMaxCount);
	OutputDebugStringA("GetClipboardFormatNameW");
	return ret;
}

BOOL (WINAPI *pEmptyClipboard) () = EmptyClipboard;
BOOL fake_EmptyClipboard(){
	BOOL ret = pEmptyClipboard();
	OutputDebugStringA("EmptyClipboard");
	return ret;
}

BOOL (WINAPI *pIsClipboardFormatAvailable) (UINT format) = IsClipboardFormatAvailable;
BOOL fake_IsClipboardFormatAvailable(UINT format){
	BOOL ret = pIsClipboardFormatAvailable(format);
	OutputDebugStringA("IsClipboardFormatAvailable");
	return ret;
}

int (WINAPI *pGetPriorityClipboardFormat) (UINT* paFormatPriorityList,int cFormats) = GetPriorityClipboardFormat;
int fake_GetPriorityClipboardFormat(UINT* paFormatPriorityList,int cFormats){
	int ret = pGetPriorityClipboardFormat(paFormatPriorityList,cFormats);
	OutputDebugStringA("GetPriorityClipboardFormat");
	return ret;
}

HWND (WINAPI *pGetOpenClipboardWindow) () = GetOpenClipboardWindow;
HWND fake_GetOpenClipboardWindow(){
	HWND ret = pGetOpenClipboardWindow();
	OutputDebugStringA("GetOpenClipboardWindow");
	return ret;
}

BOOL (WINAPI *pAddClipboardFormatListener) (HWND hwnd) = AddClipboardFormatListener;
BOOL fake_AddClipboardFormatListener(HWND hwnd){
	BOOL ret = pAddClipboardFormatListener(hwnd);
	OutputDebugStringA("AddClipboardFormatListener");
	return ret;
}

BOOL (WINAPI *pRemoveClipboardFormatListener) (HWND hwnd) = RemoveClipboardFormatListener;
BOOL fake_RemoveClipboardFormatListener(HWND hwnd){
	BOOL ret = pRemoveClipboardFormatListener(hwnd);
	OutputDebugStringA("RemoveClipboardFormatListener");
	return ret;
}

BOOL (WINAPI *pGetUpdatedClipboardFormats) (PUINT lpuiFormats,UINT cFormats,PUINT pcFormatsOut) = GetUpdatedClipboardFormats;
BOOL fake_GetUpdatedClipboardFormats(PUINT lpuiFormats,UINT cFormats,PUINT pcFormatsOut){
	BOOL ret = pGetUpdatedClipboardFormats(lpuiFormats,cFormats,pcFormatsOut);
	OutputDebugStringA("GetUpdatedClipboardFormats");
	return ret;
}

BOOL (WINAPI *pCharToOemA) (LPCSTR pSrc,LPSTR pDst) = CharToOemA;
BOOL fake_CharToOemA(LPCSTR pSrc,LPSTR pDst){
	BOOL ret = pCharToOemA(pSrc,pDst);
	OutputDebugStringA("CharToOemA");
	return ret;
}

BOOL (WINAPI *pCharToOemW) (LPCWSTR pSrc,LPSTR pDst) = CharToOemW;
BOOL fake_CharToOemW(LPCWSTR pSrc,LPSTR pDst){
	BOOL ret = pCharToOemW(pSrc,pDst);
	OutputDebugStringA("CharToOemW");
	return ret;
}

BOOL (WINAPI *pOemToCharA) (LPCSTR pSrc,LPSTR pDst) = OemToCharA;
BOOL fake_OemToCharA(LPCSTR pSrc,LPSTR pDst){
	BOOL ret = pOemToCharA(pSrc,pDst);
	OutputDebugStringA("OemToCharA");
	return ret;
}

BOOL (WINAPI *pOemToCharW) (LPCSTR pSrc,LPWSTR pDst) = OemToCharW;
BOOL fake_OemToCharW(LPCSTR pSrc,LPWSTR pDst){
	BOOL ret = pOemToCharW(pSrc,pDst);
	OutputDebugStringA("OemToCharW");
	return ret;
}

BOOL (WINAPI *pCharToOemBuffA) (LPCSTR lpszSrc,LPSTR lpszDst,DWORD cchDstLength) = CharToOemBuffA;
BOOL fake_CharToOemBuffA(LPCSTR lpszSrc,LPSTR lpszDst,DWORD cchDstLength){
	BOOL ret = pCharToOemBuffA(lpszSrc,lpszDst,cchDstLength);
	OutputDebugStringA("CharToOemBuffA");
	return ret;
}

BOOL (WINAPI *pCharToOemBuffW) (LPCWSTR lpszSrc,LPSTR lpszDst,DWORD cchDstLength) = CharToOemBuffW;
BOOL fake_CharToOemBuffW(LPCWSTR lpszSrc,LPSTR lpszDst,DWORD cchDstLength){
	BOOL ret = pCharToOemBuffW(lpszSrc,lpszDst,cchDstLength);
	OutputDebugStringA("CharToOemBuffW");
	return ret;
}

BOOL (WINAPI *pOemToCharBuffA) (LPCSTR lpszSrc,LPSTR lpszDst,DWORD cchDstLength) = OemToCharBuffA;
BOOL fake_OemToCharBuffA(LPCSTR lpszSrc,LPSTR lpszDst,DWORD cchDstLength){
	BOOL ret = pOemToCharBuffA(lpszSrc,lpszDst,cchDstLength);
	OutputDebugStringA("OemToCharBuffA");
	return ret;
}

BOOL (WINAPI *pOemToCharBuffW) (LPCSTR lpszSrc,LPWSTR lpszDst,DWORD cchDstLength) = OemToCharBuffW;
BOOL fake_OemToCharBuffW(LPCSTR lpszSrc,LPWSTR lpszDst,DWORD cchDstLength){
	BOOL ret = pOemToCharBuffW(lpszSrc,lpszDst,cchDstLength);
	OutputDebugStringA("OemToCharBuffW");
	return ret;
}

LPSTR (WINAPI *pCharUpperA) (LPSTR lpsz) = CharUpperA;
LPSTR fake_CharUpperA(LPSTR lpsz){
	LPSTR ret = pCharUpperA(lpsz);
	OutputDebugStringA("CharUpperA");
	return ret;
}

LPWSTR (WINAPI *pCharUpperW) (LPWSTR lpsz) = CharUpperW;
LPWSTR fake_CharUpperW(LPWSTR lpsz){
	LPWSTR ret = pCharUpperW(lpsz);
	OutputDebugStringA("CharUpperW");
	return ret;
}

DWORD (WINAPI *pCharUpperBuffA) (LPSTR lpsz,DWORD cchLength) = CharUpperBuffA;
DWORD fake_CharUpperBuffA(LPSTR lpsz,DWORD cchLength){
	DWORD ret = pCharUpperBuffA(lpsz,cchLength);
	OutputDebugStringA("CharUpperBuffA");
	return ret;
}

DWORD (WINAPI *pCharUpperBuffW) (LPWSTR lpsz,DWORD cchLength) = CharUpperBuffW;
DWORD fake_CharUpperBuffW(LPWSTR lpsz,DWORD cchLength){
	DWORD ret = pCharUpperBuffW(lpsz,cchLength);
	OutputDebugStringA("CharUpperBuffW");
	return ret;
}

LPSTR (WINAPI *pCharLowerA) (LPSTR lpsz) = CharLowerA;
LPSTR fake_CharLowerA(LPSTR lpsz){
	LPSTR ret = pCharLowerA(lpsz);
	OutputDebugStringA("CharLowerA");
	return ret;
}

LPWSTR (WINAPI *pCharLowerW) (LPWSTR lpsz) = CharLowerW;
LPWSTR fake_CharLowerW(LPWSTR lpsz){
	LPWSTR ret = pCharLowerW(lpsz);
	OutputDebugStringA("CharLowerW");
	return ret;
}

DWORD (WINAPI *pCharLowerBuffA) (LPSTR lpsz,DWORD cchLength) = CharLowerBuffA;
DWORD fake_CharLowerBuffA(LPSTR lpsz,DWORD cchLength){
	DWORD ret = pCharLowerBuffA(lpsz,cchLength);
	OutputDebugStringA("CharLowerBuffA");
	return ret;
}

DWORD (WINAPI *pCharLowerBuffW) (LPWSTR lpsz,DWORD cchLength) = CharLowerBuffW;
DWORD fake_CharLowerBuffW(LPWSTR lpsz,DWORD cchLength){
	DWORD ret = pCharLowerBuffW(lpsz,cchLength);
	OutputDebugStringA("CharLowerBuffW");
	return ret;
}

LPSTR (WINAPI *pCharNextA) (LPCSTR lpsz) = CharNextA;
LPSTR fake_CharNextA(LPCSTR lpsz){
	LPSTR ret = pCharNextA(lpsz);
	OutputDebugStringA("CharNextA");
	return ret;
}

LPWSTR (WINAPI *pCharNextW) (LPCWSTR lpsz) = CharNextW;
LPWSTR fake_CharNextW(LPCWSTR lpsz){
	LPWSTR ret = pCharNextW(lpsz);
	OutputDebugStringA("CharNextW");
	return ret;
}

LPSTR (WINAPI *pCharPrevA) (LPCSTR lpszStart,LPCSTR lpszCurrent) = CharPrevA;
LPSTR fake_CharPrevA(LPCSTR lpszStart,LPCSTR lpszCurrent){
	LPSTR ret = pCharPrevA(lpszStart,lpszCurrent);
	OutputDebugStringA("CharPrevA");
	return ret;
}

LPWSTR (WINAPI *pCharPrevW) (LPCWSTR lpszStart,LPCWSTR lpszCurrent) = CharPrevW;
LPWSTR fake_CharPrevW(LPCWSTR lpszStart,LPCWSTR lpszCurrent){
	LPWSTR ret = pCharPrevW(lpszStart,lpszCurrent);
	OutputDebugStringA("CharPrevW");
	return ret;
}

LPSTR (WINAPI *pCharNextExA) (WORD CodePage,LPCSTR lpCurrentChar,DWORD dwFlags) = CharNextExA;
LPSTR fake_CharNextExA(WORD CodePage,LPCSTR lpCurrentChar,DWORD dwFlags){
	LPSTR ret = pCharNextExA(CodePage,lpCurrentChar,dwFlags);
	OutputDebugStringA("CharNextExA");
	return ret;
}

LPSTR (WINAPI *pCharPrevExA) (WORD CodePage,LPCSTR lpStart,LPCSTR lpCurrentChar,DWORD dwFlags) = CharPrevExA;
LPSTR fake_CharPrevExA(WORD CodePage,LPCSTR lpStart,LPCSTR lpCurrentChar,DWORD dwFlags){
	LPSTR ret = pCharPrevExA(CodePage,lpStart,lpCurrentChar,dwFlags);
	OutputDebugStringA("CharPrevExA");
	return ret;
}

BOOL (WINAPI *pIsCharAlphaA) (CHAR ch) = IsCharAlphaA;
BOOL fake_IsCharAlphaA(CHAR ch){
	BOOL ret = pIsCharAlphaA(ch);
	OutputDebugStringA("IsCharAlphaA");
	return ret;
}

BOOL (WINAPI *pIsCharAlphaW) (WCHAR ch) = IsCharAlphaW;
BOOL fake_IsCharAlphaW(WCHAR ch){
	BOOL ret = pIsCharAlphaW(ch);
	OutputDebugStringA("IsCharAlphaW");
	return ret;
}

BOOL (WINAPI *pIsCharAlphaNumericA) (CHAR ch) = IsCharAlphaNumericA;
BOOL fake_IsCharAlphaNumericA(CHAR ch){
	BOOL ret = pIsCharAlphaNumericA(ch);
	OutputDebugStringA("IsCharAlphaNumericA");
	return ret;
}

BOOL (WINAPI *pIsCharAlphaNumericW) (WCHAR ch) = IsCharAlphaNumericW;
BOOL fake_IsCharAlphaNumericW(WCHAR ch){
	BOOL ret = pIsCharAlphaNumericW(ch);
	OutputDebugStringA("IsCharAlphaNumericW");
	return ret;
}

BOOL (WINAPI *pIsCharUpperA) (CHAR ch) = IsCharUpperA;
BOOL fake_IsCharUpperA(CHAR ch){
	BOOL ret = pIsCharUpperA(ch);
	OutputDebugStringA("IsCharUpperA");
	return ret;
}

BOOL (WINAPI *pIsCharUpperW) (WCHAR ch) = IsCharUpperW;
BOOL fake_IsCharUpperW(WCHAR ch){
	BOOL ret = pIsCharUpperW(ch);
	OutputDebugStringA("IsCharUpperW");
	return ret;
}

BOOL (WINAPI *pIsCharLowerA) (CHAR ch) = IsCharLowerA;
BOOL fake_IsCharLowerA(CHAR ch){
	BOOL ret = pIsCharLowerA(ch);
	OutputDebugStringA("IsCharLowerA");
	return ret;
}

BOOL (WINAPI *pIsCharLowerW) (WCHAR ch) = IsCharLowerW;
BOOL fake_IsCharLowerW(WCHAR ch){
	BOOL ret = pIsCharLowerW(ch);
	OutputDebugStringA("IsCharLowerW");
	return ret;
}

HWND (WINAPI *pSetFocus) (HWND hWnd) = SetFocus;
HWND fake_SetFocus(HWND hWnd){
	HWND ret = pSetFocus(hWnd);
	OutputDebugStringA("SetFocus");
	return ret;
}

HWND (WINAPI *pGetActiveWindow) () = GetActiveWindow;
HWND fake_GetActiveWindow(){
	HWND ret = pGetActiveWindow();
	OutputDebugStringA("GetActiveWindow");
	return ret;
}

HWND (WINAPI *pGetFocus) () = GetFocus;
HWND fake_GetFocus(){
	HWND ret = pGetFocus();
	OutputDebugStringA("GetFocus");
	return ret;
}

UINT (WINAPI *pGetKBCodePage) () = GetKBCodePage;
UINT fake_GetKBCodePage(){
	UINT ret = pGetKBCodePage();
	OutputDebugStringA("GetKBCodePage");
	return ret;
}

SHORT (WINAPI *pGetKeyState) (int nVirtKey) = GetKeyState;
SHORT fake_GetKeyState(int nVirtKey){
	SHORT ret = pGetKeyState(nVirtKey);
	OutputDebugStringA("GetKeyState");
	return ret;
}

SHORT (WINAPI *pGetAsyncKeyState) (int vKey) = GetAsyncKeyState;
SHORT fake_GetAsyncKeyState(int vKey){
	SHORT ret = pGetAsyncKeyState(vKey);
	OutputDebugStringA("GetAsyncKeyState");
	return ret;
}

BOOL (WINAPI *pGetKeyboardState) (PBYTE lpKeyState) = GetKeyboardState;
BOOL fake_GetKeyboardState(PBYTE lpKeyState){
	BOOL ret = pGetKeyboardState(lpKeyState);
	OutputDebugStringA("GetKeyboardState");
	return ret;
}

BOOL (WINAPI *pSetKeyboardState) (LPBYTE lpKeyState) = SetKeyboardState;
BOOL fake_SetKeyboardState(LPBYTE lpKeyState){
	BOOL ret = pSetKeyboardState(lpKeyState);
	OutputDebugStringA("SetKeyboardState");
	return ret;
}

int (WINAPI *pGetKeyNameTextA) (LONG lParam,LPSTR lpString,int cchSize) = GetKeyNameTextA;
int fake_GetKeyNameTextA(LONG lParam,LPSTR lpString,int cchSize){
	int ret = pGetKeyNameTextA(lParam,lpString,cchSize);
	OutputDebugStringA("GetKeyNameTextA");
	return ret;
}

int (WINAPI *pGetKeyNameTextW) (LONG lParam,LPWSTR lpString,int cchSize) = GetKeyNameTextW;
int fake_GetKeyNameTextW(LONG lParam,LPWSTR lpString,int cchSize){
	int ret = pGetKeyNameTextW(lParam,lpString,cchSize);
	OutputDebugStringA("GetKeyNameTextW");
	return ret;
}

int (WINAPI *pGetKeyboardType) (int nTypeFlag) = GetKeyboardType;
int fake_GetKeyboardType(int nTypeFlag){
	int ret = pGetKeyboardType(nTypeFlag);
	OutputDebugStringA("GetKeyboardType");
	return ret;
}

int (WINAPI *pToAscii) (UINT uVirtKey,UINT uScanCode,CONST BYTE* lpKeyState,LPWORD lpChar,UINT uFlags) = ToAscii;
int fake_ToAscii(UINT uVirtKey,UINT uScanCode,CONST BYTE* lpKeyState,LPWORD lpChar,UINT uFlags){
	int ret = pToAscii(uVirtKey,uScanCode,lpKeyState,lpChar,uFlags);
	OutputDebugStringA("ToAscii");
	return ret;
}

int (WINAPI *pToAsciiEx) (UINT uVirtKey,UINT uScanCode,CONST BYTE* lpKeyState,LPWORD lpChar,UINT uFlags,HKL dwhkl) = ToAsciiEx;
int fake_ToAsciiEx(UINT uVirtKey,UINT uScanCode,CONST BYTE* lpKeyState,LPWORD lpChar,UINT uFlags,HKL dwhkl){
	int ret = pToAsciiEx(uVirtKey,uScanCode,lpKeyState,lpChar,uFlags,dwhkl);
	OutputDebugStringA("ToAsciiEx");
	return ret;
}

int (WINAPI *pToUnicode) (UINT wVirtKey,UINT wScanCode,CONST BYTE* lpKeyState,LPWSTR pwszBuff,int cchBuff,UINT wFlags) = ToUnicode;
int fake_ToUnicode(UINT wVirtKey,UINT wScanCode,CONST BYTE* lpKeyState,LPWSTR pwszBuff,int cchBuff,UINT wFlags){
	int ret = pToUnicode(wVirtKey,wScanCode,lpKeyState,pwszBuff,cchBuff,wFlags);
	OutputDebugStringA("ToUnicode");
	return ret;
}

DWORD (WINAPI *pOemKeyScan) (WORD wOemChar) = OemKeyScan;
DWORD fake_OemKeyScan(WORD wOemChar){
	DWORD ret = pOemKeyScan(wOemChar);
	OutputDebugStringA("OemKeyScan");
	return ret;
}

SHORT (WINAPI *pVkKeyScanA) (CHAR ch) = VkKeyScanA;
SHORT fake_VkKeyScanA(CHAR ch){
	SHORT ret = pVkKeyScanA(ch);
	OutputDebugStringA("VkKeyScanA");
	return ret;
}

SHORT (WINAPI *pVkKeyScanW) (WCHAR ch) = VkKeyScanW;
SHORT fake_VkKeyScanW(WCHAR ch){
	SHORT ret = pVkKeyScanW(ch);
	OutputDebugStringA("VkKeyScanW");
	return ret;
}

SHORT (WINAPI *pVkKeyScanExA) (CHAR ch,HKL dwhkl) = VkKeyScanExA;
SHORT fake_VkKeyScanExA(CHAR ch,HKL dwhkl){
	SHORT ret = pVkKeyScanExA(ch,dwhkl);
	OutputDebugStringA("VkKeyScanExA");
	return ret;
}

SHORT (WINAPI *pVkKeyScanExW) (WCHAR ch,HKL dwhkl) = VkKeyScanExW;
SHORT fake_VkKeyScanExW(WCHAR ch,HKL dwhkl){
	SHORT ret = pVkKeyScanExW(ch,dwhkl);
	OutputDebugStringA("VkKeyScanExW");
	return ret;
}

VOID (WINAPI *pkeybd_event) (BYTE bVk,BYTE bScan,DWORD dwFlags,ULONG_PTR dwExtraInfo) = keybd_event;
VOID fake_keybd_event(BYTE bVk,BYTE bScan,DWORD dwFlags,ULONG_PTR dwExtraInfo){
	pkeybd_event(bVk,bScan,dwFlags,dwExtraInfo);
	OutputDebugStringA("keybd_event");
}

VOID (WINAPI *pmouse_event) (DWORD dwFlags,DWORD dx,DWORD dy,DWORD dwData,ULONG_PTR dwExtraInfo) = mouse_event;
VOID fake_mouse_event(DWORD dwFlags,DWORD dx,DWORD dy,DWORD dwData,ULONG_PTR dwExtraInfo){
	pmouse_event(dwFlags,dx,dy,dwData,dwExtraInfo);
	OutputDebugStringA("mouse_event");
}

UINT (WINAPI *pSendInput) (UINT cInputs,LPINPUT pInputs,int cbSize) = SendInput;
UINT fake_SendInput(UINT cInputs,LPINPUT pInputs,int cbSize){
	UINT ret = pSendInput(cInputs,pInputs,cbSize);
	OutputDebugStringA("SendInput");
	return ret;
}

BOOL (WINAPI *pGetTouchInputInfo) (HTOUCHINPUT hTouchInput,UINT cInputs,PTOUCHINPUT pInputs,int cbSize) = GetTouchInputInfo;
BOOL fake_GetTouchInputInfo(HTOUCHINPUT hTouchInput,UINT cInputs,PTOUCHINPUT pInputs,int cbSize){
	BOOL ret = pGetTouchInputInfo(hTouchInput,cInputs,pInputs,cbSize);
	OutputDebugStringA("GetTouchInputInfo");
	return ret;
}

BOOL (WINAPI *pCloseTouchInputHandle) (HTOUCHINPUT hTouchInput) = CloseTouchInputHandle;
BOOL fake_CloseTouchInputHandle(HTOUCHINPUT hTouchInput){
	BOOL ret = pCloseTouchInputHandle(hTouchInput);
	OutputDebugStringA("CloseTouchInputHandle");
	return ret;
}

BOOL (WINAPI *pRegisterTouchWindow) (HWND hwnd,ULONG ulFlags) = RegisterTouchWindow;
BOOL fake_RegisterTouchWindow(HWND hwnd,ULONG ulFlags){
	BOOL ret = pRegisterTouchWindow(hwnd,ulFlags);
	OutputDebugStringA("RegisterTouchWindow");
	return ret;
}

BOOL (WINAPI *pUnregisterTouchWindow) (HWND hwnd) = UnregisterTouchWindow;
BOOL fake_UnregisterTouchWindow(HWND hwnd){
	BOOL ret = pUnregisterTouchWindow(hwnd);
	OutputDebugStringA("UnregisterTouchWindow");
	return ret;
}

BOOL (WINAPI *pIsTouchWindow) (HWND hwnd,PULONG pulFlags) = IsTouchWindow;
BOOL fake_IsTouchWindow(HWND hwnd,PULONG pulFlags){
	BOOL ret = pIsTouchWindow(hwnd,pulFlags);
	OutputDebugStringA("IsTouchWindow");
	return ret;
}

BOOL (WINAPI *pGetLastInputInfo) (PLASTINPUTINFO plii) = GetLastInputInfo;
BOOL fake_GetLastInputInfo(PLASTINPUTINFO plii){
	BOOL ret = pGetLastInputInfo(plii);
	OutputDebugStringA("GetLastInputInfo");
	return ret;
}

UINT (WINAPI *pMapVirtualKeyA) (UINT uCode,UINT uMapType) = MapVirtualKeyA;
UINT fake_MapVirtualKeyA(UINT uCode,UINT uMapType){
	UINT ret = pMapVirtualKeyA(uCode,uMapType);
	OutputDebugStringA("MapVirtualKeyA");
	return ret;
}

UINT (WINAPI *pMapVirtualKeyW) (UINT uCode,UINT uMapType) = MapVirtualKeyW;
UINT fake_MapVirtualKeyW(UINT uCode,UINT uMapType){
	UINT ret = pMapVirtualKeyW(uCode,uMapType);
	OutputDebugStringA("MapVirtualKeyW");
	return ret;
}

UINT (WINAPI *pMapVirtualKeyExA) (UINT uCode,UINT uMapType,HKL dwhkl) = MapVirtualKeyExA;
UINT fake_MapVirtualKeyExA(UINT uCode,UINT uMapType,HKL dwhkl){
	UINT ret = pMapVirtualKeyExA(uCode,uMapType,dwhkl);
	OutputDebugStringA("MapVirtualKeyExA");
	return ret;
}

UINT (WINAPI *pMapVirtualKeyExW) (UINT uCode,UINT uMapType,HKL dwhkl) = MapVirtualKeyExW;
UINT fake_MapVirtualKeyExW(UINT uCode,UINT uMapType,HKL dwhkl){
	UINT ret = pMapVirtualKeyExW(uCode,uMapType,dwhkl);
	OutputDebugStringA("MapVirtualKeyExW");
	return ret;
}

BOOL (WINAPI *pGetInputState) () = GetInputState;
BOOL fake_GetInputState(){
	BOOL ret = pGetInputState();
	OutputDebugStringA("GetInputState");
	return ret;
}

DWORD (WINAPI *pGetQueueStatus) (UINT flags) = GetQueueStatus;
DWORD fake_GetQueueStatus(UINT flags){
	DWORD ret = pGetQueueStatus(flags);
	OutputDebugStringA("GetQueueStatus");
	return ret;
}

HWND (WINAPI *pGetCapture) () = GetCapture;
HWND fake_GetCapture(){
	HWND ret = pGetCapture();
	OutputDebugStringA("GetCapture");
	return ret;
}

HWND (WINAPI *pSetCapture) (HWND hWnd) = SetCapture;
HWND fake_SetCapture(HWND hWnd){
	HWND ret = pSetCapture(hWnd);
	OutputDebugStringA("SetCapture");
	return ret;
}

BOOL (WINAPI *pReleaseCapture) () = ReleaseCapture;
BOOL fake_ReleaseCapture(){
	BOOL ret = pReleaseCapture();
	OutputDebugStringA("ReleaseCapture");
	return ret;
}

DWORD (WINAPI *pMsgWaitForMultipleObjects) (DWORD nCount,CONST HANDLE* pHandles,BOOL fWaitAll,DWORD dwMilliseconds,DWORD dwWakeMask) = MsgWaitForMultipleObjects;
DWORD fake_MsgWaitForMultipleObjects(DWORD nCount,CONST HANDLE* pHandles,BOOL fWaitAll,DWORD dwMilliseconds,DWORD dwWakeMask){
	DWORD ret = pMsgWaitForMultipleObjects(nCount,pHandles,fWaitAll,dwMilliseconds,dwWakeMask);
	OutputDebugStringA("MsgWaitForMultipleObjects");
	return ret;
}

DWORD (WINAPI *pMsgWaitForMultipleObjectsEx) (DWORD nCount,CONST HANDLE* pHandles,DWORD dwMilliseconds,DWORD dwWakeMask,DWORD dwFlags) = MsgWaitForMultipleObjectsEx;
DWORD fake_MsgWaitForMultipleObjectsEx(DWORD nCount,CONST HANDLE* pHandles,DWORD dwMilliseconds,DWORD dwWakeMask,DWORD dwFlags){
	DWORD ret = pMsgWaitForMultipleObjectsEx(nCount,pHandles,dwMilliseconds,dwWakeMask,dwFlags);
	OutputDebugStringA("MsgWaitForMultipleObjectsEx");
	return ret;
}

UINT_PTR (WINAPI *pSetTimer) (HWND hWnd,UINT_PTR nIDEvent,UINT uElapse,TIMERPROC lpTimerFunc) = SetTimer;
UINT_PTR fake_SetTimer(HWND hWnd,UINT_PTR nIDEvent,UINT uElapse,TIMERPROC lpTimerFunc){
	UINT_PTR ret = pSetTimer(hWnd,nIDEvent,uElapse,lpTimerFunc);
	OutputDebugStringA("SetTimer");
	return ret;
}

BOOL (WINAPI *pKillTimer) (HWND hWnd,UINT_PTR uIDEvent) = KillTimer;
BOOL fake_KillTimer(HWND hWnd,UINT_PTR uIDEvent){
	BOOL ret = pKillTimer(hWnd,uIDEvent);
	OutputDebugStringA("KillTimer");
	return ret;
}

BOOL (WINAPI *pIsWindowUnicode) (HWND hWnd) = IsWindowUnicode;
BOOL fake_IsWindowUnicode(HWND hWnd){
	BOOL ret = pIsWindowUnicode(hWnd);
	OutputDebugStringA("IsWindowUnicode");
	return ret;
}

BOOL (WINAPI *pEnableWindow) (HWND hWnd,BOOL bEnable) = EnableWindow;
BOOL fake_EnableWindow(HWND hWnd,BOOL bEnable){
	BOOL ret = pEnableWindow(hWnd,bEnable);
	OutputDebugStringA("EnableWindow");
	return ret;
}

BOOL (WINAPI *pIsWindowEnabled) (HWND hWnd) = IsWindowEnabled;
BOOL fake_IsWindowEnabled(HWND hWnd){
	BOOL ret = pIsWindowEnabled(hWnd);
	OutputDebugStringA("IsWindowEnabled");
	return ret;
}

HACCEL (WINAPI *pLoadAcceleratorsA) (HINSTANCE hInstance,LPCSTR lpTableName) = LoadAcceleratorsA;
HACCEL fake_LoadAcceleratorsA(HINSTANCE hInstance,LPCSTR lpTableName){
	HACCEL ret = pLoadAcceleratorsA(hInstance,lpTableName);
	OutputDebugStringA("LoadAcceleratorsA");
	return ret;
}

HACCEL (WINAPI *pLoadAcceleratorsW) (HINSTANCE hInstance,LPCWSTR lpTableName) = LoadAcceleratorsW;
HACCEL fake_LoadAcceleratorsW(HINSTANCE hInstance,LPCWSTR lpTableName){
	HACCEL ret = pLoadAcceleratorsW(hInstance,lpTableName);
	OutputDebugStringA("LoadAcceleratorsW");
	return ret;
}

HACCEL (WINAPI *pCreateAcceleratorTableA) (LPACCEL paccel,int cAccel) = CreateAcceleratorTableA;
HACCEL fake_CreateAcceleratorTableA(LPACCEL paccel,int cAccel){
	HACCEL ret = pCreateAcceleratorTableA(paccel,cAccel);
	OutputDebugStringA("CreateAcceleratorTableA");
	return ret;
}

HACCEL (WINAPI *pCreateAcceleratorTableW) (LPACCEL paccel,int cAccel) = CreateAcceleratorTableW;
HACCEL fake_CreateAcceleratorTableW(LPACCEL paccel,int cAccel){
	HACCEL ret = pCreateAcceleratorTableW(paccel,cAccel);
	OutputDebugStringA("CreateAcceleratorTableW");
	return ret;
}

BOOL (WINAPI *pDestroyAcceleratorTable) (HACCEL hAccel) = DestroyAcceleratorTable;
BOOL fake_DestroyAcceleratorTable(HACCEL hAccel){
	BOOL ret = pDestroyAcceleratorTable(hAccel);
	OutputDebugStringA("DestroyAcceleratorTable");
	return ret;
}

int (WINAPI *pCopyAcceleratorTableA) (HACCEL hAccelSrc,LPACCEL lpAccelDst,int cAccelEntries) = CopyAcceleratorTableA;
int fake_CopyAcceleratorTableA(HACCEL hAccelSrc,LPACCEL lpAccelDst,int cAccelEntries){
	int ret = pCopyAcceleratorTableA(hAccelSrc,lpAccelDst,cAccelEntries);
	OutputDebugStringA("CopyAcceleratorTableA");
	return ret;
}

int (WINAPI *pCopyAcceleratorTableW) (HACCEL hAccelSrc,LPACCEL lpAccelDst,int cAccelEntries) = CopyAcceleratorTableW;
int fake_CopyAcceleratorTableW(HACCEL hAccelSrc,LPACCEL lpAccelDst,int cAccelEntries){
	int ret = pCopyAcceleratorTableW(hAccelSrc,lpAccelDst,cAccelEntries);
	OutputDebugStringA("CopyAcceleratorTableW");
	return ret;
}

int (WINAPI *pTranslateAcceleratorA) (HWND hWnd,HACCEL hAccTable,LPMSG lpMsg) = TranslateAcceleratorA;
int fake_TranslateAcceleratorA(HWND hWnd,HACCEL hAccTable,LPMSG lpMsg){
	int ret = pTranslateAcceleratorA(hWnd,hAccTable,lpMsg);
	OutputDebugStringA("TranslateAcceleratorA");
	return ret;
}

int (WINAPI *pTranslateAcceleratorW) (HWND hWnd,HACCEL hAccTable,LPMSG lpMsg) = TranslateAcceleratorW;
int fake_TranslateAcceleratorW(HWND hWnd,HACCEL hAccTable,LPMSG lpMsg){
	int ret = pTranslateAcceleratorW(hWnd,hAccTable,lpMsg);
	OutputDebugStringA("TranslateAcceleratorW");
	return ret;
}

int (WINAPI *pGetSystemMetrics) (int nIndex) = GetSystemMetrics;
int fake_GetSystemMetrics(int nIndex){
	int ret = pGetSystemMetrics(nIndex);
	OutputDebugStringA("GetSystemMetrics");
	return ret;
}

HMENU (WINAPI *pLoadMenuA) (HINSTANCE hInstance,LPCSTR lpMenuName) = LoadMenuA;
HMENU fake_LoadMenuA(HINSTANCE hInstance,LPCSTR lpMenuName){
	HMENU ret = pLoadMenuA(hInstance,lpMenuName);
	OutputDebugStringA("LoadMenuA");
	return ret;
}

HMENU (WINAPI *pLoadMenuW) (HINSTANCE hInstance,LPCWSTR lpMenuName) = LoadMenuW;
HMENU fake_LoadMenuW(HINSTANCE hInstance,LPCWSTR lpMenuName){
	HMENU ret = pLoadMenuW(hInstance,lpMenuName);
	OutputDebugStringA("LoadMenuW");
	return ret;
}

HMENU (WINAPI *pLoadMenuIndirectA) (CONST MENUTEMPLATEA* lpMenuTemplate) = LoadMenuIndirectA;
HMENU fake_LoadMenuIndirectA(CONST MENUTEMPLATEA* lpMenuTemplate){
	HMENU ret = pLoadMenuIndirectA(lpMenuTemplate);
	OutputDebugStringA("LoadMenuIndirectA");
	return ret;
}

HMENU (WINAPI *pLoadMenuIndirectW) (CONST MENUTEMPLATEW* lpMenuTemplate) = LoadMenuIndirectW;
HMENU fake_LoadMenuIndirectW(CONST MENUTEMPLATEW* lpMenuTemplate){
	HMENU ret = pLoadMenuIndirectW(lpMenuTemplate);
	OutputDebugStringA("LoadMenuIndirectW");
	return ret;
}

HMENU (WINAPI *pGetMenu) (HWND hWnd) = GetMenu;
HMENU fake_GetMenu(HWND hWnd){
	HMENU ret = pGetMenu(hWnd);
	OutputDebugStringA("GetMenu");
	return ret;
}

BOOL (WINAPI *pSetMenu) (HWND hWnd,HMENU hMenu) = SetMenu;
BOOL fake_SetMenu(HWND hWnd,HMENU hMenu){
	BOOL ret = pSetMenu(hWnd,hMenu);
	OutputDebugStringA("SetMenu");
	return ret;
}

BOOL (WINAPI *pChangeMenuA) (HMENU hMenu,UINT cmd,LPCSTR lpszNewItem,UINT cmdInsert,UINT flags) = ChangeMenuA;
BOOL fake_ChangeMenuA(HMENU hMenu,UINT cmd,LPCSTR lpszNewItem,UINT cmdInsert,UINT flags){
	BOOL ret = pChangeMenuA(hMenu,cmd,lpszNewItem,cmdInsert,flags);
	OutputDebugStringA("ChangeMenuA");
	return ret;
}

BOOL (WINAPI *pChangeMenuW) (HMENU hMenu,UINT cmd,LPCWSTR lpszNewItem,UINT cmdInsert,UINT flags) = ChangeMenuW;
BOOL fake_ChangeMenuW(HMENU hMenu,UINT cmd,LPCWSTR lpszNewItem,UINT cmdInsert,UINT flags){
	BOOL ret = pChangeMenuW(hMenu,cmd,lpszNewItem,cmdInsert,flags);
	OutputDebugStringA("ChangeMenuW");
	return ret;
}

BOOL (WINAPI *pHiliteMenuItem) (HWND hWnd,HMENU hMenu,UINT uIDHiliteItem,UINT uHilite) = HiliteMenuItem;
BOOL fake_HiliteMenuItem(HWND hWnd,HMENU hMenu,UINT uIDHiliteItem,UINT uHilite){
	BOOL ret = pHiliteMenuItem(hWnd,hMenu,uIDHiliteItem,uHilite);
	OutputDebugStringA("HiliteMenuItem");
	return ret;
}

int (WINAPI *pGetMenuStringA) (HMENU hMenu,UINT uIDItem,LPSTR lpString,int cchMax,UINT flags) = GetMenuStringA;
int fake_GetMenuStringA(HMENU hMenu,UINT uIDItem,LPSTR lpString,int cchMax,UINT flags){
	int ret = pGetMenuStringA(hMenu,uIDItem,lpString,cchMax,flags);
	OutputDebugStringA("GetMenuStringA");
	return ret;
}

int (WINAPI *pGetMenuStringW) (HMENU hMenu,UINT uIDItem,LPWSTR lpString,int cchMax,UINT flags) = GetMenuStringW;
int fake_GetMenuStringW(HMENU hMenu,UINT uIDItem,LPWSTR lpString,int cchMax,UINT flags){
	int ret = pGetMenuStringW(hMenu,uIDItem,lpString,cchMax,flags);
	OutputDebugStringA("GetMenuStringW");
	return ret;
}

UINT (WINAPI *pGetMenuState) (HMENU hMenu,UINT uId,UINT uFlags) = GetMenuState;
UINT fake_GetMenuState(HMENU hMenu,UINT uId,UINT uFlags){
	UINT ret = pGetMenuState(hMenu,uId,uFlags);
	OutputDebugStringA("GetMenuState");
	return ret;
}

BOOL (WINAPI *pDrawMenuBar) (HWND hWnd) = DrawMenuBar;
BOOL fake_DrawMenuBar(HWND hWnd){
	BOOL ret = pDrawMenuBar(hWnd);
	OutputDebugStringA("DrawMenuBar");
	return ret;
}

HMENU (WINAPI *pGetSystemMenu) (HWND hWnd,BOOL bRevert) = GetSystemMenu;
HMENU fake_GetSystemMenu(HWND hWnd,BOOL bRevert){
	HMENU ret = pGetSystemMenu(hWnd,bRevert);
	OutputDebugStringA("GetSystemMenu");
	return ret;
}

HMENU (WINAPI *pCreateMenu) () = CreateMenu;
HMENU fake_CreateMenu(){
	HMENU ret = pCreateMenu();
	OutputDebugStringA("CreateMenu");
	return ret;
}

HMENU (WINAPI *pCreatePopupMenu) () = CreatePopupMenu;
HMENU fake_CreatePopupMenu(){
	HMENU ret = pCreatePopupMenu();
	OutputDebugStringA("CreatePopupMenu");
	return ret;
}

BOOL (WINAPI *pDestroyMenu) (HMENU hMenu) = DestroyMenu;
BOOL fake_DestroyMenu(HMENU hMenu){
	BOOL ret = pDestroyMenu(hMenu);
	OutputDebugStringA("DestroyMenu");
	return ret;
}

DWORD (WINAPI *pCheckMenuItem) (HMENU hMenu,UINT uIDCheckItem,UINT uCheck) = CheckMenuItem;
DWORD fake_CheckMenuItem(HMENU hMenu,UINT uIDCheckItem,UINT uCheck){
	DWORD ret = pCheckMenuItem(hMenu,uIDCheckItem,uCheck);
	OutputDebugStringA("CheckMenuItem");
	return ret;
}

BOOL (WINAPI *pEnableMenuItem) (HMENU hMenu,UINT uIDEnableItem,UINT uEnable) = EnableMenuItem;
BOOL fake_EnableMenuItem(HMENU hMenu,UINT uIDEnableItem,UINT uEnable){
	BOOL ret = pEnableMenuItem(hMenu,uIDEnableItem,uEnable);
	OutputDebugStringA("EnableMenuItem");
	return ret;
}

HMENU (WINAPI *pGetSubMenu) (HMENU hMenu,int nPos) = GetSubMenu;
HMENU fake_GetSubMenu(HMENU hMenu,int nPos){
	HMENU ret = pGetSubMenu(hMenu,nPos);
	OutputDebugStringA("GetSubMenu");
	return ret;
}

UINT (WINAPI *pGetMenuItemID) (HMENU hMenu,int nPos) = GetMenuItemID;
UINT fake_GetMenuItemID(HMENU hMenu,int nPos){
	UINT ret = pGetMenuItemID(hMenu,nPos);
	OutputDebugStringA("GetMenuItemID");
	return ret;
}

int (WINAPI *pGetMenuItemCount) (HMENU hMenu) = GetMenuItemCount;
int fake_GetMenuItemCount(HMENU hMenu){
	int ret = pGetMenuItemCount(hMenu);
	OutputDebugStringA("GetMenuItemCount");
	return ret;
}

BOOL (WINAPI *pInsertMenuA) (HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCSTR lpNewItem) = InsertMenuA;
BOOL fake_InsertMenuA(HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCSTR lpNewItem){
	BOOL ret = pInsertMenuA(hMenu,uPosition,uFlags,uIDNewItem,lpNewItem);
	OutputDebugStringA("InsertMenuA");
	return ret;
}

BOOL (WINAPI *pInsertMenuW) (HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCWSTR lpNewItem) = InsertMenuW;
BOOL fake_InsertMenuW(HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCWSTR lpNewItem){
	BOOL ret = pInsertMenuW(hMenu,uPosition,uFlags,uIDNewItem,lpNewItem);
	OutputDebugStringA("InsertMenuW");
	return ret;
}

BOOL (WINAPI *pAppendMenuA) (HMENU hMenu,UINT uFlags,UINT_PTR uIDNewItem,LPCSTR lpNewItem) = AppendMenuA;
BOOL fake_AppendMenuA(HMENU hMenu,UINT uFlags,UINT_PTR uIDNewItem,LPCSTR lpNewItem){
	BOOL ret = pAppendMenuA(hMenu,uFlags,uIDNewItem,lpNewItem);
	OutputDebugStringA("AppendMenuA");
	return ret;
}

BOOL (WINAPI *pAppendMenuW) (HMENU hMenu,UINT uFlags,UINT_PTR uIDNewItem,LPCWSTR lpNewItem) = AppendMenuW;
BOOL fake_AppendMenuW(HMENU hMenu,UINT uFlags,UINT_PTR uIDNewItem,LPCWSTR lpNewItem){
	BOOL ret = pAppendMenuW(hMenu,uFlags,uIDNewItem,lpNewItem);
	OutputDebugStringA("AppendMenuW");
	return ret;
}

BOOL (WINAPI *pModifyMenuA) (HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCSTR lpNewItem) = ModifyMenuA;
BOOL fake_ModifyMenuA(HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCSTR lpNewItem){
	BOOL ret = pModifyMenuA(hMnu,uPosition,uFlags,uIDNewItem,lpNewItem);
	OutputDebugStringA("ModifyMenuA");
	return ret;
}

BOOL (WINAPI *pModifyMenuW) (HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCWSTR lpNewItem) = ModifyMenuW;
BOOL fake_ModifyMenuW(HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCWSTR lpNewItem){
	BOOL ret = pModifyMenuW(hMnu,uPosition,uFlags,uIDNewItem,lpNewItem);
	OutputDebugStringA("ModifyMenuW");
	return ret;
}

BOOL (WINAPI *pRemoveMenu) (HMENU hMenu,UINT uPosition,UINT uFlags) = RemoveMenu;
BOOL fake_RemoveMenu(HMENU hMenu,UINT uPosition,UINT uFlags){
	BOOL ret = pRemoveMenu(hMenu,uPosition,uFlags);
	OutputDebugStringA("RemoveMenu");
	return ret;
}

BOOL (WINAPI *pDeleteMenu) (HMENU hMenu,UINT uPosition,UINT uFlags) = DeleteMenu;
BOOL fake_DeleteMenu(HMENU hMenu,UINT uPosition,UINT uFlags){
	BOOL ret = pDeleteMenu(hMenu,uPosition,uFlags);
	OutputDebugStringA("DeleteMenu");
	return ret;
}

BOOL (WINAPI *pSetMenuItemBitmaps) (HMENU hMenu,UINT uPosition,UINT uFlags,HBITMAP hBitmapUnchecked,HBITMAP hBitmapChecked) = SetMenuItemBitmaps;
BOOL fake_SetMenuItemBitmaps(HMENU hMenu,UINT uPosition,UINT uFlags,HBITMAP hBitmapUnchecked,HBITMAP hBitmapChecked){
	BOOL ret = pSetMenuItemBitmaps(hMenu,uPosition,uFlags,hBitmapUnchecked,hBitmapChecked);
	OutputDebugStringA("SetMenuItemBitmaps");
	return ret;
}

LONG (WINAPI *pGetMenuCheckMarkDimensions) () = GetMenuCheckMarkDimensions;
LONG fake_GetMenuCheckMarkDimensions(){
	LONG ret = pGetMenuCheckMarkDimensions();
	OutputDebugStringA("GetMenuCheckMarkDimensions");
	return ret;
}

BOOL (WINAPI *pTrackPopupMenu) (HMENU hMenu,UINT uFlags,int x,int y,int nReserved,HWND hWnd,CONST RECT* prcRect) = TrackPopupMenu;
BOOL fake_TrackPopupMenu(HMENU hMenu,UINT uFlags,int x,int y,int nReserved,HWND hWnd,CONST RECT* prcRect){
	BOOL ret = pTrackPopupMenu(hMenu,uFlags,x,y,nReserved,hWnd,prcRect);
	OutputDebugStringA("TrackPopupMenu");
	return ret;
}

BOOL (WINAPI *pTrackPopupMenuEx) (HMENU arg0,UINT arg1,int arg2,int arg3,HWND arg4,LPTPMPARAMS arg5) = TrackPopupMenuEx;
BOOL fake_TrackPopupMenuEx(HMENU arg0,UINT arg1,int arg2,int arg3,HWND arg4,LPTPMPARAMS arg5){
	BOOL ret = pTrackPopupMenuEx(arg0,arg1,arg2,arg3,arg4,arg5);
	OutputDebugStringA("TrackPopupMenuEx");
	return ret;
}

BOOL (WINAPI *pCalculatePopupWindowPosition) (CONST POINT* anchorPoint,CONST SIZE* windowSize,UINT flags,RECT* excludeRect,RECT* popupWindowPosition) = CalculatePopupWindowPosition;
BOOL fake_CalculatePopupWindowPosition(CONST POINT* anchorPoint,CONST SIZE* windowSize,UINT flags,RECT* excludeRect,RECT* popupWindowPosition){
	BOOL ret = pCalculatePopupWindowPosition(anchorPoint,windowSize,flags,excludeRect,popupWindowPosition);
	OutputDebugStringA("CalculatePopupWindowPosition");
	return ret;
}

BOOL (WINAPI *pGetMenuInfo) (HMENU arg0,LPMENUINFO arg1) = GetMenuInfo;
BOOL fake_GetMenuInfo(HMENU arg0,LPMENUINFO arg1){
	BOOL ret = pGetMenuInfo(arg0,arg1);
	OutputDebugStringA("GetMenuInfo");
	return ret;
}

BOOL (WINAPI *pSetMenuInfo) (HMENU arg0,LPCMENUINFO arg1) = SetMenuInfo;
BOOL fake_SetMenuInfo(HMENU arg0,LPCMENUINFO arg1){
	BOOL ret = pSetMenuInfo(arg0,arg1);
	OutputDebugStringA("SetMenuInfo");
	return ret;
}

BOOL (WINAPI *pEndMenu) () = EndMenu;
BOOL fake_EndMenu(){
	BOOL ret = pEndMenu();
	OutputDebugStringA("EndMenu");
	return ret;
}

BOOL (WINAPI *pInsertMenuItemA) (HMENU hmenu,UINT item,BOOL fByPosition,LPCMENUITEMINFOA lpmi) = InsertMenuItemA;
BOOL fake_InsertMenuItemA(HMENU hmenu,UINT item,BOOL fByPosition,LPCMENUITEMINFOA lpmi){
	BOOL ret = pInsertMenuItemA(hmenu,item,fByPosition,lpmi);
	OutputDebugStringA("InsertMenuItemA");
	return ret;
}

BOOL (WINAPI *pInsertMenuItemW) (HMENU hmenu,UINT item,BOOL fByPosition,LPCMENUITEMINFOW lpmi) = InsertMenuItemW;
BOOL fake_InsertMenuItemW(HMENU hmenu,UINT item,BOOL fByPosition,LPCMENUITEMINFOW lpmi){
	BOOL ret = pInsertMenuItemW(hmenu,item,fByPosition,lpmi);
	OutputDebugStringA("InsertMenuItemW");
	return ret;
}

BOOL (WINAPI *pGetMenuItemInfoA) (HMENU hmenu,UINT item,BOOL fByPosition,LPMENUITEMINFOA lpmii) = GetMenuItemInfoA;
BOOL fake_GetMenuItemInfoA(HMENU hmenu,UINT item,BOOL fByPosition,LPMENUITEMINFOA lpmii){
	BOOL ret = pGetMenuItemInfoA(hmenu,item,fByPosition,lpmii);
	OutputDebugStringA("GetMenuItemInfoA");
	return ret;
}

BOOL (WINAPI *pGetMenuItemInfoW) (HMENU hmenu,UINT item,BOOL fByPosition,LPMENUITEMINFOW lpmii) = GetMenuItemInfoW;
BOOL fake_GetMenuItemInfoW(HMENU hmenu,UINT item,BOOL fByPosition,LPMENUITEMINFOW lpmii){
	BOOL ret = pGetMenuItemInfoW(hmenu,item,fByPosition,lpmii);
	OutputDebugStringA("GetMenuItemInfoW");
	return ret;
}

BOOL (WINAPI *pSetMenuItemInfoA) (HMENU hmenu,UINT item,BOOL fByPositon,LPCMENUITEMINFOA lpmii) = SetMenuItemInfoA;
BOOL fake_SetMenuItemInfoA(HMENU hmenu,UINT item,BOOL fByPositon,LPCMENUITEMINFOA lpmii){
	BOOL ret = pSetMenuItemInfoA(hmenu,item,fByPositon,lpmii);
	OutputDebugStringA("SetMenuItemInfoA");
	return ret;
}

BOOL (WINAPI *pSetMenuItemInfoW) (HMENU hmenu,UINT item,BOOL fByPositon,LPCMENUITEMINFOW lpmii) = SetMenuItemInfoW;
BOOL fake_SetMenuItemInfoW(HMENU hmenu,UINT item,BOOL fByPositon,LPCMENUITEMINFOW lpmii){
	BOOL ret = pSetMenuItemInfoW(hmenu,item,fByPositon,lpmii);
	OutputDebugStringA("SetMenuItemInfoW");
	return ret;
}

UINT (WINAPI *pGetMenuDefaultItem) (HMENU hMenu,UINT fByPos,UINT gmdiFlags) = GetMenuDefaultItem;
UINT fake_GetMenuDefaultItem(HMENU hMenu,UINT fByPos,UINT gmdiFlags){
	UINT ret = pGetMenuDefaultItem(hMenu,fByPos,gmdiFlags);
	OutputDebugStringA("GetMenuDefaultItem");
	return ret;
}

BOOL (WINAPI *pSetMenuDefaultItem) (HMENU hMenu,UINT uItem,UINT fByPos) = SetMenuDefaultItem;
BOOL fake_SetMenuDefaultItem(HMENU hMenu,UINT uItem,UINT fByPos){
	BOOL ret = pSetMenuDefaultItem(hMenu,uItem,fByPos);
	OutputDebugStringA("SetMenuDefaultItem");
	return ret;
}

BOOL (WINAPI *pGetMenuItemRect) (HWND hWnd,HMENU hMenu,UINT uItem,LPRECT lprcItem) = GetMenuItemRect;
BOOL fake_GetMenuItemRect(HWND hWnd,HMENU hMenu,UINT uItem,LPRECT lprcItem){
	BOOL ret = pGetMenuItemRect(hWnd,hMenu,uItem,lprcItem);
	OutputDebugStringA("GetMenuItemRect");
	return ret;
}

int (WINAPI *pMenuItemFromPoint) (HWND hWnd,HMENU hMenu,POINT ptScreen) = MenuItemFromPoint;
int fake_MenuItemFromPoint(HWND hWnd,HMENU hMenu,POINT ptScreen){
	int ret = pMenuItemFromPoint(hWnd,hMenu,ptScreen);
	OutputDebugStringA("MenuItemFromPoint");
	return ret;
}

DWORD (WINAPI *pDragObject) (HWND hwndParent,HWND hwndFrom,UINT fmt,ULONG_PTR data,HCURSOR hcur) = DragObject;
DWORD fake_DragObject(HWND hwndParent,HWND hwndFrom,UINT fmt,ULONG_PTR data,HCURSOR hcur){
	DWORD ret = pDragObject(hwndParent,hwndFrom,fmt,data,hcur);
	OutputDebugStringA("DragObject");
	return ret;
}

BOOL (WINAPI *pDragDetect) (HWND hwnd,POINT pt) = DragDetect;
BOOL fake_DragDetect(HWND hwnd,POINT pt){
	BOOL ret = pDragDetect(hwnd,pt);
	OutputDebugStringA("DragDetect");
	return ret;
}

BOOL (WINAPI *pDrawIcon) (HDC hDC,int X,int Y,HICON hIcon) = DrawIcon;
BOOL fake_DrawIcon(HDC hDC,int X,int Y,HICON hIcon){
	BOOL ret = pDrawIcon(hDC,X,Y,hIcon);
	OutputDebugStringA("DrawIcon");
	return ret;
}

int (WINAPI *pDrawTextA) (HDC hdc,LPCSTR lpchText,int cchText,LPRECT lprc,UINT format) = DrawTextA;
int fake_DrawTextA(HDC hdc,LPCSTR lpchText,int cchText,LPRECT lprc,UINT format){
	int ret = pDrawTextA(hdc,lpchText,cchText,lprc,format);
	OutputDebugStringA("DrawTextA");
	return ret;
}

int (WINAPI *pDrawTextW) (HDC hdc,LPCWSTR lpchText,int cchText,LPRECT lprc,UINT format) = DrawTextW;
int fake_DrawTextW(HDC hdc,LPCWSTR lpchText,int cchText,LPRECT lprc,UINT format){
	int ret = pDrawTextW(hdc,lpchText,cchText,lprc,format);
	OutputDebugStringA("DrawTextW");
	return ret;
}

int (WINAPI *pDrawTextExA) (HDC hdc,LPSTR lpchText,int cchText,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp) = DrawTextExA;
int fake_DrawTextExA(HDC hdc,LPSTR lpchText,int cchText,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp){
	int ret = pDrawTextExA(hdc,lpchText,cchText,lprc,format,lpdtp);
	OutputDebugStringA("DrawTextExA");
	return ret;
}

int (WINAPI *pDrawTextExW) (HDC hdc,LPWSTR lpchText,int cchText,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp) = DrawTextExW;
int fake_DrawTextExW(HDC hdc,LPWSTR lpchText,int cchText,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp){
	int ret = pDrawTextExW(hdc,lpchText,cchText,lprc,format,lpdtp);
	OutputDebugStringA("DrawTextExW");
	return ret;
}

BOOL (WINAPI *pGrayStringA) (HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lpData,int nCount,int X,int Y,int nWidth,int nHeight) = GrayStringA;
BOOL fake_GrayStringA(HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lpData,int nCount,int X,int Y,int nWidth,int nHeight){
	BOOL ret = pGrayStringA(hDC,hBrush,lpOutputFunc,lpData,nCount,X,Y,nWidth,nHeight);
	OutputDebugStringA("GrayStringA");
	return ret;
}

BOOL (WINAPI *pGrayStringW) (HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lpData,int nCount,int X,int Y,int nWidth,int nHeight) = GrayStringW;
BOOL fake_GrayStringW(HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lpData,int nCount,int X,int Y,int nWidth,int nHeight){
	BOOL ret = pGrayStringW(hDC,hBrush,lpOutputFunc,lpData,nCount,X,Y,nWidth,nHeight);
	OutputDebugStringA("GrayStringW");
	return ret;
}

BOOL (WINAPI *pDrawStateA) (HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfnCallBack,LPARAM lData,WPARAM wData,int x,int y,int cx,int cy,UINT uFlags) = DrawStateA;
BOOL fake_DrawStateA(HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfnCallBack,LPARAM lData,WPARAM wData,int x,int y,int cx,int cy,UINT uFlags){
	BOOL ret = pDrawStateA(hdc,hbrFore,qfnCallBack,lData,wData,x,y,cx,cy,uFlags);
	OutputDebugStringA("DrawStateA");
	return ret;
}

BOOL (WINAPI *pDrawStateW) (HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfnCallBack,LPARAM lData,WPARAM wData,int x,int y,int cx,int cy,UINT uFlags) = DrawStateW;
BOOL fake_DrawStateW(HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfnCallBack,LPARAM lData,WPARAM wData,int x,int y,int cx,int cy,UINT uFlags){
	BOOL ret = pDrawStateW(hdc,hbrFore,qfnCallBack,lData,wData,x,y,cx,cy,uFlags);
	OutputDebugStringA("DrawStateW");
	return ret;
}

LONG (WINAPI *pTabbedTextOutA) (HDC hdc,int x,int y,LPCSTR lpString,int chCount,int nTabPositions,CONST INT* lpnTabStopPositions,int nTabOrigin) = TabbedTextOutA;
LONG fake_TabbedTextOutA(HDC hdc,int x,int y,LPCSTR lpString,int chCount,int nTabPositions,CONST INT* lpnTabStopPositions,int nTabOrigin){
	LONG ret = pTabbedTextOutA(hdc,x,y,lpString,chCount,nTabPositions,lpnTabStopPositions,nTabOrigin);
	OutputDebugStringA("TabbedTextOutA");
	return ret;
}

LONG (WINAPI *pTabbedTextOutW) (HDC hdc,int x,int y,LPCWSTR lpString,int chCount,int nTabPositions,CONST INT* lpnTabStopPositions,int nTabOrigin) = TabbedTextOutW;
LONG fake_TabbedTextOutW(HDC hdc,int x,int y,LPCWSTR lpString,int chCount,int nTabPositions,CONST INT* lpnTabStopPositions,int nTabOrigin){
	LONG ret = pTabbedTextOutW(hdc,x,y,lpString,chCount,nTabPositions,lpnTabStopPositions,nTabOrigin);
	OutputDebugStringA("TabbedTextOutW");
	return ret;
}

DWORD (WINAPI *pGetTabbedTextExtentA) (HDC hdc,LPCSTR lpString,int chCount,int nTabPositions,CONST INT* lpnTabStopPositions) = GetTabbedTextExtentA;
DWORD fake_GetTabbedTextExtentA(HDC hdc,LPCSTR lpString,int chCount,int nTabPositions,CONST INT* lpnTabStopPositions){
	DWORD ret = pGetTabbedTextExtentA(hdc,lpString,chCount,nTabPositions,lpnTabStopPositions);
	OutputDebugStringA("GetTabbedTextExtentA");
	return ret;
}

DWORD (WINAPI *pGetTabbedTextExtentW) (HDC hdc,LPCWSTR lpString,int chCount,int nTabPositions,CONST INT* lpnTabStopPositions) = GetTabbedTextExtentW;
DWORD fake_GetTabbedTextExtentW(HDC hdc,LPCWSTR lpString,int chCount,int nTabPositions,CONST INT* lpnTabStopPositions){
	DWORD ret = pGetTabbedTextExtentW(hdc,lpString,chCount,nTabPositions,lpnTabStopPositions);
	OutputDebugStringA("GetTabbedTextExtentW");
	return ret;
}

BOOL (WINAPI *pUpdateWindow) (HWND hWnd) = UpdateWindow;
BOOL fake_UpdateWindow(HWND hWnd){
	BOOL ret = pUpdateWindow(hWnd);
	OutputDebugStringA("UpdateWindow");
	return ret;
}

HWND (WINAPI *pSetActiveWindow) (HWND hWnd) = SetActiveWindow;
HWND fake_SetActiveWindow(HWND hWnd){
	HWND ret = pSetActiveWindow(hWnd);
	OutputDebugStringA("SetActiveWindow");
	return ret;
}

HWND (WINAPI *pGetForegroundWindow) () = GetForegroundWindow;
HWND fake_GetForegroundWindow(){
	HWND ret = pGetForegroundWindow();
	OutputDebugStringA("GetForegroundWindow");
	return ret;
}

BOOL (WINAPI *pPaintDesktop) (HDC hdc) = PaintDesktop;
BOOL fake_PaintDesktop(HDC hdc){
	BOOL ret = pPaintDesktop(hdc);
	OutputDebugStringA("PaintDesktop");
	return ret;
}

VOID (WINAPI *pSwitchToThisWindow) (HWND hwnd,BOOL fUnknown) = SwitchToThisWindow;
VOID fake_SwitchToThisWindow(HWND hwnd,BOOL fUnknown){
	pSwitchToThisWindow(hwnd,fUnknown);
	OutputDebugStringA("SwitchToThisWindow");
}

BOOL (WINAPI *pSetForegroundWindow) (HWND hWnd) = SetForegroundWindow;
BOOL fake_SetForegroundWindow(HWND hWnd){
	BOOL ret = pSetForegroundWindow(hWnd);
	OutputDebugStringA("SetForegroundWindow");
	return ret;
}

BOOL (WINAPI *pAllowSetForegroundWindow) (DWORD dwProcessId) = AllowSetForegroundWindow;
BOOL fake_AllowSetForegroundWindow(DWORD dwProcessId){
	BOOL ret = pAllowSetForegroundWindow(dwProcessId);
	OutputDebugStringA("AllowSetForegroundWindow");
	return ret;
}

BOOL (WINAPI *pLockSetForegroundWindow) (UINT uLockCode) = LockSetForegroundWindow;
BOOL fake_LockSetForegroundWindow(UINT uLockCode){
	BOOL ret = pLockSetForegroundWindow(uLockCode);
	OutputDebugStringA("LockSetForegroundWindow");
	return ret;
}

HWND (WINAPI *pWindowFromDC) (HDC hDC) = WindowFromDC;
HWND fake_WindowFromDC(HDC hDC){
	HWND ret = pWindowFromDC(hDC);
	OutputDebugStringA("WindowFromDC");
	return ret;
}

HDC (WINAPI *pGetDC) (HWND hWnd) = GetDC;
HDC fake_GetDC(HWND hWnd){
	HDC ret = pGetDC(hWnd);
	OutputDebugStringA("GetDC");
	return ret;
}

HDC (WINAPI *pGetDCEx) (HWND hWnd,HRGN hrgnClip,DWORD flags) = GetDCEx;
HDC fake_GetDCEx(HWND hWnd,HRGN hrgnClip,DWORD flags){
	HDC ret = pGetDCEx(hWnd,hrgnClip,flags);
	OutputDebugStringA("GetDCEx");
	return ret;
}

HDC (WINAPI *pGetWindowDC) (HWND hWnd) = GetWindowDC;
HDC fake_GetWindowDC(HWND hWnd){
	HDC ret = pGetWindowDC(hWnd);
	OutputDebugStringA("GetWindowDC");
	return ret;
}

int (WINAPI *pReleaseDC) (HWND hWnd,HDC hDC) = ReleaseDC;
int fake_ReleaseDC(HWND hWnd,HDC hDC){
	int ret = pReleaseDC(hWnd,hDC);
	OutputDebugStringA("ReleaseDC");
	return ret;
}

HDC (WINAPI *pBeginPaint) (HWND hWnd,LPPAINTSTRUCT lpPaint) = BeginPaint;
HDC fake_BeginPaint(HWND hWnd,LPPAINTSTRUCT lpPaint){
	HDC ret = pBeginPaint(hWnd,lpPaint);
	OutputDebugStringA("BeginPaint");
	return ret;
}

BOOL (WINAPI *pEndPaint) (HWND hWnd,CONST PAINTSTRUCT* lpPaint) = EndPaint;
BOOL fake_EndPaint(HWND hWnd,CONST PAINTSTRUCT* lpPaint){
	BOOL ret = pEndPaint(hWnd,lpPaint);
	OutputDebugStringA("EndPaint");
	return ret;
}

BOOL (WINAPI *pGetUpdateRect) (HWND hWnd,LPRECT lpRect,BOOL bErase) = GetUpdateRect;
BOOL fake_GetUpdateRect(HWND hWnd,LPRECT lpRect,BOOL bErase){
	BOOL ret = pGetUpdateRect(hWnd,lpRect,bErase);
	OutputDebugStringA("GetUpdateRect");
	return ret;
}

int (WINAPI *pGetUpdateRgn) (HWND hWnd,HRGN hRgn,BOOL bErase) = GetUpdateRgn;
int fake_GetUpdateRgn(HWND hWnd,HRGN hRgn,BOOL bErase){
	int ret = pGetUpdateRgn(hWnd,hRgn,bErase);
	OutputDebugStringA("GetUpdateRgn");
	return ret;
}

int (WINAPI *pSetWindowRgn) (HWND hWnd,HRGN hRgn,BOOL bRedraw) = SetWindowRgn;
int fake_SetWindowRgn(HWND hWnd,HRGN hRgn,BOOL bRedraw){
	int ret = pSetWindowRgn(hWnd,hRgn,bRedraw);
	OutputDebugStringA("SetWindowRgn");
	return ret;
}

int (WINAPI *pGetWindowRgn) (HWND hWnd,HRGN hRgn) = GetWindowRgn;
int fake_GetWindowRgn(HWND hWnd,HRGN hRgn){
	int ret = pGetWindowRgn(hWnd,hRgn);
	OutputDebugStringA("GetWindowRgn");
	return ret;
}

int (WINAPI *pGetWindowRgnBox) (HWND hWnd,LPRECT lprc) = GetWindowRgnBox;
int fake_GetWindowRgnBox(HWND hWnd,LPRECT lprc){
	int ret = pGetWindowRgnBox(hWnd,lprc);
	OutputDebugStringA("GetWindowRgnBox");
	return ret;
}

int (WINAPI *pExcludeUpdateRgn) (HDC hDC,HWND hWnd) = ExcludeUpdateRgn;
int fake_ExcludeUpdateRgn(HDC hDC,HWND hWnd){
	int ret = pExcludeUpdateRgn(hDC,hWnd);
	OutputDebugStringA("ExcludeUpdateRgn");
	return ret;
}

BOOL (WINAPI *pInvalidateRect) (HWND hWnd,CONST RECT* lpRect,BOOL bErase) = InvalidateRect;
BOOL fake_InvalidateRect(HWND hWnd,CONST RECT* lpRect,BOOL bErase){
	BOOL ret = pInvalidateRect(hWnd,lpRect,bErase);
	OutputDebugStringA("InvalidateRect");
	return ret;
}

BOOL (WINAPI *pValidateRect) (HWND hWnd,CONST RECT* lpRect) = ValidateRect;
BOOL fake_ValidateRect(HWND hWnd,CONST RECT* lpRect){
	BOOL ret = pValidateRect(hWnd,lpRect);
	OutputDebugStringA("ValidateRect");
	return ret;
}

BOOL (WINAPI *pInvalidateRgn) (HWND hWnd,HRGN hRgn,BOOL bErase) = InvalidateRgn;
BOOL fake_InvalidateRgn(HWND hWnd,HRGN hRgn,BOOL bErase){
	BOOL ret = pInvalidateRgn(hWnd,hRgn,bErase);
	OutputDebugStringA("InvalidateRgn");
	return ret;
}

BOOL (WINAPI *pValidateRgn) (HWND hWnd,HRGN hRgn) = ValidateRgn;
BOOL fake_ValidateRgn(HWND hWnd,HRGN hRgn){
	BOOL ret = pValidateRgn(hWnd,hRgn);
	OutputDebugStringA("ValidateRgn");
	return ret;
}

BOOL (WINAPI *pRedrawWindow) (HWND hWnd,CONST RECT* lprcUpdate,HRGN hrgnUpdate,UINT flags) = RedrawWindow;
BOOL fake_RedrawWindow(HWND hWnd,CONST RECT* lprcUpdate,HRGN hrgnUpdate,UINT flags){
	BOOL ret = pRedrawWindow(hWnd,lprcUpdate,hrgnUpdate,flags);
	OutputDebugStringA("RedrawWindow");
	return ret;
}

BOOL (WINAPI *pLockWindowUpdate) (HWND hWndLock) = LockWindowUpdate;
BOOL fake_LockWindowUpdate(HWND hWndLock){
	BOOL ret = pLockWindowUpdate(hWndLock);
	OutputDebugStringA("LockWindowUpdate");
	return ret;
}

BOOL (WINAPI *pScrollWindow) (HWND hWnd,int XAmount,int YAmount,CONST RECT* lpRect,CONST RECT* lpClipRect) = ScrollWindow;
BOOL fake_ScrollWindow(HWND hWnd,int XAmount,int YAmount,CONST RECT* lpRect,CONST RECT* lpClipRect){
	BOOL ret = pScrollWindow(hWnd,XAmount,YAmount,lpRect,lpClipRect);
	OutputDebugStringA("ScrollWindow");
	return ret;
}

BOOL (WINAPI *pScrollDC) (HDC hDC,int dx,int dy,CONST RECT* lprcScroll,CONST RECT* lprcClip,HRGN hrgnUpdate,LPRECT lprcUpdate) = ScrollDC;
BOOL fake_ScrollDC(HDC hDC,int dx,int dy,CONST RECT* lprcScroll,CONST RECT* lprcClip,HRGN hrgnUpdate,LPRECT lprcUpdate){
	BOOL ret = pScrollDC(hDC,dx,dy,lprcScroll,lprcClip,hrgnUpdate,lprcUpdate);
	OutputDebugStringA("ScrollDC");
	return ret;
}

int (WINAPI *pScrollWindowEx) (HWND hWnd,int dx,int dy,CONST RECT* prcScroll,CONST RECT* prcClip,HRGN hrgnUpdate,LPRECT prcUpdate,UINT flags) = ScrollWindowEx;
int fake_ScrollWindowEx(HWND hWnd,int dx,int dy,CONST RECT* prcScroll,CONST RECT* prcClip,HRGN hrgnUpdate,LPRECT prcUpdate,UINT flags){
	int ret = pScrollWindowEx(hWnd,dx,dy,prcScroll,prcClip,hrgnUpdate,prcUpdate,flags);
	OutputDebugStringA("ScrollWindowEx");
	return ret;
}

int (WINAPI *pSetScrollPos) (HWND hWnd,int nBar,int nPos,BOOL bRedraw) = SetScrollPos;
int fake_SetScrollPos(HWND hWnd,int nBar,int nPos,BOOL bRedraw){
	int ret = pSetScrollPos(hWnd,nBar,nPos,bRedraw);
	OutputDebugStringA("SetScrollPos");
	return ret;
}

int (WINAPI *pGetScrollPos) (HWND hWnd,int nBar) = GetScrollPos;
int fake_GetScrollPos(HWND hWnd,int nBar){
	int ret = pGetScrollPos(hWnd,nBar);
	OutputDebugStringA("GetScrollPos");
	return ret;
}

BOOL (WINAPI *pSetScrollRange) (HWND hWnd,int nBar,int nMinPos,int nMaxPos,BOOL bRedraw) = SetScrollRange;
BOOL fake_SetScrollRange(HWND hWnd,int nBar,int nMinPos,int nMaxPos,BOOL bRedraw){
	BOOL ret = pSetScrollRange(hWnd,nBar,nMinPos,nMaxPos,bRedraw);
	OutputDebugStringA("SetScrollRange");
	return ret;
}

BOOL (WINAPI *pGetScrollRange) (HWND hWnd,int nBar,LPINT lpMinPos,LPINT lpMaxPos) = GetScrollRange;
BOOL fake_GetScrollRange(HWND hWnd,int nBar,LPINT lpMinPos,LPINT lpMaxPos){
	BOOL ret = pGetScrollRange(hWnd,nBar,lpMinPos,lpMaxPos);
	OutputDebugStringA("GetScrollRange");
	return ret;
}

BOOL (WINAPI *pShowScrollBar) (HWND hWnd,int wBar,BOOL bShow) = ShowScrollBar;
BOOL fake_ShowScrollBar(HWND hWnd,int wBar,BOOL bShow){
	BOOL ret = pShowScrollBar(hWnd,wBar,bShow);
	OutputDebugStringA("ShowScrollBar");
	return ret;
}

BOOL (WINAPI *pEnableScrollBar) (HWND hWnd,UINT wSBflags,UINT wArrows) = EnableScrollBar;
BOOL fake_EnableScrollBar(HWND hWnd,UINT wSBflags,UINT wArrows){
	BOOL ret = pEnableScrollBar(hWnd,wSBflags,wArrows);
	OutputDebugStringA("EnableScrollBar");
	return ret;
}

BOOL (WINAPI *pSetPropA) (HWND hWnd,LPCSTR lpString,HANDLE hData) = SetPropA;
BOOL fake_SetPropA(HWND hWnd,LPCSTR lpString,HANDLE hData){
	BOOL ret = pSetPropA(hWnd,lpString,hData);
	OutputDebugStringA("SetPropA");
	return ret;
}

BOOL (WINAPI *pSetPropW) (HWND hWnd,LPCWSTR lpString,HANDLE hData) = SetPropW;
BOOL fake_SetPropW(HWND hWnd,LPCWSTR lpString,HANDLE hData){
	BOOL ret = pSetPropW(hWnd,lpString,hData);
	OutputDebugStringA("SetPropW");
	return ret;
}

HANDLE (WINAPI *pGetPropA) (HWND hWnd,LPCSTR lpString) = GetPropA;
HANDLE fake_GetPropA(HWND hWnd,LPCSTR lpString){
	HANDLE ret = pGetPropA(hWnd,lpString);
	OutputDebugStringA("GetPropA");
	return ret;
}

HANDLE (WINAPI *pGetPropW) (HWND hWnd,LPCWSTR lpString) = GetPropW;
HANDLE fake_GetPropW(HWND hWnd,LPCWSTR lpString){
	HANDLE ret = pGetPropW(hWnd,lpString);
	OutputDebugStringA("GetPropW");
	return ret;
}

HANDLE (WINAPI *pRemovePropA) (HWND hWnd,LPCSTR lpString) = RemovePropA;
HANDLE fake_RemovePropA(HWND hWnd,LPCSTR lpString){
	HANDLE ret = pRemovePropA(hWnd,lpString);
	OutputDebugStringA("RemovePropA");
	return ret;
}

HANDLE (WINAPI *pRemovePropW) (HWND hWnd,LPCWSTR lpString) = RemovePropW;
HANDLE fake_RemovePropW(HWND hWnd,LPCWSTR lpString){
	HANDLE ret = pRemovePropW(hWnd,lpString);
	OutputDebugStringA("RemovePropW");
	return ret;
}

int (WINAPI *pEnumPropsExA) (HWND hWnd,PROPENUMPROCEXA lpEnumFunc,LPARAM lParam) = EnumPropsExA;
int fake_EnumPropsExA(HWND hWnd,PROPENUMPROCEXA lpEnumFunc,LPARAM lParam){
	int ret = pEnumPropsExA(hWnd,lpEnumFunc,lParam);
	OutputDebugStringA("EnumPropsExA");
	return ret;
}

int (WINAPI *pEnumPropsExW) (HWND hWnd,PROPENUMPROCEXW lpEnumFunc,LPARAM lParam) = EnumPropsExW;
int fake_EnumPropsExW(HWND hWnd,PROPENUMPROCEXW lpEnumFunc,LPARAM lParam){
	int ret = pEnumPropsExW(hWnd,lpEnumFunc,lParam);
	OutputDebugStringA("EnumPropsExW");
	return ret;
}

int (WINAPI *pEnumPropsA) (HWND hWnd,PROPENUMPROCA lpEnumFunc) = EnumPropsA;
int fake_EnumPropsA(HWND hWnd,PROPENUMPROCA lpEnumFunc){
	int ret = pEnumPropsA(hWnd,lpEnumFunc);
	OutputDebugStringA("EnumPropsA");
	return ret;
}

int (WINAPI *pEnumPropsW) (HWND hWnd,PROPENUMPROCW lpEnumFunc) = EnumPropsW;
int fake_EnumPropsW(HWND hWnd,PROPENUMPROCW lpEnumFunc){
	int ret = pEnumPropsW(hWnd,lpEnumFunc);
	OutputDebugStringA("EnumPropsW");
	return ret;
}

BOOL (WINAPI *pSetWindowTextA) (HWND hWnd,LPCSTR lpString) = SetWindowTextA;
BOOL fake_SetWindowTextA(HWND hWnd,LPCSTR lpString){
	BOOL ret = pSetWindowTextA(hWnd,lpString);
	OutputDebugStringA("SetWindowTextA");
	return ret;
}

BOOL (WINAPI *pSetWindowTextW) (HWND hWnd,LPCWSTR lpString) = SetWindowTextW;
BOOL fake_SetWindowTextW(HWND hWnd,LPCWSTR lpString){
	BOOL ret = pSetWindowTextW(hWnd,lpString);
	OutputDebugStringA("SetWindowTextW");
	return ret;
}

int (WINAPI *pGetWindowTextA) (HWND hWnd,LPSTR lpString,int nMaxCount) = GetWindowTextA;
int fake_GetWindowTextA(HWND hWnd,LPSTR lpString,int nMaxCount){
	int ret = pGetWindowTextA(hWnd,lpString,nMaxCount);
	OutputDebugStringA("GetWindowTextA");
	return ret;
}

int (WINAPI *pGetWindowTextW) (HWND hWnd,LPWSTR lpString,int nMaxCount) = GetWindowTextW;
int fake_GetWindowTextW(HWND hWnd,LPWSTR lpString,int nMaxCount){
	int ret = pGetWindowTextW(hWnd,lpString,nMaxCount);
	OutputDebugStringA("GetWindowTextW");
	return ret;
}

int (WINAPI *pGetWindowTextLengthA) (HWND hWnd) = GetWindowTextLengthA;
int fake_GetWindowTextLengthA(HWND hWnd){
	int ret = pGetWindowTextLengthA(hWnd);
	OutputDebugStringA("GetWindowTextLengthA");
	return ret;
}

int (WINAPI *pGetWindowTextLengthW) (HWND hWnd) = GetWindowTextLengthW;
int fake_GetWindowTextLengthW(HWND hWnd){
	int ret = pGetWindowTextLengthW(hWnd);
	OutputDebugStringA("GetWindowTextLengthW");
	return ret;
}

BOOL (WINAPI *pGetClientRect) (HWND hWnd,LPRECT lpRect) = GetClientRect;
BOOL fake_GetClientRect(HWND hWnd,LPRECT lpRect){
	BOOL ret = pGetClientRect(hWnd,lpRect);
	OutputDebugStringA("GetClientRect");
	return ret;
}

BOOL (WINAPI *pGetWindowRect) (HWND hWnd,LPRECT lpRect) = GetWindowRect;
BOOL fake_GetWindowRect(HWND hWnd,LPRECT lpRect){
	BOOL ret = pGetWindowRect(hWnd,lpRect);
	OutputDebugStringA("GetWindowRect");
	return ret;
}

BOOL (WINAPI *pAdjustWindowRect) (LPRECT lpRect,DWORD dwStyle,BOOL bMenu) = AdjustWindowRect;
BOOL fake_AdjustWindowRect(LPRECT lpRect,DWORD dwStyle,BOOL bMenu){
	BOOL ret = pAdjustWindowRect(lpRect,dwStyle,bMenu);
	OutputDebugStringA("AdjustWindowRect");
	return ret;
}

BOOL (WINAPI *pAdjustWindowRectEx) (LPRECT lpRect,DWORD dwStyle,BOOL bMenu,DWORD dwExStyle) = AdjustWindowRectEx;
BOOL fake_AdjustWindowRectEx(LPRECT lpRect,DWORD dwStyle,BOOL bMenu,DWORD dwExStyle){
	BOOL ret = pAdjustWindowRectEx(lpRect,dwStyle,bMenu,dwExStyle);
	OutputDebugStringA("AdjustWindowRectEx");
	return ret;
}

BOOL (WINAPI *pSetWindowContextHelpId) (HWND arg0,DWORD arg1) = SetWindowContextHelpId;
BOOL fake_SetWindowContextHelpId(HWND arg0,DWORD arg1){
	BOOL ret = pSetWindowContextHelpId(arg0,arg1);
	OutputDebugStringA("SetWindowContextHelpId");
	return ret;
}

DWORD (WINAPI *pGetWindowContextHelpId) (HWND arg0) = GetWindowContextHelpId;
DWORD fake_GetWindowContextHelpId(HWND arg0){
	DWORD ret = pGetWindowContextHelpId(arg0);
	OutputDebugStringA("GetWindowContextHelpId");
	return ret;
}

BOOL (WINAPI *pSetMenuContextHelpId) (HMENU arg0,DWORD arg1) = SetMenuContextHelpId;
BOOL fake_SetMenuContextHelpId(HMENU arg0,DWORD arg1){
	BOOL ret = pSetMenuContextHelpId(arg0,arg1);
	OutputDebugStringA("SetMenuContextHelpId");
	return ret;
}

DWORD (WINAPI *pGetMenuContextHelpId) (HMENU arg0) = GetMenuContextHelpId;
DWORD fake_GetMenuContextHelpId(HMENU arg0){
	DWORD ret = pGetMenuContextHelpId(arg0);
	OutputDebugStringA("GetMenuContextHelpId");
	return ret;
}

int (WINAPI *pMessageBoxA) (HWND hWnd,LPCSTR lpText,LPCSTR lpCaption,UINT uType) = MessageBoxA;
int fake_MessageBoxA(HWND hWnd,LPCSTR lpText,LPCSTR lpCaption,UINT uType){
	int ret = pMessageBoxA(hWnd,lpText,lpCaption,uType);
	OutputDebugStringA("MessageBoxA");
	return ret;
}

int (WINAPI *pMessageBoxW) (HWND hWnd,LPCWSTR lpText,LPCWSTR lpCaption,UINT uType) = MessageBoxW;
int fake_MessageBoxW(HWND hWnd,LPCWSTR lpText,LPCWSTR lpCaption,UINT uType){
	int ret = pMessageBoxW(hWnd,lpText,lpCaption,uType);
	OutputDebugStringA("MessageBoxW");
	return ret;
}

int (WINAPI *pMessageBoxExA) (HWND hWnd,LPCSTR lpText,LPCSTR lpCaption,UINT uType,WORD wLanguageId) = MessageBoxExA;
int fake_MessageBoxExA(HWND hWnd,LPCSTR lpText,LPCSTR lpCaption,UINT uType,WORD wLanguageId){
	int ret = pMessageBoxExA(hWnd,lpText,lpCaption,uType,wLanguageId);
	OutputDebugStringA("MessageBoxExA");
	return ret;
}

int (WINAPI *pMessageBoxExW) (HWND hWnd,LPCWSTR lpText,LPCWSTR lpCaption,UINT uType,WORD wLanguageId) = MessageBoxExW;
int fake_MessageBoxExW(HWND hWnd,LPCWSTR lpText,LPCWSTR lpCaption,UINT uType,WORD wLanguageId){
	int ret = pMessageBoxExW(hWnd,lpText,lpCaption,uType,wLanguageId);
	OutputDebugStringA("MessageBoxExW");
	return ret;
}

int (WINAPI *pMessageBoxIndirectA) (CONST MSGBOXPARAMSA*  lpmbp) = MessageBoxIndirectA;
int fake_MessageBoxIndirectA(CONST MSGBOXPARAMSA*  lpmbp){
	int ret = pMessageBoxIndirectA( lpmbp);
	OutputDebugStringA("MessageBoxIndirectA");
	return ret;
}

int (WINAPI *pMessageBoxIndirectW) (CONST MSGBOXPARAMSW*  lpmbp) = MessageBoxIndirectW;
int fake_MessageBoxIndirectW(CONST MSGBOXPARAMSW*  lpmbp){
	int ret = pMessageBoxIndirectW( lpmbp);
	OutputDebugStringA("MessageBoxIndirectW");
	return ret;
}

BOOL (WINAPI *pMessageBeep) (UINT uType) = MessageBeep;
BOOL fake_MessageBeep(UINT uType){
	BOOL ret = pMessageBeep(uType);
	OutputDebugStringA("MessageBeep");
	return ret;
}

int (WINAPI *pShowCursor) (BOOL bShow) = ShowCursor;
int fake_ShowCursor(BOOL bShow){
	int ret = pShowCursor(bShow);
	OutputDebugStringA("ShowCursor");
	return ret;
}

BOOL (WINAPI *pSetCursorPos) (int X,int Y) = SetCursorPos;
BOOL fake_SetCursorPos(int X,int Y){
	BOOL ret = pSetCursorPos(X,Y);
	OutputDebugStringA("SetCursorPos");
	return ret;
}

BOOL (WINAPI *pSetPhysicalCursorPos) (int X,int Y) = SetPhysicalCursorPos;
BOOL fake_SetPhysicalCursorPos(int X,int Y){
	BOOL ret = pSetPhysicalCursorPos(X,Y);
	OutputDebugStringA("SetPhysicalCursorPos");
	return ret;
}

HCURSOR (WINAPI *pSetCursor) (HCURSOR hCursor) = SetCursor;
HCURSOR fake_SetCursor(HCURSOR hCursor){
	HCURSOR ret = pSetCursor(hCursor);
	OutputDebugStringA("SetCursor");
	return ret;
}

BOOL (WINAPI *pGetCursorPos) (LPPOINT lpPoint) = GetCursorPos;
BOOL fake_GetCursorPos(LPPOINT lpPoint){
	BOOL ret = pGetCursorPos(lpPoint);
	OutputDebugStringA("GetCursorPos");
	return ret;
}

BOOL (WINAPI *pGetPhysicalCursorPos) (LPPOINT lpPoint) = GetPhysicalCursorPos;
BOOL fake_GetPhysicalCursorPos(LPPOINT lpPoint){
	BOOL ret = pGetPhysicalCursorPos(lpPoint);
	OutputDebugStringA("GetPhysicalCursorPos");
	return ret;
}

BOOL (WINAPI *pClipCursor) (CONST RECT* lpRect) = ClipCursor;
BOOL fake_ClipCursor(CONST RECT* lpRect){
	BOOL ret = pClipCursor(lpRect);
	OutputDebugStringA("ClipCursor");
	return ret;
}

BOOL (WINAPI *pGetClipCursor) (LPRECT lpRect) = GetClipCursor;
BOOL fake_GetClipCursor(LPRECT lpRect){
	BOOL ret = pGetClipCursor(lpRect);
	OutputDebugStringA("GetClipCursor");
	return ret;
}

HCURSOR (WINAPI *pGetCursor) () = GetCursor;
HCURSOR fake_GetCursor(){
	HCURSOR ret = pGetCursor();
	OutputDebugStringA("GetCursor");
	return ret;
}

BOOL (WINAPI *pCreateCaret) (HWND hWnd,HBITMAP hBitmap,int nWidth,int nHeight) = CreateCaret;
BOOL fake_CreateCaret(HWND hWnd,HBITMAP hBitmap,int nWidth,int nHeight){
	BOOL ret = pCreateCaret(hWnd,hBitmap,nWidth,nHeight);
	OutputDebugStringA("CreateCaret");
	return ret;
}

UINT (WINAPI *pGetCaretBlinkTime) () = GetCaretBlinkTime;
UINT fake_GetCaretBlinkTime(){
	UINT ret = pGetCaretBlinkTime();
	OutputDebugStringA("GetCaretBlinkTime");
	return ret;
}

BOOL (WINAPI *pSetCaretBlinkTime) (UINT uMSeconds) = SetCaretBlinkTime;
BOOL fake_SetCaretBlinkTime(UINT uMSeconds){
	BOOL ret = pSetCaretBlinkTime(uMSeconds);
	OutputDebugStringA("SetCaretBlinkTime");
	return ret;
}

BOOL (WINAPI *pDestroyCaret) () = DestroyCaret;
BOOL fake_DestroyCaret(){
	BOOL ret = pDestroyCaret();
	OutputDebugStringA("DestroyCaret");
	return ret;
}

BOOL (WINAPI *pHideCaret) (HWND hWnd) = HideCaret;
BOOL fake_HideCaret(HWND hWnd){
	BOOL ret = pHideCaret(hWnd);
	OutputDebugStringA("HideCaret");
	return ret;
}

BOOL (WINAPI *pShowCaret) (HWND hWnd) = ShowCaret;
BOOL fake_ShowCaret(HWND hWnd){
	BOOL ret = pShowCaret(hWnd);
	OutputDebugStringA("ShowCaret");
	return ret;
}

BOOL (WINAPI *pSetCaretPos) (int X,int Y) = SetCaretPos;
BOOL fake_SetCaretPos(int X,int Y){
	BOOL ret = pSetCaretPos(X,Y);
	OutputDebugStringA("SetCaretPos");
	return ret;
}

BOOL (WINAPI *pGetCaretPos) (LPPOINT lpPoint) = GetCaretPos;
BOOL fake_GetCaretPos(LPPOINT lpPoint){
	BOOL ret = pGetCaretPos(lpPoint);
	OutputDebugStringA("GetCaretPos");
	return ret;
}

BOOL (WINAPI *pClientToScreen) (HWND hWnd,LPPOINT lpPoint) = ClientToScreen;
BOOL fake_ClientToScreen(HWND hWnd,LPPOINT lpPoint){
	BOOL ret = pClientToScreen(hWnd,lpPoint);
	OutputDebugStringA("ClientToScreen");
	return ret;
}

BOOL (WINAPI *pScreenToClient) (HWND hWnd,LPPOINT lpPoint) = ScreenToClient;
BOOL fake_ScreenToClient(HWND hWnd,LPPOINT lpPoint){
	BOOL ret = pScreenToClient(hWnd,lpPoint);
	OutputDebugStringA("ScreenToClient");
	return ret;
}

BOOL (WINAPI *pLogicalToPhysicalPoint) (HWND hWnd,LPPOINT lpPoint) = LogicalToPhysicalPoint;
BOOL fake_LogicalToPhysicalPoint(HWND hWnd,LPPOINT lpPoint){
	BOOL ret = pLogicalToPhysicalPoint(hWnd,lpPoint);
	OutputDebugStringA("LogicalToPhysicalPoint");
	return ret;
}

BOOL (WINAPI *pPhysicalToLogicalPoint) (HWND hWnd,LPPOINT lpPoint) = PhysicalToLogicalPoint;
BOOL fake_PhysicalToLogicalPoint(HWND hWnd,LPPOINT lpPoint){
	BOOL ret = pPhysicalToLogicalPoint(hWnd,lpPoint);
	OutputDebugStringA("PhysicalToLogicalPoint");
	return ret;
}

int (WINAPI *pMapWindowPoints) (HWND hWndFrom,HWND hWndTo,LPPOINT lpPoints,UINT cPoints) = MapWindowPoints;
int fake_MapWindowPoints(HWND hWndFrom,HWND hWndTo,LPPOINT lpPoints,UINT cPoints){
	int ret = pMapWindowPoints(hWndFrom,hWndTo,lpPoints,cPoints);
	OutputDebugStringA("MapWindowPoints");
	return ret;
}

HWND (WINAPI *pWindowFromPoint) (POINT Point) = WindowFromPoint;
HWND fake_WindowFromPoint(POINT Point){
	HWND ret = pWindowFromPoint(Point);
	OutputDebugStringA("WindowFromPoint");
	return ret;
}

HWND (WINAPI *pWindowFromPhysicalPoint) (POINT Point) = WindowFromPhysicalPoint;
HWND fake_WindowFromPhysicalPoint(POINT Point){
	HWND ret = pWindowFromPhysicalPoint(Point);
	OutputDebugStringA("WindowFromPhysicalPoint");
	return ret;
}

HWND (WINAPI *pChildWindowFromPoint) (HWND hWndParent,POINT Point) = ChildWindowFromPoint;
HWND fake_ChildWindowFromPoint(HWND hWndParent,POINT Point){
	HWND ret = pChildWindowFromPoint(hWndParent,Point);
	OutputDebugStringA("ChildWindowFromPoint");
	return ret;
}

HWND (WINAPI *pChildWindowFromPointEx) (HWND hwnd,POINT pt,UINT flags) = ChildWindowFromPointEx;
HWND fake_ChildWindowFromPointEx(HWND hwnd,POINT pt,UINT flags){
	HWND ret = pChildWindowFromPointEx(hwnd,pt,flags);
	OutputDebugStringA("ChildWindowFromPointEx");
	return ret;
}

DWORD (WINAPI *pGetSysColor) (int nIndex) = GetSysColor;
DWORD fake_GetSysColor(int nIndex){
	DWORD ret = pGetSysColor(nIndex);
	OutputDebugStringA("GetSysColor");
	return ret;
}

HBRUSH (WINAPI *pGetSysColorBrush) (int nIndex) = GetSysColorBrush;
HBRUSH fake_GetSysColorBrush(int nIndex){
	HBRUSH ret = pGetSysColorBrush(nIndex);
	OutputDebugStringA("GetSysColorBrush");
	return ret;
}

BOOL (WINAPI *pSetSysColors) (int cElements,CONST INT*  lpaElements,CONST COLORREF*  lpaRgbValues) = SetSysColors;
BOOL fake_SetSysColors(int cElements,CONST INT*  lpaElements,CONST COLORREF*  lpaRgbValues){
	BOOL ret = pSetSysColors(cElements, lpaElements, lpaRgbValues);
	OutputDebugStringA("SetSysColors");
	return ret;
}

BOOL (WINAPI *pDrawFocusRect) (HDC hDC,CONST RECT*  lprc) = DrawFocusRect;
BOOL fake_DrawFocusRect(HDC hDC,CONST RECT*  lprc){
	BOOL ret = pDrawFocusRect(hDC, lprc);
	OutputDebugStringA("DrawFocusRect");
	return ret;
}

int (WINAPI *pFillRect) (HDC hDC,CONST RECT* lprc,HBRUSH hbr) = FillRect;
int fake_FillRect(HDC hDC,CONST RECT* lprc,HBRUSH hbr){
	int ret = pFillRect(hDC,lprc,hbr);
	OutputDebugStringA("FillRect");
	return ret;
}

int (WINAPI *pFrameRect) (HDC hDC,CONST RECT* lprc,HBRUSH hbr) = FrameRect;
int fake_FrameRect(HDC hDC,CONST RECT* lprc,HBRUSH hbr){
	int ret = pFrameRect(hDC,lprc,hbr);
	OutputDebugStringA("FrameRect");
	return ret;
}

BOOL (WINAPI *pInvertRect) (HDC hDC,CONST RECT* lprc) = InvertRect;
BOOL fake_InvertRect(HDC hDC,CONST RECT* lprc){
	BOOL ret = pInvertRect(hDC,lprc);
	OutputDebugStringA("InvertRect");
	return ret;
}

BOOL (WINAPI *pSetRect) (LPRECT lprc,int xLeft,int yTop,int xRight,int yBottom) = SetRect;
BOOL fake_SetRect(LPRECT lprc,int xLeft,int yTop,int xRight,int yBottom){
	BOOL ret = pSetRect(lprc,xLeft,yTop,xRight,yBottom);
	OutputDebugStringA("SetRect");
	return ret;
}

BOOL (WINAPI *pSetRectEmpty) (LPRECT lprc) = SetRectEmpty;
BOOL fake_SetRectEmpty(LPRECT lprc){
	BOOL ret = pSetRectEmpty(lprc);
	OutputDebugStringA("SetRectEmpty");
	return ret;
}

BOOL (WINAPI *pCopyRect) (LPRECT lprcDst,CONST RECT* lprcSrc) = CopyRect;
BOOL fake_CopyRect(LPRECT lprcDst,CONST RECT* lprcSrc){
	BOOL ret = pCopyRect(lprcDst,lprcSrc);
	OutputDebugStringA("CopyRect");
	return ret;
}

BOOL (WINAPI *pInflateRect) (LPRECT lprc,int dx,int dy) = InflateRect;
BOOL fake_InflateRect(LPRECT lprc,int dx,int dy){
	BOOL ret = pInflateRect(lprc,dx,dy);
	OutputDebugStringA("InflateRect");
	return ret;
}

BOOL (WINAPI *pIntersectRect) (LPRECT lprcDst,CONST RECT* lprcSrc1,CONST RECT* lprcSrc2) = IntersectRect;
BOOL fake_IntersectRect(LPRECT lprcDst,CONST RECT* lprcSrc1,CONST RECT* lprcSrc2){
	BOOL ret = pIntersectRect(lprcDst,lprcSrc1,lprcSrc2);
	OutputDebugStringA("IntersectRect");
	return ret;
}

BOOL (WINAPI *pUnionRect) (LPRECT lprcDst,CONST RECT* lprcSrc1,CONST RECT* lprcSrc2) = UnionRect;
BOOL fake_UnionRect(LPRECT lprcDst,CONST RECT* lprcSrc1,CONST RECT* lprcSrc2){
	BOOL ret = pUnionRect(lprcDst,lprcSrc1,lprcSrc2);
	OutputDebugStringA("UnionRect");
	return ret;
}

BOOL (WINAPI *pSubtractRect) (LPRECT lprcDst,CONST RECT* lprcSrc1,CONST RECT* lprcSrc2) = SubtractRect;
BOOL fake_SubtractRect(LPRECT lprcDst,CONST RECT* lprcSrc1,CONST RECT* lprcSrc2){
	BOOL ret = pSubtractRect(lprcDst,lprcSrc1,lprcSrc2);
	OutputDebugStringA("SubtractRect");
	return ret;
}

BOOL (WINAPI *pOffsetRect) (LPRECT lprc,int dx,int dy) = OffsetRect;
BOOL fake_OffsetRect(LPRECT lprc,int dx,int dy){
	BOOL ret = pOffsetRect(lprc,dx,dy);
	OutputDebugStringA("OffsetRect");
	return ret;
}

BOOL (WINAPI *pIsRectEmpty) (CONST RECT* lprc) = IsRectEmpty;
BOOL fake_IsRectEmpty(CONST RECT* lprc){
	BOOL ret = pIsRectEmpty(lprc);
	OutputDebugStringA("IsRectEmpty");
	return ret;
}

BOOL (WINAPI *pEqualRect) (CONST RECT* lprc1,CONST RECT* lprc2) = EqualRect;
BOOL fake_EqualRect(CONST RECT* lprc1,CONST RECT* lprc2){
	BOOL ret = pEqualRect(lprc1,lprc2);
	OutputDebugStringA("EqualRect");
	return ret;
}

BOOL (WINAPI *pPtInRect) (CONST RECT* lprc,POINT pt) = PtInRect;
BOOL fake_PtInRect(CONST RECT* lprc,POINT pt){
	BOOL ret = pPtInRect(lprc,pt);
	OutputDebugStringA("PtInRect");
	return ret;
}

WORD (WINAPI *pGetWindowWord) (HWND hWnd,int nIndex) = GetWindowWord;
WORD fake_GetWindowWord(HWND hWnd,int nIndex){
	WORD ret = pGetWindowWord(hWnd,nIndex);
	OutputDebugStringA("GetWindowWord");
	return ret;
}

WORD (WINAPI *pSetWindowWord) (HWND hWnd,int nIndex,WORD wNewWord) = SetWindowWord;
WORD fake_SetWindowWord(HWND hWnd,int nIndex,WORD wNewWord){
	WORD ret = pSetWindowWord(hWnd,nIndex,wNewWord);
	OutputDebugStringA("SetWindowWord");
	return ret;
}

LONG (WINAPI *pGetWindowLongA) (HWND hWnd,int nIndex) = GetWindowLongA;
LONG fake_GetWindowLongA(HWND hWnd,int nIndex){
	LONG ret = pGetWindowLongA(hWnd,nIndex);
	OutputDebugStringA("GetWindowLongA");
	return ret;
}

LONG (WINAPI *pGetWindowLongW) (HWND hWnd,int nIndex) = GetWindowLongW;
LONG fake_GetWindowLongW(HWND hWnd,int nIndex){
	LONG ret = pGetWindowLongW(hWnd,nIndex);
	OutputDebugStringA("GetWindowLongW");
	return ret;
}

LONG (WINAPI *pSetWindowLongA) (HWND hWnd,int nIndex,LONG dwNewLong) = SetWindowLongA;
LONG fake_SetWindowLongA(HWND hWnd,int nIndex,LONG dwNewLong){
	LONG ret = pSetWindowLongA(hWnd,nIndex,dwNewLong);
	OutputDebugStringA("SetWindowLongA");
	return ret;
}

LONG (WINAPI *pSetWindowLongW) (HWND hWnd,int nIndex,LONG dwNewLong) = SetWindowLongW;
LONG fake_SetWindowLongW(HWND hWnd,int nIndex,LONG dwNewLong){
	LONG ret = pSetWindowLongW(hWnd,nIndex,dwNewLong);
	OutputDebugStringA("SetWindowLongW");
	return ret;
}

LONG_PTR (WINAPI *pGetWindowLongPtrA) (HWND hWnd,int nIndex) = GetWindowLongPtrA;
LONG_PTR fake_GetWindowLongPtrA(HWND hWnd,int nIndex){
	LONG_PTR ret = pGetWindowLongPtrA(hWnd,nIndex);
	OutputDebugStringA("GetWindowLongPtrA");
	return ret;
}

LONG_PTR (WINAPI *pGetWindowLongPtrW) (HWND hWnd,int nIndex) = GetWindowLongPtrW;
LONG_PTR fake_GetWindowLongPtrW(HWND hWnd,int nIndex){
	LONG_PTR ret = pGetWindowLongPtrW(hWnd,nIndex);
	OutputDebugStringA("GetWindowLongPtrW");
	return ret;
}

LONG_PTR (WINAPI *pSetWindowLongPtrA) (HWND hWnd,int nIndex,LONG_PTR dwNewLong) = SetWindowLongPtrA;
LONG_PTR fake_SetWindowLongPtrA(HWND hWnd,int nIndex,LONG_PTR dwNewLong){
	LONG_PTR ret = pSetWindowLongPtrA(hWnd,nIndex,dwNewLong);
	OutputDebugStringA("SetWindowLongPtrA");
	return ret;
}

LONG_PTR (WINAPI *pSetWindowLongPtrW) (HWND hWnd,int nIndex,LONG_PTR dwNewLong) = SetWindowLongPtrW;
LONG_PTR fake_SetWindowLongPtrW(HWND hWnd,int nIndex,LONG_PTR dwNewLong){
	LONG_PTR ret = pSetWindowLongPtrW(hWnd,nIndex,dwNewLong);
	OutputDebugStringA("SetWindowLongPtrW");
	return ret;
}

WORD (WINAPI *pGetClassWord) (HWND hWnd,int nIndex) = GetClassWord;
WORD fake_GetClassWord(HWND hWnd,int nIndex){
	WORD ret = pGetClassWord(hWnd,nIndex);
	OutputDebugStringA("GetClassWord");
	return ret;
}

WORD (WINAPI *pSetClassWord) (HWND hWnd,int nIndex,WORD wNewWord) = SetClassWord;
WORD fake_SetClassWord(HWND hWnd,int nIndex,WORD wNewWord){
	WORD ret = pSetClassWord(hWnd,nIndex,wNewWord);
	OutputDebugStringA("SetClassWord");
	return ret;
}

DWORD (WINAPI *pGetClassLongA) (HWND hWnd,int nIndex) = GetClassLongA;
DWORD fake_GetClassLongA(HWND hWnd,int nIndex){
	DWORD ret = pGetClassLongA(hWnd,nIndex);
	OutputDebugStringA("GetClassLongA");
	return ret;
}

DWORD (WINAPI *pGetClassLongW) (HWND hWnd,int nIndex) = GetClassLongW;
DWORD fake_GetClassLongW(HWND hWnd,int nIndex){
	DWORD ret = pGetClassLongW(hWnd,nIndex);
	OutputDebugStringA("GetClassLongW");
	return ret;
}

DWORD (WINAPI *pSetClassLongA) (HWND hWnd,int nIndex,LONG dwNewLong) = SetClassLongA;
DWORD fake_SetClassLongA(HWND hWnd,int nIndex,LONG dwNewLong){
	DWORD ret = pSetClassLongA(hWnd,nIndex,dwNewLong);
	OutputDebugStringA("SetClassLongA");
	return ret;
}

DWORD (WINAPI *pSetClassLongW) (HWND hWnd,int nIndex,LONG dwNewLong) = SetClassLongW;
DWORD fake_SetClassLongW(HWND hWnd,int nIndex,LONG dwNewLong){
	DWORD ret = pSetClassLongW(hWnd,nIndex,dwNewLong);
	OutputDebugStringA("SetClassLongW");
	return ret;
}

ULONG_PTR (WINAPI *pGetClassLongPtrA) (HWND hWnd,int nIndex) = GetClassLongPtrA;
ULONG_PTR fake_GetClassLongPtrA(HWND hWnd,int nIndex){
	ULONG_PTR ret = pGetClassLongPtrA(hWnd,nIndex);
	OutputDebugStringA("GetClassLongPtrA");
	return ret;
}

ULONG_PTR (WINAPI *pGetClassLongPtrW) (HWND hWnd,int nIndex) = GetClassLongPtrW;
ULONG_PTR fake_GetClassLongPtrW(HWND hWnd,int nIndex){
	ULONG_PTR ret = pGetClassLongPtrW(hWnd,nIndex);
	OutputDebugStringA("GetClassLongPtrW");
	return ret;
}

ULONG_PTR (WINAPI *pSetClassLongPtrA) (HWND hWnd,int nIndex,LONG_PTR dwNewLong) = SetClassLongPtrA;
ULONG_PTR fake_SetClassLongPtrA(HWND hWnd,int nIndex,LONG_PTR dwNewLong){
	ULONG_PTR ret = pSetClassLongPtrA(hWnd,nIndex,dwNewLong);
	OutputDebugStringA("SetClassLongPtrA");
	return ret;
}

ULONG_PTR (WINAPI *pSetClassLongPtrW) (HWND hWnd,int nIndex,LONG_PTR dwNewLong) = SetClassLongPtrW;
ULONG_PTR fake_SetClassLongPtrW(HWND hWnd,int nIndex,LONG_PTR dwNewLong){
	ULONG_PTR ret = pSetClassLongPtrW(hWnd,nIndex,dwNewLong);
	OutputDebugStringA("SetClassLongPtrW");
	return ret;
}

BOOL (WINAPI *pGetProcessDefaultLayout) (DWORD* pdwDefaultLayout) = GetProcessDefaultLayout;
BOOL fake_GetProcessDefaultLayout(DWORD* pdwDefaultLayout){
	BOOL ret = pGetProcessDefaultLayout(pdwDefaultLayout);
	OutputDebugStringA("GetProcessDefaultLayout");
	return ret;
}

BOOL (WINAPI *pSetProcessDefaultLayout) (DWORD dwDefaultLayout) = SetProcessDefaultLayout;
BOOL fake_SetProcessDefaultLayout(DWORD dwDefaultLayout){
	BOOL ret = pSetProcessDefaultLayout(dwDefaultLayout);
	OutputDebugStringA("SetProcessDefaultLayout");
	return ret;
}

HWND (WINAPI *pGetDesktopWindow) () = GetDesktopWindow;
HWND fake_GetDesktopWindow(){
	HWND ret = pGetDesktopWindow();
	OutputDebugStringA("GetDesktopWindow");
	return ret;
}

HWND (WINAPI *pGetParent) (HWND hWnd) = GetParent;
HWND fake_GetParent(HWND hWnd){
	HWND ret = pGetParent(hWnd);
	OutputDebugStringA("GetParent");
	return ret;
}

HWND (WINAPI *pSetParent) (HWND hWndChild,HWND hWndNewParent) = SetParent;
HWND fake_SetParent(HWND hWndChild,HWND hWndNewParent){
	HWND ret = pSetParent(hWndChild,hWndNewParent);
	OutputDebugStringA("SetParent");
	return ret;
}

BOOL (WINAPI *pEnumChildWindows) (HWND hWndParent,WNDENUMPROC lpEnumFunc,LPARAM lParam) = EnumChildWindows;
BOOL fake_EnumChildWindows(HWND hWndParent,WNDENUMPROC lpEnumFunc,LPARAM lParam){
	BOOL ret = pEnumChildWindows(hWndParent,lpEnumFunc,lParam);
	OutputDebugStringA("EnumChildWindows");
	return ret;
}

HWND (WINAPI *pFindWindowA) (LPCSTR lpClassName,LPCSTR lpWindowName) = FindWindowA;
HWND fake_FindWindowA(LPCSTR lpClassName,LPCSTR lpWindowName){
	HWND ret = pFindWindowA(lpClassName,lpWindowName);
	OutputDebugStringA("FindWindowA");
	return ret;
}

HWND (WINAPI *pFindWindowW) (LPCWSTR lpClassName,LPCWSTR lpWindowName) = FindWindowW;
HWND fake_FindWindowW(LPCWSTR lpClassName,LPCWSTR lpWindowName){
	HWND ret = pFindWindowW(lpClassName,lpWindowName);
	OutputDebugStringA("FindWindowW");
	return ret;
}

HWND (WINAPI *pFindWindowExA) (HWND hWndParent,HWND hWndChildAfter,LPCSTR lpszClass,LPCSTR lpszWindow) = FindWindowExA;
HWND fake_FindWindowExA(HWND hWndParent,HWND hWndChildAfter,LPCSTR lpszClass,LPCSTR lpszWindow){
	HWND ret = pFindWindowExA(hWndParent,hWndChildAfter,lpszClass,lpszWindow);
	OutputDebugStringA("FindWindowExA");
	return ret;
}

HWND (WINAPI *pFindWindowExW) (HWND hWndParent,HWND hWndChildAfter,LPCWSTR lpszClass,LPCWSTR lpszWindow) = FindWindowExW;
HWND fake_FindWindowExW(HWND hWndParent,HWND hWndChildAfter,LPCWSTR lpszClass,LPCWSTR lpszWindow){
	HWND ret = pFindWindowExW(hWndParent,hWndChildAfter,lpszClass,lpszWindow);
	OutputDebugStringA("FindWindowExW");
	return ret;
}

HWND (WINAPI *pGetShellWindow) () = GetShellWindow;
HWND fake_GetShellWindow(){
	HWND ret = pGetShellWindow();
	OutputDebugStringA("GetShellWindow");
	return ret;
}

BOOL (WINAPI *pRegisterShellHookWindow) (HWND hwnd) = RegisterShellHookWindow;
BOOL fake_RegisterShellHookWindow(HWND hwnd){
	BOOL ret = pRegisterShellHookWindow(hwnd);
	OutputDebugStringA("RegisterShellHookWindow");
	return ret;
}

BOOL (WINAPI *pDeregisterShellHookWindow) (HWND hwnd) = DeregisterShellHookWindow;
BOOL fake_DeregisterShellHookWindow(HWND hwnd){
	BOOL ret = pDeregisterShellHookWindow(hwnd);
	OutputDebugStringA("DeregisterShellHookWindow");
	return ret;
}

BOOL (WINAPI *pEnumWindows) (WNDENUMPROC lpEnumFunc,LPARAM lParam) = EnumWindows;
BOOL fake_EnumWindows(WNDENUMPROC lpEnumFunc,LPARAM lParam){
	BOOL ret = pEnumWindows(lpEnumFunc,lParam);
	OutputDebugStringA("EnumWindows");
	return ret;
}

BOOL (WINAPI *pEnumThreadWindows) (DWORD dwThreadId,WNDENUMPROC lpfn,LPARAM lParam) = EnumThreadWindows;
BOOL fake_EnumThreadWindows(DWORD dwThreadId,WNDENUMPROC lpfn,LPARAM lParam){
	BOOL ret = pEnumThreadWindows(dwThreadId,lpfn,lParam);
	OutputDebugStringA("EnumThreadWindows");
	return ret;
}

int (WINAPI *pGetClassNameA) (HWND hWnd,LPSTR lpClassName,int nMaxCount) = GetClassNameA;
int fake_GetClassNameA(HWND hWnd,LPSTR lpClassName,int nMaxCount){
	int ret = pGetClassNameA(hWnd,lpClassName,nMaxCount);
	OutputDebugStringA("GetClassNameA");
	return ret;
}

int (WINAPI *pGetClassNameW) (HWND hWnd,LPWSTR lpClassName,int nMaxCount) = GetClassNameW;
int fake_GetClassNameW(HWND hWnd,LPWSTR lpClassName,int nMaxCount){
	int ret = pGetClassNameW(hWnd,lpClassName,nMaxCount);
	OutputDebugStringA("GetClassNameW");
	return ret;
}

HWND (WINAPI *pGetTopWindow) (HWND hWnd) = GetTopWindow;
HWND fake_GetTopWindow(HWND hWnd){
	HWND ret = pGetTopWindow(hWnd);
	OutputDebugStringA("GetTopWindow");
	return ret;
}

DWORD (WINAPI *pGetWindowThreadProcessId) (HWND hWnd,LPDWORD lpdwProcessId) = GetWindowThreadProcessId;
DWORD fake_GetWindowThreadProcessId(HWND hWnd,LPDWORD lpdwProcessId){
	DWORD ret = pGetWindowThreadProcessId(hWnd,lpdwProcessId);
	OutputDebugStringA("GetWindowThreadProcessId");
	return ret;
}

BOOL (WINAPI *pIsGUIThread) (BOOL bConvert) = IsGUIThread;
BOOL fake_IsGUIThread(BOOL bConvert){
	BOOL ret = pIsGUIThread(bConvert);
	OutputDebugStringA("IsGUIThread");
	return ret;
}

HWND (WINAPI *pGetLastActivePopup) (HWND hWnd) = GetLastActivePopup;
HWND fake_GetLastActivePopup(HWND hWnd){
	HWND ret = pGetLastActivePopup(hWnd);
	OutputDebugStringA("GetLastActivePopup");
	return ret;
}

HWND (WINAPI *pGetWindow) (HWND hWnd,UINT uCmd) = GetWindow;
HWND fake_GetWindow(HWND hWnd,UINT uCmd){
	HWND ret = pGetWindow(hWnd,uCmd);
	OutputDebugStringA("GetWindow");
	return ret;
}

HHOOK (WINAPI *pSetWindowsHookA) (int nFilterType,HOOKPROC pfnFilterProc) = SetWindowsHookA;
HHOOK fake_SetWindowsHookA(int nFilterType,HOOKPROC pfnFilterProc){
	HHOOK ret = pSetWindowsHookA(nFilterType,pfnFilterProc);
	OutputDebugStringA("SetWindowsHookA");
	return ret;
}

HHOOK (WINAPI *pSetWindowsHookW) (int nFilterType,HOOKPROC pfnFilterProc) = SetWindowsHookW;
HHOOK fake_SetWindowsHookW(int nFilterType,HOOKPROC pfnFilterProc){
	HHOOK ret = pSetWindowsHookW(nFilterType,pfnFilterProc);
	OutputDebugStringA("SetWindowsHookW");
	return ret;
}

BOOL (WINAPI *pUnhookWindowsHook) (int nCode,HOOKPROC pfnFilterProc) = UnhookWindowsHook;
BOOL fake_UnhookWindowsHook(int nCode,HOOKPROC pfnFilterProc){
	BOOL ret = pUnhookWindowsHook(nCode,pfnFilterProc);
	OutputDebugStringA("UnhookWindowsHook");
	return ret;
}

HHOOK (WINAPI *pSetWindowsHookExA) (int idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId) = SetWindowsHookExA;
HHOOK fake_SetWindowsHookExA(int idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId){
	HHOOK ret = pSetWindowsHookExA(idHook,lpfn,hmod,dwThreadId);
	OutputDebugStringA("SetWindowsHookExA");
	return ret;
}

HHOOK (WINAPI *pSetWindowsHookExW) (int idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId) = SetWindowsHookExW;
HHOOK fake_SetWindowsHookExW(int idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId){
	HHOOK ret = pSetWindowsHookExW(idHook,lpfn,hmod,dwThreadId);
	OutputDebugStringA("SetWindowsHookExW");
	return ret;
}

BOOL (WINAPI *pUnhookWindowsHookEx) (HHOOK hhk) = UnhookWindowsHookEx;
BOOL fake_UnhookWindowsHookEx(HHOOK hhk){
	BOOL ret = pUnhookWindowsHookEx(hhk);
	OutputDebugStringA("UnhookWindowsHookEx");
	return ret;
}

LRESULT (WINAPI *pCallNextHookEx) (HHOOK hhk,int nCode,WPARAM wParam,LPARAM lParam) = CallNextHookEx;
LRESULT fake_CallNextHookEx(HHOOK hhk,int nCode,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pCallNextHookEx(hhk,nCode,wParam,lParam);
	OutputDebugStringA("CallNextHookEx");
	return ret;
}

BOOL (WINAPI *pCheckMenuRadioItem) (HMENU hmenu,UINT first,UINT last,UINT check,UINT flags) = CheckMenuRadioItem;
BOOL fake_CheckMenuRadioItem(HMENU hmenu,UINT first,UINT last,UINT check,UINT flags){
	BOOL ret = pCheckMenuRadioItem(hmenu,first,last,check,flags);
	OutputDebugStringA("CheckMenuRadioItem");
	return ret;
}

HBITMAP (WINAPI *pLoadBitmapA) (HINSTANCE hInstance,LPCSTR lpBitmapName) = LoadBitmapA;
HBITMAP fake_LoadBitmapA(HINSTANCE hInstance,LPCSTR lpBitmapName){
	HBITMAP ret = pLoadBitmapA(hInstance,lpBitmapName);
	OutputDebugStringA("LoadBitmapA");
	return ret;
}

HBITMAP (WINAPI *pLoadBitmapW) (HINSTANCE hInstance,LPCWSTR lpBitmapName) = LoadBitmapW;
HBITMAP fake_LoadBitmapW(HINSTANCE hInstance,LPCWSTR lpBitmapName){
	HBITMAP ret = pLoadBitmapW(hInstance,lpBitmapName);
	OutputDebugStringA("LoadBitmapW");
	return ret;
}

HCURSOR (WINAPI *pLoadCursorA) (HINSTANCE hInstance,LPCSTR lpCursorName) = LoadCursorA;
HCURSOR fake_LoadCursorA(HINSTANCE hInstance,LPCSTR lpCursorName){
	HCURSOR ret = pLoadCursorA(hInstance,lpCursorName);
	OutputDebugStringA("LoadCursorA");
	return ret;
}

HCURSOR (WINAPI *pLoadCursorW) (HINSTANCE hInstance,LPCWSTR lpCursorName) = LoadCursorW;
HCURSOR fake_LoadCursorW(HINSTANCE hInstance,LPCWSTR lpCursorName){
	HCURSOR ret = pLoadCursorW(hInstance,lpCursorName);
	OutputDebugStringA("LoadCursorW");
	return ret;
}

HCURSOR (WINAPI *pLoadCursorFromFileA) (LPCSTR lpFileName) = LoadCursorFromFileA;
HCURSOR fake_LoadCursorFromFileA(LPCSTR lpFileName){
	HCURSOR ret = pLoadCursorFromFileA(lpFileName);
	OutputDebugStringA("LoadCursorFromFileA");
	return ret;
}

HCURSOR (WINAPI *pLoadCursorFromFileW) (LPCWSTR lpFileName) = LoadCursorFromFileW;
HCURSOR fake_LoadCursorFromFileW(LPCWSTR lpFileName){
	HCURSOR ret = pLoadCursorFromFileW(lpFileName);
	OutputDebugStringA("LoadCursorFromFileW");
	return ret;
}

HCURSOR (WINAPI *pCreateCursor) (HINSTANCE hInst,int xHotSpot,int yHotSpot,int nWidth,int nHeight,CONST VOID* pvANDPlane,CONST VOID* pvXORPlane) = CreateCursor;
HCURSOR fake_CreateCursor(HINSTANCE hInst,int xHotSpot,int yHotSpot,int nWidth,int nHeight,CONST VOID* pvANDPlane,CONST VOID* pvXORPlane){
	HCURSOR ret = pCreateCursor(hInst,xHotSpot,yHotSpot,nWidth,nHeight,pvANDPlane,pvXORPlane);
	OutputDebugStringA("CreateCursor");
	return ret;
}

BOOL (WINAPI *pDestroyCursor) (HCURSOR hCursor) = DestroyCursor;
BOOL fake_DestroyCursor(HCURSOR hCursor){
	BOOL ret = pDestroyCursor(hCursor);
	OutputDebugStringA("DestroyCursor");
	return ret;
}

BOOL (WINAPI *pSetSystemCursor) (HCURSOR hcur,DWORD id) = SetSystemCursor;
BOOL fake_SetSystemCursor(HCURSOR hcur,DWORD id){
	BOOL ret = pSetSystemCursor(hcur,id);
	OutputDebugStringA("SetSystemCursor");
	return ret;
}

HICON (WINAPI *pLoadIconA) (HINSTANCE hInstance,LPCSTR lpIconName) = LoadIconA;
HICON fake_LoadIconA(HINSTANCE hInstance,LPCSTR lpIconName){
	HICON ret = pLoadIconA(hInstance,lpIconName);
	OutputDebugStringA("LoadIconA");
	return ret;
}

HICON (WINAPI *pLoadIconW) (HINSTANCE hInstance,LPCWSTR lpIconName) = LoadIconW;
HICON fake_LoadIconW(HINSTANCE hInstance,LPCWSTR lpIconName){
	HICON ret = pLoadIconW(hInstance,lpIconName);
	OutputDebugStringA("LoadIconW");
	return ret;
}

UINT (WINAPI *pPrivateExtractIconsA) (LPCSTR szFileName,int nIconIndex,int cxIcon,int cyIcon,HICON* phicon,UINT* piconid,UINT nIcons,UINT flags) = PrivateExtractIconsA;
UINT fake_PrivateExtractIconsA(LPCSTR szFileName,int nIconIndex,int cxIcon,int cyIcon,HICON* phicon,UINT* piconid,UINT nIcons,UINT flags){
	UINT ret = pPrivateExtractIconsA(szFileName,nIconIndex,cxIcon,cyIcon,phicon,piconid,nIcons,flags);
	OutputDebugStringA("PrivateExtractIconsA");
	return ret;
}

UINT (WINAPI *pPrivateExtractIconsW) (LPCWSTR szFileName,int nIconIndex,int cxIcon,int cyIcon,HICON* phicon,UINT* piconid,UINT nIcons,UINT flags) = PrivateExtractIconsW;
UINT fake_PrivateExtractIconsW(LPCWSTR szFileName,int nIconIndex,int cxIcon,int cyIcon,HICON* phicon,UINT* piconid,UINT nIcons,UINT flags){
	UINT ret = pPrivateExtractIconsW(szFileName,nIconIndex,cxIcon,cyIcon,phicon,piconid,nIcons,flags);
	OutputDebugStringA("PrivateExtractIconsW");
	return ret;
}

HICON (WINAPI *pCreateIcon) (HINSTANCE hInstance,int nWidth,int nHeight,BYTE cPlanes,BYTE cBitsPixel,CONST BYTE* lpbANDbits,CONST BYTE* lpbXORbits) = CreateIcon;
HICON fake_CreateIcon(HINSTANCE hInstance,int nWidth,int nHeight,BYTE cPlanes,BYTE cBitsPixel,CONST BYTE* lpbANDbits,CONST BYTE* lpbXORbits){
	HICON ret = pCreateIcon(hInstance,nWidth,nHeight,cPlanes,cBitsPixel,lpbANDbits,lpbXORbits);
	OutputDebugStringA("CreateIcon");
	return ret;
}

BOOL (WINAPI *pDestroyIcon) (HICON hIcon) = DestroyIcon;
BOOL fake_DestroyIcon(HICON hIcon){
	BOOL ret = pDestroyIcon(hIcon);
	OutputDebugStringA("DestroyIcon");
	return ret;
}

int (WINAPI *pLookupIconIdFromDirectory) (PBYTE presbits,BOOL fIcon) = LookupIconIdFromDirectory;
int fake_LookupIconIdFromDirectory(PBYTE presbits,BOOL fIcon){
	int ret = pLookupIconIdFromDirectory(presbits,fIcon);
	OutputDebugStringA("LookupIconIdFromDirectory");
	return ret;
}

int (WINAPI *pLookupIconIdFromDirectoryEx) (PBYTE presbits,BOOL fIcon,int cxDesired,int cyDesired,UINT Flags) = LookupIconIdFromDirectoryEx;
int fake_LookupIconIdFromDirectoryEx(PBYTE presbits,BOOL fIcon,int cxDesired,int cyDesired,UINT Flags){
	int ret = pLookupIconIdFromDirectoryEx(presbits,fIcon,cxDesired,cyDesired,Flags);
	OutputDebugStringA("LookupIconIdFromDirectoryEx");
	return ret;
}

HICON (WINAPI *pCreateIconFromResource) (PBYTE presbits,DWORD dwResSize,BOOL fIcon,DWORD dwVer) = CreateIconFromResource;
HICON fake_CreateIconFromResource(PBYTE presbits,DWORD dwResSize,BOOL fIcon,DWORD dwVer){
	HICON ret = pCreateIconFromResource(presbits,dwResSize,fIcon,dwVer);
	OutputDebugStringA("CreateIconFromResource");
	return ret;
}

HICON (WINAPI *pCreateIconFromResourceEx) (PBYTE presbits,DWORD dwResSize,BOOL fIcon,DWORD dwVer,int cxDesired,int cyDesired,UINT Flags) = CreateIconFromResourceEx;
HICON fake_CreateIconFromResourceEx(PBYTE presbits,DWORD dwResSize,BOOL fIcon,DWORD dwVer,int cxDesired,int cyDesired,UINT Flags){
	HICON ret = pCreateIconFromResourceEx(presbits,dwResSize,fIcon,dwVer,cxDesired,cyDesired,Flags);
	OutputDebugStringA("CreateIconFromResourceEx");
	return ret;
}

HANDLE (WINAPI *pLoadImageA) (HINSTANCE hInst,LPCSTR name,UINT type,int cx,int cy,UINT fuLoad) = LoadImageA;
HANDLE fake_LoadImageA(HINSTANCE hInst,LPCSTR name,UINT type,int cx,int cy,UINT fuLoad){
	HANDLE ret = pLoadImageA(hInst,name,type,cx,cy,fuLoad);
	OutputDebugStringA("LoadImageA");
	return ret;
}

HANDLE (WINAPI *pLoadImageW) (HINSTANCE hInst,LPCWSTR name,UINT type,int cx,int cy,UINT fuLoad) = LoadImageW;
HANDLE fake_LoadImageW(HINSTANCE hInst,LPCWSTR name,UINT type,int cx,int cy,UINT fuLoad){
	HANDLE ret = pLoadImageW(hInst,name,type,cx,cy,fuLoad);
	OutputDebugStringA("LoadImageW");
	return ret;
}

HANDLE (WINAPI *pCopyImage) (HANDLE h,UINT type,int cx,int cy,UINT flags) = CopyImage;
HANDLE fake_CopyImage(HANDLE h,UINT type,int cx,int cy,UINT flags){
	HANDLE ret = pCopyImage(h,type,cx,cy,flags);
	OutputDebugStringA("CopyImage");
	return ret;
}

HICON (WINAPI *pCreateIconIndirect) (PICONINFO piconinfo) = CreateIconIndirect;
HICON fake_CreateIconIndirect(PICONINFO piconinfo){
	HICON ret = pCreateIconIndirect(piconinfo);
	OutputDebugStringA("CreateIconIndirect");
	return ret;
}

HICON (WINAPI *pCopyIcon) (HICON hIcon) = CopyIcon;
HICON fake_CopyIcon(HICON hIcon){
	HICON ret = pCopyIcon(hIcon);
	OutputDebugStringA("CopyIcon");
	return ret;
}

BOOL (WINAPI *pGetIconInfo) (HICON hIcon,PICONINFO piconinfo) = GetIconInfo;
BOOL fake_GetIconInfo(HICON hIcon,PICONINFO piconinfo){
	BOOL ret = pGetIconInfo(hIcon,piconinfo);
	OutputDebugStringA("GetIconInfo");
	return ret;
}

BOOL (WINAPI *pGetIconInfoExA) (HICON hicon,PICONINFOEXA piconinfo) = GetIconInfoExA;
BOOL fake_GetIconInfoExA(HICON hicon,PICONINFOEXA piconinfo){
	BOOL ret = pGetIconInfoExA(hicon,piconinfo);
	OutputDebugStringA("GetIconInfoExA");
	return ret;
}

BOOL (WINAPI *pGetIconInfoExW) (HICON hicon,PICONINFOEXW piconinfo) = GetIconInfoExW;
BOOL fake_GetIconInfoExW(HICON hicon,PICONINFOEXW piconinfo){
	BOOL ret = pGetIconInfoExW(hicon,piconinfo);
	OutputDebugStringA("GetIconInfoExW");
	return ret;
}

int (WINAPI *pLoadStringA) (HINSTANCE hInstance,UINT uID,LPSTR lpBuffer,int cchBufferMax) = LoadStringA;
int fake_LoadStringA(HINSTANCE hInstance,UINT uID,LPSTR lpBuffer,int cchBufferMax){
	int ret = pLoadStringA(hInstance,uID,lpBuffer,cchBufferMax);
	OutputDebugStringA("LoadStringA");
	return ret;
}

int (WINAPI *pLoadStringW) (HINSTANCE hInstance,UINT uID,LPWSTR lpBuffer,int cchBufferMax) = LoadStringW;
int fake_LoadStringW(HINSTANCE hInstance,UINT uID,LPWSTR lpBuffer,int cchBufferMax){
	int ret = pLoadStringW(hInstance,uID,lpBuffer,cchBufferMax);
	OutputDebugStringA("LoadStringW");
	return ret;
}

BOOL (WINAPI *pIsDialogMessageA) (HWND hDlg,LPMSG lpMsg) = IsDialogMessageA;
BOOL fake_IsDialogMessageA(HWND hDlg,LPMSG lpMsg){
	BOOL ret = pIsDialogMessageA(hDlg,lpMsg);
	OutputDebugStringA("IsDialogMessageA");
	return ret;
}

BOOL (WINAPI *pIsDialogMessageW) (HWND hDlg,LPMSG lpMsg) = IsDialogMessageW;
BOOL fake_IsDialogMessageW(HWND hDlg,LPMSG lpMsg){
	BOOL ret = pIsDialogMessageW(hDlg,lpMsg);
	OutputDebugStringA("IsDialogMessageW");
	return ret;
}

BOOL (WINAPI *pMapDialogRect) (HWND hDlg,LPRECT lpRect) = MapDialogRect;
BOOL fake_MapDialogRect(HWND hDlg,LPRECT lpRect){
	BOOL ret = pMapDialogRect(hDlg,lpRect);
	OutputDebugStringA("MapDialogRect");
	return ret;
}

int (WINAPI *pDlgDirListA) (HWND hDlg,LPSTR lpPathSpec,int nIDListBox,int nIDStaticPath,UINT uFileType) = DlgDirListA;
int fake_DlgDirListA(HWND hDlg,LPSTR lpPathSpec,int nIDListBox,int nIDStaticPath,UINT uFileType){
	int ret = pDlgDirListA(hDlg,lpPathSpec,nIDListBox,nIDStaticPath,uFileType);
	OutputDebugStringA("DlgDirListA");
	return ret;
}

int (WINAPI *pDlgDirListW) (HWND hDlg,LPWSTR lpPathSpec,int nIDListBox,int nIDStaticPath,UINT uFileType) = DlgDirListW;
int fake_DlgDirListW(HWND hDlg,LPWSTR lpPathSpec,int nIDListBox,int nIDStaticPath,UINT uFileType){
	int ret = pDlgDirListW(hDlg,lpPathSpec,nIDListBox,nIDStaticPath,uFileType);
	OutputDebugStringA("DlgDirListW");
	return ret;
}

BOOL (WINAPI *pDlgDirSelectExA) (HWND hwndDlg,LPSTR lpString,int chCount,int idListBox) = DlgDirSelectExA;
BOOL fake_DlgDirSelectExA(HWND hwndDlg,LPSTR lpString,int chCount,int idListBox){
	BOOL ret = pDlgDirSelectExA(hwndDlg,lpString,chCount,idListBox);
	OutputDebugStringA("DlgDirSelectExA");
	return ret;
}

BOOL (WINAPI *pDlgDirSelectExW) (HWND hwndDlg,LPWSTR lpString,int chCount,int idListBox) = DlgDirSelectExW;
BOOL fake_DlgDirSelectExW(HWND hwndDlg,LPWSTR lpString,int chCount,int idListBox){
	BOOL ret = pDlgDirSelectExW(hwndDlg,lpString,chCount,idListBox);
	OutputDebugStringA("DlgDirSelectExW");
	return ret;
}

int (WINAPI *pDlgDirListComboBoxA) (HWND hDlg,LPSTR lpPathSpec,int nIDComboBox,int nIDStaticPath,UINT uFiletype) = DlgDirListComboBoxA;
int fake_DlgDirListComboBoxA(HWND hDlg,LPSTR lpPathSpec,int nIDComboBox,int nIDStaticPath,UINT uFiletype){
	int ret = pDlgDirListComboBoxA(hDlg,lpPathSpec,nIDComboBox,nIDStaticPath,uFiletype);
	OutputDebugStringA("DlgDirListComboBoxA");
	return ret;
}

int (WINAPI *pDlgDirListComboBoxW) (HWND hDlg,LPWSTR lpPathSpec,int nIDComboBox,int nIDStaticPath,UINT uFiletype) = DlgDirListComboBoxW;
int fake_DlgDirListComboBoxW(HWND hDlg,LPWSTR lpPathSpec,int nIDComboBox,int nIDStaticPath,UINT uFiletype){
	int ret = pDlgDirListComboBoxW(hDlg,lpPathSpec,nIDComboBox,nIDStaticPath,uFiletype);
	OutputDebugStringA("DlgDirListComboBoxW");
	return ret;
}

BOOL (WINAPI *pDlgDirSelectComboBoxExA) (HWND hwndDlg,LPSTR lpString,int cchOut,int idComboBox) = DlgDirSelectComboBoxExA;
BOOL fake_DlgDirSelectComboBoxExA(HWND hwndDlg,LPSTR lpString,int cchOut,int idComboBox){
	BOOL ret = pDlgDirSelectComboBoxExA(hwndDlg,lpString,cchOut,idComboBox);
	OutputDebugStringA("DlgDirSelectComboBoxExA");
	return ret;
}

BOOL (WINAPI *pDlgDirSelectComboBoxExW) (HWND hwndDlg,LPWSTR lpString,int cchOut,int idComboBox) = DlgDirSelectComboBoxExW;
BOOL fake_DlgDirSelectComboBoxExW(HWND hwndDlg,LPWSTR lpString,int cchOut,int idComboBox){
	BOOL ret = pDlgDirSelectComboBoxExW(hwndDlg,lpString,cchOut,idComboBox);
	OutputDebugStringA("DlgDirSelectComboBoxExW");
	return ret;
}

int (WINAPI *pSetScrollInfo) (HWND hwnd,int nBar,LPCSCROLLINFO lpsi,BOOL redraw) = SetScrollInfo;
int fake_SetScrollInfo(HWND hwnd,int nBar,LPCSCROLLINFO lpsi,BOOL redraw){
	int ret = pSetScrollInfo(hwnd,nBar,lpsi,redraw);
	OutputDebugStringA("SetScrollInfo");
	return ret;
}

BOOL (WINAPI *pGetScrollInfo) (HWND hwnd,int nBar,LPSCROLLINFO lpsi) = GetScrollInfo;
BOOL fake_GetScrollInfo(HWND hwnd,int nBar,LPSCROLLINFO lpsi){
	BOOL ret = pGetScrollInfo(hwnd,nBar,lpsi);
	OutputDebugStringA("GetScrollInfo");
	return ret;
}

LRESULT (WINAPI *pDefFrameProcA) (HWND hWnd,HWND hWndMDIClient,UINT uMsg,WPARAM wParam,LPARAM lParam) = DefFrameProcA;
LRESULT fake_DefFrameProcA(HWND hWnd,HWND hWndMDIClient,UINT uMsg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pDefFrameProcA(hWnd,hWndMDIClient,uMsg,wParam,lParam);
	OutputDebugStringA("DefFrameProcA");
	return ret;
}

LRESULT (WINAPI *pDefFrameProcW) (HWND hWnd,HWND hWndMDIClient,UINT uMsg,WPARAM wParam,LPARAM lParam) = DefFrameProcW;
LRESULT fake_DefFrameProcW(HWND hWnd,HWND hWndMDIClient,UINT uMsg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pDefFrameProcW(hWnd,hWndMDIClient,uMsg,wParam,lParam);
	OutputDebugStringA("DefFrameProcW");
	return ret;
}

LRESULT (WINAPI *pDefMDIChildProcA) (HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam) = DefMDIChildProcA;
LRESULT fake_DefMDIChildProcA(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pDefMDIChildProcA(hWnd,uMsg,wParam,lParam);
	OutputDebugStringA("DefMDIChildProcA");
	return ret;
}

LRESULT (WINAPI *pDefMDIChildProcW) (HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam) = DefMDIChildProcW;
LRESULT fake_DefMDIChildProcW(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam){
	LRESULT ret = pDefMDIChildProcW(hWnd,uMsg,wParam,lParam);
	OutputDebugStringA("DefMDIChildProcW");
	return ret;
}

BOOL (WINAPI *pTranslateMDISysAccel) (HWND hWndClient,LPMSG lpMsg) = TranslateMDISysAccel;
BOOL fake_TranslateMDISysAccel(HWND hWndClient,LPMSG lpMsg){
	BOOL ret = pTranslateMDISysAccel(hWndClient,lpMsg);
	OutputDebugStringA("TranslateMDISysAccel");
	return ret;
}

UINT (WINAPI *pArrangeIconicWindows) (HWND hWnd) = ArrangeIconicWindows;
UINT fake_ArrangeIconicWindows(HWND hWnd){
	UINT ret = pArrangeIconicWindows(hWnd);
	OutputDebugStringA("ArrangeIconicWindows");
	return ret;
}

HWND (WINAPI *pCreateMDIWindowA) (LPCSTR lpClassName,LPCSTR lpWindowName,DWORD dwStyle,int X,int Y,int nWidth,int nHeight,HWND hWndParent,HINSTANCE hInstance,LPARAM lParam) = CreateMDIWindowA;
HWND fake_CreateMDIWindowA(LPCSTR lpClassName,LPCSTR lpWindowName,DWORD dwStyle,int X,int Y,int nWidth,int nHeight,HWND hWndParent,HINSTANCE hInstance,LPARAM lParam){
	HWND ret = pCreateMDIWindowA(lpClassName,lpWindowName,dwStyle,X,Y,nWidth,nHeight,hWndParent,hInstance,lParam);
	OutputDebugStringA("CreateMDIWindowA");
	return ret;
}

HWND (WINAPI *pCreateMDIWindowW) (LPCWSTR lpClassName,LPCWSTR lpWindowName,DWORD dwStyle,int X,int Y,int nWidth,int nHeight,HWND hWndParent,HINSTANCE hInstance,LPARAM lParam) = CreateMDIWindowW;
HWND fake_CreateMDIWindowW(LPCWSTR lpClassName,LPCWSTR lpWindowName,DWORD dwStyle,int X,int Y,int nWidth,int nHeight,HWND hWndParent,HINSTANCE hInstance,LPARAM lParam){
	HWND ret = pCreateMDIWindowW(lpClassName,lpWindowName,dwStyle,X,Y,nWidth,nHeight,hWndParent,hInstance,lParam);
	OutputDebugStringA("CreateMDIWindowW");
	return ret;
}

WORD (WINAPI *pTileWindows) (HWND hwndParent,UINT wHow,CONST RECT*  lpRect,UINT cKids,CONST HWND*  lpKids) = TileWindows;
WORD fake_TileWindows(HWND hwndParent,UINT wHow,CONST RECT*  lpRect,UINT cKids,CONST HWND*  lpKids){
	WORD ret = pTileWindows(hwndParent,wHow, lpRect,cKids, lpKids);
	OutputDebugStringA("TileWindows");
	return ret;
}

WORD (WINAPI *pCascadeWindows) (HWND hwndParent,UINT wHow,CONST RECT*  lpRect,UINT cKids,CONST HWND*  lpKids) = CascadeWindows;
WORD fake_CascadeWindows(HWND hwndParent,UINT wHow,CONST RECT*  lpRect,UINT cKids,CONST HWND*  lpKids){
	WORD ret = pCascadeWindows(hwndParent,wHow, lpRect,cKids, lpKids);
	OutputDebugStringA("CascadeWindows");
	return ret;
}

BOOL (WINAPI *pWinHelpA) (HWND hWndMain,LPCSTR lpszHelp,UINT uCommand,ULONG_PTR dwData) = WinHelpA;
BOOL fake_WinHelpA(HWND hWndMain,LPCSTR lpszHelp,UINT uCommand,ULONG_PTR dwData){
	BOOL ret = pWinHelpA(hWndMain,lpszHelp,uCommand,dwData);
	OutputDebugStringA("WinHelpA");
	return ret;
}

BOOL (WINAPI *pWinHelpW) (HWND hWndMain,LPCWSTR lpszHelp,UINT uCommand,ULONG_PTR dwData) = WinHelpW;
BOOL fake_WinHelpW(HWND hWndMain,LPCWSTR lpszHelp,UINT uCommand,ULONG_PTR dwData){
	BOOL ret = pWinHelpW(hWndMain,lpszHelp,uCommand,dwData);
	OutputDebugStringA("WinHelpW");
	return ret;
}

DWORD (WINAPI *pGetGuiResources) (HANDLE hProcess,DWORD uiFlags) = GetGuiResources;
DWORD fake_GetGuiResources(HANDLE hProcess,DWORD uiFlags){
	DWORD ret = pGetGuiResources(hProcess,uiFlags);
	OutputDebugStringA("GetGuiResources");
	return ret;
}

LONG (WINAPI *pChangeDisplaySettingsA) (DEVMODEA*  lpDevMode,DWORD dwFlags) = ChangeDisplaySettingsA;
LONG fake_ChangeDisplaySettingsA(DEVMODEA*  lpDevMode,DWORD dwFlags){
	LONG ret = pChangeDisplaySettingsA( lpDevMode,dwFlags);
	OutputDebugStringA("ChangeDisplaySettingsA");
	return ret;
}

LONG (WINAPI *pChangeDisplaySettingsW) (DEVMODEW*  lpDevMode,DWORD dwFlags) = ChangeDisplaySettingsW;
LONG fake_ChangeDisplaySettingsW(DEVMODEW*  lpDevMode,DWORD dwFlags){
	LONG ret = pChangeDisplaySettingsW( lpDevMode,dwFlags);
	OutputDebugStringA("ChangeDisplaySettingsW");
	return ret;
}

LONG (WINAPI *pChangeDisplaySettingsExA) (LPCSTR lpszDeviceName,DEVMODEA*  lpDevMode,HWND hwnd,DWORD dwflags,LPVOID lParam) = ChangeDisplaySettingsExA;
LONG fake_ChangeDisplaySettingsExA(LPCSTR lpszDeviceName,DEVMODEA*  lpDevMode,HWND hwnd,DWORD dwflags,LPVOID lParam){
	LONG ret = pChangeDisplaySettingsExA(lpszDeviceName, lpDevMode,hwnd,dwflags,lParam);
	OutputDebugStringA("ChangeDisplaySettingsExA");
	return ret;
}

LONG (WINAPI *pChangeDisplaySettingsExW) (LPCWSTR lpszDeviceName,DEVMODEW*  lpDevMode,HWND hwnd,DWORD dwflags,LPVOID lParam) = ChangeDisplaySettingsExW;
LONG fake_ChangeDisplaySettingsExW(LPCWSTR lpszDeviceName,DEVMODEW*  lpDevMode,HWND hwnd,DWORD dwflags,LPVOID lParam){
	LONG ret = pChangeDisplaySettingsExW(lpszDeviceName, lpDevMode,hwnd,dwflags,lParam);
	OutputDebugStringA("ChangeDisplaySettingsExW");
	return ret;
}

BOOL (WINAPI *pEnumDisplaySettingsA) (LPCSTR lpszDeviceName,DWORD iModeNum,DEVMODEA*  lpDevMode) = EnumDisplaySettingsA;
BOOL fake_EnumDisplaySettingsA(LPCSTR lpszDeviceName,DWORD iModeNum,DEVMODEA*  lpDevMode){
	BOOL ret = pEnumDisplaySettingsA(lpszDeviceName,iModeNum, lpDevMode);
	OutputDebugStringA("EnumDisplaySettingsA");
	return ret;
}

BOOL (WINAPI *pEnumDisplaySettingsW) (LPCWSTR lpszDeviceName,DWORD iModeNum,DEVMODEW*  lpDevMode) = EnumDisplaySettingsW;
BOOL fake_EnumDisplaySettingsW(LPCWSTR lpszDeviceName,DWORD iModeNum,DEVMODEW*  lpDevMode){
	BOOL ret = pEnumDisplaySettingsW(lpszDeviceName,iModeNum, lpDevMode);
	OutputDebugStringA("EnumDisplaySettingsW");
	return ret;
}

BOOL (WINAPI *pEnumDisplaySettingsExA) (LPCSTR lpszDeviceName,DWORD iModeNum,DEVMODEA*  lpDevMode,DWORD dwFlags) = EnumDisplaySettingsExA;
BOOL fake_EnumDisplaySettingsExA(LPCSTR lpszDeviceName,DWORD iModeNum,DEVMODEA*  lpDevMode,DWORD dwFlags){
	BOOL ret = pEnumDisplaySettingsExA(lpszDeviceName,iModeNum, lpDevMode,dwFlags);
	OutputDebugStringA("EnumDisplaySettingsExA");
	return ret;
}

BOOL (WINAPI *pEnumDisplaySettingsExW) (LPCWSTR lpszDeviceName,DWORD iModeNum,DEVMODEW*  lpDevMode,DWORD dwFlags) = EnumDisplaySettingsExW;
BOOL fake_EnumDisplaySettingsExW(LPCWSTR lpszDeviceName,DWORD iModeNum,DEVMODEW*  lpDevMode,DWORD dwFlags){
	BOOL ret = pEnumDisplaySettingsExW(lpszDeviceName,iModeNum, lpDevMode,dwFlags);
	OutputDebugStringA("EnumDisplaySettingsExW");
	return ret;
}

BOOL (WINAPI *pEnumDisplayDevicesA) (LPCSTR lpDevice,DWORD iDevNum,PDISPLAY_DEVICEA lpDisplayDevice,DWORD dwFlags) = EnumDisplayDevicesA;
BOOL fake_EnumDisplayDevicesA(LPCSTR lpDevice,DWORD iDevNum,PDISPLAY_DEVICEA lpDisplayDevice,DWORD dwFlags){
	BOOL ret = pEnumDisplayDevicesA(lpDevice,iDevNum,lpDisplayDevice,dwFlags);
	OutputDebugStringA("EnumDisplayDevicesA");
	return ret;
}

BOOL (WINAPI *pEnumDisplayDevicesW) (LPCWSTR lpDevice,DWORD iDevNum,PDISPLAY_DEVICEW lpDisplayDevice,DWORD dwFlags) = EnumDisplayDevicesW;
BOOL fake_EnumDisplayDevicesW(LPCWSTR lpDevice,DWORD iDevNum,PDISPLAY_DEVICEW lpDisplayDevice,DWORD dwFlags){
	BOOL ret = pEnumDisplayDevicesW(lpDevice,iDevNum,lpDisplayDevice,dwFlags);
	OutputDebugStringA("EnumDisplayDevicesW");
	return ret;
}

LONG (WINAPI *pGetDisplayConfigBufferSizes) (UINT32 flags,UINT32*  numPathArrayElements,UINT32*  numModeInfoArrayElements) = GetDisplayConfigBufferSizes;
LONG fake_GetDisplayConfigBufferSizes(UINT32 flags,UINT32*  numPathArrayElements,UINT32*  numModeInfoArrayElements){
	LONG ret = pGetDisplayConfigBufferSizes(flags, numPathArrayElements, numModeInfoArrayElements);
	OutputDebugStringA("GetDisplayConfigBufferSizes");
	return ret;
}

LONG (WINAPI *pSetDisplayConfig) (UINT32 numPathArrayElements,DISPLAYCONFIG_PATH_INFO*  pathArray,UINT32 numModeInfoArrayElements,DISPLAYCONFIG_MODE_INFO*  modeInfoArray,UINT32 flags) = SetDisplayConfig;
LONG fake_SetDisplayConfig(UINT32 numPathArrayElements,DISPLAYCONFIG_PATH_INFO*  pathArray,UINT32 numModeInfoArrayElements,DISPLAYCONFIG_MODE_INFO*  modeInfoArray,UINT32 flags){
	LONG ret = pSetDisplayConfig(numPathArrayElements, pathArray,numModeInfoArrayElements, modeInfoArray,flags);
	OutputDebugStringA("SetDisplayConfig");
	return ret;
}

LONG (WINAPI *pQueryDisplayConfig) (UINT32 flags,UINT32*  numPathArrayElements,DISPLAYCONFIG_PATH_INFO*  pathArray,UINT32*  numModeInfoArrayElements,DISPLAYCONFIG_MODE_INFO*  modeInfoArray,DISPLAYCONFIG_TOPOLOGY_ID*  currentTopologyId) = QueryDisplayConfig;
LONG fake_QueryDisplayConfig(UINT32 flags,UINT32*  numPathArrayElements,DISPLAYCONFIG_PATH_INFO*  pathArray,UINT32*  numModeInfoArrayElements,DISPLAYCONFIG_MODE_INFO*  modeInfoArray,DISPLAYCONFIG_TOPOLOGY_ID*  currentTopologyId){
	LONG ret = pQueryDisplayConfig(flags, numPathArrayElements, pathArray, numModeInfoArrayElements, modeInfoArray, currentTopologyId);
	OutputDebugStringA("QueryDisplayConfig");
	return ret;
}

LONG (WINAPI *pDisplayConfigGetDeviceInfo) (DISPLAYCONFIG_DEVICE_INFO_HEADER*  requestPacket) = DisplayConfigGetDeviceInfo;
LONG fake_DisplayConfigGetDeviceInfo(DISPLAYCONFIG_DEVICE_INFO_HEADER*  requestPacket){
	LONG ret = pDisplayConfigGetDeviceInfo( requestPacket);
	OutputDebugStringA("DisplayConfigGetDeviceInfo");
	return ret;
}

LONG (WINAPI *pDisplayConfigSetDeviceInfo) (DISPLAYCONFIG_DEVICE_INFO_HEADER*  setPacket) = DisplayConfigSetDeviceInfo;
LONG fake_DisplayConfigSetDeviceInfo(DISPLAYCONFIG_DEVICE_INFO_HEADER*  setPacket){
	LONG ret = pDisplayConfigSetDeviceInfo( setPacket);
	OutputDebugStringA("DisplayConfigSetDeviceInfo");
	return ret;
}

BOOL (WINAPI *pSystemParametersInfoA) (UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni) = SystemParametersInfoA;
BOOL fake_SystemParametersInfoA(UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni){
	BOOL ret = pSystemParametersInfoA(uiAction,uiParam,pvParam,fWinIni);
	OutputDebugStringA("SystemParametersInfoA");
	return ret;
}

BOOL (WINAPI *pSystemParametersInfoW) (UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni) = SystemParametersInfoW;
BOOL fake_SystemParametersInfoW(UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni){
	BOOL ret = pSystemParametersInfoW(uiAction,uiParam,pvParam,fWinIni);
	OutputDebugStringA("SystemParametersInfoW");
	return ret;
}

BOOL (WINAPI *pSoundSentry) () = SoundSentry;
BOOL fake_SoundSentry(){
	BOOL ret = pSoundSentry();
	OutputDebugStringA("SoundSentry");
	return ret;
}

VOID (WINAPI *pSetDebugErrorLevel) (DWORD dwLevel) = SetDebugErrorLevel;
VOID fake_SetDebugErrorLevel(DWORD dwLevel){
	pSetDebugErrorLevel(dwLevel);
	OutputDebugStringA("SetDebugErrorLevel");
}

VOID (WINAPI *pSetLastErrorEx) (DWORD dwErrCode,DWORD dwType) = SetLastErrorEx;
VOID fake_SetLastErrorEx(DWORD dwErrCode,DWORD dwType){
	pSetLastErrorEx(dwErrCode,dwType);
	OutputDebugStringA("SetLastErrorEx");
}

int (WINAPI *pInternalGetWindowText) (HWND hWnd,LPWSTR pString,int cchMaxCount) = InternalGetWindowText;
int fake_InternalGetWindowText(HWND hWnd,LPWSTR pString,int cchMaxCount){
	int ret = pInternalGetWindowText(hWnd,pString,cchMaxCount);
	OutputDebugStringA("InternalGetWindowText");
	return ret;
}

BOOL (WINAPI *pCancelShutdown) () = CancelShutdown;
BOOL fake_CancelShutdown(){
	BOOL ret = pCancelShutdown();
	OutputDebugStringA("CancelShutdown");
	return ret;
}

HMONITOR (WINAPI *pMonitorFromPoint) (POINT pt,DWORD dwFlags) = MonitorFromPoint;
HMONITOR fake_MonitorFromPoint(POINT pt,DWORD dwFlags){
	HMONITOR ret = pMonitorFromPoint(pt,dwFlags);
	OutputDebugStringA("MonitorFromPoint");
	return ret;
}

HMONITOR (WINAPI *pMonitorFromRect) (LPCRECT lprc,DWORD dwFlags) = MonitorFromRect;
HMONITOR fake_MonitorFromRect(LPCRECT lprc,DWORD dwFlags){
	HMONITOR ret = pMonitorFromRect(lprc,dwFlags);
	OutputDebugStringA("MonitorFromRect");
	return ret;
}

HMONITOR (WINAPI *pMonitorFromWindow) (HWND hwnd,DWORD dwFlags) = MonitorFromWindow;
HMONITOR fake_MonitorFromWindow(HWND hwnd,DWORD dwFlags){
	HMONITOR ret = pMonitorFromWindow(hwnd,dwFlags);
	OutputDebugStringA("MonitorFromWindow");
	return ret;
}

BOOL (WINAPI *pGetMonitorInfoA) (HMONITOR hMonitor,LPMONITORINFO lpmi) = GetMonitorInfoA;
BOOL fake_GetMonitorInfoA(HMONITOR hMonitor,LPMONITORINFO lpmi){
	BOOL ret = pGetMonitorInfoA(hMonitor,lpmi);
	OutputDebugStringA("GetMonitorInfoA");
	return ret;
}

BOOL (WINAPI *pGetMonitorInfoW) (HMONITOR hMonitor,LPMONITORINFO lpmi) = GetMonitorInfoW;
BOOL fake_GetMonitorInfoW(HMONITOR hMonitor,LPMONITORINFO lpmi){
	BOOL ret = pGetMonitorInfoW(hMonitor,lpmi);
	OutputDebugStringA("GetMonitorInfoW");
	return ret;
}

BOOL (WINAPI *pEnumDisplayMonitors) (HDC hdc,LPCRECT lprcClip,MONITORENUMPROC lpfnEnum,LPARAM dwData) = EnumDisplayMonitors;
BOOL fake_EnumDisplayMonitors(HDC hdc,LPCRECT lprcClip,MONITORENUMPROC lpfnEnum,LPARAM dwData){
	BOOL ret = pEnumDisplayMonitors(hdc,lprcClip,lpfnEnum,dwData);
	OutputDebugStringA("EnumDisplayMonitors");
	return ret;
}

VOID (WINAPI *pNotifyWinEvent) (DWORD event,HWND hwnd,LONG idObject,LONG idChild) = NotifyWinEvent;
VOID fake_NotifyWinEvent(DWORD event,HWND hwnd,LONG idObject,LONG idChild){
	pNotifyWinEvent(event,hwnd,idObject,idChild);
	OutputDebugStringA("NotifyWinEvent");
}

HWINEVENTHOOK (WINAPI *pSetWinEventHook) (DWORD eventMin,DWORD eventMax,HMODULE hmodWinEventProc,WINEVENTPROC pfnWinEventProc,DWORD idProcess,DWORD idThread,DWORD dwFlags) = SetWinEventHook;
HWINEVENTHOOK fake_SetWinEventHook(DWORD eventMin,DWORD eventMax,HMODULE hmodWinEventProc,WINEVENTPROC pfnWinEventProc,DWORD idProcess,DWORD idThread,DWORD dwFlags){
	HWINEVENTHOOK ret = pSetWinEventHook(eventMin,eventMax,hmodWinEventProc,pfnWinEventProc,idProcess,idThread,dwFlags);
	OutputDebugStringA("SetWinEventHook");
	return ret;
}

BOOL (WINAPI *pIsWinEventHookInstalled) (DWORD event) = IsWinEventHookInstalled;
BOOL fake_IsWinEventHookInstalled(DWORD event){
	BOOL ret = pIsWinEventHookInstalled(event);
	OutputDebugStringA("IsWinEventHookInstalled");
	return ret;
}

BOOL (WINAPI *pUnhookWinEvent) (HWINEVENTHOOK hWinEventHook) = UnhookWinEvent;
BOOL fake_UnhookWinEvent(HWINEVENTHOOK hWinEventHook){
	BOOL ret = pUnhookWinEvent(hWinEventHook);
	OutputDebugStringA("UnhookWinEvent");
	return ret;
}

BOOL (WINAPI *pGetGUIThreadInfo) (DWORD idThread,PGUITHREADINFO pgui) = GetGUIThreadInfo;
BOOL fake_GetGUIThreadInfo(DWORD idThread,PGUITHREADINFO pgui){
	BOOL ret = pGetGUIThreadInfo(idThread,pgui);
	OutputDebugStringA("GetGUIThreadInfo");
	return ret;
}

BOOL (WINAPI *pBlockInput) (BOOL fBlockIt) = BlockInput;
BOOL fake_BlockInput(BOOL fBlockIt){
	BOOL ret = pBlockInput(fBlockIt);
	OutputDebugStringA("BlockInput");
	return ret;
}

BOOL (WINAPI *pSetProcessDPIAware) () = SetProcessDPIAware;
BOOL fake_SetProcessDPIAware(){
	BOOL ret = pSetProcessDPIAware();
	OutputDebugStringA("SetProcessDPIAware");
	return ret;
}

BOOL (WINAPI *pIsProcessDPIAware) () = IsProcessDPIAware;
BOOL fake_IsProcessDPIAware(){
	BOOL ret = pIsProcessDPIAware();
	OutputDebugStringA("IsProcessDPIAware");
	return ret;
}

UINT (WINAPI *pGetWindowModuleFileNameA) (HWND hwnd,LPSTR pszFileName,UINT cchFileNameMax) = GetWindowModuleFileNameA;
UINT fake_GetWindowModuleFileNameA(HWND hwnd,LPSTR pszFileName,UINT cchFileNameMax){
	UINT ret = pGetWindowModuleFileNameA(hwnd,pszFileName,cchFileNameMax);
	OutputDebugStringA("GetWindowModuleFileNameA");
	return ret;
}

UINT (WINAPI *pGetWindowModuleFileNameW) (HWND hwnd,LPWSTR pszFileName,UINT cchFileNameMax) = GetWindowModuleFileNameW;
UINT fake_GetWindowModuleFileNameW(HWND hwnd,LPWSTR pszFileName,UINT cchFileNameMax){
	UINT ret = pGetWindowModuleFileNameW(hwnd,pszFileName,cchFileNameMax);
	OutputDebugStringA("GetWindowModuleFileNameW");
	return ret;
}

BOOL (WINAPI *pGetCursorInfo) (PCURSORINFO pci) = GetCursorInfo;
BOOL fake_GetCursorInfo(PCURSORINFO pci){
	BOOL ret = pGetCursorInfo(pci);
	OutputDebugStringA("GetCursorInfo");
	return ret;
}

BOOL (WINAPI *pGetWindowInfo) (HWND hwnd,PWINDOWINFO pwi) = GetWindowInfo;
BOOL fake_GetWindowInfo(HWND hwnd,PWINDOWINFO pwi){
	BOOL ret = pGetWindowInfo(hwnd,pwi);
	OutputDebugStringA("GetWindowInfo");
	return ret;
}

BOOL (WINAPI *pGetTitleBarInfo) (HWND hwnd,PTITLEBARINFO pti) = GetTitleBarInfo;
BOOL fake_GetTitleBarInfo(HWND hwnd,PTITLEBARINFO pti){
	BOOL ret = pGetTitleBarInfo(hwnd,pti);
	OutputDebugStringA("GetTitleBarInfo");
	return ret;
}

BOOL (WINAPI *pGetMenuBarInfo) (HWND hwnd,LONG idObject,LONG idItem,PMENUBARINFO pmbi) = GetMenuBarInfo;
BOOL fake_GetMenuBarInfo(HWND hwnd,LONG idObject,LONG idItem,PMENUBARINFO pmbi){
	BOOL ret = pGetMenuBarInfo(hwnd,idObject,idItem,pmbi);
	OutputDebugStringA("GetMenuBarInfo");
	return ret;
}

BOOL (WINAPI *pGetScrollBarInfo) (HWND hwnd,LONG idObject,PSCROLLBARINFO psbi) = GetScrollBarInfo;
BOOL fake_GetScrollBarInfo(HWND hwnd,LONG idObject,PSCROLLBARINFO psbi){
	BOOL ret = pGetScrollBarInfo(hwnd,idObject,psbi);
	OutputDebugStringA("GetScrollBarInfo");
	return ret;
}

BOOL (WINAPI *pGetComboBoxInfo) (HWND hwndCombo,PCOMBOBOXINFO pcbi) = GetComboBoxInfo;
BOOL fake_GetComboBoxInfo(HWND hwndCombo,PCOMBOBOXINFO pcbi){
	BOOL ret = pGetComboBoxInfo(hwndCombo,pcbi);
	OutputDebugStringA("GetComboBoxInfo");
	return ret;
}

HWND (WINAPI *pGetAncestor) (HWND hwnd,UINT gaFlags) = GetAncestor;
HWND fake_GetAncestor(HWND hwnd,UINT gaFlags){
	HWND ret = pGetAncestor(hwnd,gaFlags);
	OutputDebugStringA("GetAncestor");
	return ret;
}

HWND (WINAPI *pRealChildWindowFromPoint) (HWND hwndParent,POINT ptParentClientCoords) = RealChildWindowFromPoint;
HWND fake_RealChildWindowFromPoint(HWND hwndParent,POINT ptParentClientCoords){
	HWND ret = pRealChildWindowFromPoint(hwndParent,ptParentClientCoords);
	OutputDebugStringA("RealChildWindowFromPoint");
	return ret;
}

UINT (WINAPI *pRealGetWindowClassA) (HWND hwnd,LPSTR ptszClassName,UINT cchClassNameMax) = RealGetWindowClassA;
UINT fake_RealGetWindowClassA(HWND hwnd,LPSTR ptszClassName,UINT cchClassNameMax){
	UINT ret = pRealGetWindowClassA(hwnd,ptszClassName,cchClassNameMax);
	OutputDebugStringA("RealGetWindowClassA");
	return ret;
}

UINT (WINAPI *pRealGetWindowClassW) (HWND hwnd,LPWSTR ptszClassName,UINT cchClassNameMax) = RealGetWindowClassW;
UINT fake_RealGetWindowClassW(HWND hwnd,LPWSTR ptszClassName,UINT cchClassNameMax){
	UINT ret = pRealGetWindowClassW(hwnd,ptszClassName,cchClassNameMax);
	OutputDebugStringA("RealGetWindowClassW");
	return ret;
}

BOOL (WINAPI *pGetAltTabInfoA) (HWND hwnd,int iItem,PALTTABINFO pati,LPSTR pszItemText,UINT cchItemText) = GetAltTabInfoA;
BOOL fake_GetAltTabInfoA(HWND hwnd,int iItem,PALTTABINFO pati,LPSTR pszItemText,UINT cchItemText){
	BOOL ret = pGetAltTabInfoA(hwnd,iItem,pati,pszItemText,cchItemText);
	OutputDebugStringA("GetAltTabInfoA");
	return ret;
}

BOOL (WINAPI *pGetAltTabInfoW) (HWND hwnd,int iItem,PALTTABINFO pati,LPWSTR pszItemText,UINT cchItemText) = GetAltTabInfoW;
BOOL fake_GetAltTabInfoW(HWND hwnd,int iItem,PALTTABINFO pati,LPWSTR pszItemText,UINT cchItemText){
	BOOL ret = pGetAltTabInfoW(hwnd,iItem,pati,pszItemText,cchItemText);
	OutputDebugStringA("GetAltTabInfoW");
	return ret;
}

DWORD (WINAPI *pGetListBoxInfo) (HWND hwnd) = GetListBoxInfo;
DWORD fake_GetListBoxInfo(HWND hwnd){
	DWORD ret = pGetListBoxInfo(hwnd);
	OutputDebugStringA("GetListBoxInfo");
	return ret;
}

BOOL (WINAPI *pLockWorkStation) () = LockWorkStation;
BOOL fake_LockWorkStation(){
	BOOL ret = pLockWorkStation();
	OutputDebugStringA("LockWorkStation");
	return ret;
}

BOOL (WINAPI *pUserHandleGrantAccess) (HANDLE hUserHandle,HANDLE hJob,BOOL bGrant) = UserHandleGrantAccess;
BOOL fake_UserHandleGrantAccess(HANDLE hUserHandle,HANDLE hJob,BOOL bGrant){
	BOOL ret = pUserHandleGrantAccess(hUserHandle,hJob,bGrant);
	OutputDebugStringA("UserHandleGrantAccess");
	return ret;
}

UINT (WINAPI *pGetRawInputData) (HRAWINPUT hRawInput,UINT uiCommand,LPVOID pData,PUINT pcbSize,UINT cbSizeHeader) = GetRawInputData;
UINT fake_GetRawInputData(HRAWINPUT hRawInput,UINT uiCommand,LPVOID pData,PUINT pcbSize,UINT cbSizeHeader){
	UINT ret = pGetRawInputData(hRawInput,uiCommand,pData,pcbSize,cbSizeHeader);
	OutputDebugStringA("GetRawInputData");
	return ret;
}

UINT (WINAPI *pGetRawInputDeviceInfoA) (HANDLE hDevice,UINT uiCommand,LPVOID pData,PUINT pcbSize) = GetRawInputDeviceInfoA;
UINT fake_GetRawInputDeviceInfoA(HANDLE hDevice,UINT uiCommand,LPVOID pData,PUINT pcbSize){
	UINT ret = pGetRawInputDeviceInfoA(hDevice,uiCommand,pData,pcbSize);
	OutputDebugStringA("GetRawInputDeviceInfoA");
	return ret;
}

UINT (WINAPI *pGetRawInputDeviceInfoW) (HANDLE hDevice,UINT uiCommand,LPVOID pData,PUINT pcbSize) = GetRawInputDeviceInfoW;
UINT fake_GetRawInputDeviceInfoW(HANDLE hDevice,UINT uiCommand,LPVOID pData,PUINT pcbSize){
	UINT ret = pGetRawInputDeviceInfoW(hDevice,uiCommand,pData,pcbSize);
	OutputDebugStringA("GetRawInputDeviceInfoW");
	return ret;
}

UINT (WINAPI *pGetRawInputBuffer) (PRAWINPUT pData,PUINT pcbSize,UINT cbSizeHeader) = GetRawInputBuffer;
UINT fake_GetRawInputBuffer(PRAWINPUT pData,PUINT pcbSize,UINT cbSizeHeader){
	UINT ret = pGetRawInputBuffer(pData,pcbSize,cbSizeHeader);
	OutputDebugStringA("GetRawInputBuffer");
	return ret;
}

BOOL (WINAPI *pRegisterRawInputDevices) (PCRAWINPUTDEVICE pRawInputDevices,UINT uiNumDevices,UINT cbSize) = RegisterRawInputDevices;
BOOL fake_RegisterRawInputDevices(PCRAWINPUTDEVICE pRawInputDevices,UINT uiNumDevices,UINT cbSize){
	BOOL ret = pRegisterRawInputDevices(pRawInputDevices,uiNumDevices,cbSize);
	OutputDebugStringA("RegisterRawInputDevices");
	return ret;
}

UINT (WINAPI *pGetRegisteredRawInputDevices) (PRAWINPUTDEVICE pRawInputDevices,PUINT puiNumDevices,UINT cbSize) = GetRegisteredRawInputDevices;
UINT fake_GetRegisteredRawInputDevices(PRAWINPUTDEVICE pRawInputDevices,PUINT puiNumDevices,UINT cbSize){
	UINT ret = pGetRegisteredRawInputDevices(pRawInputDevices,puiNumDevices,cbSize);
	OutputDebugStringA("GetRegisteredRawInputDevices");
	return ret;
}

UINT (WINAPI *pGetRawInputDeviceList) (PRAWINPUTDEVICELIST pRawInputDeviceList,PUINT puiNumDevices,UINT cbSize) = GetRawInputDeviceList;
UINT fake_GetRawInputDeviceList(PRAWINPUTDEVICELIST pRawInputDeviceList,PUINT puiNumDevices,UINT cbSize){
	UINT ret = pGetRawInputDeviceList(pRawInputDeviceList,puiNumDevices,cbSize);
	OutputDebugStringA("GetRawInputDeviceList");
	return ret;
}

LRESULT (WINAPI *pDefRawInputProc) (PRAWINPUT*  paRawInput,INT nInput,UINT cbSizeHeader) = DefRawInputProc;
LRESULT fake_DefRawInputProc(PRAWINPUT*  paRawInput,INT nInput,UINT cbSizeHeader){
	LRESULT ret = pDefRawInputProc( paRawInput,nInput,cbSizeHeader);
	OutputDebugStringA("DefRawInputProc");
	return ret;
}

BOOL (WINAPI *pChangeWindowMessageFilter) (UINT message,DWORD dwFlag) = ChangeWindowMessageFilter;
BOOL fake_ChangeWindowMessageFilter(UINT message,DWORD dwFlag){
	BOOL ret = pChangeWindowMessageFilter(message,dwFlag);
	OutputDebugStringA("ChangeWindowMessageFilter");
	return ret;
}

BOOL (WINAPI *pChangeWindowMessageFilterEx) (HWND hwnd,UINT message,DWORD action,PCHANGEFILTERSTRUCT pChangeFilterStruct) = ChangeWindowMessageFilterEx;
BOOL fake_ChangeWindowMessageFilterEx(HWND hwnd,UINT message,DWORD action,PCHANGEFILTERSTRUCT pChangeFilterStruct){
	BOOL ret = pChangeWindowMessageFilterEx(hwnd,message,action,pChangeFilterStruct);
	OutputDebugStringA("ChangeWindowMessageFilterEx");
	return ret;
}

BOOL (WINAPI *pGetGestureInfo) (HGESTUREINFO hGestureInfo,PGESTUREINFO pGestureInfo) = GetGestureInfo;
BOOL fake_GetGestureInfo(HGESTUREINFO hGestureInfo,PGESTUREINFO pGestureInfo){
	BOOL ret = pGetGestureInfo(hGestureInfo,pGestureInfo);
	OutputDebugStringA("GetGestureInfo");
	return ret;
}

BOOL (WINAPI *pGetGestureExtraArgs) (HGESTUREINFO hGestureInfo,UINT cbExtraArgs,PBYTE pExtraArgs) = GetGestureExtraArgs;
BOOL fake_GetGestureExtraArgs(HGESTUREINFO hGestureInfo,UINT cbExtraArgs,PBYTE pExtraArgs){
	BOOL ret = pGetGestureExtraArgs(hGestureInfo,cbExtraArgs,pExtraArgs);
	OutputDebugStringA("GetGestureExtraArgs");
	return ret;
}

BOOL (WINAPI *pCloseGestureInfoHandle) (HGESTUREINFO hGestureInfo) = CloseGestureInfoHandle;
BOOL fake_CloseGestureInfoHandle(HGESTUREINFO hGestureInfo){
	BOOL ret = pCloseGestureInfoHandle(hGestureInfo);
	OutputDebugStringA("CloseGestureInfoHandle");
	return ret;
}

BOOL (WINAPI *pSetGestureConfig) (HWND hwnd,DWORD dwReserved,UINT cIDs,PGESTURECONFIG pGestureConfig,UINT cbSize) = SetGestureConfig;
BOOL fake_SetGestureConfig(HWND hwnd,DWORD dwReserved,UINT cIDs,PGESTURECONFIG pGestureConfig,UINT cbSize){
	BOOL ret = pSetGestureConfig(hwnd,dwReserved,cIDs,pGestureConfig,cbSize);
	OutputDebugStringA("SetGestureConfig");
	return ret;
}

BOOL (WINAPI *pGetGestureConfig) (HWND hwnd,DWORD dwReserved,DWORD dwFlags,PUINT pcIDs,PGESTURECONFIG pGestureConfig,UINT cbSize) = GetGestureConfig;
BOOL fake_GetGestureConfig(HWND hwnd,DWORD dwReserved,DWORD dwFlags,PUINT pcIDs,PGESTURECONFIG pGestureConfig,UINT cbSize){
	BOOL ret = pGetGestureConfig(hwnd,dwReserved,dwFlags,pcIDs,pGestureConfig,cbSize);
	OutputDebugStringA("GetGestureConfig");
	return ret;
}

BOOL (WINAPI *pShutdownBlockReasonCreate) (HWND hWnd,LPCWSTR pwszReason) = ShutdownBlockReasonCreate;
BOOL fake_ShutdownBlockReasonCreate(HWND hWnd,LPCWSTR pwszReason){
	BOOL ret = pShutdownBlockReasonCreate(hWnd,pwszReason);
	OutputDebugStringA("ShutdownBlockReasonCreate");
	return ret;
}

BOOL (WINAPI *pShutdownBlockReasonQuery) (HWND hWnd,LPWSTR pwszBuff,DWORD* pcchBuff) = ShutdownBlockReasonQuery;
BOOL fake_ShutdownBlockReasonQuery(HWND hWnd,LPWSTR pwszBuff,DWORD* pcchBuff){
	BOOL ret = pShutdownBlockReasonQuery(hWnd,pwszBuff,pcchBuff);
	OutputDebugStringA("ShutdownBlockReasonQuery");
	return ret;
}

BOOL (WINAPI *pShutdownBlockReasonDestroy) (HWND hWnd) = ShutdownBlockReasonDestroy;
BOOL fake_ShutdownBlockReasonDestroy(HWND hWnd){
	BOOL ret = pShutdownBlockReasonDestroy(hWnd);
	OutputDebugStringA("ShutdownBlockReasonDestroy");
	return ret;
}


BOOL WINAPI DllMain(HINSTANCE hinst, DWORD dwReason, LPVOID reserved)  
{  
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        g_mutex = CreateMutex(NULL, false, NULL);
        DetourTransactionBegin();  
        DetourUpdateThread(GetCurrentThread());  
		DetourAttach(&(PVOID&)pLoadKeyboardLayoutA, fake_LoadKeyboardLayoutA);
		DetourAttach(&(PVOID&)pLoadKeyboardLayoutW, fake_LoadKeyboardLayoutW);
		DetourAttach(&(PVOID&)pActivateKeyboardLayout, fake_ActivateKeyboardLayout);
		DetourAttach(&(PVOID&)pToUnicodeEx, fake_ToUnicodeEx);
		DetourAttach(&(PVOID&)pUnloadKeyboardLayout, fake_UnloadKeyboardLayout);
		DetourAttach(&(PVOID&)pGetKeyboardLayoutNameA, fake_GetKeyboardLayoutNameA);
		DetourAttach(&(PVOID&)pGetKeyboardLayoutNameW, fake_GetKeyboardLayoutNameW);
		DetourAttach(&(PVOID&)pGetKeyboardLayoutList, fake_GetKeyboardLayoutList);
		DetourAttach(&(PVOID&)pGetKeyboardLayout, fake_GetKeyboardLayout);
		DetourAttach(&(PVOID&)pGetMouseMovePointsEx, fake_GetMouseMovePointsEx);
		DetourAttach(&(PVOID&)pCreateDesktopA, fake_CreateDesktopA);
		DetourAttach(&(PVOID&)pCreateDesktopW, fake_CreateDesktopW);
		DetourAttach(&(PVOID&)pCreateDesktopExA, fake_CreateDesktopExA);
		DetourAttach(&(PVOID&)pCreateDesktopExW, fake_CreateDesktopExW);
		DetourAttach(&(PVOID&)pOpenDesktopA, fake_OpenDesktopA);
		DetourAttach(&(PVOID&)pOpenDesktopW, fake_OpenDesktopW);
		DetourAttach(&(PVOID&)pOpenInputDesktop, fake_OpenInputDesktop);
		DetourAttach(&(PVOID&)pEnumDesktopsA, fake_EnumDesktopsA);
		DetourAttach(&(PVOID&)pEnumDesktopsW, fake_EnumDesktopsW);
		DetourAttach(&(PVOID&)pEnumDesktopWindows, fake_EnumDesktopWindows);
		DetourAttach(&(PVOID&)pSwitchDesktop, fake_SwitchDesktop);
		DetourAttach(&(PVOID&)pSetThreadDesktop, fake_SetThreadDesktop);
		DetourAttach(&(PVOID&)pCloseDesktop, fake_CloseDesktop);
		DetourAttach(&(PVOID&)pGetThreadDesktop, fake_GetThreadDesktop);
		DetourAttach(&(PVOID&)pCreateWindowStationA, fake_CreateWindowStationA);
		DetourAttach(&(PVOID&)pCreateWindowStationW, fake_CreateWindowStationW);
		DetourAttach(&(PVOID&)pOpenWindowStationA, fake_OpenWindowStationA);
		DetourAttach(&(PVOID&)pOpenWindowStationW, fake_OpenWindowStationW);
		DetourAttach(&(PVOID&)pEnumWindowStationsA, fake_EnumWindowStationsA);
		DetourAttach(&(PVOID&)pEnumWindowStationsW, fake_EnumWindowStationsW);
		DetourAttach(&(PVOID&)pCloseWindowStation, fake_CloseWindowStation);
		DetourAttach(&(PVOID&)pSetProcessWindowStation, fake_SetProcessWindowStation);
		DetourAttach(&(PVOID&)pGetProcessWindowStation, fake_GetProcessWindowStation);
		DetourAttach(&(PVOID&)pSetUserObjectSecurity, fake_SetUserObjectSecurity);
		DetourAttach(&(PVOID&)pGetUserObjectSecurity, fake_GetUserObjectSecurity);
		DetourAttach(&(PVOID&)pGetUserObjectInformationA, fake_GetUserObjectInformationA);
		DetourAttach(&(PVOID&)pGetUserObjectInformationW, fake_GetUserObjectInformationW);
		DetourAttach(&(PVOID&)pSetUserObjectInformationA, fake_SetUserObjectInformationA);
		DetourAttach(&(PVOID&)pSetUserObjectInformationW, fake_SetUserObjectInformationW);
		DetourAttach(&(PVOID&)pIsHungAppWindow, fake_IsHungAppWindow);
		DetourAttach(&(PVOID&)pDisableProcessWindowsGhosting, fake_DisableProcessWindowsGhosting);
		DetourAttach(&(PVOID&)pRegisterWindowMessageA, fake_RegisterWindowMessageA);
		DetourAttach(&(PVOID&)pRegisterWindowMessageW, fake_RegisterWindowMessageW);
		DetourAttach(&(PVOID&)pTrackMouseEvent, fake_TrackMouseEvent);
		DetourAttach(&(PVOID&)pDrawEdge, fake_DrawEdge);
		DetourAttach(&(PVOID&)pDrawFrameControl, fake_DrawFrameControl);
		DetourAttach(&(PVOID&)pDrawCaption, fake_DrawCaption);
		DetourAttach(&(PVOID&)pDrawAnimatedRects, fake_DrawAnimatedRects);
		DetourAttach(&(PVOID&)pGetMessageA, fake_GetMessageA);
		DetourAttach(&(PVOID&)pGetMessageW, fake_GetMessageW);
		DetourAttach(&(PVOID&)pTranslateMessage, fake_TranslateMessage);
		DetourAttach(&(PVOID&)pDispatchMessageA, fake_DispatchMessageA);
		DetourAttach(&(PVOID&)pDispatchMessageW, fake_DispatchMessageW);
		DetourAttach(&(PVOID&)pSetMessageQueue, fake_SetMessageQueue);
		DetourAttach(&(PVOID&)pPeekMessageA, fake_PeekMessageA);
		DetourAttach(&(PVOID&)pPeekMessageW, fake_PeekMessageW);
		DetourAttach(&(PVOID&)pRegisterHotKey, fake_RegisterHotKey);
		DetourAttach(&(PVOID&)pUnregisterHotKey, fake_UnregisterHotKey);
		DetourAttach(&(PVOID&)pExitWindowsEx, fake_ExitWindowsEx);
		DetourAttach(&(PVOID&)pSwapMouseButton, fake_SwapMouseButton);
		DetourAttach(&(PVOID&)pGetMessagePos, fake_GetMessagePos);
		DetourAttach(&(PVOID&)pGetMessageTime, fake_GetMessageTime);
		DetourAttach(&(PVOID&)pGetMessageExtraInfo, fake_GetMessageExtraInfo);
		DetourAttach(&(PVOID&)pIsWow64Message, fake_IsWow64Message);
		DetourAttach(&(PVOID&)pSetMessageExtraInfo, fake_SetMessageExtraInfo);
		DetourAttach(&(PVOID&)pSendMessageA, fake_SendMessageA);
		DetourAttach(&(PVOID&)pSendMessageW, fake_SendMessageW);
		DetourAttach(&(PVOID&)pSendMessageTimeoutA, fake_SendMessageTimeoutA);
		DetourAttach(&(PVOID&)pSendMessageTimeoutW, fake_SendMessageTimeoutW);
		DetourAttach(&(PVOID&)pSendNotifyMessageA, fake_SendNotifyMessageA);
		DetourAttach(&(PVOID&)pSendNotifyMessageW, fake_SendNotifyMessageW);
		DetourAttach(&(PVOID&)pSendMessageCallbackA, fake_SendMessageCallbackA);
		DetourAttach(&(PVOID&)pSendMessageCallbackW, fake_SendMessageCallbackW);
		DetourAttach(&(PVOID&)pBroadcastSystemMessageExA, fake_BroadcastSystemMessageExA);
		DetourAttach(&(PVOID&)pBroadcastSystemMessageExW, fake_BroadcastSystemMessageExW);
		DetourAttach(&(PVOID&)pBroadcastSystemMessageA, fake_BroadcastSystemMessageA);
		DetourAttach(&(PVOID&)pBroadcastSystemMessageW, fake_BroadcastSystemMessageW);
		DetourAttach(&(PVOID&)pBroadcastSystemMessage, fake_BroadcastSystemMessage);
		DetourAttach(&(PVOID&)pRegisterDeviceNotificationA, fake_RegisterDeviceNotificationA);
		DetourAttach(&(PVOID&)pRegisterDeviceNotificationW, fake_RegisterDeviceNotificationW);
		DetourAttach(&(PVOID&)pUnregisterDeviceNotification, fake_UnregisterDeviceNotification);
		DetourAttach(&(PVOID&)pRegisterPowerSettingNotification, fake_RegisterPowerSettingNotification);
		DetourAttach(&(PVOID&)pUnregisterPowerSettingNotification, fake_UnregisterPowerSettingNotification);
		DetourAttach(&(PVOID&)pPostMessageA, fake_PostMessageA);
		DetourAttach(&(PVOID&)pPostMessageW, fake_PostMessageW);
		DetourAttach(&(PVOID&)pPostThreadMessageA, fake_PostThreadMessageA);
		DetourAttach(&(PVOID&)pPostThreadMessageW, fake_PostThreadMessageW);
		DetourAttach(&(PVOID&)pAttachThreadInput, fake_AttachThreadInput);
		DetourAttach(&(PVOID&)pReplyMessage, fake_ReplyMessage);
		DetourAttach(&(PVOID&)pWaitMessage, fake_WaitMessage);
		DetourAttach(&(PVOID&)pWaitForInputIdle, fake_WaitForInputIdle);
		DetourAttach(&(PVOID&)pDefWindowProcA, fake_DefWindowProcA);
		DetourAttach(&(PVOID&)pDefWindowProcW, fake_DefWindowProcW);
		DetourAttach(&(PVOID&)pPostQuitMessage, fake_PostQuitMessage);
		DetourAttach(&(PVOID&)pCallWindowProcA, fake_CallWindowProcA);
		DetourAttach(&(PVOID&)pCallWindowProcW, fake_CallWindowProcW);
		DetourAttach(&(PVOID&)pInSendMessage, fake_InSendMessage);
		DetourAttach(&(PVOID&)pInSendMessageEx, fake_InSendMessageEx);
		DetourAttach(&(PVOID&)pGetDoubleClickTime, fake_GetDoubleClickTime);
		DetourAttach(&(PVOID&)pSetDoubleClickTime, fake_SetDoubleClickTime);
		DetourAttach(&(PVOID&)pRegisterClassA, fake_RegisterClassA);
		DetourAttach(&(PVOID&)pRegisterClassW, fake_RegisterClassW);
		DetourAttach(&(PVOID&)pUnregisterClassA, fake_UnregisterClassA);
		DetourAttach(&(PVOID&)pUnregisterClassW, fake_UnregisterClassW);
		DetourAttach(&(PVOID&)pGetClassInfoA, fake_GetClassInfoA);
		DetourAttach(&(PVOID&)pGetClassInfoW, fake_GetClassInfoW);
		DetourAttach(&(PVOID&)pRegisterClassExA, fake_RegisterClassExA);
		DetourAttach(&(PVOID&)pRegisterClassExW, fake_RegisterClassExW);
		DetourAttach(&(PVOID&)pGetClassInfoExA, fake_GetClassInfoExA);
		DetourAttach(&(PVOID&)pGetClassInfoExW, fake_GetClassInfoExW);
		DetourAttach(&(PVOID&)pCreateWindowExA, fake_CreateWindowExA);
		DetourAttach(&(PVOID&)pCreateWindowExW, fake_CreateWindowExW);
		DetourAttach(&(PVOID&)pIsWindow, fake_IsWindow);
		DetourAttach(&(PVOID&)pIsMenu, fake_IsMenu);
		DetourAttach(&(PVOID&)pIsChild, fake_IsChild);
		DetourAttach(&(PVOID&)pDestroyWindow, fake_DestroyWindow);
		DetourAttach(&(PVOID&)pShowWindow, fake_ShowWindow);
		DetourAttach(&(PVOID&)pAnimateWindow, fake_AnimateWindow);
		DetourAttach(&(PVOID&)pUpdateLayeredWindow, fake_UpdateLayeredWindow);
		DetourAttach(&(PVOID&)pUpdateLayeredWindowIndirect, fake_UpdateLayeredWindowIndirect);
		DetourAttach(&(PVOID&)pGetLayeredWindowAttributes, fake_GetLayeredWindowAttributes);
		DetourAttach(&(PVOID&)pPrintWindow, fake_PrintWindow);
		DetourAttach(&(PVOID&)pSetLayeredWindowAttributes, fake_SetLayeredWindowAttributes);
		DetourAttach(&(PVOID&)pShowWindowAsync, fake_ShowWindowAsync);
		DetourAttach(&(PVOID&)pFlashWindow, fake_FlashWindow);
		DetourAttach(&(PVOID&)pFlashWindowEx, fake_FlashWindowEx);
		DetourAttach(&(PVOID&)pShowOwnedPopups, fake_ShowOwnedPopups);
		DetourAttach(&(PVOID&)pOpenIcon, fake_OpenIcon);
		DetourAttach(&(PVOID&)pCloseWindow, fake_CloseWindow);
		DetourAttach(&(PVOID&)pMoveWindow, fake_MoveWindow);
		DetourAttach(&(PVOID&)pSetWindowPos, fake_SetWindowPos);
		DetourAttach(&(PVOID&)pGetWindowPlacement, fake_GetWindowPlacement);
		DetourAttach(&(PVOID&)pSetWindowPlacement, fake_SetWindowPlacement);
		DetourAttach(&(PVOID&)pGetWindowDisplayAffinity, fake_GetWindowDisplayAffinity);
		DetourAttach(&(PVOID&)pSetWindowDisplayAffinity, fake_SetWindowDisplayAffinity);
		DetourAttach(&(PVOID&)pBeginDeferWindowPos, fake_BeginDeferWindowPos);
		DetourAttach(&(PVOID&)pDeferWindowPos, fake_DeferWindowPos);
		DetourAttach(&(PVOID&)pEndDeferWindowPos, fake_EndDeferWindowPos);
		DetourAttach(&(PVOID&)pIsWindowVisible, fake_IsWindowVisible);
		DetourAttach(&(PVOID&)pIsIconic, fake_IsIconic);
		DetourAttach(&(PVOID&)pAnyPopup, fake_AnyPopup);
		DetourAttach(&(PVOID&)pBringWindowToTop, fake_BringWindowToTop);
		DetourAttach(&(PVOID&)pIsZoomed, fake_IsZoomed);
		DetourAttach(&(PVOID&)pCreateDialogParamA, fake_CreateDialogParamA);
		DetourAttach(&(PVOID&)pCreateDialogParamW, fake_CreateDialogParamW);
		DetourAttach(&(PVOID&)pCreateDialogIndirectParamA, fake_CreateDialogIndirectParamA);
		DetourAttach(&(PVOID&)pCreateDialogIndirectParamW, fake_CreateDialogIndirectParamW);
		DetourAttach(&(PVOID&)pDialogBoxParamA, fake_DialogBoxParamA);
		DetourAttach(&(PVOID&)pDialogBoxParamW, fake_DialogBoxParamW);
		DetourAttach(&(PVOID&)pDialogBoxIndirectParamA, fake_DialogBoxIndirectParamA);
		DetourAttach(&(PVOID&)pDialogBoxIndirectParamW, fake_DialogBoxIndirectParamW);
		DetourAttach(&(PVOID&)pEndDialog, fake_EndDialog);
		DetourAttach(&(PVOID&)pGetDlgItem, fake_GetDlgItem);
		DetourAttach(&(PVOID&)pSetDlgItemInt, fake_SetDlgItemInt);
		DetourAttach(&(PVOID&)pGetDlgItemInt, fake_GetDlgItemInt);
		DetourAttach(&(PVOID&)pSetDlgItemTextA, fake_SetDlgItemTextA);
		DetourAttach(&(PVOID&)pSetDlgItemTextW, fake_SetDlgItemTextW);
		DetourAttach(&(PVOID&)pGetDlgItemTextA, fake_GetDlgItemTextA);
		DetourAttach(&(PVOID&)pGetDlgItemTextW, fake_GetDlgItemTextW);
		DetourAttach(&(PVOID&)pCheckDlgButton, fake_CheckDlgButton);
		DetourAttach(&(PVOID&)pCheckRadioButton, fake_CheckRadioButton);
		DetourAttach(&(PVOID&)pIsDlgButtonChecked, fake_IsDlgButtonChecked);
		DetourAttach(&(PVOID&)pSendDlgItemMessageA, fake_SendDlgItemMessageA);
		DetourAttach(&(PVOID&)pSendDlgItemMessageW, fake_SendDlgItemMessageW);
		DetourAttach(&(PVOID&)pGetNextDlgGroupItem, fake_GetNextDlgGroupItem);
		DetourAttach(&(PVOID&)pGetNextDlgTabItem, fake_GetNextDlgTabItem);
		DetourAttach(&(PVOID&)pGetDlgCtrlID, fake_GetDlgCtrlID);
		DetourAttach(&(PVOID&)pGetDialogBaseUnits, fake_GetDialogBaseUnits);
		DetourAttach(&(PVOID&)pDefDlgProcA, fake_DefDlgProcA);
		DetourAttach(&(PVOID&)pDefDlgProcW, fake_DefDlgProcW);
		DetourAttach(&(PVOID&)pCallMsgFilterA, fake_CallMsgFilterA);
		DetourAttach(&(PVOID&)pCallMsgFilterW, fake_CallMsgFilterW);
		DetourAttach(&(PVOID&)pOpenClipboard, fake_OpenClipboard);
		DetourAttach(&(PVOID&)pCloseClipboard, fake_CloseClipboard);
		DetourAttach(&(PVOID&)pGetClipboardSequenceNumber, fake_GetClipboardSequenceNumber);
		DetourAttach(&(PVOID&)pGetClipboardOwner, fake_GetClipboardOwner);
		DetourAttach(&(PVOID&)pSetClipboardViewer, fake_SetClipboardViewer);
		DetourAttach(&(PVOID&)pGetClipboardViewer, fake_GetClipboardViewer);
		DetourAttach(&(PVOID&)pChangeClipboardChain, fake_ChangeClipboardChain);
		DetourAttach(&(PVOID&)pSetClipboardData, fake_SetClipboardData);
		DetourAttach(&(PVOID&)pGetClipboardData, fake_GetClipboardData);
		DetourAttach(&(PVOID&)pRegisterClipboardFormatA, fake_RegisterClipboardFormatA);
		DetourAttach(&(PVOID&)pRegisterClipboardFormatW, fake_RegisterClipboardFormatW);
		DetourAttach(&(PVOID&)pCountClipboardFormats, fake_CountClipboardFormats);
		DetourAttach(&(PVOID&)pEnumClipboardFormats, fake_EnumClipboardFormats);
		DetourAttach(&(PVOID&)pGetClipboardFormatNameA, fake_GetClipboardFormatNameA);
		DetourAttach(&(PVOID&)pGetClipboardFormatNameW, fake_GetClipboardFormatNameW);
		DetourAttach(&(PVOID&)pEmptyClipboard, fake_EmptyClipboard);
		DetourAttach(&(PVOID&)pIsClipboardFormatAvailable, fake_IsClipboardFormatAvailable);
		DetourAttach(&(PVOID&)pGetPriorityClipboardFormat, fake_GetPriorityClipboardFormat);
		DetourAttach(&(PVOID&)pGetOpenClipboardWindow, fake_GetOpenClipboardWindow);
		DetourAttach(&(PVOID&)pAddClipboardFormatListener, fake_AddClipboardFormatListener);
		DetourAttach(&(PVOID&)pRemoveClipboardFormatListener, fake_RemoveClipboardFormatListener);
		DetourAttach(&(PVOID&)pGetUpdatedClipboardFormats, fake_GetUpdatedClipboardFormats);
		DetourAttach(&(PVOID&)pCharToOemA, fake_CharToOemA);
		DetourAttach(&(PVOID&)pCharToOemW, fake_CharToOemW);
		DetourAttach(&(PVOID&)pOemToCharA, fake_OemToCharA);
		DetourAttach(&(PVOID&)pOemToCharW, fake_OemToCharW);
		DetourAttach(&(PVOID&)pCharToOemBuffA, fake_CharToOemBuffA);
		DetourAttach(&(PVOID&)pCharToOemBuffW, fake_CharToOemBuffW);
		DetourAttach(&(PVOID&)pOemToCharBuffA, fake_OemToCharBuffA);
		DetourAttach(&(PVOID&)pOemToCharBuffW, fake_OemToCharBuffW);
		DetourAttach(&(PVOID&)pCharUpperA, fake_CharUpperA);
		DetourAttach(&(PVOID&)pCharUpperW, fake_CharUpperW);
		DetourAttach(&(PVOID&)pCharUpperBuffA, fake_CharUpperBuffA);
		DetourAttach(&(PVOID&)pCharUpperBuffW, fake_CharUpperBuffW);
		DetourAttach(&(PVOID&)pCharLowerA, fake_CharLowerA);
		DetourAttach(&(PVOID&)pCharLowerW, fake_CharLowerW);
		DetourAttach(&(PVOID&)pCharLowerBuffA, fake_CharLowerBuffA);
		DetourAttach(&(PVOID&)pCharLowerBuffW, fake_CharLowerBuffW);
		DetourAttach(&(PVOID&)pCharNextA, fake_CharNextA);
		DetourAttach(&(PVOID&)pCharNextW, fake_CharNextW);
		DetourAttach(&(PVOID&)pCharPrevA, fake_CharPrevA);
		DetourAttach(&(PVOID&)pCharPrevW, fake_CharPrevW);
		DetourAttach(&(PVOID&)pCharNextExA, fake_CharNextExA);
		DetourAttach(&(PVOID&)pCharPrevExA, fake_CharPrevExA);
		DetourAttach(&(PVOID&)pIsCharAlphaA, fake_IsCharAlphaA);
		DetourAttach(&(PVOID&)pIsCharAlphaW, fake_IsCharAlphaW);
		DetourAttach(&(PVOID&)pIsCharAlphaNumericA, fake_IsCharAlphaNumericA);
		DetourAttach(&(PVOID&)pIsCharAlphaNumericW, fake_IsCharAlphaNumericW);
		DetourAttach(&(PVOID&)pIsCharUpperA, fake_IsCharUpperA);
		DetourAttach(&(PVOID&)pIsCharUpperW, fake_IsCharUpperW);
		DetourAttach(&(PVOID&)pIsCharLowerA, fake_IsCharLowerA);
		DetourAttach(&(PVOID&)pIsCharLowerW, fake_IsCharLowerW);
		DetourAttach(&(PVOID&)pSetFocus, fake_SetFocus);
		DetourAttach(&(PVOID&)pGetActiveWindow, fake_GetActiveWindow);
		DetourAttach(&(PVOID&)pGetFocus, fake_GetFocus);
		DetourAttach(&(PVOID&)pGetKBCodePage, fake_GetKBCodePage);
		DetourAttach(&(PVOID&)pGetKeyState, fake_GetKeyState);
		DetourAttach(&(PVOID&)pGetAsyncKeyState, fake_GetAsyncKeyState);
		DetourAttach(&(PVOID&)pGetKeyboardState, fake_GetKeyboardState);
		DetourAttach(&(PVOID&)pSetKeyboardState, fake_SetKeyboardState);
		DetourAttach(&(PVOID&)pGetKeyNameTextA, fake_GetKeyNameTextA);
		DetourAttach(&(PVOID&)pGetKeyNameTextW, fake_GetKeyNameTextW);
		DetourAttach(&(PVOID&)pGetKeyboardType, fake_GetKeyboardType);
		DetourAttach(&(PVOID&)pToAscii, fake_ToAscii);
		DetourAttach(&(PVOID&)pToAsciiEx, fake_ToAsciiEx);
		DetourAttach(&(PVOID&)pToUnicode, fake_ToUnicode);
		DetourAttach(&(PVOID&)pOemKeyScan, fake_OemKeyScan);
		DetourAttach(&(PVOID&)pVkKeyScanA, fake_VkKeyScanA);
		DetourAttach(&(PVOID&)pVkKeyScanW, fake_VkKeyScanW);
		DetourAttach(&(PVOID&)pVkKeyScanExA, fake_VkKeyScanExA);
		DetourAttach(&(PVOID&)pVkKeyScanExW, fake_VkKeyScanExW);
		DetourAttach(&(PVOID&)pkeybd_event, fake_keybd_event);
		DetourAttach(&(PVOID&)pmouse_event, fake_mouse_event);
		DetourAttach(&(PVOID&)pSendInput, fake_SendInput);
		DetourAttach(&(PVOID&)pGetTouchInputInfo, fake_GetTouchInputInfo);
		DetourAttach(&(PVOID&)pCloseTouchInputHandle, fake_CloseTouchInputHandle);
		DetourAttach(&(PVOID&)pRegisterTouchWindow, fake_RegisterTouchWindow);
		DetourAttach(&(PVOID&)pUnregisterTouchWindow, fake_UnregisterTouchWindow);
		DetourAttach(&(PVOID&)pIsTouchWindow, fake_IsTouchWindow);
		DetourAttach(&(PVOID&)pGetLastInputInfo, fake_GetLastInputInfo);
		DetourAttach(&(PVOID&)pMapVirtualKeyA, fake_MapVirtualKeyA);
		DetourAttach(&(PVOID&)pMapVirtualKeyW, fake_MapVirtualKeyW);
		DetourAttach(&(PVOID&)pMapVirtualKeyExA, fake_MapVirtualKeyExA);
		DetourAttach(&(PVOID&)pMapVirtualKeyExW, fake_MapVirtualKeyExW);
		DetourAttach(&(PVOID&)pGetInputState, fake_GetInputState);
		DetourAttach(&(PVOID&)pGetQueueStatus, fake_GetQueueStatus);
		DetourAttach(&(PVOID&)pGetCapture, fake_GetCapture);
		DetourAttach(&(PVOID&)pSetCapture, fake_SetCapture);
		DetourAttach(&(PVOID&)pReleaseCapture, fake_ReleaseCapture);
		DetourAttach(&(PVOID&)pMsgWaitForMultipleObjects, fake_MsgWaitForMultipleObjects);
		DetourAttach(&(PVOID&)pMsgWaitForMultipleObjectsEx, fake_MsgWaitForMultipleObjectsEx);
		DetourAttach(&(PVOID&)pSetTimer, fake_SetTimer);
		DetourAttach(&(PVOID&)pKillTimer, fake_KillTimer);
		DetourAttach(&(PVOID&)pIsWindowUnicode, fake_IsWindowUnicode);
		DetourAttach(&(PVOID&)pEnableWindow, fake_EnableWindow);
		DetourAttach(&(PVOID&)pIsWindowEnabled, fake_IsWindowEnabled);
		DetourAttach(&(PVOID&)pLoadAcceleratorsA, fake_LoadAcceleratorsA);
		DetourAttach(&(PVOID&)pLoadAcceleratorsW, fake_LoadAcceleratorsW);
		DetourAttach(&(PVOID&)pCreateAcceleratorTableA, fake_CreateAcceleratorTableA);
		DetourAttach(&(PVOID&)pCreateAcceleratorTableW, fake_CreateAcceleratorTableW);
		DetourAttach(&(PVOID&)pDestroyAcceleratorTable, fake_DestroyAcceleratorTable);
		DetourAttach(&(PVOID&)pCopyAcceleratorTableA, fake_CopyAcceleratorTableA);
		DetourAttach(&(PVOID&)pCopyAcceleratorTableW, fake_CopyAcceleratorTableW);
		DetourAttach(&(PVOID&)pTranslateAcceleratorA, fake_TranslateAcceleratorA);
		DetourAttach(&(PVOID&)pTranslateAcceleratorW, fake_TranslateAcceleratorW);
		DetourAttach(&(PVOID&)pGetSystemMetrics, fake_GetSystemMetrics);
		DetourAttach(&(PVOID&)pLoadMenuA, fake_LoadMenuA);
		DetourAttach(&(PVOID&)pLoadMenuW, fake_LoadMenuW);
		DetourAttach(&(PVOID&)pLoadMenuIndirectA, fake_LoadMenuIndirectA);
		DetourAttach(&(PVOID&)pLoadMenuIndirectW, fake_LoadMenuIndirectW);
		DetourAttach(&(PVOID&)pGetMenu, fake_GetMenu);
		DetourAttach(&(PVOID&)pSetMenu, fake_SetMenu);
		DetourAttach(&(PVOID&)pChangeMenuA, fake_ChangeMenuA);
		DetourAttach(&(PVOID&)pChangeMenuW, fake_ChangeMenuW);
		DetourAttach(&(PVOID&)pHiliteMenuItem, fake_HiliteMenuItem);
		DetourAttach(&(PVOID&)pGetMenuStringA, fake_GetMenuStringA);
		DetourAttach(&(PVOID&)pGetMenuStringW, fake_GetMenuStringW);
		DetourAttach(&(PVOID&)pGetMenuState, fake_GetMenuState);
		DetourAttach(&(PVOID&)pDrawMenuBar, fake_DrawMenuBar);
		DetourAttach(&(PVOID&)pGetSystemMenu, fake_GetSystemMenu);
		DetourAttach(&(PVOID&)pCreateMenu, fake_CreateMenu);
		DetourAttach(&(PVOID&)pCreatePopupMenu, fake_CreatePopupMenu);
		DetourAttach(&(PVOID&)pDestroyMenu, fake_DestroyMenu);
		DetourAttach(&(PVOID&)pCheckMenuItem, fake_CheckMenuItem);
		DetourAttach(&(PVOID&)pEnableMenuItem, fake_EnableMenuItem);
		DetourAttach(&(PVOID&)pGetSubMenu, fake_GetSubMenu);
		DetourAttach(&(PVOID&)pGetMenuItemID, fake_GetMenuItemID);
		DetourAttach(&(PVOID&)pGetMenuItemCount, fake_GetMenuItemCount);
		DetourAttach(&(PVOID&)pInsertMenuA, fake_InsertMenuA);
		DetourAttach(&(PVOID&)pInsertMenuW, fake_InsertMenuW);
		DetourAttach(&(PVOID&)pAppendMenuA, fake_AppendMenuA);
		DetourAttach(&(PVOID&)pAppendMenuW, fake_AppendMenuW);
		DetourAttach(&(PVOID&)pModifyMenuA, fake_ModifyMenuA);
		DetourAttach(&(PVOID&)pModifyMenuW, fake_ModifyMenuW);
		DetourAttach(&(PVOID&)pRemoveMenu, fake_RemoveMenu);
		DetourAttach(&(PVOID&)pDeleteMenu, fake_DeleteMenu);
		DetourAttach(&(PVOID&)pSetMenuItemBitmaps, fake_SetMenuItemBitmaps);
		DetourAttach(&(PVOID&)pGetMenuCheckMarkDimensions, fake_GetMenuCheckMarkDimensions);
		DetourAttach(&(PVOID&)pTrackPopupMenu, fake_TrackPopupMenu);
		DetourAttach(&(PVOID&)pTrackPopupMenuEx, fake_TrackPopupMenuEx);
		DetourAttach(&(PVOID&)pCalculatePopupWindowPosition, fake_CalculatePopupWindowPosition);
		DetourAttach(&(PVOID&)pGetMenuInfo, fake_GetMenuInfo);
		DetourAttach(&(PVOID&)pSetMenuInfo, fake_SetMenuInfo);
		DetourAttach(&(PVOID&)pEndMenu, fake_EndMenu);
		DetourAttach(&(PVOID&)pInsertMenuItemA, fake_InsertMenuItemA);
		DetourAttach(&(PVOID&)pInsertMenuItemW, fake_InsertMenuItemW);
		DetourAttach(&(PVOID&)pGetMenuItemInfoA, fake_GetMenuItemInfoA);
		DetourAttach(&(PVOID&)pGetMenuItemInfoW, fake_GetMenuItemInfoW);
		DetourAttach(&(PVOID&)pSetMenuItemInfoA, fake_SetMenuItemInfoA);
		DetourAttach(&(PVOID&)pSetMenuItemInfoW, fake_SetMenuItemInfoW);
		DetourAttach(&(PVOID&)pGetMenuDefaultItem, fake_GetMenuDefaultItem);
		DetourAttach(&(PVOID&)pSetMenuDefaultItem, fake_SetMenuDefaultItem);
		DetourAttach(&(PVOID&)pGetMenuItemRect, fake_GetMenuItemRect);
		DetourAttach(&(PVOID&)pMenuItemFromPoint, fake_MenuItemFromPoint);
		DetourAttach(&(PVOID&)pDragObject, fake_DragObject);
		DetourAttach(&(PVOID&)pDragDetect, fake_DragDetect);
		DetourAttach(&(PVOID&)pDrawIcon, fake_DrawIcon);
		DetourAttach(&(PVOID&)pDrawTextA, fake_DrawTextA);
		DetourAttach(&(PVOID&)pDrawTextW, fake_DrawTextW);
		DetourAttach(&(PVOID&)pDrawTextExA, fake_DrawTextExA);
		DetourAttach(&(PVOID&)pDrawTextExW, fake_DrawTextExW);
		DetourAttach(&(PVOID&)pGrayStringA, fake_GrayStringA);
		DetourAttach(&(PVOID&)pGrayStringW, fake_GrayStringW);
		DetourAttach(&(PVOID&)pDrawStateA, fake_DrawStateA);
		DetourAttach(&(PVOID&)pDrawStateW, fake_DrawStateW);
		DetourAttach(&(PVOID&)pTabbedTextOutA, fake_TabbedTextOutA);
		DetourAttach(&(PVOID&)pTabbedTextOutW, fake_TabbedTextOutW);
		DetourAttach(&(PVOID&)pGetTabbedTextExtentA, fake_GetTabbedTextExtentA);
		DetourAttach(&(PVOID&)pGetTabbedTextExtentW, fake_GetTabbedTextExtentW);
		DetourAttach(&(PVOID&)pUpdateWindow, fake_UpdateWindow);
		DetourAttach(&(PVOID&)pSetActiveWindow, fake_SetActiveWindow);
		DetourAttach(&(PVOID&)pGetForegroundWindow, fake_GetForegroundWindow);
		DetourAttach(&(PVOID&)pPaintDesktop, fake_PaintDesktop);
		DetourAttach(&(PVOID&)pSwitchToThisWindow, fake_SwitchToThisWindow);
		DetourAttach(&(PVOID&)pSetForegroundWindow, fake_SetForegroundWindow);
		DetourAttach(&(PVOID&)pAllowSetForegroundWindow, fake_AllowSetForegroundWindow);
		DetourAttach(&(PVOID&)pLockSetForegroundWindow, fake_LockSetForegroundWindow);
		DetourAttach(&(PVOID&)pWindowFromDC, fake_WindowFromDC);
		DetourAttach(&(PVOID&)pGetDC, fake_GetDC);
		DetourAttach(&(PVOID&)pGetDCEx, fake_GetDCEx);
		DetourAttach(&(PVOID&)pGetWindowDC, fake_GetWindowDC);
		DetourAttach(&(PVOID&)pReleaseDC, fake_ReleaseDC);
		DetourAttach(&(PVOID&)pBeginPaint, fake_BeginPaint);
		DetourAttach(&(PVOID&)pEndPaint, fake_EndPaint);
		DetourAttach(&(PVOID&)pGetUpdateRect, fake_GetUpdateRect);
		DetourAttach(&(PVOID&)pGetUpdateRgn, fake_GetUpdateRgn);
		DetourAttach(&(PVOID&)pSetWindowRgn, fake_SetWindowRgn);
		DetourAttach(&(PVOID&)pGetWindowRgn, fake_GetWindowRgn);
		DetourAttach(&(PVOID&)pGetWindowRgnBox, fake_GetWindowRgnBox);
		DetourAttach(&(PVOID&)pExcludeUpdateRgn, fake_ExcludeUpdateRgn);
		DetourAttach(&(PVOID&)pInvalidateRect, fake_InvalidateRect);
		DetourAttach(&(PVOID&)pValidateRect, fake_ValidateRect);
		DetourAttach(&(PVOID&)pInvalidateRgn, fake_InvalidateRgn);
		DetourAttach(&(PVOID&)pValidateRgn, fake_ValidateRgn);
		DetourAttach(&(PVOID&)pRedrawWindow, fake_RedrawWindow);
		DetourAttach(&(PVOID&)pLockWindowUpdate, fake_LockWindowUpdate);
		DetourAttach(&(PVOID&)pScrollWindow, fake_ScrollWindow);
		DetourAttach(&(PVOID&)pScrollDC, fake_ScrollDC);
		DetourAttach(&(PVOID&)pScrollWindowEx, fake_ScrollWindowEx);
		DetourAttach(&(PVOID&)pSetScrollPos, fake_SetScrollPos);
		DetourAttach(&(PVOID&)pGetScrollPos, fake_GetScrollPos);
		DetourAttach(&(PVOID&)pSetScrollRange, fake_SetScrollRange);
		DetourAttach(&(PVOID&)pGetScrollRange, fake_GetScrollRange);
		DetourAttach(&(PVOID&)pShowScrollBar, fake_ShowScrollBar);
		DetourAttach(&(PVOID&)pEnableScrollBar, fake_EnableScrollBar);
		DetourAttach(&(PVOID&)pSetPropA, fake_SetPropA);
		DetourAttach(&(PVOID&)pSetPropW, fake_SetPropW);
		DetourAttach(&(PVOID&)pGetPropA, fake_GetPropA);
		DetourAttach(&(PVOID&)pGetPropW, fake_GetPropW);
		DetourAttach(&(PVOID&)pRemovePropA, fake_RemovePropA);
		DetourAttach(&(PVOID&)pRemovePropW, fake_RemovePropW);
		DetourAttach(&(PVOID&)pEnumPropsExA, fake_EnumPropsExA);
		DetourAttach(&(PVOID&)pEnumPropsExW, fake_EnumPropsExW);
		DetourAttach(&(PVOID&)pEnumPropsA, fake_EnumPropsA);
		DetourAttach(&(PVOID&)pEnumPropsW, fake_EnumPropsW);
		DetourAttach(&(PVOID&)pSetWindowTextA, fake_SetWindowTextA);
		DetourAttach(&(PVOID&)pSetWindowTextW, fake_SetWindowTextW);
		DetourAttach(&(PVOID&)pGetWindowTextA, fake_GetWindowTextA);
		DetourAttach(&(PVOID&)pGetWindowTextW, fake_GetWindowTextW);
		DetourAttach(&(PVOID&)pGetWindowTextLengthA, fake_GetWindowTextLengthA);
		DetourAttach(&(PVOID&)pGetWindowTextLengthW, fake_GetWindowTextLengthW);
		DetourAttach(&(PVOID&)pGetClientRect, fake_GetClientRect);
		DetourAttach(&(PVOID&)pGetWindowRect, fake_GetWindowRect);
		DetourAttach(&(PVOID&)pAdjustWindowRect, fake_AdjustWindowRect);
		DetourAttach(&(PVOID&)pAdjustWindowRectEx, fake_AdjustWindowRectEx);
		DetourAttach(&(PVOID&)pSetWindowContextHelpId, fake_SetWindowContextHelpId);
		DetourAttach(&(PVOID&)pGetWindowContextHelpId, fake_GetWindowContextHelpId);
		DetourAttach(&(PVOID&)pSetMenuContextHelpId, fake_SetMenuContextHelpId);
		DetourAttach(&(PVOID&)pGetMenuContextHelpId, fake_GetMenuContextHelpId);
		DetourAttach(&(PVOID&)pMessageBoxA, fake_MessageBoxA);
		DetourAttach(&(PVOID&)pMessageBoxW, fake_MessageBoxW);
		DetourAttach(&(PVOID&)pMessageBoxExA, fake_MessageBoxExA);
		DetourAttach(&(PVOID&)pMessageBoxExW, fake_MessageBoxExW);
		DetourAttach(&(PVOID&)pMessageBoxIndirectA, fake_MessageBoxIndirectA);
		DetourAttach(&(PVOID&)pMessageBoxIndirectW, fake_MessageBoxIndirectW);
		DetourAttach(&(PVOID&)pMessageBeep, fake_MessageBeep);
		DetourAttach(&(PVOID&)pShowCursor, fake_ShowCursor);
		DetourAttach(&(PVOID&)pSetCursorPos, fake_SetCursorPos);
		DetourAttach(&(PVOID&)pSetPhysicalCursorPos, fake_SetPhysicalCursorPos);
		DetourAttach(&(PVOID&)pSetCursor, fake_SetCursor);
		DetourAttach(&(PVOID&)pGetCursorPos, fake_GetCursorPos);
		DetourAttach(&(PVOID&)pGetPhysicalCursorPos, fake_GetPhysicalCursorPos);
		DetourAttach(&(PVOID&)pClipCursor, fake_ClipCursor);
		DetourAttach(&(PVOID&)pGetClipCursor, fake_GetClipCursor);
		DetourAttach(&(PVOID&)pGetCursor, fake_GetCursor);
		DetourAttach(&(PVOID&)pCreateCaret, fake_CreateCaret);
		DetourAttach(&(PVOID&)pGetCaretBlinkTime, fake_GetCaretBlinkTime);
		DetourAttach(&(PVOID&)pSetCaretBlinkTime, fake_SetCaretBlinkTime);
		DetourAttach(&(PVOID&)pDestroyCaret, fake_DestroyCaret);
		DetourAttach(&(PVOID&)pHideCaret, fake_HideCaret);
		DetourAttach(&(PVOID&)pShowCaret, fake_ShowCaret);
		DetourAttach(&(PVOID&)pSetCaretPos, fake_SetCaretPos);
		DetourAttach(&(PVOID&)pGetCaretPos, fake_GetCaretPos);
		DetourAttach(&(PVOID&)pClientToScreen, fake_ClientToScreen);
		DetourAttach(&(PVOID&)pScreenToClient, fake_ScreenToClient);
		DetourAttach(&(PVOID&)pLogicalToPhysicalPoint, fake_LogicalToPhysicalPoint);
		DetourAttach(&(PVOID&)pPhysicalToLogicalPoint, fake_PhysicalToLogicalPoint);
		DetourAttach(&(PVOID&)pMapWindowPoints, fake_MapWindowPoints);
		DetourAttach(&(PVOID&)pWindowFromPoint, fake_WindowFromPoint);
		DetourAttach(&(PVOID&)pWindowFromPhysicalPoint, fake_WindowFromPhysicalPoint);
		DetourAttach(&(PVOID&)pChildWindowFromPoint, fake_ChildWindowFromPoint);
		DetourAttach(&(PVOID&)pChildWindowFromPointEx, fake_ChildWindowFromPointEx);
		DetourAttach(&(PVOID&)pGetSysColor, fake_GetSysColor);
		DetourAttach(&(PVOID&)pGetSysColorBrush, fake_GetSysColorBrush);
		DetourAttach(&(PVOID&)pSetSysColors, fake_SetSysColors);
		DetourAttach(&(PVOID&)pDrawFocusRect, fake_DrawFocusRect);
		DetourAttach(&(PVOID&)pFillRect, fake_FillRect);
		DetourAttach(&(PVOID&)pFrameRect, fake_FrameRect);
		DetourAttach(&(PVOID&)pInvertRect, fake_InvertRect);
		DetourAttach(&(PVOID&)pSetRect, fake_SetRect);
		DetourAttach(&(PVOID&)pSetRectEmpty, fake_SetRectEmpty);
		DetourAttach(&(PVOID&)pCopyRect, fake_CopyRect);
		DetourAttach(&(PVOID&)pInflateRect, fake_InflateRect);
		DetourAttach(&(PVOID&)pIntersectRect, fake_IntersectRect);
		DetourAttach(&(PVOID&)pUnionRect, fake_UnionRect);
		DetourAttach(&(PVOID&)pSubtractRect, fake_SubtractRect);
		DetourAttach(&(PVOID&)pOffsetRect, fake_OffsetRect);
		DetourAttach(&(PVOID&)pIsRectEmpty, fake_IsRectEmpty);
		DetourAttach(&(PVOID&)pEqualRect, fake_EqualRect);
		DetourAttach(&(PVOID&)pPtInRect, fake_PtInRect);
		DetourAttach(&(PVOID&)pGetWindowWord, fake_GetWindowWord);
		DetourAttach(&(PVOID&)pSetWindowWord, fake_SetWindowWord);
		DetourAttach(&(PVOID&)pGetWindowLongA, fake_GetWindowLongA);
		DetourAttach(&(PVOID&)pGetWindowLongW, fake_GetWindowLongW);
		DetourAttach(&(PVOID&)pSetWindowLongA, fake_SetWindowLongA);
		DetourAttach(&(PVOID&)pSetWindowLongW, fake_SetWindowLongW);
		DetourAttach(&(PVOID&)pGetWindowLongPtrA, fake_GetWindowLongPtrA);
		DetourAttach(&(PVOID&)pGetWindowLongPtrW, fake_GetWindowLongPtrW);
		DetourAttach(&(PVOID&)pSetWindowLongPtrA, fake_SetWindowLongPtrA);
		DetourAttach(&(PVOID&)pSetWindowLongPtrW, fake_SetWindowLongPtrW);
		DetourAttach(&(PVOID&)pGetClassWord, fake_GetClassWord);
		DetourAttach(&(PVOID&)pSetClassWord, fake_SetClassWord);
		DetourAttach(&(PVOID&)pGetClassLongA, fake_GetClassLongA);
		DetourAttach(&(PVOID&)pGetClassLongW, fake_GetClassLongW);
		DetourAttach(&(PVOID&)pSetClassLongA, fake_SetClassLongA);
		DetourAttach(&(PVOID&)pSetClassLongW, fake_SetClassLongW);
		DetourAttach(&(PVOID&)pGetClassLongPtrA, fake_GetClassLongPtrA);
		DetourAttach(&(PVOID&)pGetClassLongPtrW, fake_GetClassLongPtrW);
		DetourAttach(&(PVOID&)pSetClassLongPtrA, fake_SetClassLongPtrA);
		DetourAttach(&(PVOID&)pSetClassLongPtrW, fake_SetClassLongPtrW);
		DetourAttach(&(PVOID&)pGetProcessDefaultLayout, fake_GetProcessDefaultLayout);
		DetourAttach(&(PVOID&)pSetProcessDefaultLayout, fake_SetProcessDefaultLayout);
		DetourAttach(&(PVOID&)pGetDesktopWindow, fake_GetDesktopWindow);
		DetourAttach(&(PVOID&)pGetParent, fake_GetParent);
		DetourAttach(&(PVOID&)pSetParent, fake_SetParent);
		DetourAttach(&(PVOID&)pEnumChildWindows, fake_EnumChildWindows);
		DetourAttach(&(PVOID&)pFindWindowA, fake_FindWindowA);
		DetourAttach(&(PVOID&)pFindWindowW, fake_FindWindowW);
		DetourAttach(&(PVOID&)pFindWindowExA, fake_FindWindowExA);
		DetourAttach(&(PVOID&)pFindWindowExW, fake_FindWindowExW);
		DetourAttach(&(PVOID&)pGetShellWindow, fake_GetShellWindow);
		DetourAttach(&(PVOID&)pRegisterShellHookWindow, fake_RegisterShellHookWindow);
		DetourAttach(&(PVOID&)pDeregisterShellHookWindow, fake_DeregisterShellHookWindow);
		DetourAttach(&(PVOID&)pEnumWindows, fake_EnumWindows);
		DetourAttach(&(PVOID&)pEnumThreadWindows, fake_EnumThreadWindows);
		DetourAttach(&(PVOID&)pGetClassNameA, fake_GetClassNameA);
		DetourAttach(&(PVOID&)pGetClassNameW, fake_GetClassNameW);
		DetourAttach(&(PVOID&)pGetTopWindow, fake_GetTopWindow);
		DetourAttach(&(PVOID&)pGetWindowThreadProcessId, fake_GetWindowThreadProcessId);
		DetourAttach(&(PVOID&)pIsGUIThread, fake_IsGUIThread);
		DetourAttach(&(PVOID&)pGetLastActivePopup, fake_GetLastActivePopup);
		DetourAttach(&(PVOID&)pGetWindow, fake_GetWindow);
		DetourAttach(&(PVOID&)pSetWindowsHookA, fake_SetWindowsHookA);
		DetourAttach(&(PVOID&)pSetWindowsHookW, fake_SetWindowsHookW);
		DetourAttach(&(PVOID&)pUnhookWindowsHook, fake_UnhookWindowsHook);
		DetourAttach(&(PVOID&)pSetWindowsHookExA, fake_SetWindowsHookExA);
		DetourAttach(&(PVOID&)pSetWindowsHookExW, fake_SetWindowsHookExW);
		DetourAttach(&(PVOID&)pUnhookWindowsHookEx, fake_UnhookWindowsHookEx);
		DetourAttach(&(PVOID&)pCallNextHookEx, fake_CallNextHookEx);
		DetourAttach(&(PVOID&)pCheckMenuRadioItem, fake_CheckMenuRadioItem);
		DetourAttach(&(PVOID&)pLoadBitmapA, fake_LoadBitmapA);
		DetourAttach(&(PVOID&)pLoadBitmapW, fake_LoadBitmapW);
		DetourAttach(&(PVOID&)pLoadCursorA, fake_LoadCursorA);
		DetourAttach(&(PVOID&)pLoadCursorW, fake_LoadCursorW);
		DetourAttach(&(PVOID&)pLoadCursorFromFileA, fake_LoadCursorFromFileA);
		DetourAttach(&(PVOID&)pLoadCursorFromFileW, fake_LoadCursorFromFileW);
		DetourAttach(&(PVOID&)pCreateCursor, fake_CreateCursor);
		DetourAttach(&(PVOID&)pDestroyCursor, fake_DestroyCursor);
		DetourAttach(&(PVOID&)pSetSystemCursor, fake_SetSystemCursor);
		DetourAttach(&(PVOID&)pLoadIconA, fake_LoadIconA);
		DetourAttach(&(PVOID&)pLoadIconW, fake_LoadIconW);
		DetourAttach(&(PVOID&)pPrivateExtractIconsA, fake_PrivateExtractIconsA);
		DetourAttach(&(PVOID&)pPrivateExtractIconsW, fake_PrivateExtractIconsW);
		DetourAttach(&(PVOID&)pCreateIcon, fake_CreateIcon);
		DetourAttach(&(PVOID&)pDestroyIcon, fake_DestroyIcon);
		DetourAttach(&(PVOID&)pLookupIconIdFromDirectory, fake_LookupIconIdFromDirectory);
		DetourAttach(&(PVOID&)pLookupIconIdFromDirectoryEx, fake_LookupIconIdFromDirectoryEx);
		DetourAttach(&(PVOID&)pCreateIconFromResource, fake_CreateIconFromResource);
		DetourAttach(&(PVOID&)pCreateIconFromResourceEx, fake_CreateIconFromResourceEx);
		DetourAttach(&(PVOID&)pLoadImageA, fake_LoadImageA);
		DetourAttach(&(PVOID&)pLoadImageW, fake_LoadImageW);
		DetourAttach(&(PVOID&)pCopyImage, fake_CopyImage);
		DetourAttach(&(PVOID&)pCreateIconIndirect, fake_CreateIconIndirect);
		DetourAttach(&(PVOID&)pCopyIcon, fake_CopyIcon);
		DetourAttach(&(PVOID&)pGetIconInfo, fake_GetIconInfo);
		DetourAttach(&(PVOID&)pGetIconInfoExA, fake_GetIconInfoExA);
		DetourAttach(&(PVOID&)pGetIconInfoExW, fake_GetIconInfoExW);
		DetourAttach(&(PVOID&)pLoadStringA, fake_LoadStringA);
		DetourAttach(&(PVOID&)pLoadStringW, fake_LoadStringW);
		DetourAttach(&(PVOID&)pIsDialogMessageA, fake_IsDialogMessageA);
		DetourAttach(&(PVOID&)pIsDialogMessageW, fake_IsDialogMessageW);
		DetourAttach(&(PVOID&)pMapDialogRect, fake_MapDialogRect);
		DetourAttach(&(PVOID&)pDlgDirListA, fake_DlgDirListA);
		DetourAttach(&(PVOID&)pDlgDirListW, fake_DlgDirListW);
		DetourAttach(&(PVOID&)pDlgDirSelectExA, fake_DlgDirSelectExA);
		DetourAttach(&(PVOID&)pDlgDirSelectExW, fake_DlgDirSelectExW);
		DetourAttach(&(PVOID&)pDlgDirListComboBoxA, fake_DlgDirListComboBoxA);
		DetourAttach(&(PVOID&)pDlgDirListComboBoxW, fake_DlgDirListComboBoxW);
		DetourAttach(&(PVOID&)pDlgDirSelectComboBoxExA, fake_DlgDirSelectComboBoxExA);
		DetourAttach(&(PVOID&)pDlgDirSelectComboBoxExW, fake_DlgDirSelectComboBoxExW);
		DetourAttach(&(PVOID&)pSetScrollInfo, fake_SetScrollInfo);
		DetourAttach(&(PVOID&)pGetScrollInfo, fake_GetScrollInfo);
		DetourAttach(&(PVOID&)pDefFrameProcA, fake_DefFrameProcA);
		DetourAttach(&(PVOID&)pDefFrameProcW, fake_DefFrameProcW);
		DetourAttach(&(PVOID&)pDefMDIChildProcA, fake_DefMDIChildProcA);
		DetourAttach(&(PVOID&)pDefMDIChildProcW, fake_DefMDIChildProcW);
		DetourAttach(&(PVOID&)pTranslateMDISysAccel, fake_TranslateMDISysAccel);
		DetourAttach(&(PVOID&)pArrangeIconicWindows, fake_ArrangeIconicWindows);
		DetourAttach(&(PVOID&)pCreateMDIWindowA, fake_CreateMDIWindowA);
		DetourAttach(&(PVOID&)pCreateMDIWindowW, fake_CreateMDIWindowW);
		DetourAttach(&(PVOID&)pTileWindows, fake_TileWindows);
		DetourAttach(&(PVOID&)pCascadeWindows, fake_CascadeWindows);
		DetourAttach(&(PVOID&)pWinHelpA, fake_WinHelpA);
		DetourAttach(&(PVOID&)pWinHelpW, fake_WinHelpW);
		DetourAttach(&(PVOID&)pGetGuiResources, fake_GetGuiResources);
		DetourAttach(&(PVOID&)pChangeDisplaySettingsA, fake_ChangeDisplaySettingsA);
		DetourAttach(&(PVOID&)pChangeDisplaySettingsW, fake_ChangeDisplaySettingsW);
		DetourAttach(&(PVOID&)pChangeDisplaySettingsExA, fake_ChangeDisplaySettingsExA);
		DetourAttach(&(PVOID&)pChangeDisplaySettingsExW, fake_ChangeDisplaySettingsExW);
		DetourAttach(&(PVOID&)pEnumDisplaySettingsA, fake_EnumDisplaySettingsA);
		DetourAttach(&(PVOID&)pEnumDisplaySettingsW, fake_EnumDisplaySettingsW);
		DetourAttach(&(PVOID&)pEnumDisplaySettingsExA, fake_EnumDisplaySettingsExA);
		DetourAttach(&(PVOID&)pEnumDisplaySettingsExW, fake_EnumDisplaySettingsExW);
		DetourAttach(&(PVOID&)pEnumDisplayDevicesA, fake_EnumDisplayDevicesA);
		DetourAttach(&(PVOID&)pEnumDisplayDevicesW, fake_EnumDisplayDevicesW);
		DetourAttach(&(PVOID&)pGetDisplayConfigBufferSizes, fake_GetDisplayConfigBufferSizes);
		DetourAttach(&(PVOID&)pSetDisplayConfig, fake_SetDisplayConfig);
		DetourAttach(&(PVOID&)pQueryDisplayConfig, fake_QueryDisplayConfig);
		DetourAttach(&(PVOID&)pDisplayConfigGetDeviceInfo, fake_DisplayConfigGetDeviceInfo);
		DetourAttach(&(PVOID&)pDisplayConfigSetDeviceInfo, fake_DisplayConfigSetDeviceInfo);
		DetourAttach(&(PVOID&)pSystemParametersInfoA, fake_SystemParametersInfoA);
		DetourAttach(&(PVOID&)pSystemParametersInfoW, fake_SystemParametersInfoW);
		DetourAttach(&(PVOID&)pSoundSentry, fake_SoundSentry);
		DetourAttach(&(PVOID&)pSetDebugErrorLevel, fake_SetDebugErrorLevel);
		DetourAttach(&(PVOID&)pSetLastErrorEx, fake_SetLastErrorEx);
		DetourAttach(&(PVOID&)pInternalGetWindowText, fake_InternalGetWindowText);
		DetourAttach(&(PVOID&)pCancelShutdown, fake_CancelShutdown);
		DetourAttach(&(PVOID&)pMonitorFromPoint, fake_MonitorFromPoint);
		DetourAttach(&(PVOID&)pMonitorFromRect, fake_MonitorFromRect);
		DetourAttach(&(PVOID&)pMonitorFromWindow, fake_MonitorFromWindow);
		DetourAttach(&(PVOID&)pGetMonitorInfoA, fake_GetMonitorInfoA);
		DetourAttach(&(PVOID&)pGetMonitorInfoW, fake_GetMonitorInfoW);
		DetourAttach(&(PVOID&)pEnumDisplayMonitors, fake_EnumDisplayMonitors);
		DetourAttach(&(PVOID&)pNotifyWinEvent, fake_NotifyWinEvent);
		DetourAttach(&(PVOID&)pSetWinEventHook, fake_SetWinEventHook);
		DetourAttach(&(PVOID&)pIsWinEventHookInstalled, fake_IsWinEventHookInstalled);
		DetourAttach(&(PVOID&)pUnhookWinEvent, fake_UnhookWinEvent);
		DetourAttach(&(PVOID&)pGetGUIThreadInfo, fake_GetGUIThreadInfo);
		DetourAttach(&(PVOID&)pBlockInput, fake_BlockInput);
		DetourAttach(&(PVOID&)pSetProcessDPIAware, fake_SetProcessDPIAware);
		DetourAttach(&(PVOID&)pIsProcessDPIAware, fake_IsProcessDPIAware);
		DetourAttach(&(PVOID&)pGetWindowModuleFileNameA, fake_GetWindowModuleFileNameA);
		DetourAttach(&(PVOID&)pGetWindowModuleFileNameW, fake_GetWindowModuleFileNameW);
		DetourAttach(&(PVOID&)pGetCursorInfo, fake_GetCursorInfo);
		DetourAttach(&(PVOID&)pGetWindowInfo, fake_GetWindowInfo);
		DetourAttach(&(PVOID&)pGetTitleBarInfo, fake_GetTitleBarInfo);
		DetourAttach(&(PVOID&)pGetMenuBarInfo, fake_GetMenuBarInfo);
		DetourAttach(&(PVOID&)pGetScrollBarInfo, fake_GetScrollBarInfo);
		DetourAttach(&(PVOID&)pGetComboBoxInfo, fake_GetComboBoxInfo);
		DetourAttach(&(PVOID&)pGetAncestor, fake_GetAncestor);
		DetourAttach(&(PVOID&)pRealChildWindowFromPoint, fake_RealChildWindowFromPoint);
		DetourAttach(&(PVOID&)pRealGetWindowClassA, fake_RealGetWindowClassA);
		DetourAttach(&(PVOID&)pRealGetWindowClassW, fake_RealGetWindowClassW);
		DetourAttach(&(PVOID&)pGetAltTabInfoA, fake_GetAltTabInfoA);
		DetourAttach(&(PVOID&)pGetAltTabInfoW, fake_GetAltTabInfoW);
		DetourAttach(&(PVOID&)pGetListBoxInfo, fake_GetListBoxInfo);
		DetourAttach(&(PVOID&)pLockWorkStation, fake_LockWorkStation);
		DetourAttach(&(PVOID&)pUserHandleGrantAccess, fake_UserHandleGrantAccess);
		DetourAttach(&(PVOID&)pGetRawInputData, fake_GetRawInputData);
		DetourAttach(&(PVOID&)pGetRawInputDeviceInfoA, fake_GetRawInputDeviceInfoA);
		DetourAttach(&(PVOID&)pGetRawInputDeviceInfoW, fake_GetRawInputDeviceInfoW);
		DetourAttach(&(PVOID&)pGetRawInputBuffer, fake_GetRawInputBuffer);
		DetourAttach(&(PVOID&)pRegisterRawInputDevices, fake_RegisterRawInputDevices);
		DetourAttach(&(PVOID&)pGetRegisteredRawInputDevices, fake_GetRegisteredRawInputDevices);
		DetourAttach(&(PVOID&)pGetRawInputDeviceList, fake_GetRawInputDeviceList);
		DetourAttach(&(PVOID&)pDefRawInputProc, fake_DefRawInputProc);
		DetourAttach(&(PVOID&)pChangeWindowMessageFilter, fake_ChangeWindowMessageFilter);
		DetourAttach(&(PVOID&)pChangeWindowMessageFilterEx, fake_ChangeWindowMessageFilterEx);
		DetourAttach(&(PVOID&)pGetGestureInfo, fake_GetGestureInfo);
		DetourAttach(&(PVOID&)pGetGestureExtraArgs, fake_GetGestureExtraArgs);
		DetourAttach(&(PVOID&)pCloseGestureInfoHandle, fake_CloseGestureInfoHandle);
		DetourAttach(&(PVOID&)pSetGestureConfig, fake_SetGestureConfig);
		DetourAttach(&(PVOID&)pGetGestureConfig, fake_GetGestureConfig);
		DetourAttach(&(PVOID&)pShutdownBlockReasonCreate, fake_ShutdownBlockReasonCreate);
		DetourAttach(&(PVOID&)pShutdownBlockReasonQuery, fake_ShutdownBlockReasonQuery);
		DetourAttach(&(PVOID&)pShutdownBlockReasonDestroy, fake_ShutdownBlockReasonDestroy);
 
        DetourTransactionCommit();  
    }  
    else if (dwReason == DLL_PROCESS_DETACH) {  
        DetourTransactionBegin();  
        DetourUpdateThread(GetCurrentThread());  
		DetourDetach(&(PVOID&)pLoadKeyboardLayoutA, fake_LoadKeyboardLayoutA);
		DetourDetach(&(PVOID&)pLoadKeyboardLayoutW, fake_LoadKeyboardLayoutW);
		DetourDetach(&(PVOID&)pActivateKeyboardLayout, fake_ActivateKeyboardLayout);
		DetourDetach(&(PVOID&)pToUnicodeEx, fake_ToUnicodeEx);
		DetourDetach(&(PVOID&)pUnloadKeyboardLayout, fake_UnloadKeyboardLayout);
		DetourDetach(&(PVOID&)pGetKeyboardLayoutNameA, fake_GetKeyboardLayoutNameA);
		DetourDetach(&(PVOID&)pGetKeyboardLayoutNameW, fake_GetKeyboardLayoutNameW);
		DetourDetach(&(PVOID&)pGetKeyboardLayoutList, fake_GetKeyboardLayoutList);
		DetourDetach(&(PVOID&)pGetKeyboardLayout, fake_GetKeyboardLayout);
		DetourDetach(&(PVOID&)pGetMouseMovePointsEx, fake_GetMouseMovePointsEx);
		DetourDetach(&(PVOID&)pCreateDesktopA, fake_CreateDesktopA);
		DetourDetach(&(PVOID&)pCreateDesktopW, fake_CreateDesktopW);
		DetourDetach(&(PVOID&)pCreateDesktopExA, fake_CreateDesktopExA);
		DetourDetach(&(PVOID&)pCreateDesktopExW, fake_CreateDesktopExW);
		DetourDetach(&(PVOID&)pOpenDesktopA, fake_OpenDesktopA);
		DetourDetach(&(PVOID&)pOpenDesktopW, fake_OpenDesktopW);
		DetourDetach(&(PVOID&)pOpenInputDesktop, fake_OpenInputDesktop);
		DetourDetach(&(PVOID&)pEnumDesktopsA, fake_EnumDesktopsA);
		DetourDetach(&(PVOID&)pEnumDesktopsW, fake_EnumDesktopsW);
		DetourDetach(&(PVOID&)pEnumDesktopWindows, fake_EnumDesktopWindows);
		DetourDetach(&(PVOID&)pSwitchDesktop, fake_SwitchDesktop);
		DetourDetach(&(PVOID&)pSetThreadDesktop, fake_SetThreadDesktop);
		DetourDetach(&(PVOID&)pCloseDesktop, fake_CloseDesktop);
		DetourDetach(&(PVOID&)pGetThreadDesktop, fake_GetThreadDesktop);
		DetourDetach(&(PVOID&)pCreateWindowStationA, fake_CreateWindowStationA);
		DetourDetach(&(PVOID&)pCreateWindowStationW, fake_CreateWindowStationW);
		DetourDetach(&(PVOID&)pOpenWindowStationA, fake_OpenWindowStationA);
		DetourDetach(&(PVOID&)pOpenWindowStationW, fake_OpenWindowStationW);
		DetourDetach(&(PVOID&)pEnumWindowStationsA, fake_EnumWindowStationsA);
		DetourDetach(&(PVOID&)pEnumWindowStationsW, fake_EnumWindowStationsW);
		DetourDetach(&(PVOID&)pCloseWindowStation, fake_CloseWindowStation);
		DetourDetach(&(PVOID&)pSetProcessWindowStation, fake_SetProcessWindowStation);
		DetourDetach(&(PVOID&)pGetProcessWindowStation, fake_GetProcessWindowStation);
		DetourDetach(&(PVOID&)pSetUserObjectSecurity, fake_SetUserObjectSecurity);
		DetourDetach(&(PVOID&)pGetUserObjectSecurity, fake_GetUserObjectSecurity);
		DetourDetach(&(PVOID&)pGetUserObjectInformationA, fake_GetUserObjectInformationA);
		DetourDetach(&(PVOID&)pGetUserObjectInformationW, fake_GetUserObjectInformationW);
		DetourDetach(&(PVOID&)pSetUserObjectInformationA, fake_SetUserObjectInformationA);
		DetourDetach(&(PVOID&)pSetUserObjectInformationW, fake_SetUserObjectInformationW);
		DetourDetach(&(PVOID&)pIsHungAppWindow, fake_IsHungAppWindow);
		DetourDetach(&(PVOID&)pDisableProcessWindowsGhosting, fake_DisableProcessWindowsGhosting);
		DetourDetach(&(PVOID&)pRegisterWindowMessageA, fake_RegisterWindowMessageA);
		DetourDetach(&(PVOID&)pRegisterWindowMessageW, fake_RegisterWindowMessageW);
		DetourDetach(&(PVOID&)pTrackMouseEvent, fake_TrackMouseEvent);
		DetourDetach(&(PVOID&)pDrawEdge, fake_DrawEdge);
		DetourDetach(&(PVOID&)pDrawFrameControl, fake_DrawFrameControl);
		DetourDetach(&(PVOID&)pDrawCaption, fake_DrawCaption);
		DetourDetach(&(PVOID&)pDrawAnimatedRects, fake_DrawAnimatedRects);
		DetourDetach(&(PVOID&)pGetMessageA, fake_GetMessageA);
		DetourDetach(&(PVOID&)pGetMessageW, fake_GetMessageW);
		DetourDetach(&(PVOID&)pTranslateMessage, fake_TranslateMessage);
		DetourDetach(&(PVOID&)pDispatchMessageA, fake_DispatchMessageA);
		DetourDetach(&(PVOID&)pDispatchMessageW, fake_DispatchMessageW);
		DetourDetach(&(PVOID&)pSetMessageQueue, fake_SetMessageQueue);
		DetourDetach(&(PVOID&)pPeekMessageA, fake_PeekMessageA);
		DetourDetach(&(PVOID&)pPeekMessageW, fake_PeekMessageW);
		DetourDetach(&(PVOID&)pRegisterHotKey, fake_RegisterHotKey);
		DetourDetach(&(PVOID&)pUnregisterHotKey, fake_UnregisterHotKey);
		DetourDetach(&(PVOID&)pExitWindowsEx, fake_ExitWindowsEx);
		DetourDetach(&(PVOID&)pSwapMouseButton, fake_SwapMouseButton);
		DetourDetach(&(PVOID&)pGetMessagePos, fake_GetMessagePos);
		DetourDetach(&(PVOID&)pGetMessageTime, fake_GetMessageTime);
		DetourDetach(&(PVOID&)pGetMessageExtraInfo, fake_GetMessageExtraInfo);
		DetourDetach(&(PVOID&)pIsWow64Message, fake_IsWow64Message);
		DetourDetach(&(PVOID&)pSetMessageExtraInfo, fake_SetMessageExtraInfo);
		DetourDetach(&(PVOID&)pSendMessageA, fake_SendMessageA);
		DetourDetach(&(PVOID&)pSendMessageW, fake_SendMessageW);
		DetourDetach(&(PVOID&)pSendMessageTimeoutA, fake_SendMessageTimeoutA);
		DetourDetach(&(PVOID&)pSendMessageTimeoutW, fake_SendMessageTimeoutW);
		DetourDetach(&(PVOID&)pSendNotifyMessageA, fake_SendNotifyMessageA);
		DetourDetach(&(PVOID&)pSendNotifyMessageW, fake_SendNotifyMessageW);
		DetourDetach(&(PVOID&)pSendMessageCallbackA, fake_SendMessageCallbackA);
		DetourDetach(&(PVOID&)pSendMessageCallbackW, fake_SendMessageCallbackW);
		DetourDetach(&(PVOID&)pBroadcastSystemMessageExA, fake_BroadcastSystemMessageExA);
		DetourDetach(&(PVOID&)pBroadcastSystemMessageExW, fake_BroadcastSystemMessageExW);
		DetourDetach(&(PVOID&)pBroadcastSystemMessageA, fake_BroadcastSystemMessageA);
		DetourDetach(&(PVOID&)pBroadcastSystemMessageW, fake_BroadcastSystemMessageW);
		DetourDetach(&(PVOID&)pBroadcastSystemMessage, fake_BroadcastSystemMessage);
		DetourDetach(&(PVOID&)pRegisterDeviceNotificationA, fake_RegisterDeviceNotificationA);
		DetourDetach(&(PVOID&)pRegisterDeviceNotificationW, fake_RegisterDeviceNotificationW);
		DetourDetach(&(PVOID&)pUnregisterDeviceNotification, fake_UnregisterDeviceNotification);
		DetourDetach(&(PVOID&)pRegisterPowerSettingNotification, fake_RegisterPowerSettingNotification);
		DetourDetach(&(PVOID&)pUnregisterPowerSettingNotification, fake_UnregisterPowerSettingNotification);
		DetourDetach(&(PVOID&)pPostMessageA, fake_PostMessageA);
		DetourDetach(&(PVOID&)pPostMessageW, fake_PostMessageW);
		DetourDetach(&(PVOID&)pPostThreadMessageA, fake_PostThreadMessageA);
		DetourDetach(&(PVOID&)pPostThreadMessageW, fake_PostThreadMessageW);
		DetourDetach(&(PVOID&)pAttachThreadInput, fake_AttachThreadInput);
		DetourDetach(&(PVOID&)pReplyMessage, fake_ReplyMessage);
		DetourDetach(&(PVOID&)pWaitMessage, fake_WaitMessage);
		DetourDetach(&(PVOID&)pWaitForInputIdle, fake_WaitForInputIdle);
		DetourDetach(&(PVOID&)pDefWindowProcA, fake_DefWindowProcA);
		DetourDetach(&(PVOID&)pDefWindowProcW, fake_DefWindowProcW);
		DetourDetach(&(PVOID&)pPostQuitMessage, fake_PostQuitMessage);
		DetourDetach(&(PVOID&)pCallWindowProcA, fake_CallWindowProcA);
		DetourDetach(&(PVOID&)pCallWindowProcW, fake_CallWindowProcW);
		DetourDetach(&(PVOID&)pInSendMessage, fake_InSendMessage);
		DetourDetach(&(PVOID&)pInSendMessageEx, fake_InSendMessageEx);
		DetourDetach(&(PVOID&)pGetDoubleClickTime, fake_GetDoubleClickTime);
		DetourDetach(&(PVOID&)pSetDoubleClickTime, fake_SetDoubleClickTime);
		DetourDetach(&(PVOID&)pRegisterClassA, fake_RegisterClassA);
		DetourDetach(&(PVOID&)pRegisterClassW, fake_RegisterClassW);
		DetourDetach(&(PVOID&)pUnregisterClassA, fake_UnregisterClassA);
		DetourDetach(&(PVOID&)pUnregisterClassW, fake_UnregisterClassW);
		DetourDetach(&(PVOID&)pGetClassInfoA, fake_GetClassInfoA);
		DetourDetach(&(PVOID&)pGetClassInfoW, fake_GetClassInfoW);
		DetourDetach(&(PVOID&)pRegisterClassExA, fake_RegisterClassExA);
		DetourDetach(&(PVOID&)pRegisterClassExW, fake_RegisterClassExW);
		DetourDetach(&(PVOID&)pGetClassInfoExA, fake_GetClassInfoExA);
		DetourDetach(&(PVOID&)pGetClassInfoExW, fake_GetClassInfoExW);
		DetourDetach(&(PVOID&)pCreateWindowExA, fake_CreateWindowExA);
		DetourDetach(&(PVOID&)pCreateWindowExW, fake_CreateWindowExW);
		DetourDetach(&(PVOID&)pIsWindow, fake_IsWindow);
		DetourDetach(&(PVOID&)pIsMenu, fake_IsMenu);
		DetourDetach(&(PVOID&)pIsChild, fake_IsChild);
		DetourDetach(&(PVOID&)pDestroyWindow, fake_DestroyWindow);
		DetourDetach(&(PVOID&)pShowWindow, fake_ShowWindow);
		DetourDetach(&(PVOID&)pAnimateWindow, fake_AnimateWindow);
		DetourDetach(&(PVOID&)pUpdateLayeredWindow, fake_UpdateLayeredWindow);
		DetourDetach(&(PVOID&)pUpdateLayeredWindowIndirect, fake_UpdateLayeredWindowIndirect);
		DetourDetach(&(PVOID&)pGetLayeredWindowAttributes, fake_GetLayeredWindowAttributes);
		DetourDetach(&(PVOID&)pPrintWindow, fake_PrintWindow);
		DetourDetach(&(PVOID&)pSetLayeredWindowAttributes, fake_SetLayeredWindowAttributes);
		DetourDetach(&(PVOID&)pShowWindowAsync, fake_ShowWindowAsync);
		DetourDetach(&(PVOID&)pFlashWindow, fake_FlashWindow);
		DetourDetach(&(PVOID&)pFlashWindowEx, fake_FlashWindowEx);
		DetourDetach(&(PVOID&)pShowOwnedPopups, fake_ShowOwnedPopups);
		DetourDetach(&(PVOID&)pOpenIcon, fake_OpenIcon);
		DetourDetach(&(PVOID&)pCloseWindow, fake_CloseWindow);
		DetourDetach(&(PVOID&)pMoveWindow, fake_MoveWindow);
		DetourDetach(&(PVOID&)pSetWindowPos, fake_SetWindowPos);
		DetourDetach(&(PVOID&)pGetWindowPlacement, fake_GetWindowPlacement);
		DetourDetach(&(PVOID&)pSetWindowPlacement, fake_SetWindowPlacement);
		DetourDetach(&(PVOID&)pGetWindowDisplayAffinity, fake_GetWindowDisplayAffinity);
		DetourDetach(&(PVOID&)pSetWindowDisplayAffinity, fake_SetWindowDisplayAffinity);
		DetourDetach(&(PVOID&)pBeginDeferWindowPos, fake_BeginDeferWindowPos);
		DetourDetach(&(PVOID&)pDeferWindowPos, fake_DeferWindowPos);
		DetourDetach(&(PVOID&)pEndDeferWindowPos, fake_EndDeferWindowPos);
		DetourDetach(&(PVOID&)pIsWindowVisible, fake_IsWindowVisible);
		DetourDetach(&(PVOID&)pIsIconic, fake_IsIconic);
		DetourDetach(&(PVOID&)pAnyPopup, fake_AnyPopup);
		DetourDetach(&(PVOID&)pBringWindowToTop, fake_BringWindowToTop);
		DetourDetach(&(PVOID&)pIsZoomed, fake_IsZoomed);
		DetourDetach(&(PVOID&)pCreateDialogParamA, fake_CreateDialogParamA);
		DetourDetach(&(PVOID&)pCreateDialogParamW, fake_CreateDialogParamW);
		DetourDetach(&(PVOID&)pCreateDialogIndirectParamA, fake_CreateDialogIndirectParamA);
		DetourDetach(&(PVOID&)pCreateDialogIndirectParamW, fake_CreateDialogIndirectParamW);
		DetourDetach(&(PVOID&)pDialogBoxParamA, fake_DialogBoxParamA);
		DetourDetach(&(PVOID&)pDialogBoxParamW, fake_DialogBoxParamW);
		DetourDetach(&(PVOID&)pDialogBoxIndirectParamA, fake_DialogBoxIndirectParamA);
		DetourDetach(&(PVOID&)pDialogBoxIndirectParamW, fake_DialogBoxIndirectParamW);
		DetourDetach(&(PVOID&)pEndDialog, fake_EndDialog);
		DetourDetach(&(PVOID&)pGetDlgItem, fake_GetDlgItem);
		DetourDetach(&(PVOID&)pSetDlgItemInt, fake_SetDlgItemInt);
		DetourDetach(&(PVOID&)pGetDlgItemInt, fake_GetDlgItemInt);
		DetourDetach(&(PVOID&)pSetDlgItemTextA, fake_SetDlgItemTextA);
		DetourDetach(&(PVOID&)pSetDlgItemTextW, fake_SetDlgItemTextW);
		DetourDetach(&(PVOID&)pGetDlgItemTextA, fake_GetDlgItemTextA);
		DetourDetach(&(PVOID&)pGetDlgItemTextW, fake_GetDlgItemTextW);
		DetourDetach(&(PVOID&)pCheckDlgButton, fake_CheckDlgButton);
		DetourDetach(&(PVOID&)pCheckRadioButton, fake_CheckRadioButton);
		DetourDetach(&(PVOID&)pIsDlgButtonChecked, fake_IsDlgButtonChecked);
		DetourDetach(&(PVOID&)pSendDlgItemMessageA, fake_SendDlgItemMessageA);
		DetourDetach(&(PVOID&)pSendDlgItemMessageW, fake_SendDlgItemMessageW);
		DetourDetach(&(PVOID&)pGetNextDlgGroupItem, fake_GetNextDlgGroupItem);
		DetourDetach(&(PVOID&)pGetNextDlgTabItem, fake_GetNextDlgTabItem);
		DetourDetach(&(PVOID&)pGetDlgCtrlID, fake_GetDlgCtrlID);
		DetourDetach(&(PVOID&)pGetDialogBaseUnits, fake_GetDialogBaseUnits);
		DetourDetach(&(PVOID&)pDefDlgProcA, fake_DefDlgProcA);
		DetourDetach(&(PVOID&)pDefDlgProcW, fake_DefDlgProcW);
		DetourDetach(&(PVOID&)pCallMsgFilterA, fake_CallMsgFilterA);
		DetourDetach(&(PVOID&)pCallMsgFilterW, fake_CallMsgFilterW);
		DetourDetach(&(PVOID&)pOpenClipboard, fake_OpenClipboard);
		DetourDetach(&(PVOID&)pCloseClipboard, fake_CloseClipboard);
		DetourDetach(&(PVOID&)pGetClipboardSequenceNumber, fake_GetClipboardSequenceNumber);
		DetourDetach(&(PVOID&)pGetClipboardOwner, fake_GetClipboardOwner);
		DetourDetach(&(PVOID&)pSetClipboardViewer, fake_SetClipboardViewer);
		DetourDetach(&(PVOID&)pGetClipboardViewer, fake_GetClipboardViewer);
		DetourDetach(&(PVOID&)pChangeClipboardChain, fake_ChangeClipboardChain);
		DetourDetach(&(PVOID&)pSetClipboardData, fake_SetClipboardData);
		DetourDetach(&(PVOID&)pGetClipboardData, fake_GetClipboardData);
		DetourDetach(&(PVOID&)pRegisterClipboardFormatA, fake_RegisterClipboardFormatA);
		DetourDetach(&(PVOID&)pRegisterClipboardFormatW, fake_RegisterClipboardFormatW);
		DetourDetach(&(PVOID&)pCountClipboardFormats, fake_CountClipboardFormats);
		DetourDetach(&(PVOID&)pEnumClipboardFormats, fake_EnumClipboardFormats);
		DetourDetach(&(PVOID&)pGetClipboardFormatNameA, fake_GetClipboardFormatNameA);
		DetourDetach(&(PVOID&)pGetClipboardFormatNameW, fake_GetClipboardFormatNameW);
		DetourDetach(&(PVOID&)pEmptyClipboard, fake_EmptyClipboard);
		DetourDetach(&(PVOID&)pIsClipboardFormatAvailable, fake_IsClipboardFormatAvailable);
		DetourDetach(&(PVOID&)pGetPriorityClipboardFormat, fake_GetPriorityClipboardFormat);
		DetourDetach(&(PVOID&)pGetOpenClipboardWindow, fake_GetOpenClipboardWindow);
		DetourDetach(&(PVOID&)pAddClipboardFormatListener, fake_AddClipboardFormatListener);
		DetourDetach(&(PVOID&)pRemoveClipboardFormatListener, fake_RemoveClipboardFormatListener);
		DetourDetach(&(PVOID&)pGetUpdatedClipboardFormats, fake_GetUpdatedClipboardFormats);
		DetourDetach(&(PVOID&)pCharToOemA, fake_CharToOemA);
		DetourDetach(&(PVOID&)pCharToOemW, fake_CharToOemW);
		DetourDetach(&(PVOID&)pOemToCharA, fake_OemToCharA);
		DetourDetach(&(PVOID&)pOemToCharW, fake_OemToCharW);
		DetourDetach(&(PVOID&)pCharToOemBuffA, fake_CharToOemBuffA);
		DetourDetach(&(PVOID&)pCharToOemBuffW, fake_CharToOemBuffW);
		DetourDetach(&(PVOID&)pOemToCharBuffA, fake_OemToCharBuffA);
		DetourDetach(&(PVOID&)pOemToCharBuffW, fake_OemToCharBuffW);
		DetourDetach(&(PVOID&)pCharUpperA, fake_CharUpperA);
		DetourDetach(&(PVOID&)pCharUpperW, fake_CharUpperW);
		DetourDetach(&(PVOID&)pCharUpperBuffA, fake_CharUpperBuffA);
		DetourDetach(&(PVOID&)pCharUpperBuffW, fake_CharUpperBuffW);
		DetourDetach(&(PVOID&)pCharLowerA, fake_CharLowerA);
		DetourDetach(&(PVOID&)pCharLowerW, fake_CharLowerW);
		DetourDetach(&(PVOID&)pCharLowerBuffA, fake_CharLowerBuffA);
		DetourDetach(&(PVOID&)pCharLowerBuffW, fake_CharLowerBuffW);
		DetourDetach(&(PVOID&)pCharNextA, fake_CharNextA);
		DetourDetach(&(PVOID&)pCharNextW, fake_CharNextW);
		DetourDetach(&(PVOID&)pCharPrevA, fake_CharPrevA);
		DetourDetach(&(PVOID&)pCharPrevW, fake_CharPrevW);
		DetourDetach(&(PVOID&)pCharNextExA, fake_CharNextExA);
		DetourDetach(&(PVOID&)pCharPrevExA, fake_CharPrevExA);
		DetourDetach(&(PVOID&)pIsCharAlphaA, fake_IsCharAlphaA);
		DetourDetach(&(PVOID&)pIsCharAlphaW, fake_IsCharAlphaW);
		DetourDetach(&(PVOID&)pIsCharAlphaNumericA, fake_IsCharAlphaNumericA);
		DetourDetach(&(PVOID&)pIsCharAlphaNumericW, fake_IsCharAlphaNumericW);
		DetourDetach(&(PVOID&)pIsCharUpperA, fake_IsCharUpperA);
		DetourDetach(&(PVOID&)pIsCharUpperW, fake_IsCharUpperW);
		DetourDetach(&(PVOID&)pIsCharLowerA, fake_IsCharLowerA);
		DetourDetach(&(PVOID&)pIsCharLowerW, fake_IsCharLowerW);
		DetourDetach(&(PVOID&)pSetFocus, fake_SetFocus);
		DetourDetach(&(PVOID&)pGetActiveWindow, fake_GetActiveWindow);
		DetourDetach(&(PVOID&)pGetFocus, fake_GetFocus);
		DetourDetach(&(PVOID&)pGetKBCodePage, fake_GetKBCodePage);
		DetourDetach(&(PVOID&)pGetKeyState, fake_GetKeyState);
		DetourDetach(&(PVOID&)pGetAsyncKeyState, fake_GetAsyncKeyState);
		DetourDetach(&(PVOID&)pGetKeyboardState, fake_GetKeyboardState);
		DetourDetach(&(PVOID&)pSetKeyboardState, fake_SetKeyboardState);
		DetourDetach(&(PVOID&)pGetKeyNameTextA, fake_GetKeyNameTextA);
		DetourDetach(&(PVOID&)pGetKeyNameTextW, fake_GetKeyNameTextW);
		DetourDetach(&(PVOID&)pGetKeyboardType, fake_GetKeyboardType);
		DetourDetach(&(PVOID&)pToAscii, fake_ToAscii);
		DetourDetach(&(PVOID&)pToAsciiEx, fake_ToAsciiEx);
		DetourDetach(&(PVOID&)pToUnicode, fake_ToUnicode);
		DetourDetach(&(PVOID&)pOemKeyScan, fake_OemKeyScan);
		DetourDetach(&(PVOID&)pVkKeyScanA, fake_VkKeyScanA);
		DetourDetach(&(PVOID&)pVkKeyScanW, fake_VkKeyScanW);
		DetourDetach(&(PVOID&)pVkKeyScanExA, fake_VkKeyScanExA);
		DetourDetach(&(PVOID&)pVkKeyScanExW, fake_VkKeyScanExW);
		DetourDetach(&(PVOID&)pkeybd_event, fake_keybd_event);
		DetourDetach(&(PVOID&)pmouse_event, fake_mouse_event);
		DetourDetach(&(PVOID&)pSendInput, fake_SendInput);
		DetourDetach(&(PVOID&)pGetTouchInputInfo, fake_GetTouchInputInfo);
		DetourDetach(&(PVOID&)pCloseTouchInputHandle, fake_CloseTouchInputHandle);
		DetourDetach(&(PVOID&)pRegisterTouchWindow, fake_RegisterTouchWindow);
		DetourDetach(&(PVOID&)pUnregisterTouchWindow, fake_UnregisterTouchWindow);
		DetourDetach(&(PVOID&)pIsTouchWindow, fake_IsTouchWindow);
		DetourDetach(&(PVOID&)pGetLastInputInfo, fake_GetLastInputInfo);
		DetourDetach(&(PVOID&)pMapVirtualKeyA, fake_MapVirtualKeyA);
		DetourDetach(&(PVOID&)pMapVirtualKeyW, fake_MapVirtualKeyW);
		DetourDetach(&(PVOID&)pMapVirtualKeyExA, fake_MapVirtualKeyExA);
		DetourDetach(&(PVOID&)pMapVirtualKeyExW, fake_MapVirtualKeyExW);
		DetourDetach(&(PVOID&)pGetInputState, fake_GetInputState);
		DetourDetach(&(PVOID&)pGetQueueStatus, fake_GetQueueStatus);
		DetourDetach(&(PVOID&)pGetCapture, fake_GetCapture);
		DetourDetach(&(PVOID&)pSetCapture, fake_SetCapture);
		DetourDetach(&(PVOID&)pReleaseCapture, fake_ReleaseCapture);
		DetourDetach(&(PVOID&)pMsgWaitForMultipleObjects, fake_MsgWaitForMultipleObjects);
		DetourDetach(&(PVOID&)pMsgWaitForMultipleObjectsEx, fake_MsgWaitForMultipleObjectsEx);
		DetourDetach(&(PVOID&)pSetTimer, fake_SetTimer);
		DetourDetach(&(PVOID&)pKillTimer, fake_KillTimer);
		DetourDetach(&(PVOID&)pIsWindowUnicode, fake_IsWindowUnicode);
		DetourDetach(&(PVOID&)pEnableWindow, fake_EnableWindow);
		DetourDetach(&(PVOID&)pIsWindowEnabled, fake_IsWindowEnabled);
		DetourDetach(&(PVOID&)pLoadAcceleratorsA, fake_LoadAcceleratorsA);
		DetourDetach(&(PVOID&)pLoadAcceleratorsW, fake_LoadAcceleratorsW);
		DetourDetach(&(PVOID&)pCreateAcceleratorTableA, fake_CreateAcceleratorTableA);
		DetourDetach(&(PVOID&)pCreateAcceleratorTableW, fake_CreateAcceleratorTableW);
		DetourDetach(&(PVOID&)pDestroyAcceleratorTable, fake_DestroyAcceleratorTable);
		DetourDetach(&(PVOID&)pCopyAcceleratorTableA, fake_CopyAcceleratorTableA);
		DetourDetach(&(PVOID&)pCopyAcceleratorTableW, fake_CopyAcceleratorTableW);
		DetourDetach(&(PVOID&)pTranslateAcceleratorA, fake_TranslateAcceleratorA);
		DetourDetach(&(PVOID&)pTranslateAcceleratorW, fake_TranslateAcceleratorW);
		DetourDetach(&(PVOID&)pGetSystemMetrics, fake_GetSystemMetrics);
		DetourDetach(&(PVOID&)pLoadMenuA, fake_LoadMenuA);
		DetourDetach(&(PVOID&)pLoadMenuW, fake_LoadMenuW);
		DetourDetach(&(PVOID&)pLoadMenuIndirectA, fake_LoadMenuIndirectA);
		DetourDetach(&(PVOID&)pLoadMenuIndirectW, fake_LoadMenuIndirectW);
		DetourDetach(&(PVOID&)pGetMenu, fake_GetMenu);
		DetourDetach(&(PVOID&)pSetMenu, fake_SetMenu);
		DetourDetach(&(PVOID&)pChangeMenuA, fake_ChangeMenuA);
		DetourDetach(&(PVOID&)pChangeMenuW, fake_ChangeMenuW);
		DetourDetach(&(PVOID&)pHiliteMenuItem, fake_HiliteMenuItem);
		DetourDetach(&(PVOID&)pGetMenuStringA, fake_GetMenuStringA);
		DetourDetach(&(PVOID&)pGetMenuStringW, fake_GetMenuStringW);
		DetourDetach(&(PVOID&)pGetMenuState, fake_GetMenuState);
		DetourDetach(&(PVOID&)pDrawMenuBar, fake_DrawMenuBar);
		DetourDetach(&(PVOID&)pGetSystemMenu, fake_GetSystemMenu);
		DetourDetach(&(PVOID&)pCreateMenu, fake_CreateMenu);
		DetourDetach(&(PVOID&)pCreatePopupMenu, fake_CreatePopupMenu);
		DetourDetach(&(PVOID&)pDestroyMenu, fake_DestroyMenu);
		DetourDetach(&(PVOID&)pCheckMenuItem, fake_CheckMenuItem);
		DetourDetach(&(PVOID&)pEnableMenuItem, fake_EnableMenuItem);
		DetourDetach(&(PVOID&)pGetSubMenu, fake_GetSubMenu);
		DetourDetach(&(PVOID&)pGetMenuItemID, fake_GetMenuItemID);
		DetourDetach(&(PVOID&)pGetMenuItemCount, fake_GetMenuItemCount);
		DetourDetach(&(PVOID&)pInsertMenuA, fake_InsertMenuA);
		DetourDetach(&(PVOID&)pInsertMenuW, fake_InsertMenuW);
		DetourDetach(&(PVOID&)pAppendMenuA, fake_AppendMenuA);
		DetourDetach(&(PVOID&)pAppendMenuW, fake_AppendMenuW);
		DetourDetach(&(PVOID&)pModifyMenuA, fake_ModifyMenuA);
		DetourDetach(&(PVOID&)pModifyMenuW, fake_ModifyMenuW);
		DetourDetach(&(PVOID&)pRemoveMenu, fake_RemoveMenu);
		DetourDetach(&(PVOID&)pDeleteMenu, fake_DeleteMenu);
		DetourDetach(&(PVOID&)pSetMenuItemBitmaps, fake_SetMenuItemBitmaps);
		DetourDetach(&(PVOID&)pGetMenuCheckMarkDimensions, fake_GetMenuCheckMarkDimensions);
		DetourDetach(&(PVOID&)pTrackPopupMenu, fake_TrackPopupMenu);
		DetourDetach(&(PVOID&)pTrackPopupMenuEx, fake_TrackPopupMenuEx);
		DetourDetach(&(PVOID&)pCalculatePopupWindowPosition, fake_CalculatePopupWindowPosition);
		DetourDetach(&(PVOID&)pGetMenuInfo, fake_GetMenuInfo);
		DetourDetach(&(PVOID&)pSetMenuInfo, fake_SetMenuInfo);
		DetourDetach(&(PVOID&)pEndMenu, fake_EndMenu);
		DetourDetach(&(PVOID&)pInsertMenuItemA, fake_InsertMenuItemA);
		DetourDetach(&(PVOID&)pInsertMenuItemW, fake_InsertMenuItemW);
		DetourDetach(&(PVOID&)pGetMenuItemInfoA, fake_GetMenuItemInfoA);
		DetourDetach(&(PVOID&)pGetMenuItemInfoW, fake_GetMenuItemInfoW);
		DetourDetach(&(PVOID&)pSetMenuItemInfoA, fake_SetMenuItemInfoA);
		DetourDetach(&(PVOID&)pSetMenuItemInfoW, fake_SetMenuItemInfoW);
		DetourDetach(&(PVOID&)pGetMenuDefaultItem, fake_GetMenuDefaultItem);
		DetourDetach(&(PVOID&)pSetMenuDefaultItem, fake_SetMenuDefaultItem);
		DetourDetach(&(PVOID&)pGetMenuItemRect, fake_GetMenuItemRect);
		DetourDetach(&(PVOID&)pMenuItemFromPoint, fake_MenuItemFromPoint);
		DetourDetach(&(PVOID&)pDragObject, fake_DragObject);
		DetourDetach(&(PVOID&)pDragDetect, fake_DragDetect);
		DetourDetach(&(PVOID&)pDrawIcon, fake_DrawIcon);
		DetourDetach(&(PVOID&)pDrawTextA, fake_DrawTextA);
		DetourDetach(&(PVOID&)pDrawTextW, fake_DrawTextW);
		DetourDetach(&(PVOID&)pDrawTextExA, fake_DrawTextExA);
		DetourDetach(&(PVOID&)pDrawTextExW, fake_DrawTextExW);
		DetourDetach(&(PVOID&)pGrayStringA, fake_GrayStringA);
		DetourDetach(&(PVOID&)pGrayStringW, fake_GrayStringW);
		DetourDetach(&(PVOID&)pDrawStateA, fake_DrawStateA);
		DetourDetach(&(PVOID&)pDrawStateW, fake_DrawStateW);
		DetourDetach(&(PVOID&)pTabbedTextOutA, fake_TabbedTextOutA);
		DetourDetach(&(PVOID&)pTabbedTextOutW, fake_TabbedTextOutW);
		DetourDetach(&(PVOID&)pGetTabbedTextExtentA, fake_GetTabbedTextExtentA);
		DetourDetach(&(PVOID&)pGetTabbedTextExtentW, fake_GetTabbedTextExtentW);
		DetourDetach(&(PVOID&)pUpdateWindow, fake_UpdateWindow);
		DetourDetach(&(PVOID&)pSetActiveWindow, fake_SetActiveWindow);
		DetourDetach(&(PVOID&)pGetForegroundWindow, fake_GetForegroundWindow);
		DetourDetach(&(PVOID&)pPaintDesktop, fake_PaintDesktop);
		DetourDetach(&(PVOID&)pSwitchToThisWindow, fake_SwitchToThisWindow);
		DetourDetach(&(PVOID&)pSetForegroundWindow, fake_SetForegroundWindow);
		DetourDetach(&(PVOID&)pAllowSetForegroundWindow, fake_AllowSetForegroundWindow);
		DetourDetach(&(PVOID&)pLockSetForegroundWindow, fake_LockSetForegroundWindow);
		DetourDetach(&(PVOID&)pWindowFromDC, fake_WindowFromDC);
		DetourDetach(&(PVOID&)pGetDC, fake_GetDC);
		DetourDetach(&(PVOID&)pGetDCEx, fake_GetDCEx);
		DetourDetach(&(PVOID&)pGetWindowDC, fake_GetWindowDC);
		DetourDetach(&(PVOID&)pReleaseDC, fake_ReleaseDC);
		DetourDetach(&(PVOID&)pBeginPaint, fake_BeginPaint);
		DetourDetach(&(PVOID&)pEndPaint, fake_EndPaint);
		DetourDetach(&(PVOID&)pGetUpdateRect, fake_GetUpdateRect);
		DetourDetach(&(PVOID&)pGetUpdateRgn, fake_GetUpdateRgn);
		DetourDetach(&(PVOID&)pSetWindowRgn, fake_SetWindowRgn);
		DetourDetach(&(PVOID&)pGetWindowRgn, fake_GetWindowRgn);
		DetourDetach(&(PVOID&)pGetWindowRgnBox, fake_GetWindowRgnBox);
		DetourDetach(&(PVOID&)pExcludeUpdateRgn, fake_ExcludeUpdateRgn);
		DetourDetach(&(PVOID&)pInvalidateRect, fake_InvalidateRect);
		DetourDetach(&(PVOID&)pValidateRect, fake_ValidateRect);
		DetourDetach(&(PVOID&)pInvalidateRgn, fake_InvalidateRgn);
		DetourDetach(&(PVOID&)pValidateRgn, fake_ValidateRgn);
		DetourDetach(&(PVOID&)pRedrawWindow, fake_RedrawWindow);
		DetourDetach(&(PVOID&)pLockWindowUpdate, fake_LockWindowUpdate);
		DetourDetach(&(PVOID&)pScrollWindow, fake_ScrollWindow);
		DetourDetach(&(PVOID&)pScrollDC, fake_ScrollDC);
		DetourDetach(&(PVOID&)pScrollWindowEx, fake_ScrollWindowEx);
		DetourDetach(&(PVOID&)pSetScrollPos, fake_SetScrollPos);
		DetourDetach(&(PVOID&)pGetScrollPos, fake_GetScrollPos);
		DetourDetach(&(PVOID&)pSetScrollRange, fake_SetScrollRange);
		DetourDetach(&(PVOID&)pGetScrollRange, fake_GetScrollRange);
		DetourDetach(&(PVOID&)pShowScrollBar, fake_ShowScrollBar);
		DetourDetach(&(PVOID&)pEnableScrollBar, fake_EnableScrollBar);
		DetourDetach(&(PVOID&)pSetPropA, fake_SetPropA);
		DetourDetach(&(PVOID&)pSetPropW, fake_SetPropW);
		DetourDetach(&(PVOID&)pGetPropA, fake_GetPropA);
		DetourDetach(&(PVOID&)pGetPropW, fake_GetPropW);
		DetourDetach(&(PVOID&)pRemovePropA, fake_RemovePropA);
		DetourDetach(&(PVOID&)pRemovePropW, fake_RemovePropW);
		DetourDetach(&(PVOID&)pEnumPropsExA, fake_EnumPropsExA);
		DetourDetach(&(PVOID&)pEnumPropsExW, fake_EnumPropsExW);
		DetourDetach(&(PVOID&)pEnumPropsA, fake_EnumPropsA);
		DetourDetach(&(PVOID&)pEnumPropsW, fake_EnumPropsW);
		DetourDetach(&(PVOID&)pSetWindowTextA, fake_SetWindowTextA);
		DetourDetach(&(PVOID&)pSetWindowTextW, fake_SetWindowTextW);
		DetourDetach(&(PVOID&)pGetWindowTextA, fake_GetWindowTextA);
		DetourDetach(&(PVOID&)pGetWindowTextW, fake_GetWindowTextW);
		DetourDetach(&(PVOID&)pGetWindowTextLengthA, fake_GetWindowTextLengthA);
		DetourDetach(&(PVOID&)pGetWindowTextLengthW, fake_GetWindowTextLengthW);
		DetourDetach(&(PVOID&)pGetClientRect, fake_GetClientRect);
		DetourDetach(&(PVOID&)pGetWindowRect, fake_GetWindowRect);
		DetourDetach(&(PVOID&)pAdjustWindowRect, fake_AdjustWindowRect);
		DetourDetach(&(PVOID&)pAdjustWindowRectEx, fake_AdjustWindowRectEx);
		DetourDetach(&(PVOID&)pSetWindowContextHelpId, fake_SetWindowContextHelpId);
		DetourDetach(&(PVOID&)pGetWindowContextHelpId, fake_GetWindowContextHelpId);
		DetourDetach(&(PVOID&)pSetMenuContextHelpId, fake_SetMenuContextHelpId);
		DetourDetach(&(PVOID&)pGetMenuContextHelpId, fake_GetMenuContextHelpId);
		DetourDetach(&(PVOID&)pMessageBoxA, fake_MessageBoxA);
		DetourDetach(&(PVOID&)pMessageBoxW, fake_MessageBoxW);
		DetourDetach(&(PVOID&)pMessageBoxExA, fake_MessageBoxExA);
		DetourDetach(&(PVOID&)pMessageBoxExW, fake_MessageBoxExW);
		DetourDetach(&(PVOID&)pMessageBoxIndirectA, fake_MessageBoxIndirectA);
		DetourDetach(&(PVOID&)pMessageBoxIndirectW, fake_MessageBoxIndirectW);
		DetourDetach(&(PVOID&)pMessageBeep, fake_MessageBeep);
		DetourDetach(&(PVOID&)pShowCursor, fake_ShowCursor);
		DetourDetach(&(PVOID&)pSetCursorPos, fake_SetCursorPos);
		DetourDetach(&(PVOID&)pSetPhysicalCursorPos, fake_SetPhysicalCursorPos);
		DetourDetach(&(PVOID&)pSetCursor, fake_SetCursor);
		DetourDetach(&(PVOID&)pGetCursorPos, fake_GetCursorPos);
		DetourDetach(&(PVOID&)pGetPhysicalCursorPos, fake_GetPhysicalCursorPos);
		DetourDetach(&(PVOID&)pClipCursor, fake_ClipCursor);
		DetourDetach(&(PVOID&)pGetClipCursor, fake_GetClipCursor);
		DetourDetach(&(PVOID&)pGetCursor, fake_GetCursor);
		DetourDetach(&(PVOID&)pCreateCaret, fake_CreateCaret);
		DetourDetach(&(PVOID&)pGetCaretBlinkTime, fake_GetCaretBlinkTime);
		DetourDetach(&(PVOID&)pSetCaretBlinkTime, fake_SetCaretBlinkTime);
		DetourDetach(&(PVOID&)pDestroyCaret, fake_DestroyCaret);
		DetourDetach(&(PVOID&)pHideCaret, fake_HideCaret);
		DetourDetach(&(PVOID&)pShowCaret, fake_ShowCaret);
		DetourDetach(&(PVOID&)pSetCaretPos, fake_SetCaretPos);
		DetourDetach(&(PVOID&)pGetCaretPos, fake_GetCaretPos);
		DetourDetach(&(PVOID&)pClientToScreen, fake_ClientToScreen);
		DetourDetach(&(PVOID&)pScreenToClient, fake_ScreenToClient);
		DetourDetach(&(PVOID&)pLogicalToPhysicalPoint, fake_LogicalToPhysicalPoint);
		DetourDetach(&(PVOID&)pPhysicalToLogicalPoint, fake_PhysicalToLogicalPoint);
		DetourDetach(&(PVOID&)pMapWindowPoints, fake_MapWindowPoints);
		DetourDetach(&(PVOID&)pWindowFromPoint, fake_WindowFromPoint);
		DetourDetach(&(PVOID&)pWindowFromPhysicalPoint, fake_WindowFromPhysicalPoint);
		DetourDetach(&(PVOID&)pChildWindowFromPoint, fake_ChildWindowFromPoint);
		DetourDetach(&(PVOID&)pChildWindowFromPointEx, fake_ChildWindowFromPointEx);
		DetourDetach(&(PVOID&)pGetSysColor, fake_GetSysColor);
		DetourDetach(&(PVOID&)pGetSysColorBrush, fake_GetSysColorBrush);
		DetourDetach(&(PVOID&)pSetSysColors, fake_SetSysColors);
		DetourDetach(&(PVOID&)pDrawFocusRect, fake_DrawFocusRect);
		DetourDetach(&(PVOID&)pFillRect, fake_FillRect);
		DetourDetach(&(PVOID&)pFrameRect, fake_FrameRect);
		DetourDetach(&(PVOID&)pInvertRect, fake_InvertRect);
		DetourDetach(&(PVOID&)pSetRect, fake_SetRect);
		DetourDetach(&(PVOID&)pSetRectEmpty, fake_SetRectEmpty);
		DetourDetach(&(PVOID&)pCopyRect, fake_CopyRect);
		DetourDetach(&(PVOID&)pInflateRect, fake_InflateRect);
		DetourDetach(&(PVOID&)pIntersectRect, fake_IntersectRect);
		DetourDetach(&(PVOID&)pUnionRect, fake_UnionRect);
		DetourDetach(&(PVOID&)pSubtractRect, fake_SubtractRect);
		DetourDetach(&(PVOID&)pOffsetRect, fake_OffsetRect);
		DetourDetach(&(PVOID&)pIsRectEmpty, fake_IsRectEmpty);
		DetourDetach(&(PVOID&)pEqualRect, fake_EqualRect);
		DetourDetach(&(PVOID&)pPtInRect, fake_PtInRect);
		DetourDetach(&(PVOID&)pGetWindowWord, fake_GetWindowWord);
		DetourDetach(&(PVOID&)pSetWindowWord, fake_SetWindowWord);
		DetourDetach(&(PVOID&)pGetWindowLongA, fake_GetWindowLongA);
		DetourDetach(&(PVOID&)pGetWindowLongW, fake_GetWindowLongW);
		DetourDetach(&(PVOID&)pSetWindowLongA, fake_SetWindowLongA);
		DetourDetach(&(PVOID&)pSetWindowLongW, fake_SetWindowLongW);
		DetourDetach(&(PVOID&)pGetWindowLongPtrA, fake_GetWindowLongPtrA);
		DetourDetach(&(PVOID&)pGetWindowLongPtrW, fake_GetWindowLongPtrW);
		DetourDetach(&(PVOID&)pSetWindowLongPtrA, fake_SetWindowLongPtrA);
		DetourDetach(&(PVOID&)pSetWindowLongPtrW, fake_SetWindowLongPtrW);
		DetourDetach(&(PVOID&)pGetClassWord, fake_GetClassWord);
		DetourDetach(&(PVOID&)pSetClassWord, fake_SetClassWord);
		DetourDetach(&(PVOID&)pGetClassLongA, fake_GetClassLongA);
		DetourDetach(&(PVOID&)pGetClassLongW, fake_GetClassLongW);
		DetourDetach(&(PVOID&)pSetClassLongA, fake_SetClassLongA);
		DetourDetach(&(PVOID&)pSetClassLongW, fake_SetClassLongW);
		DetourDetach(&(PVOID&)pGetClassLongPtrA, fake_GetClassLongPtrA);
		DetourDetach(&(PVOID&)pGetClassLongPtrW, fake_GetClassLongPtrW);
		DetourDetach(&(PVOID&)pSetClassLongPtrA, fake_SetClassLongPtrA);
		DetourDetach(&(PVOID&)pSetClassLongPtrW, fake_SetClassLongPtrW);
		DetourDetach(&(PVOID&)pGetProcessDefaultLayout, fake_GetProcessDefaultLayout);
		DetourDetach(&(PVOID&)pSetProcessDefaultLayout, fake_SetProcessDefaultLayout);
		DetourDetach(&(PVOID&)pGetDesktopWindow, fake_GetDesktopWindow);
		DetourDetach(&(PVOID&)pGetParent, fake_GetParent);
		DetourDetach(&(PVOID&)pSetParent, fake_SetParent);
		DetourDetach(&(PVOID&)pEnumChildWindows, fake_EnumChildWindows);
		DetourDetach(&(PVOID&)pFindWindowA, fake_FindWindowA);
		DetourDetach(&(PVOID&)pFindWindowW, fake_FindWindowW);
		DetourDetach(&(PVOID&)pFindWindowExA, fake_FindWindowExA);
		DetourDetach(&(PVOID&)pFindWindowExW, fake_FindWindowExW);
		DetourDetach(&(PVOID&)pGetShellWindow, fake_GetShellWindow);
		DetourDetach(&(PVOID&)pRegisterShellHookWindow, fake_RegisterShellHookWindow);
		DetourDetach(&(PVOID&)pDeregisterShellHookWindow, fake_DeregisterShellHookWindow);
		DetourDetach(&(PVOID&)pEnumWindows, fake_EnumWindows);
		DetourDetach(&(PVOID&)pEnumThreadWindows, fake_EnumThreadWindows);
		DetourDetach(&(PVOID&)pGetClassNameA, fake_GetClassNameA);
		DetourDetach(&(PVOID&)pGetClassNameW, fake_GetClassNameW);
		DetourDetach(&(PVOID&)pGetTopWindow, fake_GetTopWindow);
		DetourDetach(&(PVOID&)pGetWindowThreadProcessId, fake_GetWindowThreadProcessId);
		DetourDetach(&(PVOID&)pIsGUIThread, fake_IsGUIThread);
		DetourDetach(&(PVOID&)pGetLastActivePopup, fake_GetLastActivePopup);
		DetourDetach(&(PVOID&)pGetWindow, fake_GetWindow);
		DetourDetach(&(PVOID&)pSetWindowsHookA, fake_SetWindowsHookA);
		DetourDetach(&(PVOID&)pSetWindowsHookW, fake_SetWindowsHookW);
		DetourDetach(&(PVOID&)pUnhookWindowsHook, fake_UnhookWindowsHook);
		DetourDetach(&(PVOID&)pSetWindowsHookExA, fake_SetWindowsHookExA);
		DetourDetach(&(PVOID&)pSetWindowsHookExW, fake_SetWindowsHookExW);
		DetourDetach(&(PVOID&)pUnhookWindowsHookEx, fake_UnhookWindowsHookEx);
		DetourDetach(&(PVOID&)pCallNextHookEx, fake_CallNextHookEx);
		DetourDetach(&(PVOID&)pCheckMenuRadioItem, fake_CheckMenuRadioItem);
		DetourDetach(&(PVOID&)pLoadBitmapA, fake_LoadBitmapA);
		DetourDetach(&(PVOID&)pLoadBitmapW, fake_LoadBitmapW);
		DetourDetach(&(PVOID&)pLoadCursorA, fake_LoadCursorA);
		DetourDetach(&(PVOID&)pLoadCursorW, fake_LoadCursorW);
		DetourDetach(&(PVOID&)pLoadCursorFromFileA, fake_LoadCursorFromFileA);
		DetourDetach(&(PVOID&)pLoadCursorFromFileW, fake_LoadCursorFromFileW);
		DetourDetach(&(PVOID&)pCreateCursor, fake_CreateCursor);
		DetourDetach(&(PVOID&)pDestroyCursor, fake_DestroyCursor);
		DetourDetach(&(PVOID&)pSetSystemCursor, fake_SetSystemCursor);
		DetourDetach(&(PVOID&)pLoadIconA, fake_LoadIconA);
		DetourDetach(&(PVOID&)pLoadIconW, fake_LoadIconW);
		DetourDetach(&(PVOID&)pPrivateExtractIconsA, fake_PrivateExtractIconsA);
		DetourDetach(&(PVOID&)pPrivateExtractIconsW, fake_PrivateExtractIconsW);
		DetourDetach(&(PVOID&)pCreateIcon, fake_CreateIcon);
		DetourDetach(&(PVOID&)pDestroyIcon, fake_DestroyIcon);
		DetourDetach(&(PVOID&)pLookupIconIdFromDirectory, fake_LookupIconIdFromDirectory);
		DetourDetach(&(PVOID&)pLookupIconIdFromDirectoryEx, fake_LookupIconIdFromDirectoryEx);
		DetourDetach(&(PVOID&)pCreateIconFromResource, fake_CreateIconFromResource);
		DetourDetach(&(PVOID&)pCreateIconFromResourceEx, fake_CreateIconFromResourceEx);
		DetourDetach(&(PVOID&)pLoadImageA, fake_LoadImageA);
		DetourDetach(&(PVOID&)pLoadImageW, fake_LoadImageW);
		DetourDetach(&(PVOID&)pCopyImage, fake_CopyImage);
		DetourDetach(&(PVOID&)pCreateIconIndirect, fake_CreateIconIndirect);
		DetourDetach(&(PVOID&)pCopyIcon, fake_CopyIcon);
		DetourDetach(&(PVOID&)pGetIconInfo, fake_GetIconInfo);
		DetourDetach(&(PVOID&)pGetIconInfoExA, fake_GetIconInfoExA);
		DetourDetach(&(PVOID&)pGetIconInfoExW, fake_GetIconInfoExW);
		DetourDetach(&(PVOID&)pLoadStringA, fake_LoadStringA);
		DetourDetach(&(PVOID&)pLoadStringW, fake_LoadStringW);
		DetourDetach(&(PVOID&)pIsDialogMessageA, fake_IsDialogMessageA);
		DetourDetach(&(PVOID&)pIsDialogMessageW, fake_IsDialogMessageW);
		DetourDetach(&(PVOID&)pMapDialogRect, fake_MapDialogRect);
		DetourDetach(&(PVOID&)pDlgDirListA, fake_DlgDirListA);
		DetourDetach(&(PVOID&)pDlgDirListW, fake_DlgDirListW);
		DetourDetach(&(PVOID&)pDlgDirSelectExA, fake_DlgDirSelectExA);
		DetourDetach(&(PVOID&)pDlgDirSelectExW, fake_DlgDirSelectExW);
		DetourDetach(&(PVOID&)pDlgDirListComboBoxA, fake_DlgDirListComboBoxA);
		DetourDetach(&(PVOID&)pDlgDirListComboBoxW, fake_DlgDirListComboBoxW);
		DetourDetach(&(PVOID&)pDlgDirSelectComboBoxExA, fake_DlgDirSelectComboBoxExA);
		DetourDetach(&(PVOID&)pDlgDirSelectComboBoxExW, fake_DlgDirSelectComboBoxExW);
		DetourDetach(&(PVOID&)pSetScrollInfo, fake_SetScrollInfo);
		DetourDetach(&(PVOID&)pGetScrollInfo, fake_GetScrollInfo);
		DetourDetach(&(PVOID&)pDefFrameProcA, fake_DefFrameProcA);
		DetourDetach(&(PVOID&)pDefFrameProcW, fake_DefFrameProcW);
		DetourDetach(&(PVOID&)pDefMDIChildProcA, fake_DefMDIChildProcA);
		DetourDetach(&(PVOID&)pDefMDIChildProcW, fake_DefMDIChildProcW);
		DetourDetach(&(PVOID&)pTranslateMDISysAccel, fake_TranslateMDISysAccel);
		DetourDetach(&(PVOID&)pArrangeIconicWindows, fake_ArrangeIconicWindows);
		DetourDetach(&(PVOID&)pCreateMDIWindowA, fake_CreateMDIWindowA);
		DetourDetach(&(PVOID&)pCreateMDIWindowW, fake_CreateMDIWindowW);
		DetourDetach(&(PVOID&)pTileWindows, fake_TileWindows);
		DetourDetach(&(PVOID&)pCascadeWindows, fake_CascadeWindows);
		DetourDetach(&(PVOID&)pWinHelpA, fake_WinHelpA);
		DetourDetach(&(PVOID&)pWinHelpW, fake_WinHelpW);
		DetourDetach(&(PVOID&)pGetGuiResources, fake_GetGuiResources);
		DetourDetach(&(PVOID&)pChangeDisplaySettingsA, fake_ChangeDisplaySettingsA);
		DetourDetach(&(PVOID&)pChangeDisplaySettingsW, fake_ChangeDisplaySettingsW);
		DetourDetach(&(PVOID&)pChangeDisplaySettingsExA, fake_ChangeDisplaySettingsExA);
		DetourDetach(&(PVOID&)pChangeDisplaySettingsExW, fake_ChangeDisplaySettingsExW);
		DetourDetach(&(PVOID&)pEnumDisplaySettingsA, fake_EnumDisplaySettingsA);
		DetourDetach(&(PVOID&)pEnumDisplaySettingsW, fake_EnumDisplaySettingsW);
		DetourDetach(&(PVOID&)pEnumDisplaySettingsExA, fake_EnumDisplaySettingsExA);
		DetourDetach(&(PVOID&)pEnumDisplaySettingsExW, fake_EnumDisplaySettingsExW);
		DetourDetach(&(PVOID&)pEnumDisplayDevicesA, fake_EnumDisplayDevicesA);
		DetourDetach(&(PVOID&)pEnumDisplayDevicesW, fake_EnumDisplayDevicesW);
		DetourDetach(&(PVOID&)pGetDisplayConfigBufferSizes, fake_GetDisplayConfigBufferSizes);
		DetourDetach(&(PVOID&)pSetDisplayConfig, fake_SetDisplayConfig);
		DetourDetach(&(PVOID&)pQueryDisplayConfig, fake_QueryDisplayConfig);
		DetourDetach(&(PVOID&)pDisplayConfigGetDeviceInfo, fake_DisplayConfigGetDeviceInfo);
		DetourDetach(&(PVOID&)pDisplayConfigSetDeviceInfo, fake_DisplayConfigSetDeviceInfo);
		DetourDetach(&(PVOID&)pSystemParametersInfoA, fake_SystemParametersInfoA);
		DetourDetach(&(PVOID&)pSystemParametersInfoW, fake_SystemParametersInfoW);
		DetourDetach(&(PVOID&)pSoundSentry, fake_SoundSentry);
		DetourDetach(&(PVOID&)pSetDebugErrorLevel, fake_SetDebugErrorLevel);
		DetourDetach(&(PVOID&)pSetLastErrorEx, fake_SetLastErrorEx);
		DetourDetach(&(PVOID&)pInternalGetWindowText, fake_InternalGetWindowText);
		DetourDetach(&(PVOID&)pCancelShutdown, fake_CancelShutdown);
		DetourDetach(&(PVOID&)pMonitorFromPoint, fake_MonitorFromPoint);
		DetourDetach(&(PVOID&)pMonitorFromRect, fake_MonitorFromRect);
		DetourDetach(&(PVOID&)pMonitorFromWindow, fake_MonitorFromWindow);
		DetourDetach(&(PVOID&)pGetMonitorInfoA, fake_GetMonitorInfoA);
		DetourDetach(&(PVOID&)pGetMonitorInfoW, fake_GetMonitorInfoW);
		DetourDetach(&(PVOID&)pEnumDisplayMonitors, fake_EnumDisplayMonitors);
		DetourDetach(&(PVOID&)pNotifyWinEvent, fake_NotifyWinEvent);
		DetourDetach(&(PVOID&)pSetWinEventHook, fake_SetWinEventHook);
		DetourDetach(&(PVOID&)pIsWinEventHookInstalled, fake_IsWinEventHookInstalled);
		DetourDetach(&(PVOID&)pUnhookWinEvent, fake_UnhookWinEvent);
		DetourDetach(&(PVOID&)pGetGUIThreadInfo, fake_GetGUIThreadInfo);
		DetourDetach(&(PVOID&)pBlockInput, fake_BlockInput);
		DetourDetach(&(PVOID&)pSetProcessDPIAware, fake_SetProcessDPIAware);
		DetourDetach(&(PVOID&)pIsProcessDPIAware, fake_IsProcessDPIAware);
		DetourDetach(&(PVOID&)pGetWindowModuleFileNameA, fake_GetWindowModuleFileNameA);
		DetourDetach(&(PVOID&)pGetWindowModuleFileNameW, fake_GetWindowModuleFileNameW);
		DetourDetach(&(PVOID&)pGetCursorInfo, fake_GetCursorInfo);
		DetourDetach(&(PVOID&)pGetWindowInfo, fake_GetWindowInfo);
		DetourDetach(&(PVOID&)pGetTitleBarInfo, fake_GetTitleBarInfo);
		DetourDetach(&(PVOID&)pGetMenuBarInfo, fake_GetMenuBarInfo);
		DetourDetach(&(PVOID&)pGetScrollBarInfo, fake_GetScrollBarInfo);
		DetourDetach(&(PVOID&)pGetComboBoxInfo, fake_GetComboBoxInfo);
		DetourDetach(&(PVOID&)pGetAncestor, fake_GetAncestor);
		DetourDetach(&(PVOID&)pRealChildWindowFromPoint, fake_RealChildWindowFromPoint);
		DetourDetach(&(PVOID&)pRealGetWindowClassA, fake_RealGetWindowClassA);
		DetourDetach(&(PVOID&)pRealGetWindowClassW, fake_RealGetWindowClassW);
		DetourDetach(&(PVOID&)pGetAltTabInfoA, fake_GetAltTabInfoA);
		DetourDetach(&(PVOID&)pGetAltTabInfoW, fake_GetAltTabInfoW);
		DetourDetach(&(PVOID&)pGetListBoxInfo, fake_GetListBoxInfo);
		DetourDetach(&(PVOID&)pLockWorkStation, fake_LockWorkStation);
		DetourDetach(&(PVOID&)pUserHandleGrantAccess, fake_UserHandleGrantAccess);
		DetourDetach(&(PVOID&)pGetRawInputData, fake_GetRawInputData);
		DetourDetach(&(PVOID&)pGetRawInputDeviceInfoA, fake_GetRawInputDeviceInfoA);
		DetourDetach(&(PVOID&)pGetRawInputDeviceInfoW, fake_GetRawInputDeviceInfoW);
		DetourDetach(&(PVOID&)pGetRawInputBuffer, fake_GetRawInputBuffer);
		DetourDetach(&(PVOID&)pRegisterRawInputDevices, fake_RegisterRawInputDevices);
		DetourDetach(&(PVOID&)pGetRegisteredRawInputDevices, fake_GetRegisteredRawInputDevices);
		DetourDetach(&(PVOID&)pGetRawInputDeviceList, fake_GetRawInputDeviceList);
		DetourDetach(&(PVOID&)pDefRawInputProc, fake_DefRawInputProc);
		DetourDetach(&(PVOID&)pChangeWindowMessageFilter, fake_ChangeWindowMessageFilter);
		DetourDetach(&(PVOID&)pChangeWindowMessageFilterEx, fake_ChangeWindowMessageFilterEx);
		DetourDetach(&(PVOID&)pGetGestureInfo, fake_GetGestureInfo);
		DetourDetach(&(PVOID&)pGetGestureExtraArgs, fake_GetGestureExtraArgs);
		DetourDetach(&(PVOID&)pCloseGestureInfoHandle, fake_CloseGestureInfoHandle);
		DetourDetach(&(PVOID&)pSetGestureConfig, fake_SetGestureConfig);
		DetourDetach(&(PVOID&)pGetGestureConfig, fake_GetGestureConfig);
		DetourDetach(&(PVOID&)pShutdownBlockReasonCreate, fake_ShutdownBlockReasonCreate);
		DetourDetach(&(PVOID&)pShutdownBlockReasonQuery, fake_ShutdownBlockReasonQuery);
		DetourDetach(&(PVOID&)pShutdownBlockReasonDestroy, fake_ShutdownBlockReasonDestroy);
 
        DetourTransactionCommit();  
    }  
    return TRUE;  
}  
