#pragma once

#include <vector>
#include <string>

int ROW = 3;
int COL = 3;

enum joueur {
	personne,
	joueur1,
	joueur2,
};

class tic_tac_toe {
    std::vector<std::vector<joueur>> plateau_;
	bool quijoue_ = true;
	joueur winner_ = personne;

	bool is_valid(int const row, int const col) const {
		if (row >= this->plateau_.size() || col >= this->plateau_[0].size()) {
			return false;
		}
        if (this->plateau_[row][col] != personne) {
            return false;
        }
        return true;
	}

	joueur gagne() const {
		for (auto i = 0; i < this->plateau_.size(); i++) {
			if (has_winner(plateau_[i][0], plateau_[i][1], plateau_[i][2])) {
				return plateau_[i][0];
			}
			if (has_winner(plateau_[0][i], plateau_[1][i], plateau_[2][i])) {
				return plateau_[0][i];
			}
		}
		if (has_winner(plateau_[0][0], plateau_[1][1], plateau_[2][2])) {
			return plateau_[0][0];
		}
		if (has_winner(plateau_[0][2], plateau_[1][1], plateau_[2][0])) {
			return plateau_[0][2];
		}
		return personne;
	}

    static bool has_winner(joueur const& p1, joueur const& p2, joueur const& p3) {
		if (p1 == personne) return false;
		return p1 == p2 && p2 == p3;
	}

public:
	tic_tac_toe() {
        const std::vector<std::vector<joueur>> tmp(
			ROW,
			std::vector<joueur>(COL, personne)
		);
		this->plateau_ = tmp;
	}

	void jouer(int const row, int const col) {
		if (this->is_valid(row, col) && get_winner() == personne) {
			this->plateau_[row][col] = (this->quijoue_) ? joueur1 : joueur2;
			this->quijoue_ = !this->quijoue_;
			this->winner_ = gagne();
		}
	}

	joueur get_winner() const {
		return this->winner_;
	}

	std::string to_string() const {
		std::string output;
		for (auto const& row : this->plateau_) {
			output += "[";
			for (auto const& col : row) {
				output += std::to_string(col) + ",";
			}
			output += "]\n";
		}
		return output;
	}
};