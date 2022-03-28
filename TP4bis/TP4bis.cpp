#include <iostream>
#include "File.hpp"
#include "BST.hpp"

int main()
{
	enum choice {
		ex1 = 1,
		ex2 = 2
	};
	auto user_choice = 0;
	std::cout << "Welcome at TD4bis!" << std::endl;
	while (user_choice >= 0) {
		std::cout << "Pick an exercice number : " << std::endl;
		std::cin >> user_choice;
		switch (user_choice) {
		case ex1: {
			auto f1 = file();
			auto p1 = personne();
			std::cout << f1.to_string() << std::endl;
			for (auto i = 0; i < 20; i++) {
				f1 << p1;
			}
			std::cout << f1.to_string() << std::endl;
			for (auto i = 0; i < 20; i++) {
				f1 >> p1;
			}
			std::cout << f1.to_string() << std::endl;
		}
				break;
		case ex2: {
			auto bst1 = bst();
			bst1 << 4;
			bst1 << 7;
			bst1 << 2;
			for (auto i = 0; i < 10; i++) {
				std::cout << i << " ? ";
				if (bst1[i]) {
					std::cout << "Oui";
				}
				else {
					std::cout << "Non";
				}
				std::cout << std::endl;
			}
		}
				break;
		default: break;
		}
	}
}
