#include <iostream>
#include <algorithm>
#include <vector>

/**
 * Ex 1
 */
float get_min(std::vector<float> const t) {
    auto minimum = std::numeric_limits<float>::max();
    std::for_each(begin(t), end(t),
        [&minimum](float const i) {
            if (i < minimum) {
                minimum = i;
            }
        });
    return minimum;
}

float get_max(std::vector<float> const t) {
    auto maximum = std::numeric_limits<float>::min();
    std::for_each(begin(t), end(t),
        [&maximum](float const i) {
            if (i > maximum) {
                maximum = i;
            }
        });
    return maximum;
}

void fill_positives_values(float t1[], float t2[]) {
    
}


void ex1_main_function(std::vector<float> t1, std::vector<float> t2) {
    std::cout << "Max de t1 : " << get_max(t1) << "\tMin de t1 : " << get_min(t1) << std::endl;
}


int main()
{
    enum choice {
        ex1 = 1,
        ex2 = 2,
        ex3 = 3,
        ex4 = 4
    };
    auto user_choice = 0, count_call = 0;
    std::cout << "Welcome at TD2!" << std::endl;
    while (user_choice >= 0) {
        std::cout << "Pick an exercice number : " << std::endl;
        std::cin >> user_choice;

        std::vector<float> t1{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        std::vector<float> t2{ -1, 5, 1, 2, 3, -10, 1, -2, -5, 8 };
        switch (user_choice) {
        case ex1:
            ex1_main_function(t1, t2);
            break;
        case ex2:
            break;
        case ex3:
            break;
        case ex4:
            break;
        default: break;
        }
    }
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
