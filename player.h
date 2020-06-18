#ifndef PLAYER_H
#define PLAYER_H

#include "renderer.h"

#define CONSOLE_PLAYER_DEF_VELOCITY 1.f;

typedef void * ConsoleWeaponType;
typedef void(*ConsoleWeaponUpdateProc)(ConsoleRenderer *rend, ConsoleWeaponType *weapon, const float deltaTime);
typedef void(*ConsoleWeaponShoot)(ConsoleWeaponType *weapon, const float px, const float py, const float angle);

typedef struct _ConsolePlayer {
    ConsoleWeaponUpdateProc    weaponUpdate;
    ConsoleWeaponShoot         shoot;

    ConsoleWeaponType   _weapon;
    float               _px, _py;
    float               _angle;
} ConsolePlayer;

ConsolePlayer *ConsolePlayerCreate(const float px, const float py);

void ConsolePlayerWrapping(ConsoleRenderer *rend, ConsolePlayer *player);

void ConsolePlayerUpdate(ConsoleRenderer *rend, ConsolePlayer *player, const float deltaTime);

#endif // PLAYER_H
