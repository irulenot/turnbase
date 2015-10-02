//
//  Hero.cpp
//  turnbased
//
//  Created by Anthony Bilic on 9/10/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#include "Hero.hpp"
#include "ResourceHolder.hpp"
#include "Utility.hpp"
#include "DataTables.hpp"
#include "Animation.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include <iostream>
#include <cmath>

namespace

{
    const std::vector<HeroData> Table = initializeHeroData();
}

Textures::ID toTextureID(Hero::Actor actor)
{
    switch (actor)
    {
        case Hero::Link:
            return Textures::Link;
            
        case Hero::Cloud:
            return Textures::Cloud;
            
    }
}

Hero::Hero(Actor actor, const TextureHolder& textures)
: mActor(actor)
, mSprite(textures.get(Table[actor].texture), Table[actor].textureRect)
, mMoveDown(textures.get(Textures::Cloud))
, mMoveUp(textures.get(Textures::Cloud))
, mMoveLeft(textures.get(Textures::Cloud))
, mMoveRight(textures.get(Textures::Cloud))

, mHasMoveAnimation(true)
{
    mMoveDown.setFrameSize(sf::Vector2i (64, 64));
    mMoveDown.setNumFrames(4);
    mMoveDown.setDuration(sf::seconds(0.25));
    
    mMoveUp.setFrameSize(sf::Vector2i (64, 64));
    mMoveUp.setNumFrames(4);
    mMoveUp.setDuration(sf::seconds(0.25));
    
    mMoveLeft.setFrameSize(sf::Vector2i (64, 64));
    mMoveLeft.setNumFrames(4);
    mMoveLeft.setDuration(sf::seconds(0.25));
    
    mMoveRight.setFrameSize(sf::Vector2i (64, 64));
    mMoveRight.setNumFrames(4);
    mMoveRight.setDuration(sf::seconds(0.25));
    
    centerOrigin(mSprite);
    
}


void Hero::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}

void Hero::updateCurrent(sf::Time dt, CommandQueue& commands)
{
    // Update texts and move animation
    updateMoveAnimation(dt, commands);
    
}


void Hero::updateMoveAnimation(sf::Time dt, CommandQueue& commands)
{
    mMoveDown.update(dt);
    mMoveLeft.update(dt);
    mMoveRight.update(dt);
    mMoveUp.update(dt);
}



