#include "Application/Application.h"

#include <raylib.h>

#include "defs.h"
#include "imgui.h"
#include "imgui_internal.h"
#include "rlImGui.h"
#include "Components/Components.h"
#include "Systems/Systems.h"


// ReSharper disable once CppMemberFunctionMayBeStatic
void Application::Initialize() const { // NOLINT(*-convert-member-functions-to-static)
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game template");
    InitAudioDevice();

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
        ImGui::DockSpaceOverViewport();

        ImGui::Begin("Debug Info");

        ImGui::BeginTable("Debug values", 2, ImGuiTableFlags_Borders);
        ImGui::TableSetupColumn("Name");
        ImGui::TableSetupColumn("Value");
        ImGui::TableHeadersRow();
        ImGui::TableNextRow();
        ImGui::TableNextColumn();
        ImGui::Text("FPS");
        ImGui::TableNextColumn();
        ImGui::Text("%d", GetFPS());
        ImGui::EndTable();

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
