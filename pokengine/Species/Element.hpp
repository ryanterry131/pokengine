//
//  Element.hpp
//  pokengine
//
//  Created by Ryan Terry on 9/14/16.
//  Copyright © 2016 ryanterry131. All rights reserved.
//

#ifndef Element_hpp
#define Element_hpp

#include <unordered_map>
#include <string>

extern const std::string ElementNames[];

class Element
{
public:
    enum ElementID
    {
        ELEMENT_NONE = -1,
        
        ELEMENT_GRASS,
        ELEMENT_WATER,
        ELEMENT_FIRE,
        ELEMENT_NORMAL,
        ELEMENT_ROCK,
        ELEMENT_GROUND,
        ELEMENT_GHOST,
        ELEMENT_BUG,
        ELEMENT_FIGHTING,
        ELEMENT_DRAGON,
        ELEMENT_PSYCHIC,
        ELEMENT_FLYING,
        ELEMENT_ELECTRIC,
        ELEMENT_ICE,
        ELEMENT_POISON
    };
    
    struct Hash
    {
        std::size_t operator()(const Element& key) const
        {
            using std::hash;
            using std::string;
            
            return      ((hash<int>()(key.identifier)
                    ^   (hash<bool>()(key.isWater) << 1)) >> 1)
                    ^   (hash<bool>()(key.isRock) << 1);
        }
    };
    
private:
    ElementID identifier;
    bool isWater;
    bool isRock;
    std::unordered_map<Element, float, Element::Hash> effectivenessMap;
    
    Element(ElementID identifier, bool isWater, bool isRock);
    Element();
    
public:
    bool operator==(const Element& other) const
    {
        return  identifier == other.identifier &&
                isWater == other.isWater &&
                isRock == other.isRock;
    }
    
    const Element& setEffectiveness(const Element& other, float effectiveness);
    float getEffectivenessAgainst(const Element& other);
    bool affects(const Element& other);
    
    static void InitElements();
    
    static const int ELEMENT_COUNT = 15;
    static Element None;
    static Element Grass;
    static Element Water;
    static Element Fire;
    static Element Normal;
    static Element Rock;
    static Element Ground;
    static Element Ghost;
    static Element Bug;
    static Element Fighting;
    static Element Dragon;
    static Element Psychic;
    static Element Flying;
    static Element Electric;
    static Element Ice;
    static Element Poison;
    
};

#endif /* Element_hpp */
