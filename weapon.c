#include "weapon.h"

void ConsolePistolUpdate(ConsoleRenderer *rend, ConsolePistol *pistol, const float deltaTime)
{
    for (int i = 0; i < CONSOLE_PISTOL_DEF_CLIP_SIZE; ++i) {
        ConsoleBulletUpdate(rend, &pistol->_clip[i], deltaTime);
    }
}

void ConsolePistolShoot(ConsolePistol *pistol, const float px, const float py, const float angle)
{
    pistol->_clip[pistol->_currentBullet].px = px;
    pistol->_clip[pistol->_currentBullet].py = py;

    pistol->_clip[pistol->_currentBullet].vx = CONSOLE_BULLET_DEF_VELOCITY * sinf(angle);
    pistol->_clip[pistol->_currentBullet].vy = CONSOLE_BULLET_DEF_VELOCITY * -cosf(angle);
    pistol->_clip[pistol->_currentBullet].isActive = TRUE;

    if (pistol->_currentBullet < CONSOLE_PISTOL_DEF_CLIP_SIZE - 1) {
        ++pistol->_currentBullet;
    } else {
        pistol->_currentBullet = 0;
    }
}

void ConsolePistolTakeTo(ConsolePlayer *player, ConsolePistol *pistol)
{
    player->_weapon = pistol;
    player->weaponUpdate = (ConsoleWeaponUpdateProc)&ConsolePistolUpdate;
    player->shoot = (ConsoleWeaponShoot)&ConsolePistolShoot;
}

ConsolePistol *ConsolePistolCreate()
{
    ConsolePistol *pistol = (ConsolePistol *)malloc(sizeof (ConsolePistol));
    ZeroMemory(pistol, sizeof (ConsolePistol));
    return pistol;
}
