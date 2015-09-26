//
//  Animation.h
//  turnbased
//
//  Created by Ian Wilson on 9/26/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#ifndef __turnbased__AnimatedSprite__
#define __turnbased__AnimatedSprite__

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>

#include "Animation.hpp"

class Animation;

class AnimatedSprite : public sf::Drawable, public sf::Transformable
{
public:
                            AnimatedSprite();
    explicit 				AnimatedSprite(const sf::Texture& texture);
    
    void                    setAnimation(const Animation& animation);
    const Animation*        getAnimation() const;
    
    void 					setTexture(const sf::Texture& texture);
    const sf::Texture* 		getTexture() const;
    
    void 					setFrameSize(sf::Vector2i mFrameSize);
    sf::Vector2i		 	getFrameSize() const;
    
    void 					setNumFrames(std::size_t numFrames);
    std::size_t 			getNumFrames() const;
    
    void 					setDuration(sf::Time duration);
    sf::Time 				getDuration() const;
    
    void                    play();
    void                    play(const Animation& animation);
    
    void                    pause();
    void                    stop();
    
    void 					setRepeating(bool flag);
    bool 					isRepeating() const;
    
    void 					restart();
    bool 					isFinished() const;
    
    sf::FloatRect 			getLocalBounds() const;
    sf::FloatRect 			getGlobalBounds() const;
    
    void 					update(sf::Time dt);
    
private:
    void 					draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    
    const Animation*        mAnimation;
    sf::Sprite              mSprite;
    sf::Vector2i            mFrameSize;
    std::size_t             mNumFrames;
    std::size_t             mCurrentFrame;
    sf::Time                mElapsedTime;
    sf::Time                mDuration;
    bool                    mRepeat;
    bool                    mIsPaused;
    
};
#endif
