#include <iostream>
#include <string>
// #include <cstdlib>
#include <gtest/gtest.h>

/*
The function prototype shall be: std::string greet(const std::string &name);
The function shall handle nulls.
If name is an empty string, then the method shall return the string "Hello, my friend."
*/

/*
The function shall handle shouting. If name is all uppercase, then it should shout back to the user. For examples:
If name is "JERRY", the method shall return the string "HELLO JERRY!"
*/

std::string greet(const std::string &name)
{
    std::string helloFriend{"Hello, my friend."};
    if (!name.empty())
    {
        helloFriend = (name += ", my friend.");
    }
    else if (isupper(name))
    {
        std::cout<< "IS UPPERCASE!";
    }
    else
    {
        ;
    }
    return helloFriend;
}




std::string func(std::string str)
{
    std::string result{str};
    if (str == "no")
    {
        std::cerr << "THE EXPECTED ERROR MESSAGE!" << std::endl;
        exit(1);
    }
    else if (str == " ")
    {
        result = "Hello, my friend.";
    }
    else
    {
        result += ", my friend.";
    }

    std::cout << result << std::endl;
    return result;
}

/*
TEST(MyTestSuite, Test1)
{
    EXPECT_EQ(1, 1) << "1 is not equal to 2";
}
*/
TEST(Death_by_string, rvalue_ref_death)
{
    // thread safe
    // EXPECT_DEATH(func("no"), "THE EXPECTED ERROR MESSAGE!");
    // EXPECT_EQ(func(" "), "Hello, my friend.");
    EXPECT_EQ( greet("NO"), "Hello, my friend.");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
