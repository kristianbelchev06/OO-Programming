#include "BeaconPool.h"

int BeaconPool::s_successfulRequests{ 0 };

int BeaconPool::request(int t_strength)
{
    if (t_strength < 1 || t_strength > 100)
    {
        return -1;
    }

    for (int i = 0; i < CAPACITY; i++)
    {
        if (!m_beacons[i].active())
        {
            m_beacons[i].activate(t_strength);
            s_successfulRequests++;
            return i;
        }
    }

    return -1;
}

bool BeaconPool::release(int t_index)
{
    if (t_index < 0 || t_index >= CAPACITY)
    {
        return false;
    }

    if (!m_beacons[t_index].active())
    {
        return false;
    }

    m_beacons[t_index].reset();
    return true;
}

int BeaconPool::activeCount() const
{
    int count = 0;

    for (int i = 0; i < CAPACITY; i++)
    {
        if (m_beacons[i].active())
        {
            count++;
        }
    }

    return count;
}

int BeaconPool::strengthAt(int t_index) const
{
    if (t_index < 0 || t_index >= CAPACITY)
    {
        return -1;
    }

    return m_beacons[t_index].strength();
}

int BeaconPool::successfulRequests()
{
    return s_successfulRequests;
}