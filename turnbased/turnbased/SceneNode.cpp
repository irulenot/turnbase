//
//  SceneNode.cpp
//  turnbased
//
//  Created by Ian Wilson on 9/6/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#include "SceneNode.hpp"
#include "Command.hpp"

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

void SceneNode::update(sf::Time dt, CommandQueue& commands)
{
    updateCurrent(dt, commands);
    updateChildren(dt, commands);
}

void SceneNode::updateCurrent(sf::Time dt, CommandQueue& commands)
{
}

void SceneNode::updateChildren(sf::Time dt, CommandQueue& commands)
{

    for( const Ptr& child : mChildren)
        child->update(dt, commands);
    
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    
    drawCurrent(target, states);
    drawChildren(target, states);
}

void SceneNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
}

void SceneNode::drawChildren(sf::RenderTarget &target, sf::RenderStates states)const
{
    for (const Ptr& child : mChildren)
    {
        child->draw(target, states);
    }
}

sf::Transform SceneNode::getWorldTransform() const
{
    sf::Transform transform = sf::Transform::Identity;  //does nothing(wtf?????)
    
    for (const SceneNode* node = this; node != nullptr; node = node->mParent)   //traverses scenenode tree
        transform = node->getTransform() * transform;                           //to gather absolute trans
    
    return transform;
}

sf::Vector2f SceneNode::getWorldPosition() const
{
    return getWorldTransform() * sf::Vector2f();
}

void SceneNode::onCommand(const Command& command, sf::Time dt)
{
    // Command current node, if category matches
    if (command.category & getCategory())
        command.action(*this, dt);
    
    // Command children
    for (Ptr& child : mChildren)
    {
        child->onCommand(command, dt);
    }
}

unsigned int SceneNode::getCategory() const
{
    return Category::Scene;
}


