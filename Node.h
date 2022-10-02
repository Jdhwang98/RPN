//
// Created by Johnathan Hwang on 10/1/22.
//

#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H


template<class T>
struct Node{
    Node<T>* next = nullptr, *prev = nullptr;
    T data;
};


#endif //LINKEDLIST_NODE_H
