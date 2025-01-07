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
--
Point(int _x = 0, int _y = 0) : x{_x}, y{_y}
{
    std::cout << >>
} 
```
### Copy Constructor
- 

### Destructor
- Used for cleaning.
- Only one can exist.
- Must be public?
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
- 

## NOTES
[] what is `class Point { int x{0} };`
[] 