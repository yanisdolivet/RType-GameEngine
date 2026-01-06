/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** Position.hpp
*/

#pragma once

namespace Components
{
    class Position
    {
        public:
            Position();
            Position(float x, float y);
            ~Position();

            float getX() const;
            float getY() const;
            void setX(float x);
            void setY(float y);

            bool operator==(const Position&) const;

        private:
            float _x;
            float _y;
    };
} // namespace Components