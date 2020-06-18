#ifndef PLAYER_H
#define PLAYER_H

#include "renderer.h"
#include "pistol.h"

#define CONSOLE_PLAYER_DEF_VELOCITY 1.f;

struct ConsolePlayer {
    ConsolePistol _pistol;
    float _px, _py;
    float _angle;
} player;

void ConsolePlayerCreate(const float px, const float py);

void ConsolePlayerWrapping(ConsoleRenderer *rend);

void ConsolePlayerUpdate(ConsoleRenderer *rend, const float deltaTime);

#endif // PLAYER_H
