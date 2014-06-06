#pragma once

namespace Collision
{
    enum masks
    {
        EVERYTHING      = 0x0001,
        PLAYER          = 0x0002,
        WALLS           = 0x0004,
        ENEMIES         = 0x0008,
        PLAYER_BULLETS  = 0x0010,
        ENEMIES_BULLETS = 0x0020,
        SHIELD          = 0x0040
    };
}