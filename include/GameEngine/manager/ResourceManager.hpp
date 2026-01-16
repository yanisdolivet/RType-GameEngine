/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** ResourceManager
*/

#pragma once

#include <map>
#include <memory>
#include <string>
#include <unordered_map>

#include "IAssetLoader.hpp"
#include "IAudio.hpp"
#include "IRender.hpp"
#include "SpriteComponent.hpp"
#include "raylib.h"

class ResourceManager
{
    public:
        ResourceManager(Graphic::IAssetLoader& loader, Graphic::IAudio& audioloader);
        ~ResourceManager();

        void loadTexturesFromMap(const std::map<std::string, std::string>& sprites);
        void loadFontsFromMap(const std::map<std::string, std::string>& fonts);
        void loadSoundsFromMap(const std::map<std::string, std::string>& sounds);
        void loadMusicsFromMap(const std::map<std::string, std::string>& musics);

    private:
        Graphic::IAssetLoader& _loader;
        Graphic::IAudio& _audioLoader;
};
