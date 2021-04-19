#include <iostream>
using namespace std;

template<typename T>
void Merge(T* A, int first, int last)
{
    int size, left, right, mid, indeficator = 0;
    mid = (first + last) / 2;
    right = mid + 1;
    size = last - first + 1;
    T* mas = new T[size];
    for (left = first; left <= mid; left++) {
        while (right <= last && A[right] < A[left]) {
            mas[indeficator] = A[right];
            indeficator++;
            right++;
        }
        mas[indeficator] = A[left];
        indeficator++;
    }
    while (right <= last) {
        mas[indeficator] = A[right];
        indeficator++;
        right++;
    }
    for (left = 0; left < size; left++) {
        A[left + first] = mas[left];
    }
    delete[]mas;
}

template<typename T>
void Merge_sort(T* A, int first, int last)
{
    {
        if (first < last)
        {
            Merge_sort(A, first, (first + last) / 2);
            Merge_sort(A, (first + last) / 2 + 1, last);
            Merge(A, first, last);
        }
    }
};

