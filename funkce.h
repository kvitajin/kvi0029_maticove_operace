

#ifndef SEM_2_FUNKCE_H
#define SEM_2_FUNKCE_H

#include <vector>
#include <string>

void        menu();
char        odkudCtu();
void        footer();
void        velikostMatice          (int &radku, int &sloupcu);
void        makeMatrix              (const int radku,
                                     const int sloupcu,
                                     std::vector<std::vector<double> > &matrix);

std::string filename                ();
std::string overPriponu             (std::string &jmeno);

char        fileDelimiterFunction   (char &delimiter);

int         fileBranch              (std::vector< std::vector <double> > &matrix);
int         terminalFillMatrix      (std::vector< std::vector <double> > &matrix);
int         terminalBranch          (std::vector< std::vector <double> > &matrix);
void        printMatrix             (std::vector< std::vector <double> > &matrix);
void        fileParseSizeOfMatrix   (std::string &radek,
                                     int &errFlag,
                                     char &delimiter,
                                     int &rows,
                                     int &columns);
int         fileFillLineOfMatrix    (std::string &radek,
                                     std::vector<std::vector<double> > &matrix,
                                     const int i,
                                     char &delimiter);
int         fileRead                (std::string &filename,
                                     int &errFlag,
                                     char &delimiter,
                                     std::vector<std::vector<double> > &matrix);
std::string fileName                ();




#endif //SEM_2_FUNKCE_H
