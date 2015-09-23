//
//  Command.hpp
//  turnbased
//
//  Created by Ian Wilson on 9/23/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#ifndef turnbased_Command_h
#define turnbased_Command_h

#include "Category.hpp"

#include <SFML/System/Time.hpp>

#include <functional>
#include <cassert>


class SceneNode;

struct Command
{
    Command();
    
    std::function<void(SceneNode&, sf::Time)>	action;
    unsigned int								category;
};

template <typename GameObject, typename Function>
std::function<void(SceneNode&, sf::Time)> derivedAction(Function fn)
{
    return [=] (SceneNode& node, sf::Time dt)
    {
        // Check if cast is safe
        assert(dynamic_cast<GameObject*>(&node) != nullptr);
        
        // Downcast node and invoke function on it
        fn(static_cast<GameObject&>(node), dt);
    };
}

#endif
