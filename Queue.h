#ifndef QUEUE_H
#define QUEUE_H

#include <memory>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        std::shared_ptr<Node> next;
        explicit Node(const T& value) : data(value), next(nullptr) {}
    };

    std::shared_ptr<Node> front;
    std::shared_ptr<Node> rear;
    size_t currentSize;

public:
    Queue() : front(nullptr), rear(nullptr), currentSize(0) {}
    void Enqueue(const T& value);
    T Dequeue();
    T peek() const;
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] static bool isFull() { return false; }
    [[nodiscard]] size_t size() const { return currentSize; }
};


#include "Queue.cpp"

#endif // QUEUE_H