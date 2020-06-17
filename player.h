#ifndef PLAYER_H
#define PLAYER_H

#include "renderer.h"

#define CONSOLE_PLAYER_DEF_MOMENTUM 4.f
#define CONSOLE_PLAYER_DEF_VELOCITY 5.f;

struct ConsolePlayer {
    float _px, _py;
    float _vx, _vy;
    float _angle;
} player;

void ConsolePlayerCreate(const float px, const float py, const float vx, const float vy);

void ConsolePlayerWrapping(ConsoleRenderer *rend);

void ConsolePlayerUpdate(ConsoleRenderer *rend, const float deltaTime);

#endif // PLAYER_H
