//
// Created by Johnathan Hwang on 10/1/22.
//

#ifndef LINKEDLIST_QUEUE_CPP
#define LINKEDLIST_QUEUE_CPP
#include "Queue.h"
template<class T>
T& Queue<T>::front() const
{
    return list.back();
}

template<class T>
void Queue<T>::pop()
{
    list.pop_front();
}

template<class T>
void Queue<T>::push(const T &item)
{
    list.push_back(item);
}

template<class T>
bool Queue<T>::empty() const
{
    return list.empty();
}

template<class T>
int Queue<T>::getSize() const
{
    return list.getSize();
}

template<class T>
void Queue<T>::print()
{
    std::cout << list << std::endl;
}

#endif