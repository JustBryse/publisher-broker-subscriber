// this project
#include "consumer.h"

// google test
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace SoftwareArchitecture;
using namespace ::testing;

namespace ConsumerTesting
{
class ConsumerTest : public Test
{
protected:
    void SetUp() override {}
    void TearDown() override {}
};
}

using namespace ConsumerTesting;

TEST_F(ConsumerTest,ConstructorTest)
{
    ASSERT_NO_FATAL_FAILURE(Consumer consumer = Consumer());
}

TEST_F(ConsumerTest,NotifyTest)
{
    Consumer consumer = Consumer();
    const std::string item = "notification item";
    ASSERT_NO_FATAL_FAILURE(consumer.Notify(item));
}