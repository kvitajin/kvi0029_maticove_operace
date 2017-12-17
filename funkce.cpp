
#include "funkce.h"
#include <iostream>
#include <iomanip>
#include <fstream>

void    menu(){                                                    ///Funkce vypise prvotni hlavicku do terminalu
        std::cout   <<  "================================="<< std::endl;
        std::cout   <<  "Aplikace pro vypocty nad maticemi"<< std::endl;
        std::cout   <<  "================================="<< std::endl;
        std::cout   <<  "Vyberte vstup:"<< std::endl;
        std::cout   <<  "T - terminal"<< std::endl;
        std::cout   <<  "S - soubor"<< std::endl;
        std::cout   <<  "E - pro ukonceni programu"<< std::endl;
        std::cout   <<  "=================================="<< std::endl;

}

char    odkudCtu(){
        char pismeno;
        std::cin    >>  pismeno;

        if (std::cin.fail()){
            std::cout   <<  "============================================="<< std::endl;
            std::cout   <<  "Nezadal jste validni pismeno. Zkuste to znova" <<  std::endl;
            std::cout   <<  "============================================="<< std::endl;
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
            std::cout   <<  "============================================="<< std::endl;
            std::cout   <<  "Nezadal jste validni pismeno. Zkuste to znova" <<  std::endl;
            std::cout   <<  "============================================="<< std::endl;

            return 'E';
        }
}

void    velikostMatice(int &rows, int &columns){
        std::cout   <<  "==============================================="   << std::endl;
        std::cout   <<  "Zadejte pozadovanou velikost LEVE strany matice"   <<  std::endl;
        std::cout   <<  "Zadejte pocet radku:"      <<  std::endl;
        std::cout   <<  "==============================================="   << std::endl;
        std::cin    >>  rows;
        std::cout   <<  "==============================================="   << std::endl;
        std::cout   <<  "Zadejte pocet sloupcu:"    <<  std::endl;
        std::cout   <<  "==============================================="   << std::endl;
        std::cin    >>  columns;

}

void    makeMatrix(const int &rows, const int &columns, std::vector<std::vector<double> > &matrix){
        matrix.resize((unsigned long)rows);
        for(int i = 0 ; i < rows ; ++i){
            matrix[i].resize((unsigned long)columns+1);
        }
}

std::string inFileName(){
        std::string cesta;
    std::cout   <<  "=================================="<< std::endl;
    std::cout   <<  "Zadejte relativni cestu k souboru: "   <<  std::endl;
    std::cout   <<  "=================================="<< std::endl;
    std::cin    >>  cesta;
        return cesta;
}

std::string overPriponu(std::string& name){
    bool *flagPripona;                                      ///dynamic allocated variable, because I can
    flagPripona=new bool[1];
    flagPripona[0]=false;
    for (int i = 1; i < (int)name.length(); ++i) {         //// have to skip zero char
        if (((name[i-1]>='a'    &&  name[i-1]<='z')    ||
             (name[i-1]>='A'    &&  name[i-1]<='Z'))   &&
              name[i]=='.' ) {
            flagPripona[0]= true;
        }
    }
    if (!flagPripona[0]){
        name+=".csv";
    }
    delete[]flagPripona;
    return name;
}

void    fileParseSizeOfMatrix(std::string &line, int &errFlag, char &delimiter, int &rows, int &columns){
    int tmp=0, i, flag=0;
    for (i = 0; i < (int)line.size(); ++i) {
        if ((line[i]>='0'   &&  line[i]<='9')  ||
            (line[i]==' ' ||line[i]==',')){
        } else{
            ++errFlag;
            break;
        }
        if (line[i]==delimiter){
            if (flag){
                columns=tmp;
                break;
            } else{
                rows=tmp;
                tmp=0;
                ++flag;
                continue;
            }
        }
        tmp*=10;
        tmp+=line[i]-48;
    }

}

void     fileFillLineOfMatrix(std::string &line, std::vector<std::vector<double> > &matrix, const int &row, char &delimiter){
    int tmp=0, pos=0, sign=0;
    //std::cout   <<  line   <<  std::endl;
    for (int j = 0; j < (int)line.length(); ++j) {
        if (line[j]==delimiter){
            continue;
        }
        if (line[j]=='-'){
            sign=1;
            continue;
        }
        while (line[j]!=delimiter){
            tmp*=10;
            tmp+=line[j]-48;
            if(j<(int)line.length()-1){
                ++j;
            } else{
                break;
            }
        }
        if (sign){
            tmp*=-1;
            sign=0;
        }
        matrix[row][pos]=tmp;
        tmp=0;
        ++pos;
    }

}

int     fileRead(std::string &filename, int &errFlag, char &delimiter, std::vector<std::vector<double> > &matrix)  {
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

    std::getline(read, radek);                   ///unused line for spacing
    makeMatrix(rows, columns, matrix);

    int row=0;
    while (!read.eof()){
        std::getline(read, radek);
        fileFillLineOfMatrix(radek, matrix, row, delimiter);
        ++row;
    }
    //printMatrix(matrix);
    return 0;
}

char    fileDelimiterFunction(char &delimiter){        //TODO ws
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

void     fileBranch(std::vector<std::vector<double> > &matrix){
    int errFlag=0;
    char delimiter;
    std::string name;
    name= inFileName();
    name=overPriponu(name);
    delimiter= fileDelimiterFunction(delimiter);
    fileRead(name, errFlag, delimiter, matrix);

    //std::cout << name;
}

int     terminalFillMatrix(std::vector< std::vector <double> > &matrix){
    double tmp;
    std::cout   <<  "======================================================"<< std::endl;
    std::cout   <<  "Zadejte matici vcetne prave strany (jen cisla) rovnice. \nPr.: matrix 2x2\n1 2 3\n3 4 7\n";
    std::cout   <<  "Vase cisla:"   <<  std::endl;
    std::cout   <<  "======================================================"<< std::endl;
    for (size_t i = 0; i < matrix.size(); i++) {
        std::cout   <<  "Zadejte "  <<  (i+1)   <<". radek"<<std::endl;
        for (double &j : matrix[i]) {
            std::cin >> tmp;
            if (std::cin.fail()){
                return 1;
            } else{
                j =tmp;
            }
        }
    }
    printMatrix(matrix);
}

void     terminalBranch( std::vector< std::vector <double> > &matrix){
    int rows=0, columns=0;

    velikostMatice(rows, columns);
    makeMatrix(rows, columns, matrix);
    terminalFillMatrix(matrix);
}

void    footer(){
    std::cout   <<  "================"<< std::endl;
    std::cout   <<  "Preji hezky den."   <<  std::endl;
    std::cout   <<  "================"<< std::endl;

}

void    printMatrix(std::vector< std::vector <double> > &matrix){
    std::cout   <<  "======================================================"<< std::endl;

    std::cout   <<    "Vase matice je: "  <<  std::endl;
    std::cout   <<  "======================================================"<< std::endl;
    std::cout   <<  std::setprecision(3);
    for (auto &i : matrix) {
        for (int j = 0; j < (int)i.size(); j++)
        {
            if (j== i.size()-1){
                std::cout   <<  "|\t";
            }
            std::cout   << i[j] <<  "\t\t";
        }
        std::cout   <<  std::endl;
    }
    std::cout   <<  "======================================================"<< std::endl;
    std::cout   <<  std::endl;
}

std::string outFileName(){
    std::string filename="a";
    std::cout   <<  "============================================"<< std::endl;
    std::cout   <<  "Zadejte jmeno vystupniho souboru bez pripony"<< std::endl;
    std::cout   <<  "============================================"<< std::endl;
    std::cin    >>  filename;
    if (filename.length()<1){
        return "ecrtmek";
    } else{
        return filename;
    }
}
