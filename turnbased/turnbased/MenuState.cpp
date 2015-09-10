//
//  MenuState.cpp
//  turnbased
//
//  Created by Ian Wilson on 9/9/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#include "MenuState.hpp"
#include "Utility.hpp"
#include "Button.hpp"
#include "ResourceHolder.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>


MenuState::MenuState(StateStack& stack, Context context)
: State(stack, context)
, mGUIContainer()
{
    sf::Texture& texture = context.textures->get(Textures::TitleScreen);
    mBackgroundSprite.setTexture(texture);
    
    auto playButton = std::make_shared<GUI::Button>(context);
    playButton->setPosition(100, 300);
    playButton->setText("Play");
    playButton->setCallback([this] ()
                            {
                                requestStackPop();
                                requestStackPush(States::Battle);
                            });
    
    auto exitButton = std::make_shared<GUI::Button>(context);
    exitButton->setPosition(100, 350);
    exitButton->setText("Exit");
    exitButton->setCallback([this] ()
                            {
                                requestStackPop();
                            });
    
    mGUIContainer.pack(playButton);
    mGUIContainer.pack(exitButton);
    
}

void MenuState::draw()
{
    sf::RenderWindow& window = *getContext().window;
    window.setView(window.getDefaultView());
    window.draw(mBackgroundSprite);
    window.draw(mGUIContainer);
}

bool MenuState::update(sf::Time)
{
    return true;
}

bool MenuState::handleEvent(const sf::Event& event)
{
    mGUIContainer.handleEvent(event);
    return false;
}
