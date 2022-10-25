#include <stdexcept>

#ifndef STACK_H
#define STACK_H

template<typename T>
class Node
{
public:
    T val;
    Node<T> *next;
    Node(T val, Node<T> *next) : val{val}, next{next} { }
};

template<typename T>
class Stack
{
public:
    Stack() : head{nullptr} { }
    ~Stack () { clear(); } 

    bool isEmpty() {return head == nullptr;}
    void push(T val) { head = new Node<T>(val, head); }
    T peek()
    {
        if(isEmpty()) throw std::runtime_error("The stack is empty!"); 

        return head->val; // can use (*head).val instead 
    }

    T pop()
    {
        if(isEmpty()) throw std::runtime_error("The stack is empty!"); 

         Node<T>* temp{head};
         T val{head->val};

         head = head->next;

         delete temp;

         return val;
    }

    void clear()
    {
        head = clear(head);
        // Node<T>* temp{};

        // while(head != nullptr)
        // {
        //     temp = head;
        //     head = head->next;
        //     delete temp;
        // }
        
    }

private:
    Node<T> *head;

    Node<T>* clear(Node<T>* n)
    {
        if(n == nullptr) return nullptr;

        Node<T>* t {n->next};

        delete n;

        return clear(t);
        
    }
    


};




#endif

