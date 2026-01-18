/*
** EPITECH PROJECT, 2026
** R-Type-GameEngine
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

SceneManager::SceneManager()
{
}

void SceneManager::loadSceneFromMap(
    const std::map<std::string,
                   std::tuple<std::function<void()>, std::function<void(std::string)>, std::function<void()>>>& scenes)
{
    for (const auto& [sceneName, functions] : scenes) {
        if (this->_scenes.find(sceneName) == this->_scenes.end()) {
            this->_scenes[sceneName] = functions;
        }
    }
}

void SceneManager::addScene(std::string sceneName, std::function<void()> killEntities,
                            std::function<void(std::string)> changeScene, std::function<void()> spawnEntities)
{
    if (this->_scenes.find(sceneName) == this->_scenes.end()) {
        this->_scenes[sceneName] = std::make_tuple(killEntities, changeScene, spawnEntities);
    }
}

void SceneManager::changeScene(const std::string& sceneName)
{
    auto it = this->_scenes.find(sceneName);
    if (it != this->_scenes.end()) {
        // Call the function to kill entities from the previous scene
        std::get<0>(it->second)();

        // Call the function to handle scene-specific events
        std::get<1>(it->second)(sceneName);

        // Call the function to spawn entities for the new scene
        std::get<2>(it->second)();
    }
}
