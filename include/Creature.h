#pragma once

#include <string>
#include <string_view>

class StatModifier;

class Creature
{
public:
    Creature(
        std::string_view name, char symbol, int health,
        int damagePerAttack, int gold)
        : m_name{name}, m_symbol{symbol}, m_health{health}, m_damage{damagePerAttack}, m_gold{gold} {}

    std::string_view getName() const { return m_name; }
    char getSymbol() const { return m_symbol; }
    int getHealth() const { return m_health; }
    int getDamage() const { return m_damage; }
    int getGold() const { return m_gold; }

    void reduceHealth(int damage);
    bool isDead() const;
    void addGold(int amount);

    friend void applyModifier(const StatModifier modifier, Creature& creature);

protected:
    std::string m_name{};
    char m_symbol{};
    int m_health{};
    int m_damage{};
    int m_gold{};
};