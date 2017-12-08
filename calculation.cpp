
#include <vector>
#include <iostream>
#include "funkce.h"

int gem(std::vector< std::vector <long double> > &matice){}              //TODO pridat druhou matici s vysledkem;
int determinant(){}
int det(std::vector<std::vector<long double> > &matice) {
    auto n = (int)matice.size();

    for (int col = 0; col < n; ++col) {
        std::cout << "Column: " << col << "\n";
        printMatrix(matice);
        bool found = false;
        for (int row = col; row < n; ++row) {
            if (matice[row][col]) {
                std::cout << "Got non-zero value for row " << row << " and col " << col << "\n";
                if (row != col) {
                    std::cout << "(1) Swapping rows " << col << " and " << row << "\n";
                    matice[row].swap(matice[col]);
                    printMatrix(matice);
                } else {
                    std::cout << "Not swapping rows\n";
                }
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << "Did not find a non-zero row. Column: " << col << "\n";
            return 0;
        }

        for (int row = col + 1; row < n; ++row) {
            while (true) {
                long double del = matice[row][col] / matice[col][col];
                std::cout << "del: " << del << "\n";
                for (int j = col; j < n; ++j) {
                    matice[row][j] -= del * matice[col][j];
                }
                if (matice[row][col] == 0) {
                    break;
                } else {
                    std::cout << "(2) Swapping rows " << col << " and " << row << "\n";
                    matice[row].swap(matice[col]);
                    printMatrix(matice);
                }
            }
        }
    }
    printMatrix(matice);
    long determ = 1;

    for(int i = 0; i < n; ++i) {
        determ *= matice[i][i];
    }
    std::cout   <<  abs(determ);

    return abs(determ);
}