#include "window.h"
#include "renderer.h"
#include "player.h"
#include "weapon.h"

CG_Player *player;

void ConsoleWindowUpdateProc(ConsoleWindow *wnd, const float deltaTime)
{
    CG_PlayerUpdate(wnd->_rend, player, deltaTime);
    ConsoleRendererDrawNumber(wnd->_rend, 0, 0, ((CG_Pistol *)player->_weapon)->_currentBullet, FG_WHITE);
}

void ConsoleWindowKeyEventProc(ConsoleWindow *wnd, const KEY_EVENT_RECORD *ker)
{
    if (ker->bKeyDown)
    {
        if (ker->wVirtualKeyCode == VK_W) {
            player->_py += -CG_PLAYER_DEF_VELOCITY;
        } else if (ker->wVirtualKeyCode == VK_A) {
            player->_px += -CG_PLAYER_DEF_VELOCITY;
        } else if (ker->wVirtualKeyCode == VK_S) {
            player->_py += +CG_PLAYER_DEF_VELOCITY;
        } else if (ker->wVirtualKeyCode == VK_D) {
            player->_px += +CG_PLAYER_DEF_VELOCITY;
        }
    }
}

void ConsoleWindowMouseEventProc(ConsoleWindow *wnd, const MOUSE_EVENT_RECORD *mer)
{
    if (mer->dwEventFlags == MOUSE_MOVED) {
        player->_angle = atan2f(player->_py - mer->dwMousePosition.Y, player->_px - mer->dwMousePosition.X) - atanf(45.f);
    } else if (mer->dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
        player->shoot(player->_weapon, player->_px, player->_py, player->_angle);
    }
}

int main()
{
    ConsoleWindow *window = ConsoleWindowCreate(FALSE);
    player = CG_PlayerCreate(40.f, 40.f);
    CG_Pistol *pistol = CG_PistolCreate();
    CG_PistolTakeTo(player, pistol);

    int result = ConsoleWindowProc(window);
    free(pistol);
    free(player);
    return result;
}
