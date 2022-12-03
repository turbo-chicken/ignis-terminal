#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include <assert.h>
#include <wchar.h>

#define COMPILE_MULTIMON_STUBS

//#include "putty.h"
//#include "ssh.h"
//#include "terminal.h"
//#include "storage.h"
//#include "putty-rc.h"
//#include "security-api.h"
//#include "win-gui-seat.h"
//#include "tree234.h"


#ifndef UNICODE
#define UNICODE
#endif

#define BTN_TEST 0

#include <windows.h>
#include <iostream>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[]  = L"BLA";

    WNDCLASS wc = { };

    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
            0, // Optional window styles.
            CLASS_NAME, // Window class
            L"BLA1", // Window text
            WS_OVERLAPPEDWINDOW, // Window style

            // Size and position
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

            NULL, // Parent window
            NULL, // Menu
            hInstance, // Instance handle
            NULL // Additional application data
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    HWND hwndButton = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed
            L"OK",      // Button text
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles
            10,         // x position
            10,         // y position
            100,        // Button width
            40,        // Button height
            hwnd,     // Parent window
            (HMENU) BTN_TEST,       // No menu.
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);      // Pointer not needed.

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_COMMAND:
            switch (LOWORD(wParam)) {
                case BTN_TEST:
                    SetWindowTextA(hwnd, "BATTAN");
                    return 0;
            }
        case WM_LBUTTONDOWN:
            SetWindowTextA(hwnd, "You clicked the button");
            std::cout << "t";
            return 0;
        case WM_MOVING:
            std::cout << "t";
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            EndPaint(hwnd, &ps);
        }
            return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
