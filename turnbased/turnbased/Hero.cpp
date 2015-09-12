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
            break;
    }
}

Hero::Hero(Actor actor, const TextureHolder& textures)
: Entity(Table[actor].hitpoints, Table[actor].agility, Table[actor].attack)
, mActor(actor)
, mSprite(textures.get(toTextureID(actor)))
{
    centerOrigin(mSprite);
}


void Hero::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}