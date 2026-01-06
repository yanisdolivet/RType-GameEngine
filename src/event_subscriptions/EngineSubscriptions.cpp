/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** EngineSubscriptions.cpp
*/

#include "EngineSubscriptions.hpp"

#include <iostream>

#include "Collider.hpp"
#include "Controllable.hpp"
#include "CoreEvents.hpp"
#include "IndexedZipper.hpp"

void Common::initEngineSubscriptions(GameEngine::Core& engine)
{
    // Subscribe to the EventGameExit to stop the engine
    engine.getRegistry().subscribe<EventGameExit>([&engine](EventGameExit const&) {
        engine.stop();
    });
}