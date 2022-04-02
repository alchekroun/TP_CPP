#pragma once
#include <algorithm>

template <class T>
class tableau {
protected:
	int size_;
	T* tab_;
public:
	tableau(int const size) : size_(size), tab_(new T[size]) {}

	int size() const { return this->size_; }

	tableau& operator = (tableau const& other) {
		if (this == &other) return *this;

		std::copy_n(other.tab_, other.tab_ + other.size_, tab_);
		return *this;
	}

	T& operator [] (int const index) {
		if (index >= this->size_) return this->tab_[0];
		return this->tab_[index];
	}
};
