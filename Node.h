#pragma once
#include <memory>

template <typename T>
struct Node {
    T data;
    std::shared_ptr<Node<T>> next;

    explicit Node(const T& value) : data(value), next(nullptr) {}
};



template <typename T>
struct DoublyNode {
    T data;
    std::shared_ptr<DoublyNode<T>> next;
    std::weak_ptr<DoublyNode<T>> prev;

    explicit DoublyNode(const T& value) : data(value), next(nullptr) {}
};