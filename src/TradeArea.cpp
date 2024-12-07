#include "TradeArea.h"

// Constructeur à partir d'un flux d'entrée
TradeArea::TradeArea(std::istream& in, const CardFactory* factory) {
    std::string cardName;
    while (in >> cardName) {
        cards.push_back(factory->getCard(cardName));
    }
}

// Ajoute une carte à l'échange
TradeArea& TradeArea::operator+=(Card* card) {
    cards.push_back(card);
    return *this;
}

// Vérifie si une carte peut être légalement ajoutée
bool TradeArea::legal(Card* card) const {
    for (const auto& c : cards) {
        if (c->getName() == card->getName()) {
            return true;
        }
    }
    return false;
}

// Supprime et retourne une carte par son nom
Card* TradeArea::trade(const std::string& cardName) {
    for (auto it = cards.begin(); it != cards.end(); ++it) {
        if ((*it)->getName() == cardName) {
            Card* card = *it;
            cards.erase(it);
            return card;
        }
    }
    return nullptr; // Carte non trouvée
}

// Retourne le nombre de cartes dans l'échange
int TradeArea::numCards() const {
    return cards.size();
}

// Affiche toutes les cartes dans l'échange
void TradeArea::print(std::ostream& out) const {
    for (const auto& card : cards) {
        out << *card << " "; // Utilise l'opérateur << des cartes
    }
}

// Opérateur d'insertion pour afficher les cartes
std::ostream& operator<<(std::ostream& out, const TradeArea& tradeArea) {
    tradeArea.print(out);
    return out;
}
