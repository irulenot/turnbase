//
//  Animation.hpp
//  turnbased
//
//  Created by Ian Wilson on 9/26/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#ifndef __turnbased__Animation__
#define __turnbased__Animation__

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"

#include <vector>

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>

class Animation
{
public:
    Animation();
    
    void addFrame(sf::IntRect rect);
    void setSpriteSheet(const TextureHolder& texture);
    const TextureHolder getSpriteSheet() const;
    std::size_t getSize() const;
    const sf::IntRect& getFrame(std::size_t n) const;
    
private:
    std::vector<sf::IntRect> m_frames;
    TextureHolder mTexture;
};
#endif /* defined(__turnbased__Animation__) */
