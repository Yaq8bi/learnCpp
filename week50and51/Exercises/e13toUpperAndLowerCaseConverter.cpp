/*
Make a program to read a std::string from a terminal and then convert

the uppercase letters to lowercase and vice versa and

in the end print the string to the standard output.

To change and print the string use only pointers.

*/
#include <iostream>

int main()
{
    std::string Atxt;
    std::cout << "Write a text" << std::endl;
    std::cin >> Atxt;

    /*
     for (char &c : Atxt)
     {
         if (c >= 'A' && c <= 'Z')
         {
             c = tolower(c);
         }
         else
         {

             c = toupper(c);
         }
     }
 */

    char *cptr = &Atxt[0];

    while(*cptr != '\0'){
        if (*cptr >= 'A' &&*cptr <= 'Z')// Alternatively could use (islower(*cptr)) but i'm not sure wich one is better for EMBEDDED!
        {
            *cptr = tolower(*cptr);
        }
        else
        {
            *cptr = toupper(*cptr);
        }
        cptr++;//increment
    }

    std::cout << Atxt << std::endl;

    return 0;
}