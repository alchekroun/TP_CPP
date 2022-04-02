#pragma once
#include <iostream>
#include <string>

class heure {
protected:
	uint16_t h_;
	uint16_t m_;
	uint16_t s_;

public:
	heure(uint16_t const h, uint16_t const m, uint16_t const s) : h_(h < 23 ? h : 0), m_(m < 60 ? m : 0), s_(s < 60 ? s : 0) {}

	bool operator > (heure const& other) const {
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
		return std::to_string(this->h_) + ":" + std::to_string(this->m_);
	}

};
