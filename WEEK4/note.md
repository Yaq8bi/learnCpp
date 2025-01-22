### Exception handling NOTES.
1. report error to upper layer(client).
2. enum: each value has a corresponding meaning.
3. Sub function, main function(onu cagiran) return vermesi.
4. Fatal error. Memory miss allocation: Terminate with a message.
5. Throw an exeption, and catch, then handle it.
6. If a function returns something, we should cover all the possibilties.
7. Based on misra standards, set a void, to show that you are aware of the return value and you choose to ignore it.`(void)printf("Hello");`
8. Set an attribute, ussually with safety critical systems.`IN C:_attribute((_warn_unused_result)) int functioin(void){return 8;}` `IN CPP: [[nodiscard]]`
9. The a char is the exception, the try will... and catch will look for the type provided in the catch parameter.`throw 'A';`
10. In ***function members***: we can use ThrowTryCatch.
11. With ***exceptions***, size of the executable is increased, but source file code is decreased.

### Smart Pointers.
1. a smart pointer: `int *ptr{new (std::nothrow) int{10}};`.
2. . 
   ```cpp
   class autoptr{
   template<typename T>
   public:autoptr(T*_ptr = nullptr) : ptr{_ptr}{}

    T &operator*() const {return*ptr;}//This part is the dereference operator. Yani bunun islevi pointerin gosterdigi degeri dondurmek.
    T *operator->() const {return ptr;}//overload the arrow operator.

  }
  int main(){
  int *ptr{neew int{10}};
  autoptr<int> a{ptr};
  std::cout << *a << std::endl;
  }
   ```
3. Deep copy constructor: `autoptr(const autoptr &source) : ptr{new T{*source.ptr}}{}`. This is useful for deep copy, when we have a pointer in the class.
4. an Rvalue is a temporary value that does not have a memory address. But an lvalue is a value that has a memory address. `int x{10};` x is an lvalue, `int{10};` is an rvalue.
- How to print a rvalue parameter from a function that will convert it from a rvalue to lvalue? `void func(const int &lval) {std::cout << lval << std::endl;}`. Just extends the life of the ***rvalue***. by making it a **const reference**. This technique of extending the ***rvalue references*** using the function above, we improve the **performance** of the code.

### Move Semantics.
- In the code we utilize the xvalue expression in C++: `std::move(str);` moves the str to a new location, and the str will be empty. This is useful for moving the data from one object to another.

### Unique Pointers.
- `std::unique_ptr<int> ptr{new int{10}};` is a unique pointer, that will delete the memory when it goes out of scope.

#### Throw, Try, Catch
```cpp
#include <iostream>

void func()
{
    throw 10;
}
in main(){
    try{//error detection.
        func();
    }
    catch(int exp/*The exception is an int*/)//can have multiple catch, for a single try.
    {
        std::cout << exp << std::endl;
    }

    catch(...)/*must be the last, the 3 dots represent 'any'.*/
    {
        throw 3.4f;
    }

    return 0;
}
```
```cpp
void func(int x)
try{
    throw "Exception";
}
catch(int)
{

}
catch(...){
    std::cout << x << std::endl;
}
```

### Examples
- Stack Unwinding: Very cool, Functions call each other and the function that starts the "try" will hadle the exception/error.

### Q&A
1. This is important: `#include <stdexcept>` look it up. `void func() noexcept{}` shall not throw an exception, if it does it will terminate the call to the function.
2. Throwing an exception through a constructor?
   - 
3. What is the parameter in `catch (const char *){}`.
   - .
4.  What is the difference between unique_pointer and make_unique?
   - `std::unique_ptr<int> ptr{new int{10}};` is a unique pointer, that will delete the memory when it goes out of scope. `std::make_unique<int>(10);` is a smart pointer that will delete the memory when it goes out of scope. The difference is that the `make_unique` is more efficient, and it is the preferred way to create a smart pointer.

