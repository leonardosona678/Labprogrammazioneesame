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

void ContoCorrente::salvaSuFile(const std::string& nomeFile) const { //Salva ogni transazione in una riga del file, in formato testo. Così potremo leggerle successivamente con la funzione caricaDaFile.
    std::ofstream out(nomeFile); //Crea un oggetto chiamato out che apre (o crea) il file indicato da nomeFile. Funziona come std::cout, ma invece che stampare a schermo, scrive dentro un file
    if (!out) { //Se il file esiste, viene sovrascritto. Se non esiste, viene creato
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
    while (std::getline(in, linea)) { //Finché riesco a leggere una riga dal file in (che è uno std::ifstream (file di input), la salvo nella variabile linea e continuo il ciclo.
        if (!linea.empty()) {
            transazioni.push_back(Transazione::fromString(linea)); //Usa la funzione fromString() per convertire la riga di testo in una transazione vera e propria.
        }
    }
}