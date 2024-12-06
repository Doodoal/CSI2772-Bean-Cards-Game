#ifndef CHAIN_H
#define CHAIN_H

#include "Chain_Base.h"
#include "Card.h"
#include "IllegalType.h"
#include "CardFactory.h"
#include <vector>
#include <stdexcept>
#include <string>
#include <ostream>
#include <istream>
// Classe paramétrée Chain
template <typename T>
class Chain : public Chain_Base {
private:
    std::vector<T*> cards; // Conteneur pour les cartes
public:
    // Constructeur par défaut
    Chain() = default;

    // Constructeur à partir d'un istream
    Chain(std::istream& in, const CardFactory* factory) {
        std::string cardName;
        while (in >> cardName) {
            cards.push_back(dynamic_cast<T*>(factory->getCard(cardName)));
        }
    }

    // Constructeur à partir d'un vecteur de cartes
    Chain(std::vector<T*> cards) : cards(cards) {}

    //Chain(const Chain_Base&): Chain() {}

    //Constructeur de copie
    Chain(const Chain& other) {
        for (auto card : other.cards) {
            cards.push_back(new T(*card));
        }
    }

    // Opérateur d'assignation
    Chain& operator=(const Chain& other) {
        if (this != &other) {
            for (auto card : cards) {
                delete card;
            }
            cards.clear();

            for (auto card : other.cards) {
                cards.push_back(new T(*card));
            }
        }
        return *this;
    }



    // Ajoute une carte à la chaîne
    void addCard(Card* card) override {
        T* specificCard = dynamic_cast<T*>(card);
        if (specificCard) {
            cards.push_back(specificCard);
        } else {
            throw IllegalType();
        }
    }

    // Compte les cartes et calcule le nombre de pièces
    int sell() const override {
        if (cards.empty()) return 0;

        int numCards = cards.size();
        int coins = 0;

        // On utilise getCardsPerCoin de la carte pour calculer les pièces
        int cardsPerCoin = cards.front()->getCardsPerCoin(1);
        while (numCards >= cardsPerCoin) {
            coins++;
            numCards -= cardsPerCoin;
            cardsPerCoin = cards.front()->getCardsPerCoin(coins + 1);
        }

        return coins;
    }

    // Affiche la chaîne
    void print(std::ostream& out) const override {
        if (cards.empty()) return;

        // Nom complet de la carte
        out << cards.front()->getName() << " ";
        
        // Affiche les symboles des cartes
        for (const auto& card : cards) {
            card->print(out);
            out << " ";
        }
        out << std::endl;
    }

    // Destructeur
    ~Chain() {
        for (auto card : cards) {
            delete card;
        }
        cards.clear();
    }
};

#endif // CHAIN_H
