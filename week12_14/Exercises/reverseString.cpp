#include <iostream>
#include <algorithm>
 
void toUpperCase(std::string &str)
{
    for (char &ch : str)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - 32; // Make it capital letter
        }
        else if (ch == 32) // in ascii code sheet 32 was space, since i want to use the getline(std::cin, string); to get a string and not just words, i will skip/do nothing to spaces, whom has a value of 32.
        {
            ;
        }
        else if (isdigit(ch))
        {
            ;
        }
        else
        {
            ch = ch + 32; // Make it lower case letter
        }
    }
}

void toReverse(std::string &str)
{
    bool hasDigit{false};

    for (char &ch : str) // Check for digits
    {
        if (isdigit(ch))
        {
            hasDigit = true;
        }
    }

    if (hasDigit == false)
    {
        std::reverse(str.begin(), str.end());
    }
    else // Faroch said, to show that you know.
    {
        ;
    }
}

int main()
{
    bool finished{false};
    bool error{false};

    std::string string;

    do
    {
        std::cout << "input a string" << std::endl;
        getline(std::cin, string);

        if (string.length() > 20)
        {
            error = true;
            std::cout << "This string is too long, max 20 chars allowed:\n" <<  string << std::endl;
            string.clear();
        }
        else
        {
            error = false;
        }
    } while (error == true);

        toUpperCase(string);
    toReverse(string);

    std::cout << string << std::endl;

    return 0;
}