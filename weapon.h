#ifndef PISTOL_H
#define PISTOL_H

#include "ammo.h"
#include "allocator.h"

#define CG_PISTOL_SALVO_SIZE 1
#define CG_PISTOL_CLIP_SIZE 12

#define CG_RIFLE_SALVO_SIZE 3
#define CG_RIFLE_CLIP_SIZE  30

#define CG_SHOTGUN_SALVO_SIZE 3
#define CG_SHOTGUN_CLIP_SIZE  9

typedef struct _CG_Weapon {
    CG_Bullet  *_clip;
    uint32_t    _clipSize;
    uint32_t    _currentBullet;
} CG_Weapon;

typedef void(*CG_WeaponShootType)(CG_Weapon *, const float, const float, const float);
typedef void(*CG_WeaponUpdateProc)(ConsoleRenderer *rend, CG_Weapon *weapon, const float deltaTime);

CG_Weapon *CG_WeaponCreate(CG_Allocator *alloc, const uint32_t clipSize);

void CG_WeaponUpdate(ConsoleRenderer *rend, CG_Weapon *weapon, const float deltaTime);



void CG_WeaponPistolShoot(CG_Weapon *pistol, const float px, const float py, const float angle);

void CG_WeaponRifleShoot(CG_Weapon *rifle, const float px, const float py, const float angle);

void CG_WeaponShotgunShoot(CG_Weapon *shotgun, const float px, const float py, const float angle);

#endif // PISTOL_H
