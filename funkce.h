

#ifndef SEM_2_FUNKCE_H
#define SEM_2_FUNKCE_H

#include <vector>
#include <string>

void        menu();
char        odkudCtu();
void        footer();
void        velikostMatice(int &radku, int &sloupcu);
void        makeMatrix(const int radku, const int sloupcu, std::vector<std::vector<long double> > &matice);

std::string filename();
std::string overPriponu(std::string &jmeno);

char        fileDelimiterFunction(char &delimiter);
int         fileBranch(std::vector< std::vector <long double> > &matice);
int         terminalFillMatrix(std::vector< std::vector <long double> > &matice);
int         terminalBranch(std::vector< std::vector <long double> > &matice);
void        printMatrix(std::vector< std::vector <long double> > &matice);
void        fileParseSizeOfMatrix(std::string &radek, int &errFlag, char &delimiter, int &rows, int &columns);
int         fileFillLineOfMatrix(std::string &radek, std::vector<std::vector<long double> > &matice, const int i, char &delimiter);
int         fileRead(std::string &filename, int &errFlag, char &delimiter, std::vector<std::vector<long double> > &matice);




#endif //SEM_2_FUNKCE_H
