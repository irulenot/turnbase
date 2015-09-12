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
    
    data[Hero::Link].hitpoints = 100;
    data[Hero::Link].agility = 20;
    data[Hero::Link].attack = 20;
    data[Hero::Link].texture = Textures::Link;
    
    return data;
}