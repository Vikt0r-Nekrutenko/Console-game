#include "window.h"
#include "renderer.h"
#include "player.h"
#include "weapon.h"

#define CG_ENEMY_DEF_VELOCITY 3.f

typedef struct _CG_Enemy {
    float _px, _py;
    BOOL _isDestroyed;
} CG_Enemy;

void CG_EnemyUpdate(ConsoleRenderer *rend, CG_Enemy *enemy, CG_Player *target, const float deltaTime)
{
    if (enemy->_isDestroyed == FALSE) {
        if (enemy->_px < target->_px) enemy->_px += CG_ENEMY_DEF_VELOCITY * deltaTime;
        if (enemy->_py < target->_py) enemy->_py += CG_ENEMY_DEF_VELOCITY * deltaTime;
        if (enemy->_px > target->_px) enemy->_px -= CG_ENEMY_DEF_VELOCITY * deltaTime;
        if (enemy->_py > target->_py) enemy->_py -= CG_ENEMY_DEF_VELOCITY * deltaTime;

        ConsoleRendererPutPixel(rend, enemy->_px, enemy->_py, 2, FG_RED);
    }
}

CG_Player *player;
CG_Enemy enemy;

void ConsoleWindowSecondElapsed(ConsoleWindow *wnd)
{
    if (enemy._isDestroyed == TRUE) {
        enemy._isDestroyed = FALSE;
        enemy._px = enemy._py = 0;
    }
}

void ConsoleWindowUpdateProc(ConsoleWindow *wnd, const float deltaTime)
{
    for (int i = 0; i < CG_PISTOL_DEF_CLIP_SIZE; ++i) {
        CG_Bullet *bullet = &((CG_Pistol *)player->_weapon)->_clip[i];
        if (bullet->_isActive == TRUE) {
            float distance = sqrtf(powf(bullet->_px - enemy._px, 2.f) + powf(bullet->_py - enemy._py, 2.f));
            if (distance < 1.5f) {
                enemy._isDestroyed = TRUE;
            }
        }
    }

    CG_PlayerUpdate(wnd->_rend, player, deltaTime);
    CG_EnemyUpdate(wnd->_rend, &enemy, player, deltaTime);

    ConsoleRendererDrawText(wnd->_rend, 0, 0, "Ammo: ", FG_WHITE);
    ConsoleRendererDrawNumber(wnd->_rend, 6, 0, (((CG_Pistol *)player->_weapon)->_currentBullet - 30) * -1, FG_WHITE);
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
