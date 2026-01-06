#include "Position.hpp"

/**
 * @brief Construct a new Position object
 *
 */
Components::Position::Position() : _x(0.0f), _y(0.0f)
{
}

/**
 * @brief Construct a new Position object
 *
 * @param x
 * @param y
 */
Components::Position::Position(float x, float y) : _x(x), _y(y)
{
}

/**
 * @brief Destroy the Position object
 *
 */
Components::Position::~Position()
{
}

/**
 * @brief Get the X coordinate
 *
 * @return float
 */
float Components::Position::getX() const
{
    return _x;
}

/**
 * @brief Get the Y coordinate
 *
 * @return float
 */
float Components::Position::getY() const
{
    return _y;
}

/**
 * @brief Set the X coordinate
 *
 * @param x
 */
void Components::Position::setX(float x)
{
    _x = x;
}

/**
 * @brief Set the Y coordinate
 *
 * @param y
 */
void Components::Position::setY(float y)
{
    _y = y;
}

/**
 * @brief Overload of the equality operator to compare two Position objects
 *
 * @param other
 * @return true
 * @return false
 */
bool Components::Position::operator==(const Position& other) const
{
    return this->_x == other._x && this->_y == other._y;
}
