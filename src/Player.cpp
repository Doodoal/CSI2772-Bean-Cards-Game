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



