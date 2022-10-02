//
// Created by Johnathan Hwang on 10/1/22.
//

#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP
#include "LinkedList.h"

template<class T>
Node<T> *LinkedList<T>::createNode(T item)
{
    Node<T>* node = new Node<T>;
    node->next = nullptr;
    node->prev = nullptr;
    node->data = item;
    return node;
}

template<class T>
void LinkedList<T>::addFirstNode(T item)
{
    Node<T>* node = createNode(item);
    head = node;
    tail = node;
}

template<class T>
void LinkedList<T>::insertAfter(T item, Node<T> *node)
{
    assert(node != nullptr && "Node doesn't exist");
    Node<T>* temp = createNode(item);
    if(node == tail){
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    else
    {
        Node<T>* after = node->next;
        temp->next = after;
        temp->prev = node;
        after->prev = temp;
        node->next = temp;
    }
    //createNode(item);

}

template<class T>
void LinkedList<T>::insertBefore(T item, Node<T> *node)
{
//    assert(node != nullptr && "node doesn't exist");
//    assert(node->prev != nullptr && "node previous doesn't exist");
    if(node == head)
    {
        Node<T>* temp = createNode(item);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else
    {
        insertAfter(item, node->prev);
    }
}

template<class T>
Node<T> *LinkedList<T>::search(T item)
{
    Node<T>* walker = head;
    while(walker!= nullptr && walker->data != item)
    {
        walker = walker->next;
    }
    return walker;
}

template<class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList & list)
{
    *this = list;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    while(tail!=nullptr)
        remove(tail);
}

template<class S>
std::ostream &operator<<(std::ostream &out, const LinkedList<S> & list)
{
    Node<S>* walker = list.head;
    while(walker != nullptr){
        out <<walker->data << " ";
        walker = walker->next;
    }
    return out;
}

template<class T>
void LinkedList<T>::operator=(const LinkedList<T> &list)
{
    if(this == &list)
    {
        return;
    }
    else
    {
        Node<T>* w = list.head;
        this->~LinkedList();
        while(w != nullptr)
        {
            push_back(w->data);
            w=w->next;
        }
    }
}

template<class T>
void LinkedList<T>::push_back(T item)
{
    ++_size;
    if(head == nullptr)
    {
        addFirstNode(item);
    }
    else
        insertAfter(item, tail);
}

template<class T>
void LinkedList<T>::push_front(T item)
{
    ++_size;
    if(head == nullptr)
    {
        addFirstNode(item);
    }
    else
        insertBefore(item, head);
}

template<class T>
void LinkedList<T>::remove(Node<T> *node)
{
    if(head != nullptr)
    {
        if(head->next == nullptr && node == head)
        {
            head=nullptr;
            tail=nullptr;
            delete node;
        }
        else if(node == head)
        {
            head = head->next;
            head->prev = nullptr;
            delete node;
        }
        else if(node == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
            delete node;
        }
        else
        {
            Node<T> *before = node->prev;
            Node<T> *after = node->next;
            before->next = after;
            after->prev = before;
            delete node;
        }

    }

}

template<class T>
void LinkedList<T>::remove(T item)
{
    remove(search(item));
}

template<class T>
void LinkedList<T>::pop_front()
{
    --_size;
    remove(head);
}

template<class T>
void LinkedList<T>::pop_back()
{
    --_size;
    remove(tail);
}

template<class T>
T& LinkedList<T>::front() const
{
    return head->data;
}

template<class T>
T &LinkedList<T>::back()
{
    return tail->data;
}


template<class T>
unsigned LinkedList<T>::size() const
{
    return _size;
}

template<class T>
bool LinkedList<T>::empty() const
{
    return (_size == 0);
}

#endif