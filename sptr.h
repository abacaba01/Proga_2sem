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
    explicit UniquePtr(T* p) {
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

struct Counter {
    size_t strong, weak;
};


template <class T>
class WeakPtr;


template <class T>
class SharedPtr {
    friend class WeakPtr<T>;
    void Check() {
        if (counter != nullptr) {
            (counter->strong)--;
            if ((counter->strong) == 0) {
                delete data;
                if (counter->weak == 0) {
                    delete counter;
                }
            }
        }

    }
public:
    SharedPtr() {
        data = new T;
        data = nullptr;
        counter = new Counter;
        counter = nullptr;
        counter->weak = 0; counter->strong = 1;
    }
    SharedPtr(const SharedPtr& other) {
        data=other.data;
        counter=other.counter;
        if (counter != nullptr) { counter->strong++; };
    }

    SharedPtr& operator=(const SharedPtr& other) {
        Check();
        if (this == &other) return *this;
        data=other.data;
        counter=other.counter;
        (counter->strong)++;
        return *this; }

    SharedPtr(SharedPtr&& other) : data(std::exchange(other.data, nullptr)), counter(std::exchange(other.counter, nullptr)) {};


    SharedPtr& operator=(SharedPtr&& other) {
        if (this == &other) {return *this;}
        Check();
        data = other.data;
        counter = other.counter;
        other.data = nullptr;
        other.counter = nullptr;
        return *this;

    }

    SharedPtr(T* p) {
        data = p;
        counter = new Counter;
        counter->weak = 0;
        counter->strong = 1;
    }

    SharedPtr(const WeakPtr<T>& other):  data(other.data), counter(other.counter){

        counter->strong++;
    }

    // Replaces pointer with nullptr
    void Reset() {
        if (data == nullptr) { return; };
         if (counter != nullptr) {
            (counter->strong)--;
            if (counter->strong == 0) {
                delete data;
                if (counter->weak == 0) {
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

    ~SharedPtr() {
        if (data == nullptr) { return; };
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
    Counter* counter;
};



template <class T>
class WeakPtr {
    friend class SharedPtr<T>;
public:
    WeakPtr() {
        data = new T;
        data = nullptr;
        counter = new Counter;
        counter = nullptr;
    }

    WeakPtr(const WeakPtr &other): data(other.data), counter(other.counter) {
        if (counter != nullptr) { counter->weak++; };
    }

    WeakPtr &operator=(const WeakPtr &other) {
        if (counter != nullptr) {
            (counter->weak)--;
            if (counter->strong == 0 && counter->weak == 0) {
                delete counter;
            }
        }
        data=other.data;
        counter=other.counter;
        if (counter != nullptr) {
            (counter->weak)++;
        }
        return *this;
    }

    WeakPtr(WeakPtr&& other){
        data = std::exchange(other.data, nullptr);
        counter = std::exchange(other.counter, nullptr);

    }

    WeakPtr &operator=(WeakPtr &&o) {  if (this == &o) {return *this;}
        if (counter != nullptr) {
            (counter->weak)--;
            if (counter->strong == 0 && counter->weak == 0) {
                delete counter;
            }
        }
        data = std::exchange(o.data, nullptr);
        counter = std::exchange(o.counter, nullptr);
        return *this;   }

    WeakPtr(const SharedPtr<T> &other) : data(other.data),counter(other.counter){
        if (counter != nullptr) { (counter->weak)++; };
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
        if (data == nullptr) return;
        data = nullptr;
        if (counter != nullptr) {
            (counter->weak)--;
            if (counter->strong == 0 && counter->weak == 0) {
                delete counter;
            }
        }
        counter = nullptr;     
    }

    bool Expired() const {
        return (counter == nullptr) || (counter->strong == 0);
    }

    SharedPtr<T> Lock() {
        if (!Expired()) {
            SharedPtr<T> shared_ptr(*this);
            return shared_ptr;
        }
        return nullptr;
       
    }

    ~WeakPtr()
    {
        if (counter != nullptr) {
            counter->weak--;
            if (counter->strong == 0 && counter->weak == 0) {
                delete counter;
            }
        }
        counter = nullptr;
        data = nullptr;
    }

private:
    T* data;
    Counter* counter;
};




#endif //PTR_SPTR_H
