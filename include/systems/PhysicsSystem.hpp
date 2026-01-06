/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** PhysicsSystem.hpp
*/
#include "Position.hpp"
#include "Registry.hpp"
#include "Velocity.hpp"
#include "Zipper.hpp"

class PhysicsSystem
{
    public:
        void operator()(Registry& registry, SparseArray<Components::Position>& positions,
                        SparseArray<Components::Velocity> const& velocities) const;
};
