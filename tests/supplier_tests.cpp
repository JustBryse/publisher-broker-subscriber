// this project
#include "supplier.h"

// google test
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace SoftwareArchitecture;
using namespace ::testing;

namespace SupplierTesting
{
class SupplierTest : public Test
{
protected:
    void SetUp() override {}
    void TearDown() override {}
};

class MockBroker : public Broker<std::string>
{
public:
    MOCK_METHOD(void,Subscribe,(Subscriber<std::string>&),(override));
    MOCK_METHOD(void,Unsubscribe,(const Subscriber<std::string>&),(override));
    MOCK_METHOD(void,Publish,(const std::string&),(override));
};
}

using namespace SupplierTesting;

TEST_F(SupplierTest,ConstructorTest)
{
    MockBroker mock_broker = MockBroker();
    ASSERT_NO_FATAL_FAILURE(Supplier supplier = Supplier(mock_broker));
}

TEST_F(SupplierTest,SupplyTest)
{
    MockBroker mock_broker = MockBroker();
    Supplier supplier = Supplier(mock_broker);
    const std::string new_item = "supply 1";
    ASSERT_NO_FATAL_FAILURE(supplier.Supply(new_item));
}

