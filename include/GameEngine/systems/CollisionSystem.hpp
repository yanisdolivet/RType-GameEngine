/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** CollisionSystem
*/

#pragma once
#include "Collider.hpp"
#include "IndexedZipper.hpp"
#include "Position.hpp"
#include "Registry.hpp"

class CollisionSystem
{
    public:
        void operator()(Registry& registry, double, SparseArray<Components::Position>& positions,
                        SparseArray<Components::Collider> const& colliders) const;
};
