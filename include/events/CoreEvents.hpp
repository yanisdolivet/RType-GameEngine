/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** CoreEvent
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
        std::size_t entityB;
};

struct EventShoot
{
        std::size_t shooterEntity;
        int directionX;
        int directionY;
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
        float x;
        float y;
        bool pressed;
};
