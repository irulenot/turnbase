//
//  State.hpp
//  turnbased
//
//  Created by Ian Wilson on 9/7/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

//  Each State is defined as an individual screen that is rendered in the window. For example, the company logos, the introductory cutscene, the title screen, and the menu screen would each be considered states

#ifndef __turnbased__State__
#define __turnbased__State__

#include "StateIdentifiers.hpp"
#include "ResourceIdentifiers.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include <memory>

class StateStack;

namespace sf
{
    class RenderWindow;
}

class State
{
public:
    typedef std::unique_ptr<State> Ptr;
    
    struct Context
    {
                            Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts);
        
        sf::RenderWindow*	window;
        TextureHolder*		textures;
        FontHolder*			fonts;
    };
    
    
public:
                            State(StateStack& stack, Context context);
    virtual                 ~State();
    
    virtual void            draw() = 0;
    virtual bool            update(sf::Time dt) = 0;
    virtual bool            handleEvent(const sf::Event& event) = 0;
    
    virtual void            onActivate();
    virtual void            onDestroy();
    
protected:
    void                    requestStackPush(States::ID stateID);
    void                    requestStackPop();
    void                    requestStateClear();
    
    Context                 getContext() const;
    
private:
    StateStack*             mStack;
    Context                 mContext;
    
    
};

#endif /* defined(__turnbased__State__) */








