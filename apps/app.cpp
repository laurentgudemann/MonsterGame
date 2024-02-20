#include <iostream>
#include <string>
#include <string_view>
#include <Player.h>
#include <Creature.h>
#include <Monster.h>
#include <Potion.h>

void applyModifier(const StatModifier modifier, Creature& creature)
{
    creature.m_damage += modifier.m_damage;
    creature.m_health += modifier.m_health;
}

void greetPlayer(std::string_view playerName)
{
    std::cout << "Welcome, " << playerName << ".\n";
}

void printPlayer(const Player &player)
{
    std::cout << "You have " << player.getHealth() << " health, " << player.getGold() << " gold and deal " << player.getDamage() << " damage.\n";
}

void attackMonster(Player &player, Creature &monster)
{
    monster.reduceHealth(player.getDamage());
    std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage.\n";
}

void attackPlayer(Player &player, Creature &monster)
{
    player.reduceHealth(monster.getDamage());
    std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage.\n";
}

void fightMonster(Player &player, Creature &monster)
{
    attackMonster(player, monster);
    if (!monster.isDead())
    {
        attackPlayer(player, monster);
    }
}

void dropPotion(Player &player)
{
    std::cout << "You found a mythical potion! Do you want to drink it? [y/n]: ";
    
    char userChar{};

    while (true)
    {
        std::string userInput{};
        std::cin >> userInput;
        if (userInput.length() != 1)
        {
            std::cout << "Invalid input, try again: ";
            continue;
        }
        else
        {
            userChar = userInput[0];
            break;
        }
        if (!(userChar == 'y' || userChar == 'Y' || userChar == 'n' || userChar == 'N'))
        {
            std::cout << "Invalid input, try again: ";
            continue;
        }
    }
    if (userChar == 'y' || userChar == 'Y')
    {
        Potion potion{Potion::getRandomPotion()};
        std::cout << "You drank a " << potion << '\n';
        applyModifier(static_cast<StatModifier>(potion), player);
    }
}

void encounterMonster(Player &player, Creature &monster)
{
    std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ").\n";
    while (!monster.isDead() && !player.isDead())
    {
        std::cout << "(R)un or (F)ight: ";
        std::string userInput{};
        char userChar{};
        std::cin >> userInput;
        if (userInput.length() != 1)
        {
            std::cout << "Invalid input, try again.\n";
            continue;
        }
        else
        {
            userChar = userInput[0];
        }

        if (userChar == 'r' || userChar == 'R')
        {
            const bool runSuccess{static_cast<bool>(Random::get(0, 1))};
            if (runSuccess)
            {
                std::cout << "You successfully fled.\n";
                return;
            }
            else
            {
                std::cout << "You failed to flee.\n";
                attackPlayer(player, monster);
                continue;
            }
        }
        else if (userChar == 'f' || userChar == 'F')
        {
            fightMonster(player, monster);
            continue;
        }
        else
        {
            std::cout << "Invalid input, try again.\n";
            continue;
        }
    }
    if (monster.isDead())
    {
        std::cout << "You killed the " << monster.getName() << ".\n";
        if (Random::get(0, 9) < 10)
        {
            dropPotion(player);
        }
        player.levelUp();
        std::cout << "You are now level " << player.getLevel() << ".\n";
        player.addGold(monster.getGold());
        std::cout << "You found  " << monster.getGold() << " gold.\n";
    }
}

int main()
{

    std::cout << "Enter your name: ";
    std::string playerName{};
    std::cin >> playerName;
    Player player{playerName};

    greetPlayer(player.getName());

    while (!player.isDead() && !player.hasWon())
    {
        printPlayer(player);
        Monster monster{Monster::getRandomMonster()};
        encounterMonster(player, monster);
    }

    if (player.isDead())
    {
        std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\nToo bad you can’t take it with you!";
    }
    else
    {
        std::cout << "You won! Gold remaining: " << player.getGold() << '\n';
    }
    return 0;
}