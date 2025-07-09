//
// Created by leona on 07/07/2025.
//
#ifndef CONTOCORRENTE_HPP
#define CONTOCORRENTE_HPP
#include "Transazione.h"
#include <vector>
#include <string>

class ContoCorrente {
private:
    std::vector<Transazione> transazioni;

public:
    void aggiungiTransazione(const Transazione& t);
    double saldo() const;

    void salvaSuFile(const std::string& nomeFile) const;
    void caricaDaFile(const std::string& nomeFile);
};

#endif // CONTOCORRENTE_HPP