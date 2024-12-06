#include "Black.h"

int Black::getCardsPerCoin(int coins) const {
    switch (coins) {
        case 1: return 2;
        case 2: return 4;
        case 3: return 5;
        case 4: return 6;
        default: return 0;
    }
}

std::string Black::getName() const {
    return "Black";
}

void Black::print(std::ostream& out) const {
    out << "K";
}
