#include <iostream>
using namespace std;
template<typename T>
void Heap(T *arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        Heap(arr, n, largest);
    }
}

template<typename T>
void HeapSort_1(T *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Heap(arr, n, i);
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        Heap(arr, i, 0);
    }
}

template<typename T>
void HeapSort(T *arr, int first, int last)
{
    int size;
    size = last  - first + 1;
    T* mas = new T[size];
    for (int i = 0; i < size; i++) {
        mas[i] = arr[i + first];
    }
    HeapSort_1(mas, size);
    for (int i=0; i<size; i++)
    {
        arr[i+first]=mas[i];
    }
    delete[] mas;
}

