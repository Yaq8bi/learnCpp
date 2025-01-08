#include <iostream>

class Point {

    // private classin icinde kullanilir
    struct Position {
        int x;
        int y;
    };

    // Point(int m, int n);

    public:
    Position center;
    Point(int m, int n) :  center{m, n} {} // constructor;
    Point(const Point& p) : center {p.center.x, p.center.y} {} // copy constructor

    public:

    void print()
    {
        std::cout << center.x << " " << center.y << std::endl;
    }
};

// Point::Point(int m, int n) : center {m, n} {}

int main()
{
    Point p(1, 2);
    Point q{p}; // copy constructor

    q.print();
}