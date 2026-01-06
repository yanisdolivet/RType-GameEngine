/*
** EPITECH PROJECT, 2026
** R-Type
** File description:
** Clickable
*/

#pragma once

#include <functional>
#include <memory>
#include <utility>

namespace Components
{
    class Clickable
    {
        public:
            Clickable();
            Clickable(float x, float y, int width, int height, std::function<void()> callback);
            ~Clickable();

            std::pair<float, float> getPosition() const;
            std::pair<int, int> getSize() const;
            std::pair<std::pair<float, float>, std::pair<int, int>> getClickableArea() const;
            void trigger() const;

        protected:
        private:
            std::pair<float, float> _position;
            std::pair<int, int> _size;
            std::function<void()> _callback;
    };
} // namespace Components