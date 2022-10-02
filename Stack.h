//
// Created by Johnathan Hwang on 10/1/22.
//

#ifndef LINKEDLIST_STACK_H
#define LINKEDLIST_STACK_H
#include "LinkedList.h"

template<class T>
class Stack
{
private:
    LinkedList<T> list;

public:
    T& top() const;
    void push(const T& data);
    T pop();
    bool empty() const;
    unsigned getSize() const;
    void print();

};

#include "Stack.cpp"
#endif //LINKEDLIST_STACK_H