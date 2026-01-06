/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** MovementSystem
*/

#pragma once

#include "IndexedZipper.hpp"
#include "Mouvement.hpp"
#include "Registry.hpp"
#include "Speed.hpp"
#include "Velocity.hpp"

class MovementSystem
{
    public:
        void operator()(Registry&, SparseArray<Components::Mouvement>& mouvements,
                        SparseArray<Components::Velocity>& velocities, SparseArray<Components::Speed>& speeds) const;
};
