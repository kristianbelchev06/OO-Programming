#include "Enemy.h"
#include <iostream>

void takeDamage(int t_amount)
{
	if (t_amount <= 0)
	{
		  = 100;
	}
	if (t_amount > 0)
	{
		int health = health - t_amount;
	}
	if (t_amount > 100)
	{
		std::cout << "Can not take more than 100 damage";
	}
}