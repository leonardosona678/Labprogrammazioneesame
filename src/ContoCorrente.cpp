//
// Created by leona on 07/07/2025.
//
#include "ContoCorrente.h"
#include <fstream>
#include <iostream>

void ContoCorrente::aggiungiTransazione(const Transazione& t) {
    transazioni.push_back(t);
}

double ContoCorrente::saldo() const {
    double totale = 0.0;
    for (const auto& t : transazioni) {
        totale += t.getImporto();
    }
    return totale;
}
void ContoCorrente::salvaSuFile(const std::string& nomeFile) const { 
    std::ofstream out(nomeFile); 
    if (!out) {
        std::cerr << "Errore nell'apertura del file per la scrittura.\n";
        return;
    }
    for (const auto& t : transazioni) {
        out << t.toString() << "\n";
    }
}

void ContoCorrente::caricaDaFile(const std::string& nomeFile) {
    std::ifstream in(nomeFile); 
    if (!in) {
        std::cerr << "File non trovato: " << nomeFile << "\n";
        return;
    }
    transazioni.clear();
    std::string linea;
    while (std::getline(in, linea)) { 
        if (!linea.empty()) {
            transazioni.push_back(Transazione::fromString(linea)); 
        }
    }
}