#ifndef PAMSI_1_PRIORITY_QUEUE_H
#define PAMSI_1_PRIORITY_QUEUE_H

template<typename Comparable>
class BinaryHeap {
public:
    explicit BinaryHeap(int capacity = 100);

    explicit BinaryHeap(const std::vector<Comparable> &items);

    bool isEmpty() const;

    const Comparable &findMin() const;

    void insert(const Comparable &x);

    void insert(Comparable &&x);

    void deleteMin();

    void deleteMin(Comparable &minItem);

    void makeEmpty();

private:
    int currentSize; // Number of elements in heap
    std::vector<Comparable> array; // The heap array

    void buildHeap();

    void percolateDown(int hole);
};




#endif //PAMSI_1_PRIORITY_QUEUE_H
