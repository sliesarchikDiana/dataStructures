#include "DoublyLinkedList.h"
#include "Node.h"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), size(0) {}

template <typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
    auto newNode = std::make_shared<DoublyNode<T>>(value);
    if (!head) {
        head = newNode;
        tail = head;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
    auto newNode = std::make_shared<DoublyNode<T>>(value);
    if (!head) {
        head = newNode;
        tail = head;
    } else {
        auto tail_ptr = tail.lock();
        tail_ptr->next = newNode;
        newNode->prev = tail_ptr;
        tail = newNode;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::pop_front() {
    if (!head) {
        throw std::out_of_range("List is empty");
    }
    
    if (!head->next) {
        head = nullptr;
        tail.reset();
    } else {
        head = head->next;
        head->prev.reset();
    }
    size--;
}

template <typename T>
void DoublyLinkedList<T>::pop_back() {
    if (!head) {
        throw std::out_of_range("List is empty");
    }
    
    if (!head->next) {
        head = nullptr;
        tail.reset();
    } else {
        auto tail_ptr = tail.lock();
        auto new_tail = tail_ptr->prev.lock();
        new_tail->next = nullptr;
        tail = new_tail;
    }
    size--;
}

template <typename T>
T& DoublyLinkedList<T>::at(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    
    if (index < size / 2) {
        auto current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    } else {
        auto current = tail.lock();
        for (size_t i = size - 1; i > index; --i) {
            current = current->prev.lock();
        }
        return current->data;
    }
}

template <typename T>
void DoublyLinkedList<T>::insert(size_t index, const T& value) {
    if (index > size) {
        throw std::out_of_range("Index out of range");
    }
    
    if (index == 0) {
        push_front(value);
    } else if (index == size) {
        push_back(value);
    } else {
        auto newNode = std::make_shared<DoublyNode<T>>(value);
        
        if (index < size / 2) {
            auto current = head;
            for (size_t i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        } else {
            auto current = tail.lock();
            for (size_t i = size - 1; i > index; --i) {
                current = current->prev.lock();
            }
            newNode->prev = current->prev;
            newNode->next = current;
            current->prev.lock()->next = newNode;
            current->prev = newNode;
        }
        size++;
    }
}

template <typename T>
void DoublyLinkedList<T>::remove(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    
    if (index == 0) {
        pop_front();
    } else if (index == size - 1) {
        pop_back();
    } else {
        if (index < size / 2) {
            auto current = head;
            for (size_t i = 0; i < index; ++i) {
                current = current->next;
            }
            current->prev.lock()->next = current->next;
            current->next->prev = current->prev;
        } else {
            auto current = tail.lock();
            for (size_t i = size - 1; i > index; --i) {
                current = current->prev.lock();
            }
            current->prev.lock()->next = current->next;
            current->next->prev = current->prev;
        }
        size--;
    }
}

template <typename T>
size_t DoublyLinkedList<T>::get_size() const {
    return size;
}

template <typename T>
bool DoublyLinkedList<T>::is_empty() const {
    return size == 0;
}

template <typename T>
int DoublyLinkedList<T>::find(const T& value) const {
    auto current = head;
    int index = 0;
    while (current) {
        if (current->data == value) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}


template class DoublyLinkedList<int>;
template class DoublyLinkedList<std::string>;