//
//  SpriteNode.hpp
//  turnbased
//
//  Created by Ian Wilson on 9/6/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#ifndef __turnbased__SpriteNode__
#define __turnbased__SpriteNode__

#include "SceneNode.hpp"

#include <SFML/Graphics/Sprite.hpp>


class SpriteNode : public SceneNode
{
public:
    explicit			SpriteNode(const sf::Texture& texture);
    SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect);
    
    
private:
    virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    
    
private:
    sf::Sprite			mSprite;
};


#endif /* defined(__turnbased__SpriteNode__) */
