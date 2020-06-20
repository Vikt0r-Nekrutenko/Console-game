#include "weapon.h"
#include <assert.h>

CG_Weapon *CG_WeaponCreate(CG_Allocator *alloc, const uint32_t clipSize)
{
    CG_Weapon *weapon = (CG_Weapon *)CG_AllocatorGetBlock(alloc, sizeof (CG_Weapon));
    weapon->_clip = (CG_Bullet *)CG_AllocatorGetBlock(alloc, sizeof (CG_Bullet) * clipSize);
    weapon->_clipSize = clipSize;
    weapon->_currentBullet = 0u;
    return weapon;
}

void CG_WeaponUpdate(ConsoleRenderer *rend, CG_Weapon *weapon, const float deltaTime)
{
    for (uint32_t i = 0u; i < weapon->_clipSize; ++i) {
        CG_BulletUpdate(rend, &weapon->_clip[i], deltaTime);
    }
}

void CG_WeaponPistolShoot(CG_Weapon *pistol, const float px, const float py, const float angle)
{
    pistol->_clip[pistol->_currentBullet]._px = px;
    pistol->_clip[pistol->_currentBullet]._py = py;

    pistol->_clip[pistol->_currentBullet]._vx = CG_BULLET_DEF_VELOCITY * sinf(angle);
    pistol->_clip[pistol->_currentBullet]._vy = CG_BULLET_DEF_VELOCITY * -cosf(angle);
    pistol->_clip[pistol->_currentBullet]._isActive = TRUE;

    if (pistol->_currentBullet < CG_PISTOL_CLIP_SIZE - CG_PISTOL_SALVO_SIZE) {
        pistol->_currentBullet += CG_PISTOL_SALVO_SIZE;
    } else {
        pistol->_currentBullet = 0u;
    }
}

void CG_WeaponRifleShoot(CG_Weapon *rifle, const float px, const float py, const float angle)
{
    for (int i = 0; i < CG_RIFLE_SALVO_SIZE; ++i) {
        rifle->_clip[rifle->_currentBullet + i]._px = px;
        rifle->_clip[rifle->_currentBullet + i]._py = py;
        rifle->_clip[rifle->_currentBullet + i]._vx = (i + 1.f) * CG_BULLET_DEF_VELOCITY * sinf(angle);
        rifle->_clip[rifle->_currentBullet + i]._vy = (i + 1.f) * CG_BULLET_DEF_VELOCITY * -cosf(angle);
        rifle->_clip[rifle->_currentBullet + i]._isActive = TRUE;

        if (rifle->_currentBullet < CG_RIFLE_CLIP_SIZE - CG_RIFLE_SALVO_SIZE) {
            ++rifle->_currentBullet;
        } else {
            rifle->_currentBullet = 0u;
        }
    }
}

void CG_WeaponShotgunShoot(CG_Weapon *shotgun, const float px, const float py, const float angle)
{
    for (int i = 0; i < CG_SHOTGUN_SALVO_SIZE; ++i) {
        shotgun->_clip[shotgun->_currentBullet + i]._px = px;
        shotgun->_clip[shotgun->_currentBullet + i]._py = py;

        float angleCorrector = i - 1.f;

        if (i == 0) {
            angleCorrector += 0.8f;
        } else if (i == CG_SHOTGUN_SALVO_SIZE - 1) {
            angleCorrector -= 0.8f;
        }

        shotgun->_clip[shotgun->_currentBullet + i]._vx = CG_BULLET_DEF_VELOCITY * sinf(angle + angleCorrector);
        shotgun->_clip[shotgun->_currentBullet + i]._vy = CG_BULLET_DEF_VELOCITY * -cosf(angle + angleCorrector);
        shotgun->_clip[shotgun->_currentBullet + i]._isActive = TRUE;

        if (shotgun->_currentBullet < CG_SHOTGUN_CLIP_SIZE - CG_SHOTGUN_SALVO_SIZE) {
            ++shotgun->_currentBullet;
        } else {
            shotgun->_currentBullet = 0u;
        }
    }
}
