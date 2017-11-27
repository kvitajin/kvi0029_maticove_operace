//
// Created by kvitajin on 23.11.17.
//
#include "funkce.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

void menu(){                                                    ///Funkce vypise prvotni hlavicku do terminalu
        std::cout   <<  "========================="<< std::endl;
        std::cout   <<  "Aplikace pro vypocet GEMu"<< std::endl;
        std::cout   <<  "========================="<< std::endl;
        std::cout   <<  "Vzberte vstup:"<< std::endl;
        std::cout   <<  "T - terminal"<< std::endl;
        std::cout   <<  "S - soubor"<< std::endl;
        std::cout   <<  "E - pro ukonceni programu"<< std::endl;
        std::cout   <<  "========================="<< std::endl;

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
        std::cout   <<  "Zadejte pozadovanou velikost leve strany matice"  <<  std::endl;
        std::cout   <<  "zadejte pocet radku:"      <<  std::endl;
        std::cin    >>  radku;
        std::cout   <<  "Zadejte pocet sloupcu:"    <<  std::endl;
        std::cin    >>  sloupcu;

}
void vytvorMatici(const int radku, const int sloupcu, std::vector< std::vector <int> > &matice){
        matice.resize((unsigned long)radku);
        for(int i = 0 ; i < radku ; ++i){
            matice[i].resize((unsigned long)sloupcu+1);
        }
}
std::string jmenoSouboru(){
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
        jmeno+=".txt";
    }
    return jmeno;
}
int ctiSoubor(std::string& jmeno, int &errFlag){
    std::string cesta=overPriponu(jmeno);
    std::ifstream ctu;
    ctu.open(cesta);
    if (!ctu.is_open()){
        ++errFlag;
        return 1;
    }
}
int souborVetev(){
    int errFlag=0;
    std::string jmeno;
    jmeno=jmenoSouboru();
    jmeno=overPriponu(jmeno);
    ctiSoubor(jmeno, errFlag);
    std::cout << jmeno;
}                     //TODO
int terminalVetev(){
        return 0;
}
void paticka(){
        std::cout   <<  "Preji hezky den."   <<  std::endl;
}
