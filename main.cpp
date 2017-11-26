#include <iostream>
#include "funkce.h"

int main() {
    char pismeno;
    menu();
    pismeno=odkudCtu();
    while (pismeno=='E') {
       pismeno=odkudCtu();
    }

    if (pismeno == 'S') {
        //soubor();           //TODO
    } else if (pismeno == 'T') {
        //terminal();       //TODO
    } else if (pismeno == 'X') {
        paticka();
        return 0;
    } else {
        odkudCtu();

    return 0;
}