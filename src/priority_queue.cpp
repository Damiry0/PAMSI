#include <iostream>
#include "../inc/priority_queue.h"

template<typename T>
PriorityQueue<T>::PriorityQueue(unsigned int size) {
    _head= _tail=NULL;
    _currentSize=0;
    _size=size;
}

template<typename T>
PriorityQueue<T>::~PriorityQueue() {
    while (_head) Dequeue();
}

template<typename T>
bool PriorityQueue<T>::Empty() const {
    return !_size;
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

template<typename T>
void PriorityQueue<T>::Print() const {
    std::cout<<"Queue:\n";
    for (int i = 0; i < _currentSize; ++i) {
        std::cout<<
    }
}






