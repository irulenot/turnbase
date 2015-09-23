//
//  CommandQueue.cpp
//  turnbased
//
//  Created by Ian Wilson on 9/23/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#include "CommandQueue.hpp"
#include "SceneNode.hpp"


void CommandQueue::push(const Command& command)
{
    mQueue.push(command);
}

Command CommandQueue::pop()
{
    Command command = mQueue.front();
    mQueue.pop();
    return command;
}

bool CommandQueue::isEmpty() const
{
    return mQueue.empty();
}
