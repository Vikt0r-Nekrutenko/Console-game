#include "weapon.h"

void CG_PistolUpdate(ConsoleRenderer *rend, CG_Pistol *pistol, const float deltaTime)
{
    for (int i = 0; i < CG_PISTOL_DEF_CLIP_SIZE; ++i) {
        CG_BulletUpdate(rend, &pistol->_clip[i], deltaTime);
    }
}

void CG_PistolShoot(CG_Pistol *pistol, const float px, const float py, const float angle)
{
    pistol->_clip[pistol->_currentBullet]._px = px;
    pistol->_clip[pistol->_currentBullet]._py = py;

    pistol->_clip[pistol->_currentBullet]._vx = CG_BULLET_DEF_VELOCITY * sinf(angle);
    pistol->_clip[pistol->_currentBullet]._vy = CG_BULLET_DEF_VELOCITY * -cosf(angle);
    pistol->_clip[pistol->_currentBullet]._isActive = TRUE;

    if (pistol->_currentBullet < CG_PISTOL_DEF_CLIP_SIZE - 1) {
        ++pistol->_currentBullet;
    } else {
        pistol->_currentBullet = 0;
    }
}

void CG_PistolTakeTo(CG_Player *player, CG_Pistol *pistol)
{
    player->_weapon = pistol;
    player->weaponUpdate = (CG_WeaponUpdateProc)&CG_PistolUpdate;
    player->shoot = (CG_WeaponShoot)&CG_PistolShoot;
}

CG_Pistol *CG_PistolCreate()
{
    CG_Pistol *pistol = (CG_Pistol *)malloc(sizeof (CG_Pistol));
    ZeroMemory(pistol, sizeof (CG_Pistol));
    return pistol;
}
