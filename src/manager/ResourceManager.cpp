/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** ResourceManager
*/

#include "ResourceManager.hpp"

ResourceManager::ResourceManager(Graphic::IAssetLoader& loader, Graphic::IAudio& audioloader)
    : _loader(loader), _audioLoader(audioloader)
{
}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::loadTexturesFromMap(const std::map<std::string, std::string>& sprites)
{
    for (const auto& [name, path] : sprites) {
        _loader.addTexture(path, name, {32, 32});
    }
}

void ResourceManager::loadFontsFromMap(const std::map<std::string, std::string>& fonts)
{
    for (const auto& [name, path] : fonts) {
        _loader.addFont(path, name);
    }
}

void ResourceManager::loadSoundsFromMap(const std::map<std::string, std::string>& sounds)
{
    for (const auto& [name, path] : sounds) {
        _audioLoader.addSound(path, name);
    }
}

void ResourceManager::loadMusicsFromMap(const std::map<std::string, std::string>& musics)
{
    for (const auto& [name, path] : musics) {
        _audioLoader.addMusic(path, name);
    }
}
