#pragma once
#include <Creature.h>

class Monster : public Creature
{
public:
    enum Type
    {
        dragon,
        orc,
        slime,
        max_types
    };
    static inline Creature monsterData[]{
        {"dragon", 'D', 20, 4, 100},
        {"orc", 'o', 4, 2, 25},
        {"slime", 's', 1, 1, 1}};

    Monster(Type monsterType) : Creature{monsterData[static_cast<std::size_t>(monsterType)]} {}
};