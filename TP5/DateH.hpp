#pragma once
#include "Heure.hpp"

class dateh : heure {
	uint16_t a_;
	uint16_t mois_;
	uint16_t j_;
	uint16_t jours_mois_[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
public:
	dateh(uint16_t const a, uint16_t const mois, uint16_t const j, uint16_t const h, uint16_t const m, uint16_t const s) : heure(h, m, s), a_(a), mois_(mois < 13 ? mois : 1) {
		if (j <= jours_mois_[mois - 1]) {
			this->j_ = j;
		}
		else {
			this->j_ = 1;
		}
	}

	bool operator > (dateh const& other) const {
		if (this->a_ > other.a_) return true;
		if (this->a_ < other.a_) return false;
		if (this->mois_ > other.mois_) return true;
		if (this->mois_ < other.mois_) return false;
		if (this->j_ > other.j_) return true;
		if (this->j_ < other.j_) return false;
		if (this->h_ > other.h_) return true;
		if (this->h_ < other.h_) return false;
		if (this->m_ > other.m_) return true;
		if (this->m_ < other.m_) return false;
		if (this->s_ > other.s_) return true;
		return false;
	}

	void affiche() const {
		std::cout << this->to_string();
	}

	std::string to_string() const {
		return std::to_string(this->j_) + "/" + std::to_string(this->mois_) + "/" + std::to_string(this->j_) + " " + std::to_string(this->h_) + ":" + std::to_string(this->m_);
	}
};
