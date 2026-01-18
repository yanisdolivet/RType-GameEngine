/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** AnimationComponent
*/

#pragma once

#include <chrono>
#include <map>
#include <memory>
#include <optional>
#include <queue>
#include <stdexcept>
#include <string>

#include "AnimationStruct.hpp"

namespace Components
{
    class AnimationComponent
    {
        public:
            AnimationComponent();
            AnimationComponent(const std::map<std::string, AnimatorState>& animation, const std::string& curr_state);
            ~AnimationComponent();

            AnimatorState getAnimationData(std::string animation) const;
            std::string getCurrState() const;
            int getCurrFrameIndex() const;
            float getTimeOfFrame() const;

            void setCurrentState(const std::string& next_step);
            void resetElapsedTime();
            void updateElapsedTime(const float dt);
            void updateCurrentFrame();
            void resetCurrentFrame();
            bool isFinished() const;
            void setFinished(bool finished);
            void enqueueAnimation(const std::string& animation);
            std::optional<std::string> dequeueAnimation();
            bool hasPendingAnimations() const;
            void emptyQueue();
            int getQueueSize() const;
            bool isAnimationQueued(const std::string& animation) const;

        protected:
        private:
            std::map<std::string, AnimatorState> _animation;
            std::string _curr_state;
            float _elapsed_time = 0.0f;
            int _current_frame;
            bool _isFinished;
            std::queue<std::string> _animationQueue;
    };
} // namespace Components
