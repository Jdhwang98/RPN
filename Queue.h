//
// Created by Johnathan Hwang on 10/1/22.
//

#ifndef LINKEDLIST_QUEUE_H
#define LINKEDLIST_QUEUE_H
#include "LinkedList.h"

template<class T>
class Queue
{
private:
    LinkedList<T> list;
public:
    T& front() const;
    void pop();
    void push (const T& item);
    bool empty() const;
    int getSize() const;
    void print();

};

#include "Queue.cpp"
#endif //LINKEDLIST_QUEUE_H
