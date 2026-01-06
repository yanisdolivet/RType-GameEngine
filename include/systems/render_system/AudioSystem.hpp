/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** AudioSystem
*/

#pragma once

#include "IAudio.hpp"

class AudioSystem
{
    public:
        AudioSystem(Graphic::IAudio& audioBackend) : _audio(audioBackend)
        {
        }
        ~AudioSystem();

        void playShoot()
        {
            _audio.playSound("shoot.mp4");
        }

    protected:
    private:
        Graphic::IAudio& _audio;
};
