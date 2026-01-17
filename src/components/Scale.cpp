/*
** EPITECH PROJECT, 2026
** R-Type-GameEngine
** File description:
** Scale
*/

#include "Scale.hpp"

Components::Scale::Scale() : _x(1), _y(1)
{
}

Components::Scale::~Scale()
{
}

Components::Scale::Scale(int x, int y) : _x(x), _y(y)
{
}

int Components::Scale::getX() const
{
    return _x;
}

int Components::Scale::getY() const
{
    return _y;
}

void Components::Scale::setX(int x)
{
    _x = x;
}

void Components::Scale::setY(int y)
{
    _y = y;
}

bool Components::Scale::operator==(const Scale& other) const
{
    return _x == other._x && _y == other._y;
}
