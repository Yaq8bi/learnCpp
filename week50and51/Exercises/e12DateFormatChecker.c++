/*
Make a program to read date and time from a terminal and then
check if the entered date and time is in the format of YYYY-MM-DD HH:mm:ss or not.
*/
#include <iostream>
#include <regex>
#include <string>

int main()
{
    std::string input;

    // Regular expression for the format YYYY-MM-DD HH:mm:ss
    std::regex datetime_regex(R"(\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2})"); //format specification

    std::cout << "Enter date and time (format: YYYY-MM-DD HH:mm:ss): ";
    std::getline(std::cin, input);

    if (std::regex_match(input, datetime_regex))//returns 1 if the input match the datetime_regex argument.
    {
        std::cout << "The entered date and time is in the correct format.\n";
    }
    else
    {
        std::cout << "The entered date and time is NOT in the correct format.\n";
    }

    return 0;
}

/*
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

int main(void)
{
    tm time;

    cout << "Enter Time in format of [HH:MM:SS]:" << endl;

    if (cin >> get_time(&time, "%H:%M:%S"))
    {
        cout << "Your time input of: " << put_time(&time, "%H:%M:%S") << " is a correct format" << endl;
    }
    else
    {
        cout << "Wrong Format! Try Again!" << endl;
    }

    return 0;
}
*/