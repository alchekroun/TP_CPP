#include <iostream>
#include "TicTacToe.hpp"

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
		default: break;
		}
	}
}