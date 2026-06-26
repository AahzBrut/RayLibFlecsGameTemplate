#include "AssetManager/AssetManager.h"
#include "Systems/AssetLoadSystem.h"


void AssetsLoadSystem(const flecs::world &ecsWorld) {
    ecsWorld.system()
            .kind(flecs::OnStart)
            .run([&](flecs::iter &_) {
                const auto assetManager = &ecsWorld.get_mut<AssetManager>();
                assetManager->LoadMusic("main-theme", "./assets/music/Mercury.ogg");
                PlayMusicStream(*assetManager->GetMusic("main-theme"));
                LOG("Assets load complete.");
            });
}
