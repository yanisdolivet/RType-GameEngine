/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** Registry.cpp
*/

#include "Registry.hpp"

/**
 * @brief Spawn a new entity and return it
 *
 * @return Entity
 */
Entity Registry::spawnEntity()
{
    return Entity(this->_entitiesCount++);
}

/**
 * @brief Get an entity from its index
 *
 * @param idx
 * @return Entity
 */
Entity Registry::entityFromIndex(std::size_t idx)
{
    return Entity(idx);
}

/**
 * @brief Kill an entity by removing all its components
 *
 * @param e
 */
void Registry::killEntity(Entity const& e)
{
    for (auto& kill_func : this->_entityKillFunctions) {
        kill_func(*this, e);
    }
}

/**
 * @brief Run all registered systems
 *
 */
void Registry::runSystems(double deltaTime)
{
    for (auto& system : this->_systems) {
        system(*this, deltaTime);
    }
}

/**
 * @brief Get the total number of entities spawned
 *
 * @return std::size_t
 */
std::size_t Registry::getEntitiesCount() const
{
    return this->_entitiesCount;
}
