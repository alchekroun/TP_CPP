#pragma once
#include "Tableau.hpp"

class tableau_borne : tableau<int> {
	int max_;
	int min_;

public:
	tableau_borne(int const size, int const max, int const min) : tableau(size), max_(max > min ? max : min), min_(max > min ? min : max) {
		for (auto i = 0; i < size; i++) {
			this->tab_[i] = max > min ? min : max;
		}
	}

	int operator [] (int const index) const {
		if (index >= this->size_) return this->tab_[0];
		return this->tab_[index];
	}

	void operator () (int const index, int const value) const {
		if (index < this->size_ && value <= this->max_ && value >= this->min_) {
			this->tab_[index] = value;
		}
	}
};