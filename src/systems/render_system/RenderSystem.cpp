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

void RenderSystem::imgui() const
{
    rlImGuiBegin();

    // Draw your ImGui windows
    ImGui::Begin("Debug Window");
    ImGui::Text("Hello from Dear ImGui!");
    if (ImGui::Button("Click Me")) {
        // Button logic
    }
    ImGui::End();

    rlImGuiEnd();
}

void RenderSystem::operator()(Registry& reg, double, SparseArray<Components::Position> const& positions,
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
            const Components::DrawableComponent* dr;
    };

    std::vector<std::pair<Components::SpriteComponent, RenderData>> renderSpriteQueue;
    renderSpriteQueue.reserve(100); // Pre-allocate to avoid reallocations

    std::vector<std::pair<Components::TextComponent, RenderData>> renderTextQueue;
    renderTextQueue.reserve(100); // Pre-allocate to avoid reallocations

    for (auto&& [idx, pos, dr] : IndexedZipper(positions, drawable)) {
        if (dr.isVisible()) {
            RenderData render_data = {idx, dr.getLayer(), &pos, &dr};
            Entity ent             = reg.entityFromIndex(idx);
            if (reg.entity_has_component<Components::SpriteComponent>(ent)) {
                Components::SpriteComponent sp = reg.getSpecificComponent<Components::SpriteComponent>(ent);
                renderSpriteQueue.push_back(std::make_pair(sp, render_data));
            }
            else if (reg.entity_has_component<Components::TextComponent>(ent)) {
                Components::TextComponent txt = reg.getSpecificComponent<Components::TextComponent>(ent);
                renderTextQueue.push_back(std::make_pair(txt, render_data));
            }
        }
    }

    // Sort by layer
    std::sort(renderSpriteQueue.begin(), renderSpriteQueue.end(), [](const auto& a, const auto& b) {
        return a.second.layer < b.second.layer;
    });
    std::sort(renderTextQueue.begin(), renderTextQueue.end(), [](const auto& a, const auto& b) {
        return a.second.layer < b.second.layer;
    });

    // Render in sorted order
    for (const auto& [sp, renderData] : renderSpriteQueue) {
        std::pair<float, float> position                  = {renderData.pos->getX(), renderData.pos->getY()};
        GameEngine::Math::Rectangle spriteRect            = renderData.dr->getSourceRect();
        GameEngine::Math::Vector2 spriteScale             = renderData.dr->getScale();
        std::pair<unsigned int, unsigned int> sizeSection = {static_cast<unsigned int>(spriteRect.width),
                                                             static_cast<unsigned int>(spriteRect.height)};
        std::pair<float, float> spriteSection             = {spriteRect.x, spriteRect.y};
        std::pair<float, float> scale                     = {spriteScale.x, spriteScale.y};

        this->_graphic->renderSprite(sp.getResourceId(), position, spriteSection, sizeSection, scale);
    }

    // Render in sorted order
    for (const auto& [txt, renderData] : renderTextQueue) {
        std::pair<float, float> position = {renderData.pos->getX(), renderData.pos->getY()};

        this->_graphic->renderText(txt.getText(), txt.getFont(), position, txt.getSize(), txt.getColor(),
                                   txt.getSpacing());
    }

    this->imgui();

    this->_graphic->displayWindow();
}
