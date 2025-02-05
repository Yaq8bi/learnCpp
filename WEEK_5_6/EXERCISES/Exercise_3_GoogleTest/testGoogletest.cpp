#include <iostream>
#include <string>
#include <gtest/gtest.h>

std::string greet(const std::string &name);


std::string func(std::string str)
{
    std::string result{str};
    if (str == "no")
    {
        std::cerr << "THE EXPECTED ERROR MESSAGE!" << std::endl;
        exit(1);
    }
    else if(str == " ")
    {
        result = "Hello, my friend.";
    }
    else{
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
    //EXPECT_DEATH(func("no"), "THE EXPECTED ERROR MESSAGE!");

    EXPECT_EQ(func(" "), "Hello, my friend.");
}












int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}