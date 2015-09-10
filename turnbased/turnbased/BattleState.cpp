//
//  BattleState.cpp
//  turnbased
//
//  Created by Ian Wilson on 9/10/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#include "BattleState.hpp"
#include "Utility.hpp"
#include "Button.hpp"
#include "ResourceHolder.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

BattleState::BattleState(StateStack& stack, Context context)
: State(stack, context)
, mGUIContainer()
{
    sf::Texture& texture = context.textures->get(Textures::Mountain);
    mBackgroundSprite.setTexture(texture);
    
    auto atkButton = std::make_shared<GUI::Button>(context);
    atkButton->setPosition(100, 668);
    atkButton->setText("Attack");
    atkButton->setCallback([this] ()
                            {
                                requestStackPop();
                                //requestStackPush(States::Game);
                            });
    
    auto runButton = std::make_shared<GUI::Button>(context);
    runButton->setPosition(100, 618);
    runButton->setText("Run");
    runButton->setCallback([this] ()
                            {
                                requestStackPop();
                                requestStackPush(States::Menu);
                            });
    
    mGUIContainer.pack(atkButton);
    mGUIContainer.pack(runButton);
    
}

void BattleState::draw()
{
    sf::RenderWindow& window = *getContext().window;
    window.setView(window.getDefaultView());
    window.draw(mBackgroundSprite);
    window.draw(mGUIContainer);
}

bool BattleState::update(sf::Time)
{
    return true;
}

bool BattleState::handleEvent(const sf::Event& event)
{
    mGUIContainer.handleEvent(event);
    return false;
}