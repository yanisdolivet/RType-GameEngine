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

#include "PacketManager.hpp"

// Forward declaration
namespace Client
{
    class NetworkHandler;
}

namespace Components
{
    class Clickable
    {
        public:
            Clickable();
            Clickable(
                float x, float y, int width, int height,
                std::function<void(const Protocol::PacketManager&, std::shared_ptr<Client::NetworkHandler>)> onClick);
            ~Clickable();

            std::pair<float, float> getPosition() const;
            std::pair<int, int> getSize() const;
            std::pair<std::pair<float, float>, std::pair<int, int>> getClickableArea() const;
            void onClick(Protocol::PacketManager packetManager, std::shared_ptr<Client::NetworkHandler> network) const;

        protected:
        private:
            std::pair<float, float> _position;
            std::pair<int, int> _size;
            std::function<void(const Protocol::PacketManager&, std::shared_ptr<Client::NetworkHandler>)> _onClick;
    };
} // namespace Components