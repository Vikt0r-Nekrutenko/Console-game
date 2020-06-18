#include "window.h"
#include "renderer.h"
#include "player.h"
#include "pistol.h"

void ConsoleWindowUpdateProc(ConsoleWindow *wnd, const float deltaTime)
{
    ConsolePlayerUpdate(wnd->_rend, deltaTime);
    ConsoleRendererDrawNumber(wnd->_rend, 0, 0, player._pistol._currentBullet, FG_WHITE);
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
    if (mer->dwEventFlags == MOUSE_MOVED) {
        player._angle = atan2f(player._py - mer->dwMousePosition.Y, player._px - mer->dwMousePosition.X) - atanf(45.f);
    } else if (mer->dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
        ConsolePistolShoot(&player._pistol, player._px, player._py, player._angle);
    }
}

int main()
{
    ConsoleWindow *window = ConsoleWindowCreate(FALSE);
    ConsolePlayerCreate(40.f, 40.f);
    return ConsoleWindowProc(window);
}
