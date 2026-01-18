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
    for (std::size_t i = 0; i < this->_systems.size(); ++i) {
        if (this->_systemsEnabled[i]) {
            this->_systems[i](*this, deltaTime);
        }
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

/**
 * @brief Get all registered systems
 *
 * @return std::vector<std::function<void(Registry&, double)>>&
 */
std::vector<std::function<void(Registry&, double)>>& Registry::getAllSystem()
{
    return this->_systems;
}

/**
 * @brief Disable a specific system by index
 *
 * @param systemIndex
 */
void Registry::disableSpecificSystem(std::size_t systemIndex)
{
    if (systemIndex < this->_systemsEnabled.size()) {
        this->_systemsEnabled[systemIndex] = false;
    }
}

/**
 * @brief Enable a specific system by index
 *
 * @param systemIndex
 */
void Registry::enableSpecificSystem(std::size_t systemIndex)
{
    if (systemIndex < this->_systemsEnabled.size()) {
        this->_systemsEnabled[systemIndex] = true;
    }
}

/**
 * @brief Check if a specific system is enabled
 *
 * @param systemIndex
 * @return bool
 */
bool Registry::isSystemEnabled(std::size_t systemIndex) const
{
    if (systemIndex < this->_systemsEnabled.size()) {
        return this->_systemsEnabled[systemIndex];
    }
    return false;
}
