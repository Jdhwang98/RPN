//
// Created by Johnathan Hwang on 10/1/22.
//

#ifndef LINKEDLIST_STACK_CPP
#define LINKEDLIST_STACK_CPP
#include "Stack.h"

template<class T>
T& Stack<T>::top() const
{
    return list.front();
}

template<class T>
void Stack<T>::push(const T &data)
{
    return list.push_front(data);
}

template<class T>
T Stack<T>::pop()
{
    T data = top();
    list.pop_front();
    return data;
}

template<class T>
bool Stack<T>::empty() const
{
    return list.empty();
}

template<class T>
unsigned Stack<T>::getSize() const
{
    return list.size();
}

template<class T>
void Stack<T>::print()
{
    std::cout << list << std::endl;
}

#endif

