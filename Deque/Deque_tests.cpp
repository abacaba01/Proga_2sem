#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "deque.h"

int32_t M = 100;
TEST_CASE() {
    {
        Deque<int32_t> a;
        for(int32_t i = 0; i < M; i++){
            a.PushBack(i);
        }

        for(int32_t i = 0; i < M; i++){
            REQUIRE(a[i] == i);
        }

        for(int32_t i = 0; i < M; i++){
            a.PopBack();
        }
    };

    {
        Deque<int32_t> a;
        a.PushFront(0);
        for(int32_t i = 1; i <= M; i++){
            a.PushBack(i);
        }

        REQUIRE(a[0] == 0);
        for(int32_t i = 1; i <= M; i++){
            REQUIRE(a[i] == i);
        }

        for(int32_t i = 0; i < M/2; i++){
            a.PopBack();
        }
        for(int32_t i = M/2; i < M + 1; i++){
            a.PopFront();
        }
    }
};

TEST_CASE() {
    {
        Deque<int32_t> a;
        for(int32_t i = 0; i < M; i++){
            a.PushFront(i);
        }

        for(int32_t i = 0; i < M; i++){
            REQUIRE(a[i] == M - 1 - i);
        }

        for(int32_t i = 0; i < M; i++){
            a.PopFront();
        }
    };

    {
        Deque<int32_t> a;
        a.PushBack(0);
        for(int32_t i = 1; i <= M; i++){
            a.PushFront(i);
        }

        for(int32_t i = 0; i <= M; i++){
            REQUIRE(a[i] == M - i);
        }

        for(int32_t i = 0; i < M + 1; i++){
            a.PopBack();
        }
    }
};

TEST_CASE() {
    Deque<int32_t> a;
    for(int32_t i = 0; i < M; i++){
        a.PushBack(i);
    };
    Deque<int32_t> b;
    b=a;
    for (int32_t i = 0; i < M; i++){
        REQUIRE(b[i] == a[i]);
        }
    Deque<int32_t> c;

};


