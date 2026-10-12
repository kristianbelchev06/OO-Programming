#ifndef BEACON_H
#define BEACON_H

class BeaconPool;

class Beacon
{
    friend class BeaconPool;

public:
    explicit Beacon(int t_x);

    int x() const;
    int strength() const;
    bool active() const;

private:
    Beacon() = default;

    void activate(int t_strength);
    void reset();

    int m_x{ 0 };
    int m_strength{ 0 };
    bool m_active{ false };
};

#endif
