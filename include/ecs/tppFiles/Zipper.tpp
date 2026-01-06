/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** Zipper.tpp
*/

#pragma once

#include "Zipper.hpp"

/**
 * @brief Construct a new Zipper< Containers...> object
 *
 * @tparam Containers
 * @param cs
 */
template <class... Containers>
Zipper<Containers...>::Zipper(Containers&... cs)
    : _begin(std::make_tuple(cs.begin()...)), _end(_computeEnd(cs...)), _size(_computeSize(cs...))
{
}

/**
 * @brief begin iterator
 *
 * @tparam Containers
 * @return typename Zipper<Containers...>::iterator
 */
template <class... Containers>
typename Zipper<Containers...>::iterator Zipper<Containers...>::begin()
{
    return iterator(this->_begin, this->_size, 0);
}

/**
 * @brief end iterator
 *
 * @tparam Containers
 * @return typename Zipper<Containers...>::iterator
 */
template <class... Containers>
typename Zipper<Containers...>::iterator Zipper<Containers...>::end()
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
size_t Zipper<Containers...>::_computeSize(Containers&... containers)
{
    // Return the minimum size among all containers (initialize list fold)
    return std::min({containers.size()...});
}

/**
 * @brief compute the end iterator tuple
 *
 * @tparam Containers
 * @param containers
 * @return typename Zipper<Containers...>::iterator_tuple
 */
template <class... Containers>
typename Zipper<Containers...>::iterator_tuple Zipper<Containers...>::_computeEnd(Containers&... containers)
{
    return std::make_tuple(containers.end()...);
}
