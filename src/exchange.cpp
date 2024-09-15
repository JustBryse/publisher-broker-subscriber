#include "exchange.h"
#include <iostream>

using namespace SoftwareArchitecture;

void Exchange::Subscribe(Subscriber<std::string>& subscriber)
{
    std::reference_wrapper<Subscriber<std::string>> sub_ref_wrap = std::ref(subscriber);
    subscribers.push_back(sub_ref_wrap);
}

void Exchange::Unsubscribe(const Subscriber<std::string>& subscriber)
{
    for(auto it = subscribers.begin(); it != subscribers.end(); ++it)
    {   
        Subscriber<std::string>& it_sub = it->get();
        if(&it_sub == &subscriber)
        {   
            // only remove the subscriber reference from the collection if it is pointing to the same place as "subscriber"
            subscribers.erase(it);
            break;
        }
    }
}

void Exchange::Publish(const std::string& item)
{
    for(std::reference_wrapper<Subscriber<std::string>> subscriber : subscribers)
    {   
        subscriber.get().Notify(item);
    }
}

std::vector<std::reference_wrapper<Subscriber<std::string>>>::iterator Exchange::BeginSubscribers()
{
    return subscribers.begin();
}

std::vector<std::reference_wrapper<Subscriber<std::string>>>::iterator Exchange::EndSubscribers()
{
    return subscribers.end();
}