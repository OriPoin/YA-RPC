#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include "common.h"
#include <boost/test/unit_test.hpp>
#include <boost/date_time.hpp>
#include <cstdlib>
#include <string>

BOOST_AUTO_TEST_SUITE(uppercase_test)

BOOST_AUTO_TEST_CASE(abc2ABC)
{
    std::string c_string = api::Uppercase("abc");
    BOOST_CHECK_EQUAL(c_string, "ABC");
}

BOOST_AUTO_TEST_SUITE_END()