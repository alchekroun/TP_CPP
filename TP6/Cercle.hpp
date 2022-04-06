#pragma once
#include <iostream>

#include "Forme.hpp"

class cercle : public forme {
public:
	void afficher() override {
		for (auto r = 0; r < 6; r++) {
			for (auto c = 0; c < 6; c++) {
				if (r == 0 || r == 5) {
					if (c == 2 || c == 3) std::cout << "*";
					else std::cout << " ";
				}
				else if (r == 1 || r == 4) {
					if (c == 1 || c == 4) std::cout << "*";
					else std::cout << " ";
				}
				else if (r == 2 || r == 3) {
					if (c == 0 || c == 5) std::cout << "*";
					else std::cout << " ";
				}
			}
			std::cout << std::endl;
		}
	}

};