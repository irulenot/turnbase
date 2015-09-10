//
//  ResourceIdentifiers.hpp
//  Project U
//
//  Created by Ian Wilson on 8/25/15.
//  Copyright (c) 2015 Ian Wilson. All rights reserved.
//

#ifndef Project_U_ResourceIdentifiers_hpp
#define Project_U_ResourceIdentifiers_hpp

namespace sf
{
    class Texture;
    class Font;
}

namespace Textures
{
    enum ID
    {
        Mountain,
        TitleScreen,
        Buttons,
    };
}

namespace Fonts
{
    enum ID
    {
        Main
    };
    
}

template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID>      FontHolder;

#endif
