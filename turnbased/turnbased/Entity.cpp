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
attackStat(atk),
healthCurrent(hp),
agilityCurrent(agi)
{}

void Entity::takeDmg(int dmg)
    {this->healthCurrent = (this->healthCurrent) - (dmg);}

int Entity::giveAtk()
    {return this->attackStat;}

int Entity::giveSpd()
    {return this->agilityStat;}

int Entity::giveCurAgi()
    {return this->agilityCurrent;}

int Entity::giveCurHlt()
    {return this->healthCurrent;}

void Entity::changeHlt(int affect)
    {this->healthCurrent = this->healthCurrent + affect;}

void Entity::clearCurAgi()
    {this->agilityCurrent = 0;}

void Entity::resetCurAgi()
    {this->agilityCurrent = this->agilityStat;}

void Entity::updateCurrent(sf::Time dt)
{

}


