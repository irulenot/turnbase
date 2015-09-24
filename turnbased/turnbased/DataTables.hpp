//
//  DataTables.hpp
//  turnbased
//
//  Created by Ian Wilson on 9/12/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#ifndef turnbased_DataTables_hpp
#define turnbased_DataTables_hpp

#include "ResourceIdentifiers.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>

#include <vector>
#include <functional>

class Hero;

struct Direction
{
    Direction(float angle, float distance)
    : angle(angle)
    , distance(distance)
    {
    }
    
    float angle;
    float distance;
};

struct HeroData
{
    float							speed;
    Textures::ID					texture;
    sf::IntRect						textureRect;
    std::vector<Direction>			directions;
    bool							hasMoveAnimation;
};

std::vector<HeroData>	initializeHeroData();



#endif
