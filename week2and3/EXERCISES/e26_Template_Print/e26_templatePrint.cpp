/*
Make a template print function to print an array.
Make a template function pointer type to point to the print function
Call the print function using an instance of the function pointer type to print an example array of type int.
*/
#include <iostream>

template <typename T, size_t MAX>
static void print(const T arr[MAX])
{
    for(int i = 0; i < MAX; i++)
    {
        std::cout << arr[i] << "\t";
    }
    // std::cout << std::endl;
    printf("\n");
}

template <typename T, size_t MAX>
using func_t = void (*)(const T[MAX]);//Bu bir function pointer type. Islevi bir fonksiyonu gostermek.

template <typename T>//burada yapilan sey, bir template struct olusturuluyor. Bu struct, bir array tipinde bir template aliyor.
struct array{};

template <typename T, size_t MAX>//Bu struct, bir array tipinde bir template aliyor.
struct array<T[MAX]>
{
    using elementType = T;
    static constexpr size_t size{MAX};
};

int main(void){
    int arr[]{1,2,3,4,5};

    using type = array<decltype(arr)>::elementType;//Here a type is defined, which is the type of the array.
    constexpr size_t size{array<decltype(arr)>::size};//Here the size of the array is defined.

    func_t<type, size> pptr{print<type, size>};
    pptr(arr);

    return 0;
}