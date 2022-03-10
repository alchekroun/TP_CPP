#pragma once

#include "Liste.hpp"

class ensemble {
	liste elements_;

public:
	ensemble() = default;

    ensemble(std::vector<int> const& elements) {
		for (auto const& element : elements) {
			ajouter(element);
		}
	}

	void ajouter(int const i) {
		if (i > 0 && !elements_.contains(i)) {
			elements_.add(i);
		}
	}

	void retirer(int const i) {
		elements_.remove(i);
	}

	// Revoir fonction amie ?
	ensemble operator + (ensemble const& obj) const {
		ensemble output;

		for (auto i = 0; i < this->elements_.size(); i++) {
			output.elements_.add(this->elements_.get(i));
		}

		for (auto i = 0; i < obj.elements_.size(); i++) {
			if (!output.elements_.contains(obj.elements_.get(i))) {
				output.elements_.add(obj.elements_.get(i));
			}
		}
		return output;
	}

	// Revoir, ne fonctionne pas
	ensemble operator - (ensemble const& obj) const {
		ensemble output;

		for (auto i = 0; i < this->elements_.size(); i++) {
			output.elements_.add(this->elements_.get(i));
		}

		for (auto i = 0; i < obj.elements_.size(); i++) {
			if (output.elements_.contains(obj.elements_.get(i))) {
				output.elements_.remove(obj.elements_.get(i));
			}
		}

		return output;
	}

	std::string to_string() const {
		return this->elements_.to_string();
    }
};