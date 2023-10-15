#pragma once

#include <iostream>

#include "Muziekstuk.h"

class A_Capella : public Muziekstuk {
public:
    A_Capella(char* titel, char* componist);
    virtual ~A_Capella();

    void uitvoeren();
};
