/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** AnimationSystem
*/

#include "AnimationSystem.hpp"

AnimationSystem::AnimationSystem()
{
}

void AnimationSystem::operator()(Registry& registry, double delta_time,
                                 SparseArray<Components::DrawableComponent>& drawable,
                                 SparseArray<Components::Position>& positions,
                                 SparseArray<Components::AnimationComponent>& animation,
                                 SparseArray<Components::Parallax>& parallax) const

{
    // PARALLAX ANIMATION
    for (auto&& [idx, dr, pos, pr] : IndexedZipper(drawable, positions, parallax)) {
        Components::Scale scaleTemp =
            registry.entity_has_component<Components::Scale>(registry.entityFromIndex(idx))
                ? registry.getSpecificComponent<Components::Scale>(registry.entityFromIndex(idx))
                : Components::Scale();

        float maxPos = -(dr.getSourceRect().width * scaleTemp.getX());

        pos.setX(pos.getX() - pr.getSpeed());
        if (pos.getX() <= maxPos) {
            float newPos = dr.getSourceRect().width * scaleTemp.getX();

            pos.setX(newPos);
        }
        continue;
    }

    // BASIC SPRITE ANIMATION
    for (auto&& [dr, an] : Zipper(drawable, animation)) {
        AnimatorState animState = an.getAnimationData(an.getCurrState());
        int curframe            = an.getCurrFrameIndex();

        an.updateElapsedTime(static_cast<float>(delta_time));

        // Check for queued animation switch
        if (an.isFinished() && an.getQueueSize() > 0) {
            std::optional<std::string> nextAnim = an.dequeueAnimation();
            if (nextAnim.has_value()) {
                std::cout << "Animation finished, switching to: " << *nextAnim << std::endl;
                an.setCurrentState(*nextAnim);
            }
            continue;
        }

        // Changing frame
        if (an.getTimeOfFrame() >= animState.animation.duration) {
            GameEngine::Math::Rectangle newRect;
            newRect.width  = animState.size.x;
            newRect.height = animState.size.y;
            newRect.x      = curframe * animState.offset.x;
            newRect.y      = curframe * animState.offset.y;
            dr.setRectange(newRect);

            an.resetElapsedTime();
            an.updateCurrentFrame();

            // Check if animation completed all frames
            if (an.getCurrFrameIndex() >= animState.animation.frames) {
                if (animState.loop == true) {
                    an.resetCurrentFrame();
                }
                else {
                    an.resetCurrentFrame();
                    an.setFinished(true);
                }
            }
        }
    }
}
