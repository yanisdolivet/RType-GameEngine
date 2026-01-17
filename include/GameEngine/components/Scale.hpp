/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** Scale.hpp
*/

#pragma once

#include <string>

namespace Components
{
    class Scale
    {
        public:
            Scale();
            Scale(float x, float y);
            ~Scale();

            float getX() const;
            float getY() const;

            void setX(float x);
            void setY(float y);

            bool operator==(const Scale&) const;

        private:
            float _x;
            float _y;
    };
} // namespace Components