/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** DrawableComponent
*/

#pragma once

#include "raylib.h"

namespace Components
{
    class DrawableComponent
    {
        public:
            DrawableComponent();
            DrawableComponent(Rectangle source_rect, bool is_visible, int layer = 0);
            ~DrawableComponent();

            Rectangle getSourceRect() const;
            bool isVisible() const;
            int getLayer() const;

            void changeVisibility(bool visible);
            void setRectange(Rectangle new_source_rect);
            void setOrigin(float x, float y);
            void setLayer(int layer);

        protected:
        private:
            Rectangle _source_rect;
            bool _is_visible;
            int _layer = 0; // Lower values render first (background), higher values render last (foreground)
    };

} // namespace Components
