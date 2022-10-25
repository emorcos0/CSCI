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
    LinkedQueue() :  last{nullptr} {}

    bool enqueue(T item)
    {
        Node<T> *temp = new Node<T>{item};
       
        if(last==nullptr) last = temp;
        else
        {
            Node<T>* last = new Node<T>{item,last};
        }

        ++this->count;

        return true;
    }

    T dequeue()
    {
        if (this->count == 0)
            throw std::runtime_error("The queue is empty.");

        Node<T>* first {findFirstNode()};
        
        
        T temp{first->item};
        delete first;

        --this->count;
        return temp;
    }

    T front()
    {
        if (this->count == 0)
            throw std::runtime_error("The queue is empty.");

        Node<T>* first {findFirstNode()};
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

        while (last != nullptr)
        {
            temp = last;
            last = last->children;
            delete temp;
        }

        this->count = 0;
    }

private:
    Node<T> *last;

    Node<T>* findFirstNode()
    {
        Node<T> *it{last};
        while (it->children != nullptr) it = it->children;
        return it;
    }
};

#endif