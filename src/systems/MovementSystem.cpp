/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** MovementSystem
*/

#include "MovementSystem.hpp"

void MovementSystem::operator()(Registry&, double, SparseArray<Components::Movement>& movements,
                                SparseArray<Components::Velocity>& velocities,
                                SparseArray<Components::Speed>& speeds) const
{
    for (auto&& [idx, movement, velocity, speed] : IndexedZipper(movements, velocities, speeds)) {
        if (movement.getHorizontal() != 0)
            velocity.setVx(static_cast<float>(movement.getHorizontal() * speed.getSpeed()));
        else
            velocity.setVx(0);
        if (movement.getVertical() != 0)
            velocity.setVy(static_cast<float>(movement.getVertical() * speed.getSpeed()));
        else
            velocity.setVy(0);
    }
}