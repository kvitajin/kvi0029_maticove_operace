#include <iostream>
#include <vector>
#include "funkce.h"
#include "out.h"
#include "calcilation.h"

int main() {
    char pismeno;
    long int determ;
    int radku=0, sloupcu=0;
    std::vector< std::vector <double> > matice;
    std::vector<double > roots;
    menu();
    pismeno=odkudCtu();
    while (pismeno=='E') {
       pismeno=odkudCtu();
    }

    if (pismeno == 'S') {
        fileBranch(matice);
        gem(matice);
        determinant(matice, determ);
        roots(matice, roots);
    } else if (pismeno == 'T') {
        terminalBranch(matice);       //TODO
        gem(matice);
        determinant(matice, determ);
        roots(matice, roots);
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
        //fileFinalSolution();
    } else if (pismeno == 'T') {
    }*/

    /*velikostMatice(radku, sloupcu);
    makeMatrix(radku, sloupcu, matice);*/
    return 0;
}