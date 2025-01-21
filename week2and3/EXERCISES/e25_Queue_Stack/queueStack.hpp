/*
Make an uncopyable queue class using a linked list to store and restore data of type int and to provide the following functions:
A function to enqueue a data element to a queue.
A function to dequeue a data element from a queue.
A function to get the number of data elements stored in a queue.
A function to clear a queue.
Test the class using assertions and ensure that all the allocated memory blocks are released.
*/
#ifndef QUEUE_H
#define QUEUE_H

#include <new>
#include <cstddef>

class Queue
{
    struct node_t
    {
        int data;
        node_t *next;
        node_t(int _data, node_t *_next) : data{_data}, next{_next} {}
    };

    node_t *head{nullptr}; // head pointer, is a struct of the above. It is a struct so that it will hold a int value/data and a pointer to the next node.
    node_t *tail{nullptr};
    size_t elemAmount{0};

public:
    Queue() = default;                        // The constructor
    Queue(const Queue &) = delete;            // delete the copy constructor
    Queue &operator=(const Queue &) = delete; // deletes the copy assignment so that another instance won't be created rather the new one will be the same instance behind the scene.

    bool enqueue(const int &_data)
    {
        bool status{false};
        // a node is created. not throw returns nullptr if no memory is allocated.
        node_t *node = new (std::nothrow) node_t{_data, nullptr};
        // if node is not a nullptr(not empty, yani exists)
        if (node != nullptr) // if node exists.
        {
            if (tail == nullptr) // if tail doesnt exist.
            {
                head = node; // Head: points to the node created on line 37.
                tail = head; // Tail: datas that were read.
            }
            else
            {
                tail->next = node;
                tail = node;
            }
            status = true;
            elemAmount++;
        }
        return status;
    }

    bool dequeue(int &_data)
    {
        bool status{false};

        if (head != nullptr)
        {
            status = true;
            _data = head->data; // Pass the value that is inside the head node to the data parameter refernce.

            node_t *temp{head}; // Why create the temp?
            head = head->next;
            delete temp;
            elemAmount--;

            if (head == nullptr)
            {
                tail = nullptr;
            }
        }
        return status;
    }

    size_t available(void)
    {
        return elemAmount;
    }

    void clear(void)
    {
        while (head != nullptr)
        {
            node_t *temp{head}; // we need temp to delete the top node. Because we need to delete the top node before we move the top pointer to the next node.
            head = head->next;
            delete temp;
        }
        elemAmount = 0;
        tail = head;
    }

    ~Queue()
    {
        clear();
    }
};

#endif // QUEUE_H