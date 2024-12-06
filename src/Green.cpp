#include "Green.h"

int Green::getCardsPerCoin(int coins) const {
    switch (coins) {
        case 1: return 3;
        case 2: return 6;
        case 3: return 7;
        case 4: return 8;
        default: return 0;
    }
}

std::string Green::getName() const {
    return "Green";
}

void Green::print(std::ostream& out) const {
    out << "G";
}
