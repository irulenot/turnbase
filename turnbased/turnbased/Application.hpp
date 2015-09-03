//
//  Application.hpp
//  Project U
//
//  Created by Ian Wilson on 8/25/15.
//  Copyright (c) 2015 Ian Wilson. All rights reserved.
//

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#ifndef Project_U_Application_hpp
#define Project_U_Application_hpp

class Application
{
public:
                            Application();
    void                    run();
    
private:    //functions
    void					processInput();
    void					update(sf::Time dt);
    void					render();
    
private:    //variables
    static const sf::Time   TimePerFrame;
    
    sf::RenderWindow        mWindow;
    TextureHolder           mTextures;
    FontHolder              mFonts;
};


#endif
