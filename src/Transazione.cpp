#include "Transazione.h"
#include <sstream>

Transazione::Transazione(const std::string& desc, double imp, const std::string& dt)
    : descrizione(desc), importo(imp), data(dt) {}
//simula aggiunta funzione per gitgui
std::string Transazione::getDescrizione() const {
    return descrizione;
}

double Transazione::getImporto() const {
    return importo;
}

std::string Transazione::getData() const {
    return data;
}

std::string Transazione::toString() const { //per restituire la stringa di una transazione
    return data + ";" + descrizione + ";" + std::to_string(importo);
}
//aggiungo commit


Transazione Transazione::fromString(const std::string& riga) { //per convertire una riga di testo (ad esempio letta da un file) in un oggetto Transazione
    std::istringstream iss(riga); //Crea un stream di input dalla stringa riga.
    std::string data, descrizione, importoStr;
    std::getline(iss, data, ';'); //Legge dalla stringa fino al primo ; e assegna a data.
    std::getline(iss, descrizione, ';');// Legge la seconda parte fino al secondo ;
    std::getline(iss, importoStr); // //Legge tutto quello che resta nella stringa:
    double importo = std::stod(importoStr); //Converte la stringa "–50.0" in un double
    return Transazione(descrizione, importo, data);
}
