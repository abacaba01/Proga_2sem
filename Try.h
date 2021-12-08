#pragma once
#include <iostream>

using namespace std;

template<class T>
class Try {
public:
	Try() {}
	Try(const T& x) {
		try {
			value = value;
		}
		catch (...) {
			excep = current_exception();
		}
	}
	Try(T&& x) {
		try {
			value = value;
		}
		catch (...) {
			excep = current_exception();
		}
	}

	template <class TException>
	Try(const TException& e) {
		excep = make_exception_ptr(e);
	}

	Try(exception_ptr e) : excep(&e) {}

	const T& Value() const {
		return value;
	}

	bool HasError() const {
		return excep != nullptr;
	}

private:
	exception_ptr* excep;
	T value;
};