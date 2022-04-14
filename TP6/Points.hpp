#pragma once

template <class T, int I>
class points {
	T tab_[I];
public:
	points() {
		for (int i = 0; i < I; i++) {
			this->tab_[i] = 0;
		}
	}

	points(T const* tab, int const x) {
		for (int i = 0; i < x; i++) {
			this->tab_[i] = tab[i];
		}
	}

	T get_point(int i) const {
		return this->tab_[i];
	}

	void set_point(int const i, T const value) {
		this->tab_[i] = value;
	}

	points<T, I> operator + (points<T, I> const& other) {
		points<T, I> output;
		for (auto i = 0; i < I; i++) {
			output->set_point(i, this->get_point(i) + other.get_point(i));
		}
		return output;
	}

	points<T, I> operator * (points<T, I> const& other) {
		points<T, I> output;
		for (auto i = 0; i < I; i++) {
			output->set_point(i, this->get_point(i) * other.get_point(i));
		}
		return output;

	}

	T operator [] (int i) const {
		return i >= I ? -1 : this->get_point(i);
	}

	template<int K, int Y>
	void concat(points<T, K> const& p1, points<T, Y> const& p2) {
		auto output = points<T, K + Y>();

		for (auto i = 0; i < K; i++) {
			output.setIndex(i, p1->getIndex(i));
		}

		for (auto i = K; i < Y; i++) {
			output.setIndex(i, p2->getIndex(i - K));
		}

	};
};