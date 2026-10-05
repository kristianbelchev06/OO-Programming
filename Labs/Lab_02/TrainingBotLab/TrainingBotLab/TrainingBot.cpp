#include "TrainingBot.h" 

TrainingBot::TrainingBot(int t_health)
    : m_health{ t_health }
{
}

int TrainingBot::health() const
{
    return m_health;
}

void TrainingBot::takeDamage(int t_amount)
{
    if (t_amount <= 0)
    {
        return;
    }

    if (t_amount >= m_health)
    {
        m_health = 0;
    }
    else
    {
       m_health = m_health - t_amount; // Challenge: subtract t_amount from m_health here. 
    }
}

bool TrainingBot::isAlive() const 
{ 
    return m_health > 0; 
}