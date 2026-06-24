#pragma once
#include <flecs.h>


inline void RenderFPSSystem(const flecs::world &world) {
    world
            .system()
            .kind(flecs::OnStore)
            .run([](flecs::iter &) {
                const auto fpsString = std::to_string(GetFPS());
                DrawText(fpsString.c_str(), 5, 5, 32, WHITE);
            });
}
