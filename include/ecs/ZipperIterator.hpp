/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** ZipperIterator.hpp
*/

#pragma once
#include <iterator>
#include <tuple>
#include <utility>
#include <vector>

template <class... Containers>
class ZipperIterator
{

        // depending on whether Container is const or not.
        template <class Container>
        using iterator_t = decltype(std::declval<Container&>().begin());

        template <class Container>
        using it_reference_t = decltype(std::declval<iterator_t<Container>>()->value());

    public:
        using value_type        = std::tuple<it_reference_t<Containers>...>;
        using reference         = value_type;
        using pointer           = void;
        using difference_type   = std::ptrdiff_t;
        using iterator_category = std::forward_iterator_tag;

        using iterator_tuple = std::tuple<iterator_t<Containers>...>;

    public:
        ZipperIterator(iterator_tuple const& it_tuple, size_t max, size_t idx = 0);
        ZipperIterator(ZipperIterator const& z);
        ~ZipperIterator() = default;

        ZipperIterator operator++();
        ZipperIterator& operator++(int);

        reference operator*();
        reference operator->();

        bool operator==(ZipperIterator const& lhs) const;
        bool operator!=(ZipperIterator const& lhs) const;

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

#include "ZipperIterator.tpp"