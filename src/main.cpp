#include "ContoCorrente.h"
#include <iostream>
#include <limits>
int leggiSceltaUtente() {
    int scelta;
    if (!(std::cin >> scelta)) {
        throw std::runtime_error("Input non valido: atteso un numero intero.");
    }
    if (scelta < 0 || scelta > 4) {
        throw std::runtime_error("Scelta fuori dal range consentito (0–4).");
    }
    return scelta;
}
// Simulazione modifica per versionamento

void mostraMenu() {
    std::cout << "\n--- MENU ---\n";
    std::cout << "1. Aggiungi transazione\n";
    std::cout << "2. Mostra saldo\n";
    std::cout << "3. Salva su file\n";
    std::cout << "4. Carica da file\n";
    std::cout << "0. Esci\n";
    std::cout << "Scelta: ";
}

int main() {
    ContoCorrente conto;
    int scelta;

    do {
        mostraMenu();
        try {
            scelta = leggiSceltaUtente();
        } catch (const std::exception& e) {
            std::cerr << "Errore: " << e.what() << std::endl;
            // Pulisce lo stato di errore e ignora il resto della riga per evitare loop infiniti
            std::cin.clear();
            std::cin.ignore(1000, '\n');;
            continue; // torna all'inizio del ciclo
        }




        switch (scelta) {
            case 1: {
                std::string descrizione, data;
                double importo;

                std::cin.ignore(); // pulisce il newline (\n) rimasto, lasciato da cin

                std::cout << "Descrizione: ";
                std::getline(std::cin, descrizione);
                //Questa istruzione legge un'intera riga di input da tastiera
                //(standard input) e la memorizza nella variabile descrizione di tipo std::string.
                //std::cin >> descrizione; leggerebbe solo la prima parola, invece getline() legge l'intera riga fino a \n, spazi compresi

                std::cout << "Importo (positivo = deposito, negativo = prelievo): ";
                std::cin >> importo;
                std::cin.ignore();

                std::cout << "Data (YYYY-MM-DD): ";
                std::getline(std::cin, data);

                Transazione t(descrizione, importo, data);
                conto.aggiungiTransazione(t);
                std::cout << "Transazione aggiunta.\n";
                break;
            }
            case 2:
                std::cout << "Saldo attuale: " << conto.saldo() << " €\n";
                break;

            case 3: {
                std::string nomeFile;
                std::cout << "Nome file per il salvataggio: ";
                std::cin >> nomeFile;
                conto.salvaSuFile(nomeFile);
                std::cout << "Dati salvati su file.\n";
                break;
            }

            case 4: {
                std::string nomeFile;
                std::cout << "Nome file da caricare: ";
                std::cin >> nomeFile;
                conto.caricaDaFile(nomeFile);
                std::cout << "File caricato.\n";
                break;
            }

            case 0:
                std::cout << "Uscita...\n";
                break;


        }

    } while (scelta != 0);

    return 0;
}
