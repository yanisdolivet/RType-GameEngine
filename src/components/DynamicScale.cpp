/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** DynamicScale
*/

#include "DynamicScale.hpp"

#include <iostream>

Components::DynamicScale::DynamicScale()
{
}

Components::DynamicScale::DynamicScale(std::string x, std::string y, GameEngine::Math::Rectangle source_rect)
{

    if (x == "same_as_y") {
        this->_x = 1.0f;
    }
    else if (x == "screen_width / source_rect_width") {
        this->_x = GetScreenWidth() / source_rect.width;
    }
    else {
        this->_x = 1.0f;
    }

    if (y == "screen_height / source_rect_height") {
        this->_y = GetScreenHeight() / source_rect.height;
    }
    else {
        this->_y = 1.0f;
    }

    if (x == "same_as_y") {
        this->_x = this->_y;
    }
}

Components::DynamicScale::~DynamicScale()
{
}

float Components::DynamicScale::getScaleX()
{
    return this->_x;
}

float Components::DynamicScale::getScaleY()
{
    return this->_y;
}

GameEngine::Math::Vector2 Components::DynamicScale::getScale()
{
    GameEngine::Math::Vector2 scale;
    scale.x = this->_x;
    scale.y = this->_y;
    return scale;
}
