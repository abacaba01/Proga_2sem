#pragma once
#include <iostream>

template<class T>
class Try {
public:
	Try() {}
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
			value = x;
		}
		catch (...) {
			excep = std::current_exception();
		}
	}

	template <class TException>
	Try(const TException& e) {
		excep = std::make_exception_ptr(e);
	}

	Try(std::exception_ptr e) : excep(&e) {}

    const T& Value() const {
        try {
            return value;
        }
        catch (...) {
            excep = std::current_exception();
        }
        if (excep) {
            std::rethrow_exception(excep);
        }
    }

	bool HasError() const {
		return excep != nullptr;
	}

private:
	std::exception_ptr* excep;
	T value;
};