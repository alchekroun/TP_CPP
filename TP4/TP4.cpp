#include <iostream>
#include "TicTacToe.hpp"
#include "Matrice.hpp"
#include "Liste.hpp"
#include "Ensemble.hpp"

int main()
{
	enum choice {
		ex1 = 1,
		ex2 = 2,
		ex3 = 3,
		ex4 = 4
	};
	auto user_choice = 0;
	std::cout << "Welcome at TD4!" << std::endl;
	while (user_choice >= 0) {
		std::cout << "Pick an exercice number : " << std::endl;
		std::cin >> user_choice;
		switch (user_choice) {
		case ex1: {
			auto test = tic_tac_toe();
			test.jouer(0, 0);
			test.jouer(2, 2);
			test.jouer(1, 0);
			test.jouer(1, 2);
			test.jouer(2, 0);
			std::cout << test.to_string() << std::endl;
			std::cout << test.get_winner() << std::endl;
		}
				break;
		case ex2: {
			/*
			 *
			 * Soucis avec le compilateur
			auto a = matrice(3, 2);
			auto b = matrice(2, 3);
			std::cout << a.to_string() << " * " << b.to_string() << " = " << std::endl;

			auto r = matrice(3, 3);
			std::cout << matrice::get_nb_matrice_alive();

			if (a.multiply(b, r)) {
				std::cout << r.to_string();
			} else {
				std::cout << "Error";
			}
			*/

		}
				break;
		case ex3: {
			std::vector<int> tmp = { 1, 3, 5, 7, 9 };
			auto a = liste(tmp);
			std::cout << a.contains(3) << std::endl;
			a.remove(3);
			std::cout << a.contains(3) << std::endl;
			a.add(55);
			std::cout << a.contains(55) << std::endl;
			std::cout << a.get(2) << std::endl;
		}
				break;
		case ex4: {
			std::vector<int> tmp_a1 = { 1, 3, 5, 7, 9 };
			std::vector<int> tmp_a2 = { 1, 30, 5, 10 };
			auto a1 = ensemble(tmp_a1);
			auto a2 = ensemble(tmp_a2);

			std::cout << a1.to_string() << " + " << a2.to_string() << " = " << std::endl;
			auto a3 = a1 + a2;
			std::cout << a3.to_string() << std::endl;
			std::cout << a1.to_string() << " - " << a2.to_string() << " = " << std::endl;
			a3 = a1 - a2;
			std::cout << a3.to_string() << std::endl;
		}
				break;
		default: break;
		}
	}
}