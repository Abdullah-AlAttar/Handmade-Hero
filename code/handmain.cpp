#include <iostream>

#include <string>
#include <windows.h>
#include <random>
#define IGNORE_UNUSED(x) (void)(x)

LRESULT CALLBACK MainWindowCallback(HWND window,
                                    UINT msg,
                                    WPARAM wparam,
                                    LPARAM lparam)
{
    LRESULT result = 0;
    switch (msg)
    {
    case WM_SIZE:
    {
        OutputDebugStringA("WM_SIZE\n");
    }
    break;
    case WM_DESTROY:
    {
        OutputDebugStringA("WM_DESTORY\n");
    }
    break;
    case WM_CLOSE:
    {
        OutputDebugStringA("WM_CLOSE\n");
    }
    break;
    case WM_ACTIVATEAPP:
    {
        OutputDebugStringA("WM_ACTIVATEAPP\n");
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT paint;
        HDC device_context = BeginPaint(window, &paint);
        PatBlt(device_context,
               paint.rcPaint.left,
               paint.rcPaint.top,
               paint.rcPaint.right - paint.rcPaint.left,
               paint.rcPaint.bottom - paint.rcPaint.top,
               rand()%2 ? WHITENESS : BLACKNESS);

        EndPaint(window, &paint);
    }
    default:
    {
        result = DefWindowProc(window, msg, wparam, lparam);
        // OutputDebugStringA("default\n");
    }
    break;
    }
    return result;
}

int WINAPI wWinMain(_In_ HINSTANCE hInstance,
                    _In_opt_ HINSTANCE hPrevInstance,
                    _In_ LPWSTR lpCmdLine,
                    _In_ int nShowCmd)
{
    IGNORE_UNUSED(hPrevInstance);
    IGNORE_UNUSED(lpCmdLine);
    IGNORE_UNUSED(nShowCmd);

    WNDCLASS win_class = {};

    win_class.style       = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
    win_class.lpfnWndProc = MainWindowCallback;
    win_class.hInstance   = hInstance;
    // win_class.hIcon
    // win_class.hbrBackground
    win_class.lpszClassName = L"HandmadeHeroWindowClass";

    if (RegisterClass(&win_class))
    {
        HWND window_handle = CreateWindowEx(0,
                                            win_class.lpszClassName,
                                            L"Handmade Hero",
                                            WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                                            CW_USEDEFAULT,
                                            CW_USEDEFAULT,
                                            CW_USEDEFAULT,
                                            CW_USEDEFAULT,
                                            NULL,
                                            NULL,
                                            hInstance,
                                            NULL);
        if (window_handle)
        {
            ShowWindow(window_handle, SW_SHOWDEFAULT);
            MSG message;
            for (;;)
            {
                BOOL msg_res = GetMessage(&message, 0, 0, 0);
                if (msg_res > 0)
                {
                    TranslateMessage(&message);
                    DispatchMessage(&message);
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
        }
    }
    else
    {
        // TODO: LOG
    }
    return 0;
}
