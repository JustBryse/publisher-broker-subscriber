#ifndef BROKER_H
#define BROKER_H
#include <subscriber.h>

namespace SoftwareArchitecture
{
template<class T>
class Broker
{
public:
    virtual ~Broker() = default;
    virtual void Subscribe(Subscriber<T>& subscriber) = 0;
    virtual void Unsubscribe(const Subscriber<T>& subscriber) = 0;
    virtual void Publish(const T& item) = 0;
};
}

#endif