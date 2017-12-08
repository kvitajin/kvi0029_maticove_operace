
#include <vector>
#include <iostream>
#include "funkce.h"
#include <iomanip>
using namespace std;

int gem(std::vector< std::vector <double> > &matice){

    auto n = (int)matice.size();

    for (int a = 0; a < n; ++a) {
        printMatrix(matice);
        bool found = false;
        for (int b = a; b < n; ++b) {
            if (matice[b][a]) {
                if (b != a) {
                    matice[b].swap(matice[a]);
                    printMatrix(matice);
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
                    printMatrix(matice);
                }
            }
        }
    }
}
long int determinant(std::vector< std::vector <double> > &matice, long int &determ){
    determ = 1;
    auto n= (int)matice.size();
    for(int i = 0; i < n; ++i) {
        determ *= matice[i][i];
    }
    return abs(determ);
}
int det(std::vector<std::vector<double> > &matice) {

    auto n = (int)matice.size();

    for (int a = 0; a < n; ++a) {
        printMatrix(matice);
        bool found = false;
        for (int b = a; b < n; ++b) {
            if (matice[b][a]) {
                if (b != a) {
                    matice[b].swap(matice[a]);
                    printMatrix(matice);
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
                    printMatrix(matice);
                }
            }
        }
    }

    std::cout   <<  "koreny "    << n   <<  std::endl;
    --n;
    std::vector<double > roots;
    double tmp;
    int i=0;
    for (i = 0; i < matice.size()-1; ++i) {
        tmp=matice[n-i][n+1]/matice[n-i][n-i];                                            /// making root and beging on the end
        roots.push_back(tmp);
        std::cout   <<  "tmp "   <<  tmp    <<    " "  <<  n-i  << std::endl;
        for (int j = i+1; j < matice.size(); ++j) {
            matice[n-j][n+1]-=matice[n-j][n-i]*tmp;
            matice[n-j][n-i]=0;

        }
    }
    tmp=matice[0][n+1]/matice[0][0];                                            /// making root and beging on the end
    roots.push_back(tmp);
    printMatrix(matice);
    int g=(int)roots.size();
    for (int k = 0; k < g+1; ++k) {
        std::cout   <<  roots[g-k] <<   " ";
    }
}
int roots(std::vector< std::vector <double> > &matice,std::vector<double > &roots){
    int n=(int)matice.size()-1;


    double tmp;
    int i=0;
    for (i = 0; i < matice.size()-1; ++i) {
        tmp=matice[n-i][n+1]/matice[n-i][n-i];                                            /// making root and beging on the end
        roots.push_back(tmp);
        //std::cout   <<  "tmp "   <<  tmp    <<    " "  <<  n-i  << std::endl;
        for (int j = i+1; j < matice.size(); ++j) {
            matice[n-j][n+1]-=matice[n-j][n-i]*tmp;
            matice[n-j][n-i]=0;

        }
    }
    tmp=matice[0][n+1]/matice[0][0];                                            /// making root and beging on the end
    roots.push_back(tmp);
    printMatrix(matice);
    int g=(int)roots.size();
    /*for (int k = 0; k < g+1; ++k) {
        std::cout   <<  roots[g-k] <<   " ";
    }*/
}