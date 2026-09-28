// Write your own implementation for the published practical specification.
#include "Dispatch.h"
#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::string depotName;
    int units;

    std::cout << "Enter depot name: ";
    if (!std::getline(std::cin, depotName))
    {
        std::cerr << "Input ended." << std::endl;
        return 1;
    }

    std::cout << "Enter units: ";

    while (!(std::cin >> units) || units < 0 || units > 60)
    {
        if (std::cin.eof())
        {
            std::cerr << "Input ended." << std::endl;
            return 1;
        }

        std::cin.clear();
        std::cin.ignore(1000, '\n');

        std::cout << "Enter units: ";
    }

    std::cin.ignore(1000, '\n');

    std::ifstream file("batches.txt");

    if (!file)
    {
        std::cerr << "Could not open batches.txt." << std::endl;
        return 1;
    }

    int batchCount = 0;
    int stockTotal = 0;
    int lowBatchCount = 0;
    int batch;

    while (file >> batch)
    {
        batchCount++;

        if (batchCount > 12)
        {
            std::cerr << "Too many batches." << std::endl;
            return 1;
        }

        if (batch < 0 || batch > 40)
        {
            std::cerr << "Invalid batch data." << std::endl;
            return 1;
        }

        stockTotal = stockTotal + batch;

        if (batch < 10)
        {
            lowBatchCount++;
        }
    }

    if (!file.eof())
    {
        std::cerr << "Invalid batch data." << std::endl;
        return 1;
    }

    if (batchCount == 0)
    {
        std::cerr << "No batches found." << std::endl;
        return 1;
    }

    std::cout << "Batches: " << batchCount << std::endl;
    std::cout << "Stock: " << stockTotal << std::endl;
    std::cout << "Low batches: " << lowBatchCount << std::endl;

    Dispatch::printHeading();

    return 0;
}