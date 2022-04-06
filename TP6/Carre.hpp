#pragma once
#include <iostream>

#include "Forme.hpp"

class carre : public forme {
public:
	void afficher() override {
		if (!this->etat_) {
			for (auto r = 0; r < 4; r++) {
				for (auto c = 0; c < 5; c++) {
					if (r == 0 || r == 3) {
						std::cout << "*";
					}
					else if (c == 0 || c == 4) {
						std::cout << "*";
					}
					else {
						std::cout << " ";
					}
				}
				std::cout << std::endl;
			}
		}
		else {
			for (auto r = 0; r < 5; r++) {
				for (auto c = 0; c < 5; c++) {
					if (r == 0 || r == 4) {
						if (c == 2) std::cout << "*";
						else std::cout << " ";
					}
					else if (r == 1 || r == 3) {
						if (c == 2) std::cout << "*";
						else std::cout << " ";
					}
					else {
						if (c == 0 || c == 4) std::cout << "*";
						else std::cout << " ";
					}
				}
				std::cout << std::endl;
			}
		}
	}

};