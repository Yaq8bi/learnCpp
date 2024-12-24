#include "stack.h"

static_assert((stack::SIZE >= 4) && (stack::SIZE <= 1024), "SIZE shall be an integer in the range of 4 and 1024");

static int top = -1;
static int array[stack::SIZE] = {0};

void stack::clear(void)
{
    top = -1;
}

bool stack::push(int value)
{
    bool status = false;

    if (top < (stack::SIZE - 1))
    {
        top++;
        status = true;
        array[top] = value;
    }

    return status;
}

bool stack::pop(int &elem)
{
    bool status = false;

    if (top > -1)
    {
        elem = array[top];
        status = true;
        top--;
    }

    return status;
}

int stack::available(void)
{
    return (top + 1);
}
