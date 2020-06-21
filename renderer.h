#ifndef RENDERER_H
#define RENDERER_H

#include "window.h"
#include "utils.h"

typedef struct _ConsoleRenderer {
    CHAR_INFO *_array;
    COORD      _size;
} ConsoleRenderer;

ConsoleRenderer *ConsoleRendererCreate(const ConsoleWindow *wnd);

void ConsoleRendererDelete(ConsoleRenderer *rend);

void ConsoleRendererClear(ConsoleRenderer *rend);

void ConsoleRendererPresent(ConsoleWindow *wnd, ConsoleRenderer *rend);

void ConsoleRendererPutPixel(ConsoleRenderer *rend, const float x, const float y, const uint8_t sym, const ConsoleColor col);

void ConsoleRendererDrawText(ConsoleRenderer *rend, const short x, const short y, const char *text, const ConsoleColor col);

void ConsoleRendererDrawNumber(ConsoleRenderer *rend, const short x, const short y, const int number, const ConsoleColor col);

#endif // RENDERER_H
