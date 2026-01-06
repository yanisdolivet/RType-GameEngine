/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** Damage.hpp
*/

#pragma once

namespace Components
{
    class Damage
    {
        public:
            Damage();
            Damage(int damage);
            ~Damage();

            int getDamage() const;
            void setDamage(int damage);

            bool operator==(const Damage&) const;

        private:
            int _damage;
    };
} // namespace Components