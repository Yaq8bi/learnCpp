/*
The header file
*/
#ifndef E23_CLASS_SHAPES_HPP
#define E23_CLASS_SHAPES_HPP

#include <iostream>

class Shape
{
public:
    Shape() : name{"Shape"} {};

    void printArea();
    void setName(std::string _name);
    std::string getName();
    void setArea(int _area);
    int getArea();

private:
    std::string name;
    int area;
    // Make the points of  x and y on the 2d cartesian coordinate system.
};

class Point : public Shape
{
private:
    int x;
    int y;

public:
    Point() : x{0}, y{0} {};
    void setter(int _x, int _y);
    void getter();
    bool operator==(const Point &p);
};

class Circle : public Shape
{
private:
    int centerPoint;
    int radius;
    float pi = 3.14;

public:
    Circle() : centerPoint{3}, radius{5} {};
    void setArea(int _centerPoint, int _radius);
    float getArea();
    bool operator==(const Circle &c);
};

class Square : public Shape
{
private:
    int length;

public:
    Square() : length{5} {};
    void setArea(int _length);
    int getArea();
};

#endif // E23_CLASS_SHAPES_HPP