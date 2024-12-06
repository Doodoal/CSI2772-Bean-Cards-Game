#ifndef CHAIN_BASE_H
#define CHAIN_BASE_H

#include <iostream>
#include <string>


class Card;

class Chain_Base {
public:
    virtual ~Chain_Base() = default;

    // Ajoute une carte à la chaîne
    virtual void addCard(Card* card) = 0;

    // Vend les cartes de la chaîne et retourne les pièces obtenues
    virtual int sell() const = 0;

    // Affiche la chaîne dans un std::ostream
    virtual void print(std::ostream& out) const = 0;
};

inline std::ostream& operator<<(std::ostream& out, const Chain_Base& chain) {
    chain.print(out);
    return out;
}

#endif // CHAIN_BASE_H
