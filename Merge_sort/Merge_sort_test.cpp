#include "catch.hpp"
#include <iostream>
#include "Merge_sort.cpp"
#define CATCH_CONFIG_MAIN
using namespace std;




TEST_CASE() {
    int mas[5];
    mas[1] = 3;
    mas[2] = 1;
    mas[3] = 5;
    mas[4] = 4;
    mas[0] = 2;

    Merge_sort(mas, 1 ,5);
    REQUIRE(mas[0]==1);
    REQUIRE(mas[1]==2);
    REQUIRE(mas[2]==3);
    REQUIRE(mas[3]==4);
    REQUIRE(mas[4]==5);
}

TEST_CASE() {
    int mas[7];
    mas[1] = 3;
    mas[2] = 1;
    mas[3] = 5;
    mas[4] = 4;
    mas[5] = 2;
    mas[6]= 7;
    mas[0]=6;

    Merge_sort(mas, 2 ,5);
    REQUIRE(mas[0]==6);
    REQUIRE(mas[1]==1);
    REQUIRE(mas[2]==2);
    REQUIRE(mas[3]==3);
    REQUIRE(mas[4]==4);
    REQUIRE(mas[5]==5);
    REQUIRE(mas[6]==7);
}

TEST_CASE() {
    int mas[10];
    for (int i = 0; i < 10; i++){
        mas[i]=rand();
    }
    Merge_sort(mas, 1 ,10);
    for (int i = 0; i < 9; i++){
        REQUIRE(mas[i+1] >= mas[i]);
    }
}
