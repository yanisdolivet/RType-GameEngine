/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** GameEngineEvents
*/

#pragma once

#include <cstddef>
#include <cstdint>
#include <string>

struct EventGameExit
{
        // Empty payload, the event itself is the message
};

struct EventCollision
{
        std::size_t entityA;
        std::string entityAName;
        std::size_t entityB;
        std::string entityBName;
};

struct EventEntityDeath
{
        std::size_t killedEntityId;
};

struct EventUp
{
        bool pressed;
};

struct EventDown
{
        bool pressed;
};

struct EventLeft
{
        bool pressed;
};

struct EventRight
{
        bool pressed;
};

struct EventLeftClick
{
};
