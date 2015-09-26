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

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

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
: 
  mActor(actor)
, mSprite(textures.get(Table[actor].texture), Table[actor].textureRect)
{
    centerOrigin(mSprite);
    
    mMovement.setFrameSize(sf::Vector2i(256, 256));
    mMovement.setNumFrames(16);
    mMovement.setDuration(sf::seconds(1));
    
    centerOrigin(mMovement);
}


void Hero::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}

void Hero::updateCurrent(sf::Time dt, CommandQueue& commands)
{
    // Update texts and move animation
    updateMoveAnimation();
    
}


/*UNDER CONSTRUCTION*/
void Hero::updateMoveAnimation()
{
    sf::Clock clock;
    sf::Time animationTimer = sf::Time::Zero;
    int animItr = 0;
    
    if (Table[mActor].hasMoveAnimation)
    {
        sf::IntRect textureRect = Table[mActor].textureRect;
        
        // Moving Down: 1st row of texture rect
        while (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            textureRect.left += textureRect.width;
            if (textureRect.left == 256)
            {
                textureRect.left = 0;
            }
        }

        
        mSprite.setTextureRect(textureRect);
    }
}



