#include "common.h"
#include <vector>
#include <sstream>
#include <iterator>

namespace api
{
    std::string Sum(std::string value)
    {
        std::stringstream ss(value);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        std::vector<std::string> argsSting(begin, end);
        // check input args nums
        if (argsSting.size() != 2)
        {
            return "invalid";
        }
        else
        {
            try
            {
                int a_int = stoi(argsSting[0]);
                int b_int = stoi(argsSting[1]);
                float a_float = stof(argsSting[0]);
                float b_float = stof(argsSting[1]);
                // int + int = int
                if (a_float == float(a_int) && b_float == float(b_int))
                {
                    int c_int = a_int + b_int;
                    std::string c_string;
                    std::stringstream int2string;
                    int2string << c_int;
                    int2string >> c_string;
                    return c_string;
                }
                //  float + float = float
                else
                {
                    float c_float = a_float + b_float;
                    std::string c_string;
                    std::stringstream float2string;
                    float2string << c_float;
                    float2string >> c_string;
                    return c_string;
                }
            }
            catch (std::invalid_argument &e)
            {
                // string + string meaning concat
                return argsSting[0] + argsSting[1];
            }
        }
    }
}

// namespace api