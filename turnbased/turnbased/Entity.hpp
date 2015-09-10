//
//  Entity.hpp
//  turnbased
//
//  Created by Ian Wilson on 9/6/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#ifndef __turnbased__Entity__
#define __turnbased__Entity__

#include "SceneNode.hpp"

class Entity : public SceneNode
{
    private:
        int healthStat;
        int agilityStat;
        int healthCurrent;
        int basicAtk;
        
        virtual void updateCurrent(sf::Time dt);

    public:
        Entity(int hp, int agi, int atk);
        void takeDmg(int dmg);
        int giveAtk();
    
};

#endif /* defined(__turnbased__Entity__) */
