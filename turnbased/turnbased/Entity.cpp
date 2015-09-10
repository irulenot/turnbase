//
//  Entity.cpp
//  turnbased
//
//  Created by Ian Wilson on 9/6/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#include "Entity.hpp"

Entity::Entity(int hp, int agi, int atk)
:
healthStat(hp),
agilityStat(agi),
healthCurrent(hp),
basicAtk(atk)
{}

void Entity::takeDmg(int dmg)
    {this->healthCurrent = (this->healthCurrent) - (dmg);}

int Entity::giveAtk()
    {return this->basicAtk;}

void Entity::updateCurrent(sf::Time dt)
{

}


