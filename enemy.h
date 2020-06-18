#ifndef ENEMY_H
#define ENEMY_H

#include "player.h"
#include "ammo.h"

#define CG_ENEMY_DEF_VELOCITY 3.f

typedef struct _CG_Enemy {
    float _px, _py;
    BOOL _isDestroyed;
} CG_Enemy;

void CG_EnemyUpdate(ConsoleRenderer *rend, CG_Enemy *enemy, CG_Player *target, const float deltaTime);

void CG_EnemyCollisionWithBullets(CG_Enemy *enemy, CG_Bullet *bullets);

#endif // ENEMY_H
