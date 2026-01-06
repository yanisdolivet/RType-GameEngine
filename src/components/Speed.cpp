/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** Speed
*/

#include "Speed.hpp"

Components::Speed::Speed() : _speed(0)
{
}

Components::Speed::~Speed()
{
}

Components::Speed::Speed(int speed) : _speed(speed)
{
}

int Components::Speed::getSpeed() const
{
    return _speed;
}

void Components::Speed::setSpeed(int speed)
{
    _speed = speed;
}

bool Components::Speed::operator==(const Speed& other) const
{
    return _speed == other._speed;
}
