//
// Created by artemenko_pa on 24.06.2026.
//
#pragma once

#include <flecs.h>
#include "AssetManager/AssetManager.h"

inline void AssetsLoadSystem(const flecs::world &ecsWorld) {
    ecsWorld.system()
            .kind(flecs::OnStart)
            .run([&](flecs::iter &_) {
                const auto assetManager = &ecsWorld.get_mut<AssetManager>();
                assetManager->LoadMusic("main-theme", "./assets/music/Mercury.ogg");
                PlayMusicStream(*assetManager->GetMusic("main-theme"));
                LOG("Assets load complete.");
            });
}
