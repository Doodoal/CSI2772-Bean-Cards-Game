#include "Soy.h"

int Soy::getCardsPerCoin(int coins) const {
    switch (coins) {
        case 1: return 2;
        case 2: return 4;
        case 3: return 6;
        case 4: return 7;
        default: return 0;
    }
}

std::string Soy::getName() const {
    return "Soy";
}

void Soy::print(std::ostream& out) const {
    out << "Y";
}
