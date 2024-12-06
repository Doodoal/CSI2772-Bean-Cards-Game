#include "Garden.h"

int Garden::getCardsPerCoin(int coins) const {
    switch (coins) {
        case 1: return 2;
        case 2: return 3;
        case 3: return 5;
        case 4: return 6;
        default: return 0;
    }
}

std::string Garden::getName() const {
    return "Garden";
}

void Garden::print(std::ostream& out) const {
    out << "G";
}
