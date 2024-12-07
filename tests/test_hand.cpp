#include "../include/Hand.h"
#include "../include/Card.h"
#include "../include/CardFactory.h"
#include <cassert>
#include <sstream>
#include <iostream>

void testHandConstructor() {
    Hand hand;
    assert(hand.top() == nullptr); 
    std::cout << "testHandConstructor passed!" << std::endl;
}

void testHandCopyConstructor() {
    Hand hand;
    
    Card* card = new Blue();
    hand += card;

    Hand handCopy(hand);
    assert(handCopy.top() == card);
    std::cout << "testHandCopyConstructor passed!" << std::endl;
}

void testHandAssignmentOperator() {
    Hand hand1;
    CardFactory* factory = CardFactory::getFactory();
    Card* card = new Blue();
    hand1 += card;

    Hand hand2;
    hand2 = hand1;
    assert(hand2.top() == card);
    std::cout << "testHandAssignmentOperator passed!" << std::endl;
}

void testHandPlay() {
    Hand hand;
    CardFactory* factory = CardFactory::getFactory();
    Card* card = new Blue();
    hand += card;

    Card* playedCard = hand.play();
    assert(playedCard == card);
    assert(hand.top() == nullptr); 
    std::cout << "testHandPlay passed!" << std::endl;
}

void testHandTop() {
    Hand hand;
    CardFactory* factory = CardFactory::getFactory();
    Card* card = new Blue();
    hand += card;

    assert(hand.top() == card);
    std::cout << "testHandTop passed!" << std::endl;
}

void testHandOperatorIndex() {
    Hand hand;
    CardFactory* factory = CardFactory::getFactory();
    Card* card1 = new Blue();
    Card* card2 = new Chili();
    hand += card1;
    hand += card2;
    std::cout << "Hand before hand[1]: " << hand<< std::endl;

    
    assert(hand[1] == card2);
    std::cout << "Hand after hand[1] " << hand<< std::endl;
    
}

void testHandStreamOperator() {
    Hand hand;
    Card* card = new Blue();
    hand += card;


    std::ostringstream oss;
    oss << hand;
    std::string handStr = oss.str();
    assert(handStr == "B ");
   std::cout << "testHandStreamOperator passed!" << std::endl;
    
}

int main() {
    testHandConstructor();
    testHandCopyConstructor();
    testHandAssignmentOperator();
    testHandPlay();
    testHandTop();
    testHandOperatorIndex();
    testHandStreamOperator();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}