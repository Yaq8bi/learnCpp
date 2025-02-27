#include "list.h"

List::List(List &&that) noexcept : count{that.count}, head{that.head}, memory{that.memory}
{
    that.count = 0;
    that.head = nullptr;
    that.memory = nullptr;
}

List &List::operator=(List &&that) noexcept
{
    if (this != &that)
    {
        clear();

        head = that.head;
        count = that.count;
        memory = that.memory;

        that.count = 0;
        that.head = nullptr;
        that.memory = nullptr;
    }

    return *this;
}

bool List::insert(int item)
{
    bool status{false};

    if ((memory != nullptr) && (0 == search(item)))
    {
        node_t *node{static_cast<node_t *>(memory->malloc(sizeof(node_t)))};

        if (node != nullptr)
        {
            count++;
            status = true;
            node->data = item;

            if (head == nullptr)
            {
                head = node;
            }
            else
            {
                node_t *current{head};
                node_t *previous{nullptr};

                while (current != nullptr)
                {
                    if (current->data > item)
                    {
                        break;
                    }
                    previous = current;
                    current = current->next;
                }

                if (previous == nullptr) // Insert the node in the beginning
                {
                    node->next = head;
                    head = node;
                }
                else if (current == nullptr) // Insert the node in the end
                {
                    previous->next = node;
                }
                else
                {
                    node->next = current;
                    previous->next = node;
                }
            }
        }
    }

    return status;
}

size_t List::search(int value)
{
    size_t counter{0};
    size_t position{0};
    node_t *cursor{head};

    while (cursor != nullptr)
    {
        counter++;
        if (cursor->data == value)
        {
            position = counter;
            break;
        }
        cursor = cursor->next;
    }

    return position;
}

bool List::remove(int value)
{
    bool status{false};

    if ((memory != nullptr) && (0 < search(value)))
    {
        count--;
        status = true;
        node_t *current{head};
        node_t *previous{nullptr};

        while (current != nullptr)
        {
            if (current->data == value)
            {
                if (previous == nullptr) // delete the first node
                {
                    head = current->next;
                }
                else
                {
                    previous->next = current->next;
                }

                memory->free(current);
                break;
            }

            previous = current;
            current = current->next;
        }
    }

    return status;
}

bool List::edit(int cvalue, int nvalue)
{
    bool status{false};

    if (0 < search(cvalue))
    {
        if (0 == search(nvalue))
        {
            if (insert(nvalue))
            {
                status = true;
                (void)remove(cvalue);
            }
        }
    }

    return status;
}

void List::clear(void)
{
    while (head != nullptr)
    {
        node_t *temp{head};
        head = head->next;
        memory->free(temp);
    }
    count = 0;
}