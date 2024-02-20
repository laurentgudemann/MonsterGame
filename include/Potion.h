#pragma once
#include <Random.h>

class Creature;

class StatModifier
{
public:
    StatModifier(int health, int damage)
        : m_health{health}, m_damage{damage}
    {
    }

    friend void applyModifier(const StatModifier modifier, Creature& creature);

private:
    int m_health{};
    int m_damage{};
};


class Potion : public StatModifier
{
public:
    enum Type
    {
        health,
        strength,
        poison,
        max_types
    };

    enum Effect
    {
        small,
        medium,
        large,
        max_effects
    };

    static inline StatModifier potionData[]{
        {2, 0},
        {2, 0},
        {5, 0},
        {0, 1},
        {0, 2},
        {0, 3},
        {-1, 0},
        {-1, 0},
        {-1, 0}};

    Potion(Type type, Effect effect)
        : StatModifier{
              potionData[static_cast<std::size_t>(type * Type::max_types) + static_cast<std::size_t>(effect)]},
          m_type{type}, m_effect{effect}
    {
    }

    static Potion getRandomPotion()
    {
        return Potion{static_cast<Type>(Random::get(0, Type::max_types - 1)), static_cast<Effect>(Random::get(0, Effect::max_effects - 1))};
    }

    friend std::ostream &operator<<(std::ostream &out, const Potion &potion)
    {
        switch (potion.m_effect)
        {
        case Effect::small:
            out << "Small";
            break;
        case Effect::medium:
            out << "Medium";
            break;
        case Effect::large:
            out << "Large";
            break;
        }

        out << " potion of ";
        switch (potion.m_type)
        {
        case Type::health:
            out << "Health";
            break;
        case Type::strength:
            out << "Strength";
            break;
        case Type::poison:
            out << "Poison";
            break;
        }
        return out;
    }

private:
    Type m_type{};
    Effect m_effect{};
};
