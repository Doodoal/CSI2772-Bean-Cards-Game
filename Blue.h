#ifndef BLUE_H
#define BLUE_H
#include "Card.h"


// Classe dérivée de la classe abstraite

class Blue : public Card {
public:

     // Implémente le nombre de cartes nécessaires pour gagner des pièces
    int getCardsPerCoin(int coins) const override;

    // Renvoie le nom complet de la carte
    std::string getName() const override;

    //insère le premier caractère de la carte dans le flux de sortie fourni en argument.

    void print(std::ostream& out) const override;

    ~Blue()  = default; 

    
};

#endif // BLUE_H