#ifndef BULLET_H
#define BULLET_H

#include "renderer.h"

#define CONSOLE_BULLET_DEF_VELOCITY 15.f

typedef struct _ConsoleBullet {
    float px, py;
    float vx, vy;
    BOOL isActive;
} ConsoleBullet;

void ConsoleBulletUpdate(ConsoleRenderer *rend, ConsoleBullet *bullet, const float deltaTime);

#endif // BULLET_H
