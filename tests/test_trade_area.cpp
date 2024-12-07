#include <iostream>
#include <sstream>
#include "TradeArea.h"
#include "CardFactory.h"

int main() {
    CardFactory* factory = CardFactory::getFactory();
    std::istringstream input("Blue Chili Stink");

    // Initialisation de TradeArea avec des cartes
    TradeArea tradeArea(input, factory);

    std::cout << "TradeArea initial : " << tradeArea << std::endl;

    // Ajout de cartes
    Card* greenCard = factory->getCard("Green");
    tradeArea += greenCard;
    std::cout << "Après ajout de Green : " << tradeArea << std::endl;

    // Vérification de la légalité : carte légale
    std::cout << "La carte Green est-elle légale ? " << (tradeArea.legal(greenCard) ? "Oui" : "Non") << std::endl;

    // Vérification de la légalité : carte non légale
    Card* gardenCard = factory->getCard("Garden");
    std::cout << "La carte Garden est-elle légale ? " << (tradeArea.legal(gardenCard) ? "Oui" : "Non") << std::endl;

    // Retirer une carte
    Card* tradedCard = tradeArea.trade("Chili");
    std::cout << "Carte retirée : " << (tradedCard ? tradedCard->getName() : "Aucune carte trouvée") << std::endl;
    std::cout << "TradeArea après retrait de Chili : " << tradeArea << std::endl;

    // Nombre de cartes
    std::cout << "Nombre de cartes dans TradeArea : " << tradeArea.numCards() << std::endl;

    return 0;
}
