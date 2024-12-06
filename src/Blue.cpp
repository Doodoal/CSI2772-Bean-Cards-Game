#include "Blue.h"

// Implémente le nombre de cartes nécessaires pour gagner des pièces
int Blue::getCardsPerCoin(int coins) const {
    switch (coins) {
        case 1: return 4;  // 4 cartes pour 1 pièce
        case 2: return 6;  // 6 cartes pour 2 pièces
        case 3: return 8;  // 8 cartes pour 3 pièces
        case 4: return 10; // 10 cartes pour 4 pièces
        default: return 0; // Retourne 0 pour une valeur invalide
    }
}

// Renvoie le nom complet de la carte
std::string Blue::getName() const {
    return "Blue";
}

// Insère le premier caractère de la carte dans le flux de sortie fourni en argument
void Blue::print(std::ostream& out) const {
    out << "B";
}
