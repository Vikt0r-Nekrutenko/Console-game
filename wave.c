#include "wave.h"
#include "weapon.h"

void CG_WaveCreate(CG_Wave *wave, const COORD *borders, const float targetX, const float targetY, const float minDistanceToTarget) {
    for (int i = 0; i < CG_WAVE_SIZE; ++i) {
        wave->_enemies[i] = CG_EnemyCreate(borders, targetX, targetY, minDistanceToTarget);
    }
}

void CG_WaveUpdate(ConsoleRenderer *rend, CG_Wave *wave, CG_Player *target, const float deltaTime)
{
    for (int i = 0; i < CG_WAVE_SIZE; ++i) {
        if (wave->_enemies[i]->_isDestroyed == FALSE) {
            CG_EnemyCollisionWithBullets(wave->_enemies[i], ((CG_Pistol *)target->_weapon)->_clip);
            CG_EnemyCollisionWithTarget(wave->_enemies[i], target);

            CG_EnemyUpdate(rend, wave->_enemies[i], target, deltaTime);
        }
    }
}

void CG_WaveRespawnEnemies(ConsoleRenderer *rend, CG_Wave *wave, CG_Player *target)
{
    for (int i = 0; i < CG_WAVE_SIZE; ++i) {
        if (wave->_enemies[i]->_isDestroyed == TRUE) {
            wave->_enemies[i]->_isDestroyed = FALSE;
            CG_EnemyPlace(wave->_enemies[i], &rend->_size, target->_px, target->_py, 20.f);
            wave->_enemies[i]->_health = 100.f;
        }
    }
}

uint32_t CG_WaveGetAliveNumber(const CG_Wave *wave)
{
    uint32_t number = 0u;
    for (int i = 0; i < CG_WAVE_SIZE; ++i) {
        number += wave->_enemies[i]->_isDestroyed == FALSE ? 1u : 0u;
    }
    return number;
}
