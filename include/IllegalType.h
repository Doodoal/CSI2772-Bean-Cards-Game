#ifndef ILLEGALTYPE_H
#define ILLEGALTYPE_H

#include <exception>
#include <string>

// Classe d'exception pour les types illégaux
class IllegalType : public std::exception {
public:
    // Renvoie le message d'erreur
    const char* what() const noexcept override {
        return "Illegal type added to the chain.";
    }
};

#endif // ILLEGALTYPE_H
