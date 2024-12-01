#include "Pile.h"

int main() {
    // Création d'une pile pour les entiers
    Pile<int> pile_entiers(5);

    // Test de la pile
    std::cout << "Empiler des elements dans la pile :\n";
    pile_entiers.empiler(10);
    pile_entiers.empiler(20);
    pile_entiers.empiler(30);
    pile_entiers.afficher(); // Affiche les éléments après empilement

    std::cout << "\nDepiler les elements :\n";
    while (!pile_entiers.is_empty()) {
        pile_entiers.depiler();
        pile_entiers.afficher(); // Affiche les éléments après chaque dépilement
    }

    std::cout << "\nTentative de depiler une pile vide :\n";
    pile_entiers.depiler(); // Test pour une pile vide

    return 0;
}
