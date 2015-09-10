//
//  Component.hpp
//  turnbased
//
//  Created by Ian Wilson on 9/9/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#ifndef turnbased_Component_hpp
#define turnbased_Component_hpp

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include <memory>


namespace sf
{
    class Event;
}

namespace GUI   // Graphical User Interface
{
    
    class Component : public sf::Drawable, public sf::Transformable, private sf::NonCopyable
    {
    public:
        typedef std::shared_ptr<Component> Ptr;
        
        
    public:
        Component();
        virtual				~Component();
        
        virtual bool		isSelectable() const = 0;
        bool				isSelected() const;
        virtual void		select();
        virtual void		deselect();
        
        virtual bool		isActive() const;
        virtual void		activate();
        virtual void		deactivate();
        
        virtual void		handleEvent(const sf::Event& event) = 0;
        
        
    private:
        bool				mIsSelected;
        bool				mIsActive;
    };
    
}


#endif
