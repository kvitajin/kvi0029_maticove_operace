

#ifndef SEM_2_CALCILATION_H
#define SEM_2_CALCILATION_H
#include<vector>

int         gem(std::vector< std::vector <double> > &matice);              //TODO pridat druhou matici s vysledkem;
long int    determinant(std::vector< std::vector <double> > &matice, long int &determ);
int         det(std::vector< std::vector <double> > &matice);
int         roots(std::vector< std::vector <double> > &matice, std::vector<double > &roots);
#endif //SEM_2_CALCILATION_H
