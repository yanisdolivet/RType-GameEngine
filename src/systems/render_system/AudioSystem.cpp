/*
** EPITECH PROJECT, 2026
** R-Type-GameEngine
** File description:
** AudioSystem
*/

#include "AudioSystem.hpp"

AudioSystem::AudioSystem(std::shared_ptr<Graphic::IAudio> graphic) : _graphic(graphic)
{
}

void AudioSystem::operator()(Registry&, double) const
{
    this->_graphic->updateMusicStream();
}