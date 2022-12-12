#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include "common.h"
#include <boost/test/unit_test.hpp>
#include <boost/date_time.hpp>
#include <cstdlib>
#include <string>

BOOST_AUTO_TEST_SUITE(sum_test)

BOOST_AUTO_TEST_CASE(int_add_int)
{
    int a = 1;
    int b = 1;
    int c = a + b;
    std::string c_string = api::Sum("1 1");
    BOOST_CHECK_EQUAL(stoi(c_string), c);
}

BOOST_AUTO_TEST_CASE(float_add_float)
{
    float a = 1.5;
    float b = 6.1;
    float c = a + b;
    std::string c_string = api::Sum("1.5 6.1");
    BOOST_CHECK_EQUAL(stof(c_string), c);
}

BOOST_AUTO_TEST_CASE(string_concat_string)
{
    std::string a = "a";
    std::string b = "b";
    std::string c = a + b;
    std::string c_string = api::Sum("a b");
    BOOST_CHECK_EQUAL(c_string, c);
}

BOOST_AUTO_TEST_CASE(invalid_arg_nums_3)
{
    std::string c_string = api::Sum("a b c");
    BOOST_CHECK_EQUAL(c_string, "invalid");
}

BOOST_AUTO_TEST_CASE(invalid_arg_nums_1)
{
    std::string c_string = api::Sum("a");
    BOOST_CHECK_EQUAL(c_string, "invalid");
}

BOOST_AUTO_TEST_SUITE_END()