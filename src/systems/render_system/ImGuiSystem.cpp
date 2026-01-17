/*
** EPITECH PROJECT, 2026
** R-Type-GameEngine
** File description:
** ImGuiSystem
*/

#include "ImGuiSystem.hpp"

void ImGuiSystem::operator()(Registry& registry, double) const
{
    rlImGuiBegin();

    // Draw your ImGui windows
    ImGui::Begin("Game Dashboard");
    ImGui::Text("FrameRate : %.1f FPS", ImGui::GetIO().Framerate);
    ImGui::Text("Delta time : %.3f ms", 1000 * ImGui::GetIO().DeltaTime);
    ImGui::Text("Number of Entities : %zu", registry.getEntitiesCount());
    std::vector<std::function<void(Registry&, double)>>& _systems = registry.getSystems();
    ImGui::Text("Number of Systems : %zu", _systems.size());
    for (auto& system : _systems) {
        ImGui::Checkbox("System Active", nullptr); // Placeholder, as we don't have system names or states
    }
    ImGui::ShowDemoWindow();
    ImGui::End();

    rlImGuiEnd();
}
