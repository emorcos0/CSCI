#include <functional>
#include "set.h"

#ifndef KEYVALUE_PAIR_H
#define KEYVALUE_PAIR_H

enum State
{
    Occupied,
    Empty,
    Available
};

template <typename K, typename T>
struct KVPair
{
    KVPair() = default;

    KVPair(K key, T value) : key{key}, value{value} { state = Occupied; }

    KVPair(K key, T value, State state) : key{key}, value{value}, state{state} {}

    K key;
    T value;
    State state;

    void setState(State state) { this->state = state; }
    State getState() { return state; }

    T getVal() { return value; }

    bool operator<(const KVPair<K, T> &other) { return value < other.value; }
    bool operator>(const KVPair<K, T> &other) { return value > other.value; }
    bool operator>=(const KVPair<K, T> &other) { return !(*this < other); }
    bool operator<=(const KVPair<K, T> &other) { return !(*this > other); }

    bool operator==(const KVPair<K, T> &other) { return value == other.value; }
    bool operator!=(const KVPair<K, T> &other) { return *(this == other); }
};

#endif

/*-----------------------------------------------------------------------------------------------------------*/

#ifndef HASHSET_QP_H
#define HASHSET_QP_H

#define DEFAULT_SIZE 157
#define SCALING_FACTOR 2

template <typename T>
class HashSetQP : public Set<T>
{
public:
    HashSetQP(std::function<int(T)> h1) : h1{h1}, currentSize{DEFAULT_SIZE}, itmQt{0}
    {
        set = new KVPair<size_t, T>[DEFAULT_SIZE];
        for (size_t i{0}; i < currentSize; ++i)
            set[i].setState(Empty);
    }

    /** Inserts an item into the set. Returns true if successful or false otherwise.
     *  Param item: the item to be inserted
     *  return: true if successful or false otherwise. */
    bool insert(const T &item)
    {
        double occupancy;
        size_t k{compress(h1(item))};
        KVPair<size_t, T> pair{k, item, Occupied};

        if (set[k] == pair)
            return false;

        if (set[k].getState() == Occupied)
            k = probingAdd(k);

        if (k == -1)
            return false;
        else
        {
            set[k] = pair;
            set[k].setState(Occupied);
            ++itmQt;
            occupancy = (static_cast<double>(itmQt) / static_cast<double>(currentSize));
            if (occupancy >= .6)
                resize();
            return true;
        }
    }

    /** Removes an item from the Set.
     * Param item: the item to removed
     * return: true if an item was removed and false otherwise */
    bool erase(const T &item)
    {
        size_t k{compress(h1(item))};
        KVPair<size_t, T> temp{k, item, Occupied};
        if (set[k] == temp)
        {
            KVPair<size_t, T> tempp{k, 100000, Available};
            set[k] = tempp;
            --itmQt;
            /*There is something wrong with my setState function as well as my states, so I just input a large value into the map
            to overwrite the erased value.*/
            // set[k].setState(Available);
            return true;
        }
        else
        {
            k = probingFind(k, item);
            if (k == -1)
                return false;
            else
            {
                KVPair<size_t, T> tempp{k, 100000, Available};
                set[k] = tempp;
                /*There is something wrong with my setState function as well as my states, so I just input a large value into the map
                to overwrite the erased value.*/
                // set[k].setState(Available);
                --itmQt;
                return true;
            }
        }
    }

    /** retrieves a an item
     *  Param item: the item to retrieved
     *  return: a constant pointer to an item if it exists and nullptr otherwise */
    const T *find(const T &item)
    {
        size_t k{compress(h1(item))};
        KVPair<size_t, T> temp{k, item, Occupied};
        const T i = (set[k].getVal());
        const T *ia = &i;

        if (set[k] == temp)
            return ia;
        else
        {
            k = probingFind(k, item);
            if (k == -1)
                return nullptr;
            else
            {
                const T i = (set[k].getVal());
                ia = &i;
                return ia;
            }
        }
    }

    /** Checks for membership
     * Param item: the item to searched for
     * return: true of the item is a member of the set and false otherwise. */
    bool contains(const T &item)
    {
        size_t k{compress(h1(item))};
        KVPair<size_t, T> temp{k, item, Occupied};
        if (set[k] == temp)
            return true;
        else
        {
            k = probingFind(k, item);
            if (k == -1)
                return false;
            else
                return true;
        }
    }

private:
    std::function<int(T)> h1;
    size_t currentSize;
    size_t itmQt;
    KVPair<size_t, T> *set;

    size_t compress(int k)
    {
        return (k & 0x7FFFFFFF) % currentSize;
    }

    int probingAdd(size_t k)
    {
        size_t counter{27};
        for (size_t i{0}; i < currentSize; ++i)
        {
            k = (compress(k) + (i * i)) % currentSize;
            if (set[k].getState() == Empty || Available)
                return k;
            --counter;
            if (counter == 0)
                break;
        }
        return -1;
    }

    int probingFind(size_t k, const T &item)
    {
        size_t counter{27};
        KVPair<size_t, T> temp{k, item};

        for (size_t i{0}; i < currentSize; ++i)
        {
            k = (compress(k) + (i * i)) % currentSize;
            if (set[k] == temp)
                return k;
            --counter;
            if (counter == 0)
                break;
        }
        return -1;
    }

    void resize()
    {
        size_t newSize = currentSize * SCALING_FACTOR;
        KVPair<size_t, T> *newSet{new KVPair<size_t, T>[newSize]};

        for (size_t i = 0; i < newSize; ++i)
        {
            newSet[i].setState(Empty);
        }

        for (size_t i = 0; i < currentSize; ++i)
        {
            newSet[i] = set[i];
        }

        delete[] set;
        set = newSet;

        for (size_t i = 0; i < currentSize; ++i)
            if (set[i].getState() == Occupied)
            {
                set[i].setState(Available);
                insert(set[i].getVal());
            }

        currentSize = newSize;
    }
};

#endif