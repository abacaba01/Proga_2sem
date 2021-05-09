#ifndef SORTING_MERGE_SORT_H
#define SORTING_MERGE_SORT_H

#include <vector>

#include <iostream>


template <class TIter, class TCmp>
void Merge(TIter left_begin, TIter left_end, TIter right_begin, TIter right_end, TIter res_begin, TCmp cmp){

    TIter start = left_begin;
    TIter start_mas = res_begin;

    while ((left_begin != left_end) && (right_begin != right_end)){
        if(cmp(*left_begin, *right_begin)){
            *res_begin = *left_begin;
            left_begin++;
            res_begin++;
        }
        else{
            *res_begin = *right_begin;
            right_begin++;
            res_begin++;
        }
    }
    if(left_begin == left_end){
        while(right_begin!=right_end){
            *res_begin = *right_begin;
            res_begin++;
            right_begin++;
        }
    }

    if(right_begin == right_end){
        while(left_begin!=left_end){
            *res_begin = *left_begin;
            left_begin++;
            res_begin++;
        }
    }

    while(start != right_end){
        *start = *start_mas;
        start++;
        start_mas++;
    }
}

template <class TIter, class TCmp>
void MSort(TIter res_begin, TIter left, TIter right, TCmp cmp){
    if (std::distance(left, right)<=1) {
        return;
    }
    TIter middle = left + std::distance(left, right)/2;
    MSort(res_begin, left, middle, cmp);
    MSort(res_begin + std::distance(left, middle), middle, right, cmp);
    Merge(left, middle, middle, right, res_begin, cmp);
}

template <class TIter, class TCmp=std::less<typename std::iterator_traits<TIter>::value_type>>
void MergeSort(TIter left, TIter right, TCmp cmp={}){
    std::vector<typename std::iterator_traits<TIter>::value_type> res(std::distance(left, right));
    MSort(res.begin(), left, right, cmp);
}

#endif //SORTING_MERGE_SORT_H