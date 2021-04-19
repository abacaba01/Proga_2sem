#include <iostream>
using namespace std;

template<typename T>
void Quicksortlight(T *mas, int size) {
    int left = 0;
    int right = size - 1;
    int mid = mas[size / 2];
    do {
        while(mas[left] < mid) {
            left++;
        }
        while(mas[right] > mid) {
            right--;
        }
        if (left <= right) {
            swap(mas[left], mas[right]);
            left++;
            right--;
        }
    } while (left <= right);
    if(right > 0) {
        Quicksortlight(mas, right+1);
    }
    if (left < size) {
        Quicksortlight(&mas[left], size-left);
    }
}
template<typename T>
void Quicksort(T *arr, int first, int last)
{
    int size;
    size = last  - first + 1;
    T* mas = new T[size];
    for (int i = 0; i < size; i++) {
        mas[i] = arr[i + first];
    }
    Quicksortlight(mas, size);
    for (int i=0; i<size; i++)
    {
        arr[i+first]=mas[i];
    }
    delete[] mas;
}

