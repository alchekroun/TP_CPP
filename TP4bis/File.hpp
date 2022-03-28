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

	void operator << (personne const& p) {
		if (this->start_ == -1 && this->end_ == -1) {
			this->tab_[0] = p;
			this->start_ = 0;
			this->end_ = 0;
		}
		// full stack
		else if (abs(this->start_ - this->end_) == 1) {
			aggrandir_file();

		}
		else {
			this->end_ += 1;
			this->end_ %= this->size_;
			this->tab_[this->end_] = p;
		}
	}

	void operator >> (personne& p) {
		if (this->start_ != -1 && this->end_ != -1) {
			p = this->tab_[this->start_];
			this->start_ += 1;
			this->start_ %= this->size_;

			if (this->start_ > this->end_) {
				this->start_ = -1;
				this->end_ = -1;
			}
		}
	}

	void aggrandir_file() {
		int const new_size = this->size_ + 10;
		auto const new_tab = new personne[new_size];
		int index_new_tab = 0, index_old_tab = this->start_;

		while (index_new_tab < this->size_) {
			new_tab[index_new_tab] = this->tab_[index_old_tab];
			index_new_tab += 1;
			index_old_tab += 1;
			index_old_tab %= this->size_;
		}
		this->size_ = new_size;
		this->tab_ = new_tab;
	}

	std::string to_string() const {
		std::string output = "[";
		for (auto i = this->start_; i != this->end_; i++) {
			if (i >= this->size_) i = 0;
			output += this->tab_[i].to_string() + ", ";
		}
		output += "]";
		return output;
	}
};