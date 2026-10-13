#ifndef ENEMY_H
#define ENEMY_H 

class Enemy
{
public:
    static constexpr int MAX_HEALTH{ 100 };

    Enemy() = default;
    void takeDamage(int t_amount);
    int health() const;
    bool isAlive() const;

private:
    int m_health{ MAX_HEALTH };
};

#endif
