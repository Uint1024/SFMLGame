#pragma once
#include <SFML/System/Vector2.hpp>

extern float g_delta_time;
extern  sf::Vector2f  g_tile_size;
extern int g_game_time;

enum eGameState {
    kGameState_Playing,
    kGameState_Menu,
    kGameState_Editor
};

enum eObjectType {
    kObject_Wall,
    kObject_Ground,
    kObject_Door,
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
    kTexture_Door_Grey,
    kTexture_Guard,
    kTexture_Count
};


enum eMsg {
    
    kMsg_Use = 1,
    kMsg_Damage
};

enum eDirection {
    kDirection_None,
    kDirection_Up,
    kDirection_Down,
    kDirection_Left,
    kDirection_Right,
    kDirection_Count,
};

enum eObjectState {
    kObjectState_Open,
    kObjectState_Close,
    kObjectState_Locked,
    kObjectState_On,
    kObjectState_Off
};
extern eGameState g_game_state;
