#include <greet.h>
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


TEST(greetTest, noName)
{
    EXPECT_EQ("Hello, my friend.", greet(""));
    EXPECT_EQ("Hello, my friend.", greet("   $ @,   0,   . "));
}

TEST(greetTest, oneName)
{
    EXPECT_EQ("Hello, Bob.", greet("Bob"));
    EXPECT_EQ("Hello, Bob.", greet("    0Bob, @ "));

    EXPECT_EQ("HELLO BOB!", greet("BOB"));
    EXPECT_EQ("HELLO BOB!", greet("    0BOB, @ "));
}

TEST(greetTest, twoNames)
{
    EXPECT_EQ("Hello, Jill and Jane.", greet("Jill, Jane"));
    EXPECT_EQ("HELLO BOB AND JANE!", greet("BOB, JANE"));
}

TEST(greetTest, multipleNames)
{
    EXPECT_EQ("Hello, Amy, Brian, and Jane.", greet("Amy, Brian, Jane"));
    EXPECT_EQ("HELLO AMY, BRIAN, AND JANE!", greet("AMY, BRIAN, JANE"));
}

TEST(greetTest, mixedNames)
{
    EXPECT_EQ("Hello, Amy, Jane, and Jill. AND HELLO BRIAN, BOB, AND CHARLOTTE!", greet("Amy, BRIAN, Jane, BOB, Jill, CHARLOTTE"));
}


/*
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


TEST(Death_by_string, rvalue_ref_death)
{
    EXPECT_EQ( greet("NO"), "Hello, my friend.");
}
*/

/*int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
*/