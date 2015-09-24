//
//  Application.hpp
//  Project U
//
//  Created by Ian Wilson on 8/25/15.
//  Copyright (c) 2015 Ian Wilson. All rights reserved.
//

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "Player.hpp"
#include "StateStack.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#ifndef Project_U_Application_hpp
#define Project_U_Application_hpp

class Application
{
public:
                            Application();
    void                    run();
    
private:
    void					processInput();
    void					update(sf::Time dt);
    void					render();
    
    void					updateStatistics(sf::Time dt);
    void					registerStates();
    
private:
    static const sf::Time   TimePerFrame;
    
    sf::RenderWindow        mWindow;
    TextureHolder           mTextures;
    FontHolder              mFonts;
    Player                  mPlayer;
    StateStack				mStateStack;
    
    sf::Text				mStatisticsText;
    sf::Time				mStatisticsUpdateTime;
    std::size_t				mStatisticsNumFrames;
};


#endif
