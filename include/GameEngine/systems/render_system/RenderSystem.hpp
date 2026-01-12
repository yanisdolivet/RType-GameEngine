/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** RenderSystem.hpp
*/

#pragma once

#include <memory>

#include "CoreEvents.hpp"
#include "DrawableComponent.hpp"
#include "IRender.hpp"
#include "IndexedZipper.hpp"
#include "Position.hpp"
#include "Registry.hpp"
#include "SparseArray.hpp"
#include "SpriteComponent.hpp"

class RenderSystem
{
    public:
        explicit RenderSystem(std::shared_ptr<Graphic::IRender> graphic);

        void operator()(Registry&, double, SparseArray<Components::Position> const& positions,
                        SparseArray<Components::SpriteComponent> const& sprite,
                        SparseArray<Components::DrawableComponent> const& drawable) const;

    private:
        std::shared_ptr<Graphic::IRender> _graphic;
};