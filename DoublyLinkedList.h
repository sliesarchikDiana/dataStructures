#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <stdexcept>
#include <memory>

template <typename T>
class DoublyLinkedList {
private:
    std::shared_ptr<DoublyNode<T>> head;
    std::weak_ptr<DoublyNode<T>> tail;
    size_t size;
    
public:
    DoublyLinkedList();
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    T& at(size_t index);
    void insert(size_t index, const T& value);
    void remove(size_t index);
    [[nodiscard]] size_t get_size() const;
    [[nodiscard]] bool is_empty() const;
    int find(const T& value) const;


    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<T>& list) {
        auto current = list.head;
        os << "[";
        while (current) {
            os << current->data;
            if (current->next) {
                os << ", ";
            }
            current = current->next;
        }
        os << "]";
        return os;
    }
};

#endif // DOUBLYLINKEDLIST_H