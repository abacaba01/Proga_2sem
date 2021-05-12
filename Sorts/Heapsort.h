#ifndef HEAPSORT_H_HEAPSORT_H
#define HEAPSORT_H_HEAPSORT_H

#include <iostream>

template<class TIter,class TCmp>
void CheckLargest(TCmp cmp, size_t i, TIter begin, TIter end)
{
    size_t n = std::distance(begin, end);
	if (i * 2 + 1 >= n){
	    return;
	}
	TIter largest = i + begin;
    TIter start = largest;
    TIter left = 2 * i + 1 + begin;
    TIter right = 2 * i + 2 + begin;

    if (left < (n + begin) && cmp(*largest, *left))
        largest = left;

    if (right < (n + begin) && cmp(*largest, *right))
        largest = right;

    if (largest != start)
    {
        std::swap(*start, *largest);
        CheckLargest(cmp, largest - begin, begin, end);
    }
}

template<class TIter,class TCmp = std::less<typename std::iterator_traits<TIter>::value_type>>
void HeapSort(TIter begin, TIter end, TCmp cmp = {})
{
    size_t n = std::distance(begin, end);
    for (int i = n / 2 - 1; i >= 0; i--) {
        CheckLargest(cmp, i, begin, end);
    }
    TIter noone = end;
    for (int i=n-1; i>0; i--){
		--noone;
        std::swap(*begin, *noone);
        CheckLargest(cmp, 0, begin, begin + i);
    }
}

#endif //HEAPSORT_H_HEAPSORT_H

