//
//  StateStack.hpp
//  turnbased
//
//  Created by Ian Wilson on 9/7/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#ifndef __turnbased__StateStack__
#define __turnbased__StateStack__

#include "State.hpp"
#include "StateIdentifiers.hpp"
#include "ResourceIdentifiers.hpp"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>

#include <vector>
#include <utility>
#include <functional>
#include <map>

namespace sf 
{
    class RenderWindow;
    class Event;
}
class StateStack : private sf::NonCopyable
{
public:
    enum Action
    {
        Push,
        Pop,
        Clear
    };
    
public:
    explicit            StateStack(State::Context context);
    
    template <typename T>
    void                registerState(States::ID stateID);
    
    void                update(sf::Time dt);
    void                draw();
    void                handleEvent(sf::Event& event);
    
    void                pushState(States::ID stateID);
    void                popState();
    void                clearStates();
    
    bool                isEmpty() const;
    
private:
    State::Ptr          createState(States::ID stateID);
    void                applyPendingChanges();
    
private:
    struct PendingChange
    {
        explicit		PendingChange(Action action, States::ID stateID = States::None);
        
        Action          action;
        States::ID      stateID;
    };

private:
    std::vector<State::Ptr>         mStack;
    std::vector<PendingChange>      mPendingList;
    State::Context                  mContext;
    std::map<States::ID,                            // See STL documentation for <map> and <functional>
    std::function<State::Ptr()>>      mFactories;
    
};

template <typename T>
void StateStack::registerState(States::ID stateID)
{
    mFactories[stateID] = [this] ()
    {
        return State::Ptr(new T(*this, mContext));
    };
}

#endif /* defined(__turnbased__StateStack__) */
