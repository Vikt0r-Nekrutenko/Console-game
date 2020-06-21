#ifndef COLORS_H
#define COLORS_H

typedef enum _ConsoleColor {
    FB_BLACK        = 0U,
    FG_DARK_BLUE    = 1U,
    FG_DARK_GREEN   = 2U,
    FG_DARK_CYAN    = 3U,
    FG_DARK_RED     = 4U,
    FG_DARK_MAGENTA = 5U,
    FG_DARK_YELLOW  = 6U,
    FG_GREY         = 7U,
    FG_DARK_GREY    = 8U,
    FG_BLUE         = 9U,
    FG_GREEN        = 10U,
    FG_CYAN         = 11U,
    FG_RED          = 12U,
    FG_MAGENTA      = 13U,
    FG_YELLOW       = 14U,
    FG_WHITE        = 15U,

    BG_DARK_BLUE    = 16U,
    BG_DARK_GREEN   = 32U,
    BG_DARK_CYAN    = 48U,
    BG_DARK_RED     = 64U,
    BG_DARK_MAGENTA = 80U,
    BG_DARK_YELLOW  = 96U,
    BG_GREY         = 112U,
    BG_DARK_GREY    = 128U,
    BG_BLUE         = 144U,
    BG_GREEN        = 160U,
    BG_CYAN         = 176U,
    BG_RED          = 192U,
    BG_MAGENTA      = 208U,
    BG_YELLOW       = 224U,
    BG_WHITE        = 230U,
} ConsoleColor;

#define VK_A 	0x41
#define VK_B 	0x42
#define VK_C 	0x43
#define VK_D 	0x44
#define VK_E 	0x45
#define VK_F 	0x46
#define VK_G 	0x47
#define VK_H 	0x48
#define VK_I 	0x49
#define VK_J 	0x4A
#define VK_K 	0x4B
#define VK_L 	0x4C
#define VK_M 	0x4D
#define VK_N 	0x4E
#define VK_O 	0x4F
#define VK_P 	0x50
#define VK_Q 	0x51
#define VK_R 	0x52
#define VK_S 	0x53
#define VK_T 	0x54
#define VK_U 	0x55
#define VK_V 	0x56
#define VK_W 	0x57
#define VK_X 	0x58
#define VK_Y 	0x59
#define VK_Z 	0x5A

#define VK_0 	0x30
#define VK_1 	0x31
#define VK_2 	0x32
#define VK_3 	0x33
#define VK_4 	0x34
#define VK_5 	0x35
#define VK_6 	0x36
#define VK_7 	0x37
#define VK_8 	0x38
#define VK_9 	0x39

typedef enum _CG_ObjectsView {
    OV_PLAYER   = 0x01,
    OV_ENEMY    = 0x02,
    OV_BULLET   = 0x07,
} CG_ObjectsView;

#endif // COLORS_H
