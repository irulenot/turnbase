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
        int mHitpoints;
        int mAgility;
        int mAttack;
    
        virtual void updateCurrent(sf::Time dt);

    public:
        Entity(int hp, int agi, int atk);
        void takeDmg(int dmg);
        int giveSpd();
        int giveAtk();
        int giveCurAgi();
        int giveCurHlt();
        void changeHlt(int affect);
        void clearCurAgi();
        void resetCurAgi();
    
};

#endif /* defined(__turnbased__Entity__) */
