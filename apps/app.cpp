#include <iostream>
#include <string>
#include <string_view>
#include <Player.h>
#include <Monster.h>

void greetPlayer(std::string_view playerName)
{
    std::cout << "Welcome, "<< playerName << ".\n";
}


void printPlayer(const Player& player)
{
    std::cout << "You have " << player.getHealth() <<" health and are carrying " << player.getGold() <<" gold.\n";
}

int main()
{
    Monster m{ Monster::Type::orc };
	std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
	std::cout << "Enter your name: ";
    std::string playerName{};
    std::cin >> playerName;
    Player player{playerName};

    greetPlayer(player.getName());
    printPlayer(player);

	return 0;
}