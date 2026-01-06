/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** Entity
*/

#include "Entity.hpp"

/**
 * @brief Construct a new Entity object
 *
 * @param id
 */
Entity::Entity(std::size_t id) : _id(id)
{
}

/**
 * @brief Implicit conversion to size_t to use it as an index
 *
 */
Entity::operator std::size_t() const
{
    return this->_id;
}
