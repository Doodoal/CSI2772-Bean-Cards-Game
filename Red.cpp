#include "Red.h"

int Red::getCardsPerCoin(int coins) const {
    switch (coins) {
        case 1: return 2;
        case 2: return 3;
        case 3: return 4;
        case 4: return 5;
        default: return 0;
    }
}

std::string Red::getName() const {
    return "Red";
}

void Red::print(std::ostream& out) const {
    out << "R";
}
