#ifndef INPUT_RESTRICTED_QUEUE_H
#define INPUT_RESTRICTED_QUEUE_H

#include <memory>
#include <stdexcept>

template <typename T>
class InputRestrictedQueue {
private:
    struct Node {
        T data;
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> prev;
        explicit Node(const T& value) : data(value), next(nullptr) {}
    };

    std::shared_ptr<Node> front;
    std::shared_ptr<Node> rear;
    size_t currentSize;

public:
    InputRestrictedQueue() : front(nullptr), rear(nullptr), currentSize(0) {}

    void Enqueue(const T& value);
    T DequeueFront();
    T DequeueRear();
    [[nodiscard]] T PeekFront() const;
    [[nodiscard]] T PeekRear() const;
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] static bool isFull() { return false; }
    [[nodiscard]] size_t size() const { return currentSize; }
};


template class InputRestrictedQueue<int>;
template class InputRestrictedQueue<double>;


#endif // INPUT_RESTRICTED_QUEUE_H