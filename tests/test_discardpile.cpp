#include <iostream>
#include <sstream>
#include "DiscardPile.h"
#include "CardFactory.h"

int main() {
    CardFactory* factory = CardFactory::getFactory();

    // Test : Création de DiscardPile à partir d'un flux
    std::istringstream input("Blue Chili Stink");
    DiscardPile dp(input, factory);

    std::cout << "Initial DiscardPile : ";
    dp.print(std::cout);
    std::cout << std::endl;

    // Test : Ajouter une carte à la pile
    dp += factory->getCard("Green");
    std::cout << "Après ajout de Green : ";
    dp.print(std::cout);
    std::cout << std::endl;

    // Test : Afficher la carte supérieure
    std::cout << "Carte supérieure : " << dp << std::endl;

    // Test : Retirer la carte supérieure
    Card* topCard = dp.pickUp();
    std::cout << "Carte retirée : " << topCard->getName() << std::endl;
    std::cout << "Pile après retrait : ";
    dp.print(std::cout);
    std::cout << std::endl;

    delete topCard; // Libérer la mémoire de la carte retirée

    return 0;
}
