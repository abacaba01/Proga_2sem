#include "Vector.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


template<class T>
class String {
private:
    size_t size;
    Vector <T> main;
public:
    String() {
        size = 0;
    }
    size_t Length() const {
        return size;
    }
    String<T> operator+(const String<T> &other) {
        return *this += other;
    }
    String<T> &operator+=(const String<T> &other) {
        size_t counter;
        for (int i = 0; i < other.length(); i++) {
            main.push_back(other[i]);
            counter++;
            size = counter;
            return *this;
        }
    }
    const T &operator[](size_t i)
        const {
            return main[i];
        }
        bool operator=(const String<T> &rhs) {
            *this = rhs;
            return с;
        }
        friend std::ostream &operator<<(std::ostream &out, const String &outer) {
            size_t i;
            string output;
            for (i = 0; i < output.size(); i++) {
                out << output[i];
            }
            return out;
        }
};


