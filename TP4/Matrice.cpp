#include "Matrice.hpp"

int matrice::get(int const row, int const col) const { return  this->entiers_[row * col + col]; }

void matrice::set(int const row, int const col, int const value) const { this->entiers_[row * col + col] = value; }

std::pair<int, int> matrice::shape() const { return this->shape_; }

bool matrice::multiply(matrice const& other, matrice const& result) const  {
    if (this->shape().second != other.shape().first) {
        return false;
    }
    if (result.shape().first != this->shape().first || result.shape().second != other.shape().second) {
        return false;
    }
    
    for (auto r = 0; r < result.shape().first; r++) {
        for (auto c = 0; c < result.shape().second; c++) {
            int value = 0;
            for (auto n = 0; n < this->shape().second(); n++) {
                value += this->get(r, n) * other.get(n, c);
            }
            result.set(r, c, value);
        }
    }

    return true;
}

std::string matrice::to_string() const {
    std::string output;
    for (auto r = 0; r < this->shape().first; r++) {
        output += "[";
        for (auto c = 0; c < this->shape().second; c++) {
            output += std::to_string(this->get(r, c)) + ",";
        }
        output += "]\n";
    }
    return output;
}