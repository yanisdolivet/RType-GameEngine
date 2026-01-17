/*
** EPITECH PROJECT, 2026
** R-Type-GameEngine
** File description:
** ImGuiSystem
*/

#pragma once

#include <imgui.h>

#include "Registry.hpp"
#include "rlImGui.h"

class ImGuiSystem
{
    public:
        void operator()(Registry& registry, double) const;
};
