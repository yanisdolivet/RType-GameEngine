/*
** EPITECH PROJECT, 2026
** R-Type-GameEngine
** File description:
** AnimationStruct
*/

#pragma once

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
        Vector2 origin;
        Vector2 size;
        Vector2 offset;
};
