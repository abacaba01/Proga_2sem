#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "../catch.hpp"
#include "Queue.h"

BENCHMARK() {
Queue<int32_t> a;

for (int32_t i = 0; i < N; ++i) {
a.Push(i);
}
for (int32_t i = 0; i < N; ++i) {
a.Pop();
}
return a.Size();
};
}