//
//  Enemy.h
//  turnbased
//
//  Created by Anthony Bilic on 9/10/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#ifndef __turnbased__Enemy__
#define __turnbased__Enemy__

#include <stdio.h>
#include "Entity.hpp"

class Enemy : public Entity
{
private:
    void updateCurrent(sf::Time dt);
public:
    
};

#endif /* defined(__turnbased__Enemy__) */