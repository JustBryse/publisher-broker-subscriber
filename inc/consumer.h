#ifndef CONSUMER_H
#define CONSUMER_H

#include "subscriber.h"
#include <string>

namespace SoftwareArchitecture
{
class Consumer : public Subscriber<std::string>
{
public:
    Consumer() = default;
    void Notify(const std::string& item) override;
};
}

#endif