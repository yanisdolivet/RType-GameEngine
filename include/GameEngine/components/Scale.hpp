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
            Scale(int x, int y);
            ~Scale();

            int getX() const;
            int getY() const;

            void setX(int x);
            void setY(int y);

            bool operator==(const Scale&) const;

        private:
            int _x;
            int _y;
    };
} // namespace Components