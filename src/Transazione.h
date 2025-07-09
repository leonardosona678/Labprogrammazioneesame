//
// Created by leona on 07/07/2025.
//
#ifndef TRANSAZIONE_HPP
#define TRANSAZIONE_HPP

#include <string>

class Transazione {
private:
    std::string descrizione;
    double importo;
    std::string data; // formato: "YYYY-MM-DD"

public:
    Transazione(const std::string& descrizione, double importo, const std::string& data);

    std::string getDescrizione() const;
    double getImporto() const;
    std::string getData() const;

    std::string toString() const;
    static Transazione fromString(const std::string& riga);
};

#endif // TRANSAZIONE_HPP
