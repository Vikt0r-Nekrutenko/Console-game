#ifndef BULLET_H
#define BULLET_H

#include "renderer.h"

#define CONSOLE_BULLET_DEF_VELOCITY 15.f

struct ConsoleBullet {
    float px, py;
    float vx, vy;
    BOOL isActive;
};

void ConsoleBulletUpdate(ConsoleRenderer *rend, struct ConsoleBullet *bullet, const float deltaTime);

#endif // BULLET_H
