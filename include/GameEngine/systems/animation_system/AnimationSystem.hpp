/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** AnimationSystem
*/

#pragma once

#include <cmath>

#include "AnimationComponent.hpp"
#include "AnimationStruct.hpp"
#include "DrawableComponent.hpp"
#include "Parallax.hpp"
#include "Position.hpp"
#include "Registry.hpp"
#include "SparseArray.hpp"
#include "Zipper.hpp"

class AnimationSystem
{
    public:
        explicit AnimationSystem();

        void operator()(Registry&, double, SparseArray<Components::DrawableComponent>& drawable,
                        SparseArray<Components::Position>& positions,
                        SparseArray<Components::AnimationComponent>& animation,
                        SparseArray<Components::Parallax>& parallax) const;

    private:
};