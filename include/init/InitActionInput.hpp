/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** InitActionInput
*/

#pragma once

#include <functional>

#include "Registry.hpp"

struct ActionBinding
{
        std::function<void(Registry&)> onPress;
        std::function<void(Registry&)> onRelease;
};

std::unordered_map<std::string, ActionBinding> getActionBindings();