/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** MovementSystem
*/

#include "MovementSystem.hpp"

void MovementSystem::operator()(Registry& registry, SparseArray<Components::Mouvement>& mouvements,
                                SparseArray<Components::Velocity>& velocities,
                                SparseArray<Components::Speed>& speeds) const
{
    for (auto&& [idx, mouvement, velocity, speed] : IndexedZipper(mouvements, velocities, speeds)) {
        if (mouvement.getHorizontal() != 0)
            velocity.setVx(static_cast<float>(mouvement.getHorizontal() * speed.getSpeed()));
        else
            velocity.setVx(0);
        if (mouvement.getVertical() != 0)
            velocity.setVy(static_cast<float>(mouvement.getVertical() * speed.getSpeed()));
        else
            velocity.setVy(0);
    }
}