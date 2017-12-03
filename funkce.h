//
// Created by kvitajin on 23.11.17.
//

#ifndef SEM_2_FUNKCE_H
#define SEM_2_FUNKCE_H

#include <vector>
#include <string>

void menu();
//void otravnaHlavicka(char pismeno);
char odkudCtu();
void footer();
void velikostMatice(int &radku, int &sloupcu);
void vytvorMatici(const int radku, const int sloupcu, std::vector< std::vector <int> > &matice);

std::string jmenoSouboru();
int ctiSoubor();
int fileBranch();
int therminalBranch();






#endif //SEM_2_FUNKCE_H
