#include "common.h"
#include <algorithm>
#include <string>

namespace api
{
    std::string Uppercase(std::string value)
    {
        std::transform(value.begin(), value.end(), value.begin(), ::toupper);
        return value;
    }

} // namespace api
