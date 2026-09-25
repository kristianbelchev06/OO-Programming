#include "Squad.h"

void Squad::swapHealth(int* first, int* third)
{
	int temporary = *first;
	*first = *third;
	*third = temporary;
}

int Squad::totalHealth(int const* values, int count)
{

	if (count < 0 || (values == nullptr && count > 0))
	{
		return -1;
	}
	int total = 0;
	for (int index = 0; index < count; ++index)
	{
		total += values[index];
	}
	return total;
}