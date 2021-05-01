#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "MERGESORT.h"
#include <vector>



TEST_CASE() {
    std::vector<uint32_t> mas;
    mas.push_back(3);
    mas.push_back(1);
    mas.push_back(5);
    mas.push_back(4);
    mas.push_back(2);


    MergeSort(mas.begin(), mas.end());
    REQUIRE(mas[0]==1);
    REQUIRE(mas[1]==2);
    REQUIRE(mas[2]==3);
    REQUIRE(mas[3]==4);
    REQUIRE(mas[4]==5);
}

TEST_CASE() {
    std::vector<uint32_t> mas;
    mas.push_back(3);
    mas.push_back(1);
    mas.push_back(5);
    mas.push_back(2);
    mas.push_back(6);
    mas.push_back(7);
    mas.push_back(4);

    MergeSort(mas.begin(), mas.end());
    REQUIRE(mas[0]==1);
    REQUIRE(mas[1]==2);
    REQUIRE(mas[2]==3);
    REQUIRE(mas[3]==4);
    REQUIRE(mas[4]==5);
    REQUIRE(mas[5]==6);
    REQUIRE(mas[6]==7);
}

TEST_CASE() {
    std::vector<uint32_t> mas;;
    for (int i = 0; i < 10; i++){
        mas.push_back(rand());
    }
    MergeSort(mas.begin() , mas.end());
    for (int i = 0; i < 9; i++){
        REQUIRE(mas[i+1] >= mas[i]);
    }
}

