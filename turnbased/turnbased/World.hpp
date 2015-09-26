//
//  World.hpp
//  turnbased
//
//  Created by Ian Wilson on 9/18/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#ifndef turnbased_World_hpp
#define turnbased_World_hpp

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "SceneNode.hpp"
#include "SpriteNode.hpp"
#include "Hero.hpp"
#include "CommandQueue.hpp"
#include "Command.hpp"
#include "Animation.hpp"
#include "AnimatedSprite.hpp"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>
#include <queue>


// Forward declaration
namespace sf
{
    class RenderWindow;
}

class World : private sf::NonCopyable
{
public:
    explicit							World(sf::RenderWindow& window);
    void								update(sf::Time dt);
    void								draw();
    
    CommandQueue&						getCommandQueue();
    
    
private:
    void								loadTextures();
    void								buildScene();
    void								adaptPlayerPosition();
    void								adaptPlayerVelocity();
    
    
private:
    enum Layer
    {
        Background,
        Walkway,
        LayerCount
    };
    
    
private:
    sf::RenderWindow&					mWindow;
    sf::View							mWorldView;
    TextureHolder						mTextures;
    
    SceneNode							mSceneGraph;
    std::array<SceneNode*, LayerCount>	mSceneLayers;
    CommandQueue						mCommandQueue;
    
    sf::FloatRect						mWorldBounds;
    sf::Vector2f						mSpawnPosition;
    float								mScrollSpeed;
    Hero*                               mPlayerHero;
};

#endif
