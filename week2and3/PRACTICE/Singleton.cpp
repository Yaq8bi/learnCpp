#include <iostream>

class Point
{
    // private
    int x, y;
    Point(const Point &) = delete;          // Deleting the copy constructor.
    Point(int _x, int _y) : x{_x}, y{_y} {} // Constructor

public:
    static Point *handle(int _x, int _y) // Burası static bir fonksiyon, a static member belongs to the class ITSELF!
    {
        static Point p{_x, _y};
        return &p;
    }

    void print() const
    {
        std::cout << "x: " << x << ", y: " << y << std::endl;
    }
    // friend bool isEqual(const Point &p, const Point &q);
};

// bool isEqual(const Point &p, const Point &q)
// {
//     return ((p.x == q.x) && (p.y == q.y));
// }

int main()
{
    /*Point::handle(); returns a reference, to a static object of the class.*/
    Point *point = Point::handle(2, 3);
    // printing the pointer.
    std::cout << point << std::endl;

    point->print();

    return 0;
}