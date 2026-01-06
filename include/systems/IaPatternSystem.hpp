/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** PatternSystem
*/

#pragma once
#include "Ia.hpp"
#include "IndexedZipper.hpp"
#include "PatternHandling.hpp"
#include "Registry.hpp"

class IaPatternSystem
{
    public:
        void operator()(Registry& registry, SparseArray<Components::Ia> const& ia) const;
};
