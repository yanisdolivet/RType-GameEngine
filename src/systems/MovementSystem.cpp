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
        float length        = std::sqrt(h * h + v * v);

        if (length > 0.0001f) {
            velocity.setVx((h / length) * current_speed);
            velocity.setVy((v / length) * current_speed);
        }
        else {
            velocity.setVx(0);
            velocity.setVy(0);
        }
    }
}
