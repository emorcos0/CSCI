#include<vector>

#ifndef SKIPLIST_NODE
#define SKIPLIST_NODE

template<typename T>
struct SkiplistNode
{
    T item;
    SkiplistNode<T> *next;
    SkiplistNode<T> *below;
    std::vector<SkiplistNode<T>*> levels;
    Skiplist(T item, int s)
    {
        
    }
};

#endif /* SKIPLIST_NODE */
