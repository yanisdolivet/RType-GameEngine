/*
** EPITECH PROJECT, 2026
** R-Type
** File description:
** Clickable
*/

#include "Clickable.hpp"

#include "network/NetworkHandler.hpp"

namespace Components
{
    Clickable::Clickable()
    {
    }

    Clickable::Clickable(
        float x, float y, int width, int height,
        std::function<void(const Protocol::PacketManager&, std::shared_ptr<Client::NetworkHandler>)> onClick)
        : _position(std::make_pair(x, y)), _size(std::make_pair(width, height)), _onClick(onClick)
    {
    }

    Clickable::~Clickable()
    {
    }

    std::pair<float, float> Clickable::getPosition() const
    {
        return this->_position;
    }

    std::pair<int, int> Clickable::getSize() const
    {
        return this->_size;
    }

    std::pair<std::pair<float, float>, std::pair<int, int>> Clickable::getClickableArea() const
    {
        return std::make_pair(_position, _size);
    }

    void Clickable::onClick(Protocol::PacketManager packetManager,
                            std::shared_ptr<Client::NetworkHandler> network) const
    {
        this->_onClick(packetManager, network);
    }
} // namespace Components