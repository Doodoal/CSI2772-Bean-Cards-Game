#ifndef CHILI_H
#define CHILI_H

#include "Card.h"
#include <string>
#include <ostream>

class Chili : public Card {
public:
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream& out) const override;
    ~Chili() = default;
};

#endif // CHILI_H
