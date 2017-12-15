

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
 * @param out
 * @param where
 * @param what
 * @param determ
 * @param triangle
 * @param matrix
 * @param roots
 */

void        prepareString           (std::string &out,
                                     char where,
                                     int what,
                                     long int &determ,
                                     std::vector<std::vector<double> > &triangle,
                                     std::vector<std::vector<double> > &matrix,
                                     std::vector<double> &roots);

#endif //SEM_2_OUT_H
