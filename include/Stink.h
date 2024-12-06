#ifndef STINK_H
#define STINK_H

#include "Card.h"
#include <string>
#include <ostream>

class Stink : public Card {
public:
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream& out) const override;
    ~Stink() = default;
};

#endif // STINK_H
