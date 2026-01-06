/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** Mouvement
*/

#include "Mouvement.hpp"

Components::Mouvement::Mouvement() : _vertical(0), _horizontal(0)
{
}

Components::Mouvement::Mouvement(int vertical, int horizontal) : _vertical(vertical), _horizontal(horizontal)
{
}

Components::Mouvement::~Mouvement()
{
}

int Components::Mouvement::getVertical() const
{
    return this->_vertical;
}

int Components::Mouvement::getHorizontal() const
{
    return this->_horizontal;
}

void Components::Mouvement::setVertical(int vertical)
{
    this->_vertical = vertical;
}

void Components::Mouvement::setHorizontal(int horizontal)
{
    this->_horizontal = horizontal;
}

bool Components::Mouvement::operator==(const Mouvement& other) const
{
    return this->_vertical == other._vertical && this->_horizontal == other._horizontal;
}