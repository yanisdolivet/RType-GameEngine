/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** IndexedZipper.tpp
*/

#pragma once

#include "IndexedZipper.hpp"

/**
 * @brief Construct a new Indexed Zipper< Containers...> object
 *
 * @tparam Containers
 * @param cs
 */
template <class... Containers>
IndexedZipper<Containers...>::IndexedZipper(Containers&... cs)
    : _begin(std::make_tuple(cs.begin()...)), _end(_computeEnd(cs...)), _size(_computeSize(cs...))
{
}

/**
 * @brief begin iterator
 *
 * @tparam Containers
 * @return typename IndexedZipper<Containers...>::iterator
 */
template <class... Containers>
typename IndexedZipper<Containers...>::iterator IndexedZipper<Containers...>::begin()
{
    return iterator(this->_begin, this->_size, 0);
}

/**
 * @brief end iterator
 *
 * @tparam Containers
 * @return typename IndexedZipper<Containers...>::iterator
 */
template <class... Containers>
typename IndexedZipper<Containers...>::iterator IndexedZipper<Containers...>::end()
{
    return iterator(this->_end, this->_size, this->_size);
}

/**
 * @brief compute the size of the smallest container
 *
 * @tparam Containers
 * @param containers
 * @return size_t
 */
template <class... Containers>
size_t IndexedZipper<Containers...>::_computeSize(Containers&... containers)
{
    return (std::min)({containers.size()...});
}

/**
 * @brief compute the end iterator tuple
 *
 * @tparam Containers
 * @param containers
 * @return typename IndexedZipper<Containers...>::iterator_tuple
 */
template <class... Containers>
typename IndexedZipper<Containers...>::iterator_tuple
IndexedZipper<Containers...>::_computeEnd(Containers&... containers)
{
    return std::make_tuple(containers.end()...);
}
