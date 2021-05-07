#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "Queue.h"
#include "../catch.hpp"



TEST_CASE("1") {
    BENCHMARK(" LL Plus 1000, minus 1000") {
                                               Queue<int64_t> a;

                                               for (size_t i = 0; i < 1000; ++i) {
                                                   a.Push(i);
                                               }
                                               for (size_t i = 0; i < 1000; ++i) {
                                                   a.Pop();
                                               }
                                               return a.Size();
                                           };
    BENCHMARK(" LL Plus 10000, minus 10000") {
                                                 Queue<int64_t> a;

                                                 for (size_t i = 0; i < 10000; ++i) {
                                                     a.Push(i);
                                                 }
                                                 for (size_t i = 0; i < 10000; ++i) {
                                                     a.Pop();
                                                 }
                                                 return a.Size();
                                             };
    BENCHMARK(" LL Plus 100 000, minus 100 000") {
                                                     Queue<int64_t> a;

                                                     for (size_t i = 0; i < 100000; ++i) {
                                                         a.Push(i);
                                                     }
                                                     for (size_t i = 0; i < 100000; ++i) {
                                                         a.Pop();
                                                     }
                                                     return a.Size();
                                                 };
    BENCHMARK(" LL Plus 1 000 000, minus 1 000 000") {
                                                         Queue<int64_t> a;

                                                         for (size_t i = 0; i < 1000000; ++i) {
                                                             a.Push(i);
                                                         }
                                                         for (size_t i = 0; i < 1000000; ++i) {
                                                             a.Pop();
                                                         }
                                                         return a.Size();

                                                     };
}