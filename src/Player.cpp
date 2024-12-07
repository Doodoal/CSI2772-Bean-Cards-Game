#include "../include/Player.h"
#include <string>
#include <iomanip>
#include <stdexcept>
#include <iostream>
using namespace std;

int Player::maxNumChains = 2;

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







