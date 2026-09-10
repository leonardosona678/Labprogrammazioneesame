#include "ContoCorrente.h"
#include <iostream>
#include <limits>
#include <string>

int leggiSceltaUtente() {
    int scelta;
    if (!(std::cin >> scelta)) {
        throw std::runtime_error("Input non valido: atteso un valore numerico.");
    }
    if (scelta < 0 || scelta > 4) {
        throw std::out_of_range("Scelta non valida: seleziona un'opzione tra 0 e 4.");
    }
    return scelta;
}

void mostraMenu() {
    std::cout << "\n--- GESTIONE CONTO CORRENTE ---\n"
              << "1. Aggiungi transazione\n"
              << "2. Mostra saldo\n"
              << "3. Salva su file\n"
              << "4. Carica da file\n"
              << "0. Esci\n"
              << "Scelta: ";
}

int main() {
    ContoCorrente conto;
    int scelta = -1;

    do {
        mostraMenu();
        try {
            scelta = leggiSceltaUtente();
        } catch (const std::exception& e) {
            std::cerr << "Errore: " << e.what() << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (scelta) {
            case 1: {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::string descrizione, data;
                double importo;

                std::cout << "Descrizione: ";
                std::getline(std::cin, descrizione);

                std::cout << "Importo (positivo = deposito, negativo = prelievo): ";
                while (!(std::cin >> importo)) {
                    std::cerr << "Importo non valido. Riprova: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Data (YYYY-MM-DD): ";
                std::getline(std::cin, data);

                conto.aggiungiTransazione(Transazione(descrizione, importo, data));
                std::cout << "Transazione registrata con successo.\n";
                break;
            }
            case 2:
                std::cout << "Saldo attuale: " << conto.saldo() << " EUR\n";
                break;

            case 3: {
                std::string nomeFile;
                std::cout << "Nome file per il salvataggio: ";
                std::cin >> nomeFile;
                conto.salvaSuFile(nomeFile);
                std::cout << "Dati salvati.\n";
                break;
            }
            case 4: {
                std::string nomeFile;
                std::cout << "Nome file da caricare: ";
                std::cin >> nomeFile;
                conto.caricaDaFile(nomeFile);
                std::cout << "Dati caricati.\n";
                break;
            }
            case 0:
                std::cout << "Chiusura applicazione.\n";
                break;
        }
    } while (scelta != 0);

    return 0;
}