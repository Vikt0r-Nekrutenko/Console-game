#ifndef BULLET_H
#define BULLET_H

#include "renderer.h"

#define CG_BULLET_DEF_VELOCITY 15.f

typedef struct _CG_Bullet {
    float px, py;
    float vx, vy;
    BOOL isActive;
} CG_Bullet;

void CG_BulletUpdate(ConsoleRenderer *rend, CG_Bullet *bullet, const float deltaTime);

#endif // BULLET_H
