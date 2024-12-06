#include <iostream>
#include "../include/Card.h"


int main() {
    Blue blue;
    Chili chili;
    Stink stink;
    Green green;
    soy soy;
    black black;
    Red red;
    garden garden;

    std::cout << "Nom : " << blue.getName() << ", Affichage : " << blue << std::endl;
    std::cout << "Nom : " << chili.getName() << ", Affichage : " << chili << std::endl;
    std::cout << "Nom : " << stink.getName() << ", Affichage : " << stink << std::endl;
    std::cout << "Nom : " << green.getName() << ", Affichage : " << green << std::endl;
    std::cout << "Nom : " << soy.getName() << ", Affichage : " << soy << std::endl;
    std::cout << "Nom : " << black.getName() << ", Affichage : " << black << std::endl;
    std::cout << "Nom : " << red.getName() << ", Affichage : " << red << std::endl;
    std::cout << "Nom : " << garden.getName() << ", Affichage : " << garden << std::endl;

    return 0;
}
