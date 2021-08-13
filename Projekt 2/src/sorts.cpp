#pragma once
#ifndef SORT_HPP
#define SORT_HPP


#include <iostream>
#include <algorithm>



template<typename T>
void merge(T* array, int start_index, int middle_index, int end_index)
{
    T left_array_size, right_array_size;

    left_array_size = middle_index - start_index + 1;
    right_array_size = end_index - middle_index;

    T* left_array = new T[left_array_size];
    T* right_array = new T[right_array_size];
    for (int i = 0; i < left_array_size; i++)
    {
        left_array[i] = array[start_index + i];
    }

    for (int j = 0; j < right_array_size; j++)
    {
        right_array[j] = array[middle_index + 1 + j];
    }
	
    int i = 0, j = 0, k = start_index;
    while (i < left_array_size && j < right_array_size)
    {

        if (left_array[i] <= right_array[j])
        {
            array[k] = left_array[i];
            i++;
        }
        else {
            array[k] = right_array[j];
            j++;
        }
        k++;

    }
    while (i < left_array_size)
    {
        array[k] = left_array[i];
        i++;
        k++;
    }
    while (j < right_array_size)
    {
        array[k] = right_array[j];
        j++;
        k++;
    }

    delete[] left_array;
    delete[] right_array;
}

template<typename T>
void mergeSort(T* array, int start_index, int end_index)
{
    if (start_index < end_index)                  
    {
        long int middle_index = start_index + (end_index - start_index) / 2; //obliczanie srodkowego indeksu
        mergeSort(array, start_index, middle_index);         //Merge sort dla lewej strony tablicy
        mergeSort(array, middle_index + 1, end_index);          //Merge sort dla prawej strony tablicy
        merge(array, start_index, middle_index, end_index);    //Polaczenie posortowanych tablic w jedną
    }
}

template<typename T>
void quickSort(T* array, int start_index, int end_index)
{

    int i = start_index; int j = end_index;
    int pivot = array[(start_index + end_index) / 2];    //pivot to srodkowy indekst

    do
    {
        while (array[i] < pivot) 
            i++;

        while (array[j] > pivot) 
            j--;

        if (i <= j)    
        {
            std::swap(array[i], array[j]);
            i++; j--;
        }

    } while (i <= j);

    if (start_index < j)
        quickSort(array, start_index, j);  

    if (end_index > i)
        quickSort(array, i, end_index);    

}

template<typename T>
void insertionSort(T array[], int* begin, int* end)
{
    int left_index = begin - array;
    int right_index = end - array;

    for (int i = left_index + 1; i <= right_index; i++)
    {
        int key = array[i];
        int j = i - 1;

        while (j >= left_index && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }

}

template<typename T>
T* Partition(T array[], int first, int last)
{
    T pivot = array[last];
    int i = (first - 1);  

    for (int j = first; j <= last - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i + 1], array[last]);
    return (array + i + 1);
}



template<typename T>
T* MedianOfThree(T* a, T* b, T* c)
{
    if (*a < *b && *b < *c)
        return b;
    if (*c <= *b && *b <= *a)
        return b;
    if (*a < *c && *c <= *b)
        return c;
    if (*b < *c && *c <= *a)
        return c;
    if (*c <= *a && *a < *b)
        return a;
    if (*b <= *a && *a < *c)
        return a;
}

template<typename T>
void IntroSortWithDepth(T array[], int* begin,
    int* end, int depthLimit)
{ 
    int size = end - begin;
    if (size < 16)
        insertionSort(array, begin, end);

    // Uzywanie heapSotrtu gdy głębkość rekurencji ==0
    if (depthLimit == 0)
    {
        std::make_heap(begin, end + 1);
        std::sort_heap(begin, end + 1);
    }
    int* pivot = MedianOfThree(begin, begin + size / 2, end);
    std::swap(pivot, end);
    int* partitionPoint = Partition(array, begin - array, end - array);
    IntroSortWithDepth(array, begin, partitionPoint - 1, depthLimit - 1);
    IntroSortWithDepth(array, partitionPoint + 1, end, depthLimit - 1);
}

template<typename T>
void introSort(T array[], int* begin, int* end)
{
    int depthLimit = 2 * log(end - begin);
    IntroSortWithDepth(array, begin, end, depthLimit);
}

#endif // SORT_HPP
#pragma once