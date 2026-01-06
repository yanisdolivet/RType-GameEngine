/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** DynamicScale
*/

#pragma once

#include <string>

#include "raylib.h"

namespace Components
{
    class DynamicScale
    {
        public:
            DynamicScale();
            DynamicScale(std::string x, std::string y, Rectangle source_rect);
            ~DynamicScale();

            float getScaleX();
            float getScaleY();

            Vector2 getScale();

        protected:
        private:
            float _x;
            float _y;
    };

} // namespace Components
