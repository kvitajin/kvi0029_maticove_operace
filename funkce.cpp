
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

void velikostMatice(int &radku, int &sloupcu){      //todo rename
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

void fileParseSizeOfMatrix(std::string &radek, int &errFlag, char &delimiter, int &rows, int &columns){
    int tmp=0, i, flag=0;
    std::cout   <<  "jsem zde 1 " <<  std::endl;
    for (i = 0; i < (int)radek.size(); ++i) {
        if ((radek[i]>='0'   &&  radek[i]<='9')  ||
            (radek[i]==' ' ||radek[i]==',')){
        } else{
            ++errFlag;
            break;
        }
        if (radek[i]==delimiter){
            if (flag){
                columns=tmp;
                tmp=0;
                //std::cout   <<  columns;
                break;
            } else{
                rows=tmp;
                tmp=0;
                ++flag;
                //td::cout   <<  rows;
                continue;
            }
        }
        tmp*=10;
        tmp+=radek[i]-48;
    }
    //std::cout   <<  "column "    <<  columns    <<  " rows "    <<  rows    <<  std::endl;

}

int fileFillLineOfMatrix(std::string &radek, std::vector<std::vector<long double> > &matice, const int i, char &delimiter){
    int tmp=0, pos=0, sign=0;
    std::cout   <<  radek   <<  std::endl;
    for (int j = 0; j < (int)radek.length(); ++j) {
        if (radek[j]==delimiter){
            continue;
        }
        if (radek[j]=='-'){
            sign=1;
            continue;
        }
        while (radek[j]!=delimiter){
            tmp*=10;
            tmp+=radek[j]-48;
            if(j<(int)radek.length()){
                ++j;
            } else{
                break;
            }
        }
        if (sign){
            tmp*=-1;
            sign=0;
        }
        matice[i][pos]=tmp;
        tmp=0;
        ++pos;
    }

}

int fileRead(std::string &filename, int &errFlag, char &delimiter, std::vector<std::vector<long double> > &matice){
    std::string path=overPriponu(filename);

    int rows=0, columns=0;
    std::ifstream read;
    read.open(path);
    if (!read.is_open()){
        std::cout   << "se posralo";
        ++errFlag;
        return 1;
    }
    std::string radek;
    std::getline(read, radek);
    //std::cout   << "jsem zde";
    fileParseSizeOfMatrix(radek, errFlag, delimiter, rows, columns);
    //todo test funkce
    std::getline(read, radek);      //radek odradkovani, nepouzije se
    makeMatrix(rows, columns, matice);
    int i=0;
    while (!read.eof()){
        std::getline(read, radek);
        fileFillLineOfMatrix(radek, matice, i, delimiter);
        ++i;
    }
    printMatrix(matice);
    return 0;
}

char fileDelimiterFunction(char &delimiter){        //TODO ws
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
    std::vector<std::vector<long double> > matice;
    std::string name;
    name= filename();
    name=overPriponu(name);
    delimiter= fileDelimiterFunction(delimiter);
    fileRead(name, errFlag, delimiter, matice);

    //std::cout << name;
}                     //TODO
int terminalFillMatrix(std::vector< std::vector <long double> > &matice){       //TODO prekopat
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
    printMatrix(matice);
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

void printMatrix(std::vector< std::vector <long double> > &matice){
    std::cout <<    "Vase matice je: "  <<  std::endl;
    for (int i = 0; i < matice.size(); i++)
    {
        for (int j = 0; j < matice[i].size(); j++)
        {
            if (j==matice[i].size()-1){
                std::cout   <<  "|\t";
            }
            std::cout   <<  matice[i][j] <<  "\t";
        }
        std::cout   <<  std::endl;
    }
}
