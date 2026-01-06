/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** Mouvement
*/

#pragma once

namespace Components
{
    class Mouvement
    {
        public:
            Mouvement();
            Mouvement(int vertical, int horizontal);
            ~Mouvement();

            int getVertical() const;
            int getHorizontal() const;

            void setVertical(int vertical);
            void setHorizontal(int horizontal);

            bool operator==(const Mouvement&) const;

        private:
            int _vertical;
            int _horizontal;
    };
} // namespace Components
