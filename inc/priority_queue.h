#ifndef PAMSI_1_PRIORITY_QUEUE_H
#define PAMSI_1_PRIORITY_QUEUE_H

template<typename T>
class PriorityQueue {
private:
    T *_Head;
    T *_Tail;
    unsigned int _Size;
    unsigned int _CurrentSize;

public:
    PriorityQueue();
    ~PriorityQueue();
    bool Empty() const;
    void Insert(T) const;
    bool Enqueue() const;
    bool Dequeue() const;




private:

};




#endif //PAMSI_1_PRIORITY_QUEUE_H
