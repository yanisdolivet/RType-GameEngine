/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** Core.cpp
*/

#include "Core.hpp"

#include <iostream>
#include <raylib.h>
#include <thread>

/**
 * @brief Construct a new Core object
 *
 */
GameEngine::Core::Core() : _isRunning(false), _deltaTime(0)
{
    this->_lastTime = std::chrono::steady_clock::now();
}

/**
 * @brief Destroy the Core object
 *
 */
GameEngine::Core::~Core()
{
}

std::chrono::steady_clock::time_point GameEngine::Core::getTimer() const
{
    return this->_lastTime;
}

/**
 * @brief Accessor to configure the registry (add components/systems)
 *
 * @return Registry&
 */
Registry& GameEngine::Core::getRegistry()
{
    return this->_registry;
}

/**
 * @brief Runs the main game loop
 *
 */
void GameEngine::Core::run()
{
    while (this->_isRunning) {
        this->_updateTime();
        this->_registry.runSystems(_deltaTime);
    }
}

/**
 * @brief Update the game loop with a non blocking way (one tick)
 *
 */
void GameEngine::Core::update()
{
    this->_updateTime();
    this->_registry.runSystems(this->_deltaTime);
}

/**
 * @brief Stops the main game loop
 *
 */
void GameEngine::Core::stop()
{
    this->_isRunning = false;
}

/**
 * @brief Starts the main game loop
 *
 */
void GameEngine::Core::start()
{
    this->_isRunning = true;
}

/**
 * @brief Update the delta time between frames
 *
 */
void GameEngine::Core::_updateTime()
{
    auto frameDuration = FRAME_DURATION;

    auto currentTime = std::chrono::steady_clock::now();
    auto elapsed     = currentTime - _lastTime;

    if (elapsed < frameDuration) {
        auto sleepTime = frameDuration - elapsed;
        std::this_thread::sleep_for(sleepTime);
    }

    auto currentPostSleep = std::chrono::steady_clock::now();
    auto totalElapsed     = currentPostSleep - _lastTime;

    _deltaTime = std::chrono::duration<double>(totalElapsed).count();
    _lastTime  = currentPostSleep;
}
/**
 * @brief Get deltaTime var
 *
 * @return double
 */
double GameEngine::Core::getDeltaTime()
{
    return _deltaTime;
}

void GameEngine::Core::setMap(std::vector<std::string> entitiesList)
{
    this->_entityMap.clear();
    this->_entityId = 1;
    for (auto const& entityName : entitiesList)
        this->setEntity(entityName);
}

void GameEngine::Core::setEntity(const std::string& entityName)
{
    this->_entityMap[entityName] = _entityId;
    this->_entityId += 1;
}

int GameEngine::Core::getEntityId(const std::string& entityName) const
{
    std::unordered_map<std::string, int>::const_iterator got = this->_entityMap.find(entityName);
    return got != this->_entityMap.end() ? got->second : -1;
}

std::string GameEngine::Core::getEntityName(const int id) const
{
    auto it = std::find_if(std::begin(this->_entityMap), std::end(this->_entityMap), [&id](auto&& p) {
        return p.second == id;
    });

    if (it == std::end(this->_entityMap))
        return "";

    return it->first;
}

std::unordered_map<std::string, int> GameEngine::Core::getEntityMap() const
{
    return this->_entityMap;
}
