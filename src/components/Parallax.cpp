/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** Parallax
*/

#include "Parallax.hpp"

Components::Parallax::Parallax(float speed) : _speed(speed)
{
}

Components::Parallax::~Parallax()
{
}

float Components::Parallax::getSpeed() const
{
    return _speed;
}

void Components::Parallax::setSpeed(float speed)
{
    _speed = speed;
}
