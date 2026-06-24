#pragma once
#include <flecs.h>

#include "Impl/AssetLoadSystem.h"
#include "Impl/PlayMusicSystem.h"
#include "Impl/RenderFPSSystem.h"


inline void RegisterSystems(const flecs::world &world) {
    AssetsLoadSystem(world);
    RenderFPSSystem(world);
    PlayMusicSystem(world);
}
