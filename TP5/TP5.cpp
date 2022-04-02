#include <iostream>
#include "DateH.hpp"
#include "FileNew.hpp"
#include "Heure.hpp"
#include "Tableau.hpp"
#include "Tableau_borne.hpp"

int main()
{
	enum choice {
		ex1 = 1,
		ex2 = 2,
		ex3 = 3
	};
	auto user_choice = 0;
	std::cout << "Welcome at TD4bis!" << std::endl;
	while (user_choice >= 0) {
		std::cout << "Pick an exercice number : " << std::endl;
		std::cin >> user_choice;
		switch (user_choice) {
		case ex1: {
			auto h1 = heure(15, 20, 50);
			auto h2 = heure(16, 25, 57);
			std::cout << h1.to_string() << " > " << h2.to_string() << " -> " << (h1 > h2) << std::endl;

			auto d1 = dateh(2022, 4, 1, 15, 20, 50);
			auto d2 = dateh(2022, 4, 15, 15, 20, 50);
			std::cout << d1.to_string() << " > " << d2.to_string() << " -> " << (d1 > d2) << std::endl;
		}
				break;
		case ex2: {
			auto t1 = tableau<int>(2);
			t1[0] = 2;
			t1[1] = 3;
			t1[10] = 10;
			std::cout << t1[1] << "\t" << t1[99] << std::endl;
			auto t2 = tableau_borne(2, 1, 10);
			std::cout << t2[0] << std::endl;
		}
				break;
		case ex3: {
			auto f1 = filenew(2);
			auto test = f1(1);
			std::cout << test[0].to_string() << std::endl;
		}
				break;
		default:break;
		}
	}
}
