

#ifndef SEM_2_FUNKCE_H
#define SEM_2_FUNKCE_H

#include <vector>
#include <string>

/**
 * Entrance menu
 */
void        menu();

/**
 * This function returns the input stream
 * @return returns T for terminal input, F for file input, E for exit and X for error
 */

char        odkudCtu();

void        footer();

/**
 * This function loads size of the matrix from the terminal.
 * @param rows      number of rows for required matrix
 * @param columns   number of columns for required matrix
 */

void        velikostMatice          (int &rows,
                                     int &columns);


/**
 * This function creates matrix of required size.
 * @param rows      number of rows for required matrix
 * @param columns   number of columns for required matrix
 * @param matrix    dereference for matrix with the data
 */

void        makeMatrix              (const int &rows,
                                     const int &columns,
                                     std::vector<std::vector<double> > &matrix);

/**
 * This function enters the input file name
 * @return          returns name of input file
 */

std::string inFileName                ();

/**
 * This function verifies the sufix and adds it if needed
 * @param name      filename
 * @return          filename with the sufix
 */

std::string overPriponu             (std::string &name);

/**
 * This function discovers the delimiter used in the csv file
 * @param delimiter     empty variable for save delimiter
 * @return              delimiter
 */

char        fileDelimiterFunction   (char &delimiter);



/**
 * This function manages other functions while loading from the file
 * @param matrix    dereference of matrix with the data
 */

void         fileBranch              (std::vector< std::vector <double> > &matrix);

/**
 * This function loads numbers from terminal and saves them into the matrix
 * @param matrix    dereference of matrix with the data
 */

int         terminalFillMatrix      (std::vector< std::vector <double> > &matrix);

/**
 * This function manages other functions while loading from the terminal
 * @param matrix    dereference of matrix with the data
 */

void         terminalBranch          (std::vector< std::vector <double> > &matrix);

/**
 * This function print matrix
 * @param matrix    dereference of matrix with the data
 */

void        printMatrix             (std::vector< std::vector <double> > &matrix);

/**
 * This function loads the size of required matrix
 * @param line          one line of matrix from .csv file
 * @param errFlag       flag reporting errors
 * @param delimiter     delimiter char
 * @param rows          number of rows for required matrix
 * @param columns       number of columns for required matrix
 */

void        fileParseSizeOfMatrix   (std::string &line,
                                     int &errFlag,
                                     char &delimiter,
                                     int &rows,
                                     int &columns);

/**
 * This function loads one line from the file and inserts it into the matrix
 * @param line      char line of matrix got from .csv file
 * @param matrix    dereference of matrix with the data
 * @param row       number of row in matrix (index bagin on 0)
 * @param delimiter delimiter char
 */


void         fileFillLineOfMatrix    (std::string &line,
                                     std::vector<std::vector<double> > &matrix,
                                     const int &row,
                                     char &delimiter);

/**
 * This function manages file loading
 * @param filename  name of the opened file
 * @param errFlag   flag reporting errors
 * @param delimiter delimiter char
 * @param matrix    dereference of matrix with the data
 * @return          0 for success, 1 for error
 */

int         fileRead                (std::string &filename,
                                     int &errFlag,
                                     char &delimiter,
                                     std::vector<std::vector<double> > &matrix);


/**
 * This function enters the output file name
 * @return          0 for success, 1 for error
 */

std::string outFileName                ();




#endif //SEM_2_FUNKCE_H
