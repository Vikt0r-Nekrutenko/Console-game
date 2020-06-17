#include "bullet.h"


void ConsoleBulletUpdate(ConsoleRenderer *rend, const float deltaTime)
{
    if (bullet.isActive == TRUE) {
        bullet.px += bullet.vx * deltaTime;
        bullet.py += bullet.vy * deltaTime;
        ConsoleRendererPutPixel(rend, bullet.px, bullet.py, 7, FG_YELLOW);
    }
}
