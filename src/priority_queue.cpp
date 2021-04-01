
#include <iostream>
#include "../inc/priority_queue.h"

template<typename T>
PriorityQueue<T>::PriorityQueue() {
    _Head=_Tail=NULL;
}

template<typename T>
PriorityQueue<T>::~PriorityQueue() {
    while (_Head) Dequeue();
}

template<typename T>
bool PriorityQueue<T>::Empty() const {
    return false;
}

template<typename T>
void PriorityQueue<T>::Insert(T) const {

}

template<typename T>
bool PriorityQueue<T>::Enqueue() const {
    return false;
}

template<typename T>
bool PriorityQueue<T>::Dequeue() const {
    return false;
}






