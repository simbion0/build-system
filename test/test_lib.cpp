#define BOOST_TEST_MODULE calculate_test_module

#include "../lib/calculate/lib.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(calculate_test_suite)

BOOST_AUTO_TEST_CASE(calculate_test_sum)
{
    // int
    BOOST_CHECK(Lib::Sum(1, 1) == 2);
    BOOST_CHECK(Lib::Sum(-1, 1) == 0);
    BOOST_CHECK(Lib::Sum(1, -1) == 0);
    BOOST_CHECK(Lib::Sum(0, 0) == 0);
    // double
    /*
    BOOST_CHECK(Lib::Sum(1.1, 1.2) == 2.3);
    BOOST_CHECK(Lib::Sum(-1.5, 1.0) == -0.5);
    BOOST_CHECK(Lib::Sum(1.1, -1.0) == 0.1);
    BOOST_CHECK(Lib::Sum(0.0, 0.0) == 0);
    */
}

BOOST_AUTO_TEST_SUITE_END()
