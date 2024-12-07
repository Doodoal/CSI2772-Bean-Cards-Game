#ifndef PLAYER_H
#define PLAYER_H


#include <vector>
#include "Hand.h"
#include "Chain.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include "CardFactory.h"
#include <memory>
#include <typeinfo>

class MaxChainReached;
class NotEnoughCoins;

//TODO: Ajouter les classes Chain et Hand
class Player {

    std::string name;
    int numCoins;
    static int maxNumChains; //Tous les joueurs ont le même nombre maximal de chaines
    std::vector<std::unique_ptr<Chain_Base>> chains; //On store les chaines dans un vecteurs de pointeurs de type Chain_Base
                                                    //On utilise des pointeurs intelligents pour éviter les fuites de mémoire
    Hand hand;

    


   public:
        //Constructeur 
        Player(const std::string& name) : name(name), numCoins(0) , chains(){//Aucune pièce au début
            if (maxNumChains == 0) { // Si on a pas encore initialisé maxNumChains	
            maxNumChains = 2;   // Par défaut, 2 chaines au maximum pour tous les joueurs
            }
         }


        //Destructeur
        ~Player() { chains.clear();} //On a pas vraiment besoin de destructeur, vu que l'on a que deux joueurs.

        //Déclarations simples (Voir src/Player.cpp pour les définitions)
        void buyThirdChain();
        friend std::ostream& operator<<(std::ostream& os, const Player& player);
        void printHand(std::ostream&, bool) const;
        Player(std::istream&, const CardFactory*);


    


        //Déclarations avec inline definitions
        std::string getName() const { return name; }
        int getNumCoins() const { return numCoins; }
        int getNumChains() const { return chains.size(); }
        int getMaxNumChains() const { return maxNumChains; }
        void setMaxNumChains(int n) { maxNumChains = n; }
        Player& operator+=(int ncoins) { numCoins = numCoins + ncoins; return *this; }
        Chain_Base& operator[](int i) { return *chains[i]; }
        void addToHand(Card* card) { hand += card; }

       template <class T> //J'utilise un template pour pouvoir ajouter n'importe quel type de chaines
        void addChain(std::unique_ptr<Chain<T>> chain) {
            if (chains.size() == maxNumChains) {
                throw MaxChainReached(*this);
            } else {
                chains.push_back(std::move(chain));
                std::cout << "Nouvelle chaine de type " << typeid(T).name() << " ajoutee" << std::endl;
            }
        }

        template <class T>
        void addCardtoChain(T* card) {
            bool chainExists = false;

            //Verifie si le joueur a une chaine de type T
            for (auto& chain : chains) {
                if (typeid(*chain) == typeid(Chain<T>)) {
                    chain->addCard(card);
                    std::cout << "Carte ajoutee a une chaine existante de " << typeid(T).name() << std::endl;
                    std::cout << "Nouvel etat de la chaine: " << std::endl;
                    chain->print(std::cout);
                    std::cout << std::endl;
                    chainExists = true;
                    return;
                }
            } 
            
            if (!chainExists) {

                //Si le joueur n'a pas de chaine de type T, on en crée une nouvelle (si le nombre maximal de chaines n'est pas atteint)
                try{ 
                    addChain(std::make_unique<Chain<T>>());
                    chains.back()->addCard(card);
                    chains.back()->print(std::cout);
                } catch (MaxChainReached& e) {
                    std::cout << "ERREUR: Nombre maximal de chaines atteint | # Max: " + std::to_string(this->getMaxNumChains())<< std::endl;
                }
                
                
            }
        }



};


class NotEnoughCoins : public std::runtime_error {
public:
    explicit NotEnoughCoins( int ncoins, const Player& player) :
        std::runtime_error("ERREUR: Pieces insuffisantes | # Requis: " + std::to_string(ncoins) + " | # En votre possession: " + std::to_string(player.getNumCoins())) {} 

};

class MaxChainReached : public std::runtime_error {
public:
    explicit MaxChainReached(const Player& player) :
        std::runtime_error("ERREUR: Nombre maximal de chaines atteint | # Max: " + std::to_string(player.getMaxNumChains())) {} 

};



#endif // PLAYER_H