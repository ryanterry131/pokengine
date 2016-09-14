//
//  Element.cpp
//  pokengine
//
//  Created by Ryan Terry on 9/14/16.
//  Copyright © 2016 ryanterry131. All rights reserved.
//

#include "Element.hpp"

const std::string ElementNames[] =
{
    "NONE",
    "GRASS",
    "WATER",
    "FIRE",
    "NORMAL",
    "ROCK",
    "GROUND",
    "GHOST",
    "BUG",
    "FIGHTING",
    "DRAGON",
    "PSYCHIC",
    "FLYING",
    "ELECTRIC",
    "ICE",
    "POISON"
};

/* Element used for Curse("???") */
Element Element::None;
Element Element::Grass;
Element Element::Water;
Element Element::Fire;
Element Element::Normal;
Element Element::Rock;
Element Element::Ground;
Element Element::Ghost;
Element Element::Bug;
Element Element::Fighting;
Element Element::Dragon;
Element Element::Psychic;
Element Element::Flying;
Element Element::Electric;
Element Element::Ice;
Element Element::Poison;

void Element::InitElements()
{
    None = Element(ElementID::ELEMENT_NONE, false, false);
    Grass = Element(ElementID::ELEMENT_GRASS, false, false);
    Water = Element(ElementID::ELEMENT_WATER, true, false);
    Fire = Element(ElementID::ELEMENT_FIRE, false, false);
    Normal = Element(ElementID::ELEMENT_NORMAL, false, false).setEffectiveness(Ghost, 0.0F);
    Rock = Element(ElementID::ELEMENT_ROCK, false, true);
    Ground = Element(ElementID::ELEMENT_GROUND, false, true).setEffectiveness(Flying, 0.0F);
    Ghost = Element(ElementID::ELEMENT_GHOST, false, false).setEffectiveness(Normal, 0.0F);
    Bug = Element(ElementID::ELEMENT_BUG, false, false);
    Fighting = Element(ElementID::ELEMENT_FIGHTING, false, false).setEffectiveness(Ghost, 0.0F);
    Dragon = Element(ElementID::ELEMENT_DRAGON, false, false);
    Psychic = Element(ElementID::ELEMENT_PSYCHIC, false, false);
    Flying = Element(ElementID::ELEMENT_FLYING, false, false);
    Electric = Element(ElementID::ELEMENT_ELECTRIC, false, false).setEffectiveness(Ground, 0.0F);
    Ice = Element(ElementID::ELEMENT_ICE, false, false);
    Poison = Element(ElementID::ELEMENT_POISON, false, false);
}

Element::Element(ElementID identifier, bool isWater, bool isRock)
:   identifier(identifier),
    isWater(isWater),
    isRock(isRock)
{}

Element::Element()
:   Element(ElementID::ELEMENT_NONE, false, false)
{}

const Element& Element::setEffectiveness(const Element& other, float effectiveness)
{
    effectivenessMap[other] = effectiveness;
    return *this;
}

float Element::getEffectivenessAgainst(const Element& other)
{
    return effectivenessMap[other];
}

bool Element::affects(const Element& other)
{
    return effectivenessMap[other] != 0.0F;
}
