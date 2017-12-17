

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
 * @param determ    empty variable for saving determinant
 * @return          returns calculated determinant of the matrix
 */
long int    determinant (std::vector< std::vector <double> > &matrix, long int &determ);

/**
 * This function returns the real roots of the matrix
 * @param matrix    dereference for matrix with the data
 * @param roots     vector of roots of the matrix
 * @return
 */

int         root        (std::vector< std::vector <double> > &matrix, std::vector<double > &roots);

/**
 * This function asks about saving requirements
 * @return          returns number which says what to save (1-gem, 2-determinant, 4- roots, theirs sums says combinatoins of them)
 */

int         whatToSave  ();
#endif //SEM_2_CALCILATION_H
