#include <vector>
#include "greet.h"

constexpr char const *HELLO_MY_FRIEND{"Hello, my friend."};
constexpr char const *HELLO_LOWER{"Hello, "};
constexpr char const *HELLO_UPPER{"HELLO "};

static bool isUpper(const std::string &string)
{
    bool xCase{true};

    for (const auto &c : string)
    {
        //if any letter that is lowercase found, break the loop and return false.
        if (std::islower(c))
        {
            xCase = false;
            break;
        }
    }

    return xCase
}

static std::vector<std::string> getNames(const std::strting &string)
{
    std::vector<std::string> names;
}