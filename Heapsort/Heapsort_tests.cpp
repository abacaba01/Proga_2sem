#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "Heapsort.cpp"

using namespace std;




TEST_CASE() {
    int mas[5];
    mas[1] = 3;
    mas[2] = 1;
    mas[3] = 5;
    mas[4] = 4;
    mas[0] = 2;

    Heapsort(mas, 0 ,4);
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

    Heapsort(mas, 1 ,5);
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
    for (int & ma : mas){
        ma=rand();
    }
    Heapsort(mas, 0 ,9);
    for (int i = 3; i < 5; i++){
        REQUIRE(mas[i+1] >= mas[i]);
    }
}

