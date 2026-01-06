/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** IRender
*/

#pragma once

#include <string>

namespace Graphic
{
    class IRender
    {
        public:
            virtual ~IRender()                                                       = default;
            virtual void initWindow(int width, int height, std::string const& title) = 0;
            virtual void closeWindow()                                               = 0;
            virtual void clearWindow()                                               = 0;
            virtual void displayWindow()                                             = 0;
            virtual bool windowShouldClose() const                                   = 0;
            virtual void renderSprite(std::string const& spriteName, std::pair<float, float> position,
                                      std::pair<float, float> spriteSection,
                                      std::pair<unsigned int, unsigned int> sectionSize,
                                      std::pair<float, float> scale)                 = 0;

        protected:
        private:
    };
} // namespace Graphic