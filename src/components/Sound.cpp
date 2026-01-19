/*
** EPITECH PROJECT, 2026
** R-Type-GameEngine
** File description:
** Sound
*/

#include "Sound.hpp"

Sound::Sound() : _onSpawnSound(""), _onDestroySound("")
{
}

Sound::Sound(const std::string &onSpawnSound, const std::string &onDestroySound) : _onSpawnSound(onSpawnSound), _onDestroySound(onDestroySound)
{
}

Sound::~Sound()
{
}

std::string Sound::getOnSpawnSound() const
{
    return _onSpawnSound;
}

std::string Sound::getOnDestroySound() const
{
    return _onDestroySound;
}

void Sound::setOnSpawnSound(const std::string &onSpawnSound)
{
    _onSpawnSound = onSpawnSound;
}

void Sound::setOnDestroySound(const std::string &onDestroySound)
{
    _onDestroySound = onDestroySound;
}

bool Sound::operator==(const Sound &other) const
{
    return _onSpawnSound == other._onSpawnSound && _onDestroySound == other._onDestroySound;
}