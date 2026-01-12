/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** Movement
*/

#include "Movement.hpp"

Components::Movement::Movement() : _vertical(0), _horizontal(0)
{
}

Components::Movement::Movement(int vertical, int horizontal) : _vertical(vertical), _horizontal(horizontal)
{
}

Components::Movement::~Movement()
{
}

int Components::Movement::getVertical() const
{
    return this->_vertical;
}

int Components::Movement::getHorizontal() const
{
    return this->_horizontal;
}

void Components::Movement::setVertical(int vertical)
{
    this->_vertical = vertical;
}

void Components::Movement::setHorizontal(int horizontal)
{
    this->_horizontal = horizontal;
}

bool Components::Movement::operator==(const Movement& other) const
{
    return this->_vertical == other._vertical && this->_horizontal == other._horizontal;
}