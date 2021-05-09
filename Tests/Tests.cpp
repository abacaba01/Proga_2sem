#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../Sorts/Quicksort.h"
#include "../Sorts/MERGESORT.h"
#include "../Sorts/Heapsort.h"
#include <vector>



TEST_CASE() {
    std::vector<uint32_t> mas{3, 1, 5, 4, 2};
    QuickSortFixed(mas.begin(), mas.end());
    for (int i = 0; i < 5; i++){
        REQUIRE(mas[i] == i + 1);
    }
}

TEST_CASE() {
    std::vector<uint32_t> mas{0, 5, 3, 4, 1, 2, 6};
    QuickSortFixed(mas.begin(), mas.end());
    for (int i = 0; i < 7; i++){
        REQUIRE(mas[i] == i);
    }
}

TEST_CASE() {
    std::vector<uint32_t> mas;;
    for (int i = 0; i < 10; i++){
        mas.push_back(rand());
    }
    QuickSortFixed(mas.begin(), mas.end());
    for (int i = 0; i < 9; i++){
        REQUIRE(mas[i+1] >= mas[i]);
    }
}


TEST_CASE() {
    std::vector<uint32_t> mas{3, 1, 5, 4, 2};
    QuickSortRandom(mas.begin(), mas.end());
    for (int i = 0; i < 5; i++){
        REQUIRE(mas[i] == i + 1);
    }
}

TEST_CASE() {
    std::vector<uint32_t> mas{0, 5, 3, 4, 1, 2, 6};
    QuickSortRandom(mas.begin(), mas.end());
    for (int i = 0; i < 7; i++){
        REQUIRE(mas[i] == i);
    }
}

TEST_CASE() {
    std::vector<uint32_t> mas;;
    for (int i = 0; i < 10; i++){
        mas.push_back(rand());
    }
    QuickSortRandom(mas.begin(), mas.end());
    for (int i = 0; i < 9; i++){
        REQUIRE(mas[i+1] >= mas[i]);
    }
}

TEST_CASE() {
    std::vector<uint32_t> mas{3, 1, 5, 4, 2};
    QuickSortMedian(mas.begin(), mas.end());
    for (int i = 0; i < 5; i++){
        REQUIRE(mas[i] == i + 1);
    }
}

TEST_CASE() {
    std::vector<uint32_t> mas{0, 5, 3, 4, 1, 2, 6};
    QuickSortMedian(mas.begin(), mas.end());
    for (int i = 0; i < 7; i++){
        REQUIRE(mas[i] == i);
    }
}

TEST_CASE() {
    std::vector<uint32_t> mas;;
    for (int i = 0; i < 10; i++){
        mas.push_back(rand());
    }
    QuickSortMedian(mas.begin(), mas.end());
    for (int i = 0; i < 9; i++){
        REQUIRE(mas[i+1] >= mas[i]);
    }
}
TEST_CASE() {
    std::vector<uint32_t> mas{3, 1, 5, 4, 2};
    MergeSort(mas.begin(), mas.end());
    for (int i = 0; i < 5; i++){
        REQUIRE(mas[i] == i + 1);
    }
}

TEST_CASE() {
    std::vector<uint32_t> mas{0, 5, 3, 4, 1, 2, 6};
    MergeSort(mas.begin(), mas.end());
    for (int i = 0; i < 7; i++){
        REQUIRE(mas[i] == i);
    }
}

TEST_CASE() {
    std::vector<uint32_t> mas;;
    for (int i = 0; i < 10; i++){
        mas.push_back(rand());
    }
    MergeSort(mas.begin(), mas.end());
    for (int i = 0; i < 9; i++){
        REQUIRE(mas[i+1] >= mas[i]);
    }
}

TEST_CASE() {
    std::vector<uint32_t> mas{3, 1, 5, 4, 2};
    HeapSort(mas.begin(), mas.end());
    for (int i = 0; i < 5; i++){
        REQUIRE(mas[i] == i + 1);
    }
}

TEST_CASE() {
    std::vector<uint32_t> mas{0, 5, 3, 4, 1, 2, 6};
    HeapSort(mas.begin(), mas.end());
    for (int i = 0; i < 7; i++){
        REQUIRE(mas[i] == i);
    }
}

TEST_CASE() {
    std::vector<uint32_t> mas;;
    for (int i = 0; i < 10; i++){
        mas.push_back(rand());
    }
    HeapSort(mas.begin(), mas.end());
    for (int i = 0; i < 9; i++){
        REQUIRE(mas[i+1] >= mas[i]);
    }
}