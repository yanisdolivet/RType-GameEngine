/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** InputSystem.hpp
*/

#pragma once

#include <any>
#include <memory>
#include <raylib.h>
#include <unordered_map>
#include <vector>

#include "Controllable.hpp"
#include "IndexedZipper.hpp"
#include "Registry.hpp"

class InputSystem
{
    public:
        explicit InputSystem(
            std::shared_ptr<std::unordered_map<int, std::vector<std::function<void(Registry&)>>>> keymap,
            std::function<bool(int key)> IsKeyDown);

        void operator()(Registry& registry) const;

    private:
        std::shared_ptr<std::unordered_map<int, std::vector<std::function<void(Registry&)>>>> _keymap;
        std::function<bool(int key)> _keyDown;
};