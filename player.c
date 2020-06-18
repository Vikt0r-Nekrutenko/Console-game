#include "player.h"

ConsolePlayer *ConsolePlayerCreate(const float px, const float py)
{
    ConsolePlayer *player = (ConsolePlayer *)malloc(sizeof (ConsolePlayer));
    player->_weapon         = NULL;
    player->weaponUpdate   = NULL;
    player->shoot          = NULL;

    player->_px     = px;
    player->_py     = py;
    player->_angle  = 0.f;

    return player;
}

void ConsolePlayerWrapping(ConsoleRenderer *rend, ConsolePlayer *player)
{
    if (player->_px < 0.f) player->_px += rend->_size.X - 1;
    if (player->_py < 0.f) player->_py += rend->_size.Y - 1;
    if (player->_px >= rend->_size.X - 1) player->_px -= rend->_size.X - 1;
    if (player->_py >= rend->_size.Y - 1) player->_py -= rend->_size.Y - 1;
}

void ConsolePlayerUpdate(ConsoleRenderer *rend, ConsolePlayer *player, const float deltaTime)
{
    player->weaponUpdate(rend, player->_weapon, deltaTime);
    ConsolePlayerWrapping(rend, player);
    ConsoleRendererPutPixel(rend, player->_px, player->_py, 1, FG_GREEN);
}
