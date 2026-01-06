/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** entity
*/

#pragma once
#include <cstddef>

class Entity
{
    public:
        explicit Entity(std::size_t id);

        // Implicit conversion to size_t to use it as an index
        operator std::size_t() const;

    private:
        std::size_t _id;
};
