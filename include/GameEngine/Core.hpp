/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** Core.hpp
*/

#pragma once

#include <algorithm>
#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "Registry.hpp"

#define FRAME_RATE 60
#define DURATION 1000000000
#define FRAME_DURATION std::chrono::nanoseconds(DURATION / FRAME_RATE)

namespace GameEngine
{

    class Core
    {
        public:
            Core();
            ~Core();

            // Runs the main game loop
            void run();
            void update();
            void stop();
            void start();

            // Accessor to configure the registry (add components/systems)
            Registry& getRegistry();

            double getDeltaTime();
            void setMap(std::vector<std::string> entitiesList);
            int getEntityId(const std::string& entityName) const;
            std::string getEntityName(const int id) const;
            std::unordered_map<std::string, int> getEntityMap() const;

            std::chrono::steady_clock::time_point getTimer() const;

        private:
            void setEntity(const std::string& entityName);
            void _updateTime();

        private:
            Registry _registry;
            bool _isRunning;

            std::chrono::steady_clock::time_point _lastTime;
            double _deltaTime;

            std::unordered_map<std::string, int> _entityMap;
            int _entityId = 1;
    };
} // namespace GameEngine
