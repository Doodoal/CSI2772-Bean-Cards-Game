#ifndef SOY_H
#define SOY_H

#include "Card.h"
#include <string>
#include <ostream>

class Soy : public Card {
public:
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream& out) const override;
    ~Soy() = default;
};

#endif // SOY_H
