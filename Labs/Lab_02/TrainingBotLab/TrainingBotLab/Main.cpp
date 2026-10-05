#include "TrainingBot.h" 

#include <iostream> 

int main()
{
    std::cout << std::boolalpha;
    std::cout << "Training bot lab\n\n";

    TrainingBot firstBot{};

    std::cout << "First bot\n";
    std::cout << "Starting health: " << firstBot.health() << '\n';
    firstBot.takeDamage(25);
    std::cout << "After 25 damage: " << firstBot.health() << '\n';
    std::cout << "Alive: " << firstBot.isAlive() << '\n';

    TrainingBot secondBot{ 40 };

    std::cout << "\nSecond bot\n";
    std::cout << "Starting health: " << secondBot.health() << '\n';
    secondBot.takeDamage(10);
    std::cout << "After 10 damage: " << secondBot.health() << '\n';
    std::cout << "Alive: " << secondBot.isAlive() << '\n';

    std::cout << "\nHeavy damage\n";
    secondBot.takeDamage(1000);
    std::cout << "Second bot health: " << secondBot.health() << '\n';
    std::cout << "Second bot alive: " << secondBot.isAlive() << '\n';

    return 0;
}