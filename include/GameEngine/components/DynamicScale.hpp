/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** DynamicScale
*/

#pragma once

#include <string>

#include "EngineMath.hpp"
#include "raylib.h"

namespace Components
{
    class DynamicScale
    {
        public:
            DynamicScale();
            DynamicScale(std::string x, std::string y, GameEngine::Math::Rectangle source_rect);
            ~DynamicScale();

            float getScaleX();
            float getScaleY();

            GameEngine::Math::Vector2 getScale();

        protected:
        private:
            float _x;
            float _y;
    };

} // namespace Components
