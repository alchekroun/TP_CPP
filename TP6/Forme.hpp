#pragma once

class forme {
protected:
    bool etat_ = false;

public:
	virtual void afficher() = 0;
	void rotation() { this->etat_ = !this->etat_; }
};