#pragma once

class sommet {
public:
	sommet(int const val) : val(val) {}
	int val = 0;
	sommet* gauche = nullptr;
	sommet* droite = nullptr;
};


class bst {
	sommet* racine_;
public:
	bst() : racine_(nullptr) {}

	void operator << (int const val) {
		auto noeud = this->racine_;

		if (!noeud) {
			this->racine_ = new sommet(val);
		}
		else {
			while (noeud) {
				if (val > noeud->val) {
					if (!noeud->droite) {
						noeud->droite = new sommet(val);
						return;
					}
					noeud = noeud->droite;
				}
				else {
					if (!noeud->gauche) {
						noeud->gauche = new sommet(val);
						return;
					}
					noeud = noeud->gauche;
				}
			}
		}
	}

	void operator >> (int const val) const {
		delete_node(this->racine_, val);
	}

	static sommet* delete_node(sommet* racine, int const val) {
		if (!racine) {
			return nullptr;
		}
		if (val < racine->val) {
			racine->gauche = delete_node(racine->gauche, val);
		}
		else if (val > racine->val) {
			racine->droite = delete_node(racine->droite, val);
		}
		else {
			if (!racine->gauche && !racine->droite) {
				delete racine;
				racine = nullptr;
			}
			else if (!racine->gauche) {
				const sommet* tmp = racine;
				racine = racine->droite;
				delete tmp;
			}
			else if (!racine->droite) {
				const sommet* tmp = racine;
				racine = racine->gauche;
				delete tmp;
			}
			else {
				const sommet* tmp = get_min(racine->droite);
				racine->val = tmp->val;
				racine->droite = delete_node(racine->droite, tmp->val);
			}
		}
		return racine;
	}

	static sommet* get_min(sommet* racine) {
		if (!racine) return nullptr;
		if (racine->gauche) return get_min(racine->gauche);
		return racine;
	}

	bool operator [] (int const val) const {
		sommet* noeud = this->racine_;

		while (noeud) {
			if (noeud->val == val) return true;
			if (noeud->val > val) noeud = noeud->gauche;
			else noeud = noeud->droite;
		}

		return false;
	}
};