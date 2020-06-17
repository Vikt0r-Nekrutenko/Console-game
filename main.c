#include "window.h"
#include "renderer.h"

float x = 0.f, y = 0.f;

void ConsoleWindowUpdateProc(ConsoleWindow *window, const float deltaTime)
{
    ConsoleRendererPutPixel(window->_rend, x += .3f, y += .3f, '@', FG_CYAN);

    if (x < 0.f) x += window->_size.X - 1;
    if (y < 0.f) y += window->_size.Y - 1;
    if (x >= window->_size.X - 1) x -= window->_size.X - 1;
    if (y >= window->_size.Y - 1) y -= window->_size.Y - 1;
}

void ConsoleWindowMouseEventProc(ConsoleWindow *window, const MOUSE_EVENT_RECORD *mer)
{

}

int main()
{
    ConsoleWindow *window = ConsoleWindowCreate(FALSE);
    return ConsoleWindowProc(window);
}
