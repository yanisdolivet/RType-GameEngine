#include "Velocity.hpp"

/**
 * @brief Construct a new Velocity object
 *
 */
Components::Velocity::Velocity() : _vx(0.0f), _vy(0.0f)
{
}

/**
 * @brief Construct a new Velocity object
 *
 * @param vx
 * @param vy
 */
Components::Velocity::Velocity(float vx, float vy) : _vx(vx), _vy(vy)
{
}

/**
 * @brief Destroy the Velocity object
 *
 */
Components::Velocity::~Velocity()
{
}

/**
 * @brief Get the Vx value
 *
 * @return float
 */
float Components::Velocity::getVx() const
{
    return _vx;
}

/**
 * @brief Get the Vy value
 *
 * @return float
 */
float Components::Velocity::getVy() const
{
    return _vy;
}

/**
 * @brief Set the Vx value
 *
 * @param vx
 */
void Components::Velocity::setVx(float vx)
{
    _vx = vx;
}

/**
 * @brief Set the Vy value
 *
 * @param vy
 */
void Components::Velocity::setVy(float vy)
{
    _vy = vy;
}

/**
 * @brief Overload of the equality operator to compare two Velocity objects
 *
 * @param other
 * @return true
 * @return false
 */
bool Components::Velocity::operator==(const Velocity& other) const
{
    return this->_vx == other._vx && this->_vy == other._vy;
}
