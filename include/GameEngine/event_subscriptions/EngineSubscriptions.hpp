/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** EngineSubscriptions.hpp
*/

#pragma once

#include <functional>
#include <iostream>
#include <optional>

#include "Collider.hpp"
#include "Controllable.hpp"
#include "Core.hpp"
#include "GameEngineEvents.hpp"
#include "IndexedZipper.hpp"
#include "SceneManager.hpp"

namespace Common
{
    /**
     * @brief Initialize engine event subscriptions
     *
     * @param engine
     * @param sceneManager Optional scene manager (can be std::nullopt)
     */
    void initEngineSubscriptions(GameEngine::Core& engine,
                                 std::optional<std::reference_wrapper<SceneManager>> sceneManager = std::nullopt);

} // namespace Common