#include "consumer.h"
#include <iostream>

using namespace SoftwareArchitecture;

void Consumer::Notify(const std::string& item)
{
    // Notify() currently does nothing besides print "item". Future implementation needed
    std::cout << "Consumer::Notify() -> ITEM = {" << item << "}\n";
}