#include "../include/Hand.h"
#include <iostream>
#include <list>
#include <queue>
#include <stdexcept>



Card* Hand::play(){
        Card* card = cards.front();
        cards.pop();
        return card;
    }


std::ostream& operator<<(std::ostream& os, const Hand& hand) {
    auto cards = hand.cards;
    while (!cards.empty()) {
        os << *cards.front() << " ";
        cards.pop();
    }
    return os;
}

Card* Hand::operator[](int index) { 
        // Validater l'index
        if (index < 0 || index >= cards.size()) {
            throw std::out_of_range("Index out of range.");
        }

        // Accéder à la liste
        auto& list_ref = *reinterpret_cast<std::list<Card*>*>(&cards);

        // Itérer jusqu'à l'élément voulu
        auto it = list_ref.begin();
        std::advance(it, index);

        // Effacer et retourner la carte
        Card* card = *it;
        list_ref.erase(it);
        return card;
     }

Hand& Hand::operator+=(Card* card){
        cards.push(card);
        return *this;
    }

// Constructeur à partir d'un flux istream
Hand::Hand(std::istream& in, const CardFactory* factory) {
    std::string cardName;
    while (in >> cardName) {
        cards.push(factory->getCard(cardName));
    }
}

 Hand::Hand(const Hand& other){
        auto temp = other.cards;
        while(!temp.empty()){
            cards.push(temp.front());
            temp.pop();
        }
    }

Hand& Hand::operator=(const Hand& other){
        if(this != &other){
            auto temp = other.cards;
            while(!temp.empty()){
                cards.push(temp.front());
                temp.pop();
            }
        }
        return *this;
    }

Hand::~Hand(){
        while(!cards.empty()){
            cards.pop();
        }
    }