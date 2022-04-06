#pragma once
#include <iostream>

#include "Forme.hpp"

class triangle : public forme {
public:
	void afficher() override {
		if (!this->etat_) {
			for (auto r = 0; r < 4; r++) {
				for (auto c = 0; c < 7; c++) {
					if (r == 0) {
						if (c == 3) std::cout << "*";
						else std::cout << " ";
					}
					else if (r == 1) {
						if (c == 2 || c == 4) std::cout << "*";
						else std::cout << " ";
					}
					else if (r == 2) {
						if (c == 1 || c == 5) std::cout << "*";
						else std::cout << " ";
					}
					else {
						std::cout << "*";
					}
				}
				std::cout << std::endl;
			}
		}
		else {
			for (auto r = 0; r < 4; r++) {
				for (auto c = 0; c < 7; c++) {
					if (r == 0) {
						std::cout << "*";
					}
					else if (r == 1) {
						if (c == 1 || c == 5) std::cout << "*";
						else std::cout << " ";
					}
					else if (r == 2) {
						if (c == 2 || c == 4) std::cout << "*";
						else std::cout << " ";
					}
					else {
						if (c == 3) std::cout << "*";
						else std::cout << " ";
					}
				}
				std::cout << std::endl;
			}
		}
	}

};