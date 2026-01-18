/*
** EPITECH PROJECT, 2026
** R-Type-GameEngine
** File description:
** AnimationStruct
*/

#pragma once

#include "EngineMath.hpp"
#include "raylib.h"

struct AnimationData
{
        int frames;
        float duration;
};

struct AnimatorState
{
        bool loop;
        AnimationData animation;
        GameEngine::Math::Vector2 origin;
        GameEngine::Math::Vector2 size;
        GameEngine::Math::Vector2 offset;
};
