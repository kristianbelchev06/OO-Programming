// Write your own implementation for the published practical specification.
#include "Dispatch.h"
#include <iostream>
#include <string>

int main()
{
    std::string depotName;
    int units;

    std::cout << "Enter depot name: ";
    std::getline(std::cin, depotName);

    std::cout << "Enter units: ";
    std::cin >> units;

    while (!(std::cin >> units) || units < 0 || units > 60)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');

        if (std::cin.eof())
        {
            std::cout << "Input ended." << std::endl;
            return 1;
        }

        std::cout << "Enter units: ";
    }

    std::cin.ignore(1000, '\n');
    
    Dispatch::printHeading();

    return 0;
}
