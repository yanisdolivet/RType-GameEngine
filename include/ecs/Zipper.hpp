/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** Zipper.hpp
*/

#pragma once
#include <algorithm>
#include <tuple>

#include "ZipperIterator.hpp"

template <class... Containers>
class Zipper
{
    public:
        using iterator       = ZipperIterator<Containers...>;
        using iterator_tuple = typename iterator::iterator_tuple;

        Zipper(Containers&... cs);

        iterator begin();
        iterator end();

    private:
        static size_t _computeSize(Containers&... containers);
        static iterator_tuple _computeEnd(Containers&... containers);

    private:
        iterator_tuple _begin;
        iterator_tuple _end;
        size_t _size;
};

#include "Zipper.tpp"