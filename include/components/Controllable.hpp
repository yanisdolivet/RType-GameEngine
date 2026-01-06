/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** Controllable.hpp
*/

#pragma once

namespace Components
{
    class Controllable
    {
        public:
            Controllable();
            Controllable(bool isControllable);
            ~Controllable();

            bool isControllable() const;
            void setControllable(bool isControllable);

            bool operator==(const Controllable&) const;

        private:
            bool _isControllable;
    };
} // namespace Components
