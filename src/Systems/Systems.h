#pragma once
#include <flecs.h>

#include "AssetLoadSystem.h"
#include "PlayMusicSystem.h"


inline void RegisterSystems(const flecs::world &world) {
    AssetsLoadSystem(world);
    PlayMusicSystem(world);
}
