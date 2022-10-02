//
// Created by Johnathan Hwang on 10/1/22.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H


#include "Node.h"
#include <iostream>
#include <cassert>

template<class T>
class LinkedList
{
private:
    Node<T>* head = nullptr, *tail = nullptr;
    Node<T>* createNode(T item);
    void addFirstNode(T item);
    void insertAfter(T item, Node<T>* node);
    void insertBefore(T item, Node<T>* node);
    Node<T>* search(T item);
    void remove(Node<T>* node);
    unsigned _size = 0;
public:

    ////The Big 3////

    LinkedList();
    LinkedList(const LinkedList& list);
    ~LinkedList();

    template<class S>
    friend std::ostream& operator<<(std::ostream& out, const LinkedList<S>& list);
    void operator=(const LinkedList<T>& list);

    void push_back(T item);
    void push_front(T item);

    void remove(T item);
    void pop_front();
    void pop_back();
    T& front() const;
    T& back();
    unsigned size() const;
    bool empty() const;


};

#include "LinkedList.cpp"
#endif //LINKEDLIST_LINKEDLIST_H


#endif //LINKEDLIST_LINKEDLIST_H
