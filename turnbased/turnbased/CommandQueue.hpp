//
//  CommandQueue.hpp
//  turnbased
//
//  Created by Ian Wilson on 9/23/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#ifndef turnbased_CommandQueue_hpp
#define turnbased_CommandQueue_hpp

#include "Command.hpp"

#include <queue>


class CommandQueue
{
public:
    void						push(const Command& command);
    Command						pop();
    bool						isEmpty() const;
    
    
private:
    std::queue<Command>			mQueue;
};


#endif
