/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** DrawableComponent
*/

#include "DrawableComponent.hpp"

namespace Components
{
    DrawableComponent::DrawableComponent() : _source_rect({0, 0, 0, 0}), _is_visible(true), _layer(0)
    {
    }

    DrawableComponent::DrawableComponent(Rectangle source_rect, bool is_visible, int layer)
        : _source_rect(source_rect), _is_visible(is_visible), _layer(layer)
    {
    }

    DrawableComponent::~DrawableComponent()
    {
    }

    Rectangle DrawableComponent::getSourceRect() const
    {
        return this->_source_rect;
    }

    bool DrawableComponent::isVisible() const
    {
        return this->_is_visible;
    }

    int DrawableComponent::getLayer() const
    {
        return this->_layer;
    }

    void DrawableComponent::changeVisibility(bool visible)
    {
        this->_is_visible = visible;
    }

    void DrawableComponent::setRectange(Rectangle new_source_rect)
    {
        this->_source_rect = new_source_rect;
    }

    void DrawableComponent::setLayer(int layer)
    {
        this->_layer = layer;
    }

    void DrawableComponent::setOrigin(float x, float y)
    {
        this->_source_rect.x = x;
        this->_source_rect.y = y;
    }

} // namespace Components