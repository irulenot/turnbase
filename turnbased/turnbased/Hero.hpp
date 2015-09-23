//
//  Hero.hpp
//  turnbased
//
//  Created by Anthony Bilic on 9/10/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#ifndef __turnbased__Hero__
#define __turnbased__Hero__

#include "Entity.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"

#include <SFML/Graphics/Sprite.hpp>


class Hero : public Entity
{
    public:
        enum Actor
        {
            Link,
            ActorCount,
        };
    public:
        explicit                Hero(Actor actor, const TextureHolder& textures);
        virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    
    private:
        Actor					mActor;
        sf::Sprite				mSprite;
    
   
    
};

#endif /* defined(__turnbased__Hero__) */
