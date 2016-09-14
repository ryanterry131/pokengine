//
//  main.cpp
//  pokengine
//
//  Created by Ryan Terry on 9/14/16.
//  Copyright © 2016 ryanterry131. All rights reserved.
//

#include "Species/Element.hpp"
#include "Species/Species.hpp"

int main()
{
    Element::InitElements();
    Species::InitSpecies();
    
    
    
    Species::TeardownSpecies();
    
    return 0;
}