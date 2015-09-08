//
//  Application.cpp
//  Project U
//
//  Created by Ian Wilson on 8/25/15.
//  Copyright (c) 2015 Ian Wilson. All rights reserved.
//

#include "Application.hpp"
#include "ResourcePath.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


// TO DO
// 1. Be sure to include all states, include state identifiers
// 2. Utility file for math and other useful functions

const sf::Time Application::TimePerFrame = sf::seconds(1.f/60.f);

Application::Application()
: mWindow(sf::VideoMode(1234, 732), "Gameplay", sf::Style::Close)
, mTextures()
, mFonts()
{
    mWindow.setKeyRepeatEnabled(false);
    
    
    
    
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "Mountain.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);
    
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("turnbased deez nutz", font, 50);
    text.setColor(sf::Color::Black);
    
    /*
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
        return EXIT_FAILURE;
    }
    
    // Play the music
    music.play();
    */
     
    // Start the game loop
    while (mWindow.isOpen())
    {
        // Process events
        sf::Event event;
        while (mWindow.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                mWindow.close();
            }
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                mWindow.close();
            }
        }
        
        // Clear screen
        mWindow.clear();
        
        // Draw the sprite
        mWindow.draw(sprite);
        
        // Draw the string
        mWindow.draw(text);
        
        // Update the window
        mWindow.display();
    }
}

void Application::run()
{
    
}

void Application::processInput()
{
    
    
}

void Application::update(sf::Time dt)
{
    
}

void Application::render()
{
    
}