#include "Deck.h"
#include "CardFactory.h" // Inclure ici pour la définition complète de CardFactory


// Constructeur à partir d'un istream
Deck::Deck(std::istream& in, const CardFactory* factory) {
    std::string cardName;
    while (in >> cardName) {
        this->push_back(factory->getCard(cardName)); // Utilise CardFactory pour récupérer les cartes
    }
}

// Retourne et supprime la carte supérieure du Deck
Card* Deck::draw() {
    if (this->empty()) {
        throw std::out_of_range("Le deck est vide.");
    }
    Card* topCard = this->back();
    this->pop_back(); // Supprime la carte supérieure
    return topCard;
}

// Opérateur d'insertion pour afficher le contenu du Deck
std::ostream& operator<<(std::ostream& out, const Deck& deck) {
    for (const auto& card : deck) {
        out << *card << " "; // Utilise l'opérateur << des cartes
    }
    return out;
}
