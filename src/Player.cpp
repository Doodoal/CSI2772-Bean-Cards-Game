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





int main() {
	cout << "Unit tests - Player Class" << endl;
    cout << "==========================" << endl;
    cout << "Creating a player named 'Bob' with 5 coins" << endl;
    Player p("Bob");
    cout << "Player name: " << p.getName() << endl;
    cout << "Player coins: " << p.getNumCoins() << endl;
    cout << "Player max chains: " << p.getMaxNumChains() << endl;
   
    cout << "Buying a third chain" << endl;
    try {
        p.buyThirdChain();
    } catch (NotEnoughCoins& e) {
        cout << e.what() << endl;
    }
    cout << "Adding 3 coins to player" << endl;
    p += 3;
    cout << "Buying a third chain" << endl;
    try {
        p.buyThirdChain();
    } catch (NotEnoughCoins& e) {
        cout << e.what() << endl;
    }
    cout << "Player coins: " << p.getNumCoins() << endl;
     cout << "Adding 5 coins to player" << endl;
    p += 5;
    cout << "Player coins: " << p.getNumCoins() << endl;
    cout << "Player max chains: " << p.getMaxNumChains() << endl;

	return 0;
}