/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** IAssetLoader
*/

#pragma once

#include <string>
#include <utility>

namespace Graphic
{
    class IAssetLoader
    {
        public:
            ~IAssetLoader() = default;

            virtual void addTexture(std::string const& spritePath, std::string const& spriteName,
                                    std::pair<unsigned int, unsigned int> sectionSize) = 0;

        protected:
        private:
    };
} // namespace Graphic