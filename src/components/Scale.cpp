/*
** EPITECH PROJECT, 2026
** R-Type-GameEngine
** File description:
** Scale
*/

#include "Scale.hpp"

Components::Scale::Scale() : _x(1.0f), _y(1.0f)
{
}

Components::Scale::~Scale()
{
}

Components::Scale::Scale(float x, float y) : _x(x), _y(y)
{
}

float Components::Scale::getX() const
{
    return _x;
}

float Components::Scale::getY() const
{
    return _y;
}

void Components::Scale::setX(float x)
{
    _x = x;
}

void Components::Scale::setY(float y)
{
    _y = y;
}

bool Components::Scale::operator==(const Scale& other) const
{
    return _x == other._x && _y == other._y;
}
