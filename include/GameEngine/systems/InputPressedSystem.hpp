/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** InputPressedSystem.hpp
*/

#pragma once

#include <functional>
#include <memory>
#include <unordered_map>
#include <vector>

#include "ecs/Registry.hpp"

class InputPressedSystem
{
    public:
        InputPressedSystem(std::shared_ptr<std::unordered_map<int, std::vector<std::function<void(Registry&)>>>> keymap,
                           std::function<bool(int key)> IsKeyDown);
        void operator()(Registry& registry, double) const;

    private:
        std::shared_ptr<std::unordered_map<int, std::vector<std::function<void(Registry&)>>>> _keymap;
        std::function<bool(int key)> _keyDown;
};
