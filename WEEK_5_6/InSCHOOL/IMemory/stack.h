#include <iostream>//chatgptden yardim al, line 1 den 13e kadar tamamlasin.






virtual void *malloc(size_t *);
virtual free(void *ptr) = 0;
~IMemory();




class Stack
{
    struct node_t
    {
        int data;
        node_t *next;
        node_t(int _data, node_t *next) : data{_data}, next{_next} {}
    };
    size_t count{0};
    node_t *top{nullptr};
    IMemory *memory{nullptr};

public:
    Stack(const Stack &) = delete;
    Stack(IMemory *mem) : memory{mem} {}
    Stack &operator=(const Stack &) = delete;

    bool push(int _data)
    {
        bool status{false};

        if (memory != nullptr)
        {
            node_t *node{reinterpret_cast(memory->malloc(sizeof(node_t)))};

            if (node != nullptr)
            {
                node->data = _data;
                node->next = top;
                top = node;

                status = true;
                count++;
            }
        }

        return status;
    }

    bool pop(int &data)
    {
        bool status{false};

        if ((memory != nullptr) && (top != nullptr))
        {
            status = true;
            data = top->data;
            node_t tempNode{top};
            top = top->next;

            memory->free(tempNode);
            count--;
        }
        return status;
    }

    size_t available(void) { return count; }

    void clear(void)
    {
        while (top != nullptr)
        {
            node_t *tempNode{top};
            top = top->next
            memory->free(tempNode);
        }

        count = 0;
    }

    ~Stack() {clear();}
};