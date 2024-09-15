#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

namespace SoftwareArchitecture
{
template<class T>
class Subscriber
{
public:
    virtual ~Subscriber() = default;
    virtual void Notify(const T& item) = 0;
};
}

#endif