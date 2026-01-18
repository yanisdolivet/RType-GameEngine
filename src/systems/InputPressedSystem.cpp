/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** InputPressedSystem.cpp
*/

#include "InputPressedSystem.hpp"

#include <unordered_set>

InputPressedSystem::InputPressedSystem(
    std::shared_ptr<std::unordered_map<int, std::vector<std::function<void(Registry&)>>>> keymap,
    std::function<bool(int key)> IsKeyDown)
    : _keymap(keymap), _keyDown(IsKeyDown)
{
}

/**
 * @brief Process input pressed events and publish corresponding game events
 *
 * @param registry
 */
void InputPressedSystem::operator()(Registry& registry, double) const
{
    static std::unordered_set<int> keys_held;

    for (const auto& [key, actions] : *(this->_keymap)) {
        if (this->_keyDown(key)) {
            if (keys_held.find(key) == keys_held.end()) {
                for (const auto& action : actions) {
                    action(registry);
                }
                keys_held.insert(key);
            }
        }
        else {
            keys_held.erase(key);
        }
    }
}
