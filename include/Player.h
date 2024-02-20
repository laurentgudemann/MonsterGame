#pragma once
#include <Creature.h>

class Player : public Creature
{
public:
    Player(std::string_view name)
        : Creature(name, '@', 10, 1, 0) {}

    void levelUp();

    int getLevel() const { return m_level; }

    bool hasWon() const { return m_level > 19; }

private:
    int m_level{1};
};