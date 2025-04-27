#include <iostream>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

int main() {
    try {
        std::cout << "Singly Linked List:\n";
        SinglyLinkedList<int> sll;
        sll.push_front(10);
        sll.push_back(20);
        sll.push_front(5);
        sll.insert(0, 7);

        std::cout << "List: " << sll << std::endl;
        std::cout << "Size: " << sll.get_size() << std::endl;
        std::cout << "Element at 2: " << sll.at(2) << std::endl;

        sll.remove(1);
        std::cout << "After remove at 1: " << sll << std::endl;



        std::cout << "\nDoubly Linked List:\n";
        DoublyLinkedList<std::string> dll;
        dll.push_back("cat");
        dll.push_front("dog");
        dll.push_back("parrot");
        dll.insert(3, "hamster");
        dll.insert(3, "fish");

        std::cout << "List: " << dll << std::endl;
        std::cout << "Size: " << dll.get_size() << std::endl;
        std::cout << "Element at 3: " << dll.at(3) << std::endl;

        dll.pop_back();
        std::cout << "After pop_back: " << dll << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}