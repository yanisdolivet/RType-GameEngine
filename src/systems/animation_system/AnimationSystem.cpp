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

void AnimationSystem::operator()(Registry&, SparseArray<Components::DrawableComponent>& drawable,
                                 SparseArray<Components::Position>& positions,
                                 SparseArray<Components::AnimationComponent>& animaton,
                                 SparseArray<Components::Parallax>& parallax) const
{
    // PARALLAX ANIMATION
    for (auto&& [dr, pos, pr] : Zipper(drawable, positions, parallax)) {
        float maxPos = -(dr.getSourceRect().width * dr.getScale().x);
        if (pos.getX() <= maxPos) {
            float newPos = dr.getSourceRect().width;
            pos.setX(newPos);
        }
        continue;
    }

    // BASIC SPRITE ANIMATION
    for (auto&& [dr, an] : Zipper(drawable, animaton)) {
        Config::AnimatorState animState = an.getAnimationData(an.getCurrState());
        int curframe                    = an.getCurrFrameIndex();
        an.updateTime();

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
            Rectangle newRect;
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
