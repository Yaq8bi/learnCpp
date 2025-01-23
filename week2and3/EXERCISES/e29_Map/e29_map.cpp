#include <iostream>

template <typename T>

struct Range
{
    T min;
    T max;
};
// conditional instanciation
template <typename F, typename T>
std::enable_if_t<std::is_arithmetic<T>::value, T> map(std::enable_if_t<std::is_arithmetic_v<F>, F> _data, Range<F> from, Range<T> to) // converting to arithmetic type. We will get a
{
    return (((to.max - to.min) / (from.max - from.min)) * (_data - from.min) + to.min);
}

int main(void)
{

    Range<float> from{0.0f, 3.3f};
    Range<int> to{0, 1023};

    //
    std::cout << map<float, int>(0.5f, from, to) << std::endl;

    return 0;
}