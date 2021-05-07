//
// Created by artem on 02.05.2021.
//

#ifndef VECTOR_CPP_VECTOR_H
#define VECTOR_CPP_VECTOR_H

#include <algorithm>

template <class T>
class Vector {
public:
    Vector() : sz(0), cp(16) {
        arr = new T[cp];
    }

    size_t Size() {
        return sz;
    }

    void PushBack(T t) {
        if (sz >= cp) {
            Expand();
        }
        arr[sz] = t;
        sz++;
    }

    void PopBack() {
        if (sz != 0) {
            arr[--sz].~T();
        }
    }
    ~Vector() {
        for (size_t i = 0; i < sz; i++) {
            (arr + i)->~T();
        };
    }

    const T *Begin() const {
        return arr;
    }

    T *Begin() {
        return arr;
    }

    const T *End() const {
        return arr + sz;
    }

    T *End() {
        return arr + sz;
    }

    const T &Back() const {
        return arr[sz - 1];
    }

    T &Back() {
        return arr[sz - 1];
    }

    T &operator[](unsigned int i) {
        return arr[i];
    }

    const T &operator[](unsigned int i) const {
        return arr[i];
    }

    Vector(Vector &&other) : cp(std::exchange(other.cp, 0)),
                             arr(std::exchange(other.arr, nullptr)),
                             sz(std::exchange(other.sz, 0)) {
    }

    Vector(const Vector &&other) : cp(std::exchange(other.cp, 0)),
                                   sz(std::exchange(other.sz, 0)) {
        for (size_t i = 0; i < sz; i++) {
            arr[i] = other.arr[i];
        }
        return *this;
    }

    Vector &operator=(const Vector<T> &other) {
        sz = other.sz;
        cp = other.cp;
        for (size_t i = 0; i < sz; i++) {
            arr[i] = other.arr[i];
        }

        return *this;
    }

    Vector &operator=(Vector<T> &&other) {
        if (this == &other) return *this;
        Vector tmp(std::move(other));
        std::swap(sz, tmp.sz);
        std::swap(cp, tmp.cp);
        std::swap(arr, tmp.arr);
        return *this;
    }

private:
    size_t cp, sz;
    T *arr;

    void Expand() {;
        T* new_arr = new T[2 * cp];
        for (int i = 0; i < sz; i++) {
            new_arr[i] = arr[i];
        }
        arr = new_arr;
        cp *= 2;
    }
};



#endif //VECTOR_CPP_VECTOR_H
