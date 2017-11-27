#include <iostream>
#include <vector>
#include "funkce.h"

int main() {
    char pismeno;
    int radku=0, sloupcu=0;
    std::vector< std::vector <int> > matice;
    menu();
    pismeno=odkudCtu();
    while (pismeno=='E') {
       pismeno=odkudCtu();
    }

    if (pismeno == 'S') {
        souborVetev();           //TODO
    } else if (pismeno == 'T') {
        //terminalVetev();       //TODO
    } else if (pismeno == 'X') {
        paticka();
        return 0;
    } else {
        odkudCtu();
    }


    /*velikostMatice(radku, sloupcu);
    vytvorMatici(radku, sloupcu, matice);*/
    return 0;
}