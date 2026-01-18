/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** MovementSystem
*/

#include "MovementSystem.hpp"

#include <cmath>

void MovementSystem::operator()(Registry&, double, SparseArray<Components::Movement>& movements,
                                SparseArray<Components::Velocity>& velocities,
                                SparseArray<Components::Speed>& speeds) const
{
    for (auto&& [idx, movement, velocity, speed] : IndexedZipper(movements, velocities, speeds)) {
        float h             = static_cast<float>(movement.getHorizontal());
        float v             = static_cast<float>(movement.getVertical());
        float current_speed = static_cast<float>(speed.getSpeed());

        if (h != 0 || v != 0) {
            float length = std::sqrt(h * h + v * v);

            h = h / length;
            v = v / length;
            velocity.setVx(h * current_speed);
            velocity.setVy(v * current_speed);
        }
        else {
            velocity.setVx(0);
            velocity.setVy(0);
        }
    }
}
