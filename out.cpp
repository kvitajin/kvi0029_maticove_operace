
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
    std::cout   <<  "C - pro .csv soubor"<< std::endl;
    std::cout   <<  "H - pro .html soubor"<< std::endl;
    std::cout   <<  "================================="<< std::endl;
    std::cin    >>  tmp;
    if (std::cin.fail()){
        return 'X';
    }
    else if (tmp=='T'   ||  tmp=='t'){
        return 'T';
    }
    else if (tmp=='C'   ||  tmp=='c'){
        return 'C';
    }
    else if (tmp=='H'   ||  tmp=='h') {
        return 'H';
    }else{
        return 'X';
    }
}


void    prepareString           (std::string &out,
                                 char where,
                                 int what,
                                 long int determ,
                                 std::vector<std::vector<double> > &triangle,
                                 std::vector<double> &roots){
    if (where=='C'){                        ///CSV branch
        if (what==1 || what==3 || what==5 ||what==7){
            //out="Trojuhelnikovy tvar matice:\n";
            for (int i = 0; i < triangle.size(); ++i) {
                for (int j = 0; j < triangle.size()+1; ++j) {
                    out+=triangle[i][j];
                    out+="\t";
                    if (j==triangle.size()){
                        out+="|\t";
                    }
                }
                out+="\n";
            }
        }
        if (what==2 || what==3 || what==6 || what==7){
            //out+="Determinant= ";
            out+=std::to_string(determ);
            out="\n";
        }
        if (what==4 || what==5 || what==6 || what==7){
            auto g=(int)roots.size();
            char tmp;
            //out+="Koreny: ";
            for (int k = 0; k < g+1; ++k) {
                tmp=(char)('a'+k);
                out+=std::to_string(tmp);
                out+=
                out+=std::to_string(roots[g-k]);
            }
        }
    }
    else if (where=='H'){
        out="<!DOCTYPE html>\n"
                "<html lang=\"cs\" dir=\"ltr\">\n"
                "  <head>\n"
                "    <meta charset=\"UTF-8\">\n"
                "    <title>Vypocty nad maticemi</title>\n"
                "  </head>\n"
                "  <body>\n";
        if (what==1 || what==3 || what==5 ||what==7){
            out+="<h1>Trojuhelnikovy tvar matice:</h1></br>";
            for (int i = 0; i < triangle.size(); ++i) {
                for (int j = 0; j < triangle.size()+1; ++j) {
                    out+=std::to_string(triangle[i][j]);
                    out+="\t";
                    if (j==triangle.size()){
                        out+="|\t";
                    }
                }
                out+="\n";
            }
        }

    } else{
        if (what==1 || what==3 || what==5 ||what==7){
            out="Trojuhelnikovy tvar matice:\n";
            for (int i = 0; i < triangle.size(); ++i) {
                for (int j = 0; j < triangle.size()+1; ++j) {
                    out+=std::to_string(triangle[i][j]);
                    out+="\t";
                    if (j==triangle.size()){
                        out+="|\t";
                    }
                }
                out+="\n";
            }
        }
        if (what==2 || what==3 || what==6 || what==7){
            out+="Determinant= ";
            out+=std::to_string(determ);
            out="\n";
        }
        if (what==4 || what==5 || what==6 || what==7){
            auto g=(int)roots.size();
            char tmp;
            out+="Koreny: ";
            for (int k = 0; k < g+1; ++k) {
                tmp=(char)('a'+k);
                out+=std::to_string(tmp);
                out+=
                out+=std::to_string(roots[g-k]);
            }
        }
    }
}


