//
// Created by kvitajin on 23.11.17.
//
#include "funkce.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

void menu(){                                                    ///Funkce vypise prvotni hlavicku do terminalu
        std::cout   <<  "================================="<< std::endl;
        std::cout   <<  "Aplikace pro vypoctz nad maticemi"<< std::endl;
        std::cout   <<  "================================="<< std::endl;
        std::cout   <<  "Vyberte vstup:"<< std::endl;
        std::cout   <<  "T - terminal"<< std::endl;
        std::cout   <<  "S - soubor"<< std::endl;
        std::cout   <<  "E - pro ukonceni programu"<< std::endl;
        std::cout   <<  "=================================="<< std::endl;

}

/*void otravnaHlavicka(char pismeno){
    if (pismeno=='E'){
        menu();
    }
    else if(pismeno=='T'){
        //terminal();                 //TODO
    }

}*/

char odkudCtu(){
        char pismeno;
        std::cin    >>  pismeno;

        if (std::cin.fail()){
            std::cout   <<  "Nezadal jste validni pismeno. Zkuste to znova." <<  std::endl;
            return 'E';
        }
        if (pismeno=='t' || pismeno == 'T'){
            return 'T';
        }
        else if (pismeno=='s' || pismeno== 'S'){
            return 'S';
        }
        else if (pismeno=='e' || pismeno== 'E') {
            return 'X';
        }
        else {
            std::cout   <<  "Nezadal jste pismeno." <<  std::endl;
            return 'E';
        }
}

void velikostMatice(int &radku, int &sloupcu){
        std::cout   <<  "Zadejte pozadovanou velikost LEVE strany matice"  <<  std::endl;
        std::cout   <<  "Zadejte pocet radku:"      <<  std::endl;
        std::cin    >>  radku;
        std::cout   <<  "Zadejte pocet sloupcu:"    <<  std::endl;
        std::cin    >>  sloupcu;

}
void makeMatrix(const int radku, const int sloupcu, std::vector<std::vector<long double> > &matice){
        matice.resize((unsigned long)radku);
        for(int i = 0 ; i < radku ; ++i){
            matice[i].resize((unsigned long)sloupcu+1);
        }
    //std::cout   <<  "vytvarim matici"   <<  std::endl;
}
std::string filename(){
        std::string cesta;
        std::cout   <<  "Zadejte relativni cestu k souboru: "   <<  std::endl;
        std::cin    >>  cesta;
        return cesta;
}
std::string overPriponu(std::string& jmeno){
    bool flagPripona= false;
    for (int i = 1; i < (int)jmeno.length(); ++i) {         //preskocenim nulteho znaku se vyhnu
        if (((jmeno[i-1]>='a'    &&  jmeno[i-1]<='z')    ||
             (jmeno[i-1]>='A'    &&  jmeno[i-1]<='Z'))   &&
              jmeno[i]=='.' ) {
            flagPripona= true;
        }
    }
    if (!flagPripona){
        jmeno+=".csv";
    }
    return jmeno;
}
void fileParseSizeOfMatrix(std::string &radek, int &errFlag, char &delimiter){
    int tmp=0, i, rows=0, columns=0, flag=0;
    for (i = 0; i < (int)radek.size(); ++i) {
        if ((radek[i]>='0'   &&  radek[i]<='9')  ||
            (radek[i]==' ' ||radek[i]==',')){
        } else{
            ++errFlag;
            break;
        }
        if (radek[i]==delimiter){
            if (tmp){
                columns=tmp;
                tmp=0;
                std::cout   <<  columns;
                break;
            } else{
                rows=tmp;
                tmp=0;
                ++flag;
                std::cout   <<  rows;
                continue;
            }
        }
        tmp*=10;
        tmp+=radek[i];
    }

}
int fileRead(std::string &filename, int &errFlag, char &delimiter){
    std::string path=overPriponu(filename);
    std::ifstream read;
    read.open(path);
    if (!read.is_open()){
        ++errFlag;
        return 1;
    }
    std::string radek;
    std::getline(read, radek);
    fileParseSizeOfMatrix(radek, errFlag, delimiter);

}
char fileDelimiterFunction(char &delimiter){
    std::cout   <<  "================================="<< std::endl;
    std::cout   <<  "Zadejte delimiter:"<< std::endl;
    /*std::cin.clear();
    std::cin    >>  std::noskipws    >>  delimiter  >>  std::skipws;*/
    std::cin    >>  delimiter;
    std::cout   <<  "================================="<< std::endl;
    if (std::cin.fail()){

    }
    return delimiter;

}
int fileBranch(){
    int errFlag=0;
    char delimiter;
    std::string name;
    name= filename();
    name=overPriponu(name);
    delimiter= fileDelimiterFunction(delimiter);
    fileRead(name, errFlag, delimiter);
    std::cout << name;
}                     //TODO
int terminalFillMatrix(std::vector< std::vector <long double> > &matice){
    long double tmp;
    std::cout   <<  "Zadejte matici vcetne prave strany (jen cisla) rovnice. \nPr.: matice 2x2\n1 2 3\n3 4 7\n";
    std::cout   <<  "Vase cisla:"   <<  std::endl;
    for (size_t i = 0; i < matice.size(); i++) {
        for (size_t j = 0; j < matice[i].size(); j++) {
            std::cin >> tmp;
            if (std::cin.fail()){
                return 1;
            } else{
                matice[i][j]=tmp;
            }
        }
    }
}
int terminalBranch(){
    int rows=0, columns=0;
    std::vector< std::vector <long double> > matice;
    velikostMatice(rows, columns);
    makeMatrix(rows, columns, matice);
    terminalFillMatrix(matice);
}

void footer(){
        std::cout   <<  "Preji hezky den."   <<  std::endl;
}
char whereToSaveFinalSolution(){
    char tmp;
    std::cout   <<  "================================="<< std::endl;
    std::cout   <<  "Kde chcete vysledek?"<< std::endl;
    std::cout   <<  "T - terminal"<< std::endl;
    std::cout   <<  "S - soubor"<< std::endl;
    std::cout   <<  "================================="<< std::endl;
    std::cin    >>  tmp;
    if (std::cin.fail()){
        return 'X';
    }
    else if (tmp=='T'   ||  tmp=='t'){
        return 'T';
    }
    else if (tmp=='S'   ||  tmp=='s'){
        return 'S';
    } else{
        return 'X';
    }
}
