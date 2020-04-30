#ifndef HAUSARBEITWEGSUCHE_UNITTESTS_HPP
#define HAUSARBEITWEGSUCHE_UNITTESTS_HPP

#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE( my_test )
{
    // seven ways to detect and report the same error:
    BOOST_CHECK( 2 + 2 == 4 );        // #1 continues on error

    BOOST_REQUIRE( 2 + 2 == 4 );      // #2 throws on error
}



#endif