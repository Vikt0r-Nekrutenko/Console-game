#include "window.h"
#include "renderer.h"
#include "player.h"
#include "weapon.h"
#include "enemy.h"

CG_Player *player;
CG_Enemy enemy;

void ConsoleWindowSecondElapsed(ConsoleWindow *wnd)
{
    if (enemy._isDestroyed == TRUE) {
        enemy._isDestroyed = FALSE;
        enemy._px = enemy._py = 0;
        enemy._health = 100.f;
    }
}

WINBOOL ConsoleWindowUpdateProc(ConsoleWindow *wnd, const float deltaTime)
{
    CG_EnemyCollisionWithBullets(&enemy, ((CG_Pistol *)player->_weapon)->_clip);
    CG_EnemyCollisionWithTarget(&enemy, player);

    CG_PlayerUpdate(wnd->_rend, player, deltaTime);
    CG_EnemyUpdate(wnd->_rend, &enemy, player, deltaTime);

    if (player->_health < 0.f) {
        ConsoleRendererClear(wnd->_rend);
        ConsoleRendererDrawText(wnd->_rend, (wnd->_size.X >> 1) - 5, wnd->_size.Y >> 1, "GAME OVER!", FG_WHITE);
        ConsoleRendererPresent(wnd, wnd->_rend);
        return FALSE;
    }

    // draw the HUD
    ConsoleRendererDrawText(wnd->_rend, 0, 0, "Ammo: ", FG_WHITE);
    ConsoleRendererDrawNumber(wnd->_rend, 6, 0, (((CG_Pistol *)player->_weapon)->_currentBullet - 30) * -1, FG_WHITE);
    ConsoleRendererDrawText(wnd->_rend, 0, 1, "Health: ", FG_WHITE);
    ConsoleRendererDrawNumber(wnd->_rend, 8, 1, player->_health, FG_WHITE);

    return TRUE;
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
