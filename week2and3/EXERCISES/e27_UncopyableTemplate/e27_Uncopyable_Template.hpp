// 27, 28, 29 = exam exercises.
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

    node_t *head{nullptr};
    node_t *tail{nullptr};
    size_t elemAmount{0};

public:
//make uncopyable
queue() = default;//default constructor
queue(const queue &) = delete;//copy constructor
queue &operator=(const queue &) = delete;//copy assignment, which means that the object cannot be copied.

    bool enqueue(const T &_data){
        bool status{false};
        node_t *node = new (std::nothrow) node_t{_data, nullptr};
    }
}