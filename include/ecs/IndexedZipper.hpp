/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** IndexedZipper.hpp
*/

#pragma once
#include <algorithm>
#include <iterator>
#include <tuple>
#include <utility>
#include <vector>

#include "IndexedZipperIterator.hpp"

template <class... Containers>
class IndexedZipper
{
    public:
        using iterator       = IndexedZipperIterator<Containers...>;
        using iterator_tuple = typename iterator::iterator_tuple;

        IndexedZipper(Containers&... cs);

        iterator begin();
        iterator end();

    private:
        static size_t _computeSize(Containers&... containers);
        static iterator_tuple _computeEnd(Containers&... containers);

        iterator_tuple _begin;
        iterator_tuple _end;
        size_t _size;
};

#include "IndexedZipper.tpp"
