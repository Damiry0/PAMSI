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

    int  Size() const;
    bool Empty() const;
    bool Full() const;

    bool Add(unsigned int key, T value) const;
    bool Remove(unsigned int key) const;
    void Print() const;
private:
    int  left_child(unsigned int i){ return 2*i;}
    int  right_child(unsigned int i){ return 2*i+1;}

};

#endif //PAMSI_1_PRIORITY_QUEUE_H
