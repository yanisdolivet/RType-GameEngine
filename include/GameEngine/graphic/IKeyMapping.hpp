/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** IKeyMapping
*/
#pragma once

#include <functional>
#include <memory>
#include <unordered_map>

#include "Registry.hpp"

namespace Graphic
{
    class IKeyMapping
    {
        public:
            virtual ~IKeyMapping() = default;

            virtual void addKeyMapping(int key, std::function<void(Registry&)> action) = 0;

            virtual void addKeyReleasedMapping(int key, std::function<void(Registry&)> action) = 0;

            virtual std::function<bool(int)> getKeyDownFunc() const = 0;

            virtual std::function<bool(int)> getKeyReleasedFunc() const = 0;

            virtual std::shared_ptr<std::unordered_map<int, std::vector<std::function<void(Registry&)>>>>
            getKeymap() const = 0;

            virtual std::shared_ptr<std::unordered_map<int, std::vector<std::function<void(Registry&)>>>>
            getKeyReleasedMap() const = 0;

            virtual int stringtoKeyCode(const std::string& keyString) const = 0;

            virtual void clearKeyMappings() = 0;

            virtual void clearKeyReleasedMappings() = 0;

            virtual std::pair<float, float> getMousePosition() const = 0;

        protected:
        private:
    };
} // namespace Graphic