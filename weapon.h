#ifndef PISTOL_H
#define PISTOL_H

#include "ammo.h"

#define CG_PISTOL_DEF_CLIP_SIZE 30

typedef struct _CG_Weapon {
    CG_Bullet  *_clip;
    uint32_t    _clipSize;
    uint32_t    _currentBullet;
} CG_Weapon;

typedef void(*CG_WeaponShootType)(CG_Weapon *, const float, const float, const float);
typedef void(*CG_WeaponUpdateProc)(ConsoleRenderer *rend, CG_Weapon *weapon, const float deltaTime);

CG_Weapon *CG_WeaponCreate(const uint32_t clipSize);

void CG_PistolUpdate(ConsoleRenderer *rend, CG_Weapon *pistol, const float deltaTime);

void CG_PistolShoot(CG_Weapon *pistol, const float px, const float py, const float angle);

#endif // PISTOL_H
