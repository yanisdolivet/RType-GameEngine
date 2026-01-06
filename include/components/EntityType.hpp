/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** EntityType
*/

#pragma once

#include <string>

namespace Components
{
    class EntityType
    {
        public:
            EntityType();
            explicit EntityType(int entityId);
            ~EntityType();

            int getEntityType() const;
            void setEntitytType(int entityId);

        protected:
        private:
            int _entityId;
    };
} // namespace Components