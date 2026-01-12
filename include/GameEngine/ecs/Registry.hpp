/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** Registry.hpp
*/

#pragma once
#include <any>
#include <functional>
#include <typeindex>
#include <unordered_map>
#include <vector>

#include "Entity.hpp"
#include "IndexedZipper.hpp"
#include "SparseArray.hpp"

class Registry
{
    public:
        template <class Component>
        SparseArray<Component>& registerComponent();

        template <class Component, typename... Params>
        typename SparseArray<Component>::reference_type emplaceComponent(Entity const& to, Params&&... p);

        template <class Component>
        SparseArray<Component>& getComponents();

        template <class Component>
        SparseArray<Component> const& getComponents() const;

        template <class Component>
        Component& getSpecificComponent(Entity const& entity);

        template <class Component>
        bool entity_has_component(Entity entity) const;

        Entity spawnEntity();

        Entity entityFromIndex(std::size_t idx);

        // Kills an entity (removes all its components)
        void killEntity(Entity const& e);

        // Removes a specific component (from a given entity)
        template <class Component>
        void removeComponent(Entity const& from);

        /* --- System Management --- */
        template <class... Components, typename Function>
        void addSystem(Function&& f);

        void runSystems(double deltaTime);

        /* --- Système de Messages Simplifié --- */
        template <typename T>
        void subscribe(std::function<void(T const&)> callback);

        template <typename T>
        void publish(T const& event);

        std::size_t getEntitiesCount() const;

    private:
        std::unordered_map<std::type_index, std::any> _componentsArrays;
        std::size_t _entitiesCount = 0;

        std::vector<std::function<void(Registry&, double)>> _systems;

        // List of functions to call when an entity is killed
        // Each function knows how to remove one specific type of component
        std::vector<std::function<void(Registry&, Entity const&)>> _entityKillFunctions;

        std::unordered_map<std::type_index, std::any> _subscribers;
};

#include "Registry.tpp"
