#include "player.h"

void ConsolePlayerCreate(const float px, const float py, const float vx, const float vy)
{
    player._px = px; player._py = py;
    player._vx = vx; player._vy = vy;
    player._angle = 0.f;
}

void ConsolePlayerWrapping(ConsoleRenderer *rend)
{
    if (player._px < 0.f) player._px += rend->_size.X - 1;
    if (player._py < 0.f) player._py += rend->_size.Y - 1;
    if (player._px >= rend->_size.X - 1) player._px -= rend->_size.X - 1;
    if (player._py >= rend->_size.Y - 1) player._py -= rend->_size.Y - 1;
}

void ConsolePlayerUpdate(ConsoleRenderer *rend, const float deltaTime)
{
    if (fabsf(player._vx) > 0.f || fabsf(player._vy) > 0.f) {
        float ax = -player._vx * CONSOLE_PLAYER_DEF_MOMENTUM;
        float ay = -player._vy * CONSOLE_PLAYER_DEF_MOMENTUM;

        player._vx += ax *deltaTime;
        player._vy += ay *deltaTime;
    }

    player._px += player._vx * deltaTime;
    player._py += player._vy * deltaTime;

    ConsolePlayerWrapping(rend);
    ConsoleRendererPutPixel(rend, player._px, player._py, 1, FG_GREEN);

    ConsoleRendererDrawNumber(rend, 0, 0, player._vx, FG_WHITE);
    ConsoleRendererDrawNumber(rend, 0, 1, player._vy, FG_WHITE);
}
