#ifndef PLAYER_H
#define PLAYER_H


#include <vector>
//#include "Hand.h"
//#include "Chain.h"
#include <iostream>
#include <string>
#include <stdexcept>


//TODO: Ajouter les classes Chain et Hand
class Player {

    std::string name;
    int numCoins;
    static int maxNumChains; //Tous les joueurs ont le même nombre maximal de chaines
   //vector<Chain> chains;


   public:
        //Constructeur 
        Player(std::string& name) : name(name), numCoins(0) {//Aucune pièce au début
            //this->chains = vector<Chain>();
            if (maxNumChains == 0) { // Si on a pas encore initialisé maxNumChains	
            maxNumChains = 2;   // Par défaut, 2 chaines au maximum pour tous les joueurs
            }
         }

        Player(std::string name) : name(name), numCoins(0) {//Aucune pièce au début
            //this->chains = vector<Chain>();
            if (maxNumChains == 0) { // Si on a pas encore initialisé maxNumChains	
            maxNumChains = 2;   // Par défaut, 2 chaines au maximum pour tous les joueurs
            }
         }
         


        //Déclarations avec inline definitions
        std::string getName() const { return name; }
        int getNumCoins() const { return numCoins; }
        //int getNumChains() const { return chains.size(); }
        int getMaxNumChains() const { return maxNumChains; }
        void setMaxNumChains(int n) { maxNumChains = n; }
        Player& operator+=(int ncoins) { numCoins = numCoins + ncoins; return *this; }
        //Chain& operator[](int i) { return chains[i]; }


        //Déclarations simples (Voir src/Player.cpp pour les définitions)
        void buyThirdChain();
        friend std::ostream& operator<<(std::ostream& os, const Player& player);
        void printHand(std::ostream&, bool) const;
        //Player(istream&, const CardFactory*);
        
        



};


class NotEnoughCoins : public std::runtime_error {
public:
    explicit NotEnoughCoins( int ncoins, const Player& player) :
        std::runtime_error("ERREUR: Pieces insuffisantes | # Requis: " + std::to_string(ncoins) + " | # En votre possession: " + std::to_string(player.getNumCoins())) {} 

};



#endif;