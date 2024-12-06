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


// Classes dérivées de la classe abstraite

class black : public Card {
public:
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream& out) const override;
    ~black() = default;
};




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


class Chili : public Card {
public:
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream& out) const override;
    ~Chili() = default;
};

class garden : public Card {
public:
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream& out) const override;
    ~garden() = default;
};

class Green : public Card {
public:
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream& out) const override;
    ~Green() = default;
};


class Red : public Card {
public:
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream& out) const override;
    ~Red() = default;
};


class soy : public Card {
public:
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream& out) const override;
    ~soy() = default;
};


class Stink : public Card {
public:
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream& out) const override;
    ~Stink() = default;
};

#endif
