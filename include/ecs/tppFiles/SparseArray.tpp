/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** SparceArray.tpp
*/

#pragma once

#include "SparseArray.hpp"

/**
 * @brief Construct a new Sparse Array< Component>:: Sparse Array object
 *
 * @tparam Component
 */
template <typename Component>
SparseArray<Component>::SparseArray()
{
}

/**
 * @brief Construct a new Sparse Array< Component>:: Sparse Array object
 *
 * @tparam Component
 * @param other
 */
template <typename Component>
SparseArray<Component>::SparseArray(SparseArray const& other)
{
    this->_data = other._data;
}

/**
 * @brief Construct a new Sparse Array< Component>:: Sparse Array object
 *
 * @tparam Component
 * @param other
 */
template <typename Component>
SparseArray<Component>::SparseArray(SparseArray&& other) noexcept
{
    this->_data = std::move(other._data);
}

/**
 * @brief Destroy the Sparse Array< Component>:: Sparse Array object
 *
 * @tparam Component
 */
template <typename Component>
SparseArray<Component>::~SparseArray()
{
}

/**
 * @brief Copy assignment operator for SparseArray
 *
 * @tparam Component
 * @param other
 * @return SparseArray<Component>&
 */
template <typename Component>
SparseArray<Component>& SparseArray<Component>::operator=(SparseArray const& other)
{
    this->_data = other._data;

    return *this;
}

/**
 * @brief Move assignment operator for SparseArray
 *
 * @tparam Component
 * @param other
 * @return SparseArray<Component>&
 */
template <typename Component>
SparseArray<Component>& SparseArray<Component>::operator=(SparseArray&& other) noexcept
{
    this->_data = std::move(other._data);

    return *this;
}

/**
 * @brief Access element at given index (non-const)
 *
 * @tparam Component
 * @param idx
 * @return reference_type
 */
template <typename Component>
typename SparseArray<Component>::reference_type SparseArray<Component>::operator[](size_t idx)
{
    if (idx >= this->_data.size()) {
        this->_data.resize(idx + 1);
    }
    return this->_data[idx];
}

/**
 * @brief Access element at given index (const)
 *
 * @tparam Component
 * @param idx
 * @return const_reference_type
 */
template <typename Component>
typename SparseArray<Component>::const_reference_type SparseArray<Component>::operator[](size_t idx) const
{
    return this->_data[idx];
}

/**
 * @brief Get iterator to the beginning
 *
 * @tparam Component
 * @return typename SparseArray<Component>::iterator
 */
template <typename Component>
typename SparseArray<Component>::iterator SparseArray<Component>::begin()
{
    return this->_data.begin();
}

/**
 * @brief Get iterator to the beginning (const)
 *
 * @tparam Component
 * @return SparseArray<Component>::const_iterator
 */
template <typename Component>
typename SparseArray<Component>::const_iterator SparseArray<Component>::begin() const
{
    return this->_data.begin();
}

/**
 * @brief Get const iterator to the beginning
 *
 * @tparam Component
 * @return typename SparseArray<Component>::const_iterator
 */
template <typename Component>
typename SparseArray<Component>::const_iterator SparseArray<Component>::cbegin() const
{
    return this->_data.cbegin();
}

/**
 * @brief Get iterator to the end
 *
 * @tparam Component
 * @return typename SparseArray<Component>::iterator
 */
template <typename Component>
typename SparseArray<Component>::iterator SparseArray<Component>::end()
{
    return this->_data.end();
}

/**
 * @brief Get iterator to the end (const)
 *
 * @tparam Component
 * @return typename SparseArray<Component>::const_iterator
 */
template <typename Component>
typename SparseArray<Component>::const_iterator SparseArray<Component>::end() const
{
    return this->_data.end();
}

/**
 * @brief Get const iterator to the end
 *
 * @tparam Component
 * @return typename SparseArray<Component>::const_iterator
 */
template <typename Component>
typename SparseArray<Component>::const_iterator SparseArray<Component>::cend() const
{
    return this->_data.cend();
}

/**
 * @brief Get the size of the SparseArray
 *
 * @tparam Component
 * @return typename SparseArray<Component>::size_type
 */
template <typename Component>
typename SparseArray<Component>::size_type SparseArray<Component>::size() const
{
    return this->_data.size();
}

/**
 * @brief Insert a component at a specific index (lvalue)
 *
 * @tparam Component
 * @param pos
 * @param c
 * @return typename SparseArray<Component>::reference_type
 */
template <typename Component>
typename SparseArray<Component>::reference_type SparseArray<Component>::insertAt(size_type pos, Component const& c)
{
    if (pos >= this->_data.size()) {
        this->_data.resize(pos + 1);
    }
    this->_data[pos] = c;

    return this->_data[pos];
}

/**
 * @brief Insert a component at a specific index (rvalue)
 *
 * @tparam Component
 * @param pos
 * @param c
 * @return typename SparseArray<Component>::reference_type
 */
template <typename Component>
typename SparseArray<Component>::reference_type SparseArray<Component>::insertAt(size_type pos, Component&& c)
{
    if (pos >= this->_data.size()) {
        this->_data.resize(pos + 1);
    }
    this->_data[pos] = std::move(c);

    return this->_data[pos];
}

/**
 * @brief Construct a component in-place at a specific index
 *
 * @tparam Component
 * @tparam Params
 * @param pos
 * @param args
 * @return typename SparseArray<Component>::reference_type
 */
template <typename Component>
template <class... Params>
typename SparseArray<Component>::reference_type SparseArray<Component>::emplaceAt(size_type pos, Params&&... args)
{
    if (pos >= this->_data.size()) {
        this->_data.resize(pos + 1);
    }
    // Emplace directly into the optional
    this->_data[pos].emplace(std::forward<Params>(args)...);

    return this->_data[pos];
}

/**
 * @brief Erase the component at a specific index
 *
 * @tparam Component
 * @param pos
 */
template <typename Component>
void SparseArray<Component>::erase(size_type pos)
{
    if (pos < this->_data.size()) {
        this->_data[pos].reset();
    }
}

/**
 * @brief Get the index of a specific value
 *
 * @tparam Component
 * @param val
 * @return typename SparseArray<Component>::size_type
 */
template <typename Component>
typename SparseArray<Component>::size_type SparseArray<Component>::getIndex(value_type const& val) const
{
    for (size_t i = 0; i < this->_data.size(); ++i) {
        if (this->_data[i].has_value() && val.has_value()) {
            if (this->_data[i].value() == val.value()) {
                return i;
            }
        }
    }
    return static_cast<size_type>(-1);
}
