#include <iostream>
#include <cassert>
#include "e23_Class_Shapes.hpp"

 void Shape::printArea()
    {
        std::cout << "Area of the shape is: " << area << std::endl;
    }

    void Shape::setName(std::string _name)
    {
        name = _name;
    }

    std::string Shape::getName()
    {
        return name;
    }

    void Shape::setArea(int _area)
    {
        area = _area;
    }

    int Shape::getArea()
    {
        return area;
    }



     void Point::setter(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    void Point::getter()
    {
        std::cout << "x: " << x << " y: " << y << std::endl;
    }

    bool Point::operator==(const Point &p)
    {
        return (x == p.x && y == p.y); // bu bolean return ediyor. Ve iki point objesi arasinda karsilastirma yapabiliyor.
    }





 void Circle::setArea(int _centerPoint, int _radius)
    {
        centerPoint = _centerPoint;
        radius = _radius;
    }

    float Circle::getArea()
    {
        return pi * radius * radius; // Area of the circle is pi*r^2
    }

    bool Circle::operator==(const Circle &c)
    {
        return (centerPoint == c.centerPoint && radius == c.radius); // bu bolean return ediyor. Ve iki circle objesi arasinda karsilastirma yapabiliyor.
    }



void Square::setArea(int _length)// functions to be used to set the value of the hidden variable
    {
        length = _length;
    }

    int Square::getArea()
    {
        return length * length; // Area of the square is length^2.
    }

