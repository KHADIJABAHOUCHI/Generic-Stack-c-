

#include <iostream>

template <typename T>
class Pile {
private:
    T* tableau;        // Tableau g�n�rique pour stocker les �l�ments
    int max_elem;      // Capacit� maximale de la pile
    int nbr_elem;      // Nombre d'�l�ments actuellement dans la pile

public:
    // Constructeur
    Pile(int taille);

    // M�thodes
    bool is_empty() const;       // V�rifie si la pile est vide
    bool is_full() const;        // V�rifie si la pile est pleine
    void empiler(const T& element); // Empile un �l�ment
    T depiler();                 // D�pile un �l�ment
    void afficher() const;       // Affiche les �l�ments de la pile

    // Destructeur
    ~Pile();
};

// D�finition des m�thodes apr�s la classe

// Constructeur
template <typename T>
Pile<T>::Pile(int taille) : max_elem(taille), nbr_elem(0) {
    tableau = new T[max_elem]; // Allocation dynamique du tableau
}

// V�rifie si la pile est vide
template <typename T>
bool Pile<T>::is_empty() const {
    return nbr_elem == 0;
}

// V�rifie si la pile est pleine
template <typename T>
bool Pile<T>::is_full() const {
    return nbr_elem == max_elem;
}

// Empile un �l�ment
template <typename T>
void Pile<T>::empiler(const T& element) {
    if (is_full()) {
        std::cerr << "Erreur : La pile est pleine, impossible d'empiler.\n";
    }
    else {
        tableau[nbr_elem++] = element;
    }
}

// D�pile un �l�ment
template <typename T>
T Pile<T>::depiler() {
    if (is_empty()) {
        std::cerr << "Erreur : La pile est vide, impossible de d�piler.\n";
        return T(); // Retourne une valeur par d�faut
    }
    else {
        return tableau[--nbr_elem];
    }
}

// Affiche les �l�ments de la pile
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
    delete[] tableau; // Lib�re la m�moire allou�e dynamiquement
}

