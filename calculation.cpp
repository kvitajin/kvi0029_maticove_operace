
#include <vector>
#include <iostream>
#include "funkce.h"
#include <iomanip>
using namespace std;

int gem(std::vector< std::vector <double> > &matice){

    auto n = (int)matice.size();

    for (int a = 0; a < n; ++a) {
        //printMatrix(matice);
        bool found = false;
        for (int b = a; b < n; ++b) {
            if (matice[b][a]) {
                if (b != a) {
                    matice[b].swap(matice[a]);
                    //printMatrix(matice);
                }
                found = true;
                break;
            }
        }

        if (!found) {
            return 0;
        }

        for (int b = a + 1; b < n; ++b) {
            while (true) {
                double del = matice[b][a] / matice[a][a];                               ///coefficient for making triangle shape
                for (int c = a; c < n+1; ++c) {                                         ///n+1 for matching with right side of matrix
                    matice[b][c] -= del * matice[a][c];
                }
                if (matice[b][a] == 0) {                                                ///after previews loop it have to be 0, if it isn't
                    break;
                } else {
                    matice[b].swap(matice[a]);
                    //printMatrix(matice);
                }
            }
        }
    }
}
long int determinant(std::vector< std::vector <double> > &matrix, long int &determ){
    determ = 1;
    auto n= (int)matrix.size();
    for(int i = 0; i < n; ++i) {
        determ *= matrix[i][i];
    }
    return abs(determ);
}
int det(std::vector<std::vector<double> > &matrix) {

    auto n = (int)matrix.size();

    for (int a = 0; a < n; ++a) {
        printMatrix(matrix);
        bool found = false;
        for (int b = a; b < n; ++b) {
            if (matrix[b][a]) {
                if (b != a) {
                    matrix[b].swap(matrix[a]);
                    printMatrix(matrix);
                }
                found = true;
                break;
            }
        }

        if (!found) {
            return 0;
        }

        for (int b = a + 1; b < n; ++b) {
            while (true) {
                double del = matrix[b][a] / matrix[a][a];                               ///coefficient for making triangle shape
                for (int c = a; c < n+1; ++c) {                                         ///n+1 for matching with right side of matrix
                    matrix[b][c] -= del * matrix[a][c];
                }
                if (matrix[b][a] == 0) {                                                ///after previews loop it have to be 0, if it isn't
                    break;
                } else {
                    matrix[b].swap(matrix[a]);
                    printMatrix(matrix);
                }
            }
        }
    }

    std::cout   <<  "koreny "    << n   <<  std::endl;
    --n;
    std::vector<double > roots;
    double tmp;
    int i=0;
    for (i = 0; i < matrix.size()-1; ++i) {
        tmp=matrix[n-i][n+1]/matrix[n-i][n-i];                                            /// making root and beging on the end
        roots.push_back(tmp);
        std::cout   <<  "tmp "   <<  tmp    <<    " "  <<  n-i  << std::endl;
        for (int j = i+1; j < matrix.size(); ++j) {
            matrix[n-j][n+1]-=matrix[n-j][n-i]*tmp;
            matrix[n-j][n-i]=0;

        }
    }
    tmp=matrix[0][n+1]/matrix[0][0];                                            /// making root and beging on the end
    roots.push_back(tmp);
    printMatrix(matrix);
    auto g=(int)roots.size();
    for (int k = 0; k < g+1; ++k) {
        std::cout   <<  roots[g-k] <<   " ";
    }
}
int root    (std::vector< std::vector <double> > &matrix,std::vector<double > &roots){
    int n=(int)matrix.size()-1;


    double tmp;
    int i=0;
    for (i = 0; i < matrix.size()-1; ++i) {
        tmp=matrix[n-i][n+1]/matrix[n-i][n-i];                                            /// making root and beging on the end
        roots.push_back(tmp);
        //std::cout   <<  "tmp "   <<  tmp    <<    " "  <<  n-i  << std::endl;
        for (int j = i+1; j < matrix.size(); ++j) {
            matrix[n-j][n+1]-=matrix[n-j][n-i]*tmp;
            matrix[n-j][n-i]=0;

        }
    }
    tmp=matrix[0][n+1]/matrix[0][0];                                            /// making root and beging on the end
    roots.push_back(tmp);
    printMatrix(matrix);
    /*auto g=(int)roots.size();
    for (int k = 0; k < g+1; ++k) {
        std::cout   <<  roots[g-k] <<   " ";
    }*/
}
int whatToSave(){
    int tmp=0;
    std::cout   <<  "================================="<< std::endl;
    std::cout   <<  "Co chcete ulozit?"<< std::endl;
    std::cout   <<  "Pro kombinace cisla scitejte"<< std::endl;
    std::cout   <<  "1 - GEM"<< std::endl;
    std::cout   <<  "2 - Determinant"<< std::endl;
    std::cout   <<  "4 - Koreny"<< std::endl;
    std::cout   <<  "================================="<< std::endl;
    std::cin    >>  tmp;
    if (std::cin.fail() ||
        tmp<1           ||
        tmp>7){
        std::cin.clear();
        std::cin.ignore();

        return 0;
    } else{
        return tmp;
    }
}