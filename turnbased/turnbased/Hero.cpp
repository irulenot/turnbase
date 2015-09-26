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
    
    Animation walkAnimationDown;
    walkAnimationDown.setSpriteSheet(textures);
    walkAnimationDown.addFrame(sf::IntRect(0, 0, 64, 64));
    walkAnimationDown.addFrame(sf::IntRect(64, 0, 64, 64));
    walkAnimationDown.addFrame(sf::IntRect(128, 0, 64, 64));
    walkAnimationDown.addFrame(sf::IntRect(192, 0, 64, 64));
    
    Animation walkAnimationLeft;
    walkAnimationLeft.setSpriteSheet(textures);
    walkAnimationLeft.addFrame(sf::IntRect(0, 64, 64, 64));
    walkAnimationLeft.addFrame(sf::IntRect(64, 64, 64, 64));
    walkAnimationLeft.addFrame(sf::IntRect(128, 64, 64, 64));
    walkAnimationLeft.addFrame(sf::IntRect(192, 64, 64, 64));

    Animation walkAnimationRight;
    walkAnimationRight.setSpriteSheet(textures);
    walkAnimationRight.addFrame(sf::IntRect(0, 128, 64, 64));
    walkAnimationRight.addFrame(sf::IntRect(64, 128, 64, 64));
    walkAnimationRight.addFrame(sf::IntRect(128, 128, 64, 64));
    walkAnimationRight.addFrame(sf::IntRect(192, 128, 64, 64));
    
    Animation walkAnimationUp;
    walkAnimationUp.setSpriteSheet(textures);
    walkAnimationUp.addFrame(sf::IntRect(0, 192, 64, 64));
    walkAnimationUp.addFrame(sf::IntRect(64, 192, 64, 64));
    walkAnimationUp.addFrame(sf::IntRect(128, 192, 64, 64));
    walkAnimationUp.addFrame(sf::IntRect(192, 192, 64, 64));

    Animation* currentAnimation = &walkAnimationDown;
    
    AnimatedSprite animatedSprite;
    centerOrigin(animatedSprite);
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


void Hero::updateMoveAnimation()
{
    float speed = 80.f;
    bool noKeyWasPressed = true;
    
    sf::Vector2f movement(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        currentAnimation = &walkAnimationUp;
        movement.y -= speed;
        noKeyWasPressed = false;
    }
}



