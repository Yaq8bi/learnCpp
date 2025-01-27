/*
Implement and test an uncopyable, but movable template stack class using an array whose size is specified during creation(size shall be greater than three)
The class shall provide the following function:
A function to get size of a stack.
A function to push a data element to a stack.
A function to get number of the data elements stored in a stack.
A function to pop an element from a stack.
A function to clear a stack
Use exception handling, test the class using assertions, ensure that the dynamic memory is managed properly and the class is movable.
*/

#include <iostream>

template <typename T>
class Darray
{

private:
    T *ptr;
    size_t size;

public:
    // delete copy constructor
    Darray(const Darray &) = delete;
    // delete copyt assignment operator
    Darray &operator=(const Darray &) = delete;
    // constructor
    Darray(size_t _size) : size{_size}, ptr(new T[_size{}]) {}
    // implement the subscript operator, we need one with and one without reference return type.
    T &operator[](size_t index)
    {
        if (index >= size)
        {
            throw std::range_error{"Wrong Index"};
        }
        return ptr[index];
    }

    T operator[](size_t index) const
    {
        if (index >= size)
        {
            throw std::range_error{"Wrong Index"};
        }
        return ptr[index];
    }

    void resize(size_t _size);
    // destructor
    ~Darray() { delete ptr };
};

template <typename T>
void Darray<T>::resize(size_t _size)
{
    if (size_t > _size)
    { // allocate mem with new size.
        T *temp{new T[_size]{}};
        for (size_t i = 0; i < size; i++)
        {
            temp[i] = ptr[i];
        }

        delete ptr;
        size = _size;
        ptr = temp;
    }
    else if (_size < size)
    {
        if (size_t > _size)
        { // allocate mem with new size.
            T *temp{new T[_size]{}};
            for (size_t i = 0; i < size; i++)
            {
                temp[i] = ptr[i];
            }

            delete ptr;
            size = _size;
            ptr = temp;
        }
        else
        {
            ;
        }
    }
}

int main()
{

    Darray<int> arr(10);

    arr[0];
    = 100;

    return 0;
}