#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "Heapsort.cpp"
#include "catch.hpp""

TEST_CASE("Benchmark for Heapsort with sorted mas") {
    BENCHMARK("Sort 100")
                {
                    int b=100;
                    int *a =  new int[b] ;
                    for (int i = 0; i < b; i++) {
                        a[i] = i;
                    }
                    Heapsort(a, 0, b - 1);
                };
    BENCHMARK("Sort 1000")
                {
                    int b=1000;
                    int *a =  new int[b] ;
                    for (int i = 0; i < b; i++) {
                        a[i] = i;
                    }
                    Heapsort(a, 0, b - 1);
                };
    BENCHMARK("Sort 2500")
                {
                    int b=2500;
                    int *a =  new int[b] ;
                    for (int i = 0; i < b; i++) {
                        a[i] = i;
                    }
                    Heapsort(a, 0, b - 1);
                };
    BENCHMARK("Sort 5000")
                {
                    int b=5000;
                    int *a =  new int[b] ;
                    for (int i = 0; i < b; i++) {
                        a[i] = i;
                    }
                    Heapsort(a, 0, b - 1);
                };
    BENCHMARK("Sort 7500")
                {
                    int b=7500;
                    int *a =  new int[b] ;
                    for (int i = 0; i < b; i++) {
                        a[i] = i;
                    }
                    Heapsort(a, 0, b - 1);
                };
    BENCHMARK("Sort 10000")
                {
                    int b=10000;
                    int *a =  new int[b] ;
                    for (int i = 0; i < b; i++) {
                        a[i] = i;
                    }
                    Heapsort(a, 0, b - 1);
                };
}
TEST_CASE("Benchmark for Heapsort with random mas") {
    BENCHMARK("Sort 100")
                {
                    int b=100;
                    int *a =  new int[b] ;
                    for (int i = 0; i < b; i++) {
                        a[i] = rand();
                    }
                    Heapsort(a, 0, b - 1);
                };
    BENCHMARK("Sort 1000")
                {
                    int b=1000;
                    int *a =  new int[b] ;
                    for (int i = 0; i < b; i++) {
                        a[i] = rand();
                    }
                    Heapsort(a, 0, b - 1);
                };
    BENCHMARK("Sort 2500")
                {
                    int b=2500;
                    int *a =  new int[b] ;
                    for (int i = 0; i < b; i++) {
                        a[i] = rand();
                    }
                    Heapsort(a, 0, b - 1);
                };
    BENCHMARK("Sort 5000")
                {
                    int b=5000;
                    int *a =  new int[b] ;
                    for (int i = 0; i < b; i++) {
                        a[i] = rand();
                    }
                    Heapsort(a, 0, b - 1);
                };
    BENCHMARK("Sort 7500")
                {
                    int b=7500;
                    int *a =  new int[b] ;
                    for (int i = 0; i < b; i++) {
                        a[i] = rand();
                    }
                    Heapsort(a, 0, b - 1);
                };
    BENCHMARK("Sort 10000")
                {
                    int b=10000;
                    int *a =  new int[b] ;
                    for (int i = 0; i < b; i++) {
                        a[i] = rand();
                    }
                    Heapsort(a, 0, b - 1);
                };
}
TEST_CASE("Benchmark for Heapsort with quite sorted mas") {
    BENCHMARK("Sort 100")
                {
                    int b = 100;
                    int *a = new int[b];
                    for (int i = 0; i < b/20; i++) {
                        a[i] = 20;
                    }
                    for (int i = b/20; i < b; i++) {
                        a[i] = i;
                    }
                    Heapsort(a, 0, b - 1);
                };
    BENCHMARK("Sort 1000")
                {
                    int b = 1000;
                    int *a = new int[b];
                    for (int i = 0; i < b/20; i++) {
                        a[i] = 20;
                    }
                    for (int i = b/20; i < b; i++) {
                        a[i] = i;
                    }
                    Heapsort(a, 0, b - 1);
                };
    BENCHMARK("Sort 2500")
                {
                    int b = 2500;
                    int *a = new int[b];
                    for (int i = 0; i < b/20; i++) {
                        a[i] = 20;
                    }
                    for (int i = b/20; i < b; i++) {
                        a[i] = i;
                    }
                    Heapsort(a, 0, b - 1);
                };
    BENCHMARK("Sort 5000")
                {
                    int b = 5000;
                    int *a = new int[b];
                    for (int i = 0; i < b/20; i++) {
                        a[i] = 20;
                    }
                    for (int i = b/20; i < b; i++) {
                        a[i] = i;
                    }
                    Heapsort(a, 0, b - 1);
                };
    BENCHMARK("Sort 7500")
                {
                    int b = 7500;
                    int *a = new int[b];
                    for (int i = 0; i < b/20; i++) {
                        a[i] = 20;
                    }
                    for (int i = b/20; i < b; i++) {
                        a[i] = i;
                    }
                    Heapsort(a, 0, b - 1);
                };
    BENCHMARK("Sort 10000")
                {
                    int b = 10000;
                    int *a = new int[b];
                    for (int i = 0; i < b/20; i++) {
                        a[i] = 20;
                    }
                    for (int i = b/20; i < b; i++) {
                        a[i] = i;
                    }
                    Heapsort(a, 0, b - 1);
                };
}
TEST_CASE("Benchmark for Heapsort with mas with same el") {
    BENCHMARK("Sort 100")
                {
                    int b = 100;
                    int *a = new int[b];
                    for (int i = 0; i < b/20; i++) {
                        a[i] = i;
                    }
                    for (int i = b/20; i < b; i++) {
                        a[i] = 50;
                    }
                    Heapsort(a, 0, b - 1);
                };
    BENCHMARK("Sort 1000")
                {
                    int b = 1000;
                    int *a = new int[b];
                    for (int i = 0; i < b/20; i++) {
                        a[i] = i;
                    }
                    for (int i = b/20; i < b; i++) {
                        a[i] = 50;
                    }
                    Heapsort(a, 0, b - 1);
                };
    BENCHMARK("Sort 2500")
                {
                    int b = 2500;
                    int *a = new int[b];
                    for (int i = 0; i < b/20; i++) {
                        a[i] = i;
                    }
                    for (int i = b/20; i < b; i++) {
                        a[i] = 50;
                    }
                    Heapsort(a, 0, b - 1);
                };
    BENCHMARK("Sort 5000")
                {
                    int b = 5000;
                    int *a = new int[b];
                    for (int i = 0; i < b/20; i++) {
                        a[i] = i;
                    }
                    for (int i = b/20; i < b; i++) {
                        a[i] = 50;
                    }
                    Heapsort(a, 0, b - 1);
                };
    BENCHMARK("Sort 7500")
                {
                    int b = 7500;
                    int *a = new int[b];
                    for (int i = 0; i < b/20; i++) {
                        a[i] = i;
                    }
                    for (int i = b/20; i < b; i++) {
                        a[i] = 50;
                    }
                    Heapsort(a, 0, b - 1);
                };
    BENCHMARK("Sort 10000")
                {
                    int b = 10000;
                    int *a = new int[b];
                    for (int i = 0; i < b/20; i++) {
                        a[i] = i;
                    }
                    for (int i = 50/20; i < b; i++) {
                        a[i] = 50;
                    }
                    Heapsort(a, 0, b - 1);
                };
}

