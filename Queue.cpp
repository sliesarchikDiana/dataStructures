#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.h"

// Template method implementations
template <typename T>
void Queue<T>::Enqueue(const T& value) {
    auto newNode = std::make_shared<Node>(value);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    currentSize++;
}

template <typename T>
T Queue<T>::Dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    T value = front->data;
    front = front->next;
    if (!front) {
        rear.reset();
    }
    currentSize--;
    return value;
}

template <typename T>
T Queue<T>::peek() const {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return front->data;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return front == nullptr;
}

// Explicit instantiations (for the types you plan to use)
template class Queue<int>;       // Example for int
template class Queue<double>;    // Example for double
// Add more types as needed

#endif // QUEUE_CPP