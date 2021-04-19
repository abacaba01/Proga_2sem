#include <iostream>
using namespace std;

template<typename T>
void Merge(T* A, int first, int last)
{
    int size, i, j, mid, ind = 0;
    mid = (first + last) / 2;
    j = mid + 1;
    size = last - first + 1;
    T* mas = new T[size];
    for (i = first; i <= mid; i++) {
        while (j <= last and A[j] < A[i]) {
            mas[ind] = A[j];
            ind++;
            j++;
        }
        mas[ind] = A[i];
        ind++;
    }
    while (j <= last) {
        mas[ind] = A[j];
        ind++;
        j++;
    }
    for (i = 0; i < size; i++) {
        A[i + first] = mas[i];
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

