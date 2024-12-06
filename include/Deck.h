#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "CardFactory.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <iterator>
// Déclaration anticipée de CardFactory
class CardFactory;

class Deck : public std::vector<Card*> {
public:
    // Constructeur par défaut
    Deck() = default;

    // Constructeur à partir d'un istream
    Deck(std::istream& in, const CardFactory* factory);

    // Retourne et supprime la carte supérieure du Deck
    Card* draw();

    // Opérateur d'insertion pour afficher le contenu du Deck dans un std::ostream
    friend std::ostream& operator<<(std::ostream& out, const Deck& deck);
};

#endif // DECK_H
