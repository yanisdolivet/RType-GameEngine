/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** main.cpp
*/

#include <iostream>

#include "Core.hpp"

int main()
{
    try {
        GameEngine::Core game_engine;

        game_engine.run();
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
}
