#include "player.h"

void ConsolePlayerCreate(const float px, const float py)
{
    player._px = px; player._py = py;
    player._angle = 0.f;
}

void ConsolePlayerWrapping(ConsoleRenderer *rend)
{
    if (player._px < 0.f) player._px += rend->_size.X - 1;
    if (player._py < 0.f) player._py += rend->_size.Y - 1;
    if (player._px >= rend->_size.X - 1) player._px -= rend->_size.X - 1;
    if (player._py >= rend->_size.Y - 1) player._py -= rend->_size.Y - 1;
}

void ConsolePlayerUpdate(ConsoleRenderer *rend)
{
    ConsolePlayerWrapping(rend);
    ConsoleRendererPutPixel(rend, player._px, player._py, 1, FG_GREEN);
}
