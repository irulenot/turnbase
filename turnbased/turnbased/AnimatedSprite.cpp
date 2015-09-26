//
//  Animation.cpp
//  turnbased
//
//  Created by Ian Wilson on 9/26/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#include "AnimatedSprite.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

AnimatedSprite::AnimatedSprite()
: mSprite()
, mFrameSize()
, mNumFrames(0)
, mCurrentFrame(0)
, mDuration(sf::Time::Zero)
, mElapsedTime(sf::Time::Zero)
, mRepeat(false)
, mIsPaused(false)
{
}

AnimatedSprite::AnimatedSprite(const sf::Texture& texture)
: mSprite(texture)
, mFrameSize()
, mNumFrames(0)
, mCurrentFrame(0)
, mDuration(sf::Time::Zero)
, mElapsedTime(sf::Time::Zero)
, mRepeat(false)
, mIsPaused(false)
{
}

void AnimatedSprite::setAnimation(const Animation& animation)
{
    mAnimation = &animation;
    mCurrentFrame = 0;
}

const Animation* AnimatedSprite::getAnimation() const
{
    return mAnimation;
}

void AnimatedSprite::setTexture(const sf::Texture& texture)
{
    mSprite.setTexture(texture);
}

const sf::Texture* AnimatedSprite::getTexture() const
{
    return mSprite.getTexture();
}



void AnimatedSprite::setFrameSize(sf::Vector2i frameSize)
{
    mFrameSize = frameSize;
}

sf::Vector2i AnimatedSprite::getFrameSize() const
{
    return mFrameSize;
}

void AnimatedSprite::setNumFrames(std::size_t numFrames)
{
    mNumFrames = numFrames;
}

std::size_t AnimatedSprite::getNumFrames() const
{
    return mNumFrames;
}

void AnimatedSprite::setDuration(sf::Time duration)
{
    mDuration = duration;
}

sf::Time AnimatedSprite::getDuration() const
{
    return mDuration;
}

void AnimatedSprite::play()
{
    mIsPaused = false;
}

void AnimatedSprite::play(const Animation& animation)
{
    if (getAnimation() != &animation)
        setAnimation(animation);
    play();
}

void AnimatedSprite::pause()
{
    mIsPaused = true;
}

void AnimatedSprite::stop()
{
    mIsPaused = true;
    mCurrentFrame = 0;
    
}

void AnimatedSprite::setRepeating(bool flag)
{
    mRepeat = flag;
}

bool AnimatedSprite::isRepeating() const
{
    return mRepeat;
}

void AnimatedSprite::restart()
{
    mCurrentFrame = 0;
}

bool AnimatedSprite::isFinished() const
{
    return mCurrentFrame >= mNumFrames;
}

sf::FloatRect AnimatedSprite::getLocalBounds() const
{
    return sf::FloatRect(getOrigin(), static_cast<sf::Vector2f>(getFrameSize()));
}

sf::FloatRect AnimatedSprite::getGlobalBounds() const
{
    return getTransform().transformRect(getLocalBounds());
}
void AnimatedSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(mSprite, states);
}

void AnimatedSprite::update(sf::Time dt)
{
    sf::Time timePerFrame = mDuration / static_cast<float>(mNumFrames);
    mElapsedTime += dt;
    
    sf::Vector2i textureBounds(mSprite.getTexture()->getSize());
    sf::IntRect textureRect = mSprite.getTextureRect();

    if (mCurrentFrame == 0)
        textureRect = sf::IntRect(0, 0, mFrameSize.x, mFrameSize.y);
    
    while (mElapsedTime >= timePerFrame && (mCurrentFrame <= mNumFrames || mRepeat))
    {
        textureRect.left += textureRect.width;
        if (textureRect.left + textureRect.width > textureBounds.x)
        {
            textureRect.left = 0;
            textureRect.top += textureRect.height;
        }
        
        mElapsedTime -= timePerFrame;
        if (mRepeat)
        {
            mCurrentFrame = (mCurrentFrame + 1) % mNumFrames;
            if (mCurrentFrame == 0)
                textureRect = sf::IntRect(0, 0, mFrameSize.x, mFrameSize.y);
        }
        else
        {
            mCurrentFrame++;
        }
        
        mSprite.setTextureRect(textureRect);
    }
}