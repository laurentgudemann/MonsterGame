#pragma once

#include <string>
#include <string_view>

class Creature
{
public:
    Creature(
        std::string_view name, char symbol, int health,
        int damagePerAttack, int gold)
        : m_name{name}, m_symbol{symbol}, m_health{health}, m_gold{gold} {}

    std::string_view getName() const { return m_name; }
    char getSymbol() const { return m_symbol; }
    int getHealth() const { return m_health; }
    int getDamagePerAttack() const { return m_damagePerAttack; }
    int getGold() const { return m_gold; }

    void reduceHealth(int damage);
    bool isDead() const;
    void addGold(int amount);

protected:
    std::string m_name{};
    char m_symbol{};
    int m_health{};
    int m_damagePerAttack{};
    int m_gold{};
};