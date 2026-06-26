#pragma once
#include <flecs.h>
#include "AssetManager/AssetManager.h"
#include "AudioManager/AudioManager.h"


// ReSharper disable file CppExpressionWithoutSideEffects
inline void RegisterComponents(const flecs::world &ecsWorld) {
    ecsWorld.component<AssetManager>();
    ecsWorld.component<AudioManager>();
}
