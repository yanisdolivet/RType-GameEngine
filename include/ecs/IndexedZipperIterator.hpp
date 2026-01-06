/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** IndexedZipper.hpp
*/

#pragma once

#include <iterator>
#include <tuple>
#include <utility>
#include <vector>

template <class... Containers>
class IndexedZipperIterator
{
        template <class Container>
        using iterator_t = decltype(std::declval<Container&>().begin());

        template <class Container>
        using it_reference_t = decltype(std::declval<iterator_t<Container>>()->value());

    public:
        // Index, Component1&, Component2&...
        using value_type        = std::tuple<std::size_t, it_reference_t<Containers>...>;
        using reference         = value_type;
        using iterator_category = std::forward_iterator_tag;
        using iterator_tuple    = std::tuple<iterator_t<Containers>...>;

    public:
        IndexedZipperIterator(iterator_tuple const& it_tuple, size_t max, size_t idx = 0);
        IndexedZipperIterator(IndexedZipperIterator const& z) = default;
        ~IndexedZipperIterator()                              = default;

        IndexedZipperIterator operator++();
        IndexedZipperIterator& operator++(int);

        reference operator*();
        reference operator->();

        bool operator==(IndexedZipperIterator const& izi) const;
        bool operator!=(IndexedZipperIterator const& izi) const;

    private:
        template <size_t... Is>
        void incrAll(std::index_sequence<Is...>);

        template <size_t... Is>
        bool allSet(std::index_sequence<Is...>);

        template <size_t... Is>
        value_type toValue(std::index_sequence<Is...>);

    private:
        iterator_tuple _current;
        size_t _max;
        size_t _idx;
        static constexpr std::index_sequence_for<Containers...> _seq{};
};

#include "IndexedZipperIterator.tpp"