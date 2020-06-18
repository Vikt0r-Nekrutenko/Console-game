#ifndef PLAYER_H
#define PLAYER_H

#include "renderer.h"

#define CG_PLAYER_DEF_VELOCITY 1.f;

typedef void *CG_WeaponType;
typedef void(*CG_WeaponUpdateProc)(ConsoleRenderer *rend, CG_WeaponType *weapon, const float deltaTime);
typedef void(*CG_WeaponShoot)(CG_WeaponType *weapon, const float px, const float py, const float angle);

typedef struct _CG_Player {
    CG_WeaponUpdateProc    weaponUpdate;
    CG_WeaponShoot         shoot;

    CG_WeaponType   _weapon;
    float               _px, _py;
    float               _angle;
} CG_Player;

CG_Player *CG_PlayerCreate(const float px, const float py);

void CG_EntityWrapping(ConsoleRenderer *rend, CG_Player *entity);

void CG_PlayerUpdate(ConsoleRenderer *rend, CG_Player *player, const float deltaTime);

#endif // PLAYER_H
