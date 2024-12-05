#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

class Card {

/*Créer la hiérarchie de carte haricot. Une carte haricot peut être affichée à la console avec son premier 
caractère de son nom.  - - 
La classe de base Card sera abstraite,  
Les classes derivées Blue, Chili, Stink, Green, soy, black, Red et garden 
devront être des classes concrètes.  
La classe Card aura les fonctions virtuelles pures suivantes : - - - 
virtual int getCardsPerCoin(int coins) implémentera dans les classes dérivées 
le tableau ci-dessus pour un nombre de cartes nécessaires afin de recevoir le nombre 
correspondant de pièces (coins). 
virtual string getName() renvoie le nom complet de la carte (e.g., Blue). 
virtual void print(ostream& out) insère le premier caractère de la carte dans le 
flux de sortie fourni en argument.  
Vous devriez créer également un flux global de l'opérateur d'insertion pour l'affichage des objets 
d'une telle classe qui implémente “Virtual Friend Function Idiom” avec la hiérarchie de la classe.  */

//on a mis les fonctions virtuelles en constantes pour eviter de les modifier dans les classes filles
public:
    virtual int getCardsPerCoin(int coins) const = 0;
    virtual std::string getName() const = 0;
    virtual void print(std::ostream& out) const = 0;
    virtual ~Card() = default;
    // Opérateur d'insertion global (défini uniquement ici)
    friend std::ostream& operator<<(std::ostream& out, const Card& card) {
        card.print(out);
        return out;
    }
};

#endif
