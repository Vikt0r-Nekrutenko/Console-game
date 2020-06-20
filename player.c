#include "player.h"

CG_Player *CG_PlayerCreate(CG_Allocator *alloc, const float px, const float py)
{
    CG_Player *player = (CG_Player *)CG_AllocatorGetBlock(alloc, sizeof (CG_Player));
    player->_weapon        = NULL;
    player->weaponUpdate   = NULL;
    player->shoot          = NULL;

    player->_px     = px;
    player->_py     = py;
    player->_angle  = 0.f;
    player->_health = 100.f;
    return player;
}

void CG_EntityWrapping(ConsoleRenderer *rend, CG_Player *player)
{
    if (player->_px < 0.f) player->_px += rend->_size.X - 1;
    if (player->_py < 0.f) player->_py += rend->_size.Y - 1;
    if (player->_px >= rend->_size.X - 1) player->_px -= rend->_size.X - 1;
    if (player->_py >= rend->_size.Y - 1) player->_py -= rend->_size.Y - 1;
}

void CG_PlayerUpdate(ConsoleRenderer *rend, CG_Player *player, const float deltaTime)
{
    if (player->weaponUpdate != NULL) {
        player->weaponUpdate(rend, player->_weapon, deltaTime);
    }
    CG_EntityWrapping(rend, player);
    ConsoleRendererPutPixel(rend, player->_px, player->_py, OV_PLAYER, FG_GREEN);
}

void CG_PlayerPickupWeapon(CG_Player *player, CG_Weapon *weapon, CG_WeaponShootType type, CG_WeaponUpdateProc updateProc)
{
    player->_weapon = weapon;
    player->shoot = type;
    player->weaponUpdate = updateProc;
}
