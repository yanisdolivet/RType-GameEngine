/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** IAudio
*/

#pragma once
#include <string>

namespace Graphic
{
    class IAudio
    {
        public:
            virtual ~IAudio()                                                                 = default;
            virtual void addSound(std::string const& soundPath, std::string const& soundName) = 0;
            virtual void playSound(std::string const& soundName)                              = 0;
            virtual void stopSound(std::string const& soundName)                              = 0;
            virtual void setVolumeSound(std::string const& soundName, float volume)           = 0;
            virtual void addMusic(std::string const& musicPath, std::string const& musicName) = 0;
            virtual void playMusic(std::string const& musicName)                              = 0;
            virtual void stopMusic(std::string const& musicName)                              = 0;
            virtual void setVolumeMusic(std::string const& musicName, float volume)           = 0;

        protected:
        private:
    };
} // namespace Graphic