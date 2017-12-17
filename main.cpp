#include <iostream>
#include <vector>
#include "funkce.h"
#include "out.h"
#include "calcilation.h"

int main() {
    long int determ;
    int radku=0, sloupcu=0, flag=0, tmp=0;
    std::string out;
    std::vector< std::vector <double> > matrix;
    std::vector< std::vector <double> > triangle;
    std::vector<double > roots;

    struct info{                                        ///Here the basic programme information is saved
        char read='E';
        char where='X';
        int what=0;
        std::string outFilename="ecrtmek";
    };
    info Info;


    menu();

    while (Info.read=='E') {
        Info.read=odkudCtu();
        if (Info.read=='X'){
            footer();
            ++flag;
            break;
        }
    }
    if (flag){
        return 0;
    }
    while (Info.where=='X'){
        Info.where=whereToSaveFinalSolution();
    }
    while (Info.what==0){
        Info.what=whatToSave();
    }
    if(Info.where=='C'||Info.where=='H') {
        while (Info.outFilename == "ecrtmek") {
            Info.outFilename = outFileName();
        }
    }
    if (Info.read == 'S') {
        fileBranch(matrix);
        gem(matrix);
        triangle=matrix;
        determinant(matrix, determ);
        root(matrix, roots);
    } else if (Info.read == 'T') {
        terminalBranch(matrix);
        gem(matrix);
        triangle=matrix;
        determinant(matrix, determ);
        root(matrix, roots);
    } else if (Info.read == 'X') {
        footer();
        return 0;
    } else {
        return 1;
    }
    prepareString(out, Info.where, Info.what, determ, triangle, matrix, roots);

    if (Info.where == 'T') {
        std::cout   <<  out;

    } else if (Info.where == 'C' || Info.where=='H') {
        tmp=makeFinalSolution(out, Info.outFilename, Info.where);
        return tmp;
    }

    footer();

    return 0;
}