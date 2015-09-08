//
//  StringHelper.hpp
//  turnbased
//
//  Created by Ian Wilson on 9/7/15.
//  Copyright (c) 2015 WandA. All rights reserved.
//

#ifndef turnbased_StringHelper_hpp
#define turnbased_StringHelper_hpp

#include <sstream>

// Since std::to_string doesn't work on MinGW we have to implement
// our own to support all platforms.
template <typename T>
std::string toString(const T& value);

template <typename T>
std::string toString(const T& value)
{
    std::stringstream stream;
    stream << value;
    return stream.str();
}
#endif
