#include <iostream>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "Queue.h"
#include "InputRestrictedQueue.h"
#include "Stack.h"
int main() {
    try {
        std::cout << "Singly Linked List:\n";
        SinglyLinkedList<int> sll;
        sll.push_front(10);
        sll.push_back(20);
        sll.push_front(5);
        sll.insert(1, 15);
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

/*        dll.pop_back();
        std::cout << "After pop_back: " << dll << std::endl;
        dll.remove(7);
*/
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout<<std::endl<<std::endl<<std::endl;

    Queue<int> queue;
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(40);
    std::cout << queue.Dequeue() << std::endl;
    std::cout << queue.peek() << std::endl;
    std::cout << "Is empty? " << (queue.isEmpty() ? "Yes" : "No") << "\n";
    std::cout << queue.Dequeue() << std::endl;
    std::cout << queue.Dequeue() << std::endl;


    std::cout<<std::endl<<std::endl<<std::endl;

    InputRestrictedQueue<int> IRQ;
    IRQ.Enqueue(10);
    IRQ.Enqueue(20);
    IRQ.Enqueue(5);
    std::cout << "DequeueFront: " << IRQ.DequeueFront() << "\n";
    std::cout << "DequeueRear: " << IRQ.DequeueRear() << "\n";
    std::cout << "Is empty? " << (IRQ.isEmpty() ? "Yes" : "No") << "\n";



    std::cout << std::endl<<std::endl<<std::endl;

    Stack<int> stack(3);

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);

    std::cout << "Top: " << stack.Peek() << "\n";
    std::cout << "Pop: " << stack.Pop() << "\n";
    std::cout << "Size: " << stack.size() << "\n";


    return 0;

}