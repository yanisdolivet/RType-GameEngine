/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** Shooting
*/

#include "Shooting.hpp"

Components::Shooting::Shooting()
{
}

Components::Shooting::Shooting(std::string type) : _type(type)
{
}

Components::Shooting::~Shooting()
{
}

std::string Components::Shooting::getType() const
{
    return _type;
}

void Components::Shooting::setType(const std::string& type)
{
    _type = type;
}

bool Components::Shooting::operator==(const Shooting& other) const
{
    return _type == other._type;
}
