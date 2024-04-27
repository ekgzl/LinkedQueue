#include <iostream>
#include "Queue.h";

int main() {
    Queue<int> myQueue;

    // Test isEmpty() method
    std::cout << "Queue is empty: " << (myQueue.isEmpty() ? "True" : "False") << std::endl;

    // Test insert() method
    int item1 = 10;
    int item2 = 20;
    int item3 = 30;
    int item4 = 40;
    myQueue.insert(item1);
    myQueue.insert(item2);
    myQueue.insert(item3);
    myQueue.insert(item4);

    // Test getFront() and getBack() methods
    std::cout << "Front of the queue: " << myQueue.getFront() << std::endl;
    std::cout << "Back of the queue: " << myQueue.getBack() << std::endl;

    // Test deleteQ() method
    int deletedItem = myQueue.deleteQ();
    std::cout << "Deleted item: " << deletedItem << std::endl;

    // Test destroyQ() method
    myQueue.destroyQ();
    std::cout << "Queue is empty after destruction: " << (myQueue.isEmpty() ? "True" : "False") << std::endl;

    return 0;
}
