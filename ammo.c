#include "ammo.h"

void CG_BulletUpdate(ConsoleRenderer *rend, CG_Bullet *bullet, const float deltaTime)
{
    if (bullet->_isActive == TRUE) {
        bullet->_px += bullet->_vx * deltaTime;
        bullet->_py += bullet->_vy * deltaTime;

        ConsoleRendererPutPixel(rend, bullet->_px, bullet->_py, 7, FG_YELLOW);
    }
}
