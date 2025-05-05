#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> data;
    size_t capacity;
    size_t currentSize;

public:
    explicit Stack(size_t size = 100) : capacity(size), currentSize(0) {
        data.reserve(capacity);
    }

    void Push(const T& value);
    T Pop();
    [[nodiscard]] T Peek() const;
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] bool isFull() const;
    [[nodiscard]] size_t size() const { return currentSize; }
};


template class Stack<int>;
template class Stack<double>;

#endif // STACK_H