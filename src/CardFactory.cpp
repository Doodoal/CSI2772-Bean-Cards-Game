#include "../include/CardFactory.h"
#include "../include/Deck.h"
#include <chrono>

// Initialise l'instance unique
CardFactory* CardFactory::instance = nullptr;

// Constructeur privé
CardFactory::CardFactory() {
    // Crée toutes les cartes en fonction des quantités spécifiées
    for (int i = 0; i < 20; ++i) allCards.push_back(new Blue());
    for (int i = 0; i < 18; ++i) allCards.push_back(new Chili());
    for (int i = 0; i < 16; ++i) allCards.push_back(new Stink());
    for (int i = 0; i < 14; ++i) allCards.push_back(new Green());
    for (int i = 0; i < 12; ++i) allCards.push_back(new soy());
    for (int i = 0; i < 10; ++i) allCards.push_back(new black());
    for (int i = 0; i < 8; ++i) allCards.push_back(new Red());
    for (int i = 0; i < 6; ++i) allCards.push_back(new garden());
}

// Renvoie l'instance unique de CardFactory
CardFactory* CardFactory::getFactory() {
    if (!instance) {
        instance = new CardFactory();
    }
    return instance;
}

// Renvoie un deck contenant toutes les cartes mélangées
Deck CardFactory::getDeck() const {
    Deck deck;

    // Ajoute toutes les cartes dans les quantités spécifiées
    for (int i = 0; i < 20; ++i) deck.push_back(new Blue());
    for (int i = 0; i < 18; ++i) deck.push_back(new Chili());
    for (int i = 0; i < 16; ++i) deck.push_back(new Stink());
    for (int i = 14; i > 0; --i) deck.push_back(new Green());
    for (int i = 12; i > 0; --i) deck.push_back(new soy());
    for (int i = 10; i > 0; --i) deck.push_back(new black());
    for (int i = 8; i > 0; --i) deck.push_back(new Red());
    for (int i = 6; i > 0; --i) deck.push_back(new garden());

    // Mélange les cartes avec une graine basée sur un dispositif aléatoire et l'horloge système
    std::random_device rd;
    std::mt19937 g(rd() ^ static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count()));
    std::shuffle(deck.begin(), deck.end(), g);

    return deck;
}







// Renvoie une carte en fonction de son nom
Card* CardFactory::getCard(const std::string& cardName) const {
    for (auto card : allCards) {
        if (card->getName() == cardName) {
            return card;
        }
    }
    return nullptr;
}

// Destructeur
CardFactory::~CardFactory() {
    for (Card* card : allCards) {
        delete card; // Libère chaque carte
    }
    allCards.clear();
}
