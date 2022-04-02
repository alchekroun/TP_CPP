#pragma once
#include <string>
#include <vector>

#include "Tableau.hpp"

int constexpr lg_nom = 30;

struct date {
	int jour;
	int mois;
	int annee;

	std::string to_string() const {
		return std::to_string(jour) + '/' + std::to_string(mois) + '/' + std::to_string(annee);
	}
};

struct personne {
	char nom[lg_nom + 1];
	date date_embauche;

	std::string to_string() const {
		std::string const name(nom);
		return name + "\tEmbauche : " + date_embauche.to_string();
	}
};

class filenew : tableau<personne> {
public:
	filenew(int const size) : tableau<personne>(size) {}

	std::vector<personne> operator () (int nb) const {
		std::vector<personne> output;
		if (nb <= 0) return output;
		if (nb >= this->size_) {
			for (auto i = 0; i < this->size_; i++) output.push_back(this->tab_[i]);
		}
		int count = 0;
		while (nb > 0) {
			output.push_back(this->tab_[count]);
			count++;
			nb--;
		}
		return output;

	}
};
