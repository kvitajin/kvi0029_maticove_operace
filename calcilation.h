

#ifndef SEM_2_CALCILATION_H
#define SEM_2_CALCILATION_H
#include<vector>

int         gem         (std::vector< std::vector <double> > &matrix);
long int    determinant (std::vector< std::vector <double> > &matrix, long int &determ);
int         det         (std::vector< std::vector <double> > &matrix);
int         root        (std::vector< std::vector <double> > &matrix, std::vector<double > &roots);
int         whatToSave  ();
#endif //SEM_2_CALCILATION_H
