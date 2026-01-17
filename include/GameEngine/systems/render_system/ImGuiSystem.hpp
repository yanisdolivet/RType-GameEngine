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
        ImGuiSystem(std::vector<std::string> systemName);
        ~ImGuiSystem() = default;
        void operator()(Registry& registry, double) const;

    private:
        std::vector<std::string> _systemName;
};
