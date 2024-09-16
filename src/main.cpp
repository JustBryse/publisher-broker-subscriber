#include <iostream>
#include "supplier.h"
#include "exchange.h"
#include "consumer.h"

using namespace SoftwareArchitecture;

int main()
{
    Exchange exchange = Exchange();
    Supplier supplier = Supplier(exchange);
    Consumer consumer = Consumer();

    exchange.Subscribe(consumer);

    const std::string supplier_item = "Hello subscribers!";
    supplier.Supply(supplier_item);

    return 0;
}