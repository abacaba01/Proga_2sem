//
// Created by artem on 03.10.2021.
//

#ifndef PTR_SPTR_H
#define PTR_SPTR_H
template <class T>
class UniquePtr {
public:
    UniquePtr() {
        data = new T;
        data = nullptr;
    }
    UniquePtr(const UniquePtr& o) = delete;
    UniquePtr& operator=(const UniquePtr& o) = delete;
    UniquePtr(UniquePtr &&other) : data(std::exchange(other.data, nullptr)) {
    }
    UniquePtr& operator=(UniquePtr&& other) {
        if (this == &other) {
            return *this;
        }
        data = std::exchange(other.data, nullptr);
        return *this;
    }
    UniquePtr(T* p) {
        data = p;
    }
    T* operator->() {
        return data;
    }

    T& operator*() {
        return *data;
    }
    ~UniquePtr() {
        delete data;
    }

private:
    T *data;
};


// ================================================


template <class T>
class WeakPtr;

template <class T> struct Counter{
    T* data;
    uint32_t strong, weak;
    Counter(T* data, uint32_t  strong, uint32_t weak): data(data), strong(strong), weak(weak){};
};

template <class T>
class SharedPtr {
    friend class WeakPtr<T>;
public:
    SharedPtr() {
        data(nullptr);
        counter(nullptr);
    }
    SharedPtr(const SharedPtr& other) : data(other.data), counter(other.counter) {

        counter->strong++;
    }

    SharedPtr& operator=(const SharedPtr& other) {
        if (counter != nullptr) {
            (counter->strong)--;
            if ((counter->strong) == 0) {
                delete data;
                if (counter->weak == 0) {
                    delete counter;
                }
            }
        }
        if (this == &other) return *this;
        data=other.data;
        counter=other.counter;
        (counter->strong)++;
        return *this; }

    SharedPtr(SharedPtr&& other) : data(std::exchange(other.data, nullptr)), counter(std::exchange(other.counter, nullptr)) {};


    SharedPtr& operator=(SharedPtr&& other) {
        if (this == &other) {return *this;}
        if (counter != nullptr) {
            (counter->strong)--;
            if (counter->strong == 0) {
                delete data;
                if (counter->weak == 0) {
                    delete counter;
                }
            }
        }
        std::swap(data, other.data);
        std::swap(counter, other.counter);
        return *this;

    }

    SharedPtr(T* p) {
        data = p;
        counter = new Counter<T>(p, 1, 0);
    }

    SharedPtr(const WeakPtr<T>& other):  data(other.data), counter(other.counter){

        counter->strong+=1;
    }

    // Replaces pointer with nullptr
    void Reset() {
        if (counter!=nullptr){
            counter->strong--;
            if (counter->strong == 0) {
                delete data;
                if(counter->weak == 0) {
                    delete counter;
                }
            }
        }
        data = nullptr;
        counter = nullptr;
    }

    T* operator->() {
        return data;
    }

    T& operator*() {
        return *data;
    }

    ~SharedPtr () {
        if (data == nullptr) return;
        (counter->strong)--;
        if (counter->strong == 0) {
            delete data;
            if (counter->weak == 0) {
                delete counter;
            }
        }
    }


private:
    T* data;
    Counter<T>* counter;
};



template <class T>
class WeakPtr {
    friend class SharedPtr<T>;

public:
    WeakPtr() {
        data(nullptr);
        counter(nullptr);
    }

    WeakPtr(const WeakPtr &other): data(other.data), counter(other.counter) {
        counter->weak++;
    }

    WeakPtr &operator=(const WeakPtr &other) {
        if (this == &other) return *this;
        WeakPtr<T> a(other);
        std::swap(data, a.data);
        std::swap(counter, a.counter);

        return *this;
    }

    WeakPtr(WeakPtr&& other):data(other.data), counter(other.counter){
        other.data = nullptr;
        other.counter = nullptr;
    }

    WeakPtr &operator=(WeakPtr &&o) {  if (this == &o) {return *this;}
        if (counter != nullptr) {
            (counter->weak)--;
        }
        counter = o.counter;
        data = o.data;
        o.data = nullptr;
        o.counter = nullptr;
        return *this;   }

    WeakPtr(const SharedPtr<T> &other) : data(other.data),counter(other.counter){
        (counter->weak)++;
    }


    WeakPtr &operator=(const SharedPtr<T> &other) {
        data = other.data;
        counter = other.counter;
        if (counter != nullptr)
            (counter->weak)++;
        return *this;
    }

    // Replaces pointer with nullptr
    void Reset() {
        if (counter != nullptr) {
            counter->weak--;
            if (counter->weak == 0) {
                delete counter;
            }
        }
        data = nullptr;
        counter = nullptr;
    }

    bool Expired() const {
        return (counter == nullptr) || (counter->strong == 0);
    }

    SharedPtr<T> Lock() {
        SharedPtr<T> shared_ptr(*this);
        return shared_ptr;
    }

    ~WeakPtr()
    {
        if (counter != nullptr) {
            counter->weak--;
            if (counter->weak == 0) {
                delete counter;
            }
        }
    }

private:
    T* data;
    Counter<T>* counter;
};




#endif //PTR_SPTR_H
