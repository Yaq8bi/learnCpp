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

constexpr int amount{2};
typedef struct
{
    std::string name;
    int age;
    int id;
} person_t;

int main()
{
    person_t person[2];

    for (int i = 0; i < amount; i++)
    {
        std::cout << "Name person " << i + 1 << " :" << std::endl;
        std::cin >> person[i].name;

        std::cout << "How old is " << person[i].name << "?: " << std::endl;
        std::cin >> person[i].age;

        std::cout << " ID for " << person[i].name << std::endl;
        std::cin >> person[i].id;
    }

    for (int i = 0; i < amount; i++)
    {
        std::cout << "\v" << i + 1 << person[i].name << "\n"
                  << person[i].age << "\n"
                  << person[i].id << std::endl;
    }

    //Sort persons based on ID

    return 0;
}