#ifndef E27_UNCOPYABLE_TEMPLATE_HPP
#define E27_UNCOPYABLE_TEMPLATE_HPP

#include <iostream>
#include <new>
#include <cstddef>

template <typename T>
class queue
{
    struct node_t
    {
        T data;
        node_t *next;
        node_t(const T &_data, node_t *_next) : data(_data), next(_next) {} // the object created from this struct takes parameters and assigns them to the data and the next.
    };

    node_t *head{nullptr}; // starting position.
    node_t *tail{nullptr}; // last queued node.(latest)
    size_t elemAmount{0};

public:
    // make uncopyable
    queue() = default;                        // default constructor
    queue(const queue &) = delete;            // Make the class **UNCOPYABLE** copy constructor deleted.
    queue &operator=(const queue &) = delete; // copy assignment, which means that the object cannot be copied by assignment operator.

    bool enqueue(const T &_data)
    {
        bool status{false};
        node_t *node = new (std::nothrow) node_t{_data, nullptr};

        // if the list(node) doesn't exist, go ahead and create a node.
        if (node != nullptr)
        {
            if (tail == nullptr)
            {
                head = node;
                tail = node;
            }
            else // if the tail is pointing to nothing, then make the tail and the head to point to this local node.
            {
                tail->next = node;
                tail = node;
            }
            status = true;
            elemAmount++;
        }
        return status;
    }

    bool dequeue(T &_data)
    {
        bool status{false};
        if (head != nullptr) // means something is in the head.
        {
            status = true;
            _data = head->data;
            node_t *temp{head}; // initialized as head, so the node that the head WAS poining to is now also pointed to by TEMP.
            head = head->next;  // head wiil be head next.
            delete temp;        // deleteing the node that the heaad WAS pointing to.
            elemAmount--;
            // When the time comes and the head will point to the next node, yet there is no node and it falls back to NULLPTR, the Tail shall too!
            if (head == nullptr)
            {
                tail = nullptr;
            }
        }
        return status;
    }

    void erase(void)
    {
        while (head != nullptr)
        {
            node_t *temp{head};
            head = head->next;
            delete temp;
        }
        if (head == nullptr)
        {
            tail = nullptr; // as the one furthest behind, is now upclose, which means the distance and everything in between the last and the first guy is gone. So naturally they should be nullptrs.
            elemAmount = 0;
        }
    }

    size_t leftNodes(void) { return elemAmount; }

    // friend auto friendFunction(); // you return auto, not a "typename||T".
    ~queue() { erase(); }
};
#endif // E27_UNCOPYABLE_TEMPLATE.HPP
/*Q&A Soufien.
1. is doing the exercises 27, 28, 29 enough to prepare for the exam?
2. Does the things Faroch covered in week 4 be on the exam?
3. */