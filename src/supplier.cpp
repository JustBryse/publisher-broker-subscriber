#include "supplier.h"
#include <iostream>

using namespace SoftwareArchitecture;

void Supplier::SetBroker(Broker<std::string>& broker)
{
    current_broker = broker;
}

void Supplier::Supply(const std::string& item)
{   
    current_broker.Publish(item);
}
