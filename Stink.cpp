#include "Stink.h"

int Stink::getCardsPerCoin(int coins) const {
    switch (coins) {
        case 1: return 3;
        case 2: return 5;
        case 3: return 7;
        case 4: return 8;
        default: return 0;
    }
}

std::string Stink::getName() const {
    return "Stink";
}

void Stink::print(std::ostream& out) const {
    out << "S";
}
