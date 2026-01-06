/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** Collider.hpp
*/

#pragma once

#include <string>

namespace Components
{
    class Collider
    {
        public:
            Collider();
            Collider(int width, int height, std::string type);
            ~Collider();

            int getWidth() const;
            int getHeight() const;
            std::string getType() const;

            void setWidth(int width);
            void setHeight(int height);
            void setType(std::string type);

            bool operator==(const Collider&) const;

        private:
            int _width;
            int _height;
            std::string _type;
    };
} // namespace Components