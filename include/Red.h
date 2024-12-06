#ifndef RED_H
#define RED_H

#include "Card.h"
#include <string>
#include <ostream>

class Red : public Card {
public:
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream& out) const override;
    ~Red() = default;
};

#endif // RED_H
