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
            DrawableComponent(Rectangle source_rect, bool is_visible, Vector2 scale, int layer = 0);
            ~DrawableComponent();

            Rectangle getSourceRect() const;
            bool isVisible() const;
            Vector2 getScale() const;
            int getLayer() const;

            void changeVisibility(bool visible);
            void setRectange(Rectangle new_source_rect);
            void setScale(Vector2 scale);
            void setOrigin(float x, float y);
            void setLayer(int layer);

        protected:
        private:
            Rectangle _source_rect;
            bool _is_visible;
            Vector2 _scale = {1.0, 1.0};
            int _layer     = 0; // Lower values render first (background), higher values render last (foreground)
    };

} // namespace Components
