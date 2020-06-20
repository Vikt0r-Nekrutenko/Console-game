#ifndef WAVE_H
#define WAVE_H

#include "enemy.h"

#define CG_WAVE_SIZE 5

typedef struct _CG_Wave {
    CG_Enemy *_enemies[CG_WAVE_SIZE];
} CG_Wave;

uint32_t CG_WaveGetAliveNumber(const CG_Wave *wave);

void CG_WaveCreate(CG_Wave *wave, const COORD *borders, const float targetX, const float targetY, const float minDistanceToTarget);

void CG_WaveUpdate(ConsoleRenderer *rend, CG_Wave *wave, CG_Player *target, const float deltaTime);

void CG_WaveRespawnEnemies(ConsoleRenderer *rend, CG_Wave *wave, CG_Player *target);

#endif // WAVE_H
