#include <Creature.h>

void Creature::reduceHealth(int damage)
{
    m_health = m_health < damage ? 0 : m_health - damage;
}

bool Creature::isDead() const
{
    return m_health < 1;
}

void Creature::addGold(int amount)
{
    m_gold += amount;
}