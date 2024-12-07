#include "../include/DiscardPile.h"

// Constructeur qui lit les cartes d'un fichier
DiscardPile::DiscardPile(std::istream& in, const CardFactory* factory) {
    std::string cardName;
    while (in >> cardName) {
        pile.push_back(factory->getCard(cardName));
    }
}

// Jette une carte dans la pile
DiscardPile& DiscardPile::operator+=(Card* card) {
    pile.push_back(card);
    return *this;
}

// Renvoie et supprime la carte supérieure
Card* DiscardPile::pickUp() {
    if (pile.empty()) {
        throw std::out_of_range("La pile de défausse est vide.");
    }
    Card* topCard = pile.back();
    pile.pop_back();
    return topCard;
}

// Renvoie mais ne supprime pas la carte supérieure
Card* DiscardPile::top() const {
    if (pile.empty()) {
        throw std::out_of_range("La pile de défausse est vide.");
    }
    return pile.back();
}

// Imprime toutes les cartes de la pile
void DiscardPile::print(std::ostream& out) const {
    for (const auto& card : pile) {
        out << *card << " "; // Utilise l'opérateur << des cartes
    }
}

// Opérateur d'insertion pour afficher la carte supérieure
std::ostream& operator<<(std::ostream& out, const DiscardPile& dp) {
    if (!dp.pile.empty()) {
        out << *(dp.pile.back()); // Affiche seulement la carte supérieure
    } else {
        out << "(Vide)";
    }
    return out;
}

// Libère la mémoire allouée pour les cartes
DiscardPile::~DiscardPile() {
    for (Card* card : pile) {
        delete card;
    }
}
