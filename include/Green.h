#ifndef GREEN_H
#define GREEN_H

#include "Card.h"
#include <string>
#include <ostream>

class Green : public Card {
public:
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream& out) const override;
    ~Green() = default;
};

#endif // GREEN_H
