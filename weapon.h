#ifndef PISTOL_H
#define PISTOL_H

#include "ammo.h"
#include "player.h"

#define CONSOLE_PISTOL_DEF_CLIP_SIZE 30

typedef struct _ConsolePistol {
    struct _ConsoleBullet _clip[CONSOLE_PISTOL_DEF_CLIP_SIZE];
    int _currentBullet;
} ConsolePistol;

ConsolePistol *ConsolePistolCreate();

void ConsolePistolUpdate(ConsoleRenderer *rend, ConsolePistol *pistol, const float deltaTime);

void ConsolePistolShoot(ConsolePistol *pistol, const float px, const float py, const float angle);

void ConsolePistolTakeTo(ConsolePlayer *player, ConsolePistol *pistol);

#endif // PISTOL_H
