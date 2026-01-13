/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** Parallax
*/

#pragma once

namespace Components
{
    class Parallax
    {
        public:
            Parallax();
            Parallax(float speed);
            ~Parallax();

            float getSpeed() const;
            void setSpeed(float speed);

        protected:
        private:
            float _speed = 1.0f;
    };

} // namespace Components