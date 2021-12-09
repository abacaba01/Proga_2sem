#pragma once
#include <iostream>


class OptionalException :public exception {
private:
	std::string m_error;
public:
	OptionalException(std::string error) : m_error(error) {}
};

template <class T>
struct Optional {
private:
	T val;
	bool empty = true;
public:
	T GetValue() {
		if (!empty) {
			return val;
		}
		throw OptionalException("No Value");
	}
	T GetValueOr(const T& x) {
		if (empty) {
			return x;
		}
		else {
			return val;
		}
	}
	bool Empty() {
		return empty;
	}
	Optional() {}
	Optional(const T& x) : val(x), empty(false) {}
	Optional(const Optional<T>& other) {
		if (!other.Empty()) {
			val = other.GetValue();
			empty = false;
		}
	}
};