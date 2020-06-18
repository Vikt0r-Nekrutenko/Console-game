#ifndef BULLET_H
#define BULLET_H

#include "renderer.h"

#define CG_BULLET_DEF_VELOCITY 25.f
#define CG_BULLET_DAMAGE 10.f

typedef struct _CG_Bullet {
    float _px, _py;
    float _vx, _vy;
    BOOL _isActive;
} CG_Bullet;

void CG_BulletUpdate(ConsoleRenderer *rend, CG_Bullet *bullet, const float deltaTime);

#endif // BULLET_H
