#include "InputRestrictedQueue.h"

template <typename T>
void InputRestrictedQueue<T>::Enqueue(const T& value) {
    auto newNode = std::make_shared<Node>(value);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
    currentSize++;
}

template <typename T>
T InputRestrictedQueue<T>::DequeueFront() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    T value = front->data;
    front = front->next;
    if (front) {
        front->prev.reset();
    } else {
        rear.reset();
    }
    currentSize--;
    return value;
}

template <typename T>
T InputRestrictedQueue<T>::DequeueRear() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    T value = rear->data;
    if (auto prev = rear->prev.lock()) {
        prev->next = nullptr;
        rear = prev;
    } else {
        front = rear = nullptr;
    }
    currentSize--;
    return value;
}

template <typename T>
T InputRestrictedQueue<T>::PeekFront() const {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return front->data;
}

template <typename T>
T InputRestrictedQueue<T>::PeekRear() const {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return rear->data;
}

template <typename T>
bool InputRestrictedQueue<T>::isEmpty() const {
    return front == nullptr;
}