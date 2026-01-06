/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** Controllable.cpp
*/

#include "Controllable.hpp"

/**
 * @brief Construct a new Controllable object
 *
 */
Components::Controllable::Controllable() : _isControllable(false)
{
}

/**
 * @brief Construct a new Controllable object
 *
 * @param isControllable
 */
Components::Controllable::Controllable(bool isControllable) : _isControllable(isControllable)
{
}

/**
 * @brief Destroy the Controllable object
 *
 */
Components::Controllable::~Controllable()
{
}

/**
 * @brief Check if the object is controllable
 *
 * @return true
 * @return false
 */
bool Components::Controllable::isControllable() const
{
    return _isControllable;
}

/**
 * @brief Set the controllable state of the object
 *
 * @param isControllable
 */
void Components::Controllable::setControllable(bool isControllable)
{
    _isControllable = isControllable;
}

/**
 * @brief Overload of the equality operator to compare two Controllable objects
 *
 * @param other
 * @return true
 * @return false
 */
bool Components::Controllable::operator==(const Controllable& other) const
{
    return this->_isControllable == other._isControllable;
}
