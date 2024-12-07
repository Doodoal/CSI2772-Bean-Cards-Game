#ifndef TRADEAREA_H
#define TRADEAREA_H

#include <list>
#include <string>
#include <iostream>
#include "Card.h"
#include "CardFactory.h"

class TradeArea {
private:
    std::list<Card*> cards; // Conteneur de cartes

public:
    // Constructeur à partir d'un flux d'entrée
    TradeArea(std::istream& in, const CardFactory* factory);

    // Ajoute une carte à l'échange
    TradeArea& operator+=(Card* card);

    // Vérifie si une carte peut être légalement ajoutée
    bool legal(Card* card) const;

    // Supprime et retourne une carte par son nom
    Card* trade(const std::string& cardName);

    // Retourne le nombre de cartes dans l'échange
    int numCards() const;

    // Affiche toutes les cartes dans l'échange
    void print(std::ostream& out) const;

    // Opérateur d'insertion pour afficher les cartes
    friend std::ostream& operator<<(std::ostream& out, const TradeArea& tradeArea);
};

#endif // TRADEAREA_H
