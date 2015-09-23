//
//  Category.hpp
//  turnbased
//
//  Created by Ian Wilson on 9/23/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#ifndef turnbased_Category_hpp
#define turnbased_Category_hpp

// Entity/scene node category, used to dispatch commands
namespace Category
{
    enum Type
    {
        None				= 0,
        Scene				= 1 << 0,
        PlayerHero          = 1 << 1,
        AlliedNPC           = 1 << 2,
        EnemyNPC            = 1 << 3,
    };
}


#endif
