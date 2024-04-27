//
// Created by enes4 on 4/27/2024.
//

#ifndef QUEUEIMP_QUEUE_H
#define QUEUEIMP_QUEUE_H
#include <cassert>
using namespace std;

template<class T>
struct Node
        {
            T info;
            Node<T>* link;
        };

template<class T>
class Queue
        {
        private:
            Node<T> *front,*rear;
        public:
            Queue();
            ~Queue();
            bool isEmpty();
            T getFront();
            T getBack();
            void insert(T&);
            T deleteQ();
            void destroyQ();
        };


template<class T>
Queue<T>::Queue()
{
    rear = nullptr;
    front = nullptr;
}

template<class T>
Queue<T>::~Queue()
{
    destroyQ();
}

template<class T>
bool Queue<T>::isEmpty()
{
    return front == nullptr;
}

template<class T>
void Queue<T>::insert(T &item)
{
    Node<T>* newNode = new Node<T>;
    newNode->info = item;
    newNode->link = nullptr;

    if(front == nullptr)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->link = newNode;
        rear = newNode;
    }
}

template<class T>
T Queue<T>::getFront()
{
    return front->info;
}

template<class T>
T Queue<T>::getBack()
{
    return rear->info;
}

template<class T>
T Queue<T>::deleteQ()
{
    T temp = front->info;
    Node<T> *tempNode = front;
    front = front->link;
    delete tempNode;
    return temp;
}

template <class T>
void Queue<T>::destroyQ()
{
    Node<T> *temp;
    while(!isEmpty())
    {
        temp = front;
        front = front->link;
        delete temp;
    }
}
#endif //QUEUEIMP_QUEUE_H
