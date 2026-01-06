#include "Damage.hpp"

/**
 * @brief Construct a new Damage object
 *
 */
Components::Damage::Damage() : _damage(10)
{
}

/**
 * @brief Construct a new Damage object
 *
 * @param damage
 */
Components::Damage::Damage(int damage) : _damage(damage)
{
}

/**
 * @brief Destroy the Damage object
 *
 */
Components::Damage::~Damage()
{
}

/**
 * @brief Get the damage value
 *
 * @return int
 */
int Components::Damage::getDamage() const
{
    return _damage;
}

/**
 * @brief Set the damage value
 *
 * @param damage
 */
void Components::Damage::setDamage(int damage)
{
    _damage = damage;
}

/**
 * @brief Overload of the equality operator to compare two Damage objects
 *
 * @param other
 * @return true
 * @return false
 */
bool Components::Damage::operator==(const Damage& other) const
{
    return this->_damage == other._damage;
}
