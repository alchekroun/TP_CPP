#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>  
#include <vector>
#include <algorithm>
#include <numeric>

/**
 * Ex 1
 */
struct complexe {
	int val_reel, val_imaginaire;

	std::string to_string() const {
		return "(" + std::to_string(val_reel) + ", " + std::to_string(val_imaginaire) + "i )";
	}
};

complexe addition(complexe const x, complexe const y, complexe& result) {

	result.val_reel = x.val_reel + y.val_reel;
	result.val_imaginaire = x.val_imaginaire + y.val_imaginaire;

	return result;
}

complexe multiply_by_cte(int const cte, complexe& result) {
	result.val_reel *= cte;
	result.val_imaginaire *= cte;

	return result;
}

/**
 * Ex 2
 */
complexe sum_complexe(std::vector<complexe> const& complexes) {
	complexe output{ 0, 0 };

	for (auto const cplx : complexes) {
		addition(cplx, output, output);
	}

	return output;
}

/**
 * Ex 3
 */
int const NMOIS = 12;

struct enreg {
	int stock;
	float prix;
	int ventes[NMOIS];

	std::string to_string() const {
		std::string ventes_str = "[";
		for (auto i = 0; i < NMOIS; i++) {
			ventes_str += std::to_string(ventes[i]) + ", ";
		}
		ventes_str += "]";
		return "stock : " + std::to_string(stock) + "\nprix : " + std::to_string(prix) + "\nventes: " + ventes_str;
	}
};

void reset_stocks(enreg& reg) {
	reg.stock = 0;
	for (auto i = 0; i < NMOIS; i++) {
		reg.ventes[i] = 0;
	}
}

/**
* Ex 4
*/
int const LG_NOM = 30;

struct date {
	int jour;
	int mois;
	int annee;

	std::string to_string() const {
		return std::to_string(jour) + '/' + std::to_string(mois) + '/' + std::to_string(annee);
	}
};

struct personne {
	char nom[LG_NOM + 1];
	date date_embauche;

	std::string to_string() const {
		std::string name(nom);
		return name + "\tEmbauche : " + date_embauche.to_string();
	}
};

void define_persone(personne& p) {
	std::cout << "Nom : ";
	std::cin >> p.nom;
	std::cout << "Date embauche (jj mm aa) : ";
	std::cin >> p.date_embauche.jour >> p.date_embauche.mois >> p.date_embauche.annee;
}

struct personne_dyn {
	std::string nom;
	date date_embauche;
	std::string to_string() const {
		return nom + "\tEmbauche : " + date_embauche.to_string();
	}
};

void define_persone(personne_dyn& p) {
	std::cout << "Nom : ";
	std::cin >> p.nom;
	std::cout << "Date embauche (jj mm aa) : ";
	std::cin >> p.date_embauche.jour >> p.date_embauche.mois >> p.date_embauche.annee;
}

int main() {
	enum choice {
		ex1 = 1,
		ex2 = 2,
		ex3 = 3,
		ex4 = 4
	};

	srand(time(nullptr));

	auto user_choice = 0;
	std::cout << "Welcome at TD1!" << std::endl;
	while (user_choice >= 0) {
		std::cout << "Pick an exercice number : " << std::endl;
		std::cin >> user_choice;
		switch (user_choice) {
		case ex1: {
			complexe const x{ 1, 2 };
			complexe const y{ 3, 4 };
			complexe z{};
			addition(x, y, z);
			std::cout << x.to_string() << " + " << y.to_string() << " = " << z.to_string() << std::endl;
			std::cout << "10 * " << z.to_string() << " = ";
			multiply_by_cte(10, z);
			std::cout << z.to_string() << std::endl;
		}
				break;
		case ex2: {
			std::vector<complexe> complexes(10);

			std::for_each(begin(complexes), end(complexes),
				[](complexe& cmpl) {
					// random values between 0 and 99
					cmpl.val_reel = rand() % 100;
					cmpl.val_imaginaire = rand() % 100;
				});

			auto result = sum_complexe(complexes);

			std::cout << "Result : " << result.to_string() << std::endl;
		}
				break;
		case ex3: {
			enreg x{ 50, 10, {1,2,3,4,5,6,7,8,9,10,11,12} };
			std::cout << "## Before ##" << std::endl << x.to_string() << std::endl;
			reset_stocks(x);
			std::cout << "## After ##" << std::endl << x.to_string() << std::endl;
		}
				break;
		case ex4: {
			personne pers{};
			define_persone(pers);
			std::cout << pers.to_string() << std::endl;
			personne_dyn pers_dyn{};
			define_persone(pers_dyn);
			std::cout << pers.to_string() << std::endl;
		}
				break;
		default: break;
		}
	}
	return 0;
}