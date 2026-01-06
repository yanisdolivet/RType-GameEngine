#include "Collider.hpp"

/**
 * @brief Construct a new Collider object
 *
 */
Components::Collider::Collider() : _width(1), _height(1), _type("DEFAULT")
{
}

/**
 * @brief Construct a new Collider object
 *
 * @param width
 * @param height
 * @param type
 */
Components::Collider::Collider(int width, int height, std::string type) : _width(width), _height(height), _type(type)
{
}

/**
 * @brief Destroy the Collider object
 *
 */
Components::Collider::~Collider()
{
}

/**
 * @brief Get the width of the Collider
 *
 * @return int
 */
int Components::Collider::getWidth() const
{
    return _width;
}

/**
 * @brief Get the height of the Collider
 *
 * @return int
 */
int Components::Collider::getHeight() const
{
    return _height;
}

/**
 * @brief Get the type of the Collider
 *
 * @return std::string
 */
std::string Components::Collider::getType() const
{
    return _type;
}

/**
 * @brief Set the width of the Collider
 *
 * @param width
 */
void Components::Collider::setWidth(int width)
{
    _width = width;
}

/**
 * @brief Set the height of the Collider
 *
 * @param height
 */
void Components::Collider::setHeight(int height)
{
    _height = height;
}

/**
 * @brief Set the type of the Collider
 *
 * @param type
 */
void Components::Collider::setType(std::string type)
{
    _type = type;
}

/**
 * @brief Overload of the equality operator to compare two Collider objects
 *
 * @param other
 * @return true
 * @return false
 */
bool Components::Collider::operator==(const Collider& other) const
{
    return this->_width == other._width && this->_height == other._height && this->_type == other._type;
}
