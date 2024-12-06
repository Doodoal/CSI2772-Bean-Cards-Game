#include "../include/Card.h"




//Blue
// Implémente le nombre de cartes nécessaires pour gagner des pièces
int Blue::getCardsPerCoin(int coins) const {
    switch (coins) {
        case 1: return 4;  // 4 cartes pour 1 pièce
        case 2: return 6;  // 6 cartes pour 2 pièces
        case 3: return 8;  // 8 cartes pour 3 pièces
        case 4: return 10; // 10 cartes pour 4 pièces
        default: return 0; // Retourne 0 pour une valeur invalide
    }
}

// Renvoie le nom complet de la carte
std::string Blue::getName() const {
    return "Blue";
}

// Insère le premier caractère de la carte dans le flux de sortie fourni en argument
void Blue::print(std::ostream& out) const {
    out << "B";
}


//Chili


int Chili::getCardsPerCoin(int coins) const {
    switch (coins) {
        case 1: return 3;
        case 2: return 6;
        case 3: return 8;
        case 4: return 9;
        default: return 0;
    }
}

std::string Chili::getName() const {
    return "Chili";
}

void Chili::print(std::ostream& out) const {
    out << "C";
}

//Stink

int Stink::getCardsPerCoin(int coins) const {
    switch (coins) {
        case 1: return 3;
        case 2: return 5;
        case 3: return 7;
        case 4: return 8;
        default: return 0;
    }
}

std::string Stink::getName() const {
    return "Stink";
}

void Stink::print(std::ostream& out) const {
    out << "S";
}


//Green


int Green::getCardsPerCoin(int coins) const {
    switch (coins) {
        case 1: return 3;
        case 2: return 6;
        case 3: return 7;
        case 4: return 8;
        default: return 0;
    }
}

std::string Green::getName() const {
    return "Green";
}

void Green::print(std::ostream& out) const {
    out << "G";
}

//soy


int soy::getCardsPerCoin(int coins) const {
    switch (coins) {
        case 1: return 2;
        case 2: return 4;
        case 3: return 6;
        case 4: return 7;
        default: return 0;
    }
}

std::string soy::getName() const {
    return "soy";
}

void soy::print(std::ostream& out) const {
    out << "s";
}





//black
int black::getCardsPerCoin(int coins) const {
    switch (coins) {
        case 1: return 2;
        case 2: return 4;
        case 3: return 5;
        case 4: return 6;
        default: return 0;
    }
}

std::string black::getName() const {
    return "black";
}

void black::print(std::ostream& out) const {
    out << "b";
}


//Red


int Red::getCardsPerCoin(int coins) const {
    switch (coins) {
        case 1: return 2;
        case 2: return 3;
        case 3: return 4;
        case 4: return 5;
        default: return 0;
    }
}

std::string Red::getName() const {
    return "Red";
}

void Red::print(std::ostream& out) const {
    out << "R";
}


//garden


int garden::getCardsPerCoin(int coins) const {
    switch (coins) {
        case 1: return 2;
        case 2: return 3;
        case 3: return 5;
        case 4: return 6;
        default: return 0;
    }
}

std::string garden::getName() const {
    return "garden";
}

void garden::print(std::ostream& out) const {
    out << "g";
}


