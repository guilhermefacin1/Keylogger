#include <stdio.h>
#include <windows.h>

HHOOK hook;

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
  PKBDLLHOOKSTRUCT kDllHook = (PKBDLLHOOKSTRUCT)lParam;
  printf("%d", kDllHook->vkCode);
  return(CallNextHookEx(hook, cod, wParam, lParam));
}
