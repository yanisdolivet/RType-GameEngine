/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** InputSystem.cpp
*/

#include "InputSystem.hpp"

#include "CoreEvents.hpp"

InputSystem::InputSystem(std::shared_ptr<std::unordered_map<int, std::vector<std::function<void(Registry&)>>>> keymap,
                         std::function<bool(int key)> IsKeyDown)
    : _keymap(keymap), _keyDown(IsKeyDown)
{
}

/**
 * @brief Process input events and publish corresponding game events
 *
 * @param registry
 */
void InputSystem::operator()(Registry& registry, double) const
{
    for (const auto& [key, actions] : *(this->_keymap)) {
        if (this->_keyDown(key)) { //! Changer pour utiliser celui de la lib graphique utilisée
            for (const auto& action : actions) {
                action(registry);
            }
        }
    }
}
