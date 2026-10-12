#include "Receiver.h"
#include "Beacon.h"
#include <cstdlib>

Receiver::Receiver(int t_x)
    : m_x(t_x)
{
}

int Receiver::rangeTo(Beacon const& t_beacon) const
{
    return std::abs(m_x - t_beacon.x());
}