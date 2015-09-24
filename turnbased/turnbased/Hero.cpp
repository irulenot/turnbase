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
}


void Hero::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}

void Hero::updateCurrent(sf::Time dt, CommandQueue& commands)
{
    // Update texts and roll animation
    updateMoveAnimation();
}


/*UNDER CONSTRUCTION*/
void Hero::updateMoveAnimation()
{
    sf::Clock clock;
    sf::Time animationTimer = sf::Time::Zero;
    
    if (Table[mActor].hasMoveAnimation)
    {
        sf::IntRect textureRect = Table[mActor].textureRect;
        
        // Moving Down: 1st row of texture rect
        while (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            sf::Time dt = clock.restart();
            animationTimer += dt;
            textureRect.left += textureRect.width;
            if (animationTimer.asSeconds() >= 1.f)
            {
                textureRect.left = 0;
            }
        }

        
        mSprite.setTextureRect(textureRect);
    }
}
