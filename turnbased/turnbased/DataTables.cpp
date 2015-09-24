//
//  DataTables.cpp
//  turnbased
//
//  Created by Ian Wilson on 9/12/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#include "DataTables.hpp"
#include "Hero.hpp"


std::vector<HeroData> initializeHeroData()  // Can create basic AI
{
    std::vector<HeroData> data(Hero::ActorCount);
    
    data[Hero::Cloud].speed = 200.f;
    data[Hero::Cloud].texture = Textures::Cloud;
    data[Hero::Cloud].textureRect = sf::IntRect(0, 0, 64, 64);
    data[Hero::Cloud].hasMoveAnimation = true;
    
    return data;
}