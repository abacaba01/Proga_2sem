#include <iostream>
#include <queue>
#include "vector.h"


template <class T>
class Queue{
private:

    vector<T> que;
    std::size_t head{0};
    int end{-1};

public:
    Queue() {}

    Queue(const queue& x) : end{x.end}, head{x.head} {
        que = x.que;
    }
    void Push(const T& elem) {
        que.push_back(elem);
        ++end;
    }

    T& Back() {
        return que[end];
    }

    T& Front() {
        return que[head];
    }

    bool Empty() {
        return que.empty();
    }

    void Pop() {
        ++head;
    }
    std::size_t Size() const {
        return end < head ? 0 : end - head + 1;
    }
};
