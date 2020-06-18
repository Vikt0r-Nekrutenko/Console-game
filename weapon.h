#ifndef PISTOL_H
#define PISTOL_H

#include "ammo.h"
#include "player.h"

#define CG_PISTOL_DEF_CLIP_SIZE 30

typedef struct _CG_Pistol {
    struct _CG_Bullet _clip[CG_PISTOL_DEF_CLIP_SIZE];
    int _currentBullet;
} CG_Pistol;

CG_Pistol *CG_PistolCreate();

void CG_PistolUpdate(ConsoleRenderer *rend, CG_Pistol *pistol, const float deltaTime);

void CG_PistolShoot(CG_Pistol *pistol, const float px, const float py, const float angle);

void CG_PistolTakeTo(CG_Player *player, CG_Pistol *pistol);

#endif // PISTOL_H
