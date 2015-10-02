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
#include "CommandQueue.hpp"
#include "Animation.hpp"

#include <SFML/Graphics/Sprite.hpp>

class Hero : public Entity
{
    public:
        enum Actor
        {
            Link,
            Cloud,
            ActorCount,
        };
    public:
        explicit                Hero(Actor actor, const TextureHolder& textures);
    
    private:
        virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
        void					updateMoveAnimation(sf::Time dt, CommandQueue& commands);
        virtual void 			updateCurrent(sf::Time dt, CommandQueue& commands);
        void                    setTextureRect(int left, int top, int width, int height);
    
    private:
        Actor					mActor;
        sf::Sprite				mSprite;
        Animation               mMoveDown;
        Animation               mMoveUp;
        Animation               mMoveLeft;
        Animation               mMoveRight;
        bool                    mHasMoveAnimation;

    
    
   
    
};

#endif /* defined(__turnbased__Hero__) */
