#include "Stack.h"

template <typename T>
void Stack<T>::Push(const T& value) {
    if (isFull()) {
        throw std::overflow_error("Stack is full");
    }
    data.push_back(value);
    currentSize++;
}

template <typename T>
T Stack<T>::Pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    T value = data.back();
    data.pop_back();
    currentSize--;
    return value;
}

template <typename T>
T Stack<T>::Peek() const {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return data.back();
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return currentSize == 0;
}

template <typename T>
bool Stack<T>::isFull() const {
    return currentSize >= capacity;
}