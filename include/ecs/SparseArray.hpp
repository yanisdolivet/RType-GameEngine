/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** SparceArray.hpp
*/

#pragma once
#include <optional>
#include <vector>

#include "Entity.hpp"

template <typename Component>
class SparseArray
{
    public:
        using value_type           = std::optional<Component>;
        using reference_type       = value_type&;
        using const_reference_type = value_type const&;
        using container_t          = std::vector<value_type>;
        using size_type            = typename container_t::size_type;
        using iterator             = typename container_t::iterator;
        using const_iterator       = typename container_t::const_iterator;

    public:
        SparseArray();
        SparseArray(SparseArray const& other);
        SparseArray(SparseArray&& other) noexcept;
        ~SparseArray();

        SparseArray& operator=(SparseArray const& other);
        SparseArray& operator=(SparseArray&& other) noexcept;

        reference_type operator[](size_t idx);
        const_reference_type operator[](size_t idx) const;

        iterator begin();
        const_iterator begin() const;
        const_iterator cbegin() const;

        iterator end();
        const_iterator end() const;
        const_iterator cend() const;

        size_type size() const;

        reference_type insertAt(size_type pos, Component const& c);
        reference_type insertAt(size_type pos, Component&& c);

        // Construct a component in-place at a specific index
        template <class... Params>
        reference_type emplaceAt(size_type pos, Params&&... args);

        void erase(size_type pos);

        size_type getIndex(value_type const& val) const;

    private:
        container_t _data;
};

#include "SparseArray.tpp"