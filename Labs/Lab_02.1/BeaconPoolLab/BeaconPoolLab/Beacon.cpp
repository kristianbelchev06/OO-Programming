#include "Beacon.h"

Beacon::Beacon(int t_x)
    : m_x(t_x)
{
}

int Beacon::x() const
{
    return m_x;
}

int Beacon::strength() const
{
    return m_strength;
}

bool Beacon::active() const
{
    return m_active;
}

void Beacon::activate(int t_strength)
{
    m_strength = t_strength;
    m_active = true;
}

void Beacon::reset()
{
    m_strength = 0;
    m_active = false;
}