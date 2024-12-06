#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include "Card.h"
#include "Blue.h"
#include "Chili.h"
#include "Stink.h"
#include "Green.h"
#include "Soy.h"
#include "Black.h"
#include "Red.h"
#include "Garden.h"
#include "Deck.h"
#include <vector>
#include <algorithm>
#include <random>

// Déclaration anticipée de Deck
class Deck;

class CardFactory {
private:
    // Instance unique de CardFactory
    static CardFactory* instance;

    // Conteneur contenant toutes les cartes
    std::vector<Card*> allCards;

    // Constructeur privé pour empêcher la création directe
    CardFactory();

public:
    // Suppression du constructeur de copie et de l'opérateur d'affectation
    CardFactory(const CardFactory&) = delete;
    CardFactory& operator=(const CardFactory&) = delete;

    // Renvoie l'instance unique de CardFactory
    static CardFactory* getFactory();

    // Renvoie un deck contenant toutes les cartes mélangées
    Deck getDeck() const;

    // Renvoie une carte en fonction de son nom
    Card* getCard(const std::string& cardName) const;

    // Destructeur
    ~CardFactory();
};

#endif // CARDFACTORY_H
