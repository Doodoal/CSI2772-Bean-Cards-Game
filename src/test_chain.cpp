#include <iostream>
#include "Chain.h"
#include "Blue.h"
#include "Red.h"
#include "IllegalType.h"

int main() {
    // Crée une chaîne pour les cartes Blue
    Chain<Blue> blueChain;

    // Ajoute des cartes Blue à la chaîne
    try {
        std::cout << "Ajout de cartes Blue à la chaîne..." << std::endl;
        blueChain.addCard(new Blue());
        blueChain.addCard(new Blue());
        blueChain.addCard(new Blue());
    } catch (const IllegalType& e) {
        std::cerr << e.what() << std::endl;
    }

    // Affiche la chaîne Blue
    std::cout << "Contenu de la chaîne Blue : " << std::endl;
    std::cout << blueChain;

    // Teste l'ajout d'une carte de type incorrect
    try {
        std::cout << "Ajout d'une carte Red (type incorrect) à la chaîne Blue..." << std::endl;
        blueChain.addCard(new Red()); // Devrait lancer une exception
    } catch (const IllegalType& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    // Vend les cartes Blue
    int coins = blueChain.sell();
    std::cout << "Pièces obtenues après vente de la chaîne Blue : " << coins << std::endl;

    // Crée une chaîne pour les cartes Red
    Chain<Red> redChain;

    // Ajoute des cartes Red à la chaîne
    try {
        std::cout << "Ajout de cartes Red à la chaîne..." << std::endl;
        redChain.addCard(new Red());
        redChain.addCard(new Red());
        redChain.addCard(new Red());
    } catch (const IllegalType& e) {
        std::cerr << e.what() << std::endl;
    }

    // Affiche la chaîne Red
    std::cout << "Contenu de la chaîne Red : " << std::endl;
    std::cout << redChain;

    // Vend les cartes Red
    coins = redChain.sell();
    std::cout << "Pièces obtenues après vente de la chaîne Red : " << coins << std::endl;

    return 0;
}
