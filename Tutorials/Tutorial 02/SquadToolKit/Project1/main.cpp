#include "Squad.h"
#include <iostream>
#include <iomanip>




int main()
{

	char callsign[] = "Rook";
	char const* fixedText = "Rook";
	std::cout << "Storage: " << sizeof(callsign) << '\n';
	std::cout << "Length: " << std::strlen(callsign) << '\n';
	callsign[0] = 'B'; // This array contains our writable characters.
	std::cout << callsign << " / " << fixedText << '\n';

	int const SQUAD_SIZE = 3;
	int health[SQUAD_SIZE] = { 100,75,40 };
	std::cout << "Initial first health : " << health[0] << '\n';

	Squad::swapHealth(&health[0], &health[2]);
	std::cout << "After swap:" << health[0] << ' '
		<< health[1] << ' ' << health[2] << '\n';

	int* healthPointer = health;
	std::cout << "Array bytes: " << sizeof(health) << '\n';
	std::cout << "Pointer bytes: " << sizeof(healthPointer) << '\n';
	for (int const* current = health;
		current != health + SQUAD_SIZE; ++current)
	{
		std::cout << "Slot" << (current - health)
			<< ":" << *current << '\n';
	}
	std::cout << "Total health: "
		<< Squad::totalHealth(health, SQUAD_SIZE) << '\n';

	char const* names[] = { "Rook", "Ada", "Mina" };
	char const** slot = names;
	std::cout << "First name: " << *slot << '\n';
	std::cout << "First character: " << **slot << '\n';
	++slot;
	std::cout << "Next name: " << *slot << '\n';

	if (std::strcmp(names[0], names[1]) > 0)
	{
		char const* temporaryName = names[0];
		names[0] = names[1];
		names[1] = temporaryName;
	}
	std::cout << "Name order: " << names[0] << ' '
		<< names[1] << ' ' << names[2] << '\n';
	std::cout << "Slot now sees: " << *slot << '\n';

	for (int value : health)
	{
		value -= 5;
		std::cout << "Changed copy: " << value << '\n';
	}
	std::cout << "After copy loop: "
		<< Squad::totalHealth(health, SQUAD_SIZE) << '\n';
	for (int& value : health)
	{
		value -= 5; // Apply the cost to each actual array element.
	}
	for (int const& value : health)
	{
		std::cout << "Stored health: " << value << '\n';
	}

	int total = Squad::totalHealth(health, SQUAD_SIZE);
	double tooLate = static_cast<double>(total / SQUAD_SIZE);
	double average = static_cast<double>(total) / SQUAD_SIZE;
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Late conversion: " << tooLate << '\n';
	std::cout << "Average health: " << average << '\n';

	return 0;
}