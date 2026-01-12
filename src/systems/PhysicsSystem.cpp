/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** PhysicsSystem.cpp
*/

#include "PhysicsSystem.hpp"

/**
 * @brief Update positions based on velocities
 *
 * @param registry
 * @param positions
 * @param velocities
 */
void PhysicsSystem::operator()(Registry&, double, SparseArray<Components::Position>& positions,
                               SparseArray<Components::Velocity> const& velocities) const
{
    for (auto&& [pos, vel] : Zipper(positions, velocities)) {
        pos.setX(pos.getX() + vel.getVx());
        pos.setY(pos.getY() + vel.getVy());
    }
}
