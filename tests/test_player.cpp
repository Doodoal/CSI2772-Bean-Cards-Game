#include "../include/Player.h"


using namespace std;

int main() {
	cout << "Unit tests - Player Class" << endl;
    cout << "==========================" << endl;
    std::string name;
    cout << "Enter your name: " << endl;
    cin >> name;
    Player p(name);
    cout << "Player name: " << p.getName() << endl;
    cout << "Player coins: " << p.getNumCoins() << endl;
    cout << "Player max chains: " << p.getMaxNumChains() << endl;
   
        // Additional tests
        cout << "Testing addCardToChain function" << endl;
        Blue* card = new Blue(); // Assuming Card has a default constructor
        try {
             
            p.addChain(std::make_unique<Chain<Blue>>());
            p[0].addCard(card);
            cout << "Card added to chain 0" << endl;
        } catch (IllegalType& e) {
            cout << e.what() << endl;
        }

        cout << "Testing getChain function" << endl;
        try {
            Chain_Base& chain = p[0];
            cout << "Chain 0 retrieved successfully" << endl;
        } catch (IllegalType& e) {
            cout << e.what() << endl;
        }

        cout << "Testing print function" << endl;
        p[0].addCard(new Blue());
        p[0].print(std::cout);
        try{
            
           
            Green* card2 = new Green();  
            p.addCardtoChain(card2);

            p.addCardtoChain(new Blue());
            p.addCardtoChain(new Blue());
            p.addCardtoChain(new Green());
            p.addCardtoChain(new Red());
            p.addCardtoChain(new soy());
            
        } catch (MaxChainReached& e) {
            cout << e.what() << endl;
        }

        std::cout << p << std::endl;

        
    cout << "Buying a third chain" << endl;
    try {
        p.buyThirdChain();
    } catch (NotEnoughCoins& e) {
        cout << e.what() << endl;
    }
    cout << "Adding 3 coins to player" << endl;
    p += 3;
    cout << "Buying a third chain" << endl;
    try {
        p.buyThirdChain();
    } catch (NotEnoughCoins& e) {
        cout << e.what() << endl;
    }
    cout << "Player coins: " << p.getNumCoins() << endl;
    cout << "Player max chains: " << p.getMaxNumChains() << endl;
    p.addCardtoChain(new soy());
    p.addCardtoChain(new Blue());
    p+= p[0].sell();
    cout << p << endl;

   

        

     

	return 0;
}