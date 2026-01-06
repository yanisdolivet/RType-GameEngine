/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** EntityType
*/

#include "EntityType.hpp"

Components::EntityType::EntityType()
{
}

Components::EntityType::EntityType(int entityId) : _entityId(entityId)
{
}

Components::EntityType::~EntityType()
{
}

int Components::EntityType::getEntityType() const
{
    return _entityId;
}

void Components::EntityType::setEntitytType(int entityId)
{
    this->_entityId = entityId;
}
