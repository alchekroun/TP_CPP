#pragma once
#include <string>
#include <iostream>

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


class file {
	int size_ = 10;
	personne* tab_ = new personne[this->size_];
	int start_;
	int end_;

public:
	file() : start_(-1), end_(-1) {}

	// desctructeur
	// Recopie
	// Affectation

	void operator << (file& origin, personne const& p) {
		if (origin.start_ == -1 && origin.end_ == -1) {
			origin.tab_[0] = p;
			origin.start_ = 0;
			origin.end_ = 0;
		}
		// full stack
		else if (abs(origin.start_ - origin.end_) == 1) {
			aggrandir_file();

		}
		else {
			origin.end_ += 1;
			origin.end_ %= origin.size_;
			origin.tab_[origin.end_] = p;
		}
	}

	void operator >> (file& origin, personne& p) {
		if (origin.start_ != -1 && origin.end_ != -1) {
			p = origin.tab_[origin.start_];
			origin.start_ += 1;
			origin.start_ %= origin.size_;

			if (origin.start_ > origin.end_) {
				origin.start_ = -1;
				origin.end_ = -1;
			}
		}
	}

	void aggrandir_file() {
		int const new_size = size_ + 10;
		auto const new_tab = new personne[new_size];
		memcpy(new_tab, this->tab_, this->size_ * sizeof(personne));
		this->size_ = new_size;
		this->tab_ = new_tab;
	}
};