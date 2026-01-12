/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** Movement
*/

#pragma once

namespace Components
{
    class Movement
    {
        public:
            Movement();
            Movement(int vertical, int horizontal);
            ~Movement();

            int getVertical() const;
            int getHorizontal() const;

            void setVertical(int vertical);
            void setHorizontal(int horizontal);

            bool operator==(const Movement&) const;

        private:
            int _vertical;
            int _horizontal;
    };
} // namespace Components
