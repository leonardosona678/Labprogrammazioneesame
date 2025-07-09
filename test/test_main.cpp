//
// Created by leona on 08/07/2025.
#include "ContoCorrente.h"
#include "Transazione.h"
#include <gtest/gtest.h>

TEST(ContoCorrenteTest, SaldoCorretto) {
    ContoCorrente conto;
    conto.aggiungiTransazione(Transazione("Deposito", 100.0, "2025-07-01"));
    conto.aggiungiTransazione(Transazione("Prelievo", -30.0, "2025-07-02"));
    EXPECT_DOUBLE_EQ(conto.saldo(), 70.0);
}

TEST(TransazioneTest, ConversioneStringa) {
    Transazione t("Pagamento bolletta", -50.0, "2025-07-03");
    std::string s = t.toString();
    Transazione t2 = Transazione::fromString(s);
    EXPECT_EQ(t2.getDescrizione(), t.getDescrizione());
    EXPECT_DOUBLE_EQ(t2.getImporto(), t.getImporto());
    EXPECT_EQ(t2.getData(), t.getData());
}

