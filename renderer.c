#include "renderer.h"
#include <assert.h>
#include <string.h>

ConsoleRenderer *ConsoleRendererCreate(const ConsoleWindow *wnd)
{
    ConsoleRenderer *rend = (ConsoleRenderer *)malloc(sizeof(ConsoleRenderer));
    rend->_array = (CHAR_INFO *)malloc(wnd->_size.X * wnd->_size.Y * sizeof (CHAR_INFO));
    rend->_size = wnd->_size;

    return rend;
}

void ConsoleRendererDelete(ConsoleRenderer *rend)
{
    free(rend->_array);
    free(rend);
}

void ConsoleRendererClear(ConsoleRenderer *rend)
{
    for (int i = rend->_size.X * rend->_size.Y - 1; i >= 0; --i) {
        CHAR_INFO *pix = &rend->_array[i];
        pix->Char.AsciiChar = ' ';
        pix->Attributes = FB_BLACK;
    }
}

void ConsoleRendererPresent(ConsoleWindow *wnd, ConsoleRenderer *rend)
{
    COORD offset = { 0, 0 }; SMALL_RECT srect = { 0, 0, rend->_size.X, rend->_size.Y };
    WriteConsoleOutputA(wnd->_output, rend->_array, rend->_size, offset, &srect);
}

void ConsoleRendererPutPixel(ConsoleRenderer *rend, const float x, const float y, const uint8_t sym, const ConsoleColor col)
{
    int indx = rend->_size.X * (int)y + (int)x;
    if (indx < rend->_size.X * rend->_size.Y && indx >= 0) {

//    assert(x >= 0.f && y >= 0.f);
//    assert(y < rend->_size.Y && x < rend->_size.X);

        CHAR_INFO *pix = &rend->_array[indx];
        pix->Char.AsciiChar = sym;
        pix->Attributes = col;
    }
}

void ConsoleRendererDrawText(ConsoleRenderer *rend, const short x, const short y, const char *text, const ConsoleColor col)
{
    for (int sym = strlen(text) - 1; sym >= 0; --sym) {
        ConsoleRendererPutPixel(rend, x + sym, y, text[sym], col);
    }
}

void ConsoleRendererDrawNumber(ConsoleRenderer *rend, const short x, const short y, const int number, const ConsoleColor col)
{
    char buffer[11];
    ConsoleRendererDrawText(rend, x, y, itoa(number, buffer, 10), col);
}
