//
//  Player.hpp
//  turnbased
//
//  Created by Ian Wilson on 9/23/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#ifndef __turnbased__Player__
#define __turnbased__Player__

#include "Command.hpp"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Window/Event.hpp>

#include <map>

class CommandQueue;

class Player
{
public:
    enum Action
    {
        MoveLeft,
        MoveRight,
        MoveUp,
        MoveDown,
        ActionCount
    };
    
    
public:
    Player();
    
    void					handleEvent(const sf::Event& event, CommandQueue& commands);
    void					handleRealtimeInput(CommandQueue& commands);
    
    void					assignKey(Action action, sf::Keyboard::Key key);
    sf::Keyboard::Key		getAssignedKey(Action action) const;
    
    
private:
    void					initializeActions();
    static bool				isRealtimeAction(Action action);
    
    
private:
    std::map<sf::Keyboard::Key, Action>		mKeyBinding;
    std::map<Action, Command>				mActionBinding;
};

#endif /* defined(__turnbased__Player__) */
