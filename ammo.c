#include "ammo.h"

void CG_BulletUpdate(ConsoleRenderer *rend, CG_Bullet *bullet, const float deltaTime)
{
    if (bullet->_isActive == TRUE) {
        bullet->_px += bullet->_vx * deltaTime;
        bullet->_py += bullet->_vy * deltaTime;

        if (bullet->_px < 0.f || bullet->_px >= rend->_size.X || bullet->_py < 0.f || bullet->_py >= rend->_size.Y) {
            bullet->_isActive = FALSE;
        }

        ConsoleRendererPutPixel(rend, bullet->_px, bullet->_py, OV_BULLET, FG_YELLOW);
    }
}
