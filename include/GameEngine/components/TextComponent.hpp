/*
** EPITECH PROJECT, 2026
** R-Type-GameEngine
** File description:
** TextComponent
*/

#pragma once

#include <cstdint>
#include <string>
#include <tuple>

namespace Components
{

    class TextComponent
    {
        public:
            TextComponent();

            /**
             * @brief Construct a new Text Component object
             *
             * @param text The text content
             * @param id The identifier for the text component
             */
            TextComponent(const std::string& text, const std::string& font, int size, float spacing,
                          std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> color, int id);
            ~TextComponent() = default;

            std::string getText() const;
            std::string getFont() const;
            int getSize() const;
            float getSpacing() const;
            int getId() const;
            std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> getColor() const;

            void setTextContent(const std::string& text);
            void setFontName(const std::string& font);
            void setSize(int size);
            void setSpacing(float spacing);
            void setColor(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> color);

        protected:
        private:
            std::string _text;
            std::string _font;
            int _size;
            float _spacing;
            std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> _color;
            int _id;
    };

} // namespace Components