#include "Systems/PlayMusicSystem.h"
#include "AssetManager/AssetManager.h"


void PlayMusicSystem(const flecs::world &ecsWorld) {
    auto assetManager = &ecsWorld.get_mut<AssetManager>();

    ecsWorld.system()
        .run([assetManager](flecs::iter &) {
            const auto music = assetManager->GetMusic("main-theme");
            UpdateMusicStream(*music);
    });
}
