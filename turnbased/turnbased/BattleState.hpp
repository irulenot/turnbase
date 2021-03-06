//
//  BattleState.hpp
//  turnbased
//
//  Created by Ian Wilson on 9/10/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#include "State.hpp"
#include "Container.hpp"
#include "SpriteNode.hpp"
#include "SceneNode.hpp"
#include "Hero.hpp"
#include "ResourceHolder.hpp"
#include "ResourcePath.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>
#include <queue>

#ifndef turnbased_BattleState_hpp
#define turnbased_BattleState_hpp

class BattleState : public State
{
    
public:
                        BattleState(StateStack& stack, Context context);
    
    virtual void        draw();
    virtual bool        update(sf::Time dt);
    virtual bool        handleEvent(const sf::Event& event);
    
    
private:
    enum Layer
    {
        Background,
        Actors,
        LayerCount
    };
    
private:
    sf::Text            mText;

    Hero*               mHero;
    sf::Sprite          mBackgroundSprite;
    TextureHolder       mTextures;
    SceneNode           mSceneGraph;
    
    std::array<SceneNode*, LayerCount>	mSceneLayers;

    
    GUI::Container      mGUIContainer;
};


#endif
