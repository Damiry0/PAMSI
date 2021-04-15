#include <iostream>
#include "../inc/priority_queue.h"

template<typename T>
PriorityQueue<T>::PriorityQueue(unsigned int size) {
    _heap=NULL;
    _currentSize=0;
    _size=size;
}

template<typename T>
PriorityQueue<T>::~PriorityQueue() {
    while (_heap) Dequeue();
}

template<typename T>
bool PriorityQueue<T>::Empty() const {
    return _size==0 ? 1:0;
}

template<typename T>
int PriorityQueue<T>::Size() const {
    return _currentSize;
}

template<typename T>
bool PriorityQueue<T>::Full() const {
    return _currentSize==_size ? 1:0;
}


template<typename T>
bool PriorityQueue<T>::Enqueue() const {
    return false;
}

template<typename T>
bool PriorityQueue<T>::Dequeue() const {
    return false;
}

template<typename T>
void PriorityQueue<T>::Insert(unsigned int k, T x) const {

}







