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
        fileBranch();           //TODO
    } else if (pismeno == 'T') {
        terminalBranch();       //TODO
    } else if (pismeno == 'X') {
        footer();
        return 0;
    } else {
        odkudCtu();
    }


    /*velikostMatice(radku, sloupcu);
    makeMatrix(radku, sloupcu, matice);*/
    return 0;
}