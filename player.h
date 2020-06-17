#ifndef PLAYER_H
#define PLAYER_H

#include "renderer.h"

#define CONSOLE_PLAYER_DEF_VELOCITY 1.f;

struct ConsolePlayer {
    float _px, _py;
    float _angle;
} player;

void ConsolePlayerCreate(const float px, const float py);

void ConsolePlayerWrapping(ConsoleRenderer *rend);

void ConsolePlayerUpdate(ConsoleRenderer *rend);

#endif // PLAYER_H
