/*
** EPITECH PROJECT, 2026
** R-Type-GameEngine
** File description:
** Sound
*/

#pragma once

#include <string>

namespace Components {
    class Sound {
        public:
            Sound();
            Sound(const std::string &onSpawnSound, const std::string &onDestroySound);
            ~Sound();

            std::string getOnSpawnSound() const;
            std::string getOnDestroySound() const;

            void setOnSpawnSound(const std::string &onSpawnSound);
            void setOnDestroySound(const std::string &onDestroySound);

            bool operator==(const Sound &other) const;
        protected:
        private:
            std::string _onSpawnSound;
            std::string _onDestroySound;
    };
} // namespace Components