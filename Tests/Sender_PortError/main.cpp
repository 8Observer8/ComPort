
#include "gtest/gtest.h"
#include "PortError.h"

TEST( test001, messageTest )
{
    // Input data
    std::string errorText = "error text";
    PortError portError( errorText );

    std::string actual = portError.getMessage();
    std::string expected = "Error: error text";
    ASSERT_EQ( expected, actual );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
