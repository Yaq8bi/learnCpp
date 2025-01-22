#include <iostream>
#include <string>
#include <cassert>

class Animal
{
    std::string name;

protected:
    Animal(const std::string &_name) : name{_name} {}
};

class Cat : protected Animal{
    // std::string catName;
    // std::sring  catName2;

    public :
        Cat(const std::string &_name) : Animal{_name}
} {}

            void
            printVar()
{
    std::cout << catName << " - " << catName2 << std::endl;
};

int main()
{
    std::string tempName{"DJUR"};
    std::string tempName2{"djur"};
    Animal a(tempName);
        Cat c(tempName);
    // Animal *ptr{&c};

    c.printVar();

    /*
        // downcasting
        Animal a{"Anhmet"};

        Cat &ref{static_cast<Cat &>(a)}; //
        ref.printVar();
    */

    return 0;
}