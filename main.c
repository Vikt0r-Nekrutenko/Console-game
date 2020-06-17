#include "window.h"
#include "renderer.h"
#include "player.h"

#define CONSOLE_BULLET_DEF_VELOCITY 0.01f

struct ConsoleBullet {
    float px, py;
    float dx, dy;
    BOOL isActive;
} bullet;

void ConsoleBulletUpdate(ConsoleRenderer *rend, const float deltaTime)
{
    if (bullet.isActive == TRUE) {
        if (bullet.dy < bullet.py) {
            bullet.py -= CONSOLE_BULLET_DEF_VELOCITY;
        }
        if (bullet.dy > bullet.py) {
            bullet.py += CONSOLE_BULLET_DEF_VELOCITY;
        }
        if (bullet.dx < bullet.px) {
            bullet.px -= CONSOLE_BULLET_DEF_VELOCITY;
        }
        if (bullet.dx > bullet.px) {
            bullet.px += CONSOLE_BULLET_DEF_VELOCITY;
        }
        ConsoleRendererPutPixel(rend, bullet.px, bullet.py, 7, FG_YELLOW);
    }
}

void ConsoleWindowUpdateProc(ConsoleWindow *wnd, const float deltaTime)
{
    ConsolePlayerUpdate(wnd->_rend);
    ConsoleBulletUpdate(wnd->_rend, deltaTime);
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
    if (mer->dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
        bullet.px = player._px; bullet.py = player._py;
        bullet.dx = mer->dwMousePosition.X; bullet.dy = mer->dwMousePosition.Y;
        bullet.isActive = TRUE;
    }
}

int main()
{
    ConsoleWindow *window = ConsoleWindowCreate(FALSE);
    ConsolePlayerCreate(40.f, 40.f);
    return ConsoleWindowProc(window);
}
