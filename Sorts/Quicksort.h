
#ifndef QUICKSORT_CPP_QUICKSORT_H
#define QUICKSORT_CPP_QUICKSORT_H
#include <iostream>
#include <random>
#include <iterator>
#include <ctime>
#include <stdlib.h>
#include <time.h>


uint64_t GetRandom(uint32_t n) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, n);
    return dist(gen);
}

template <class TIter, class TCmp=std::less<typename std::iterator_traits<TIter>::value_type>>
TIter Fixed(TIter begin, TIter end, TCmp cmp={}){
    return begin + std::distance(begin, end)/2;
}

template <class TIter, class TCmp=std::less<typename std::iterator_traits<TIter>::value_type>>
TIter Random(TIter begin, TIter end, TCmp cmp={}){
    return begin + GetRandom(std::distance(begin, end)-1);
}
template <class TIter, class TCmp=std::less<typename std::iterator_traits<TIter>::value_type>>
TIter Median(TIter begin, TIter end, TCmp cmp={}){
    size_t size = std::distance(begin, end);
    TIter a = begin + GetRandom(size-1);
    TIter b = begin + GetRandom(size-1);
    TIter c = begin + GetRandom(size-1);
    if (!cmp(*a, *b) && !cmp(*c, *a)) return a;
    if (!cmp(*b, *a) && !cmp(*c, *b)) return b;
    return c;
}




template <class TIter, class TCmp=std::less<typename std::iterator_traits<TIter>::value_type>>
void QuickSort(TIter begin, TIter end, TCmp cmp= {},TIter (*element)(TIter begin, TIter end, TCmp cmp) = Fixed){
    if (std::distance(begin, end)<=1) {
        return;}
    typename std::iterator_traits<TIter>::value_type pivot = *element(begin, end, cmp);
    TIter left = begin;
    TIter right= end-1;
    do {
        while(cmp(*left, pivot)) {
            left++;
        }
        while(cmp(pivot, *right)) {
            right--;
        }
        if (left <= right ) {
            std::swap(*left, *right);
            left++;
            if (std::distance(begin, right) > 0) {
                right--;
            }
        }
    } while (left <= right);
    QuickSort(begin, right + 1, cmp, element);
    QuickSort(left, end, cmp, element);
}

template <class TIter, class TCmp=std::less<typename std::iterator_traits<TIter>::value_type>>
void QuickSortFixed(TIter begin, TIter end, TCmp cmp= {}){
    QuickSort(begin, end, cmp, Fixed);
}

template <class TIter, class TCmp=std::less<typename std::iterator_traits<TIter>::value_type>>
void QuickSortRandom(TIter begin, TIter end, TCmp cmp= {}){
    QuickSort(begin, end, cmp, Random);
}

template <class TIter, class TCmp=std::less<typename std::iterator_traits<TIter>::value_type>>
void QuickSortMedian(TIter begin, TIter end, TCmp cmp= {}){
    QuickSort(begin, end, cmp, Median);
}

#endif //QUICKSORT_CPP_QUICKSORT_H