
#include "funkce.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

char    whereToSaveFinalSolution(){
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

/*void    terminalFinalSolution(std::string &out){
        std::cout   <<  out;
}
void    fileFinalSolution(std::string &out, std::string &outFilename){
                        //TODO
}*/
