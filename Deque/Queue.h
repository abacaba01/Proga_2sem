
#ifndef DEQUE_H_QUEUE_H
#define DEQUE_H_QUEUE_H

#include <iostream>
#include "deque.h"
template<class T>
class Queue {
public:
    Deque <T> deq;

    void PushBack(const T& el) {
        deq.Push_Back(el);
    }

    const T& operator[](size_t i) {
        return deq[i];
    }

    size_t Size() const {
        return deq.Size();
    }

    void PopFront() {
        deq.Pop_Front();
    }
};



#endif //DEQUE_H_QUEUE_H
