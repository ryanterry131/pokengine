//
//  Species.cpp
//  pokengine
//
//  Created by Ryan Terry on 9/13/16.
//  Copyright © 2016 ryanterry131. All rights reserved.
//

#include "Species.hpp"

/* Pokemon Species */
Species* Species::Bulbasaur;
Species* Species::Ivysaur;
Species* Species::Venusaur;


std::map<SpeciesID, Species*> Species::mRegisteredSpeciesMap;
void Species::InitSpecies()
{
    /* TODO: Each species should have their own class */
    Bulbasaur = new Species(001, Element::Grass, Element::Poison);
    Ivysaur = new Species(002, Element::Grass, Element::Poison);
    Venusaur = new Species(003, Element::Grass, Element::Poison);
}
void Species::TeardownSpecies()
{
    for(auto it = mRegisteredSpeciesMap.begin(); it != mRegisteredSpeciesMap.end(); it++)
    {
        if(it->second)
        {
            delete it->second;
        }
    }
}

const Species* Species::GetSpecies(SpeciesID identifier)
{
    return mRegisteredSpeciesMap[identifier];
}

Species::Species(SpeciesID identifier, const Element& element1, const Element& element2)
:   identifier(identifier),
    height(1.0F),
    weight(1.0F),
    element1((Element&) element1),
    element2((Element&) element2)
{
    mRegisteredSpeciesMap[identifier] = this;
}

SpeciesID Species::getSpeciesID() const
{
    return this->identifier;
}

const Element& Species::getElement1()
{
    return element1;
}

const Element& Species::getElement2()
{
    return element2;
}

void Species::setHeight(float height)
{
    this->height = height;
}

void Species::setWeight(float weight)
{
    this->weight = weight;
}

float Species::getHeight() const
{
    return height;
}

float Species::getWeight() const
{
    return weight;
}

const std::string& Species::getName() const
{
    return name;
}

void Species::setName(const std::string& name)
{
    this->name = name;
}

bool Species::evolves() const
{
    return false;
}

SpeciesID Species::evolvesInto()
{
    return 0;
}
