/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** AnimationComponent
*/

#include "AnimationComponent.hpp"

namespace Components
{
    AnimationComponent::AnimationComponent() : _animation(), _curr_state(""), _elapsed_time(0.0f), _current_frame(0)
    {
    }

    AnimationComponent::AnimationComponent(const std::map<std::string, AnimatorState>& animation,
                                           const std::string& curr_state)
        : _animation(animation), _curr_state(curr_state)
    {
        this->_current_frame = 0;
        this->_elapsed_time  = 0.0f;
        this->_isFinished    = false;
        this->_animationQueue.push(curr_state);
    }

    AnimationComponent::~AnimationComponent()
    {
    }

    AnimatorState AnimationComponent::getAnimationData(std::string animation) const
    {
        return this->_animation.at(animation);
    }

    std::string AnimationComponent::getCurrState() const
    {
        return this->_curr_state;
    }

    int AnimationComponent::getCurrFrameIndex() const
    {
        return this->_current_frame;
    }

    float AnimationComponent::getTimeOfFrame() const
    {
        return this->_elapsed_time;
    }

    void AnimationComponent::setCurrentState(const std::string& next_step)
    {
        if (this->_animation.find(next_step) == this->_animation.end()) {
            return;
        }
        this->_curr_state = next_step;
        this->resetCurrentFrame();
        this->resetElapsedTime();
        this->setFinished(false);
    }

    void AnimationComponent::resetElapsedTime()
    {
        this->_elapsed_time = 0.0f;
    }

    void AnimationComponent::updateElapsedTime(const float dt)
    {
        this->_elapsed_time += dt;
    }

    void AnimationComponent::updateCurrentFrame()
    {
        this->_current_frame++;
    }

    void AnimationComponent::resetCurrentFrame()
    {
        this->_current_frame = 0;
    }

    bool AnimationComponent::isFinished() const
    {
        return this->_isFinished;
    }

    void AnimationComponent::setFinished(bool finished)
    {
        this->_isFinished = finished;
    }

    void AnimationComponent::enqueueAnimation(const std::string& animation)
    {
        this->_animationQueue.push(animation);
    }

    std::optional<std::string> AnimationComponent::dequeueAnimation()
    {
        if (this->_animationQueue.empty()) {
            return std::nullopt;
        }
        std::string animation = this->_animationQueue.front();
        this->_animationQueue.pop();
        return animation;
    }

    bool AnimationComponent::hasPendingAnimations() const
    {
        return !this->_animationQueue.empty();
    }

    void AnimationComponent::emptyQueue()
    {
        while (!this->_animationQueue.empty()) {
            this->_animationQueue.pop();
        }
    }

    int AnimationComponent::getQueueSize() const
    {
        return static_cast<int>(this->_animationQueue.size());
    }

    bool AnimationComponent::isAnimationQueued(const std::string& animation) const
    {
        std::queue<std::string> tempQueue = this->_animationQueue;

        while (!tempQueue.empty()) {
            if (tempQueue.front() == animation) {
                return true;
            }
            tempQueue.pop();
        }
        return false;
    }

} // namespace Components
