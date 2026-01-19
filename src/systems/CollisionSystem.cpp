/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** CollisionSystem
*/

#include "CollisionSystem.hpp"

#include "GameEngineEvents.hpp"

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
            Components::Scale scaleA(1.0f, 1.0f);
            Components::Scale scaleB(1.0f, 1.0f);
            if (registry.entity_has_component<Components::Scale>(registry.entityFromIndex(idxA))) {
                scaleA = registry.getSpecificComponent<Components::Scale>(registry.entityFromIndex(idxA));
            }
            if (registry.entity_has_component<Components::Scale>(registry.entityFromIndex(idxB))) {
                scaleB = registry.getSpecificComponent<Components::Scale>(registry.entityFromIndex(idxB));
            }
            if (idxA >= idxB)
                continue;

            bool collisionX = posA.getX() < posB.getX() + colliderB.getWidth() * scaleB.getX() &&
                              posA.getX() + colliderA.getWidth() * scaleA.getX() > posB.getX();
            bool collisionY = posA.getY() < posB.getY() + colliderB.getHeight() * scaleB.getY() &&
                              posA.getY() + colliderA.getHeight() * scaleA.getY() > posB.getY();

            if (collisionX && collisionY) {
                registry.publish(EventCollision{static_cast<Entity>(idxA), colliderA.getType(),
                                                static_cast<Entity>(idxB), colliderB.getType()});
            }
        }
    }
}
