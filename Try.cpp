#include <exception>
#include <iostream>

template<class T>
class Try {
private:
    std::exception_ptr excep = nullptr;
    T value;
public:
    Try() {
        try {
            value = T();
        }
        catch (...) {
            excep = std::current_exception();
        }
    }

    Try(const T& x) {
        try {
            value = x;
        }
        catch (...) {
            excep = std::current_exception();
        }
    }
    Try(T&& x) {
        try {
            value = std::move(x);
        }
        catch (...) {
            excep = std::current_exception();
        }
    }

    template <class TException>
    Try(const TException& e) {
        excep = std::make_exception_ptr(e);
    }

    Try(std::exception_ptr e) : excep(std::move(e)) {}

    const T& Value() const {

        return value;

    }

    bool HasError() const {
        return excep != nullptr;
    }
};
int main() {
    Try<int> Tr;
    std::cout << Tr.Value();
    return 0;
}
