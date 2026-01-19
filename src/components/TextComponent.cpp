/*
** EPITECH PROJECT, 2026
** R-Type-GameEngine
** File description:
** TextComponent
*/

#include "TextComponent.hpp"

Components::TextComponent::TextComponent() : _text(""), _font(""), _size(0), _spacing(0), _color({0, 0, 0, 0}), _id(-1)
{
}

Components::TextComponent::TextComponent(const std::string& text, const std::string& font, int size, float spacing,
                                         std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> color, int id)
    : _text(text), _font(font), _size(size), _spacing(spacing), _color(color), _id(id)
{
}

std::string Components::TextComponent::getText() const
{
    return this->_text;
}

int Components::TextComponent::getId() const
{
    return this->_id;
}

std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> Components::TextComponent::getColor() const
{
    return this->_color;
}

void Components::TextComponent::setTextContent(const std::string& text)
{
    this->_text = text;
}

std::string Components::TextComponent::getFont() const
{
    return this->_font;
}

int Components::TextComponent::getSize() const
{
    return this->_size;
}

float Components::TextComponent::getSpacing() const
{
    return this->_spacing;
}

void Components::TextComponent::setFontName(const std::string& font)
{
    this->_font = font;
}

void Components::TextComponent::setSize(int size)
{
    this->_size = size;
}

void Components::TextComponent::setSpacing(float spacing)
{
    this->_spacing = spacing;
}

void Components::TextComponent::setColor(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> color)
{
    this->_color = color;
}
