/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** SpriteComponent
*/

#include "SpriteComponent.hpp"

namespace Components
{
    SpriteComponent::SpriteComponent()
    {
    }

    SpriteComponent::SpriteComponent(std::string resource_id, int layer_id)
        : _resource_id(resource_id), _layer_id(layer_id)
    {
    }

    SpriteComponent::~SpriteComponent()
    {
    }

    int SpriteComponent::getLayerId() const
    {
        return this->_layer_id;
    }

    std::string SpriteComponent::getResourceId() const
    {
        return this->_resource_id;
    }

    void SpriteComponent::setResourceId(const std::string& resource_id)
    {
        this->_resource_id = resource_id;
    }

    void SpriteComponent::setLayerId(const int layer_id)
    {
        this->_layer_id = layer_id;
    }

} // namespace Components