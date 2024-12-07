#ifndef DISCARDPILE_H
#define DISCARDPILE_H

#include <vector>
#include <iostream>
#include "Card.h"
#include "CardFactory.h"

class DiscardPile {
private:
    std::vector<Card*> pile; // Conteneur pour les cartes

public:

    // Constructeur par défaut
    DiscardPile() = default;
    
    // Constructeur à partir d'un flux d'entrée
    DiscardPile(std::istream& in, const CardFactory* factory);

    // Jette une carte dans la pile
    DiscardPile& operator+=(Card* card);

    // Renvoie et supprime la carte supérieure de la pile
    Card* pickUp();

    // Renvoie mais ne supprime pas la carte supérieure
    Card* top() const;

    // Imprime toutes les cartes dans le flux fourni
    void print(std::ostream& out) const;

    // Opérateur d'insertion pour afficher seulement la carte supérieure
    friend std::ostream& operator<<(std::ostream& out, const DiscardPile& dp);

    // Libère la mémoire allouée pour les cartes
    ~DiscardPile();
};

#endif // DISCARDPILE_H
