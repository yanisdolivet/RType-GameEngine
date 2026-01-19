/*
** EPITECH PROJECT, 2026
** R-Type-GameEngine
** File description:
** Sound
*/

#include "Sound.hpp"

Components::Sound::Sound() : _onSpawnSound(""), _onDestroySound("")
{
}

Components::Sound::Sound(const std::string &onSpawnSound, const std::string &onDestroySound) : _onSpawnSound(onSpawnSound), _onDestroySound(onDestroySound)
{
}

Components::Sound::~Sound()
{
}

std::string Components::Sound::getOnSpawnSound() const
{
    return _onSpawnSound;
}

std::string Components::Sound::getOnDestroySound() const
{
    return _onDestroySound;
}

void Components::Sound::setOnSpawnSound(const std::string &onSpawnSound)
{
    _onSpawnSound = onSpawnSound;
}

void Components::Sound::setOnDestroySound(const std::string &onDestroySound)
{
    _onDestroySound = onDestroySound;
}

bool Components::Sound::operator==(const Sound &other) const
{
    return _onSpawnSound == other._onSpawnSound && _onDestroySound == other._onDestroySound;
}