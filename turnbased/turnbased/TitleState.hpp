//
//  TitleState.hpp
//  turnbased
//
//  Created by Ian Wilson on 9/7/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#include "State.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#ifndef turnbased_TitleState_hpp
#define turnbased_TitleState_hpp

class TitleState : public State
{
    
public:
                        TitleState(StateStack& stack, Context context);
    
    virtual void        draw();
    virtual bool        update(sf::Time dt);
    virtual bool        handleEvent(const sf::Event& event);
    
private:
    sf::Sprite          mBackgroundSprite;
    sf::Text            mText;
    
    bool                mShowText;
    sf::Time            mTextEffectTime;
};

#endif
