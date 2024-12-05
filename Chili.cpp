#include "Chili.h"

int Chili::getCardsPerCoin(int coins) const {
    switch (coins) {
        case 1: return 3;
        case 2: return 6;
        case 3: return 8;
        case 4: return 9;
        default: return 0;
    }
}

std::string Chili::getName() const {
    return "Chili";
}

void Chili::print(std::ostream& out) const {
    out << "C";
}
