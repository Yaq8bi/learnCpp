#include <iostream>

/*
Public inheritence
*/
class A // Base class
{
    int a;

public:
    A(int _a) : a{_a} {}

    void printA(void) { std::cout << a << std::endl; }
};

class B : public A
{
    int b;

public:
    B(int _a, int _b) : A{_a}, b{_b} {}

    void printB(void) { std::cout << b << std::endl; }
};
/*
Protected Inheritence
final key word stops inheritance for the next class.
*/
class Base
{
    int x;
    int y;

public:
    Base(int _x, int _y) : x{_x}, y{_y}
    {
        std::cout << "Base Constructor" << std::endl;
    };

    void printX()
    {
        std::cout << x << std::endl;
    }

    ~Base()
    {
        std::cout << "Base Destructor" << std::endl;
    };
};
//inheritence
class Derived : public Base
{
    int c;
    int d;

public:
    Derived(int _c, int _d) : Base{_c, _d}, c{_c}, d{_d}
    {
        std::cout << "Derived Constructor" << std::endl;
    };

    void printY()
    {
        std::cout << d << std::endl;
    }

    ~Derived()
    {
        std::cout << "Derived Destructor" << std::endl;
    };
};

class J final : public Derived
{
    int khan;
    int mita;

public:
    J(int _khan, int _mita) : Derived{_khan, _mita}, khan{_khan}, mita{_mita} { std::cout << "J Constructor" << std::endl; }
   
    

    ~J() { std::cout << "J Destructor" << std::endl; }
};

int main()
{
    J instanceOfJ(8, 4);
    instanceOfJ.printX();
    instanceOfJ.printY();

    // B instanceOfB(2, 4);

    // instanceOfB.printA();
    // instanceOfB.printB();
}