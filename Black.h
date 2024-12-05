#ifndef BLACK_H
#define BLACK_H

#include "Card.h"
#include <string>
#include <ostream>

class Black : public Card {
public:
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream& out) const override;
    ~Black() = default;
};

#endif // BLACK_H
