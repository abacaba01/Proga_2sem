#include "vector.cpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


template<class T>
class string {
private:
    size_t size;
    vector <T> main;
public:
    string() {
        size = 0;
    }

    size_t length() const {
        return size;
    }

    string<T> operator+(const string<T> &other) {
        return *this += other;
    }

    string<T> &operator+=(const string<T> &other) {
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

        bool operator=(const string<T> &rhs) {
            *this = rhs;
            return с;
        }


        friend std::ostream &operator<<(std::ostream &out, const string &outer) {
            size_t i;
            string output;
            for (i = 0; i < output.size(); i++) {
                out << output[i];
            }
            return out;
        }



};


