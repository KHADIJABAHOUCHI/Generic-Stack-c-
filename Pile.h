

#include <iostream>

template <typename T>
class Pile {
private:
    T* tableau;        // Tableau générique pour stocker les éléments
    int max_elem;      // Capacité maximale de la pile
    int nbr_elem;      // Nombre d'éléments actuellement dans la pile

public:
    // Constructeur
    Pile(int taille);

    // Méthodes
    bool is_empty() const;       // Vérifie si la pile est vide
    bool is_full() const;        // Vérifie si la pile est pleine
    void empiler(const T& element); // Empile un élément
    T depiler();                 // Dépile un élément
    void afficher() const;       // Affiche les éléments de la pile

    // Destructeur
    ~Pile();
};

// Définition des méthodes après la classe

// Constructeur
template <typename T>
Pile<T>::Pile(int taille) : max_elem(taille), nbr_elem(0) {
    tableau = new T[max_elem]; // Allocation dynamique du tableau
}

// Vérifie si la pile est vide
template <typename T>
bool Pile<T>::is_empty() const {
    return nbr_elem == 0;
}

// Vérifie si la pile est pleine
template <typename T>
bool Pile<T>::is_full() const {
    return nbr_elem == max_elem;
}

// Empile un élément
template <typename T>
void Pile<T>::empiler(const T& element) {
    if (is_full()) {
        std::cerr << "Erreur : La pile est pleine, impossible d'empiler.\n";
    }
    else {
        tableau[nbr_elem++] = element;
    }
}

// Dépile un élément
template <typename T>
T Pile<T>::depiler() {
    if (is_empty()) {
        std::cerr << "Erreur : La pile est vide, impossible de dépiler.\n";
        return T(); // Retourne une valeur par défaut
    }
    else {
        return tableau[--nbr_elem];
    }
}

// Affiche les éléments de la pile
template <typename T>
void Pile<T>::afficher() const {
    if (is_empty()) {
        std::cout << "La pile est vide.\n";
    }
    else {
        std::cout << "Contenu de la pile : ";
        for (int i = nbr_elem - 1; i >= 0; --i) { // Affiche dans l'ordre LIFO
            std::cout << tableau[i] << " ";
        }
        std::cout << "\n";
    }
}

// Destructeur
template <typename T>
Pile<T>::~Pile() {
    delete[] tableau; // Libère la mémoire allouée dynamiquement
}

