#include <iostream>
#include <cstdlib>

#include "5-includes/Muziekstuk.h"
#include "5-includes/A_Capella.h"

int main(int argc, char** argv) {
    Muziekstuk stuk{"Mountains", "Hans Zimmer"};
    A_Capella zang{"Destroyer of Worlds", "Hans Zimmer"};

    stuk.uitvoeren();
    zang.uitvoeren();
    return EXIT_SUCCESS;
}
