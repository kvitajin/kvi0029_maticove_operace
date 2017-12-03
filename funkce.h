//
// Created by kvitajin on 23.11.17.
//

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
void        fileParseSizeOfMatrix(std::string &radek, int &errFlag, char &delimiter);
int         fileRead(std::string &filename, int &errFlag, char &delimiter);
char        fileDelimiterFunction(char &delimiter);
int         fileBranch();
int         terminalFillMatrix(std::vector< std::vector <long double> > &matice);
int         terminalBranch();






#endif //SEM_2_FUNKCE_H
