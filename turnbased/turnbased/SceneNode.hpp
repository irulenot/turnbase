//
//  SceneNode.h
//  turnbased
//
//  Created by Ian Wilson on 9/6/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#ifndef __turnbased__SceneNode__
#define __turnbased__SceneNode__

#include "Category.hpp"

#include <SFML/System/Noncopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <vector>
#include <memory>

struct Command;

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
    typedef std::unique_ptr<SceneNode> Ptr;
    
public:
                            SceneNode();
    
    void                    attachChild(Ptr child);
    Ptr                     detachChild(const SceneNode& node);
    
    void                    update(sf::Time dt);
    
    sf::Vector2f			getWorldPosition() const;       //returns ABSOLUTE position
    sf::Transform			getWorldTransform() const;      // accounts for all parent transforms
    
    void					onCommand(const Command& command, sf::Time dt);
    virtual unsigned int	getCategory() const;
    
private:
    virtual void			updateCurrent(sf::Time dt);
    void					updateChildren(sf::Time dt);
    
    virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    void					drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
    
private:
    std::vector<Ptr>        mChildren;
    SceneNode*              mParent;
};



#endif /* defined(__turnbased__SceneNode__) */
