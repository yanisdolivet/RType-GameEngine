/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** CollisionSystem
*/

#include "CollisionSystem.hpp"

#include "CoreEvents.hpp"

/**
 * @brief Detect and publish collision events between entities
 *
 * @param registry
 * @param positions
 * @param colliders
 */
void CollisionSystem::operator()(Registry& registry, double, SparseArray<Components::Position>& positions,
                                 SparseArray<Components::Collider> const& colliders) const
{
    for (auto&& [idxA, posA, colliderA] : IndexedZipper(positions, colliders)) {
        for (auto&& [idxB, posB, colliderB] : IndexedZipper(positions, colliders)) {
            if (idxA >= idxB || colliderA.getType() == colliderB.getType())
                continue;

            bool collisionX =
                posA.getX() < posB.getX() + colliderB.getWidth() && posA.getX() + colliderA.getWidth() > posB.getX();
            bool collisionY =
                posA.getY() < posB.getY() + colliderB.getHeight() && posA.getY() + colliderA.getHeight() > posB.getY();

            if (collisionX && collisionY) {
                registry.publish(EventCollision{static_cast<Entity>(idxA), static_cast<Entity>(idxB)});
            }
        }
    }
}
