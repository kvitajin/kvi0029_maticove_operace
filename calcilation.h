

#ifndef SEM_2_CALCILATION_H
#define SEM_2_CALCILATION_H
#include<vector>


/********************************/
/** This function calculates GEM**/
/********************************/

int         gem         (std::vector< std::vector <double> > &matrix);

/*******************************************************/
/** This function calculates determinant of the matrix**/
/*******************************************************/
long int    determinant (std::vector< std::vector <double> > &matrix, long int &determ);
int         det         (std::vector< std::vector <double> > &matrix);

/*******************************************************/
/** This function returns the real roots of the matrix**/
/*******************************************************/

int         root        (std::vector< std::vector <double> > &matrix, std::vector<double > &roots);

/*************************************************/
/** This function asks about saving requirements**/
/*************************************************/

int         whatToSave  ();
#endif //SEM_2_CALCILATION_H
