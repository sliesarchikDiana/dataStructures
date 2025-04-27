#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include "Node.h"
#include <memory>

template <typename T>
class SinglyLinkedList {
private:
    std::shared_ptr<Node<T>> head;
    size_t size;
    
public:
    SinglyLinkedList();
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


    friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList<T>& list) {
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

#endif // SINGLYLINKEDLIST_H