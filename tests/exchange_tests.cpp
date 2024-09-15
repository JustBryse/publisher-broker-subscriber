// this project
#include "exchange.h"

// google test
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace SoftwareArchitecture;
using namespace ::testing;

namespace ExchangeTesting
{
class ExchangeTest : public Test
{
protected:
    void SetUp() override {}
    void TearDown() override {}
};

class MockSubscriber : public Subscriber<std::string>
{
public:
    MOCK_METHOD(void,Notify,(const std::string&),(override));
};
}

using namespace ExchangeTesting;

TEST_F(ExchangeTest,ConstructorTest)
{
    ASSERT_NO_FATAL_FAILURE(Exchange exchange = Exchange());
}

TEST_F(ExchangeTest,SubscribeTest)
{
    Exchange exchange = Exchange();
    MockSubscriber mock_sub = MockSubscriber();
    ASSERT_NO_FATAL_FAILURE(exchange.Subscribe(mock_sub));
}

TEST_F(ExchangeTest,IteratorTest)
{
    Exchange exchange = Exchange();
    MockSubscriber mock_sub = MockSubscriber();

    const int subscriber_count = 3;

    for(int i = 0; i < subscriber_count; ++i)
    {
        exchange.Subscribe(mock_sub);
    }

    int i = 0;
    std::string iterator_message = "(ExchangeTest,IteratorTest) -> SUBCRIBERS = {";

    for(auto it = exchange.BeginSubscribers(); it != exchange.EndSubscribers(); ++it)
    {   
        ++i;
    }

    iterator_message += std::to_string(i);
    iterator_message += "}";
    std::cerr << iterator_message << "\n";

    ASSERT_EQ(subscriber_count,i);
}

TEST_F(ExchangeTest,UnsubscribeTest)
{
    Exchange exchange = Exchange();
    MockSubscriber mock_sub1 = MockSubscriber();
    MockSubscriber mock_sub2 = MockSubscriber();

    const int correct_start_sub_count = 2;
    const int correct_end_sub_count = 1;

    exchange.Subscribe(mock_sub1);
    exchange.Subscribe(mock_sub2);

    int subscribers = 0;
    for(auto it = exchange.BeginSubscribers(); it != exchange.EndSubscribers(); ++it)
    {
        ++subscribers;
    }

    ASSERT_EQ(subscribers,correct_start_sub_count);

    exchange.Unsubscribe(mock_sub1);

    subscribers = 0;
    for(auto it = exchange.BeginSubscribers(); it != exchange.EndSubscribers(); ++it)
    {
        ++subscribers;
        ASSERT_EQ(&(it->get()),&mock_sub2); // only mock_sub2 should still be subscribed
    }

    // verify that there is the correct number of subscribers remaining
    ASSERT_EQ(subscribers,correct_end_sub_count);
}

TEST_F(ExchangeTest,PublishTest)
{
    Exchange exchange = Exchange();
    MockSubscriber mock_sub = MockSubscriber();
    exchange.Subscribe(mock_sub);
    const std::string publishing_item = "publishing item";
    ASSERT_NO_FATAL_FAILURE(exchange.Publish(publishing_item));
}
