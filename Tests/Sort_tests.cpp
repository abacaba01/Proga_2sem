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

void Test(int N){
    std::vector<uint32_t> V, V1, V2, V3, V4, V5, V0;
    RandomMas(V, N);
    V1 = V;
    V2 = V;
    V3 = V;
    V4 = V;
    V5 = V;
    V0 = V;
    QuickSortFixed(V1.begin(), V1.end());
    QuickSortRandom(V2.begin(), V2.end());
    QuickSortMedian(V3.begin(), V3.end());
    MergeSort(V4.begin(), V4.end());
    HeapSort(V5.begin(), V5.end());
    std::sort(V.begin(), V.end());
    std::sort(V0.rbegin(), V0.rend(), std::greater<int>());
    REQUIRE(V == V1);
    REQUIRE(V == V2);
    REQUIRE(V == V3);
    REQUIRE(V == V4);
    REQUIRE(V == V5);
    REQUIRE(V0 == V1);
    REQUIRE(V0 == V2);
    REQUIRE(V0 == V3);
    REQUIRE(V0 == V4);
    REQUIRE(V0 == V5);
}

TEST_CASE("check all sorts using std::sort") {
    // создается общий массив из n эл, который сортируется каждой сортировкой а потом сравнивается
    // со станлартной сортировкой этого массива
    Test(100);
    Test(1000);
    Test(10000);
    Test(100000);
    Test(1000000);
}
