#ifndef HAND_H
#define HAND_H

#include "Chain_Base.h"
#include "Card.h"
#include <queue>
#include <list>
#include <iostream>
#include "CardFactory.h"

class Hand {
    std::queue<Card*, std::list<Card*>> cards;
    public:

    //Constructeur
    Hand() = default;
    Hand(std::istream&, const CardFactory*);

    //Operateur de copie
    Hand(const Hand& other);

    //Operateur d'assignation
    Hand& operator=(const Hand& other);

    //Destructeur
    ~Hand();

    Hand& operator+=(Card* card);
    Card* play();
    Card* top() const{ return cards.front();}
    Card* operator[](int index);
    friend std::ostream& operator<<(std::ostream&, const Hand&);


};

#endif //HAND_H
