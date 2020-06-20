#include "enemy.h"
#include "player.h"
#include "weapon.h"

CG_Enemy *CG_EnemyCreate(CG_Allocator *alloc, const COORD *borders, const float targetX, const float targetY, const float minDistanceToTarget)
{
    CG_Enemy *enemy = (CG_Enemy *)CG_AllocatorGetBlock(alloc, sizeof (CG_Enemy));
    CG_EnemyPlace(enemy, borders, targetX, targetY, minDistanceToTarget);
    enemy->_health = 100.f;
    enemy->_isDestroyed = FALSE;

    return enemy;
}

void CG_EnemyUpdate(ConsoleRenderer *rend, CG_Enemy *enemy, CG_Player *target, const float deltaTime)
{
    if (enemy->_isDestroyed == FALSE) {
        if (enemy->_px < target->_px) enemy->_px += CG_ENEMY_DEF_VELOCITY * deltaTime;
        if (enemy->_py < target->_py) enemy->_py += CG_ENEMY_DEF_VELOCITY * deltaTime;
        if (enemy->_px > target->_px) enemy->_px -= CG_ENEMY_DEF_VELOCITY * deltaTime;
        if (enemy->_py > target->_py) enemy->_py -= CG_ENEMY_DEF_VELOCITY * deltaTime;

        ConsoleRendererPutPixel(rend, enemy->_px, enemy->_py, OV_ENEMY, FG_RED);
    }
}

void CG_EnemyCollisionWithBullets(CG_Enemy *enemy, CG_Weapon *weapon)
{
    for (uint32_t i = 0; i < weapon->_clipSize; ++i) {
        if (weapon->_clip[i]._isActive == TRUE) {
            float distance = sqrtf(powf(weapon->_clip[i]._px - enemy->_px, 2.f) + powf(weapon->_clip[i]._py - enemy->_py, 2.f));
            if (distance < 1.5f) {
                enemy->_health -= CG_BULLET_DAMAGE;
                weapon->_clip[i]._isActive = FALSE;

                if (enemy->_health < 0.f) {
                    enemy->_isDestroyed = TRUE;
                }
            }
        }
    }
}

void CG_EnemyCollisionWithTarget(CG_Enemy *enemy, CG_Player *target)
{
    float distance = sqrtf(powf(target->_px - enemy->_px, 2.f) + powf(target->_py - enemy->_py, 2.f));
    if (distance < 1.5f) {
        target->_health -= CG_ENEMY_DAMAGE;
    }
}

void CG_EnemyPlace(CG_Enemy *enemy, const COORD *borders, const float targetX, const float targetY, const float minDistanceToTarget)
{
    float randX = rand() % borders->X;
    float randY = rand() % borders->Y;

    float distance = sqrtf(powf(targetX - randX, 2.f) + powf(targetY - randY, 2.f));
    while (distance < minDistanceToTarget) {
        randX = rand() % borders->X;
        randY = rand() % borders->Y;
        distance = sqrtf(powf(targetX - randX, 2.f) + powf(targetY - randY, 2.f));
    }

    enemy->_px = randX;
    enemy->_py = randY;
}
