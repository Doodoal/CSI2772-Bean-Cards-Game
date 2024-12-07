#include "../include/Player.h"
#include "../include/Table.h"
#include <string>
#include <iomanip>
#include <stdexcept>
#include <iostream>
using namespace std;


int Player::maxNumChains = 2;

int main() {
    try {
        std::string winner;
        // Add players to the table
        cout << "Le texte est ecrit au masculin pour des raisons de simplicite" << endl;
        cout << "______________________________________"<< endl;

        cout << "Entrez le nom du premier joueur: ";
        string p1_name;
        cin >> p1_name;
        cout << "Entrez le nom du deuxieme joueur: ";
        string p2_name;
        cin >> p2_name;

        Table table(p1_name, p2_name);

        TradeArea& tradeArea = table.getTradeArea();
        Deck& deck = table.getDeck();
        DiscardPile& dPile = table.getDiscardPile();

        table.getPlayer1().draw(5, deck);
        cout << "Main de " << table.getPlayer1().getName() << endl;
        table.getPlayer1().printHand(std::cout, true);

        table.getPlayer2().draw(5, deck);
        cout << "Main de " << table.getPlayer2().getName() << endl;
        table.getPlayer2().printHand(std::cout, true);
        

        while (!table.win(winner)) {

            
            
            cout << table;
            Player& player = table.getCurrentPlayer();
            cout << "NOUVEAU TOUR ( Joueur:" << player.getName() << ")" << endl;
            player.play();

            std::list<Card*>::iterator it = tradeArea.begin();
            
            while (it != tradeArea.end()) {
                try {
                    player.addCardtoChain(*it);
                } catch (MaxChainReached& e) {
                    cout << "La carte " << (*it)->getName() << " ne peut pas etre ajoutee a une chaine" << endl;
                    cout << "Ajout de cette carte a la discard pile" << endl;
                 ++it;
            }

            

            bool continuePlaying = true;
            cout << "CHECKPOINT A" << endl;
            while (continuePlaying) {
                cout << endl;
                cout << "Progrès actuel:" << endl;
                cout << "Nombre de pieces: " << player.getNumCoins() << endl;
                cout << "Chaines:"<< endl;
                player.printChains(cout);
                cout << "Main: " << endl;
                player.printHand(std::cout, true);
                cout << endl;
                cout << "Voulez-vous jouer une carte? (y/n)" << endl;
                char c;
                cin >> c;
                if (c == 'y') {
                    player.play();
                } else {
                    continuePlaying = false;
                }
            }

            cout << "CHECKPOINT B" << endl;

            cout << "Voulez-vous vous debarasser d'une carte? (y/n)" << endl;
            char discardDecision;
            cin >> discardDecision;
            if (discardDecision == 'y') {
                cout << "De quelle carte voulez-vous vous debarasser?" << endl;
                // Afficher les cartes dans la main
                player.printHand(std::cout, true);
                cout << "Entrez l'index de la carte a jeter (commence avec 1)" << endl;
                int index;
                cin >> index;
                player.discard(index-1, dPile);

            }

            cout << "CHECKPOINT C" << endl;
            player.draw(3, table.getDeck());
            while (tradeArea.legal(dPile.top())) {

                cout << "Carte ajoutee a la trade area: " << dPile.top() << endl;
                tradeArea += dPile.pickUp();
            }


            it = tradeArea.begin();

            cout << "CHECKPOINT D" << endl;
            cout << "Vos chaines actuelles: " << endl;
            player.printChains(cout);

            cout << "Cartes dans la trade area: ";
            while (it != tradeArea.end()) {
                
                    cout << "Carte "<< (*it)->getName() << endl;
                    cout << "Voulez-vous jouer cette carte? (y/n)" << endl;
                    char jouer;
                    cin >> jouer;

                    if (jouer == 'y') {
                        try {
                        player.addCardtoChain(*it);
                        } catch (MaxChainReached& e) {
                          cout << "La carte " << (*it)->getName() << " ne peut pas etre ajoutee a une chaine" << endl;
                        } 
                    }
                    
                
            
                 ++it;
            }


           player.draw(2, deck);
           cout << "----------------------------------"<< endl;
           cout << "FIN DU TOUR DE:" << player.getName() << endl;
           cout << "Récapitulatif:" << endl;
            cout << "Nombre de pieces: " << player.getNumCoins() << endl;
            cout << "Chaines:"<< endl;
            player.printChains(cout);
            cout << "Main: " << endl;
            player.printHand(std::cout, true);
            cout << "----------------------------------"<< endl;
            table.nextPlayer(); 
        }

        }
        // Missing closing brace added here

        // Display the winner
        cout << "The winner is: " << winner << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}