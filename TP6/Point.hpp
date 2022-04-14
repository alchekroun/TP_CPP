#pragma once
#include <cmath>

class point {
	int x_;
	int y_;
public:
	point(int const x = 0, int const y = 0) : x_(x), y_(y) {}

	bool operator < (point const& other) const {
		if (sqrt(pow(this->x_, 2) + pow(this->y_, 2)) < sqrt(pow(other.x_, 2) + pow(other.y_, 2))) {
			return true;
		}
		return false;
	}
};
