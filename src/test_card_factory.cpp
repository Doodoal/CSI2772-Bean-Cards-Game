#include <iostream>
#include <vector>
#include <string>
#include "CardFactory.h"
#include "Deck.h"

int main() {
    // Récupère l'instance unique de CardFactory
    CardFactory* factory = CardFactory::getFactory();

    // Génère deux decks à partir de la CardFactory
    Deck deck1 = factory->getDeck();
    Deck deck2 = factory->getDeck();

    // Affiche les noms des cartes dans Deck 1
    std::vector<std::string> deck1Names, deck2Names;
    std::cout << "Noms des cartes dans Deck 1 : ";
    for (Card* card : deck1) {
        deck1Names.push_back(card->getName());
        std::cout << card->getName() << " ";
    }
    std::cout << std::endl;

    // Affiche les noms des cartes dans Deck 2
    std::cout << "Noms des cartes dans Deck 2 : ";
    for (Card* card : deck2) {
        deck2Names.push_back(card->getName());
        std::cout << card->getName() << " ";
    }
    std::cout << std::endl;

    // Compare les noms des cartes pour vérifier le mélange
    if (deck1Names != deck2Names) {
        std::cout << "Succès : Deux decks sont mélangés différemment." << std::endl;
    } else {
        std::cerr << "Échec : Les deux decks sont identiques." << std::endl;
    }

    return 0;
}
