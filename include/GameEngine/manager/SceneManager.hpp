/*
** EPITECH PROJECT, 2026
** R-Type-GameEngine
** File description:
** SceneManager
*/

#pragma once

#include <functional>
#include <map>
#include <string>
#include <tuple>

class SceneManager
{
    public:
        SceneManager();
        ~SceneManager() = default;

        /**
         * @brief Load scenes from a map where each scene is defined by a name and a tuple of three functions:
         *        - A function to kill specific (or all) entities from the previous scene (no parameters).
         *        - A function to handle scene-specific events (takes a string parameter).
         *        - A function to create all the new entities for the scene (no parameters).
         */
        void
        loadSceneFromMap(const std::map<std::string, std::tuple<std::function<void()>, std::function<void(std::string)>,
                                                                std::function<void()>>>& scenes);

        /**
         * @brief Add a new scene with its associated functions.
         * @param sceneName The name of the scene.
         * @param killEntities Function to kill specific (or all) entities from the previous scene.
         * @param changeScene Function to handle scene-specific events.
         * @param spawnEntities Function to create all the new entities for the scene.
         */
        void addScene(std::string sceneName, std::function<void()> killEntities,
                      std::function<void(std::string)> changeScene, std::function<void()> spawnEntities);

        /**
         * @brief Change to a different scene by its name.
         * @param sceneName The name of the scene to switch to.
         */
        void changeScene(const std::string& sceneName);

    protected:
    private:
        std::map<std::string,
                 std::tuple<std::function<void()>, std::function<void(std::string)>, std::function<void()>>>
            _scenes;
};
