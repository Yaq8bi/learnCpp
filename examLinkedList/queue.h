
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template <typename T>

class CircularQueueLL
{
private:
    struct node_t
    {
        T data;
        node_t *next;
        node_t() : data(T()), next(nullptr) {} // constructor
    };

    node_t *head; // reading arrow
    node_t *tail; // write arrow

    size_t maxSize;     // max size for linked list
    size_t currentSize; // amount in linked list

public:
    /**
     * @brief Construct a new CircularQueueLL object with a specified size.
     * Throw error if size is less than 2.
     *
     * @param size The maximum size of the queue.
     */

    CircularQueueLL(size_t size) : maxSize(size), currentSize(0), head(nullptr), tail(nullptr)
    {
        if (size <= 2)
        {
            throw std::invalid_argument("Queue size must be greater than 2");
        }

        // the first node
        head = new node_t{};
        node_t *current = head;

        // remaining nodes
        for (size_t i = 1; i < maxSize; ++i)
        {
            current->next = new node_t{}; // allocate memory for new node
            current = current->next;      // current will move like faroch said
        }
        // circular LL
        current->next = head;
        tail = head;
    }

    /**
     * @brief Disable copy constructor to prevent copying of the queue.
     */
    CircularQueueLL(const CircularQueueLL<T> &) = delete; // Disable copy constructor

    /**
     * @brief Disable copy assignment to prevent copying of the queue.
     */
    CircularQueueLL &operator=(const CircularQueueLL<T> &) = delete; // Disable copy assignment

    /**
     * @brief Move constructor to transfer ownership of resources from another queue.
     *
     * @param other The queue to move from.
     */
    CircularQueueLL(CircularQueueLL<T> &&other) noexcept;

    /**
     * @brief Move assignment operator to transfer ownership of resources from another queue.
     *
     * @param other The queue to move from.
     * @return CircularQueueLL& Reference to the current queue.
     */
    CircularQueueLL &operator=(CircularQueueLL<T> &&other) noexcept;

    /**
     * @brief Write data to the queue.
     *
     * @param data The data to write.
     */
    void writeData(const T &data);

    /**
     * @brief Read data from the queue.
     *
     * @return T The data read from the queue.
     */
    T readData();

    /**
     * @brief Check if the queue is full.
     *
     * @return true If the queue is full.
     * @return false If the queue is not full.
     */
    bool isFull() const;

    /**
     * @brief Get the number of elements in the queue.
     *
     * @return size_t The number of elements in the queue.
     */
    size_t countElements() const;

    /**
     * @brief Resize the queue to a new size.
     *
     * @param newSize The new size of the queue.
     * @return true If the resize was successful.
     * @return false If the resize failed.
     */
    bool resizeQueue(size_t newSize);

    /**
     * @brief Empty the queue.
     */
    void emptyQueue();

    /**
     * @brief Get the average of the elements in the queue.
     *
     * @return double The average of the elements.
     */
    double getAverage() const;

    /**
     * @brief Destroy the CircularQueueLL object and free all resources.
     */
    ~CircularQueueLL(); // destructor
};

// Destructor: Free all nodes
template <typename T>
CircularQueueLL<T>::~CircularQueueLL()
{
    if (!head)
        return; // Avoid deleting nullptr

    node_t *current = head;
    node_t *nextNode = nullptr;

    // Traverse and delete each node
    do
    {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != head); // Stop when we loop back

    head = tail = nullptr; // Ensure no dangling pointers
}

// Move Constructor
template <typename T>
CircularQueueLL<T>::CircularQueueLL(CircularQueueLL<T> &&other) noexcept
    : maxSize(other.maxSize), currentSize(other.currentSize), head(other.head), tail(other.tail)
{
    other.head = nullptr;
    other.tail = nullptr;
    other.currentSize = 0;
}

// Move Assignment Operator
template <typename T>
CircularQueueLL<T> &CircularQueueLL<T>::operator=(CircularQueueLL<T> &&other) noexcept
{
    if (this != &other)
    {
        // free nodes
        node_t *current = head;
        while (current)
        {
            node_t *next = current->next;
            delete current;
            if (next == head)
                break; // Stop at the last node
            current = next;
        }

        // Move ownership
        head = other.head;
        tail = other.tail;
        maxSize = other.maxSize;
        currentSize = other.currentSize;

        other.head = nullptr;
        other.tail = nullptr;
        other.currentSize = 0;
    }
    return *this;
}

// Write data to the queue
template <typename T>
void CircularQueueLL<T>::writeData(const T &data)
{
    tail->data = data;         // Assign data to the tail.
    if (currentSize < maxSize) // If current size of buffer is not full
    {
        ++currentSize;
    }
    else
    { // If full, move head forward => overwrite oldest
        head = head->next;
    }
    tail = tail->next; // Move tail forward
}

// Read data from the queue
template <typename T>
T CircularQueueLL<T>::readData()
{
    if (currentSize == 0)
    {
        throw std::underflow_error("Queue is empty");
    }

    T data = head->data;
    head = head->next; // Move head forward
    --currentSize;
    return data;
}

// Check if queue is full
template <typename T>
bool CircularQueueLL<T>::isFull() const
{
    return currentSize == maxSize;
}

// Count number of elements in queue
template <typename T>
size_t CircularQueueLL<T>::countElements() const
{
    return currentSize;
}

// Resize the queue
template <typename T>
bool CircularQueueLL<T>::resizeQueue(size_t newSize)
{
    if (newSize <= 2)
        return false;

    if (newSize < currentSize)
    {
        // Reduce size, remove oldest elements
        size_t removeCount = currentSize - newSize;
        for (size_t i = 0; i < removeCount; ++i)
        {
            readData();
        }
    }

    if (newSize > maxSize)
    {
        // Allocate new nodes if needed
        size_t addCount = newSize - maxSize;
        node_t *prev = tail;
        for (size_t i = 0; i < addCount; ++i)
        {
            node_t *newNode = new node_t{};
            prev->next = newNode;
            prev = newNode;
        }
        prev->next = head; // Maintain circular link
        tail = prev;       // Update tail to the new last node
    }
    else if (newSize < maxSize)
    {
        // Remove extra nodes if needed
        size_t removeCount = maxSize - newSize;
        node_t *current = head;

        for (size_t i = 0; i < removeCount; ++i)
        {
            node_t *temp = current;
            current = current->next;
            delete temp;
        }

        head = current;    // Update head
        tail->next = head; // Ensure circular link
    }

    maxSize = newSize;
    return true;
}

// Make queue empty
template <typename T>
void CircularQueueLL<T>::emptyQueue()
{
    currentSize = 0;
    head = tail;
}

// Get average
template <typename T>
double CircularQueueLL<T>::getAverage() const
{
    static_assert(std::is_arithmetic<T>::value, "getAverage() is only available for numeric types.");

    if (currentSize == 0)
        return 0.0;

    double sum = 0;
    node_t *current = head;
    for (size_t i = 0; i < currentSize; ++i)
    {
        sum += current->data;
        current = current->next;
    }
    return sum / currentSize;
}

#endif
