#ifndef PISTOL_H
#define PISTOL_H

#include "bullet.h"

#define CONSOLE_PISTOL_DEF_CLIP_SIZE 30

typedef struct _ConsolePistol {
    struct ConsoleBullet _clip[CONSOLE_PISTOL_DEF_CLIP_SIZE];
    int _currentBullet;
} ConsolePistol;

void ConsolePistolUpdate(ConsoleRenderer *rend, ConsolePistol *pistol, const float deltaTime);

void ConsolePistolShoot(ConsolePistol *pistol, const float px, const float py, const float angle);

#endif // PISTOL_H
