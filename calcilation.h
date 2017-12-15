

#ifndef SEM_2_CALCILATION_H
#define SEM_2_CALCILATION_H

#include<vector>

/**
 * This function calculates GEM
 * @param matrix    dereference for matrix with the data
 * @return
 */

int         gem         (std::vector< std::vector <double> > &matrix);


/**
 * This function calculates determinant of the matrix
 * @param matrix    dereference for matrix with the data
 * @param determ
 * @return
 */
long int    determinant (std::vector< std::vector <double> > &matrix, long int &determ);
int         det         (std::vector< std::vector <double> > &matrix);

/**
 * This function returns the real roots of the matrix
 * @param matrix    dereference for matrix with the data
 * @param roots
 * @return
 */

int         root        (std::vector< std::vector <double> > &matrix, std::vector<double > &roots);

/**
 * This function asks about saving requirements
 * @return
 */

int         whatToSave  ();
#endif //SEM_2_CALCILATION_H
