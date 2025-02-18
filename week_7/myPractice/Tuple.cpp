#include <iostream>

#include <tuple>

int main()
{
    std::tuple<int, double, std::string> myTuple(42, 3.14, "Arinah");

    int age;
    double pi;
    std::string name;

    std::tie(age, pi, name) = myTuple;

    std::cout << "name: " << name << '\n'
              << "pi: " << pi << '\n'
              << "Age: " << age << '\n'
              << std::endl;

    return 0;
}