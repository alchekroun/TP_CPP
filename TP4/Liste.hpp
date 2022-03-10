#pragma once

#include <string>
#include <vector>

class liste_case {
public:
	int value;
	liste_case* next_case;
	liste_case(int const value = 0, liste_case* next_case = nullptr) : value(value), next_case(next_case) {}

};

class liste {
	int size_ = 0;
	liste_case* first_;

public:
	liste() : first_(nullptr) {}
	liste(std::vector<int> const& entiers) {
		for (auto const& i : entiers) {
			add(i);
			this->size_ += 1;
		}
	}

	// Desctructeur !
	// Constructeur de recopie
	// operator =

	void add(int const value) {
		if (value < 0) {
			return;
		}
		if (!this->first_) {
			this->first_ = new liste_case(value);
		}
		else {
			auto curr = this->first_;

			while (curr->next_case) {
				curr = curr->next_case;
			}

			curr->next_case = new liste_case(value);
		}
		this->size_ += 1;
	}

	bool contains(int const value) const {
		auto curr = this->first_;
		while (curr) {
			if (curr->value == value) return true;
			curr = curr->next_case;
		}
		return false;
	}

	// Friend function !
	int get(int const index) const {
		int output = -1, count = 0;
		auto curr = this->first_;
		while (curr) {
			if (count == index) {
				output = curr->value;
				break;
			}
			curr = curr->next_case;
			count += 1;
		}
		return output;
	}

	void remove(int const value) {
		auto curr = this->first_;
		while (curr->next_case) {
			if (curr->next_case->value == value) {
				curr->next_case = curr->next_case->next_case;
				this->size_ -= 1;
				return;
			}
			curr = curr->next_case;
		}
	}

	int size() const { return this->size_; }

	std::string to_string() const {
		std::string output = "[";

		for (auto i = 0; i < size(); i++) {
			output += std::to_string(get(i)) + ", ";
		}
		output += "]";
		return output;
	}
};