#ifndef PLAYER_H
#define PLAYER_H

#include "renderer.h"
#include "weapon.h"

#define CG_PLAYER_DEF_VELOCITY 1.f;

typedef struct _CG_Player {
    CG_WeaponUpdateProc     weaponUpdate;
    CG_WeaponShootType      shoot;

    struct _CG_Weapon  *_weapon;
    float               _px, _py;
    float               _angle;
    float               _health;
} CG_Player;

CG_Player *CG_PlayerCreate(const float px, const float py);

void CG_EntityWrapping(ConsoleRenderer *rend, CG_Player *entity);

void CG_PlayerUpdate(ConsoleRenderer *rend, CG_Player *player, const float deltaTime);

void CG_PlayerPickupWeapon(CG_Player *player, CG_Weapon *weapon, CG_WeaponShootType type, CG_WeaponUpdateProc updateProc);

#endif // PLAYER_H
