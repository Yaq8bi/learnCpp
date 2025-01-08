#include <iostream>

class Point
{
    int x, y;

public:
    Point(int _x, int _y) : x(_x), y(_y) {} // Constructor

    int getX() const { return x; } 
    int getY() const { return y; }
    
    static Point &handle(int _x, int _y)//Burası static bir fonksiyon, a static member belongs to the class ITSELF!
    {
        static Point p(_x, _y);
        return p;
    }

    void print()
    {
        std::cout << "x: " << x << ", y: " << y << std::endl;
    }
    friend bool isEqual(const Point &p, const Point &q);
};

bool isEqual(const Point &p, const Point &q)
{
    return ((p.x == q.x) && (p.y == q.y));
}

int main()
{
    Point p1(1, 2), q(1, 2);

    std::cout << (isEqual(p1, q) ? "Equal" : "Not equal") << std::endl;

    Point::handle(3, 4).print();

    return 0;
}