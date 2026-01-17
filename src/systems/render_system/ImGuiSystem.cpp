/*
** EPITECH PROJECT, 2026
** R-Type-GameEngine
** File description:
** ImGuiSystem
*/

#include "ImGuiSystem.hpp"

ImGuiSystem::ImGuiSystem(std::vector<std::string> systemName) : _systemName(systemName)
{
}

void ImGuiSystem::operator()(Registry& registry, double) const
{
    rlImGuiBegin();

    // Draw your ImGui windows
    ImGui::Begin("Game Dashboard");
    ImGui::Text("FrameRate : %.1f FPS", ImGui::GetIO().Framerate);
    ImGui::Text("Delta time : %.3f ms", 1000 * ImGui::GetIO().DeltaTime);
    ImGui::Text("Number of Entities : %zu", registry.getEntitiesCount());

    // Get the number of systems
    std::size_t numSystems = registry.getAllSystem().size();
    ImGui::Text("Number of Systems : %zu", numSystems);

    // Display toggle for each system
    for (std::size_t i = 0; i < numSystems; ++i) {
        bool enabled = registry.isSystemEnabled(i);
        ImGui::PushID(static_cast<int>(i));
        if (ImGui::Checkbox(_systemName[i].c_str(), &enabled)) {
            // Toggle system on checkbox change
            if (enabled) {
                registry.enableSpecificSystem(i);
            }
            else {
                registry.disableSpecificSystem(i);
            }
        }
        ImGui::PopID();
    }

    ImGui::ShowDemoWindow();
    ImGui::End();

    rlImGuiEnd();
}
