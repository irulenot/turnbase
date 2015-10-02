//
//  Animation.cpp
//  turnbased
//
//  Created by Ian Wilson on 10/1/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#include "Animation.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>


Animation::Animation()
: mSprite()
, mFrameSize()
, mNumFrames(0)
, mCurrentFrame(0)
, mDuration(sf::Time::Zero)
, mElapsedTime(sf::Time::Zero)
, mRepeat(false)
{
}

Animation::Animation(const sf::Texture& texture)
: mSprite(texture)
, mFrameSize()
, mNumFrames(0)
, mCurrentFrame(0)
, mDuration(sf::Time::Zero)
, mElapsedTime(sf::Time::Zero)
, mRepeat(false)
{
}

void Animation::setTexture(const sf::Texture& texture)
{
    mSprite.setTexture(texture);
}

const sf::Texture* Animation::getTexture() const
{
    return mSprite.getTexture();
}

void Animation::setFrameSize(sf::Vector2i frameSize)
{
    mFrameSize = frameSize;
}

sf::Vector2i Animation::getFrameSize() const
{
    return mFrameSize;
}

void Animation::setNumFrames(std::size_t numFrames)
{
    mNumFrames = numFrames;
}

std::size_t Animation::getNumFrames() const
{
    return mNumFrames;
}

void Animation::setDuration(sf::Time duration)
{
    mDuration = duration;
}

sf::Time Animation::getDuration() const
{
    return mDuration;
}

void Animation::setRepeating(bool flag)
{
    mRepeat = flag;
}

bool Animation::isRepeating() const
{
    return mRepeat;
}

void Animation::restart()
{
    mCurrentFrame = 0;
}

bool Animation::isFinished() const
{
    return mCurrentFrame >= mNumFrames;
}

sf::FloatRect Animation::getLocalBounds() const
{
    return sf::FloatRect(getOrigin(), static_cast<sf::Vector2f>(getFrameSize()));
}

sf::FloatRect Animation::getGlobalBounds() const
{
    return getTransform().transformRect(getLocalBounds());
}

void Animation::update(sf::Time dt)
{
    sf::Time timePerFrame = mDuration / static_cast<float>(mNumFrames);
    mElapsedTime += dt;
    
    sf::Vector2i textureBounds(mSprite.getTexture()->getSize());
    sf::IntRect textureRect = mSprite.getTextureRect();
    
    if (mCurrentFrame == 0)
        textureRect = sf::IntRect(0, 0, mFrameSize.x, mFrameSize.y);
    
    // While we have a frame to process
    while (mElapsedTime >= timePerFrame && (mCurrentFrame <= mNumFrames || mRepeat))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            textureRect.left += textureRect.width;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            textureRect.top += textureRect.height;
            textureRect.left += textureRect.width;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            textureRect.top += (2 * textureRect.height);
            textureRect.left += textureRect.width;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            textureRect.top += (3 * textureRect.height);
            textureRect.left += textureRect.width;
        }
        // If we reach the end of the texture
        if (textureRect.left + textureRect.width > textureBounds.x)
        {
            // Return to beginning of line
            textureRect.left = 0;
        }
        
        // And progress to next frame
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
    }
    
    mSprite.setTextureRect(textureRect);
}

void Animation::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(mSprite, states);
}
