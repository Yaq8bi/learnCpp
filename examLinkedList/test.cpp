#include <gtest/gtest.h> // Google Test
#include "queue.h"       // Include the header file

// test cases for different data types.
using MyTypes = ::testing::Types<int, float, std::string>;
TYPED_TEST_SUITE(CircularQueueTest, MyTypes);

template <typename T>
T convertToType(int val);

template <>
int convertToType<int>(int val) { return val; }

template <>
float convertToType<float>(int val) { return static_cast<float>(val); }

template <>
std::string convertToType<std::string>(int val) { return std::to_string(val); }

// Test fixture for CircularQueueLL
template <typename T>
class CircularQueueTest : public ::testing::Test
{
protected:
    CircularQueueLL<T> *queue;

    void SetUp() override
    {
        queue = new CircularQueueLL<T>(5); // Start with size 5
    }

    void TearDown() override
    {
        delete queue;
    }
};

// Passed

// Test queue initialization
TYPED_TEST(CircularQueueTest, Initialization)
{
    EXPECT_EQ(this->queue->countElements(), 0);
    EXPECT_FALSE(this->queue->isFull());
}

// Test queue amount
TYPED_TEST(CircularQueueTest, Amount)
{
    EXPECT_THROW(CircularQueueLL<int> queue(1), std::invalid_argument);
}

// Passed
TYPED_TEST(CircularQueueTest, WriteRead)
{

    this->queue->writeData(convertToType<TypeParam>(10));
    this->queue->writeData(convertToType<TypeParam>(20));
    EXPECT_EQ(this->queue->readData(), convertToType<TypeParam>(10));
    EXPECT_EQ(this->queue->readData(), convertToType<TypeParam>(20));
}

// Testing overwriting
TYPED_TEST(CircularQueueTest, OverwriteOldestData)
{
    this->queue->writeData(convertToType<TypeParam>(1));
    this->queue->writeData(convertToType<TypeParam>(2));
    this->queue->writeData(convertToType<TypeParam>(3));
    this->queue->writeData(convertToType<TypeParam>(4));
    this->queue->writeData(convertToType<TypeParam>(5)); // Now full

    // Adding another element should overwrite the oldest (1) = > to become 6
    this->queue->writeData(convertToType<TypeParam>(6));

    EXPECT_EQ(this->queue->readData(), convertToType<TypeParam>(2)); // 1 was overwrittenconvertToType
}

// Resize Testing
TYPED_TEST(CircularQueueTest, ResizeQueue)
{
    this->queue->writeData(convertToType<TypeParam>(1));
    this->queue->writeData(convertToType<TypeParam>(2));

    EXPECT_EQ(this->queue->countElements(), 2);

    // Resize to a larger size
    EXPECT_TRUE(this->queue->resizeQueue(10));
    EXPECT_EQ(this->queue->countElements(), 2);

    // Resize to a smaller size (removes oldest if necessary)
    EXPECT_TRUE(this->queue->resizeQueue(3));
    EXPECT_LE(this->queue->countElements(), 3);
}

// Testing emptying the queue
TYPED_TEST(CircularQueueTest, Empty_queue)
{
    this->queue->writeData(convertToType<TypeParam>(1));
    this->queue->writeData(convertToType<TypeParam>(2));

    this->queue->emptyQueue();
    EXPECT_EQ(this->queue->countElements(), 0); // If queue is emptied, check if its elements in queue is 0.
}

// Test arithmetic average & string
TEST(CircularQueueNumericTest, GetAverage)
{
    CircularQueueLL<int> intQueue(5); // Create queue for the int types to test getAverage()
    intQueue.writeData(10);
    intQueue.writeData(20);
    intQueue.writeData(30);

    EXPECT_DOUBLE_EQ(intQueue.getAverage(), 20.0);

    CircularQueueLL<float> floatQueue(5); // Create queue for the float type to test getAverage function.
    floatQueue.writeData(1.5f);
    floatQueue.writeData(2.5f);
    floatQueue.writeData(3.5f);

    EXPECT_DOUBLE_EQ(floatQueue.getAverage(), 2.5); // Test passes if average is 2.5(float).
}

// Test move semantic
TEST(CircularQueueMoveTest, MoveConstructor)
{
    CircularQueueLL<int> queue1(5);
    queue1.writeData(1);
    queue1.writeData(2);

    CircularQueueLL<int> queue2(std::move(queue1)); // Move constructor
    EXPECT_EQ(queue2.countElements(), 2);
}

TEST(CircularQueueMoveTest, MoveAssignment)
{
    CircularQueueLL<int> queue1(5);
    queue1.writeData(1);
    queue1.writeData(2);

    CircularQueueLL<int> queue2(3);
    queue2 = std::move(queue1); // Move assignment
    EXPECT_EQ(queue2.countElements(), 2);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}