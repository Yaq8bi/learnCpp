/*
Implement and test a stack class using a linked list to store and restore data of type int.
Test the class using assertions and ensure that all the allocated memory blocks are released.

The class shall provide the following function:
A function to push a data element to a stack.
A function to get number of the data elements stored in a stack.
A function to pop an element from a stack.
A function to clear a stack
Overload the insertion operator to print a stack to the terminal
*/
#include <iostream>
#include <cassert>

class Stack
{
    struct node_t
    {
        int data;
        node_t *next;
        node_t(int _data, node_t *_next) : data{_data}, next{_next} {} // Constructor for the node_t struct that is needed for the linked list.
    };

    node_t *top{nullptr}; // a pointer to the top of the stack.
    size_t elements{0};  // Number of elements in the stack.

public:
    Stack() = default;                        // Default constructor
    Stack(const Stack &) = delete;            // Copy constructor
    Stack &operator=(const Stack &) = delete; // Copy assignment oprator

    bool push(int _data) // Push data to the stack.
    {
        bool status{false};

        node_t *node = new (std::nothrow) /*return nullptr if, new doesn't allocate memory*/ node_t(_data, top); // Create a new node and assign the value to the data field and the top pointer to the next field.
/*node_t(struct)'yi, hafizada bir *node(pointer) olarak yapiyorum. Hafizada"new" ile yapiyorum, [std::nothrow, returns a nullptr if new fails]*/
        if (node_t != nullptr){
            status = true;
            elements++;
            top = node;
        }

        return status;
    }

    ~Stack() { clear(); } // Destructor
};

int main()
{

    return 0;
}