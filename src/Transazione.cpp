#include "Transazione.h"
#include <sstream>

Transazione::Transazione(const std::string& desc, double imp, const std::string& dt)
    : descrizione(desc), importo(imp), data(dt) {}

std::string Transazione::getDescrizione() const {
    return descrizione;
}

double Transazione::getImporto() const {
    return importo;
}

std::string Transazione::getData() const {
    return data;
}

std::string Transazione::toString() const { 
    return data + ";" + descrizione + ";" + std::to_string(importo);
}



Transazione Transazione::fromString(const std::string& riga) {  
    std::istringstream iss(riga); 
    std::string data, descrizione, importoStr;
    std::getline(iss, data, ';'); 
    std::getline(iss, descrizione, ';');
    std::getline(iss, importoStr); 
    double importo = std::stod(importoStr); 
    return Transazione(descrizione, importo, data);
}
