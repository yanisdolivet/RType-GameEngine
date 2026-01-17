/*
** EPITECH PROJECT, 2026
** R-Type-GameEngine
** File description:
** ImGuiSystem
*/

#pragma once

#include <functional>
#include <imgui.h>
#include <vector>

#include "Registry.hpp"
#include "rlImGui.h"

class ImGuiSystem
{
    public:
        ImGuiSystem(Registry& registry);
        ~ImGuiSystem();
        void operator()(Registry& registry, double) const;

    private:
        bool* _systemEnabled;
        std::vector<std::function<void(Registry&, double)>> _systems;
};
