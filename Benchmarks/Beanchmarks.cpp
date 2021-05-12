#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "../catch.hpp"
#include "../Sorts/Quicksort.h"
#include "../Sorts/MERGESORT.h"
#include "../Sorts/Heapsort.h"

void SortedMas(std::vector<uint32_t> a, int b){
    for (int i = 0; i < b; i++) {
        a.push_back(i);
    }
}


void RandomMas(std::vector<uint32_t> a, int b){
    for (int i = 0; i < b; i++) {
        a.push_back(rand());
    }
}

void QuiteSortedMas(std::vector<uint32_t> a, int b){
    for (int i = 0; i < b; i++) {
        for (int i = 0; i < b/20; i++) {
            a.push_back(20) ;
        }
        for (int i = b/20; i < b; i++) {
            a.push_back(i);
        }
    }
}
void SameElMassive(std::vector<uint32_t> a, int b) {
    for (int i = 0; i < b; i++) {
        for (int i = 0; i < b / 20; i++) {
            a.push_back(20);
        }
        for (int i = b / 20; i < b; i++) {
            a.push_back(i);
        }
    }
}

void Test(int N, void (*f)(std::vector<uint32_t>, int)){
    std::vector<uint32_t> V1, V2, V3, V4, V5;
    f(V1, N);
    f(V2, N);
    f(V3, N);
    f(V4, N);
    f(V5, N);
    BENCHMARK("Heap Sort " + std::to_string(N)) {
                                                    HeapSort(V1.begin(), V1.end());
                                                };

    BENCHMARK("Merge Sort " + std::to_string(N)) {
                                                     MergeSort(V2.begin(), V2.end());
                                                 };

    BENCHMARK("Quick Sort Random" + std::to_string(N)) {
                                                     QuickSortRandom(V3.begin(), V3.end());
                                                 };
    BENCHMARK("Quick Sort Fixed" + std::to_string(N)) {
                                                     QuickSortFixed(V4.begin(), V4.end());
                                                 };
    BENCHMARK("Quick Sort Median" + std::to_string(N)) {
                                                     QuickSortMedian(V5.begin(), V5.end());
                                                 };
}

TEST_CASE("Sorted mas") {
    Test(100, SortedMas);
    Test(1000, SortedMas);
    Test(2000, SortedMas);
    Test(5000, SortedMas);
    Test(10000, SortedMas);
}

TEST_CASE("Random mas") {
    Test(100, RandomMas);
    Test(1000, RandomMas);
    Test(2000, RandomMas);
    Test(5000, RandomMas);
    Test(10000, RandomMas);
}

TEST_CASE("Quite sorted mas") {
    Test(100, QuiteSortedMas);
    Test(1000, QuiteSortedMas);
    Test(2000, QuiteSortedMas);
    Test(5000, QuiteSortedMas);
    Test(10000, QuiteSortedMas);
}

TEST_CASE("Mas with a lot of same elements") {
    Test(100, SameElMassive);
    Test(1000, SameElMassive);
    Test(2000, SameElMassive);
    Test(5000, SameElMassive);
    Test(10000, SameElMassive);
}