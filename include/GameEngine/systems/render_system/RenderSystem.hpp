/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** RenderSystem.hpp
*/

#pragma once

#include <memory>

#include "DrawableComponent.hpp"
#include "GameEngineEvents.hpp"
#include "IRender.hpp"
#include "IndexedZipper.hpp"
#include "Position.hpp"
#include "Registry.hpp"
#include "Scale.hpp"
#include "SparseArray.hpp"
#include "SpriteComponent.hpp"
#include "TextComponent.hpp"

class RenderSystem
{
    public:
        RenderSystem(std::shared_ptr<Graphic::IRender> graphic);

        void operator()(Registry&, double, SparseArray<Components::Position> const& positions,
                        SparseArray<Components::DrawableComponent> const& drawable) const;

    private:
        std::shared_ptr<Graphic::IRender> _graphic;
};