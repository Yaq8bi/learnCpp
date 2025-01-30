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
#include <stdexcept>

/**
 * @brief class for creating  a buffer, reading from it, writing into it.
 *
 * @tparam T
 * @tparam N Size of the aray.
 */
template <typename T, size_t N, typename = std::enable_if<std::is_aritmetic_v<T>> class cirBuffer
{
private:
    static_assert(N >= 4, "Buffer size must be at least 4!");

    T Buffer[N];
    int head;
    int tail;
    size_t elemAmount;

public:
    cirBuffer() : head{0}, tail{0}, elemAmount{0} {};
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

        if (isFull())
        {
            head = (head + 1) % N; // Overwrite oldest data.
            
        }
        else
        {
            elemAmount++; // If Buffer is not full, this conditional statement ends with this increment. Below the assignment will happen.
        }

        Buffer[tail] = _data;
        tail = (tail + 1) % N; // move tail to next, where it will write to on next usage.

        if (Buffer[tail] != _data) // Ceck to see if the assignment is succesful.
        {
            status = false;
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
            status = false;
        }
        else
        {
            _data = Buffer[head];
            head = (head + 1) % N; // head goes to the right one step.
            elemAmount--;
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
        for (size_t i = 0; i < N; i++)
        {
            Buffer[i] = T();
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
    bool isFull() const
    {
        return elemAmount == N;
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
     * @brief The operator oveloding, to achieve the ability to easily print the contents of th ebuffer.
     *
     * @param _cout
     * @param _Buffer
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &_cout, const cirBuffer &_Buffer)
    {
        for (size_t i = 0; i < _Buffer.elemAmount; i++)
        {
            _cout << _Buffer.Buffer[(_Buffer.head + i) % N] << " ";
        }
        return _cout;
    }
};

#endif // EXAM_HPP