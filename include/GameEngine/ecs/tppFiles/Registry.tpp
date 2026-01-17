/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** Registry.tpp
*/

#pragma once

#include <iostream>

#include "Registry.hpp"

/**
 * @brief Register a component type and return its associated SparseArray
 *
 * @tparam Component
 * @return SparseArray<Component>&
 */
template <class Component>
SparseArray<Component>& Registry::registerComponent()
{
    std::type_index index = std::type_index(typeid(Component));

    if (this->_componentsArrays.find(index) == this->_componentsArrays.end()) {
        this->_componentsArrays[index] = std::make_any<SparseArray<Component>>();

        // Register a function that knows how to remove this component from an entity
        this->_entityKillFunctions.push_back([](Registry& r, Entity const& e) {
            r.removeComponent<Component>(e);
        });
    }

    return std::any_cast<SparseArray<Component>&>(this->_componentsArrays[index]);
}

/**
 * @brief Emplace a component of type Component for a given entity
 *
 * @tparam Component
 * @tparam Params
 * @param to
 * @param p
 * @return typename SparseArray<Component>::reference_type
 */
template <class Component, typename... Params>
typename SparseArray<Component>::reference_type Registry::emplaceComponent(Entity const& to, Params&&... p)
{
    return this->getComponents<Component>().emplaceAt(to, std::forward<Params>(p)...);
}

/**
 * @brief Get the SparseArray of a specific component type
 *
 * @tparam Component
 * @return SparseArray<Component>&
 */
template <class Component>
SparseArray<Component>& Registry::getComponents()
{
    std::type_index index = std::type_index(typeid(Component));

    try {
        return std::any_cast<SparseArray<Component>&>(this->_componentsArrays.at(index));
    }
    catch (const std::out_of_range&) {

        throw std::logic_error("Registry Error: Component not registered: " + std::string(typeid(Component).name()));
    }
}

/**
 * @brief Get the SparseArray of a specific component type (const version)
 *
 * @tparam Component
 * @return SparseArray<Component> const&
 */
template <class Component>
SparseArray<Component> const& Registry::getComponents() const
{
    std::type_index index = std::type_index(typeid(Component));

    try {
        return std::any_cast<SparseArray<Component> const&>(this->_componentsArrays.at(index));
    }
    catch (const std::out_of_range&) {
        throw std::logic_error("Registry Error: Component not registered: " + std::string(typeid(Component).name()));
    }
}

/**
 * @brief Get a specific component instance for a given entity
 *
 * @tparam Component
 * @param entity
 * @return Component&
 */
template <class Component>
Component& Registry::getSpecificComponent(Entity const& entity)
{
    auto& components = this->getComponents<Component>();

    try {
        return components[entity].value();
    }
    catch (const std::runtime_error&) {
        throw std::logic_error("Registry Error: Component not registered: " + std::string(typeid(Component).name()));
    }
}

/**
 * @brief Check if an entity has a specific component
 *
 * @tparam Component
 * @param entity
 * @return true
 * @return false
 */
template <class Component>
bool Registry::entity_has_component(Entity entity) const
{
    const auto& components = this->getComponents<Component>();

    if (entity >= components.size())
        return false;

    return components[entity].has_value();
}

/**
 * @brief Remove a component of type Component from a given entity
 *
 * @tparam Component
 * @param from
 */
template <class Component>
void Registry::removeComponent(Entity const& from)
{
    SparseArray<Component>& components = this->getComponents<Component>();
    components.erase(from);
}

/* --- System Management Implementation --- */

/**
 * @brief Add a system that operates on specific component types
 *
 * @tparam Components
 * @tparam Function
 * @param func
 */
template <class... Components, typename Function>
void Registry::addSystem(Function&& func)
{
    // Lambda wrap
    auto wrapped_system = [func](Registry& reg, double deltaTime) {
        func(reg, deltaTime, reg.getComponents<Components>()...);
    };

    this->_systems.push_back(wrapped_system);
    this->_systemsEnabled.push_back(true); // System is enabled by default
}

/* --- Messaging System Implementation --- */

/**
 * @brief Subscribe to a specific event type with a callback
 *
 * @tparam T
 * @param callback
 */
template <typename T>
void Registry::subscribe(std::function<void(T const&)> callback)
{
    using Listeners        = std::vector<std::function<void(T const&)>>;
    std::type_index typeId = std::type_index(typeid(T));

    if (this->_subscribers.find(typeId) == this->_subscribers.end()) {
        this->_subscribers[typeId] = std::make_any<Listeners>();
    }

    auto& listeners = std::any_cast<Listeners&>(this->_subscribers[typeId]);
    listeners.push_back(callback);
}

/**
 * @brief Publish an event to all its subscribers
 *
 * @tparam T
 * @param event
 */
template <typename T>
void Registry::publish(T const& event)
{
    using Listeners        = std::vector<std::function<void(T const&)>>;
    std::type_index typeId = std::type_index(typeid(T));

    if (this->_subscribers.find(typeId) == this->_subscribers.end()) {
        return;
    }

    auto& listeners = std::any_cast<Listeners&>(this->_subscribers[typeId]);
    for (auto& function : listeners) {
        function(event);
    }
}