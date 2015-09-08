//
//  Application.cpp
//  Project U
//
//  Created by Ian Wilson on 8/25/15.
//  Copyright (c) 2015 Ian Wilson. All rights reserved.
//

#include "Application.hpp"
#include "ResourcePath.hpp"
#include "StringHelper.hpp"
#include "State.hpp"
#include "StateIdentifiers.hpp"
#include "TitleState.hpp"


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

const sf::Time Application::TimePerFrame = sf::seconds(1.f/60.f);

Application::Application()
: mWindow(sf::VideoMode(1234, 732), "Gameplay", sf::Style::Close)
, mTextures()
, mFonts()
, mStateStack(State::Context(mWindow, mTextures, mFonts))
{
    mWindow.setKeyRepeatEnabled(false);
    mWindow.setVerticalSyncEnabled(true);
    
    
    mFonts.load(Fonts::Main, resourcePath() + "sansation.ttf");
    
    mTextures.load(Textures::TitleScreen, resourcePath() + "Mountain.png");
    
    mStatisticsText.setFont(mFonts.get(Fonts::Main));
    mStatisticsText.setPosition(5.f, 5.f);
    mStatisticsText.setCharacterSize(10u);
    
    registerStates();
    mStateStack.pushState(States::Title);   // Initialize title screen

     
}

void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    
    while (mWindow.isOpen())
    {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            
            processInput();
            update(TimePerFrame);
            
            // Check inside this loop, because stack might be empty before update() call
            if (mStateStack.isEmpty())
                mWindow.close();
        }
        
        updateStatistics(dt);
        render();
    }

}

void Application::processInput()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        mStateStack.handleEvent(event);
        
        if (event.type == sf::Event::Closed)
            mWindow.close();
    }
    
}

void Application::update(sf::Time dt)
{
    mStateStack.update(dt);
}

void Application::render()
{
    mWindow.clear();
    
    mStateStack.draw();
    
    mWindow.setView(mWindow.getDefaultView());
    mWindow.draw(mStatisticsText);
    
    mWindow.display();
}

void Application::updateStatistics(sf::Time dt)
{
    mStatisticsUpdateTime += dt;
    mStatisticsNumFrames += 1;
    if (mStatisticsUpdateTime >= sf::seconds(1.0f))
    {
        mStatisticsText.setString("FPS: " + toString(mStatisticsNumFrames));
        
        mStatisticsUpdateTime -= sf::seconds(1.0f);
        mStatisticsNumFrames = 0;
    }

}
void Application::registerStates()
{
    mStateStack.registerState<TitleState>(States::Title);

}




