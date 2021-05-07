#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "Quicksort.h"
#include "catch.hpp"

TEST_CASE("Benchmark for Merge_sort with sorted mas") {
    BENCHMARK("Sort 100")
                {
                    int b=100;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b; i++) {
                        a.push_back(i);
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
    BENCHMARK("Sort 1000")
                {
                    int b=1000;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b; i++) {
                        a.push_back(i);
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
    BENCHMARK("Sort 2500")
                {
                    int b=2500;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b; i++) {
                        a.push_back(i);
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
    BENCHMARK("Sort 5000")
                {
                    int b=5000;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b; i++) {
                        a.push_back(i);
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
    BENCHMARK("Sort 7500")
                {
                    int b=7500;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b; i++) {
                        a.push_back(i);
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
    BENCHMARK("Sort 10000")
                {
                    int b=10000;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b; i++) {
                        a.push_back(i);
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
}
TEST_CASE("Benchmark for Merge_sort with random mas") {
    BENCHMARK("Sort 100")
                {
                    int b=100;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b; i++) {
                        a.push_back(rand());
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
    BENCHMARK("Sort 1000")
                {
                    int b=1000;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b; i++) {
                        a.push_back(rand());
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
    BENCHMARK("Sort 2500")
                {
                    int b=2500;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b; i++) {
                        a.push_back(rand());
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
    BENCHMARK("Sort 5000")
                {
                    int b=5000;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b; i++) {
                        a.push_back(rand());
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
    BENCHMARK("Sort 7500")
                {
                    int b=7500;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b; i++) {
                        a.push_back(rand());
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
    BENCHMARK("Sort 10000")
                {
                    int b=10000;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b; i++) {
                        a.push_back(rand());
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
}
TEST_CASE("Benchmark for Merge_sort with quite sorted mas") {
    BENCHMARK("Sort 100")
                {
                    int b = 100;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b/20; i++) {
                        a.push_back(20) ;
                    }
                    for (int i = b/20; i < b; i++) {
                        a.push_back(i);
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
    BENCHMARK("Sort 1000")
                {
                    int b = 1000;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b/20; i++) {
                        a.push_back(20) ;
                    }
                    for (int i = b/20; i < b; i++) {
                        a.push_back(i);
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
    BENCHMARK("Sort 2500")
                {
                    int b = 2500;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b/20; i++) {
                        a.push_back(20) ;
                    }
                    for (int i = b/20; i < b; i++) {
                        a.push_back(i);
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
    BENCHMARK("Sort 5000")
                {
                    int b = 5000;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b/20; i++) {
                        a.push_back(20) ;
                    }
                    for (int i = b/20; i < b; i++) {
                        a.push_back(i);
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
    BENCHMARK("Sort 7500")
                {
                    int b = 7500;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b/20; i++) {
                        a.push_back(20) ;
                    }
                    for (int i = b/20; i < b; i++) {
                        a.push_back(i);
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
    BENCHMARK("Sort 10000")
                {
                    int b = 10000;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b/20; i++) {
                        a.push_back(20) ;
                    }
                    for (int i = b/20; i < b; i++) {
                        a.push_back(i);
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
}
TEST_CASE("Benchmark for Merge_sort with mas with same el") {
    BENCHMARK("Sort 100")
                {
                    int b = 100;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b/20; i++) {
                        a.push_back(i) ;
                    }
                    for (int i = b/20; i < b; i++) {
                        a.push_back(20);
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
    BENCHMARK("Sort 1000")
                {
                    int b = 1000;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b/20; i++) {
                        a.push_back(i) ;
                    }
                    for (int i = b/20; i < b; i++) {
                        a.push_back(20);
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
    BENCHMARK("Sort 2500")
                {
                    int b = 2500;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b/20; i++) {
                        a.push_back(i) ;
                    }
                    for (int i = b/20; i < b; i++) {
                        a.push_back(20);
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
    BENCHMARK("Sort 5000")
                {
                    int b = 5000;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b/20; i++) {
                        a.push_back(i) ;
                    }
                    for (int i = b/20; i < b; i++) {
                        a.push_back(20);
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
    BENCHMARK("Sort 7500")
                {
                    int b = 7500;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b/20; i++) {
                        a.push_back(i) ;
                    }
                    for (int i = b/20; i < b; i++) {
                        a.push_back(20);
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
    BENCHMARK("Sort 10000")
                {
                    int b = 10000;
                    std::vector<uint32_t> a;
                    for (int i = 0; i < b/20; i++) {
                        a.push_back(i) ;
                    }
                    for (int i = b/20; i < b; i++) {
                        a.push_back(20);
                    }
                    QuickSortRandom(a.begin(), a.end());
                };
}