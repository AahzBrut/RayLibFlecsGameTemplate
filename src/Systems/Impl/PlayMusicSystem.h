//
// Created by artemenko_pa on 24.06.2026.
//
#pragma once

#include <flecs.h>
#include <raylib.h>

#include "AssetManager/AssetManager.h"


inline void PlayMusicSystem(const flecs::world &ecsWorld) {
    auto assetManager = &ecsWorld.get_mut<AssetManager>();

    ecsWorld.system()
        .run([assetManager](flecs::iter &) {
            const auto music = assetManager->GetMusic("main-theme");
            UpdateMusicStream(*music);
    });
}
