#ifndef TABLE_H
#define TABLE_H

#include "Player.h"
#include "CardFactory.h"
#include "DiscardPile.h"
#include "Deck.h"
#include "TradeArea.h"
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>


class Table{
    Player p1;
    Player p2;
    int currentPlayer;
    DiscardPile dPile;
    CardFactory* factory;
    Deck deck;
    TradeArea tradeArea;

    public:
        //Constructeur a partir du nom des joueurs
        Table(std::string p1_name ="Player 1", std::string p2_name = "Player 2"): 
                                        p1(Player(p1_name)), 
                                        p2(Player(p2_name)),
                                        currentPlayer(1),//Le premier joueurs commence par défaut
                                        dPile(DiscardPile()),
                                        factory(CardFactory::getFactory()){
                                            deck = factory->getDeck();

                                        }
                                                                                
        Table(std::istream&, const CardFactory*);




    
        bool win(std::string&);

        void playCard();

        void printHand(bool all_cards) const;

       

        void nextPlayer(){currentPlayer = currentPlayer == 1 ? 2 : 1;}
        Player& getCurrentPlayer() {return currentPlayer == 1 ? p1 : p2;}
        Player& getPlayer1(){return p1;}
        Player& getPlayer2(){return p2;}
        DiscardPile& getDiscardPile(){return dPile;}
        Deck& getDeck() {return deck;}
        TradeArea& getTradeArea() {return tradeArea;}
        friend std::ostream& operator<<(std::ostream& os, const Table& table);
        friend std::ostream& saveGame(std::ostream& os, const Table& table);


};




#endif // TABLE_H