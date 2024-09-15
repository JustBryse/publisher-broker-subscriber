#ifndef SUPPLIER_H
#define SUPPLIER_H

#include "publisher.h"
#include <string>

namespace SoftwareArchitecture
{
class Supplier : public Publisher<std::string>
{
public:
    Supplier() = delete;
    Supplier(Broker<std::string>& broker) : current_broker(broker){}
    void SetBroker(Broker<std::string>& broker) override;
    void Supply(const std::string& item);

private:
    Broker<std::string>& current_broker;
    void Publish(const std::string& item);
};
}

#endif