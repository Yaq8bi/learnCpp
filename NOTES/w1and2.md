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
## How Does Constructor Work?

In your example:
```cpp
/*Stack() is the constructor—it has the same name as the class.*/
Stack() : stack{} {}
/*: stack{} is initializer list syntax, which ensures that the stack array is zero-initialized (all elements are set to 0).*/
top{-1} /*directly initializes the top variable to -1.*/
```
---
### Copy Constructor
- 
---
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
---
### Alision
1. what is this?
2. `Point p{Point{1, 2}};`
---
### Uniform Initialization?
- ` Point(int parameterVarX, parameterVarY) : privateVarX{parameterVarX}, privateVarY{parameterVarY}`
  ---
# Singleton
- There shall be only 1 instance: mnemonic/metaphorically similar to a manager, there is only 1 manager. We can access to the class functionality through the singleton object. 
<h3 style="color: lightblue;">Example</h3>

```cpp
Point(int m, int n) : x{m}, y{n} {}
Point(const Point &) = delete;
```
- `Point(const Point &) = delete;` ensures the singleton cannot be copied (no duplicates).

### What is a Singleton inside its class?
The line `Point(const Point &) = delete;` in C++ explicitly deletes the copy constructor of the Point class. This ensures that the compiler will not generate a default copy constructor, and any attempt to copy an instance of the class will result in a compile-time error.

Here's a breakdown of why this ensures a single instance:

1. Copy Constructor Overview:
A copy constructor allows creating a new object as a copy of an existing object (e.g., Point p2 = p1;).
If not explicitly defined, the compiler automatically provides a default copy constructor.
<br>
1. Deleting the Copy Constructor:
By explicitly writing Point(const Point&) = delete;, you tell the compiler, "This operation is not allowed."
This makes any code that tries to copy an instance of the Point class invalid, ensuring there can be no duplicate instances.
<br>
1. Singleton Context:
In a singleton design pattern, we aim to ensure that only one instance of a class exists throughout the program.
Preventing copying is a critical step because copies would undermine the singleton's guarantee of a single instance.
<br>
1. Enforcement:
Attempting to copy an instance `(e.g., via Point p2 = p1;or Point p3(p1);)` will result in a compilation error, enforcing this restriction at compile time.
</p>
EXAMPLE:

```cpp
#include <iostream>

class Point {
public:
    static Point& getInstance() {
        static Point instance; // Single instance
        return instance;
    }

    Point(const Point&) = delete; // No copying
    Point& operator=(const Point&) = delete; // No assignment

private:
    Point() {} // Private constructor
};

int main() {
    Point& p1 = Point::getInstance();
    // Point p2 = p1; // Compile-time error
    // Point p3(p1);  // Compile-time error

    std::cout << "Single instance enforced!" << std::endl;
    return 0;
}

```

---

### Private Members Access
1. In a class, the public section can access private variables.
2. Only a const object can use a const function.
  ---
### Inheritance
1. If Derived class inherites Base class privately. 
2. And an instance of Derived, is assigned to an instance of Base implicitly.
3. It shall not work, Due to the inheritance being done privately.
4. It should work if the casting is done explicitly.
---

### Templates
1. Generic programing.

#### Example:
```cpp
 Derived d{10,20};
 Base &b{d};
 Derived &ref{reinterpret_cast<Deried &>(b)};
```

## NOTES | Look up
[] what is `class Point { int x{0} };`
[] what is a singleton?
[] Virtual & Override
[] Dynamic Polymorphism[pdf'i oku]: 1. Size of program increased. 2. Slow(Pointers must be dereferenced after... ?).
[] Why do we need virtual function? Pure virtual function, prototype in class: defined globally.
[] 

```cpp
class Animal{
    std::string name;
    protected:
    Animal(const std::string &_name):name{_name}{}
};
class Cat : Animal
{
    public:
    Cat(const sd::string  _name) : Animal{_name}{}

}

int main(){
Cat c;
Animal *ptr{&c};
}
```

# Code example:
