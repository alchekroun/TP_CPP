#pragma once
#include <string>


class matrice {
	static int matrice_alive_;
	int* entiers_;
	std::pair<int, int> shape_;

public:
	matrice(int const row, int const col = 1) : entiers_(new int(row* col + col)), shape_(row, col) {
		matrice_alive_ += 1;
	}

    int static get_nb_matrice_alive() {
		return matrice_alive_;
	}

	int get(int row, int col) const;

	void set(int row, int col, int value) const;

	std::pair<int, int> shape() const;

	bool multiply(matrice const& other, matrice const& result) const;

	std::string to_string() const;
};
