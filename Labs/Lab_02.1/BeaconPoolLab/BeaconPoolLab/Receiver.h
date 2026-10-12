#ifndef RECEIVER_H
#define RECEIVER_H

class Beacon;

class Receiver
{
public:
    explicit Receiver(int t_x);

    int rangeTo(Beacon const& t_beacon) const;

private:
    int m_x;
};

#endif
