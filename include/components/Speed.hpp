/*
** EPITECH PROJECT, 2025
** $
** File description:
** Speed
*/

#pragma once

namespace Components
{
    class Speed
    {
        public:
            Speed();
            Speed(int speed);
            ~Speed();

            int getSpeed() const;
            void setSpeed(int speed);

            bool operator==(const Speed& other) const;

        private:
            int _speed;
    };
} // namespace Components