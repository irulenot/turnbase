//
//  Animation.cpp
//  turnbased
//
//  Created by Ian Wilson on 9/26/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#include "Animation.hpp"

Animation::Animation() : m_texture(NULL)
{
    
}

void Animation::addFrame(sf::IntRect rect)
{
    m_frames.push_back(rect);
}

void Animation::setSpriteSheet(const sf::Texture& texture)
{
    m_texture = &texture;
}

const sf::Texture* Animation::getSpriteSheet() const
{
    return m_texture;
}

std::size_t Animation::getSize() const
{
    return m_frames.size();
}

const sf::IntRect& Animation::getFrame(std::size_t n) const
{
    return m_frames[n];
}