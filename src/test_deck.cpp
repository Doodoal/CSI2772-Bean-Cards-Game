#include <iostream>
#include "Deck.h"
#include "CardFactory.h"

int main() {
    // Récupère l'instance unique de CardFactory
    CardFactory* factory = CardFactory::getFactory();

    // Crée un Deck mélangé
    Deck deck = factory->getDeck();

    // Affiche le contenu initial du Deck
    std::cout << "Deck mélangé :" << std::endl;
    std::cout << deck << std::endl;

    // Tire des cartes du Deck
    try {
        Card* card1 = deck.draw();
        std::cout << "Carte tirée : " << card1->getName() << std::endl;

        Card* card2 = deck.draw();
        std::cout << "Carte tirée : " << card2->getName() << std::endl;

        // Affiche le Deck après le tirage
        std::cout << "Deck après tirage : " << std::endl;
        std::cout << deck << std::endl;

        // Libère la mémoire pour les cartes tirées
        delete card1;
        delete card2;
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
