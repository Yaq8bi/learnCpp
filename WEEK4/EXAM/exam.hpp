/**
 * @file exam.hpp
 * @author Ahmed Sami (Ahmetbugatti@gmail.com)
 * @brief Circular buffer class with functionalities of write, read, clear.
 * @version 0.1
 * @date 2025-01-27
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef EXAM_HPP
#define EXAM_HPP

#include <iostream>

/**
 * @brief class for creating  a buffer, reading from it, writing into it.
 *
 * @tparam T
 * @tparam N Size of the aray.
 */
template <typename T, size_t N>
class cirBuffer
{
private:
    static_assert(N >= 4, "Buffer size must be at least 4!");

    T Buffer[N];
    int head{0};
    int tail{0};
    static constexpr size_t limit{N};
    size_t elemAmount{0};

public:
    cirBuffer() = default;
    cirBuffer(const cirBuffer &) = delete;
    cirBuffer &operator=(const cirBuffer &) = delete;

    /**
     * @brief Writes into the array, where the tail is.
     *
     * @param _data The value that is written into the buffer.
     * @return true If process is successful.
     * @return false If process is failed.
     */
    bool write(const T &_data)
    {
        bool status{true};

        Buffer[tail] = _data; // write _data into tail position.

        if (elemAmount <= limit - 1)
        {
            elemAmount++; // element coutner goes up if its less than the number of elements.
        }

        // TAIL
        if (tail != limit - 1)
        {
            tail++; // tail moves right.
        }
        else
        {
            tail = 0;
        }

        // HEAD
        if (head != limit - 1) // if head is not at last stop => 0,1,2,3(4 total)
        {
            head++; // move head.
        }
        else
        {
            head = 0; // Put head back to begining position.
        }

        return status;
    }

    /**
     * @brief Read a data from the buffer.
     *
     * @param _data The number that is going to be assigned the value that the head is pointing to(oldest data).
     * @return true If the process is succesful.
     * @return false If the process is fail.
     */
    bool read(T &_data)
    {
        bool status{false};

        if (elemAmount == 0)
        {
            std::cerr << "Buffer is empty." << std::endl;
        }
        else
        {
            _data = Buffer[head]; // head position value copied into _data.
            status = true;
        }

        return status;
    }

    /**
     * @brief Clears the circular buffer and returns the status.
     *
     * @return true Return true if clearing is succesful.
     */
    bool clear()
    {
        for (size_t i = 0; i < limit; i++)
        {
            Buffer[i] = 0;
        }
        head = 0;
        tail = 0;
        elemAmount = 0;
        return true;
    }

    /**
     * @brief If the buffer is full.
     *
     * @return true
     */
    bool isFull()
    {
        return elemAmount >= limit - 1;
    }

    /**
     * @brief Returns the amount of elements in the buffer.
     *
     * @return size_t
     */
    size_t dataAmount()
    {
        return elemAmount;
    }

    /**
     * @brief Template function that works with arithmetic numbers, returns the average of elements in the circular buffer.
     *
     * @tparam Z
     * @tparam typename
     * @return double
     */
    template <typename Z, typename = std::enable_if_t<std::is_arithmetic_v<Z>>>
    double averageBuff()
    {
        double result{0.0};
        double tempNum{0}; // temporary number to add up the numbers.

        for (size_t i = 0; i < elemAmount; i++)
        {
            tempNum += Buffer[i];
        }

        result = tempNum / static_cast<double>(elemAmount); // divide them by the amount of elements, cast to double.

        return result;
    }

    /**
     * @brief The operator oveloding, to achieve the ability to easily print the contents of the circular buffer.
     *
     * @param _cout
     * @param _Buffer
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &_cout, const cirBuffer &_Buffer)
    {
        for (int i = 0; i <= _Buffer.elemAmount - 1; i++)
        {
            _cout << _Buffer.Buffer[i] << " ";
        }
        return _cout;
    }
};

#endif // EXAM_HPP