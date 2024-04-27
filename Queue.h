//
// Created by enes4 on 4/27/2024.
//

#ifndef QUEUEIMP_QUEUE_H
#define QUEUEIMP_QUEUE_H
#include <cassert>
using namespace std;

template<class T>
        struct Node{
            T data;
            Node<T>* link;
        };


template<class T>
class Queue {
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
    front = nullptr;
    rear = nullptr;
}

template <class T>
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
    Node<T> *newNode = new Node<T>;
    newNode->data = item;
    newNode->link = nullptr;
    if(front == nullptr)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->link = newNode;
        rear = rear->link;
    }

}

template <class T>
T Queue<T>::getFront()
{
    assert(front != nullptr);
    return front->data;
}

template <class T>
T Queue<T>::getBack()
{
    assert(front != nullptr);
    return rear->data;
}

template <class T>
T Queue<T>::deleteQ()
{
    assert(front!= nullptr);

    Node<T>* temp;
    temp = front;
    front= front->link;
    T tempValue = temp->data;
    delete temp;
    if(front == nullptr)
        rear = nullptr;

    return tempValue;
}

template <class T>
void Queue<T>::destroyQ()
{
    if(front == nullptr)
        return;

    Node<T>* temp;
    while(!isEmpty())
    {
        temp = front;
        delete temp;
        front = front->link;
    }


}

#endif //QUEUEIMP_QUEUE_H
