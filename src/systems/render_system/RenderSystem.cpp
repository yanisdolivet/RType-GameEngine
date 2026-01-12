/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** RenderSystem.cpp
*/

#include "RenderSystem.hpp"

#include <algorithm>
#include <vector>

RenderSystem::RenderSystem(std::shared_ptr<Graphic::IRender> graphic) : _graphic(graphic)
{
}

void RenderSystem::operator()(Registry& reg, double, SparseArray<Components::Position> const& positions,
                              SparseArray<Components::SpriteComponent> const& sprite,
                              SparseArray<Components::DrawableComponent> const& drawable) const
{
    this->_graphic->clearWindow();

    if (this->_graphic->windowShouldClose())
        reg.publish(EventGameExit{});

    // Collect all renderable entities with their layer information
    struct RenderData
    {
            std::size_t index;
            int layer;
            const Components::Position* pos;
            const Components::SpriteComponent* sp;
            const Components::DrawableComponent* dr;
    };

    std::vector<RenderData> renderQueue;
    renderQueue.reserve(100); // Pre-allocate to avoid reallocations

    for (auto&& [idx, pos, sp, dr] : IndexedZipper(positions, sprite, drawable)) {
        if (dr.isVisible()) {
            renderQueue.push_back({idx, dr.getLayer(), &pos, &sp, &dr});
        }
    }

    // Sort by layer
    std::sort(renderQueue.begin(), renderQueue.end(), [](const RenderData& a, const RenderData& b) {
        return a.layer < b.layer;
    });

    // Render in sorted order
    for (const auto& renderData : renderQueue) {
        std::pair<float, float> position                  = {renderData.pos->getX(), renderData.pos->getY()};
        Rectangle spriteRect                              = renderData.dr->getSourceRect();
        Vector2 spriteScale                               = renderData.dr->getScale();
        std::pair<unsigned int, unsigned int> sizeSection = {static_cast<unsigned int>(spriteRect.width),
                                                             static_cast<unsigned int>(spriteRect.height)};
        std::pair<float, float> spriteSection             = {spriteRect.x, spriteRect.y};
        std::pair<float, float> scale                     = {spriteScale.x, spriteScale.y};

        this->_graphic->renderSprite(renderData.sp->getResourceId(), position, spriteSection, sizeSection, scale);
    }

    this->_graphic->displayWindow();
}
