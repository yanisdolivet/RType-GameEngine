/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** IndexedZipperIterator.tpp
*/

#pragma once

#include "IndexedZipperIterator.hpp"

/**
 * @brief Construct a new Indexed Zipper Iterator< Containers...>:: Indexed Zipper Iterator object
 *
 * @tparam Containers
 * @param it_tuple
 * @param max
 * @param idx
 */
template <class... Containers>
IndexedZipperIterator<Containers...>::IndexedZipperIterator(iterator_tuple const& it_tuple, size_t max, size_t idx)
    : _current(it_tuple), _max(max), _idx(idx)
{
    if (this->_idx < this->_max && !this->allSet(this->_seq)) {
        this->operator++();
    }
}

/**
 * @brief overload of ++ operator to incrAll iterators
 *
 * @tparam Containers
 * @return IndexedZipperIterator<Containers...>
 */
template <class... Containers>
IndexedZipperIterator<Containers...> IndexedZipperIterator<Containers...>::operator++()
{
    this->incrAll(this->_seq);
    this->_idx++;
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
 * @return IndexedZipperIterator<Containers...>&
 */
template <class... Containers>
IndexedZipperIterator<Containers...>& IndexedZipperIterator<Containers...>::operator++(int)
{
    IndexedZipperIterator tmp = *this;
    ++(*this);
    return tmp;
}

/**
 * @brief dereference operator to access the values
 *
 * @tparam Containers
 * @return IndexedZipperIterator<Containers...>::reference
 */
template <class... Containers>
typename IndexedZipperIterator<Containers...>::reference IndexedZipperIterator<Containers...>::operator*()
{
    return this->toValue(this->_seq);
}

/**
 * @brief overload of -> operator to access the values
 *
 * @tparam Containers
 * @return IndexedZipperIterator<Containers...>::reference
 */
template <class... Containers>
typename IndexedZipperIterator<Containers...>::reference IndexedZipperIterator<Containers...>::operator->()
{
    return this->toValue(this->_seq);
}

/**
 * @brief overload of == operator to compare two iterators
 *
 * @tparam Containers
 * @param izi
 * @return true
 * @return false
 */
template <class... Containers>
bool IndexedZipperIterator<Containers...>::operator==(IndexedZipperIterator const& izi) const
{
    return this->_idx == izi._idx;
}

/**
 * @brief overload of != operator to compare two iterators
 *
 * @tparam Containers
 * @param izi
 * @return true
 * @return false
 */
template <class... Containers>
bool IndexedZipperIterator<Containers...>::operator!=(IndexedZipperIterator const& izi) const
{
    return this->_idx != izi._idx;
}

/**
 * @brief increment all iterators
 *
 * @tparam Containers
 * @tparam Is
 */
template <class... Containers>
template <size_t... Is>
void IndexedZipperIterator<Containers...>::incrAll(std::index_sequence<Is...>)
{
    (++std::get<Is>(this->_current), ...);
}

/**
 * @brief check if all iterators are set
 *
 * @tparam Containers
 * @tparam Is
 * @return true
 * @return false
 */
template <class... Containers>
template <size_t... Is>
bool IndexedZipperIterator<Containers...>::allSet(std::index_sequence<Is...>)
{
    return ((std::get<Is>(this->_current)->has_value()) && ...);
}

/**
 * @brief convert current iterators to value_type
 *
 * @tparam Containers
 * @tparam Is
 * @return typename IndexedZipperIterator<Containers...>::value_type
 */
template <class... Containers>
template <size_t... Is>
typename IndexedZipperIterator<Containers...>::value_type
IndexedZipperIterator<Containers...>::toValue(std::index_sequence<Is...>)
{
    // Index first, then references
    return std::tie(this->_idx, std::get<Is>(this->_current)->value()...);
}
