//
//  Species.hpp
//  pokengine
//
//  Created by Ryan Terry on 9/13/16.
//  Copyright © 2016 ryanterry131. All rights reserved.
//

#ifndef Species_hpp
#define Species_hpp

#include "Element.hpp"

#include <map>
#include <string>

typedef unsigned short SpeciesID;

class Species
{
private:
    static Species* Bulbasaur;
    static Species* Ivysaur;
    static Species* Venusaur;
    
    static std::map<SpeciesID, Species*> mRegisteredSpeciesMap;
    
    SpeciesID identifier;
    float   height,
    weight;
    Element&   element1,
    element2;
    std::string name;

    Species(SpeciesID indentifier, const Element& element1, const Element& element2);
    
public:
    static void InitSpecies();
    static void TeardownSpecies();
    static const Species* GetSpecies(SpeciesID);
    
    SpeciesID getSpeciesID() const;
    const Element& getElement1();
    const Element& getElement2();
    
    void setHeight(float height);
    void setWeight(float weight);
    float getHeight() const;
    float getWeight() const;

    virtual const std::string& getName() const;
    virtual void setName(const std::string& name);
    
    virtual bool evolves() const;
    virtual SpeciesID evolvesInto();
};

#endif /* Species_hpp */
