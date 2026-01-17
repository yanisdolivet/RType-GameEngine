/*
** EPITECH PROJECT, 2026
** R-Type-GameEngine
** File description:
** ImGuiSystem
*/

#include "ImGuiSystem.hpp"

ImGuiSystem::ImGuiSystem(Registry& registry)
{
    this->_systems       = registry.getAllSystem();
    int numSystems       = static_cast<int>(this->_systems.size());
    this->_systemEnabled = new bool[numSystems];

    for (int i = 0; i < numSystems; ++i) {
        this->_systemEnabled[i] = true;
    }
}

ImGuiSystem::~ImGuiSystem()
{
    delete[] this->_systemEnabled;
}

void ImGuiSystem::operator()(Registry& registry, double) const
{
    rlImGuiBegin();

    // Draw your ImGui windows
    ImGui::Begin("Game Dashboard");
    ImGui::Text("FrameRate : %.1f FPS", ImGui::GetIO().Framerate);
    ImGui::Text("Delta time : %.3f ms", 1000 * ImGui::GetIO().DeltaTime);
    ImGui::Text("Number of Entities : %zu", registry.getEntitiesCount());
    std::size_t numSystems = this->_systems.size();
    ImGui::Text("Number of Systems : %zu", numSystems);
    for (int i = 0; i < static_cast<int>(numSystems); ++i) {
        ImGui::PushID(i);
        ImGui::Checkbox(("System " + std::to_string(i)).c_str(),
                        &this->_systemEnabled[i]); // Placeholder for system enable/disable
        ImGui::PopID();
    }
    ImGui::ShowDemoWindow();
    ImGui::End();

    rlImGuiEnd();
}
