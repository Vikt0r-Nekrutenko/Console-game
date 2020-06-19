#include "weapon.h"

CG_Weapon *CG_WeaponCreate(const uint32_t clipSize)
{
    CG_Weapon *weapon = (CG_Weapon *)malloc(sizeof (CG_Weapon));
    weapon->_clip = (CG_Bullet *)malloc(sizeof (CG_Bullet) * clipSize);
    weapon->_clipSize = clipSize;
    weapon->_currentBullet = 0;
    return weapon;
}

void CG_PistolUpdate(ConsoleRenderer *rend, CG_Weapon *pistol, const float deltaTime)
{
    for (int i = 0; i < CG_PISTOL_DEF_CLIP_SIZE; ++i) {
        CG_BulletUpdate(rend, &pistol->_clip[i], deltaTime);
    }
}

void CG_PistolShoot(CG_Weapon *pistol, const float px, const float py, const float angle)
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
