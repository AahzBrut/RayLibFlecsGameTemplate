#include "Application/Application.h"

#include <raylib.h>

#include "defs.h"
#include "imgui.h"
#include "rlImGui.h"
#include "Components/Components.h"
#include "Systems/Systems.h"


// ReSharper disable once CppMemberFunctionMayBeStatic
void Application::Initialize() const { // NOLINT(*-convert-member-functions-to-static)
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game template");
    InitAudioDevice();

    // SetTargetFPS(60);
    // ecsWorld.import<flecs::units>();
    // ecsWorld.import<flecs::stats>();
    // ecsWorld.set<flecs::Rest>({});

    RegisterComponents(ecsWorld);
    ecsWorld.emplace<AssetManager>();
    ecsWorld.emplace<AudioManager>();
    RegisterSystems(ecsWorld);
}

void Application::Run() {
    Initialize();
    rlImGuiSetup(true);
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.FontGlobalScale = 2.0;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        ecsWorld.progress(GetFrameTime());

        rlImGuiBegin();
        ImGui::Begin("Debug Info");
        ImGui::Text("FPS: %d", GetFPS());
        ImGui::Button("Test button");
        ImGui::End();
        rlImGuiEnd();

        EndDrawing();
    }
    rlImGuiShutdown();
    DeInitialize();
}

// ReSharper disable once CppMemberFunctionMayBeStatic
void Application::DeInitialize() { // NOLINT(*-convert-member-functions-to-static)
    CloseAudioDevice();
    CloseWindow();
}
