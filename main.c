#include "window.h"
#include "renderer.h"
#include "player.h"
#include "weapon.h"
#include "wave.h"

CG_Player *player;
CG_Weapon *pistol, *rifle, *shotgun;
CG_Wave wave;

void ConsoleWindowSecondElapsed(ConsoleWindow *wnd)
{
//    CG_WaveRespawnEnemies(wnd->_rend, &wave, player);
}

WINBOOL ConsoleWindowUpdateProc(ConsoleWindow *wnd, const float deltaTime)
{
    CG_PlayerUpdate(wnd->_rend, player, deltaTime);
//    CG_WaveUpdate(wnd->_rend, &wave, player, deltaTime);

//    uint32_t alived = 0u;
//    if (player->_health < 0.f) {
//        ConsoleRendererClear(wnd->_rend);
//        ConsoleRendererDrawText(wnd->_rend, (wnd->_size.X >> 1) - 5, wnd->_size.Y >> 1, "GAME OVER!", FG_WHITE);
//        ConsoleRendererPresent(wnd, wnd->_rend);
//        return FALSE;
//    } else if ((alived = CG_WaveGetAliveNumber(&wave)) == 0u) {
//        ConsoleRendererClear(wnd->_rend);
//        ConsoleRendererDrawText(wnd->_rend, (wnd->_size.X >> 1) - 4, wnd->_size.Y >> 1, "YOU WON!", FG_WHITE);
//        ConsoleRendererPresent(wnd, wnd->_rend);
//        return FALSE;
//    }

    // draw the HUD
    ConsoleRendererDrawText(wnd->_rend, 0, 0, "Ammo: ", FG_WHITE);
    ConsoleRendererDrawNumber(wnd->_rend, 6, 0, player->_weapon == NULL ? 0 : (player->_weapon->_currentBullet - player->_weapon->_clipSize) * -1, FG_WHITE);
    ConsoleRendererDrawText(wnd->_rend, 0, 1, "Health: ", FG_WHITE);
    ConsoleRendererDrawNumber(wnd->_rend, 8, 1, player->_health, FG_WHITE);
//    ConsoleRendererDrawText(wnd->_rend, 0, 2, "Alived: ", FG_WHITE);
//    ConsoleRendererDrawNumber(wnd->_rend, 8, 2, alived, FG_WHITE);

    return TRUE;
}

void ConsoleWindowKeyEventProc(ConsoleWindow *wnd, const KEY_EVENT_RECORD *ker)
{
    if (ker->bKeyDown)
    {
        if (ker->wVirtualKeyCode == VK_W) {
            player->_py += -CG_PLAYER_DEF_VELOCITY;
        } else if (ker->wVirtualKeyCode == VK_A) {
            player->_px += -CG_PLAYER_DEF_VELOCITY;
        } else if (ker->wVirtualKeyCode == VK_S) {
            player->_py += +CG_PLAYER_DEF_VELOCITY;
        } else if (ker->wVirtualKeyCode == VK_D) {
            player->_px += +CG_PLAYER_DEF_VELOCITY;
        }

        switch (ker->wVirtualKeyCode) {
        case VK_1: CG_PlayerPickupWeapon(player, pistol, CG_WeaponPistolShoot); break;
        case VK_2: CG_PlayerPickupWeapon(player, rifle, CG_WeaponRifleShoot); break;
        case VK_3: CG_PlayerPickupWeapon(player, shotgun, CG_WeaponShotgunShoot); break;
        }
    }
}

void ConsoleWindowMouseEventProc(ConsoleWindow *wnd, const MOUSE_EVENT_RECORD *mer)
{
    if (mer->dwEventFlags == MOUSE_MOVED) {
        player->_angle = atan2f(player->_py - mer->dwMousePosition.Y, player->_px - mer->dwMousePosition.X) - atanf(45.f);
    } else if (mer->dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
        CG_PlayerTakeShot(player);
    }
}

int main()
{
    ConsoleWindow *window = ConsoleWindowCreate(FALSE);
    CG_Allocator *alloc = CG_AllocatorAllocate(sizeof (CG_Player) +                         /* memory for player        */
                                               sizeof (CG_Weapon) +                         /* memory for pistol        */
                                               sizeof (CG_Bullet) * CG_PISTOL_CLIP_SIZE +   /* memory for pistol clip   */
                                               sizeof (CG_Weapon) +                         /* memory for rifle         */
                                               sizeof (CG_Bullet) * CG_RIFLE_CLIP_SIZE +    /* memory for rifle clip    */
                                               sizeof (CG_Weapon) +                         /* memory for shotgun       */
                                               sizeof (CG_Bullet) * CG_SHOTGUN_CLIP_SIZE);  /* memory for shotgun clip  */
    player = CG_PlayerCreate(alloc, 40.f, 40.f);

    pistol = CG_WeaponCreate(alloc, CG_PISTOL_CLIP_SIZE);
    rifle  = CG_WeaponCreate(alloc, CG_RIFLE_CLIP_SIZE);
    shotgun = CG_WeaponCreate(alloc, CG_SHOTGUN_CLIP_SIZE);

//    CG_WaveCreate(&wave, &window->_rend->_size, player->_px, player->_py, 20.f);
    int result = ConsoleWindowProc(window);
    free(alloc);
    return result;
//    return 0;
}
