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

    KVPair(K key, T value) : key{key}, value{value} {state = Occupied;}

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