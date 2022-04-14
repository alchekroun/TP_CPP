// TP6.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>

#include "Carre.hpp"
#include "Cercle.hpp"
#include "Triangle.hpp"
#include "Point.hpp"
#include "Points.hpp"


template<class T>
void tri(T l[], int const size) {
	for (auto k = size - 1; k >= 0; k--) {
		T max = l[0];
		int max_indice = 0;
		for (auto i = 0; i <= k; i++) {
			if (l[i] > max) {
				max = l[i];
				max_indice = i;
			}
		}
		auto tmp = l[k];
		l[k] = l[max_indice];
		l[max_indice] = tmp;

	}
}


int main()
{
	enum choice {
		ex1 = 1,
		ex2 = 2,
		ex3 = 3,
		ex4 = 4
	};
	auto user_choice = 0;
	std::cout << "Welcome at TD6!" << std::endl;
	while (user_choice >= 0) {
		std::cout << "Pick an exercice number : " << std::endl;
		std::cin >> user_choice;
		switch (user_choice) {
		case ex1: {
			for (auto i = 0; i < 10; i++) {
				std::string choix;
				std::cout << "Quelle forme ? (Carre [C] / Triangle [T] / Cercle [R])" << std::endl;
				std::cin >> choix;
				if (choix == "C") {
					auto ff = carre();
					ff.afficher();
					ff.rotation();
					ff.afficher();
				}
				if (choix == "T") {
					auto ff = triangle();
					ff.afficher();
					ff.rotation();
					ff.afficher();
				}
				else {
					auto ff = cercle();
					ff.afficher();
					ff.rotation();
					ff.afficher();
				}
			}
		}
				break;
		case ex2: {
			int l1[3] = { 3, 2, 4 };
			tri(l1, 3);
			double l2[3] = { 3.5, 2.1, 4.2 };
			tri(l2, 3);
		}
		default:break;
		}
	}
}
