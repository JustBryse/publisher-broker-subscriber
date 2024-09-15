#ifndef PUBLISHER_H
#define PUBLISHER_H
#include "broker.h"

namespace SoftwareArchitecture
{
template<class T>
class Publisher
{
public:
    virtual ~Publisher() = default;
    // allows the publisher to set a broker who can be published to
    virtual void SetBroker(Broker<T>& broker) = 0;
};
}

#endif