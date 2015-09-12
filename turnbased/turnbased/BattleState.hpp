//
//  BattleState.hpp
//  turnbased
//
//  Created by Ian Wilson on 9/10/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#include "State.hpp"
#include "Container.hpp"
#include "ResourceHolder.hpp"
#include "ResourcePath.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#ifndef turnbased_BattleState_hpp
#define turnbased_BattleState_hpp

class BattleState : public State
{
    
public:
                        BattleState(StateStack& stack, Context context);
    
    virtual void        draw();
    virtual bool        update(sf::Time dt);
    virtual bool        handleEvent(const sf::Event& event);
    
private:
    void                loadTextures();
    void                buildScene();
    
private:
    sf::Sprite          mBackgroundSprite;
    sf::Text            mText;
    TextureHolder       mTextures;
    
    GUI::Container      mGUIContainer;
};


#endif
