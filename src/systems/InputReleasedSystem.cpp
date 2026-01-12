/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** InputReleasedSystem
*/

#include "InputReleasedSystem.hpp"

InputReleasedSystem::InputReleasedSystem(
    std::shared_ptr<std::unordered_map<int, std::vector<std::function<void(Registry&)>>>> keymap,
    std::function<bool(int)> keyReleasedFunc)
    : _keymap(keymap), _keyReleasedFunc(keyReleasedFunc)
{
}

/**
 * @brief Process input released events and publish corresponding game events
 *
 * @param registry
 */
void InputReleasedSystem::operator()(Registry& registry, double) const
{
    for (const auto& [key, actions] : *(this->_keymap)) {
        if (this->_keyReleasedFunc(key)) {
            for (const auto& action : actions) {
                action(registry);
            }
        }
    }
}