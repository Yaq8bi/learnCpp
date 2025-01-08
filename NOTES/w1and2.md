### OOP
1. can inherit abilities from each other: classes can aquire 
2. Polymorphism(animal analogy): a type can represent other types.
- The blue girl from X-men.
3.  

### Constuctor
1. Must be same name as the "class".
2. The "this->x" is a pointer to the current instance!
3. There could be multiple constructor in a class.
4. compiler will generate default constructor, IF you don't make one yourself!
5. Code example:
```c++
public:
Point() = default; // generate the default constructor.
--- UNIFORM INITIALIZATION ---
Point(int _x = 0, int _y = 0) : x{_x}, y{_y} {} //Constructor, yani bir obje oluşturulduğunda o objenin x ve y değerlerini set eder. 
-- NON UNIFORM INITIALIZATION ---
Point(int _x = 0, int _y = 0) {
    x = _x;
    y = _y;
} 

```
### Copy Constructor
- 

### Destructor
- Used for cleaning.
- Only one can exist.
- Must be public.
- Code:
  ```cpp
    ~className()
    {
        std::cout << "Destructor called!" << std::endl;
    }
  ```

### Alision
1. what is this?
2. `Point p{Point{1, 2}};`

### Uniform Initialization?
- Look it up and learn from GPT
  
### Singleton?
- 1 instance.

### Private Members Access
- .
  
### Inheritance
1. If Derived class inherites Base class privately. 
2. And an instance of Derived, is assigned to an instance of Base implicitly.
3. It shall not work, Due to the inheritance being done privately.
4. It should work if the casting is done explicitly.
5. #### Example:
```cpp
 Derived d{10,20};
 Base &b{d};
 Derived &ref{reinterpret_cast<Deried &>(b)};
```

## NOTES
[] what is `class Point { int x{0} };`
[] 


# Code example:
```cpp
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

```