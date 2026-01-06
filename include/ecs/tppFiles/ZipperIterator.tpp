/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** ZipperIterator.tpp
*/

#pragma once

#include "ZipperIterator.hpp"

/**
 * @brief Construct a new Zipper Iterator< Containers...>:: Zipper Iterator object
 *
 * @tparam Containers
 * @param it_tuple
 * @param max
 * @param idx
 */
template <class... Containers>
ZipperIterator<Containers...>::ZipperIterator(iterator_tuple const& it_tuple, size_t max, size_t idx)
    : _current(it_tuple), _max(max), _idx(idx)
{
    // Fast-forward to the first valid entity.
    if (this->_idx < this->_max && !this->allSet(this->_seq)) {
        this->operator++();
    }
}

/**
 * @brief Construct a new Zipper Iterator< Containers...>:: Zipper Iterator object
 *
 * @tparam Containers
 * @param z
 */
template <class... Containers>
ZipperIterator<Containers...>::ZipperIterator(ZipperIterator const& z)
    : _current(z._current), _max(z._max), _idx(z._idx)
{
}

/**
 * @brief overload of ++ operator to incrAll iterators
 *
 * @tparam Containers
 * @return ZipperIterator<Containers...>
 */
template <class... Containers>
ZipperIterator<Containers...> ZipperIterator<Containers...>::operator++()
{
    this->incrAll(this->_seq);
    this->_idx++;

    // Fast-forward to the first valid entity.
    while (this->_idx < this->_max && !this->allSet(this->_seq)) {
        this->incrAll(this->_seq);
        this->_idx++;
    }
    return *this;
}

/**
 * @brief overload of ++ operator
 *
 * @tparam Containers
 * @return ZipperIterator<Containers...>&
 */
template <class... Containers>
ZipperIterator<Containers...>& ZipperIterator<Containers...>::operator++(int)
{
    ZipperIterator tmp = *this;
    ++(*this);
    return tmp;
}

/**
 * @brief dereference operator to access the values
 *
 * @tparam Containers
 * @return ZipperIterator<Containers...>::reference
 */
template <class... Containers>
typename ZipperIterator<Containers...>::reference ZipperIterator<Containers...>::operator*()
{
    return this->toValue(this->_seq);
}

/**
 * @brief overload of -> operator to access the values
 *
 * @tparam Containers
 * @return ZipperIterator<Containers...>::reference
 */
template <class... Containers>
typename ZipperIterator<Containers...>::reference ZipperIterator<Containers...>::operator->()
{
    return this->toValue(this->_seq);
}

/**
 * @brief overload of == operator to compare two iterators
 *
 * @tparam Containers
 * @param zi
 * @return true
 * @return false
 */
template <class... Containers>
bool ZipperIterator<Containers...>::operator==(ZipperIterator const& zi) const
{
    return this->_idx == zi._idx;
}

/**
 * @brief overload of != operator to compare two iterators
 *
 * @tparam Containers
 * @param zi
 * @return true
 * @return false
 */
template <class... Containers>
bool ZipperIterator<Containers...>::operator!=(ZipperIterator const& zi) const
{
    return this->_idx != zi._idx;
}

/* --- Helpers --- */

/**
 * @brief increment all current iterators
 *
 * @tparam Containers
 * @tparam Is
 */
template <class... Containers>
template <size_t... Is>
void ZipperIterator<Containers...>::incrAll(std::index_sequence<Is...>)
{
    // Executes ++std::get<Is>(_current) for each (Fold Epxression #TrucDeZinzin ca se fait a la compile)
    (++std::get<Is>(this->_current), ...);
}

/**
 * @brief check if all current iterators point to a valid value
 *
 * @tparam Containers
 * @tparam Is
 * @return true
 * @return false
 */
template <class... Containers>
template <size_t... Is>
bool ZipperIterator<Containers...>::allSet(std::index_sequence<Is...>)
{
    // Fold expression: checks has_value() for all iterators
    // std::get<Is>(_current) returns an iterator to optional<Component>
    return ((std::get<Is>(this->_current)->has_value()) && ...);
}

/**
 * @brief convert the current iterators to a tuple of values
 *
 * @tparam Containers
 * @tparam Is
 * @return typename ZipperIterator<Containers...>::value_type
 */
template <class... Containers>
template <size_t... Is>
typename ZipperIterator<Containers...>::value_type ZipperIterator<Containers...>::toValue(std::index_sequence<Is...>)
{
    return std::tie(std::get<Is>(this->_current)->value()...);
}
