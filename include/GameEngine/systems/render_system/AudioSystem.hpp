/*
** EPITECH PROJECT, 2026
** R-Type-GameEngine
** File description:
** AudioSystem
*/

#pragma once

#include <memory>

#include "IAudio.hpp"
#include "Registry.hpp"

class AudioSystem
{
    public:
        explicit AudioSystem(std::shared_ptr<Graphic::IAudio> graphic);

        void operator()(Registry& registry, double) const;

    private:
        std::shared_ptr<Graphic::IAudio> _graphic;
};
