#include "window.h"
#include "renderer.h"
#include "player.h"


void ConsoleWindowUpdateProc(ConsoleWindow *wnd, const float deltaTime)
{
    ConsolePlayerUpdate(wnd->_rend);
}

void ConsoleWindowKeyEventProc(ConsoleWindow *wnd, const KEY_EVENT_RECORD *ker)
{
    if (ker->bKeyDown)
    {
        if (ker->wVirtualKeyCode == VK_W) {
            player._py += -CONSOLE_PLAYER_DEF_VELOCITY;
        } else if (ker->wVirtualKeyCode == VK_A) {
            player._px += -CONSOLE_PLAYER_DEF_VELOCITY;
        } else if (ker->wVirtualKeyCode == VK_S) {
            player._py += +CONSOLE_PLAYER_DEF_VELOCITY;
        } else if (ker->wVirtualKeyCode == VK_D) {
            player._px += +CONSOLE_PLAYER_DEF_VELOCITY;
        }
    }
}

void ConsoleWindowMouseEventProc(ConsoleWindow *wnd, const MOUSE_EVENT_RECORD *mer)
{

}

int main()
{
    ConsoleWindow *window = ConsoleWindowCreate(FALSE);
    ConsolePlayerCreate(40.f, 40.f);
    return ConsoleWindowProc(window);
}
