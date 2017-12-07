#include <iostream>
#include <vector>
#include "funkce.h"
#include "out.h"
#include "calcilation.h"

int main() {
    char pismeno;
    int radku=0, sloupcu=0;
    std::vector< std::vector <long double> > matice;
    menu();
    pismeno=odkudCtu();
    while (pismeno=='E') {
       pismeno=odkudCtu();
    }

    if (pismeno == 'S') {
        fileBranch(matice);           //TODO
        det(matice);
    } else if (pismeno == 'T') {
        terminalBranch(matice);       //TODO
    } else if (pismeno == 'X') {
        footer();
        return 0;
    } else {
        odkudCtu();
    }

  /*  pismeno=whereToSaveFinalSolution();
    while (pismeno=='X'){
        pismeno=whereToSaveFinalSolution();
    }
    if (pismeno == 'S') {
        //fileFinalSolution();           //TODO
    } else if (pismeno == 'T') {
    }*/

    /*velikostMatice(radku, sloupcu);
    makeMatrix(radku, sloupcu, matice);*/
    return 0;
}