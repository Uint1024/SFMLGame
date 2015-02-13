#pragma once
#include <SFML/System/Vector2.hpp>

extern float g_delta_time;
extern  sf::Vector2f  g_tile_size;

enum eGameState {
    kGameState_Playing,
    kGameState_Menu,
    kGameState_Editor
};

enum eObjectType {
    kObject_Wall,
    kObject_Wall_Black,
    kObject_Wall_LightGrey,
    kObject_Wall_DarkGrey,
    kObject_Wall_Blue,
    kObject_Wall_Green,
    kObject_Ground,
    kObject_Ground_Grass,
    kObject_Ground_Cement,
    kObject_Ground_Sand,
    kObject_Ground_Dirt,
    kObject_Ground_BlueCarpet,
    kObject_Ground_GreenCarpet,
    kObject_Ground_Wood,
    kObject_Guard,
    kObject_Count
};

enum eTexture {
    kTexture_Wall_Black,
    kTexture_Wall_LightGrey,
    kTexture_Wall_DarkGrey,
    kTexture_Wall_Blue,
    kTexture_Wall_Green,
    kTexture_Ground_Grass,
    kTexture_Ground_Cement,
    kTexture_Ground_Sand,
    kTexture_Ground_Dirt,
    kTexture_Ground_BlueCarpet,
    kTexture_Ground_GreenCarpet,
    kTexture_Ground_Wood,
    kTexture_Guard,
    kTexture_Count
};

enum eDirection {
    kDirection_None,
    kDirection_Up,
    kDirection_Down,
    kDirection_Left,
    kDirection_Right,
    kDirection_Count,
};

extern eGameState g_game_state;
