

#ifndef SEM_2_OUT_H
#define SEM_2_OUT_H

/**
 * This function determines the final saving location*
 * @return
 */

char        whereToSaveFinalSolution();

int         makeFinalSolution(std::string &out, std::string outFileName, char where);

/**
 * This function prepares the string
 * @param out       string with all information will be saved
 * @param where     char which tell where to save (T- terminal, C-csv file, H-html file)
 * @param what      int which say that to save (1-gem, 2-determinant, 4- roots, theirs sums says combinatoins of them)
 * @param determ    variable with determinant
 * @param triangle  triangle shape of matrix
 * @param matrix    matrix with... what the fuck?
 * @param roots     vector of roots
 */

void        prepareString           (std::string &out,
                                     char where,
                                     int what,
                                     long int &determ,
                                     std::vector<std::vector<double> > &triangle,
                                     std::vector<std::vector<double> > &matrix,
                                     std::vector<double> &roots);

#endif //SEM_2_OUT_H
