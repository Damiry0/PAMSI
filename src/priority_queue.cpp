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
    while (_heap) Remove();
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
bool PriorityQueue<T>::Add(unsigned int key, T value) const {
    if(this->Full) return false;

}

template<typename T>
void PriorityQueue<T>::Print() const {

}







