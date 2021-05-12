
#ifndef QUICKSORT_CPP_QUICKSORT_H
#define QUICKSORT_CPP_QUICKSORT_H
#include <iostream>
#include <random>
#include <iterator>
#include <ctime>
#include <stdlib.h>
#include <time.h>

template <class TIter, class TCmp=std::less<typename std::iterator_traits<TIter>::value_type>>
TIter Fixed(TIter begin, TIter end, TCmp cmp={}){
    return begin + std::distance(begin, end)/2;
}

template <class TIter, class TCmp=std::less<typename std::iterator_traits<TIter>::value_type>>
TIter Random(TIter begin, TIter end, TCmp cmp={}){
    srand(time(NULL));
    size_t size = std::distance(begin, end);
    return begin + rand()%size;
}
template <class TIter, class TCmp=std::less<typename std::iterator_traits<TIter>::value_type>>
TIter Median(TIter begin, TIter end, TCmp cmp={}){
    srand(time(NULL));
    size_t size = std::distance(begin, end);
    TIter a = begin + rand()%size;
    TIter b = begin + rand()%size;
    TIter c = begin + rand()%size;
    if (!cmp(*a, *b) && !cmp(*c, *a)){
        return a;}
    if (!cmp(*b, *a) && !cmp(*c, *b)){
        return b;}
    return c;
}




template <class TIter, class TCmp=std::less<typename std::iterator_traits<TIter>::value_type>>
void QuickSortFixed(TIter begin, TIter end, TCmp cmp= {},TIter (*element)(TIter begin, TIter end, TCmp cmp)= Fixed){
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
    QuickSortFixed(begin, right + 1, cmp, element);
    QuickSortFixed(left, end, cmp, element);
}

template <class TIter, class TCmp=std::less<typename std::iterator_traits<TIter>::value_type>>
void QuickSortRandom(TIter begin, TIter end, TCmp cmp= {},TIter (*element)(TIter begin, TIter end, TCmp cmp)= Random){
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
    QuickSortRandom(begin, right + 1, cmp, element);
    QuickSortRandom(left, end, cmp, element);
}

template <class TIter, class TCmp=std::less<typename std::iterator_traits<TIter>::value_type>>
void QuickSortMedian(TIter begin, TIter end, TCmp cmp= {},TIter (*element)(TIter begin, TIter end, TCmp cmp)= Median){
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
    QuickSortMedian(begin, right + 1, cmp, element);
    QuickSortMedian(left, end, cmp, element);
}
#endif //QUICKSORT_CPP_QUICKSORT_H