//
// Created by damir on 3/24/2021.
//

#ifndef PAMSI_1_PRIORITY_QUEUE_H
#define PAMSI_1_PRIORITY_QUEUE_H

1 template <typename Comparable>
2 class BinaryHeap
3 {
4 public:
5 explicit BinaryHeap( int capacity = 100 );
6 explicit BinaryHeap( const vector<Comparable> & items );
7
8 bool isEmpty( ) const;
9 const Comparable & findMin( ) const;
10
11 void insert( const Comparable & x );
12 void insert( Comparable && x );
13 void deleteMin( );
14 void deleteMin( Comparable & minItem );
15 void makeEmpty( );
16
17 private:
18 int currentSize; // Number of elements in heap
19 vector<Comparable> array; // The heap array
20
21 void buildHeap( );
22 void percolateDown( int hole );
23 };



#endif //PAMSI_1_PRIORITY_QUEUE_H
