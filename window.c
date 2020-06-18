#include "window.h"
#include "renderer.h"

ConsoleWindow *ConsoleWindowCreate(const WINBOOL fullscreen)
{
    ConsoleWindow *wnd = (ConsoleWindow *)malloc(sizeof(ConsoleWindow));
    wnd->_wnd = GetConsoleWindow();
    wnd->_output = GetStdHandle(STD_OUTPUT_HANDLE);
    wnd->_input = GetStdHandle(STD_INPUT_HANDLE);


    CONSOLE_FONT_INFOEX cfiex;
    cfiex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(wnd->_output, FALSE, &cfiex);
    cfiex.dwFontSize.X = cfiex.dwFontSize.Y = 8;
    SetCurrentConsoleFontEx(wnd->_output, FALSE, &cfiex);

    if (fullscreen) {
        ConsoleWindowEnableFullscreen(wnd);
    } else {
        wnd->_size.X = 80; wnd->_size.Y = 60;
        ConsoleWindowSetSize(wnd, wnd->_size.X, wnd->_size.Y);
    }
    wnd->_rend = ConsoleRendererCreate(wnd);

    return wnd;
}

int ConsoleWindowProc(ConsoleWindow *wnd)
{
    INPUT_RECORD ir[32];
    DWORD n = 0;
    float dt = 0.f, elpsd_time = 0.f;
    uint64_t frames = 0ull;

    COORD fps_pos = { 0, wnd->_size.Y };
    SetConsoleCursorPosition(wnd->_output, fps_pos);

    while (TRUE)
    {
        if (elpsd_time > 1.f)
        {
            char buffer[32]; SetConsoleTitleA(itoa(frames / elpsd_time, buffer, 10));
            ConsoleWindowSecondElapsed(wnd);
            elpsd_time = frames = 0;
        }

        time_t begin = clock();

        ConsoleRendererClear(wnd->_rend);
        if (ConsoleWindowUpdateProc(wnd, dt) == FALSE) {
            return 0;
        }
        ConsoleRendererPresent(wnd, wnd->_rend);

        GetNumberOfConsoleInputEvents(wnd->_input, &n);
        if (n > 0)
        {
            ReadConsoleInputA(wnd->_input, ir, n, &n);
            for (DWORD i = 0; i < n; ++i)
            {
                switch (ir[i].EventType)
                {
                case MOUSE_EVENT:
                    ConsoleWindowMouseEventProc(wnd, &ir[i].Event.MouseEvent);
                    break;
                case KEY_EVENT:
                    if (ir[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
                    {
                        ConsoleRendererDelete(wnd->_rend);
                        free(wnd);
                        return 0;
                    }
                    ConsoleWindowKeyEventProc(wnd, &ir[i].Event.KeyEvent);
                    break;
                }
            }
        }

        dt = (clock() - begin) / 1000.f;
        elpsd_time += dt;
        ++frames;
    }
}

void ConsoleWindowSetSize(ConsoleWindow *wnd, short width, short height)
{
    CONSOLE_SCREEN_BUFFER_INFOEX csbiex;
    csbiex.cbSize = sizeof (CONSOLE_SCREEN_BUFFER_INFOEX);
    GetConsoleScreenBufferInfoEx(wnd->_output, &csbiex);
    csbiex.srWindow.Top = csbiex.srWindow.Left = 0;
    csbiex.dwSize.X = csbiex.dwMaximumWindowSize.X = csbiex.srWindow.Right = width;
    csbiex.dwSize.Y = csbiex.dwMaximumWindowSize.Y = csbiex.srWindow.Bottom = height;
    SetConsoleScreenBufferInfoEx(wnd->_output, &csbiex);
}

void ConsoleWindowEnableFullscreen(ConsoleWindow *wnd)
{
    wnd->_size = GetLargestConsoleWindowSize(wnd->_output);
    wnd->_size.X += 1; wnd->_size.Y += 2;

    ConsoleWindowSetSize(wnd, wnd->_size.X, wnd->_size.Y);

    SetWindowLongPtrA(wnd->_wnd, GWL_STYLE, WS_CHILD);
    SetWindowPos(wnd->_wnd, 0, -2, -2, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW);
}
