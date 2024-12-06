#ifndef GARDEN_H
#define GARDEN_H

#include "Card.h"
#include <string>
#include <ostream>

class Garden : public Card {
public:
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream& out) const override;
    ~Garden() = default;
};

#endif // GARDEN_H
