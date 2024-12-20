/*

Make a struct type named person_t which has, name, age and id members.

Make a program to create an array of 3 persons.

Then read 3 persons from the standard input and then sort the persons according thier ids and print the persons to the standard output. To sort and print use only pointers.

*/

// typedef struct kullanarak person type'i olustur, bir fonkyonda (if null gibi bir check uret[examplesa bak]).
// fonksyonda std outputtan value'lari topla.
// baska bir fonksiyonda ID degerine gore sort yap.
// baska bir fonksiyonda Personlari PRINT.
#include <iostream>
#include <limits>

constexpr int amount{3};
typedef struct
{
    std::string name;
    int age;
    int id;
} person_t;

int main()
{
    person_t person[amount];

    for (int i = 0; i < amount; i++)
    {
        std::cout << "Name person " << (i + 1) << " :" << std::endl;
        std::cin >> person[i].name;

        do // check if letters inputted, this loop will loop the questions until no letters are inputted. 
        {
            // person[i].age = -1;
            std::cout << "How old is " << person[i].name << "?: " << std::endl;
            std::cin >> person[i].age;

            if (std::cin.fail()) // returns 1(TRUE) if a LETTER is inputted.
            {
                person[i].age = -1;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (person[i].age == -1);

        do //Take Number to put as ID with check if there are letters.
        {
            std::cout
                << " ID for " << person[i].name << std::endl;
            std::cin >> person[i].id;

            if (std::cin.fail())
            {
                person[i].id = -1;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

        } while (person[i].id == -1);
    }

    // Sort persons based on ID, use bubble sort algorithm
    person_t tempPerson; // temp person to hold the persons.
    for (int i = 0; i < amount; i++)
    {
        for (int j = 0; j < (amount - 1 - i); j++)
        {
            if (person[j].id > person[j + 1].id)
            {
                tempPerson = person[j];
                person[j] = person[j + 1];
                person[j + 1] = tempPerson;
            }
        }
    }

    for (int i = 0; i < amount; i++)
    {
        std::cout << "\v\v" << i + 1 << person[i].name << "\n"
                  << person[i].age << "\n"
                  << person[i].id << std::endl;
    }

    return 0;
}