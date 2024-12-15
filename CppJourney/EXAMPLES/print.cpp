#include <iostream>
#include <unistd.h>

int main(void)
{
    std::cout << ">> Print\tHorizontalTAB" << std::endl;
    usleep(1000000);
    std::cout << ">> Print\vVerticalTAB" << std::endl;
    usleep(1000000);
    std::cout << ">> Print\na new line." << std::endl;
    usleep(1000000);
    std::cout << ">> Printt\bBackspace" << std::endl;
    usleep(1000000);
    std::cout << ">> Print special characters: % \' \" \\" << std::endl;

    for (size_t i = 0; i < 15; i++)
    {
        std::cout << "\r" << i << std::flush;
        usleep(1000000);
    }

    std::cout << std::endl;

    return 0;
}