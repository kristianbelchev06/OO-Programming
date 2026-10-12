#ifndef BEACON_POOL_H
#define BEACON_POOL_H

#include "Beacon.h"

class BeaconPool
{
public:
    static constexpr int CAPACITY{ 3 };

    BeaconPool() = default;

    int request(int t_strength);
    bool release(int t_index);
    int activeCount() const;
    int strengthAt(int t_index) const;
    static int successfulRequests();

private:
    Beacon m_beacons[CAPACITY];
    static int s_successfulRequests;
};

#endif
