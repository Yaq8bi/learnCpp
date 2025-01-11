#include <iostream>

class Point
{
    int x; // private by default
    int y; // private by default

public:
    // Constructor, yani bir obje oluşturulduğunda o objenin x ve y değerlerini set eder.
    Point(int _x, int _y) : x(_x), y(_y) {}

    void print() const
    {
        std::cout << "x: " << x << ", y: " << y << std::endl;
        // x = 5; // Sincs this is a const function, it can not modify the values of the variables.
    }
};

int main()
{
    //Since 'p' is a const object, it can only call const member functions.
    const Point p(1, 2); // Constructor fonksiyonu çalışır.
    Point q(3,4);       //Simdi q objesinin x ve y değerleri sifir cunku constructor fonksiyonu kullanmadigimiz icin.

    p.print();

    return 0;
}