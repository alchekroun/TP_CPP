#include <iostream>

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
		}
				break;
		case ex2: {

		}
				break;
		default: break;
		}
	}
}
