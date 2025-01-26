#ifndef EXAM_HPP
#define EXAM_HPP

#include <iostream>
#include <string>

template <typename T, size_t N>
class cirBuffer
{
private:
    T Buffer[N]{0};
    int head{-1};
    int tail{-1};
    size_t elemAmount{0};

public:
    cirBuffer() = default;
    cirBuffer(const cirBuffer &) = delete;
    cirBuffer &operator=(const cirBuffer &) = delete;

    bool write(const T &_data)
    {
        N - 1;
        if (N < 4)
        {
            printf("\v\t**N is less than 4**\n");
            try
            {
                checkError();
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }

        bool status{false};

        if (Buffer != nullptr)
        {
            if (tail == -1)
            {
                tail = 0;
                head = 0;
            }

            if (tail == N)
            {
                Buffer[tail] = _data;
                status = true;
                elemAmount++;

                tail = 0;
            }
            else
            {
                Buffer[tail] = _data;
                status = true;
                elemAmount++;

                tail++;
            }
        }
        return status;
    }

    bool read(T &_data)
    {
        bool status{false};

        if (head != -1)
        {
            _data = Buffer[head];
            Buffer[head] = 0;
            status = true;
            head++;
            elemAmount--;
        }
        else if (head == N)
        {
            _data = Buffer[head];
            Buffer[head] = 0;
            status = true;
            head = 0;
            elemAmount--;
        }
        else if (head == -1 && tail == -1)
        {
            std::cout << "You must write a data in to the buffer, before you can read from the buffer!" << std::endl;
        }

        return status;
    }

    bool clear()
    {
        bool status{false};
        if (isFull())
        {
            for (int i = 0; i < N; i++)
            {
                Buffer[i] = 0;
            }
            status = true;
        }

        return status;
    }

    bool isFull()
    {
        bool status{false};

        if (Buffer[N - 1] != 0)
        {
            status = true;
        }

        return status;
    }

    int dataAmount()
    {
        int tempNum{0};
        for (int &i : Buffer)
        {
            if (i != 0)
            {
                tempNum++;
            }
        }
        return tempNum;
    }

    // friend operator<<(std::ostream &_cout, cirBuffer &_Buffer)

    void checkError()
    {
        throw 404;
    }
};

// void operator<<(std::ostream &_cout, cirBuffer &_Buffer)
//     {
//         _cout << _cirBuffer._Buffer[0] << std::endl;
//     }


#endif // EXAM_HPP