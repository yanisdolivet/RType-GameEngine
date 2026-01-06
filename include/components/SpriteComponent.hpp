/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** SpriteComponent
*/

#pragma once

#include <string>

#include "raylib.h"

namespace Components
{
    class SpriteComponent
    {
        public:
            SpriteComponent();
            SpriteComponent(std::string resource_id, int layer_id);
            ~SpriteComponent();

            int getLayerId() const;
            std::string getResourceId() const;

            void setResourceId(const std::string& resource_id);
            void setLayerId(const int layer_id);

        protected:
        private:
            std::string _resource_id;
            int _layer_id;
    };

} // namespace Components
