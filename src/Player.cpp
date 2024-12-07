#include "../include/Player.h"
#include <string>
#include <iomanip>
#include <stdexcept>
#include <iostream>
using namespace std;



void Player::buyThirdChain() {
    if (numCoins < 3) {
        throw NotEnoughCoins(3, *this);
    }
    numCoins -= 3;
    maxNumChains = 3;
    cout << "3e chaine achetee!" << endl;
    cout << "# Pieces restantes: " << numCoins << endl;
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << player.name <<"   "<<   player.numCoins << " coins" << endl;
    for (const auto& chain : player.chains) {
        chain->print(os);
    }
    return os;
}

Player::Player(std::istream&, const CardFactory*) {
    cout << "Pas encore implemente" << endl;
}

void Player::printHand(std::ostream& os, bool all_cards) const {
    if (all_cards){
        os << hand<<std::endl;
    }
    else {
        os << *hand.top() << std::endl;
    }
}

void Player::printChains(std::ostream& os) const {
    int index = 1;
    for (const auto& chain : chains) {
            cout << "["<< index << "] ";
            chain->print(cout);
            cout << "Valeur actuelle: " << chain->sell() << " coins" << endl;
            ++index;
        }
}

void Player::sell(){

    bool loop = true;

    while(loop){
        cout << "VENTE DE CHAINE" << endl;
        cout << "Vos chaines actuelles: " << endl;
        printChains(cout);
        cout << "Quelle chaine voulez-vous vendre?" << endl;
        int choice;
        cin >> choice;
        if (choice < 1 || choice > chains.size()) {
            cout << "Choix invalide" << endl;
            continue;
        }
        numCoins += chains[choice - 1]->sell();
        chains.erase(chains.begin() + choice - 1);
        loop = false;
    }
    
}


void Player::play() {

    cout << name << " va jouer une carte" << endl;
    if (hand.size() == 0) {
        cout << "Main vide !" << endl;
        return;
    }
    
    auto* card = hand.play();
    cout << "Carte à jouer: " << *card << endl;

    try {
        addCardtoChain(card);
    } catch (MaxChainReached& e) {

        if (getNumChains() == 3) {
            cout << "Nombre maximal de chaines atteint: " << maxNumChains<< endl;
            cout << "Vous avez déjà payé une 3e chaine, vous devez donc en vendre une" << endl;
            sell();
            addCardtoChain(card);
            return;
        } else {
            cout << "Nombre maximal de chaines atteint: " << maxNumChains<< endl;
            cout << "Vous avez 2 options: " << endl;
            cout << "1. Vendre une chaine existante" << endl;
            cout << "2. Payer une 3e chaine" << endl;
            cout << "Payer une nouvelle chaine? (y/n)" << endl;
            char c;
            cin >> c;
            if (c == 'y') {
                buyThirdChain();
                addCardtoChain(card);
            } else {
                sell();
                addCardtoChain(card);
            }

        }

        

    }
   
    
}



void Player::draw(int n, Deck& deck) {
    for (int i = 0; i < n; ++i) {
        hand += deck.draw();
    }
}

void Player::discard(Card& card, DiscardPile& discardPile) {
    discardPile += &card;
}

void Player::discard(int index, DiscardPile& discardPile) {
    discardPile += hand[index];
}


void Player::trade(Card& card, TradeArea& tradeArea) {
    if (tradeArea.legal(&card)) {
        tradeArea += &card;
    } else {
        cout << "Carte illégale" << endl;
    }
}











