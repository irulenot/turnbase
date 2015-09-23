//
//  GameState.hpp
//  turnbased
//
//  Created by Ian Wilson on 9/23/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#ifndef turnbased_GameState_hpp
#define turnbased_GameState_hpp

#include "State.hpp"
#include "World.hpp"         // Work on these
#include "Player.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class GameState : public State
{
public:
    GameState(StateStack& stack, Context context);
    
    virtual void		draw();
    virtual bool		update(sf::Time dt);
    virtual bool		handleEvent(const sf::Event& event);
    
    
private:
    World				mWorld;
    Player&				mPlayer;
};

#endif
