#include "bag.h"
#include "E:\dev\fall21\csci_240\node.h"
#include <stdexcept>

#ifndef LINKED_BAG_H
#define LINKED_BAG_H

template <typename T>
class LinkedBag : public Bag<T>
{
public:
    LinkedBag() : head{nullptr} {}
    bool add(T item)
    {
        head = new Node<T>(item, head);
        ++this->count;

        return true;
    }

    bool remove(T item)
    {
        Node<T>* it{findNode(item)};
        Node<T>* temp{head};
        if(it != nullptr)
        {
            it->item = head->item;
            head = head->children;

            delete temp;
            --this->count;
            
            return true;
        }

        return false;
    }

    bool contains(T item)
    {
        Node<T> *temp{head};
        while (temp != nullptr)
        {
            if (temp->item == item)
                return true;
            temp = temp->children;
        }
        return false;
    }

    size_t size() { return this->count; }

    T grab()
    {
        if (this->count == 0) throw std::runtime_error("Grab on empty bag!");

        return head->item;
    }

private:
    Node<T> *head;

    Node<T>* findNode(T item) 
    {
        Node<T>* it{head};
        while(it != nullptr)
        {
            if(it->item == item) return it;
            it = it->children;
        }

        return nullptr;
    }
};

#endif