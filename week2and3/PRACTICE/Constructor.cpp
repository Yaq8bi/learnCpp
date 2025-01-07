#include <iostream>

class Point
{
    int x; // private by default
    int y; // private by default

public:
    // Constructor, yani bu class'tan bir obje oluşturulduğunda bu fonksiyon çalışır.
    Point(int _x, int _y) : x(_x), y(_y) {}

    void print() const
    {
        std::cout << "x: " << x << ", y: " << y << std::endl;
    }
};

int main()
{
    const Point p(1, 2); // Constructor fonksiyonu çalışır.
    p.print();

    return 0;
}