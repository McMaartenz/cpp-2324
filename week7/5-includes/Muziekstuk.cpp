#include "Muziekstuk.h"

Muziekstuk::Muziekstuk(char* titel, char* componist) : titel(titel), componist(componist) {}
Muziekstuk::~Muziekstuk() { /* dtor */ }

void Muziekstuk::uitvoeren() {
    std::cout << "Het stuk " << titel << " van " << componist << " wordt gespeeld.\n";
}
