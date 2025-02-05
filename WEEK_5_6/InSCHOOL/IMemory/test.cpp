#include "stack.h"
#include <vector>
#include <gtest/gtest.h>

class Memory : public IMemory 
{
    bool mallocSuccess{true};
    std::vector<void *> ptrs;

    public:
    void setStatus(bool_success){
        success = _success;
    }

    //Here we spy on malloc.
    void *malloc(size_t size) override
    {
        void *ptr{nullptr};
        if (success)
        {
            ptr = std::malloc(size);
            if (ptr != nullptr)
            {
                ptrs.push_back(ptr);
            }
            
        }
        return ptr;
    }

    void free(void *ptr) override{
        ptrs.erase(std::remove(ptrs.begin(), ptrs.end(), ptr), ptrs.end());
        std::free(ptr);//after we remove the ptr from the vector, we relese i from the memory.
    }

    ~Memory() {EXPECT_EQ(0, ptrs.size()); }
};

//if no main, compile with gtest_main
TEST(stack, placeHolderName){
    int value ;
    Stack stack{nullptr};
    EXPECT_FALSE(stack.push(10));
    EXPECT_TRUE(stack.pop(value));
}


//Test stack
TEST(stack, placeHolder)
{
    int 
}

//Test pop
TEST(stack, pop)
{

}