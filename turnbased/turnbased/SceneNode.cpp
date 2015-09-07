//
//  SceneNode.cpp
//  turnbased
//
//  Created by Ian Wilson on 9/6/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#include "SceneNode.hpp"
#include "Foreach.hpp"

#include <algorithm>
#include <cassert>


SceneNode::SceneNode()
: mChildren()
, mParent(nullptr)
{
}

void SceneNode::attachChild(Ptr child)
{
    child->mParent = this;
    mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode &node)
{
    auto found = std::find_if(mChildren.begin(), mChildren.end(), [&] (Ptr& p) -> bool { return p.get() ==  &node; } );
    
    assert(found != mChildren.end());
    
    Ptr result = std::move(*found);
    result->mParent = nullptr;
    mChildren.erase(found);
    return result;
}

void SceneNode::update(sf::Time dt)
{
    updateCurrent(dt);
    updateChildren(dt);
}

void SceneNode::updateCurrent(sf::Time dt)
{
}

void SceneNode::updateChildren(sf::Time dt)
{
    FOREACH(Ptr& child, mChildren)
    child->update(dt);
}