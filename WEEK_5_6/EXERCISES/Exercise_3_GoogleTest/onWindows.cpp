#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <cassert>

/*
The function prototype shall be: std::string greet(const std::string &name);
The function shall handle nulls.
If name is an empty string, then the method shall return the string "Hello, my friend."
*/

/*
The function shall handle shouting. If name is all uppercase, then it should shout back to the user. For examples:
If name is "JERRY", the method shall return the string "HELLO JERRY!"
*/

/*
The function shall handle two names. If name is a string of two names, then both names should be printed. For examples:
If name is "Jill, Jane", the method shall return the string "Hello, Jill and Jane."
If name is "BOB, JANE", the method shall return the string "HELLO BOB AND JANE!"
*/

std::string greet(const std::string &name)
{
    std::string helloName{"Hello, "};
    std::string firstName, secondName;

    // check space
    int i{0};
    while (name[i] != '\0')
    {
        if (name[i] == ' ')
        {
            std::istringstream iss(name);
            iss >> firstName;
            std::getline(iss, secondName);
        }
        else
        {
            ;
        }
        i++;
    }

    if (name.empty() || name == " ")
    {
        helloName += "my friend.";
    }

    if (!name.empty() && isupper(name[1]))
    {
        helloName = "HELLO, ";
        helloName += name;
        helloName += "!";
    }
    else if (!name.empty())
    {
        helloName += name;
    }

    if (!firstName.empty() && !secondName.empty())
    {
        helloName = "Hello, ";
        helloName += firstName;
        helloName += " and ";
        helloName += secondName;
    }

    return helloName;
}

int main()
{
    std::string aName = "James Bond";
    std::cout << greet(aName) << std::endl;

    return 0;
}