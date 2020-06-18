#include "enemy.h"
#include "player.h"
#include "weapon.h"

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

void CG_EnemyCollisionWithBullets(CG_Enemy *enemy, CG_Bullet *bullets)
{
    for (int i = 0; i < CG_PISTOL_DEF_CLIP_SIZE; ++i) {
        if (bullets[i]._isActive == TRUE) {
            float distance = sqrtf(powf(bullets[i]._px - enemy->_px, 2.f) + powf(bullets[i]._py - enemy->_py, 2.f));
            if (distance < 1.5f) {
                enemy->_isDestroyed = TRUE;
            }
        }
    }
}
