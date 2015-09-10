//
//  Component.cpp
//  turnbased
//
//  Created by Ian Wilson on 9/9/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#include "Component.hpp"

namespace GUI
{
    
    Component::Component()
    : mIsSelected(false)
    , mIsActive(false)
    {
    }
    
    Component::~Component()
    {
    }
    
    bool Component::isSelected() const
    {
        return mIsSelected;
    }
    
    void Component::select()
    {
        mIsSelected = true;
    }
    
    void Component::deselect()
    {
        mIsSelected = false;
    }
    
    bool Component::isActive() const
    {
        return mIsActive;
    }
    
    void Component::activate()
    {
        mIsActive = true;
    }
    
    void Component::deactivate()
    {
        mIsActive = false;
    }
    
}