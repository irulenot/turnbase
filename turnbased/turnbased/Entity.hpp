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
    virtual void updateCurrent(sf::Time dt);
    
    
};

#endif /* defined(__turnbased__Entity__) */
