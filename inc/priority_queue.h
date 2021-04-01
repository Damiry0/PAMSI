#ifndef PAMSI_1_PRIORITY_QUEUE_H
#define PAMSI_1_PRIORITY_QUEUE_H

template<typename T>
class PriorityQueue {
private:
    T *_head;
    T *_tail;
    unsigned int _size;
    unsigned int _currentSize;

public:
    PriorityQueue(unsigned int size);
    ~PriorityQueue();
    bool Empty() const;
    void Insert(unsigned int k, T x) const;
    bool Enqueue() const;
    bool Dequeue() const;
    void Print() const;




private:

};




#endif //PAMSI_1_PRIORITY_QUEUE_H
