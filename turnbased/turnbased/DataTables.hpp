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

struct HeroData
{
    int								hitpoints;
    int                             agility;
    int                             attack;
    Textures::ID					texture;
};

std::vector<HeroData>	initializeHeroData();



#endif
