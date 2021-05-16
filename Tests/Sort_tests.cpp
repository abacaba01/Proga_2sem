#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-transparent-functors"
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../Sorts/Quicksort.h"
#include "../Sorts/MERGESORT.h"
#include "../Sorts/Heapsort.h"
#include <vector>
#include <algorithm>

void RandomMas(std::vector<uint32_t> &a, int b){
    for (int i = 0; i < b; i++) {
        a.push_back(rand());
    }
}

void turn(std::vector<uint32_t> &a){
    for (int i = 0; i < a.size()/2; i++) {
        std::swap(a[i], a[a.size()-i-1]);
    }
}


void Test(int N){
    std::vector<uint32_t> V, V1, V2, V3, V4, V5, Arr1, Arr2, Arr3, Arr4, Arr5;
    RandomMas(V, N);
    V1 = V;
    V2 = V;
    V3 = V;
    V4 = V;
    V5 = V;
    Arr1 = V;
    Arr2 = V;
    Arr3 = V;
    Arr4 = V;
    Arr5 = V;
    QuickSortFixed(V1.begin(), V1.end());
    QuickSortFixed(Arr1.begin(), Arr1.end(), std::greater<int>());
    QuickSortRandom(V2.begin(), V2.end());
    QuickSortRandom(Arr2.begin(), Arr2.end(), std::greater<int>());
    QuickSortMedian(V3.begin(), V3.end());
    QuickSortMedian(Arr3.begin(), Arr3.end(), std::greater<int>());
    MergeSort(V4.begin(), V4.end());
    MergeSort(Arr4.begin(), Arr4.end(), std::greater<int>());
    HeapSort(V5.begin(), V5.end());
    HeapSort(Arr5.begin(), Arr5.end(), std::greater<int>());
    std::sort(V.begin(), V.end());
    turn(Arr1);
    turn(Arr2);
    turn(Arr3);
    turn(Arr4);
    turn(Arr5);
    REQUIRE(V == V1);
    REQUIRE(V == V2);
    REQUIRE(V == V3);
    REQUIRE(V == V4);
    REQUIRE(V == V5);
    REQUIRE(Arr1 == V1);
    REQUIRE(Arr2 == V2);
    REQUIRE(Arr3 == V3);
    REQUIRE(Arr4 == V4);
    REQUIRE(Arr5 == V5);
}

TEST_CASE("check all sorts using std::sort") {
    // создается общий массив из n эл, который сортируется каждой сортировкой а потом сравнивается
    // со станлартной сортировкой этого массива
    Test(100);
    Test(1000);
    Test(10000);
    Test(100000);
}
