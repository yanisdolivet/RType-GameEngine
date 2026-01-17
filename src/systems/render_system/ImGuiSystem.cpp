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
    ImGui::Begin("Debug Window");
    ImGui::Text("Hello from Dear ImGui!");
    ImGui::Text("FrameRate : %.1f FPS", ImGui::GetIO().Framerate);
    ImGui::ShowDemoWindow();
    ImGui::End();

    rlImGuiEnd();
}
