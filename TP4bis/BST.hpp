#pragma once

class sommet {
public:
	int val = 0;
	sommet* gauche = nullptr;
	sommet* droite = nullptr;
};


class bst {
	sommet* racine_;
public:
	bst() : racine_(nullptr) {}

	void operator << (bst& arbre, int const val) const {
		auto noeud = arbre.racine_;

		if (!noeud) {
			arbre.racine_ = new sommet(val);
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

	void operator >> (bst const& arbre, int const val) const {
		delete_node(arbre.racine_, val);
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

	bool operator [] (bst const& arbre, int const val) const {
		sommet* noeud = arbre.racine_;

		while (noeud) {
			if (noeud->val == val) return true;
			if (noeud->val > val) noeud = noeud->gauche;
			else noeud = noeud->droite;
		}

		return false;
	}
};