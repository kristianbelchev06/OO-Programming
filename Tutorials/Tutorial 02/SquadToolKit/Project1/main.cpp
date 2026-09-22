#include "Squad.h"
#include <iostream>

int main()
{
	int const SQUAD_SIZE = 3;
	int health[SQUAD_SIZE] = { 100,75,40 };
	std::cout << "Initial fist health : " << health[0] << '\n';
	return 0;
}