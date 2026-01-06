/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** Velocity.hpp
*/

#pragma once

namespace Components
{
    class Velocity
    {
        public:
            Velocity();
            Velocity(float vx, float vy);
            ~Velocity();

            float getVx() const;
            float getVy() const;
            void setVx(float vx);
            void setVy(float vy);

            bool operator==(const Velocity&) const;

        private:
            float _vx;
            float _vy;
    };
} // namespace Components