
#ifndef TRAINING_BOT_H 
#define TRAINING_BOT_H 

class TrainingBot
{
public:
    TrainingBot() = default;
    TrainingBot(int t_health);
    void takeDamage(int t_amount);
    int health() const;
    bool isAlive() const;

private:
    int m_health{ 100 };
};

#endif