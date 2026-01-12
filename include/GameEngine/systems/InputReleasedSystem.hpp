/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** InputReleasedSystem
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

class InputReleasedSystem
{
    public:
        explicit InputReleasedSystem(
            std::shared_ptr<std::unordered_map<int, std::vector<std::function<void(Registry&)>>>> keymap,
            std::function<bool(int)> keyReleasedFunc);

        void operator()(Registry& registry, double) const;

    private:
        std::shared_ptr<std::unordered_map<int, std::vector<std::function<void(Registry&)>>>> _keymap;
        std::function<bool(int)> _keyReleasedFunc;
};
