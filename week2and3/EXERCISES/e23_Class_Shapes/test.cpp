/*
A circle is a shape which has a center point and a radius.
A square is a shape which has a length(four equal sides).
Every shape has a name and an area. Every point has x and y on the 2d cartesian coordinate system.
Make a Shape class and a Point class.
Make a Circle class based on Shape.
The class shall have a function to get area of a circle.
It shall be possible to  check if two circles are equal or not by overloading the == operator.
Make a Square class based on Shape. The class shall have a function to get area of a square.
Make a function to print area of any shape.
*/
#include <iostream>
#include <cassert>
#include "e23_Class_Shapes.hpp"

/*
class Shape
{
    std::string name;
    int area;
    // Make the points of  x and y on the 2d cartesian coordinate system.
public:
    Shape() : name{"Shape"} {};

    void printArea()
    {
        std::cout << "Area of the shape is: " << area << std::endl;
    }

    void setName(std::string _name)
    {
        name = _name;
    }

    std::string getName()
    {
        return name;
    }

    void setArea(int _area)
    {
        area = _area;
    }

    int getArea()
    {
        return area;
    }
};

class Point : public Shape
{
    int x;
    int y;

public:
    Point() : x{0}, y{0} {};

    void setter(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    void getter()
    {
        std::cout << "x: " << x << " y: " << y << std::endl;
    }

    bool operator==(const Point &p)
    {
        return (x == p.x && y == p.y); // bu bolean return ediyor. Ve iki point objesi arasinda karsilastirma yapabiliyor.
    }
};

class Circle : public Shape
{
    int centerPoint;
    int radius;
    float pi = 3.14;

public:
    Circle() : centerPoint{3}, radius{5} {};

    void setArea(int _centerPoint, int _radius)
    {
        centerPoint = _centerPoint;
        radius = _radius;
    }

    float getArea()
    {
        return pi * radius * radius; // Area of the circle is pi*r^2
    }

    bool operator==(const Circle &c)
    {
        return (centerPoint == c.centerPoint && radius == c.radius); // bu bolean return ediyor. Ve iki circle objesi arasinda karsilastirma yapabiliyor.
    }
};

class Square : public Shape
{
    int length; //Variable hidden/encapsulated/abstraction

public:
    Square() : length{5} {};// constructor

    void setArea(int _length)// functions to be used to set the value of the hidden variable
    {
        length = _length;
    }

    int getArea()
    {
        return length * length; // Area of the square is length^2.
    }
};
*/

int main()
{
    Circle c1;
    Circle c2;
    c1.setArea(2, 5);
    c2.setArea(5, 10);
    std::cout << c1.getArea() << std::endl;
    std::cout << c2.getArea() << std::endl;

//    std::cout << Circle::operator==(c1, c2) << std::endl;
    std::cout << (c1 == c2) << std::endl;// if the returned value is 1, then the two circles are equal. If 0, then they are not equal.

    Point p1;
    Point p2;
    p1.setter(2,3);
    p2.setter(3,8);
    p1.getter();
    p2.getter();
    
    
    Square s1;
    s1.setArea(4);
    std::cout << s1.getArea() << std::endl;



    return 0;
};