#include <stdexcept>
#include "queue.h"


#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node
{
    T item;
    Node<T> *children;

    Node(T item, Node<T> *children) : item{item}, children{children} {}
    Node(T item) : Node<T>(item, nullptr) {}
};

#endif

#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

template <typename T>
class LinkedQueue : public Queue<T>
{
public:
    LinkedQueue() :  first{nullptr} {}

    bool enqueue(T item)
    {
        Node<T> *temp = new Node<T>{item};
       
        if(first==nullptr) first = temp;
        else
        {
            Node<T>* last {findLastNode()};
            last->children = temp;
        }

        ++this->count;

        return true;
    }

    T dequeue()
    {
        if (this->count == 0)
            throw std::runtime_error("The queue is empty.");

        T temp{first->item};
        Node<T> *tempfirst{first};
        first = first->children;
        delete tempfirst;

        --this->count;
        return temp;
    }

    T front()
    {
        if (this->count == 0)
            throw std::runtime_error("The queue is empty.");

        T temp{first->item};
        return temp;
    }

    bool empty()
    {
        if (this->count == 0)
            return true;
        return false;
    }

    void clear()
    {
        Node<T> *temp{};

        while (first != nullptr)
        {
            temp = first;
            first = first->children;
            delete temp;
        }

        this->count = 0;
    }

private:
    Node<T> *first;

    Node<T> *findLastNode()
    {
        Node<T> *it{first};
        while (it->children != nullptr) it = it->children;
        return it;
    }
};

#endif