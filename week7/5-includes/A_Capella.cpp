#include "A_Capella.h"

A_Capella::A_Capella(char* titel, char* componist): Muziekstuk(titel, componist) {}
A_Capella::~A_Capella() { /* dtor */ }

void A_Capella::uitvoeren() {
    std::cout << "Het stuk " << titel << " van " << componist << " wordt gezongen.\n";
}
