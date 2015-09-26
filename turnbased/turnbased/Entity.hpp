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
#include "CommandQueue.hpp"

class Entity : public SceneNode
{
public:
    void				setVelocity(sf::Vector2f velocity);
    void				setVelocity(float vx, float vy);
    void				accelerate(sf::Vector2f velocity);
    void				accelerate(float vx, float vy);
    sf::Vector2f		getVelocity() const;
    
    
private:
    virtual void		updateCurrent(sf::Time dt, CommandQueue&);
    
    
private:
    sf::Vector2f		mVelocity;

    
};

#endif /* defined(__turnbased__Entity__) */
