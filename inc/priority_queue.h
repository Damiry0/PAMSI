#ifndef PAMSI_1_PRIORITY_QUEUE_H
#define PAMSI_1_PRIORITY_QUEUE_H

template<typename T>
class PriorityQueue {
private:
    T *_heap;
    unsigned int _size;
    unsigned int _currentSize;

public:
    PriorityQueue(unsigned int size);
    ~PriorityQueue();

    int Size() const;
    bool Empty() const;
    void Insert(unsigned int k, T x) const;
    bool Enqueue() const;
    bool Full() const;

    bool Dequeue() const;
    




private:

};




#endif //PAMSI_1_PRIORITY_QUEUE_H
