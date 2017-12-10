

#ifndef SEM_2_FUNKCE_H
#define SEM_2_FUNKCE_H

#include <vector>
#include <string>
/********************************************/
/**              entrance menu             **/
/********************************************/
void        menu();
/********************************************/
/** This function returns the input stream **/
/********************************************/
char        odkudCtu();

void        footer();

/**************************************************************/
/** This function loads size of the matrix from the terminal.**/
/**************************************************************/
void        velikostMatice          (int &radku, int &sloupcu);

/***************************************************/
/** This function creates matrix of required size.**/
/***************************************************/

void        makeMatrix              (const int radku,
                                     const int sloupcu,
                                     std::vector<std::vector<double> > &matrix);

/**********************************************/
/** This function enters the input file name**/
/**********************************************/

std::string inFileName                ();                 //todo

/***********************************************************/
/** This function verifies the sufix and adds it if needed**/
/***********************************************************/


std::string overPriponu             (std::string &jmeno);
/***************************************************************/
/** This function discovers the delimiter used in the csv file**/
/***************************************************************/



char        fileDelimiterFunction   (char &delimiter);

/**********************************************************************/
/** This function manages other functions while loading from the file**/
/**********************************************************************/

int         fileBranch              (std::vector< std::vector <double> > &matrix);

/*****************************************************************************/
/** This function loads numbers from terminal and saves them into the matrix**/
/*****************************************************************************/

int         terminalFillMatrix      (std::vector< std::vector <double> > &matrix);

/**************************************************************************/
/** This function manages other functions while loading from the terminal**/
/**************************************************************************/

int         terminalBranch          (std::vector< std::vector <double> > &matrix);

/*******************************/
/** This function print matrix**/
/*******************************/

void        printMatrix             (std::vector< std::vector <double> > &matrix);

/****************************************************/
/** This function loads the size of required matrix**/
/****************************************************/



void        fileParseSizeOfMatrix   (std::string &radek,
                                     int &errFlag,
                                     char &delimiter,
                                     int &rows,
                                     int &columns);

/******************************************************************************/
/** This function loads one line from the file and inserts it into the matrix**/
/******************************************************************************/


int         fileFillLineOfMatrix    (std::string &radek,
                                     std::vector<std::vector<double> > &matrix,
                                     const int i,
                                     char &delimiter);

/***************************************/
/** This function manages file loading**/
/***************************************/

int         fileRead                (std::string &filename,
                                     int &errFlag,
                                     char &delimiter,
                                     std::vector<std::vector<double> > &matrix);

/**********************************************/
/** This function enters the output file name**/
/**********************************************/

std::string outFileName                ();




#endif //SEM_2_FUNKCE_H
