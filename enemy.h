#ifndef ENEMY_H
#define ENEMY_H

#include "player.h"
#include "ammo.h"

#define CG_ENEMY_DEF_VELOCITY 2.5f
#define CG_ENEMY_DAMAGE 0.01f;

typedef struct _CG_Enemy {
    float _px, _py;
    float _health;
    BOOL _isDestroyed;
} CG_Enemy;

CG_Enemy *CG_EnemyCreate(const COORD *borders, const float targetX, const float targetY, const float minDistanceToTarget);

void CG_EnemyPlace(CG_Enemy *enemy, const COORD *borders, const float targetX, const float targetY, const float minDistanceToTarget);

void CG_EnemyUpdate(ConsoleRenderer *rend, CG_Enemy *enemy, CG_Player *target, const float deltaTime);

void CG_EnemyCollisionWithBullets(CG_Enemy *enemy, CG_Bullet *bullets);

void CG_EnemyCollisionWithTarget(CG_Enemy *enemy, CG_Player *target);

#endif // ENEMY_H
