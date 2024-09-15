#ifndef EXCHANGE_H
#define EXCHANGE_H

// this project
#include "broker.h"

// standard library
#include <string>
#include <vector>
#include <iterator>
#include <functional> // std::reference_wrapper allows collections like vector to store reference variables

namespace SoftwareArchitecture
{
class Exchange : public Broker<std::string>
{
public:
    Exchange()
    {
        subscribers = std::vector<std::reference_wrapper<Subscriber<std::string>>>();
    }
    void Subscribe(Subscriber<std::string>& subscriber) override;
    void Unsubscribe(const Subscriber<std::string>& subscriber) override;
    void Publish(const std::string& item) override;
    std::vector<std::reference_wrapper<Subscriber<std::string>>>::iterator BeginSubscribers();
    std::vector<std::reference_wrapper<Subscriber<std::string>>>::iterator EndSubscribers();

private:
    std::vector<std::reference_wrapper<Subscriber<std::string>>> subscribers;

};
}

#endif