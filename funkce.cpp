//
// Created by kvitajin on 23.11.17.
//
#include "funkce.h"
#include <iostream>
#include <cstdlib>

void menu(){                                                    ///Funkce vypise prvotni hlavicku do terminalu
    std::cout   <<  "========================="<< std::endl;
    std::cout   <<  "Aplikace pro vypocet GEMu"<< std::endl;
    std::cout   <<  "========================="<< std::endl;
    std::cout   <<  "Vzberte vstup:"<< std::endl;
    std::cout   <<  "T - terminal"<< std::endl;
    std::cout   <<  "S - soubor"<< std::endl;
    std::cout   <<  "E - pro ukonceni programu"<< std::endl;
}

void otravnaHlavicka(char pismeno){
    if (pismeno=='E'){
        menu();
    }
    else if(pismeno=='T'){
        //terminal();                 //TODO
    }

}

char odkudCtu(){
    char pismeno;
    std::cin    >>  pismeno;

    if (std::cin.fail()){
        std::cout   <<  "Nezadal jste pismeno." <<  std::endl;
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
void paticka(){
    std::cout   <<  "Preji hezky den"   <<  std::endl;
}
//gitk knihovna,