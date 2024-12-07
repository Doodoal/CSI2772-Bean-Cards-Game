#include "../include/Table.h"   
#include <vector>
#include <iostream>
#include <stdexcept>

//TODO: Bien faire istream
Table::Table(std::istream& in, const CardFactory* factory){
    std::string p1_name;
    std::string p2_name;
    in >> p1_name;
    in >> p2_name;
    p1 = Player(p1_name);
    p2 = Player(p2_name);
    currentPlayer = 1;
    dPile = DiscardPile();
    deck = factory->getDeck();
}

bool Table::win(std::string& winner){
    if(deck.size() == 0){
        if(p1.getNumCoins() > p2.getNumCoins()){
            winner = p1.getName();
        } else if(p1.getNumCoins() < p2.getNumCoins()){
            winner = p2.getName();
        } else {
            winner = "Tie";
        }
        return true;
    }
    return false;
}


void Table::printHand(bool all_cards) const{
    if(currentPlayer == 1){
        std::cout << "Main de "<< p1.getName() <<":"<< std::endl;
        p1.printHand(std::cout, all_cards);
    } else {
        std::cout << "Main de "<< p2.getName() <<":"<< std::endl;
        p2.printHand(std::cout, all_cards);
    }
}

std::ostream& operator<<(std::ostream& os, const Table& table){
    os << table.p1 << std::endl;
    os << table.p2 << std::endl;
    os << table.dPile << std::endl;
    os << table.tradeArea << std::endl;
    return os;
}


std::ostream& saveGame(std::ostream& os, const Table& table){
    os << table.p1 << std::endl;
    os << table.p2 << std::endl;
    os << table.dPile << std::endl;
    os << table.tradeArea << std::endl;
    os << table.deck << std::endl;
    return os;
}









