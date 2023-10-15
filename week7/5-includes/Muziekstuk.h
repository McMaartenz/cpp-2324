#pragma once

#include <iostream>

class Muziekstuk {
public:
    Muziekstuk(char* title, char* componist);
    virtual ~Muziekstuk();

    virtual void uitvoeren();

protected:
    char* titel;
    char* componist;
};
